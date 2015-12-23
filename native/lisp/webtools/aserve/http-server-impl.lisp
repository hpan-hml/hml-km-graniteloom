;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; http-server-impl.lisp

#|
 +---------------------------- BEGIN LICENSE BLOCK ---------------------------+
 |                                                                            |
 | Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
 |                                                                            |
 | The contents of this file are subject to the Mozilla Public License        |
 | Version 1.1 (the "License"); you may not use this file except in           |
 | compliance with the License. You may obtain a copy of the License at       |
 | http://www.mozilla.org/MPL/                                                |
 |                                                                            |
 | Software distributed under the License is distributed on an "AS IS" basis, |
 | WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
 | for the specific language governing rights and limitations under the       |
 | License.                                                                   |
 |                                                                            |
 | The Original Code is the STELLA Programming Language.                      |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 2003-2010      |
 | the Initial Developer. All Rights Reserved.                                |
 |                                                                            |
 | Contributor(s):                                                            |
 |                                                                            |
 | Alternatively, the contents of this file may be used under the terms of    |
 | either the GNU General Public License Version 2 or later (the "GPL"), or   |
 | the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
 | in which case the provisions of the GPL or the LGPL are applicable instead |
 | of those above. If you wish to allow use of your version of this file only |
 | under the terms of either the GPL or the LGPL, and not to allow others to  |
 | use your version of this file under the terms of the MPL, indicate your    |
 | decision by deleting the provisions above and replace them with the notice |
 | and other provisions required by the GPL or the LGPL. If you do not delete |
 | the provisions above, a recipient may use your version of this file under  |
 | the terms of any one of the MPL, the GPL or the LGPL.                      |
 |                                                                            |
 +----------------------------- END LICENSE BLOCK ----------------------------+
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR SGT-HTTP-SERVER-IMPL-ASERVE-HTTP-SERVER-ASERVE NULL)
(CL:DEFVAR SGT-HTTP-SERVER-IMPL-ASERVE-HTTP-EXCHANGE-ASERVE NULL)
(CL:DEFVAR KWD-HTTP-SERVER-IMPL-CONTENT-TYPE NULL)
(CL:DEFVAR SYM-HTTP-SERVER-IMPL-ASERVE-STARTUP-HTTP-SERVER-IMPL NULL)
(CL:DEFVAR SYM-HTTP-SERVER-IMPL-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* NIL))

;;; (DEFCLASS HTTP-SERVER-ASERVE ...)

(CL:DEFCLASS HTTP-SERVER-ASERVE (HTTP-SERVER)
  ())

(CL:DEFUN NEW-HTTP-SERVER-ASERVE ()
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE HTTP-SERVER-ASERVE))) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF HTTP-SERVER-ASERVE))
  SGT-HTTP-SERVER-IMPL-ASERVE-HTTP-SERVER-ASERVE)

;;; (DEFMETHOD (START-HTTP-SERVER-IMPL STRING) ...)

(CL:DEFMETHOD START-HTTP-SERVER-IMPL ((SERVER HTTP-SERVER-ASERVE) PORT)
  (CL:DECLARE (CL:TYPE CL:FIXNUM PORT))
  #+MCL
  (CL:CHECK-TYPE PORT CL:FIXNUM)
  (net.aserve:start :port port :chunking #-:MCL CL:t #+:MCL CL:nil)
  STELLA::NULL-STRING)

;;; (DEFMETHOD STOP-HTTP-SERVER-IMPL ...)

(CL:DEFMETHOD STOP-HTTP-SERVER-IMPL ((SERVER HTTP-SERVER-ASERVE))
  (net.aserve:shutdown))

;;; (DEFCLASS HTTP-EXCHANGE-ASERVE ...)

(CL:DEFCLASS HTTP-EXCHANGE-ASERVE (HTTP-EXCHANGE)
  ((REQUEST :ALLOCATION :INSTANCE :ACCESSOR %REQUEST)
   (ENTITY :ALLOCATION :INSTANCE :ACCESSOR %ENTITY)
   (STREAM :ALLOCATION :INSTANCE :ACCESSOR %STREAM)))

(CL:DEFUN NEW-HTTP-EXCHANGE-ASERVE (REQUEST ENTITY)
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF (CL:MAKE-INSTANCE (CL:QUOTE HTTP-EXCHANGE-ASERVE)))
   (CL:SETF (%REQUEST SELF) REQUEST) (CL:SETF (%ENTITY SELF) ENTITY)
   (CL:SETF (%STREAM SELF) NULL) SELF))

