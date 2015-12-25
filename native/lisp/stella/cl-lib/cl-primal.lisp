;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; cl-primal.lisp

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
| Portions created by the Initial Developer are Copyright (C) 1996-2014      |
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
+---------------------------- END LICENSE BLOCK -----------------------------+
|#

(CL:IN-PACKAGE "STELLA")

;;; Auxiliary variables:

(CL:DEFVAR SGT-CL-PRIMAL-STELLA-CONS NULL)
(CL:DEFVAR SYM-CL-PRIMAL-STELLA-STARTUP-CL-PRIMAL NULL)
(CL:DEFVAR SYM-CL-PRIMAL-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL NIL KEYWORD-SYM *ROOT-MODULE* *STELLA-MODULE* SYMBOL-SYM
  SURROGATE-SYM *MODULE* NULL-INTEGER))

;;; (DEFCONSTANT CL-NIL ...)

(CL:DEFVAR CL-NIL (CL:OR))

;;; (VERBATIM :COMMON-LISP ...)

#-:lispworks
   (CL:defmethod print-object ((self (CL:eql NULL)) stream)
     (CL:write-string "NULL" stream))

;;; (VERBATIM :COMMON-LISP ...)

#-:lispworks
   (CL:defmethod print-object ((self (CL:eql NULL-INTEGER)) stream)
     (CL:write-string "NULL-INTEGER" stream))

;;; (VERBATIM :COMMON-LISP ...)

#-lispworks
   (CL:defmethod print-object ((self (CL:eql NULL-LONG-INTEGER)) stream)
     (CL:write-string "NULL-LONG-INTEGER" stream))

;;; (VERBATIM :COMMON-LISP ...)

#-:lispworks
   (CL:defmethod print-object ((self (CL:eql NULL-FLOAT)) stream)
     (CL:write-string "NULL-FLOAT" stream))

;;; (VERBATIM :COMMON-LISP ...)

#-:lispworks
   (CL:defmethod cl:print-object ((self (CL:eql CL:NIL)) stream)
     (CL:write-string "()" stream))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:T))
  (CL:EQ VALUE NULL))

;;; (VERBATIM :COMMON-LISP ...)

(%%DEFINTEGERMETHOD NULL? ((VALUE CL:FIXNUM))
  (CL:= VALUE NULL-INTEGER))

;;; (VERBATIM :COMMON-LISP ...)

(%%DEFINTEGERMETHOD NULL? ((VALUE CL:INTEGER))
  (CL:= VALUE NULL-LONG-INTEGER))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:FLOAT))
  (CL:= VALUE NULL-FLOAT))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:CHARACTER))
  (CL:EQ VALUE NULL-CHARACTER))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:STRING))
  (CL:EQ VALUE NULL-STRING))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:VECTOR))
  (CL:EQ VALUE NULL-NATIVE-VECTOR))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD NULL? ((VALUE CL:ARRAY))
  (CL:DECLARE (CL:INLINE NULL-ARRAY?))
  (NULL-ARRAY? VALUE))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:T))
  (CL:NOT (CL:EQ VALUE NULL)))

;;; (VERBATIM :COMMON-LISP ...)

(%%DEFINTEGERMETHOD DEFINED? ((VALUE CL:FIXNUM))
  (CL:NOT (CL:= VALUE NULL-INTEGER)))

;;; (VERBATIM :COMMON-LISP ...)

(%%DEFINTEGERMETHOD DEFINED? ((VALUE CL:INTEGER))
  (CL:NOT (CL:= VALUE NULL-LONG-INTEGER)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:FLOAT))
  (CL:NOT (CL:= VALUE NULL-FLOAT)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:CHARACTER))
  (CL:NOT (CL:EQ VALUE NULL-CHARACTER)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:STRING))
  (CL:NOT (CL:EQ VALUE NULL-STRING)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:VECTOR))
  (CL:NOT (CL:EQ VALUE NULL-NATIVE-VECTOR)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFMETHOD DEFINED? ((VALUE CL:ARRAY))
  (CL:DECLARE (CL:INLINE NULL-ARRAY?))
  (CL:NOT (NULL-ARRAY? VALUE)))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFUN EQ? (X Y)
  "Equality test equivalent to the C++ '==' and the Common Lisp 'EQL'."
  (CL:EQL X Y))

;;; (DEFUN (> BOOLEAN) ...)

(CL:DEFUN > (X Y)
  (CL:RETURN-FROM > (CL:> X Y)))

;;; (DEFUN (>= BOOLEAN) ...)

(CL:DEFUN >= (X Y)
  (CL:RETURN-FROM >= (CL:>= X Y)))

;;; (DEFUN (< BOOLEAN) ...)

(CL:DEFUN < (X Y)
  (CL:RETURN-FROM < (CL:< X Y)))

;;; (DEFUN (<= BOOLEAN) ...)

(CL:DEFUN <= (X Y)
  (CL:RETURN-FROM <= (CL:<= X Y)))

;;; (DEFUN (+ NUMBER) ...)

(CL:DEFUN + (CL:&REST ARGS)
  (CL:LET* ((SUM 0)) (CL:DECLARE (CL:TYPE CL:FIXNUM SUM))
   (CL:LET* ((ARG NULL) (ITER-000 ARGS))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ ARG (CL:POP ITER-000))
     (CL:SETQ SUM (CL:+ SUM ARG))))
   (CL:RETURN-FROM + SUM)))

;;; (DEFUN (- NUMBER) ...)

(CL:DEFUN - (X CL:&REST ARGS)
  (CL:IF (CL:= (CL:LENGTH ARGS) 0) (CL:RETURN-FROM - (CL:- X))
   (CL:LET* ((DIFFERENCE X))
    (CL:LET* ((ARG NULL) (ITER-000 ARGS))
     (CL:LOOP WHILE ITER-000 DO (CL:SETQ ARG (CL:POP ITER-000))
      (CL:SETQ DIFFERENCE (CL:- DIFFERENCE ARG))))
    (CL:RETURN-FROM - DIFFERENCE))))

;;; (DEFUN (* NUMBER) ...)

(CL:DEFUN * (CL:&REST ARGS)
  (CL:LET* ((PRODUCT 1)) (CL:DECLARE (CL:TYPE CL:FIXNUM PRODUCT))
   (CL:LET* ((ARG NULL) (ITER-000 ARGS))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ ARG (CL:POP ITER-000))
     (CL:SETQ PRODUCT (CL:* PRODUCT ARG))))
   (CL:RETURN-FROM * PRODUCT)))

;;; (DEFUN (/ NUMBER) ...)

