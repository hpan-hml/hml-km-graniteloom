;; stella.asd 						-*- lisp -*-

;;;;;;;;;;;;;;;;;;;;;;;;;;;;; BEGIN LICENSE BLOCK ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                                                            ;
;; Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          ;
;;                                                                            ;
;; The contents of this file are subject to the Mozilla Public License        ;
;; Version 1.1 (the "License"); you may not use this file except in           ;
;; compliance with the License. You may obtain a copy of the License at       ;
;; http://www.mozilla.org/MPL/                                                ;
;;                                                                            ;
;; Software distributed under the License is distributed on an "AS IS" basis, ;
;; WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   ;
;; for the specific language governing rights and limitations under the       ;
;; License.                                                                   ;
;;                                                                            ;
;; The Original Code is this system definition                                ;
;;                                                                            ;
;; The Initial Developer of the Original Code is                              ;
;; Sean Champ spchamp@users.noreply.github.com                                ;
;;                                                                            ;
;; Portions created by the Initial Developer are Copyright (C) 2015           ;
;; the Initial Developer. All Rights Reserved.                                ;
;;                                                                            ;
;; Alternatively, the contents of this file may be used under the terms of    ;
;; either the GNU General Public License Version 2 or later (the "GPL"), or   ;
;; the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   ;
;; in which case the provisions of the GPL or the LGPL are applicable instead ;
;; of those above. If you wish to allow use of your version of this file only ;
;; under the terms of either the GPL or the LGPL, and not to allow others to  ;
;; use your version of this file under the terms of the MPL, indicate your    ;
;; decision by deleting the provisions above and replace them with the notice ;
;; and other provisions required by the GPL or the LGPL. If you do not delete ;
;; the provisions above, a recipient may use your version of this file under  ;
;; the terms of any one of the MPL, the GPL or the LGPL.                      ;
;;                                                                            ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; END LICENSE BLOCK ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(in-package #:cl-user)


(eval-when (:compile-toplevel :load-toplevel :execute)

  (let ((p (find-package '#:cl-user)))
    (dolist (s '(#:*load-cl-struct-stella?*
                 #:*stella-verbose?*
                 #:*source-truename* ;; [new]
                 #:*system-asdf* ;; [new]
                 ))
      (intern (symbol-name s) p)))
  
  (defpackage #:stella-system
    (:use #:asdf #:cl)

    #+CMUCL
    (:shadowing-import-from #:ext #:inhibit-warnings)
    #+SBCL
    (:shadowing-import-from #:sb-ext #:muffle-conditions #:inhibit-warnings)
    #+SBCL
    (:shadowing-import-from #:sb-kernel #:redefinition-warning)
    #+EXCL
    (:shadowing-import-from #:excl compiler-undefined-functions-called-warning)
    
    (:shadowing-import-from
     #:cl-user
     #:*load-cl-struct-stella?*
     #:*stella-verbose?*
     #:*source-truename*
     #:*system-asdf*
     ))

  #+NIL
  (pushnew :stella-struct *features*
           ;; ^ another way to represent
           ;; CL-USER::*load-cl-struct-stella?* => T
           ;; newly developed in this system definition
           :test #'eq)
  
  (unless (find-package "STELLA")
    ;; emulating forms defined in
    ;; file native/lisp/stella/cl-lib/cl-setup.lisp
    (defpackage "STELLA"
      (:use)
      (:intern
       #:with-redefinition-warnings-surpressed
       #:with-undefined-function-warnings-suppressed
       )
      (:shadowing-import-from
       #:CL
       #:SETQ #:SETF
       #:PRINT-OBJECT
       #:IN-PACKAGE #:EXPORT
       #:TRACE #:UNTRACE #:INSPECT
       #:apropos
       #+Allegro #:COMPILE
       #+Allegro #:EVAL-WHEN
       #+Allegro #:READTABLE
       )))
  
  ) ;; EVAL-WHEN


;; n.b
;;
;;   *STELLA-SOURCE-EXTENSION* =default=> ".ste" 
;;   *STELLA-TRANSLATED-EXTENSION*  =default=> ".lisp"

(in-package #:stella-system)


(defmacro setv (name value &optional docstring)
  `(cond
     ((boundp (quote ,name))
      ,@(when docstring `(progn (setf (documentation (quote ,name) 'variable)
                                      ,docstring)))
      (setq ,name ,value))
     (t
      (defvar ,name ,value ,@(when docstring (list docstring))))))


(defclass stella-source-file (source-file)
  ;; intermediay source file
  ;; may be processed to generate a c++, java,
  ;; or lisp source file
  ()
  (:default-initargs :type "ste"))

(defclass java-source-file (source-file)
  ()
  (:default-initargs :type "java"))

(defclass c-header-file (source-file)
  ()
  (:default-initargs :type "h"))

;; asdf:c-source-file - defined in ASDF upstream

(defclass c++-source-file (source-file)
  ()
  (:default-initargs :type "cc"))

(defclass makefile (source-file)
  ()
  ;; e.g. ./native/cpp/stella/cpp-lib/Makefile
  (:default-initargs :type nil))


(defclass powerloom-kb (source-file)
  ()
  (:default-initargs :type "plm"))


(defclass stella-sytem (system)
  ()
  (:default-initargs :type nil))


(deftype stella-laguage ()
  ;; cf. STELLA::%MAKE-SYSTEM - syntax tho?
  ;;
  ;; informaive typedef
  '(member :common-lisp :cpp :java))



(defclass transform-op (operation)
  ())


(defmethod operate ((o transform-op) (c stella-system)
                    &key (production t))
  (apply #'stella::make-system
         (component-name c)
         :force-translation? t
         :load-system? t
         (cond
           (production '(:production-settings? t
                         :developmen-settings? nil))
           (t '(:production-settings? nil
                :developmen-settings? tx)))))

(defmethod operate ((o load-op) (c stella-system))
  ;; FIXME: pathname handling
  ;;
  ;; FIXME: IN-ORDER-TO method

  ;; compiles and loads ... ? then calls 'the system startup function"...
  ;;; referring to docstriing or STELLA::MAKE-SYSTEM, STELLA::%MAKE-SYSTEM
  (stella::make-system (component-name c) :load-system? t)
  )


(defmethod operate ((o compile-op) (c stella-system))
  ;; FIXME: pathname handling
  ;;
  ;; FIXME: IN-ORDER-TO method

  ;; compiles and loads ... ? then calls 'the system startup function"...
  ;;; referring to docstriing or STELLA::MAKE-SYSTEM, STELLA::%MAKE-SYSTEM
  (stella::make-system (component-name c)
                       :load-system? nil
                       :force-recompilation? t))

;; --- 

;; emulating forms defined in
;; file native/lisp/stella/cl-lib/cl-setup.lisp
(unless (>= (integer-length most-positive-fixnum) 24)
  (error "The maximum fixnum size of this lisp ~
implementation ~(~D)~%is too small.  It must be at least 24 bits."
         (integer-length most-positive-fixnum)))

(defmacro stella::with-redefinition-warnings-suppressed
    (&body forms)
  ;; modified from native/lisp/stella/cl-lib/cl-setup.lisp
  `(locally
       #+(or CMUCL SBCL)
       (declare
        #+CMUCL (optimize (inhibit-warnings 3))
        #+SBCL (muffle-conditions redefinition-warning))
       (handler-bind
           #-SBCL ()
           #+SBCL ((redefinition-warning #'muffle-warning))
           (let (#+:MCL(CCL::*WARN-IF-REDEFINE* CL:NIL)
                       #+:EXCL(EXCL::*REDEFINITION-WARNINGS* CL:NIL)
                       #+:LUCID(USER::*REDEFINITION-ACTION* CL:NIL)
                       #+:TI(TICL::INHIBIT-FDEFINE-WARNINGS CL:T)
                       #+:LISPWORKS(LISPWORKS::*REDEFINITION-ACTION* CL:NIL)
                       #+:CLISP(CLOS::*WARN-IF-GF-ALREADY-CALLED* CL:NIL)
                       #+:CLISP(CLOS::*GF-WARN-ON-REPLACING-METHOD* CL:NIL)
                       #+:CLISP(CUSTOM:*SUPPRESS-CHECK-REDEFINITION* CL:T)
                       )
             ,@forms))))

(defmacro stella::with-undefined-function-warnings-suppressed
    (&body forms)
  ;; modified from native/lisp/stella/cl-lib/cl-setup.lisp
  `(locally
       #+(or CMUCL SBCL) (declare (optimize (inhibit-warnings 3)))
       (handler-bind 
           (#+EXCL
            (compiler-undefined-functions-called-warning #'muffle-warning)
            )
         (progn ,@forms))))


;; [new] (FIXME: DO not define here)

(defun unwrap-literal (value) ;; UTIL
  ;; see also: stella::wrap-literal
  (declare (type stella::literal-wrapper value))
  (etypecase value
    (stella::string-wrapper (stella::unwrap-string value))
    (stella::integer-wrapper (stella::unwrap-integer value))
    (stella::long-integer-wrapper (stella::unwrap-long-integer value))
    (stella::float-wrapper (stella::unwrap-float value))
    (stella::boolean-wrapper (stella::unwrap-boolean value))
    (stella::character-wrapper (stella::unwrap-character value))))

(defun unencapsulate-object (value)
  (declare (type (or stella::literal-wrapper
                     stella::list)
                 value))
  (etypecase value
    (stella::literal-wrapper (values (unwrap-literal value)))
    (stella::list (values (stella::%the-cons-list value)))))

(defclass stella-lisp-file (cl-source-file)
  ())


(defvar *source-truename*)

(defvar *system-asdf*)

(defvar *stella-verbose?* (or *compile-verbose* *load-verbose*))

(defmethod perform :around ((o compile-op) (c stella-lisp-file))
  (let ((*compile-verbose* *stella-verbose?*)
        (*system-asdf* (component-system c))
        (*source-truename*
         (truename (component-pathname c))))
    (stella::with-redefinition-warnings-suppressed
      (stella::with-undefined-function-warnings-suppressed
        (call-next-method)))))

(defmethod perform :around ((o load-op) (c stella-lisp-file))
  (let ((*load-verbose* *stella-verbose?*)
        (*system-asdf* (component-system c))
        (*source-truename*
         (truename (component-pathname c))))
    (stella::with-redefinition-warnings-suppressed
      (stella::with-undefined-function-warnings-suppressed
        (call-next-method)))))


(defclass stella-system-asdf (system)
  ())

(defmethod perform :around ((op operation) (c stella-system-asdf))
  (let ((*system-asdf* c))
    ;; NB: PERFORM might not be applied recursively onto system components
    (call-next-method)))


(defsystem #:stella ;; xref: ./load-stella.lisp , ...
  :class stella-system-asdf
  :depends-on
  (#:usocket ;; portable sockets interface
   ;; ^ cf. socket handling in STELLA 
   ;; ^ see native/lisp/stella/cl-lib/cl-setup.lisp , ...
   ;; ^ #+Allegro, #+(And MCL (not OPENMCL)), #+Lispworks, #+SBCL

   #:bordeaux-threads ;; portable threads interface
   ;; ^ cf. process locks in STELLA
   ;; ^ see native/lisp/stella/cl-lib/cl-setup.lisp , ...
   ;; ^ #+Allegro, #+Lispworks #+MCL, #+CMUCL, #+SBCL
   )
  
  :perform
  (compile-op :before (o c)
              
              ;; [new] in COMPILE-OP :BEFORE
              #+stella-struct
              (setv *load-cl-struct-stella?* t)
              ;; ^ set CL-USER::*load-cl-struct-stella?*
              ;; per #+STELLA-STRUCT
              
              ) ;; :BEFORE COMPILE-OP

  ;; :perform
  ;; (compile-op :after (o c)
  ;;             (trace STELLA::DEFINE-SYSTEM)
  ;;             #+NIL (trace STELLA::%MAKE_SYSTEM))
  
  
  :perform
  (load-op :after (o c)
           (macrolet ((func (name pkg)
                        `(funcall (symbol-function
                                   (find-symbol ,(symbol-name name)
                                                (quote ,pkg))))))
             ;; convenience - emulating a form defined in
             ;; file ./native/lisp/stella/cl-lib/make-stella.lisp
             (func #:startup-stella-system #:stella) 
             (func #:startup-stella-to-cl #:stella))

           ;; emulating a form defined in
           ;; file ./load-stella.lisp
           (when *stella-verbose?* 
             (format t "~&~a loaded.~%~
Type `(in-package \"STELLA\")' to execute STELLA commands."
                     (symbol-value (find-symbol
                                    (symbol-name '#:*stella-version-string*)
                                    '#:stella)))
             #+allegro ;; cf. STELLA Lisp dialect; Allegro Emacs FI
             (tpl:setq-default cl-user::*redefinition-warnings* nil)
             )) ;; :AFTER LOAD-OP
  
  :components
  ((stella-lisp-file "translations")
   ;; ^ LPN translations - "PL:" + {sorces|native|bin|kbs} + ";" ...
   (:module
    "native"
    :depends-on ("translations")
    :pathname "native/lisp/stella"
    :serial t
    :components
    ((:file "load-stella")
     (:module "cl-lib"
              :serial t
              :components
              ((:file "cl-setup")
               #+NIL
               (:file "make-stella" ;; transposed to this system definition
                      :depends-on ("cl-setup"))))
     
     ;; following elements transposed from make-stella.lisp
     #+:stella-struct (stella-lisp-file "stella-system-structs")
     (stella-lisp-file "hierarchy")
     (stella-lisp-file "streams")
     (stella-lisp-file "taxonomies")
     (stella-lisp-file "primal")
     (stella-lisp-file "cl-primal" :pathname "cl-lib/cl-primal")
     (stella-lisp-file "startup")
     (stella-lisp-file "type-predicates")
     (stella-lisp-file "conses")
     (stella-lisp-file "lists")
     (stella-lisp-file "collections")
     (stella-lisp-file "iterators")
     (stella-lisp-file "symbols")
     ;; (stella-lisp-file "boot-symbols") ;; unused in original make-stella.lisp
     (stella-lisp-file "literals")
     (stella-lisp-file "classes")
     (stella-lisp-file "methods")
     (stella-lisp-file "defclass")
     (stella-lisp-file "date-time")
     (stella-lisp-file "date-time-parser")
     (stella-lisp-file "stella-in")
     (stella-lisp-file "foreach")
     (stella-lisp-file "walk")
     (stella-lisp-file "dynamic-slots")
     (stella-lisp-file "dynamic-literal-slots")
     (stella-lisp-file "cl-translate")
     (stella-lisp-file "macros")
     (stella-lisp-file "memoize")
     (stella-lisp-file "describe")
     (stella-lisp-file "demons")
     (stella-lisp-file "more-demons")
     (stella-lisp-file "name-utility")
     (stella-lisp-file "modules")
     (stella-lisp-file "contexts")
     (stella-lisp-file "read")
     (stella-lisp-file "xml")
     (stella-lisp-file "translate-file")
     (stella-lisp-file "systems")
     (stella-lisp-file "cl-translate-file")
     (stella-lisp-file "cpp-translate")
     (stella-lisp-file "cpp-translate-file")
     (stella-lisp-file "cpp-class-out")
     (stella-lisp-file "cpp-output")
     (stella-lisp-file "java-translate")
     (stella-lisp-file "java-translate-file")
     (stella-lisp-file "java-class-out")
     (stella-lisp-file "java-output")
     (stella-lisp-file "idl-translate")
     (stella-lisp-file "idl-translate-file")
     (stella-lisp-file "idl-class-out")
     (stella-lisp-file "idl-output")
     (stella-lisp-file "tools")
     (stella-lisp-file "stella-to-cl" :pathname "cl-lib/stella-to-cl")
     (stella-lisp-file "startup-system")
     ))
   ))
 