(CL:DEFMETHOD PRIMARY-TYPE ((SELF HTTP-EXCHANGE-ASERVE))
  SGT-HTTP-SERVER-IMPL-ASERVE-HTTP-EXCHANGE-ASERVE)

;;; (DEFUN (COERCE-LISP-VALUE-TO-STRING STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) COERCE-LISP-VALUE-TO-STRING))
(CL:DEFUN COERCE-LISP-VALUE-TO-STRING (LVALUE)
  (CL:COND ((CL:EQ LVALUE NIL) STELLA::NULL-STRING)
   ((CL:STRINGP LVALUE) LVALUE) (CL:T (CL:PRINC-TO-STRING LVALUE))))

;;; (DEFMETHOD (GET-HEADER-VALUE-IMPL STRING) ...)

(CL:DEFMETHOD GET-HEADER-VALUE-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG KEY)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)) (LKEY (LISPIFY KEY)))
   (COERCE-LISP-VALUE-TO-STRING (net.aserve:header-slot-value lreq lkey))))

;;; (DEFMETHOD (GET-REPLY-HEADER-VALUE-IMPL STRING) ...)

(CL:DEFMETHOD GET-REPLY-HEADER-VALUE-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG KEY)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)) (LKEY (LISPIFY KEY)))
   (COERCE-LISP-VALUE-TO-STRING
    (net.aserve:reply-header-slot-value lreq lkey))))

;;; (DEFMETHOD SET-REPLY-HEADER-VALUE-IMPL ...)

(CL:DEFMETHOD SET-REPLY-HEADER-VALUE-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG KEY VALUE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING VALUE))
  #+MCL
  (CL:CHECK-TYPE VALUE CL:SIMPLE-STRING)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)) (LKEY (LISPIFY KEY)))
   (CL:setf (net.aserve:reply-header-slot-value lreq lkey) value)))

;;; (DEFMETHOD (GET-REQUEST-URI-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-URI-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)))
   (net.uri:render-uri (net.aserve:request-raw-uri lreq) CL:nil)))

;;; (DEFMETHOD (GET-REQUEST-URI-QUERY-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-URI-QUERY-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)))
   (COERCE-LISP-VALUE-TO-STRING
    (net.uri:uri-query (net.aserve:request-uri lreq)))))

;;; (DEFMETHOD (GET-REQUEST-URI-PATH-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-URI-PATH-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)))
   (COERCE-LISP-VALUE-TO-STRING
    (net.uri:uri-path (net.aserve:request-uri lreq)))))

;;; (DEFMETHOD (GET-REQUEST-METHOD-IMPL KEYWORD) ...)

(CL:DEFMETHOD GET-REQUEST-METHOD-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)))
   (INTERN-KEYWORD (CL:symbol-name (net.aserve:request-method lreq)))))

;;; (DEFMETHOD (GET-REQUEST-PROTOCOL-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-PROTOCOL-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)))
   (net.aserve:request-protocol-string lreq)))

;;; (DEFMETHOD (GET-REQUEST-BODY-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-BODY-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET* ((LXCHG XCHG) (LREQ (%REQUEST LXCHG)))
   (net.aserve:get-request-body lreq)))

;;; (DEFMETHOD (GET-REQUEST-LOCAL-ADDRESS-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-LOCAL-ADDRESS-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET*
   ((LXCHG XCHG) (LREQ (%REQUEST LXCHG))
    (LSOCKET (net.aserve:request-socket lreq))
    (HOST (CL:or (socket:ipaddr-to-hostname (socket:local-host lsocket))
                                                    (socket:ipaddr-to-dotted (socket:local-host lsocket))))
    (PORT (socket:local-port lsocket)))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING HOST) (CL:TYPE CL:FIXNUM PORT))
   (CONCATENATE HOST ":" (INTEGER-TO-STRING (CL:TRUNCATE PORT)))))