(CL:DEFUN / (X CL:&REST ARGS)
  (CL:IF (CL:= (CL:LENGTH ARGS) 0) (CL:RETURN-FROM / (CL:/ X))
   (CL:LET* ((QUOTIENT X))
    (CL:LET* ((ARG NULL) (ITER-000 ARGS))
     (CL:LOOP WHILE ITER-000 DO (CL:SETQ ARG (CL:POP ITER-000))
      (CL:SETQ QUOTIENT (CL:/ QUOTIENT ARG))))
    (CL:RETURN-FROM / QUOTIENT))))

;;; (DEFUN (CEILING INTEGER) ...)

(CL:DECLAIM (CL:FTYPE (CL:FUNCTION (CL:T) CL:FIXNUM) CEILING))
(CL:DEFUN CEILING (N)
  (CL:RETURN-FROM CEILING (CL:VALUES (CL:CEILING N))))

;;; (DEFUN (FLOOR INTEGER) ...)

(CL:DECLAIM (CL:FTYPE (CL:FUNCTION (CL:T) CL:FIXNUM) FLOOR))
(CL:DEFUN FLOOR (N)
  (CL:RETURN-FROM FLOOR (CL:VALUES (CL:FLOOR N))))

;;; (DEFUN (ROUND INTEGER) ...)

(CL:DECLAIM (CL:FTYPE (CL:FUNCTION (CL:T) CL:FIXNUM) ROUND))
(CL:DEFUN ROUND (N)
  (CL:RETURN-FROM ROUND (CL:VALUES (CL:FLOOR (CL:+ N 0.5d0)))))

;;; (DEFUN (TRUNCATE INTEGER) ...)

(CL:DECLAIM (CL:FTYPE (CL:FUNCTION (CL:T) CL:FIXNUM) TRUNCATE))
(CL:DEFUN TRUNCATE (N)
  (CL:RETURN-FROM TRUNCATE (CL:VALUES (CL:TRUNCATE N))))

;;; (DEFUN (MAKE-STRING STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:FIXNUM CL:T) CL:SIMPLE-STRING) MAKE-STRING))
(CL:DEFUN MAKE-STRING (SIZE INITCHAR)
  "Return a new string filled with 'size' 'initchar's."
  (CL:DECLARE (CL:TYPE CL:FIXNUM SIZE))
  #+MCL
  (CL:CHECK-TYPE SIZE CL:FIXNUM)
  (CL:RETURN-FROM MAKE-STRING
   (CL:MAKE-STRING SIZE :INITIAL-ELEMENT INITCHAR)))

;;; (DEFUN (STRING-CONCATENATE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE
  (CL:FUNCTION (CL:SIMPLE-STRING CL:SIMPLE-STRING) CL:SIMPLE-STRING)
  STRING-CONCATENATE))
(CL:DEFUN STRING-CONCATENATE (STRING1 STRING2)
  "Return a new string representing the concatenation of
'string1' and 'string2'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING1 STRING2))
  #+MCL
  (CL:CHECK-TYPE STRING1 CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE STRING2 CL:SIMPLE-STRING)
  (CL:RETURN-FROM STRING-CONCATENATE
   (CL:CONCATENATE (CL:QUOTE CL:STRING) STRING1 STRING2)))

;;; (DEFUN (STRING-UPCASE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:SIMPLE-STRING) CL:SIMPLE-STRING)
  STRING-UPCASE))
(CL:DEFUN STRING-UPCASE (STRING)
  "Return an upper-case copy of 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (CL:RETURN-FROM STRING-UPCASE (CL:STRING-UPCASE STRING)))

;;; (DEFUN (STRING-DOWNCASE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:SIMPLE-STRING) CL:SIMPLE-STRING)
  STRING-DOWNCASE))
(CL:DEFUN STRING-DOWNCASE (STRING)
  "Return a lower-case copy of 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (CL:RETURN-FROM STRING-DOWNCASE (CL:STRING-DOWNCASE STRING)))

;;; (DEFUN (STRING-CAPITALIZE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:SIMPLE-STRING) CL:SIMPLE-STRING)
  STRING-CAPITALIZE))
(CL:DEFUN STRING-CAPITALIZE (STRING)
  "Return a capitalized version of 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (CL:RETURN-FROM STRING-CAPITALIZE (CL:STRING-CAPITALIZE STRING)))

;;; (DEFMETHOD (COPY STRING) ...)

(CL:DEFMETHOD COPY ((STRING CL:STRING))
  "Return a copy of 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (CL:RETURN-FROM COPY (CL:COPY-SEQ STRING)))

;;; (DEFMETHOD (REMOVE STRING) ...)

(CL:DEFMETHOD REMOVE ((STRING CL:STRING) CHAR)
  "Remove all occurences of 'char' from 'string'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (CL:RETURN-FROM REMOVE (CL:REMOVE CHAR STRING)))

;;; (DEFMETHOD (SUBSTITUTE MUTABLE-STRING) ...)

(CL:DEFMETHOD SUBSTITUTE ((SELF CL:STRING) NEWCHAR OLDCHAR)
  "Substitute all occurences of oldChar with newChar
in the string 'self'."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF))
  #+MCL
  (CL:CHECK-TYPE SELF CL:SIMPLE-STRING)
  (CL:RETURN-FROM SUBSTITUTE (CL:SUBSTITUTE NEWCHAR OLDCHAR SELF)))

;;; (DEFMETHOD (MEMBER? BOOLEAN) ...)

(CL:DEFMETHOD MEMBER? ((SELF CL:STRING) CHAR)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF))
  #+MCL
  (CL:CHECK-TYPE SELF CL:SIMPLE-STRING)
  (CL:RETURN-FROM MEMBER? (CL:NOT (CL:NULL (CL:FIND CHAR SELF)))))

;;; (DEFMETHOD (REST STRING) ...)

(CL:DEFMETHOD REST ((SELF CL:STRING))
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF))
  #+MCL
  (CL:CHECK-TYPE SELF CL:SIMPLE-STRING)
  (CL:RETURN-FROM REST (CL:SUBSEQ SELF 1)))

;;; (VERBATIM :COMMON-LISP ...)

 (CL:DECLAIM (CL:FTYPE (CL:FUNCTION (CL:T CL:T CL:FIXNUM) CL:FIXNUM) 
		POSITION))

;;; (DEFMETHOD (POSITION INTEGER) ...)

(CL:DEFMETHOD POSITION ((STRING CL:STRING) CHARACTER START)
  "Return the position of 'character' within 'string' (counting
from zero); or return NULL if 'character' does not occur within 'string'.
If 'start' was supplied as non-NULL, only consider the substring starting
at 'start', however, the returned position will always be relative to the
entire string."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING)
   (CL:TYPE CL:FIXNUM START))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE START CL:FIXNUM)
  (CL:WHEN (CL:= START NULL-INTEGER) (CL:SETQ START 0))
  (CL:RETURN-FROM POSITION
   (CL:OR (CL:POSITION CHARACTER STRING :START START) NULL-INTEGER)))

;;; (VERBATIM :COMMON-LISP ...)

 (CL:DECLAIM (CL:FTYPE (CL:FUNCTION (CL:T CL:T CL:FIXNUM) CL:FIXNUM) 
		LAST-POSITION))

;;; (DEFMETHOD (LAST-POSITION INTEGER) ...)

(CL:DEFMETHOD LAST-POSITION ((STRING CL:STRING) CHARACTER END)
  "Return the last position of 'character' within 'string' (counting
from zero); or return NULL if 'character' does not occur within 'string'.
If 'end' was supplied as non-NULL, only consider the substring ending
at 'end', however, the returned position will always be relative to the
entire string."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING) (CL:TYPE CL:FIXNUM END))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE END CL:FIXNUM)
  (CL:IF (CL:= END NULL-INTEGER)
   (CL:SETQ END (CL:THE CL:FIXNUM (CL:LENGTH STRING)))
   (CL:SETQ END (CL:1+ END)))
  (CL:RETURN-FROM LAST-POSITION
   (CL:OR (CL:POSITION CHARACTER STRING :END END :FROM-END CL:T)
    NULL-INTEGER)))

;;; (DEFUN (STRING-SEARCH INTEGER) ...)

(CL:DECLAIM
 (CL:FTYPE
  (CL:FUNCTION (CL:SIMPLE-STRING CL:SIMPLE-STRING CL:FIXNUM) CL:FIXNUM)
  STRING-SEARCH))
(CL:DEFUN STRING-SEARCH (STRING SUBSTRING START)
  "Return start position of the left-most occurrence right of
'start' of 'substring' in 'string'.  Return NULL if it is not a substring."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING SUBSTRING)
   (CL:TYPE CL:FIXNUM START))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE SUBSTRING CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE START CL:FIXNUM)
  (CL:WHEN (CL:= START NULL-INTEGER) (CL:SETQ START 0))
  (CL:RETURN-FROM STRING-SEARCH
   (CL:OR (CL:SEARCH SUBSTRING STRING :START2 START) NULL-INTEGER)))

;;; (DEFMETHOD (SUBSEQUENCE STRING) ...)

(CL:DEFMETHOD SUBSEQUENCE ((STRING CL:STRING) START END)
  "Return a substring of 'string' beginning at position 'start'
and ending up to but not including position 'end', counting from zero.  An
'end' value of NULL stands for the rest of the string."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING)
   (CL:TYPE CL:FIXNUM START END))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE START CL:FIXNUM)
  #+MCL
  (CL:CHECK-TYPE END CL:FIXNUM)
  (CL:LET* ((NULLEND? (CL:= END NULL-INTEGER)))
   (CL:RETURN-FROM SUBSEQUENCE
    (CL:SUBSEQ STRING START (CL:IF NULLEND? CL:NIL END)))))

;;; (DEFUN (STRINGIFY STRING) ...)

(CL:DECLAIM (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) STRINGIFY))
(CL:DEFUN STRINGIFY (EXPRESSION)
  (CL:LET* ((*PRINTPRETTY?* CL:NIL) (*PRINTREADABLY?* CL:T))
   (CL:DECLARE (CL:SPECIAL *PRINTPRETTY?* *PRINTREADABLY?*))
   (CL:RETURN-FROM STRINGIFY
    (CL:LET ((CL:*PRINT-PRETTY* CL:NIL))
     (CL:WITH-OUTPUT-TO-STRING (S) (%%PRINT-OBJECT S EXPRESSION))))))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFVAR *STANDARD-READTABLE* (CL:COPY-READTABLE CL:NIL))

;;; (VERBATIM :COMMON-LISP ...)

(CL:DEFVAR *CASE-SENSITIVE-READTABLE* (CL:COPY-READTABLE CL:NIL))

;;; (VERBATIM :COMMON-LISP ...)

(CL:progn
    #+(or :ANSI-CL :CLTL2)
    (CL:setf (CL:readtable-case *case-sensitive-readtable*) :preserve))

;;; (DEFUN (OLD-CL-READ-S-EXPRESSION-FROM-STRING OBJECT) ...)

(CL:DEFUN OLD-CL-READ-S-EXPRESSION-FROM-STRING (STRING)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (CL:LET* ((CASESENSITIVE? (%CASE-SENSITIVE? *MODULE*)))
   (CL:RETURN-FROM OLD-CL-READ-S-EXPRESSION-FROM-STRING
    (STELLA-CODE-TO-CONS-TREE
     (CL:LET
      ((CL:*PACKAGE* (CL:FIND-PACKAGE "STELLA"))
       (CL:*READTABLE*
        (CL:IF CASESENSITIVE? *CASE-SENSITIVE-READTABLE*
         *STANDARD-READTABLE*)))
      (CL:HANDLER-CASE (CL:READ-FROM-STRING STRING)
       (CL:STREAM-ERROR ()
        (CL:ERROR
         (NEW-READ-EXCEPTION ">> Unstringify: Parse error~%")))
       (CL:ERROR (C)
        (CL:ERROR
         (NEW-UNHANDLED-EXCEPTION
          (CL:FORMAT NIL
           "Unstringify: Caught unhandled exception ~A.~%" C))))))))))

;;; (DEFUN (INTEGER-TO-STRING-IN-BASE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T CL:FIXNUM) CL:SIMPLE-STRING)
  INTEGER-TO-STRING-IN-BASE))