;;; (DEFMETHOD (GET-REQUEST-REMOTE-ADDRESS-IMPL STRING) ...)

(CL:DEFMETHOD GET-REQUEST-REMOTE-ADDRESS-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET*
   ((LXCHG XCHG) (LREQ (%REQUEST LXCHG))
    (LSOCKET (net.aserve:request-socket lreq))
    (HOST (CL:or (socket:ipaddr-to-hostname (socket:remote-host lsocket))
                                                    (socket:ipaddr-to-dotted (socket:remote-host lsocket))))
    (PORT (socket:remote-port lsocket)))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING HOST) (CL:TYPE CL:FIXNUM PORT))
   (CONCATENATE HOST ":" (INTEGER-TO-STRING (CL:TRUNCATE PORT)))))

;;; (DEFMETHOD (GET-REPLY-STREAM-IMPL NATIVE-OUTPUT-STREAM) ...)

(CL:DEFMETHOD GET-REPLY-STREAM-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET* ((LXCHG XCHG) (LSTREAM (%STREAM LXCHG)))
   (CL:WHEN (NULL? LSTREAM) (CL:SETQ LSTREAM (CL:make-string-output-stream))
    (CL:SETF (%STREAM LXCHG) LSTREAM))
   LSTREAM))

;;; (DEFUN (GET-ASERVE-RESPONSE-CODE LISP-CODE) ...)

(CL:DEFUN GET-ASERVE-RESPONSE-CODE (CODE)
  (CL:LET*
   ((NCODE (GET-HTTP-RESPONSE-CODE CODE NULL))
    (LCODE (net.aserve::code-to-response ncode))
    (LCODEDESC (net.aserve::response-desc lcode)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM NCODE) (CL:TYPE CL:SIMPLE-STRING LCODEDESC))
   (CL:WHEN (STRING-EQL? LCODEDESC "unknown code")
    (CL:SETQ LCODEDESC (GET-HTTP-RESPONSE-DESC CODE NULL))
    (CL:setf (net.aserve::response-desc lcode) lcodedesc))
   LCODE))

;;; (DEFMETHOD SET-RESPONSE-CODE-IMPL ...)

(CL:DEFMETHOD SET-RESPONSE-CODE-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG CODE)
  (CL:LET*
   ((LXCHG XCHG) (LREQ (%REQUEST LXCHG))
    (LCODE (GET-ASERVE-RESPONSE-CODE CODE)))
   (CL:setf (net.aserve:request-reply-code lreq) lcode)))

;;; (DEFMETHOD PUBLISH-FILE-IMPL ...)

(CL:DEFMETHOD PUBLISH-FILE-IMPL ((SERVER HTTP-SERVER-ASERVE) PATH FILE OPTIONS)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH FILE))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE FILE CL:SIMPLE-STRING)
  (CL:LET*
   ((CTYPE (LISPIFY (LOOKUP OPTIONS KWD-HTTP-SERVER-IMPL-CONTENT-TYPE))))
   (net.aserve:publish-file
         :path path
         :file file
         :content-type ctype
         :plist `(handler-options ,options))))

;;; (DEFMETHOD PUBLISH-DIRECTORY-IMPL ...)

(CL:DEFMETHOD PUBLISH-DIRECTORY-IMPL ((SERVER HTTP-SERVER-ASERVE) PATH DIRECTORY OPTIONS)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH DIRECTORY))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE DIRECTORY CL:SIMPLE-STRING)
  (CL:SETQ OPTIONS OPTIONS)
  (net.aserve:publish-directory
        :prefix path
        :destination directory
        :plist `(handler-options ,options)))

;;; (DEFMETHOD PUBLISH-HANDLER-IMPL ...)