(CL:DEFUN INTEGER-TO-STRING-IN-BASE (INTEGER BASE)
  "Return a string representation of `integer' in `base'.
Helping function for `integer-to-string' and `integer-to-hex-string'"
  (CL:DECLARE (CL:TYPE CL:FIXNUM BASE))
  #+MCL
  (CL:CHECK-TYPE BASE CL:FIXNUM)
  (CL:RETURN-FROM INTEGER-TO-STRING-IN-BASE
   (CL:let ((buffer (CL:make-string 32 :initial-element #\Space))
                (table "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ")
                (index 32)
                (digit 0)
                (negativeP CL:NIL))
         (CL:declare (CL:type CL:simple-string buffer table)
                     (CL:type CL:fixnum index digit))
         (CL:cond
          ((CL:= integer 0) "0")
          (CL:t
           (CL:when (CL:< integer 0)
             (CL:setq integer (CL:- integer))
             (CL:setq negativeP CL:t))
           (CL:loop while (CL:> integer 0)
               do (CL:decf index)
                  (CL:multiple-value-setq (integer digit)
                    (CL:floor integer base))
                  (CL:setf (CL:aref buffer index)
                    (CL:aref table digit)))
           (CL:when negativeP
             (CL:decf index)
             (CL:setf (CL:aref buffer index) #\-))
           (CL:subseq buffer index 32))))))

;;; (DEFUN (INTEGER-TO-STRING STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) INTEGER-TO-STRING))
(CL:DEFUN INTEGER-TO-STRING (INTEGER)
  "Return a string representation of `integer'."
  (CL:RETURN-FROM INTEGER-TO-STRING
   (INTEGER-TO-STRING-IN-BASE INTEGER 10)))

;;; (DEFUN (INTEGER-TO-HEX-STRING STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T) CL:SIMPLE-STRING) INTEGER-TO-HEX-STRING))
(CL:DEFUN INTEGER-TO-HEX-STRING (INTEGER)
  "Return a hex string representation of 'integer'."
  (CL:RETURN-FROM INTEGER-TO-HEX-STRING
   (INTEGER-TO-STRING-IN-BASE INTEGER 16)))

;;; (DEFUN (FLOAT-TO-STRING STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:DOUBLE-FLOAT) CL:SIMPLE-STRING)
  FLOAT-TO-STRING))
(CL:DEFUN FLOAT-TO-STRING (FLOAT)
  "Return a string representation of 'float'."
  (CL:DECLARE (CL:TYPE CL:DOUBLE-FLOAT FLOAT))
  #+MCL
  (CL:CHECK-TYPE FLOAT CL:DOUBLE-FLOAT)
  (CL:RETURN-FROM FLOAT-TO-STRING
   (CL:let ((CL:*read-default-float-format* 'CL:double-float))
         (CL:with-output-to-string (s)
           (CL:prin1 float s)))))

;;; (DEFUN (FORMAT-FLOAT STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:DOUBLE-FLOAT CL:FIXNUM) CL:SIMPLE-STRING)
  FORMAT-FLOAT))
(CL:DEFUN FORMAT-FLOAT (VALUE NDECIMALS)
  "Return a string representation of 'float' with 'nDecimals' decimal places."
  (CL:DECLARE (CL:TYPE CL:DOUBLE-FLOAT VALUE)
   (CL:TYPE CL:FIXNUM NDECIMALS))
  #+MCL
  (CL:CHECK-TYPE VALUE CL:DOUBLE-FLOAT)
  #+MCL
  (CL:CHECK-TYPE NDECIMALS CL:FIXNUM)
  (CL:RETURN-FROM FORMAT-FLOAT
   (CL:FORMAT CL-NIL "~,vF" NDECIMALS VALUE)))

;;; (DEFUN (STRING-TO-INTEGER LONG-INTEGER) ...)

(CL:DEFUN STRING-TO-INTEGER (STRING)
  "Convert the 'string' representation of an integer into an
integer and return the result."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (CL:RETURN-FROM STRING-TO-INTEGER (CL:PARSE-INTEGER STRING)))

;;; (DEFUN (STRING-TO-FLOAT FLOAT) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:SIMPLE-STRING) CL:DOUBLE-FLOAT)
  STRING-TO-FLOAT))
(CL:DEFUN STRING-TO-FLOAT (STRING)
  "Convert the 'string' representation of a float into a
float and return the result."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING STRING))
  #+MCL
  (CL:CHECK-TYPE STRING CL:SIMPLE-STRING)
  (CL:RETURN-FROM STRING-TO-FLOAT
   (CL:LET ((CL:*read-default-float-format* (CL:quote CL:double-float)))
               (CL:float (CL:read-from-string string) 0.0d0))))

;;; (DEFUN (CL-SYMBOL-TO-STELLA-SYMBOL GENERALIZED-SYMBOL) ...)

(CL:DEFUN CL-SYMBOL-TO-STELLA-SYMBOL (NAME)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
  #+MCL
  (CL:CHECK-TYPE NAME CL:SIMPLE-STRING)
  (CL:LET* ((MODULE *MODULE*) (BARENAME NAME))
   (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING BARENAME))
   (CL:WHEN (QUALIFIED-STELLA-NAME? NAME)
    (CL:MULTIPLE-VALUE-SETQ (MODULE BARENAME)
     (COMPUTE-MODULE-AND-BARE-NAME NAME))
    (CL:WHEN (STRING-EQL? BARENAME "")
     (CL:IF
      (CL:OR (CL:EQ MODULE *MODULE*) (CL:EQ MODULE *ROOT-MODULE*))
      (CL:RETURN-FROM CL-SYMBOL-TO-STELLA-SYMBOL
       (INTERN-RIGID-SYMBOL-WRT-MODULE "/" *STELLA-MODULE* SYMBOL-SYM))
      (CL:ERROR
       (NEW-READ-EXCEPTION "Empty symbol name encountered")))))
   (CL:COND
    ((KEYWORD-NAME? BARENAME)
     (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
       "Illegal read syntax: `" NAME "'")
      (CL:ERROR (NEW-READ-EXCEPTION (THE-STRING-READER STREAM-000)))))
    ((SURROGATE-NAME? BARENAME)
     (CL:RETURN-FROM CL-SYMBOL-TO-STELLA-SYMBOL
      (INTERN-RIGID-SYMBOL-WRT-MODULE
       (SUBSEQUENCE BARENAME 1 NULL-INTEGER) MODULE SURROGATE-SYM)))
    (CL:T
     (CL:RETURN-FROM CL-SYMBOL-TO-STELLA-SYMBOL
      (INTERN-RIGID-SYMBOL-WRT-MODULE BARENAME MODULE SYMBOL-SYM))))))

;;; (DEFUN (STELLA-CODE-TO-CONS-TREE OBJECT) ...)

(CL:DEFUN STELLA-CODE-TO-CONS-TREE (STELLACODE)
  (CL:COND
   ((CL:NULL STELLACODE) (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE NIL))
   ((CL:CONSP STELLACODE)
    (CL:LET* ((CONSTREE NIL))
     (CL:LOOP FOR ELEMENT IN STELLACODE DO
      (SETQ CONSTREE
       (CONS (STELLA-CODE-TO-CONS-TREE ELEMENT) CONSTREE)))
     (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE (REVERSE CONSTREE))))
   ((CL:SYMBOLP STELLACODE)
    (CL:LET* ((NAME (CL:SYMBOL-NAME STELLACODE)))
     (CL:COND
      ((CL:KEYWORDP STELLACODE)
       (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
        (INTERN-RIGID-SYMBOL-WRT-MODULE NAME *MODULE* KEYWORD-SYM)))
      ((CL:AND
        (CL:EQL (CL:SYMBOL-PACKAGE STELLACODE)
         (CL:SYMBOL-PACKAGE (CL:QUOTE CL:EVAL)))
        (CL:NOT (CL:EQ (CL:FIND-SYMBOL NAME "STELLA") STELLACODE)))
       (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
        (INTERN-COMMON-LISP-SYMBOL NAME)))
      (CL:T
       (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
        (CL-SYMBOL-TO-STELLA-SYMBOL NAME))))))
   ((CL:typep stellaCode 'CL:fixnum)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
     (WRAP-INTEGER (CL:TRUNCATE STELLACODE))))
   ((CL:INTEGERP STELLACODE)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
     (WRAP-LONG-INTEGER (CL:TRUNCATE STELLACODE))))
   ((CL:FLOATP STELLACODE)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
     (WRAP-FLOAT (CL:FLOAT (CL:float stellaCode 0.0d0) 0.0d0))))
   ((CL:STRINGP STELLACODE)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE (WRAP-STRING STELLACODE)))
   ((CL:CHARACTERP STELLACODE)
    (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE
     (WRAP-CHARACTER STELLACODE)))
   (CL:T (CL:RETURN-FROM STELLA-CODE-TO-CONS-TREE STELLACODE))))

;;; (DEFUN (CONS-TREE-TO-LISP-CODE LISP-CODE) ...)

(CL:DEFUN CONS-TREE-TO-LISP-CODE (STELLATREE)
  (CL:WHEN (CL:EQ STELLATREE NULL)
   (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE (CL:QUOTE NULL)))
  (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE STELLATREE)))
   (CL:COND
    ((CL:EQ TEST-VALUE-000 SGT-CL-PRIMAL-STELLA-CONS)
     (CL:PROGN
      (CL:IF (CL:EQ STELLATREE NIL)
       (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE CL-NIL)
       (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
        (CL:CONS (CONS-TREE-TO-LISP-CODE (%%VALUE STELLATREE))
         (CONS-TREE-TO-LISP-CODE (%%REST STELLATREE)))))))
    ((SUBTYPE-OF-KEYWORD? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (CL:INTERN (%SYMBOL-NAME STELLATREE) "KEYWORD"))))
    ((SUBTYPE-OF-SYMBOL? TEST-VALUE-000)
     (CL:PROGN
      (CL:LET*
       ((TRANSLATEDSYMBOL (CL-TRANSLATE-GLOBAL-SYMBOL STELLATREE)))
       (CL:COND
        ((SYMBOL? TRANSLATEDSYMBOL)
         (CL:LET* ((NAME (%SYMBOL-NAME TRANSLATEDSYMBOL)))
          (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING NAME))
          (CL:IF (SYMBOL-COMMON-LISP? TRANSLATEDSYMBOL)
           (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
            (CL:INTERN NAME "COMMON-LISP"))
           (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
            (CL:INTERN NAME "STELLA")))))
        (CL:T
         (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
          (CONS-TREE-TO-LISP-CODE TRANSLATEDSYMBOL)))))))
    ((SUBTYPE-OF-SURROGATE? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (CL:INTERN (CONCATENATE "@" (%SYMBOL-NAME STELLATREE))
        "STELLA"))))
    ((SUBTYPE-OF-VERBATIM-STRING? TEST-VALUE-000)
     (CL:PROGN
      (CL:LET*
       ((VERBATIMSTRING (%WRAPPER-VALUE STELLATREE))
        (PACKAGENAME (LISP-PACKAGE *MODULE*)))
       (CL:DECLARE
        (CL:TYPE CL:SIMPLE-STRING VERBATIMSTRING PACKAGENAME))
       (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
        (CL:LET
         ((CL:*PACKAGE* (CL:FIND-PACKAGE PACKAGENAME))
          (CL:*READTABLE* *STANDARD-READTABLE*))
         (CL:READ-FROM-STRING VERBATIMSTRING CL:NIL CL:NIL))))))
    ((SUBTYPE-OF-INTEGER? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-LONG-INTEGER? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-FLOAT? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-STRING? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-CHARACTER? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    ((SUBTYPE-OF-BOOLEAN? TEST-VALUE-000)
     (CL:PROGN
      (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
       (%WRAPPER-VALUE STELLATREE))))
    (CL:T
     (CL:WARN
      "cons-tree-to-lisp-code: Don't know how to convert `~A' into LISP-CODE"
      STELLATREE)
     (CL:RETURN-FROM CONS-TREE-TO-LISP-CODE
      (CL:FORMAT CL-NIL "~s" STELLATREE))))))

;;; (DEFUN (CONS-LIST-TO-LISP-LIST LISP-CODE) ...)

(CL:DEFUN CONS-LIST-TO-LISP-LIST (LIST)
  (CL:LET* ((LISPLIST CL-NIL))
   (CL:LET* ((ITEM NULL) (ITER-000 LIST))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ ITEM (%%VALUE ITER-000)) (CL:PUSH ITEM LISPLIST)
     (CL:SETQ ITER-000 (%%REST ITER-000))))
   (CL:RETURN-FROM CONS-LIST-TO-LISP-LIST (CL:NREVERSE LISPLIST))))

;;; (DEFUN (OLD-CL-READ-S-EXPRESSION OBJECT BOOLEAN) ...)

(CL:DEFUN OLD-CL-READ-S-EXPRESSION (INPUTSTREAM)
  (CL:LET*
   ((STREAM (%NATIVE-STREAM INPUTSTREAM)) (EOFVALUE :EOF)
    (CASESENSITIVE? (%CASE-SENSITIVE? *MODULE*))
    (INPUT
     (CL:LET
      ((CL:*PACKAGE* (CL:FIND-PACKAGE "STELLA"))
       (CL:*READTABLE*
        (CL:IF CASESENSITIVE? *CASE-SENSITIVE-READTABLE*
         *STANDARD-READTABLE*)))
      (CL:READ STREAM CL-NIL EOFVALUE))))
   (CL:IF (CL:EQ INPUT EOFVALUE)
    (CL:RETURN-FROM OLD-CL-READ-S-EXPRESSION (CL:VALUES NULL CL:T))
    (CL:RETURN-FROM OLD-CL-READ-S-EXPRESSION
     (CL:VALUES (STELLA-CODE-TO-CONS-TREE INPUT) CL:NIL)))))