(CL:DEFMETHOD PUBLISH-HANDLER-IMPL ((SERVER HTTP-SERVER-ASERVE) PATH HANDLER OPTIONS)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  (CL:LET*
   ((CTYPE (LISPIFY (LOOKUP OPTIONS KWD-HTTP-SERVER-IMPL-CONTENT-TYPE))))
   (net.aserve:publish
         :path path
         :content-type ctype
         :function #'generic-response-handler
         :plist `(response-handler ,handler handler-options ,options))))

;;; (DEFMETHOD (GET-HANDLER-OPTIONS-IMPL PROPERTY-LIST) ...)

(CL:DEFMETHOD GET-HANDLER-OPTIONS-IMPL ((SERVER HTTP-SERVER-ASERVE) XCHG)
  (CL:LET* ((LXCHG XCHG) (LENT (%ENTITY LXCHG)))
   (CL:getf (net.aserve:entity-plist lent) 'handler-options)))

;;; (DEFUN GENERIC-RESPONSE-HANDLER ...)

(CL:DEFUN GENERIC-RESPONSE-HANDLER (LREQ LENT)
  (CL:LET*
   ((HANDLER (CL:getf (net.aserve:entity-plist lent) 'response-handler))
    (XCHG (NEW-HTTP-EXCHANGE-ASERVE LREQ LENT)))
   (CL:FUNCALL HANDLER XCHG)
   (CL:LET* ((STREAM (%STREAM XCHG)) (OUTPUT ""))
    (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING OUTPUT))
    (CL:WHEN (DEFINED? STREAM)
     (CL:SETQ OUTPUT (cl:get-output-stream-string stream)))
    (net.aserve:with-http-response (lreq lent)
          (net.aserve:with-http-body (lreq lent)
            (CL:write-string output (net.aserve:request-reply-stream lreq)))))))

(CL:DEFUN STARTUP-HTTP-SERVER-IMPL ()
  (CL:LET*
   ((*MODULE* (GET-STELLA-MODULE "/HTTP/ASERVE" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SGT-HTTP-SERVER-IMPL-ASERVE-HTTP-SERVER-ASERVE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "HTTP-SERVER-ASERVE" NULL 1))
    (CL:SETQ SGT-HTTP-SERVER-IMPL-ASERVE-HTTP-EXCHANGE-ASERVE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "HTTP-EXCHANGE-ASERVE" NULL 1))
    (CL:SETQ KWD-HTTP-SERVER-IMPL-CONTENT-TYPE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CONTENT-TYPE" NULL 2))
    (CL:SETQ SYM-HTTP-SERVER-IMPL-ASERVE-STARTUP-HTTP-SERVER-IMPL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-HTTP-SERVER-IMPL" NULL 0))
    (CL:SETQ SYM-HTTP-SERVER-IMPL-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 5)
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "HTTP-SERVER-ASERVE"
        "(DEFCLASS HTTP-SERVER-ASERVE (HTTP-SERVER) :PUBLIC? TRUE)")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION NEW-HTTP-SERVER-ASERVE)))
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "HTTP-EXCHANGE-ASERVE"
        "(DEFCLASS HTTP-EXCHANGE-ASERVE (HTTP-EXCHANGE) :SLOTS ((REQUEST :TYPE LISP-CODE :REQUIRED? TRUE) (ENTITY :TYPE LISP-CODE :REQUIRED? TRUE) (STREAM :TYPE NATIVE-OUTPUT-STREAM)))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION NEW-HTTP-EXCHANGE-ASERVE))))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (START-HTTP-SERVER-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (PORT INTEGER)))"
     (CL:FUNCTION START-HTTP-SERVER-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD STOP-HTTP-SERVER-IMPL ((SERVER HTTP-SERVER-ASERVE)))"
     (CL:FUNCTION STOP-HTTP-SERVER-IMPL) NULL)
    (DEFINE-FUNCTION-OBJECT "COERCE-LISP-VALUE-TO-STRING"
     "(DEFUN (COERCE-LISP-VALUE-TO-STRING STRING) ((LVALUE LISP-CODE)))"
     (CL:FUNCTION COERCE-LISP-VALUE-TO-STRING) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-HEADER-VALUE-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE) (KEY KEYWORD)))"
     (CL:FUNCTION GET-HEADER-VALUE-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REPLY-HEADER-VALUE-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE) (KEY KEYWORD)))"
     (CL:FUNCTION GET-REPLY-HEADER-VALUE-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD SET-REPLY-HEADER-VALUE-IMPL ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE) (KEY KEYWORD) (VALUE STRING)))"
     (CL:FUNCTION SET-REPLY-HEADER-VALUE-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REQUEST-URI-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REQUEST-URI-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REQUEST-URI-QUERY-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REQUEST-URI-QUERY-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REQUEST-URI-PATH-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REQUEST-URI-PATH-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REQUEST-METHOD-IMPL KEYWORD) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REQUEST-METHOD-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REQUEST-PROTOCOL-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REQUEST-PROTOCOL-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REQUEST-BODY-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REQUEST-BODY-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REQUEST-LOCAL-ADDRESS-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REQUEST-LOCAL-ADDRESS-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REQUEST-REMOTE-ADDRESS-IMPL STRING) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REQUEST-REMOTE-ADDRESS-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-REPLY-STREAM-IMPL NATIVE-OUTPUT-STREAM) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-REPLY-STREAM-IMPL) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-ASERVE-RESPONSE-CODE"
     "(DEFUN (GET-ASERVE-RESPONSE-CODE LISP-CODE) ((CODE KEYWORD)))"
     (CL:FUNCTION GET-ASERVE-RESPONSE-CODE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD SET-RESPONSE-CODE-IMPL ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE) (CODE KEYWORD)))"
     (CL:FUNCTION SET-RESPONSE-CODE-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD PUBLISH-FILE-IMPL ((SERVER HTTP-SERVER-ASERVE) (PATH STRING) (FILE STRING) (OPTIONS PROPERTY-LIST)))"
     (CL:FUNCTION PUBLISH-FILE-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD PUBLISH-DIRECTORY-IMPL ((SERVER HTTP-SERVER-ASERVE) (PATH STRING) (DIRECTORY STRING) (OPTIONS PROPERTY-LIST)))"
     (CL:FUNCTION PUBLISH-DIRECTORY-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD PUBLISH-HANDLER-IMPL ((SERVER HTTP-SERVER-ASERVE) (PATH STRING) (HANDLER FUNCTION-CODE) (OPTIONS PROPERTY-LIST)))"
     (CL:FUNCTION PUBLISH-HANDLER-IMPL) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (GET-HANDLER-OPTIONS-IMPL PROPERTY-LIST) ((SERVER HTTP-SERVER-ASERVE) (XCHG HTTP-EXCHANGE)))"
     (CL:FUNCTION GET-HANDLER-OPTIONS-IMPL) NULL)
    (DEFINE-FUNCTION-OBJECT "GENERIC-RESPONSE-HANDLER"
     "(DEFUN GENERIC-RESPONSE-HANDLER ((LREQ LISP-CODE) (LENT LISP-CODE)))"
     (CL:FUNCTION GENERIC-RESPONSE-HANDLER) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-HTTP-SERVER-IMPL"
     "(DEFUN STARTUP-HTTP-SERVER-IMPL () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-HTTP-SERVER-IMPL) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION
        SYM-HTTP-SERVER-IMPL-ASERVE-STARTUP-HTTP-SERVER-IMPL)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-HTTP-SERVER-IMPL-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupHttpServerImpl") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "HTTP/ASERVE")))
    (CL:IF
     (CL:AND (CL:NOT (CL:EQ *HTTP-SERVER-IMPLEMENTATION* NULL))
      (CL:NOT
       (ISA? *HTTP-SERVER-IMPLEMENTATION*
        SGT-HTTP-SERVER-IMPL-ASERVE-HTTP-SERVER-ASERVE)))
     (CL:ERROR
      (NEW-STELLA-EXCEPTION
       "Conflicting HTTP server implementation already loaded"))
     (CL:SETQ *HTTP-SERVER-IMPLEMENTATION* (NEW-HTTP-SERVER-ASERVE))))))