;;; (DEFUN TOGGLE-CL-BASED-READERS ...)

(CL:DEFUN TOGGLE-CL-BASED-READERS ()
  (CL:let ((unstringify
               (CL:symbol-function 'read-s-expression-from-string))
              (oldUnstringify
               (CL:symbol-function 'old-cl-read-s-expression-from-string))
              (readSExp
               (CL:symbol-function 'read-s-expression))
              (oldReadSExp
               (CL:symbol-function 'old-cl-read-s-expression)))
       (CL:setf (CL:symbol-function 'read-s-expression-from-string)
         oldUnstringify)
       (CL:setf (CL:symbol-function 'old-cl-read-s-expression-from-string)
         unstringify)
       (CL:setf (CL:symbol-function 'read-s-expression) oldReadSExp)
       (CL:setf (CL:symbol-function 'old-cl-read-s-expression) readSExp)
       (CL:setf (CL:get 'old-cl-read-s-expression 'old-cl-readers-active?)
         (CL:not (CL:get 'old-cl-read-s-expression 'old-cl-readers-active?)))
       (CL:if (CL:get 'old-cl-read-s-expression 'old-cl-readers-active?)
           (CL:format CL:t "Activated old CL-based readers.~%")
         (CL:format CL:t "Activated new STELLA-based readers.~%")))
  :VOID)

;;; (DEFUN (NATIVE-PROBE-FILE? BOOLEAN) ...)

(CL:DEFUN NATIVE-PROBE-FILE? (FILENAME)
  (CL:RETURN-FROM NATIVE-PROBE-FILE?
   (CL:NOT (CL:NULL (CL:IGNORE-ERRORS (CL:PROBE-FILE FILENAME))))))

;;; (DEFUN (NATIVE-FILE-WRITE-DATE CALENDAR-DATE) ...)

(CL:DEFUN NATIVE-FILE-WRITE-DATE (FILENAME)
  (CL:RETURN-FROM NATIVE-FILE-WRITE-DATE
   (CL:LET ((DATE (CL:FILE-WRITE-DATE FILENAME)))
    (CL:IF (CL:NULL DATE) NULL
     (NATIVE-DATE-TIME-TO-CALENDAR-DATE DATE)))))

;;; (DEFUN (NATIVE-FILE-LENGTH LONG-INTEGER) ...)

(CL:DEFUN NATIVE-FILE-LENGTH (FILENAME)
  (CL:RETURN-FROM NATIVE-FILE-LENGTH
   (CL:WITH-OPEN-FILE (FSTREAM FILENAME :DIRECTION :INPUT)
    (CL:FILE-LENGTH FSTREAM))))

;;; (DEFUN NATIVE-DELETE-FILE ...)

(CL:DEFUN NATIVE-DELETE-FILE (FILENAME)
  (CL:DELETE-FILE FILENAME)
  :VOID)

;;; (DEFUN NATIVE-RENAME-FILE ...)

(CL:DEFUN NATIVE-RENAME-FILE (FROMFILE TOFILE)
  (CL:RENAME-FILE FROMFILE TOFILE)
  :VOID)

;;; (DEFUN (GET-TICKTOCK TICKTOCK) ...)

(CL:DEFUN GET-TICKTOCK ()
  (CL:RETURN-FROM GET-TICKTOCK (CL:GET-INTERNAL-RUN-TIME)))

;;; (DEFUN (TICKTOCK-DIFFERENCE FLOAT) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:T CL:T) CL:DOUBLE-FLOAT)
  TICKTOCK-DIFFERENCE))
(CL:DEFUN TICKTOCK-DIFFERENCE (T1 T2)
  "The difference in two TICKTOCK time values in seconds.
The resolution is implementation dependent but will normally be some fractional
value of a second."
  (CL:RETURN-FROM TICKTOCK-DIFFERENCE
   (CL:/ (CL:FLOAT (CL:- T2 T1) 0.0D0)
    (CL:FLOAT CL:INTERNAL-TIME-UNITS-PER-SECOND 0.0D0))))

;;; (DEFUN (TICKTOCK-RESOLUTION FLOAT) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION () CL:DOUBLE-FLOAT) TICKTOCK-RESOLUTION))
(CL:DEFUN TICKTOCK-RESOLUTION ()
  "The minimum theoretically detectable resolution of the
difference in two TICKTOCK time values in seconds.  This resolution is
implementation dependent.  It may also not be realizable in practice, since
the timing grain size may be larger than this resolution."
  (CL:RETURN-FROM TICKTOCK-RESOLUTION
   (CL:/ (CL:FLOAT CL:INTERNAL-TIME-UNITS-PER-SECOND 0.0D0))))

(CL:DEFUN STARTUP-CL-PRIMAL ()
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ SGT-CL-PRIMAL-STELLA-CONS
     (INTERN-RIGID-SYMBOL-WRT-MODULE "CONS" NULL 1))
    (CL:SETQ SYM-CL-PRIMAL-STELLA-STARTUP-CL-PRIMAL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-CL-PRIMAL" NULL 0))
    (CL:SETQ SYM-CL-PRIMAL-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL
      0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT ">"
     "(DEFUN (> BOOLEAN) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION >)
     NULL)
    (DEFINE-FUNCTION-OBJECT ">="
     "(DEFUN (>= BOOLEAN) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION >=)
     NULL)
    (DEFINE-FUNCTION-OBJECT "<"
     "(DEFUN (< BOOLEAN) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION <)
     NULL)
    (DEFINE-FUNCTION-OBJECT "<="
     "(DEFUN (<= BOOLEAN) ((X NUMBER) (Y NUMBER)))" (CL:FUNCTION <=)
     NULL)
    (DEFINE-FUNCTION-OBJECT "+"
     "(DEFUN (+ NUMBER) (|&REST| (ARGS NUMBER)))" (CL:FUNCTION +) NULL)
    (DEFINE-FUNCTION-OBJECT "-"
     "(DEFUN (- NUMBER) ((X NUMBER) |&REST| (ARGS NUMBER)))"
     (CL:FUNCTION -) NULL)
    (DEFINE-FUNCTION-OBJECT "*"
     "(DEFUN (* NUMBER) (|&REST| (ARGS NUMBER)))" (CL:FUNCTION *) NULL)
    (DEFINE-FUNCTION-OBJECT "/"
     "(DEFUN (/ NUMBER) ((X NUMBER) |&REST| (ARGS NUMBER)))"
     (CL:FUNCTION /) NULL)
    (DEFINE-FUNCTION-OBJECT "CEILING"
     "(DEFUN (CEILING INTEGER) ((N NUMBER)))" (CL:FUNCTION CEILING)
     NULL)
    (DEFINE-FUNCTION-OBJECT "FLOOR"
     "(DEFUN (FLOOR INTEGER) ((N NUMBER)))" (CL:FUNCTION FLOOR) NULL)
    (DEFINE-FUNCTION-OBJECT "ROUND"
     "(DEFUN (ROUND INTEGER) ((N NUMBER)))" (CL:FUNCTION ROUND) NULL)
    (DEFINE-FUNCTION-OBJECT "TRUNCATE"
     "(DEFUN (TRUNCATE INTEGER) ((N NUMBER)))" (CL:FUNCTION TRUNCATE)
     NULL)
    (DEFINE-FUNCTION-OBJECT "MAKE-STRING"
     "(DEFUN (MAKE-STRING STRING) ((SIZE INTEGER) (INITCHAR CHARACTER)) :DOCUMENTATION \"Return a new string filled with 'size' 'initchar's.\" :PUBLIC? TRUE)"
     (CL:FUNCTION MAKE-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-CONCATENATE"
     "(DEFUN (STRING-CONCATENATE STRING) ((STRING1 STRING) (STRING2 STRING)) :DOCUMENTATION \"Return a new string representing the concatenation of
'string1' and 'string2'.\")" (CL:FUNCTION STRING-CONCATENATE) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-UPCASE"
     "(DEFUN (STRING-UPCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return an upper-case copy of 'string'.\")"
     (CL:FUNCTION STRING-UPCASE) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-DOWNCASE"
     "(DEFUN (STRING-DOWNCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return a lower-case copy of 'string'.\")"
     (CL:FUNCTION STRING-DOWNCASE) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-CAPITALIZE"
     "(DEFUN (STRING-CAPITALIZE STRING) ((STRING STRING)) :DOCUMENTATION \"Return a capitalized version of 'string'.\")"
     (CL:FUNCTION STRING-CAPITALIZE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (COPY STRING) ((STRING STRING)) :DOCUMENTATION \"Return a copy of 'string'.\")"
     (CL:FUNCTION COPY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (REMOVE STRING) ((STRING STRING) (CHAR CHARACTER)) :DOCUMENTATION \"Remove all occurences of 'char' from 'string'.\")"
     (CL:FUNCTION REMOVE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SUBSTITUTE MUTABLE-STRING) ((SELF MUTABLE-STRING) (NEWCHAR CHARACTER) (OLDCHAR CHARACTER)) :DOCUMENTATION \"Substitute all occurences of oldChar with newChar
in the string 'self'.\")" (CL:FUNCTION SUBSTITUTE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF STRING) (CHAR CHARACTER)))"
     (CL:FUNCTION MEMBER?) NULL)
    (DEFINE-METHOD-OBJECT "(DEFMETHOD (REST STRING) ((SELF STRING)))"
     (CL:FUNCTION REST) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (POSITION INTEGER) ((STRING STRING) (CHARACTER CHARACTER) (START INTEGER)) :DOCUMENTATION \"Return the position of 'character' within 'string' (counting
from zero); or return NULL if 'character' does not occur within 'string'.
If 'start' was supplied as non-NULL, only consider the substring starting
at 'start', however, the returned position will always be relative to the
entire string.\" :PUBLIC? TRUE)" (CL:FUNCTION POSITION) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LAST-POSITION INTEGER) ((STRING STRING) (CHARACTER CHARACTER) (END INTEGER)) :DOCUMENTATION \"Return the last position of 'character' within 'string' (counting
from zero); or return NULL if 'character' does not occur within 'string'.
If 'end' was supplied as non-NULL, only consider the substring ending
at 'end', however, the returned position will always be relative to the
entire string.\" :PUBLIC? TRUE)" (CL:FUNCTION LAST-POSITION) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-SEARCH"
     "(DEFUN (STRING-SEARCH INTEGER) ((STRING STRING) (SUBSTRING STRING) (START INTEGER)) :DOCUMENTATION \"Return start position of the left-most occurrence right of
'start' of 'substring' in 'string'.  Return NULL if it is not a substring.\")"
     (CL:FUNCTION STRING-SEARCH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SUBSEQUENCE STRING) ((STRING STRING) (START INTEGER) (END INTEGER)) :DOCUMENTATION \"Return a substring of 'string' beginning at position 'start'
and ending up to but not including position 'end', counting from zero.  An
'end' value of NULL stands for the rest of the string.\")"
     (CL:FUNCTION SUBSEQUENCE) NULL)
    (DEFINE-FUNCTION-OBJECT "STRINGIFY"
     "(DEFUN (STRINGIFY STRING) ((EXPRESSION OBJECT)))"
     (CL:FUNCTION STRINGIFY) NULL)
    (DEFINE-FUNCTION-OBJECT "OLD-CL-READ-S-EXPRESSION-FROM-STRING"
     "(DEFUN (OLD-CL-READ-S-EXPRESSION-FROM-STRING OBJECT) ((STRING STRING)))"
     (CL:FUNCTION OLD-CL-READ-S-EXPRESSION-FROM-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "INTEGER-TO-STRING-IN-BASE"
     "(DEFUN (INTEGER-TO-STRING-IN-BASE STRING) ((INTEGER LONG-INTEGER) (BASE INTEGER)) :PUBLIC? TRUE :DOCUMENTATION \"Return a string representation of `integer' in `base'.
Helping function for `integer-to-string' and `integer-to-hex-string'\")"
     (CL:FUNCTION INTEGER-TO-STRING-IN-BASE) NULL)
    (DEFINE-FUNCTION-OBJECT "INTEGER-TO-STRING"
     "(DEFUN (INTEGER-TO-STRING STRING) ((INTEGER LONG-INTEGER)) :DOCUMENTATION \"Return a string representation of `integer'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION INTEGER-TO-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "INTEGER-TO-HEX-STRING"
     "(DEFUN (INTEGER-TO-HEX-STRING STRING) ((INTEGER LONG-INTEGER)) :DOCUMENTATION \"Return a hex string representation of 'integer'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION INTEGER-TO-HEX-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "FLOAT-TO-STRING"
     "(DEFUN (FLOAT-TO-STRING STRING) ((FLOAT FLOAT)) :DOCUMENTATION \"Return a string representation of 'float'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION FLOAT-TO-STRING) NULL)
    (DEFINE-FUNCTION-OBJECT "FORMAT-FLOAT"
     "(DEFUN (FORMAT-FLOAT STRING) ((VALUE FLOAT) (NDECIMALS INTEGER)) :DOCUMENTATION \"Return a string representation of 'float' with 'nDecimals' decimal places.\" :PUBLIC? TRUE)"
     (CL:FUNCTION FORMAT-FLOAT) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-TO-INTEGER"
     "(DEFUN (STRING-TO-INTEGER LONG-INTEGER) ((STRING STRING)) :DOCUMENTATION \"Convert the 'string' representation of an integer into an
integer and return the result.\" :PUBLIC? TRUE)"
     (CL:FUNCTION STRING-TO-INTEGER) NULL)
    (DEFINE-FUNCTION-OBJECT "STRING-TO-FLOAT"
     "(DEFUN (STRING-TO-FLOAT FLOAT) ((STRING STRING)) :DOCUMENTATION \"Convert the 'string' representation of a float into a
float and return the result.\" :PUBLIC? TRUE)"
     (CL:FUNCTION STRING-TO-FLOAT) NULL)
    (DEFINE-FUNCTION-OBJECT "CL-SYMBOL-TO-STELLA-SYMBOL"
     "(DEFUN (CL-SYMBOL-TO-STELLA-SYMBOL GENERALIZED-SYMBOL) ((NAME STRING)))"
     (CL:FUNCTION CL-SYMBOL-TO-STELLA-SYMBOL) NULL)
    (DEFINE-FUNCTION-OBJECT "STELLA-CODE-TO-CONS-TREE"
     "(DEFUN (STELLA-CODE-TO-CONS-TREE OBJECT) ((STELLACODE LISP-CODE)))"
     (CL:FUNCTION STELLA-CODE-TO-CONS-TREE) NULL)
    (DEFINE-FUNCTION-OBJECT "CONS-TREE-TO-LISP-CODE"
     "(DEFUN (CONS-TREE-TO-LISP-CODE LISP-CODE) ((STELLATREE OBJECT)))"
     (CL:FUNCTION CONS-TREE-TO-LISP-CODE) NULL)
    (DEFINE-FUNCTION-OBJECT "CONS-LIST-TO-LISP-LIST"
     "(DEFUN (CONS-LIST-TO-LISP-LIST LISP-CODE) ((LIST CONS)))"
     (CL:FUNCTION CONS-LIST-TO-LISP-LIST) NULL)
    (DEFINE-FUNCTION-OBJECT "OLD-CL-READ-S-EXPRESSION"
     "(DEFUN (OLD-CL-READ-S-EXPRESSION OBJECT BOOLEAN) ((INPUTSTREAM INPUT-STREAM)))"
     (CL:FUNCTION OLD-CL-READ-S-EXPRESSION) NULL)
    (DEFINE-FUNCTION-OBJECT "TOGGLE-CL-BASED-READERS"
     "(DEFUN TOGGLE-CL-BASED-READERS ())"
     (CL:FUNCTION TOGGLE-CL-BASED-READERS) NULL)
    (DEFINE-FUNCTION-OBJECT "NATIVE-PROBE-FILE?"
     "(DEFUN (NATIVE-PROBE-FILE? BOOLEAN) ((FILENAME FILE-NAME)))"
     (CL:FUNCTION NATIVE-PROBE-FILE?) NULL)
    (DEFINE-FUNCTION-OBJECT "NATIVE-FILE-WRITE-DATE"
     "(DEFUN (NATIVE-FILE-WRITE-DATE CALENDAR-DATE) ((FILENAME FILE-NAME)))"
     (CL:FUNCTION NATIVE-FILE-WRITE-DATE) NULL)
    (DEFINE-FUNCTION-OBJECT "NATIVE-FILE-LENGTH"
     "(DEFUN (NATIVE-FILE-LENGTH LONG-INTEGER) ((FILENAME FILE-NAME)))"
     (CL:FUNCTION NATIVE-FILE-LENGTH) NULL)
    (DEFINE-FUNCTION-OBJECT "NATIVE-DELETE-FILE"
     "(DEFUN NATIVE-DELETE-FILE ((FILENAME FILE-NAME)))"
     (CL:FUNCTION NATIVE-DELETE-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "NATIVE-RENAME-FILE"
     "(DEFUN NATIVE-RENAME-FILE ((FROMFILE FILE-NAME) (TOFILE FILE-NAME)))"
     (CL:FUNCTION NATIVE-RENAME-FILE) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-TICKTOCK"
     "(DEFUN (GET-TICKTOCK TICKTOCK) () :PUBLIC? TRUE)"
     (CL:FUNCTION GET-TICKTOCK) NULL)
    (DEFINE-FUNCTION-OBJECT "TICKTOCK-DIFFERENCE"
     "(DEFUN (TICKTOCK-DIFFERENCE FLOAT) ((T1 TICKTOCK) (T2 TICKTOCK)) :DOCUMENTATION \"The difference in two TICKTOCK time values in seconds.
The resolution is implementation dependent but will normally be some fractional
value of a second.\" :PUBLIC? TRUE)" (CL:FUNCTION TICKTOCK-DIFFERENCE)
     NULL)
    (DEFINE-FUNCTION-OBJECT "TICKTOCK-RESOLUTION"
     "(DEFUN (TICKTOCK-RESOLUTION FLOAT) () :DOCUMENTATION \"The minimum theoretically detectable resolution of the
difference in two TICKTOCK time values in seconds.  This resolution is
implementation dependent.  It may also not be realizable in practice, since
the timing grain size may be larger than this resolution.\" :PUBLIC? TRUE)"
     (CL:FUNCTION TICKTOCK-RESOLUTION) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-CL-PRIMAL"
     "(DEFUN STARTUP-CL-PRIMAL () :PUBLIC? TRUE)"
     (CL:FUNCTION STARTUP-CL-PRIMAL) NULL)
    (CL:LET*
     ((FUNCTION
       (LOOKUP-FUNCTION SYM-CL-PRIMAL-STELLA-STARTUP-CL-PRIMAL)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-CL-PRIMAL-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupClPrimal") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (%IN-MODULE (COPY-CONS-TREE (WRAP-STRING "/STELLA")))
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFCONSTANT CL-NIL LISP-CODE (VERBATIM :COMMON-LISP (CL:OR)))")))
  :VOID)
