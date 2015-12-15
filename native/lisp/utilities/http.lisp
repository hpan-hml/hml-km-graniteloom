;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; http.lisp

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
| Portions created by the Initial Developer are Copyright (C) 2001-2006      |
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

(CL:DEFVAR KWD-HTTP-MAC NULL)
(CL:DEFVAR SYM-HTTP-STELLA-LET NULL)
(CL:DEFVAR SYM-HTTP-STELLA-INPUT-STREAM NULL)
(CL:DEFVAR SYM-HTTP-STELLA-NULL NULL)
(CL:DEFVAR SYM-HTTP-STELLA-UNWIND-PROTECT NULL)
(CL:DEFVAR SYM-HTTP-STELLA-PROGN NULL)
(CL:DEFVAR SYM-HTTP-STELLA-SETQ NULL)
(CL:DEFVAR SYM-HTTP-UTILITIES-OPEN-URL-STREAM NULL)
(CL:DEFVAR SYM-HTTP-STELLA-WHEN NULL)
(CL:DEFVAR SYM-HTTP-STELLA-DEFINED? NULL)
(CL:DEFVAR SYM-HTTP-STELLA-FREE NULL)
(CL:DEFVAR SYM-HTTP-UTILITIES-STARTUP-HTTP NULL)
(CL:DEFVAR SYM-HTTP-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM
 (CL:SPECIAL *STARTUP-TIME-PHASE* *MODULE* NIL STANDARD-OUTPUT
  NULL-CHARACTER NULL-INTEGER))

;;; (DEFCLASS HTTP-EXCEPTION ...)

(CL:DEFINE-CONDITION HTTP-EXCEPTION (READ-EXCEPTION)
  ((ERROR-CODE :TYPE CL:FIXNUM :INITFORM NULL-INTEGER :ALLOCATION
    :INSTANCE :ACCESSOR %ERROR-CODE)))

(CL:DEFUN NEW-HTTP-EXCEPTION (MESSAGE)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING MESSAGE))
  #+MCL
  (CL:CHECK-TYPE MESSAGE CL:SIMPLE-STRING)
  (CL:LET* ((SELF NULL))
   (CL:SETQ SELF
    (CL:MAKE-CONDITION (CL:QUOTE HTTP-EXCEPTION)
     *CONDITION-MESSAGE-KEYWORD*
     (REPLACE-SUBSTRINGS MESSAGE "~~" "~")))
   (CL:SETF (%ERROR-CODE SELF) NULL-INTEGER) SELF))

;;; (DEFUN (HANDLE-HTTP-HEADER-FIRST-LINE STRING INTEGER STRING) ...)

(CL:DECLAIM
 (CL:FTYPE
  (CL:FUNCTION (CL:SIMPLE-STRING CL:T)
   (CL:VALUES CL:SIMPLE-STRING CL:FIXNUM CL:SIMPLE-STRING))
  HANDLE-HTTP-HEADER-FIRST-LINE))
(CL:DEFUN HANDLE-HTTP-HEADER-FIRST-LINE (LINE FIELDS)
  "Handles the first line of an http header.  
Returns version, response code, response message.  The first
line is inserted into `fields' fields with the empty string key \"\"
This is a low-level utility routine that can be used to build custom
message parsing code."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING LINE))
  #+MCL
  (CL:CHECK-TYPE LINE CL:SIMPLE-STRING)
  (CL:LET*
   ((SPACE1 (POSITION LINE #\  0))
    (SPACE2
     (CL:IF (NULL? SPACE1) NULL-INTEGER
      (POSITION LINE #\  (CL:1+ SPACE1)))))
   (CL:DECLARE (CL:TYPE CL:FIXNUM SPACE1 SPACE2))
   (CL:WHEN (NULL? SPACE2)
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
      "Malformed header line: `" LINE "'")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))
   (INSERT-AT FIELDS (WRAP-STRING "") (WRAP-STRING LINE))
   (CL:VALUES (SUBSEQUENCE LINE 0 SPACE1)
    (STRING-TO-INTEGER (SUBSEQUENCE LINE (CL:1+ SPACE1) SPACE2))
    (SUBSEQUENCE LINE (CL:1+ SPACE2) NULL-INTEGER))))

;;; (DEFUN HANDLE-HTTP-HEADER-OTHER-LINE ...)

(CL:DEFUN HANDLE-HTTP-HEADER-OTHER-LINE (LINE FIELDS)
  "Handles header lines other than the first one.
Each such line is inserted into `fields' as keyword value pairs.
This is a low-level utility routine that can be used to build custom
message parsing code."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING LINE))
  #+MCL
  (CL:CHECK-TYPE LINE CL:SIMPLE-STRING)
  (CL:LET* ((COLON-POSITION (POSITION LINE #\: 0)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM COLON-POSITION))
   (CL:IF (NULL? COLON-POSITION)
    (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000) "Bad header seen: `"
      LINE "'")
     (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))
    (INSERT-AT FIELDS (WRAP-STRING (SUBSEQUENCE LINE 0 COLON-POSITION))
     (WRAP-STRING
      (SUBSEQUENCE LINE (CL:+ COLON-POSITION 2) NULL-INTEGER))))))

;;; (DEFUN (DECOMPOSE-INTERNET-URL STRING STRING STRING STRING STRING STRING STRING) ...)

(CL:DECLAIM
 (CL:FTYPE
  (CL:FUNCTION (CL:SIMPLE-STRING)
   (CL:VALUES CL:SIMPLE-STRING CL:SIMPLE-STRING CL:SIMPLE-STRING
    CL:SIMPLE-STRING CL:SIMPLE-STRING CL:SIMPLE-STRING
    CL:SIMPLE-STRING))
  DECOMPOSE-INTERNET-URL))
(CL:DEFUN DECOMPOSE-INTERNET-URL (URL)
  "Takes an internet style URL and returns the components of
that URL as specified below.  Missing elements return the empty string \"\".
  PROTOCOL USERNAME:PASSWORD DOMAIN PORT PATH QUERY FRAGMENT

  o Protocol.  The access protocol.

       Those schemes which refer to internet protocols mostly have a
       common syntax for the rest of the object name. This starts with a
       double slash '//' to indicate its presence, and continues until
       the following slash '/':

  o An optional user name, if required (as it is with a few FTP servers).
    The password, if present, follows the user name, separated from it by a colon;
    the user name and optional password are followed by a commercial at sign '@'. 
  o The internet domain name of the host
  o The port number, if it is not the default number for the protocol,
    is given in decimal notation after a colon.
  o Path The path is a hierarchical representation of a particular path. It may 
    define details of how the client should communicate with the server, including
    information to be passed transparently to the server without any processing by
    the client.
    The path is interpreted in a manner dependent on the scheme being used.
    Generally, the reserved slash '/' character (ASCII 2F hex) denotes a level in a
    hierarchical structure, the higher level part to the left of the slash.
  o Query is the part of the hierarchical information following a '?' character.
  o Fragment is the part of the hierarchical information following a '#' character.

References:  http://www.gbiv.com/protocols/uri/rfc/rfc3986.html
"
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING URL))
  #+MCL
  (CL:CHECK-TYPE URL CL:SIMPLE-STRING)
  (CL:LET*
   ((FIELD-START 0)
    (FIELD-END (STRING-SEARCH URL (MAKE-STRING 1 #\:) 0)) (PROTOCOL "")
    (USER-INFORMATION "") (DOMAIN-NAME "") (PORT-NUMBER "") (PATH "")
    (QUERY "") (FRAGMENT ""))
   (CL:DECLARE (CL:TYPE CL:FIXNUM FIELD-START FIELD-END)
    (CL:TYPE CL:SIMPLE-STRING PROTOCOL USER-INFORMATION DOMAIN-NAME
     PORT-NUMBER PATH QUERY FRAGMENT))
   (CL:WHEN (DEFINED? FIELD-END)
    (CL:SETQ PROTOCOL (SUBSEQUENCE URL 0 FIELD-END))
    (CL:IF (CL:= FIELD-END (STRING-SEARCH URL "://" FIELD-END))
     (CL:SETQ FIELD-END (CL:+ FIELD-END 3))
     (CL:SETQ FIELD-END (CL:1+ FIELD-END)))
    (CL:SETQ FIELD-START FIELD-END)
    (CL:SETQ FIELD-END (POSITION URL #\/ FIELD-START))
    (CL:SETQ DOMAIN-NAME (SUBSEQUENCE URL FIELD-START FIELD-END))
    (CL:SETQ FIELD-START FIELD-END))
   (CL:SETQ FIELD-END (POSITION URL #\? FIELD-START))
   (CL:IF (DEFINED? FIELD-END)
    (CL:PROGN (CL:SETQ PATH (SUBSEQUENCE URL FIELD-START FIELD-END))
     (CL:SETQ FIELD-START (CL:1+ FIELD-END))
     (CL:SETQ FIELD-END (POSITION URL #\# FIELD-START))
     (CL:IF (DEFINED? FIELD-END)
      (CL:PROGN (CL:SETQ QUERY (SUBSEQUENCE URL FIELD-START FIELD-END))
       (CL:SETQ FIELD-START (CL:1+ FIELD-END))
       (CL:SETQ FRAGMENT (SUBSEQUENCE URL FIELD-START NULL-INTEGER)))
      (CL:SETQ QUERY (SUBSEQUENCE URL FIELD-START NULL-INTEGER))))
    (CL:PROGN (CL:SETQ FIELD-END (POSITION URL #\# FIELD-START))
     (CL:IF (DEFINED? FIELD-END)
      (CL:PROGN (CL:SETQ PATH (SUBSEQUENCE URL FIELD-START FIELD-END))
       (CL:SETQ FIELD-START (CL:1+ FIELD-END))
       (CL:SETQ FRAGMENT (SUBSEQUENCE URL FIELD-START NULL-INTEGER)))
      (CL:SETQ PATH (SUBSEQUENCE URL FIELD-START NULL-INTEGER)))))
   (CL:SETQ FIELD-END (POSITION DOMAIN-NAME #\@ 0))
   (CL:WHEN (DEFINED? FIELD-END)
    (CL:SETQ USER-INFORMATION (SUBSEQUENCE DOMAIN-NAME 0 FIELD-END))
    (CL:SETQ DOMAIN-NAME
     (SUBSEQUENCE DOMAIN-NAME (CL:1+ FIELD-END) NULL-INTEGER)))
   (CL:SETQ FIELD-START (POSITION DOMAIN-NAME #\: 0))
   (CL:WHEN (DEFINED? FIELD-START)
    (CL:SETQ PORT-NUMBER
     (SUBSEQUENCE DOMAIN-NAME (CL:1+ FIELD-START) NULL-INTEGER))
    (CL:SETQ DOMAIN-NAME (SUBSEQUENCE DOMAIN-NAME 0 FIELD-START)))
   (CL:VALUES PROTOCOL USER-INFORMATION DOMAIN-NAME PORT-NUMBER PATH
    QUERY FRAGMENT)))

;;; (DEFUN (READ-HTTP-HEADER INTEGER STRING STRING) ...)

(CL:DECLAIM
 (CL:FTYPE
  (CL:FUNCTION (CL:T CL:T)
   (CL:VALUES CL:FIXNUM CL:SIMPLE-STRING CL:SIMPLE-STRING))
  READ-HTTP-HEADER))
(CL:DEFUN READ-HTTP-HEADER (STREAM FIELDS)
  "Reads the HTTP header from `stream', parses the header fields
and stores the results in `fields'.  The first line of the response will be
stored in `fields' with the empty string \"\" as the key.  Other values will
have the header name as the key.  The first return value is the response code
of the HTTP request.  A response of 200 indicates success.  Other common
responses are 404 (page not found).  The second return value is the message
associated with the code.  The third return value is the version information.
If the stream ends before a valid header is read, then `null' is returned for
all values."
  (CL:LET*
   ((BUFFER (MAKE-RAW-MUTABLE-STRING 1024)) (FIRST-LINE? CL:T)
    (RESPONSE-CODE NULL-INTEGER) (RESPONSE-MESSAGE STELLA::NULL-STRING)
    (VERSION-STRING STELLA::NULL-STRING) (CH NULL-CHARACTER) (INDEX 0)
    (EOF? CL:NIL) (RETURN? CL:NIL))
   (CL:DECLARE
    (CL:TYPE CL:SIMPLE-STRING BUFFER RESPONSE-MESSAGE VERSION-STRING)
    (CL:TYPE CL:FIXNUM RESPONSE-CODE INDEX))
   (CL:MULTIPLE-VALUE-SETQ (CH EOF?) (READ-CHARACTER STREAM))
   (CL:LOOP WHILE (CL:NOT EOF?) DO
    (CL:CASE CH
     (#\Return
      (CL:IF RETURN? (CL:PROGN (CL:RETURN)) (CL:SETQ RETURN? CL:T)))
     (#\Linefeed (CL:WHEN (CL:NOT RETURN?))
      (CL:COND ((CL:= INDEX 0) (CL:RETURN))
       (FIRST-LINE?
        (CL:MULTIPLE-VALUE-SETQ
         (VERSION-STRING RESPONSE-CODE RESPONSE-MESSAGE)
         (HANDLE-HTTP-HEADER-FIRST-LINE (SUBSEQUENCE BUFFER 0 INDEX)
          FIELDS))
        (CL:SETQ FIRST-LINE? CL:NIL))
       (CL:T
        (HANDLE-HTTP-HEADER-OTHER-LINE (SUBSEQUENCE BUFFER 0 INDEX)
         FIELDS)))
      (CL:SETQ RETURN? CL:NIL) (CL:SETQ INDEX 0))
     (CL:OTHERWISE
      (CL:WHEN RETURN?
       (CL:COND ((CL:= INDEX 0) (CL:RETURN))
        (FIRST-LINE?
         (CL:MULTIPLE-VALUE-SETQ
          (VERSION-STRING RESPONSE-CODE RESPONSE-MESSAGE)
          (HANDLE-HTTP-HEADER-FIRST-LINE (SUBSEQUENCE BUFFER 0 INDEX)
           FIELDS))
         (CL:SETQ FIRST-LINE? CL:NIL))
        (CL:T
         (HANDLE-HTTP-HEADER-OTHER-LINE (SUBSEQUENCE BUFFER 0 INDEX)
          FIELDS))))
      (CL:LET ((SELF BUFFER) (CH CH) (POSITION INDEX))
       (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF)
        (CL:TYPE CL:FIXNUM POSITION))
       (SETF
        (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF)
         (CL:THE CL:FIXNUM POSITION))
        (CL:THE CL:CHARACTER CH)))
      (CL:SETQ INDEX (CL:1+ INDEX)) (CL:SETQ RETURN? CL:NIL)))
    (CL:MULTIPLE-VALUE-SETQ (CH EOF?) (READ-CHARACTER STREAM)))
   (CL:VALUES RESPONSE-CODE RESPONSE-MESSAGE VERSION-STRING)))

;;; (DEFUN WRITE-HTTP-REQUEST ...)

(CL:DEFUN WRITE-HTTP-REQUEST (STREAM METHOD HOST URL-PATH HEADERS CONTENT)
  "Send `content' as an HTTP 1.0 request on `stream' using `method'.
The request is sent to `url-path' at `host'.  The `stream' must be a TCP-stream
that is connected to `host' at the appropriate port."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING METHOD HOST URL-PATH CONTENT))
  #+MCL
  (CL:CHECK-TYPE METHOD CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE HOST CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE URL-PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE CONTENT CL:SIMPLE-STRING)
  (%%PRINT-STREAM (%NATIVE-STREAM STREAM) METHOD " " URL-PATH
   " HTTP/1.0
")
  (CL:WHEN (CL:NOT (CL:EQ HOST STELLA::NULL-STRING))
   (CL:WHEN (CL:EQ HEADERS NULL) (CL:SETQ HEADERS (NEW-PROPERTY-LIST)))
   (INSERT-AT HEADERS (WRAP-STRING "Host") (WRAP-STRING HOST)))
  (CL:WHEN (CL:NOT (CL:EQ CONTENT STELLA::NULL-STRING))
   (CL:WHEN (CL:EQ HEADERS NULL) (CL:SETQ HEADERS (NEW-PROPERTY-LIST)))
   (INSERT-AT HEADERS (WRAP-STRING "Content-Length")
    (WRAP-STRING
     (INTEGER-TO-STRING (CL:THE CL:FIXNUM (CL:LENGTH CONTENT))))))
  (CL:WHEN (CL:NOT (CL:EQ HEADERS NULL))
   (CL:LET*
    ((KEY NULL) (VALUE NULL) (ITER-000 (ALLOCATE-ITERATOR HEADERS)))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ KEY (%KEY ITER-000))
     (CL:SETQ VALUE (%VALUE ITER-000))
     (%%PRINT-STREAM (%NATIVE-STREAM STREAM) (UNWRAP-STRING KEY) ": "
      (UNWRAP-STRING VALUE) "
"))))
  (%%PRINT-STREAM (%NATIVE-STREAM STREAM) "
")
  (CL:WHEN (CL:NOT (CL:EQ CONTENT STELLA::NULL-STRING))
   (%%PRINT-STREAM (%NATIVE-STREAM STREAM) CONTENT))
  (FLUSH-OUTPUT STREAM))

;;; (DEFUN WRITE-POST-REQUEST ...)

(CL:DEFUN WRITE-POST-REQUEST (STREAM HOST URL-PATH HEADERS CONTENT)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING HOST URL-PATH CONTENT))
  #+MCL
  (CL:CHECK-TYPE HOST CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE URL-PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE CONTENT CL:SIMPLE-STRING)
  (WRITE-HTTP-REQUEST STREAM "POST" HOST URL-PATH HEADERS CONTENT))

;;; (DEFUN (POST-DATA STRING) ...)

(CL:DECLAIM
 (CL:FTYPE
  (CL:FUNCTION
   (CL:SIMPLE-STRING CL:FIXNUM CL:SIMPLE-STRING CL:T CL:SIMPLE-STRING)
   CL:SIMPLE-STRING)
  POST-DATA))
(CL:DEFUN POST-DATA (HOST PORT URL-PATH HEADERS CONTENT)
  "Posts `content' as data to `url-path' on `host' and `port'.
The port value for standard http servers is 80.  Returns the body of the
reply message as a string, if successful.  Otherwise an HTTP-EXCEPTION is
signaled."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING HOST URL-PATH CONTENT)
   (CL:TYPE CL:FIXNUM PORT))
  #+MCL
  (CL:CHECK-TYPE HOST CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE PORT CL:FIXNUM)
  #+MCL
  (CL:CHECK-TYPE URL-PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE CONTENT CL:SIMPLE-STRING)
  (CL:LET* ((RETURN-HEADERS (NEW-KEY-VALUE-LIST)))
   (CL:LET* ((*PRINTREADABLY?* CL:NIL))
    (CL:DECLARE (CL:SPECIAL *PRINTREADABLY?*))
    (CL:LET* ((IN NULL) (OUT NULL))
     (CL:UNWIND-PROTECT
      (CL:PROGN
       (CL:MULTIPLE-VALUE-SETQ (IN OUT)
        (OPEN-NETWORK-STREAM HOST PORT))
       (WRITE-POST-REQUEST OUT HOST URL-PATH HEADERS CONTENT)
       (CL:LET*
        ((RETURN-CODE NULL-INTEGER)
         (RETURN-MESSAGE STELLA::NULL-STRING)
         (VERSION STELLA::NULL-STRING))
        (CL:DECLARE (CL:TYPE CL:FIXNUM RETURN-CODE)
         (CL:TYPE CL:SIMPLE-STRING RETURN-MESSAGE VERSION))
        (CL:MULTIPLE-VALUE-SETQ (RETURN-CODE RETURN-MESSAGE VERSION)
         (READ-HTTP-HEADER IN RETURN-HEADERS))
        (CL:SETQ VERSION VERSION)
        (CL:IF (CL:= RETURN-CODE 200)
         (CL:RETURN-FROM POST-DATA (STREAM-TO-STRING IN))
         (CL:LET* ((SELF-001 (NEW-HTTP-EXCEPTION RETURN-MESSAGE)))
          (CL:SETF (%ERROR-CODE SELF-001) RETURN-CODE)
          (CL:LET* ((EX SELF-001))
           (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "code = "
            RETURN-CODE "    message = " RETURN-MESSAGE
            "    version = " VERSION)
           (CL:ERROR EX))))))
      (CL:WHEN (CL:NOT (CL:EQ IN NULL)) (FREE IN))
      (CL:WHEN (CL:NOT (CL:EQ OUT NULL)) (FREE OUT)))))))

;;; (DEFUN (GET-WEB-PAGE STRING) ...)

(CL:DECLAIM
 (CL:FTYPE
  (CL:FUNCTION (CL:SIMPLE-STRING CL:FIXNUM CL:SIMPLE-STRING CL:T)
   CL:SIMPLE-STRING)
  GET-WEB-PAGE))
(CL:DEFUN GET-WEB-PAGE (HOST PORT URL-PATH RETURN-HEADERS)
  "Gets the webpage describe by path `url-path' on `host' and `port'.
The port value for standard http servers is 80.  If successful, 
returns the body of the web message as a string.  The headers
from the reply message will be set in `return-headers' if not
`null'.  If an error occurs an HTTP-EXCEPTION is signaled."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING HOST URL-PATH)
   (CL:TYPE CL:FIXNUM PORT))
  #+MCL
  (CL:CHECK-TYPE HOST CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE PORT CL:FIXNUM)
  #+MCL
  (CL:CHECK-TYPE URL-PATH CL:SIMPLE-STRING)
  (CL:WHEN (CL:EQ RETURN-HEADERS NULL)
   (CL:SETQ RETURN-HEADERS (NEW-KEY-VALUE-LIST)))
  (CL:LET* ((*PRINTREADABLY?* CL:NIL))
   (CL:DECLARE (CL:SPECIAL *PRINTREADABLY?*))
   (CL:LET* ((IN NULL) (OUT NULL))
    (CL:UNWIND-PROTECT
     (CL:PROGN
      (CL:MULTIPLE-VALUE-SETQ (IN OUT) (OPEN-NETWORK-STREAM HOST PORT))
      (WRITE-HTTP-REQUEST OUT "GET" HOST URL-PATH NULL
       STELLA::NULL-STRING)
      (CL:LET*
       ((RETURN-CODE NULL-INTEGER) (RETURN-MESSAGE STELLA::NULL-STRING)
        (VERSION STELLA::NULL-STRING))
       (CL:DECLARE (CL:TYPE CL:FIXNUM RETURN-CODE)
        (CL:TYPE CL:SIMPLE-STRING RETURN-MESSAGE VERSION))
       (CL:MULTIPLE-VALUE-SETQ (RETURN-CODE RETURN-MESSAGE VERSION)
        (READ-HTTP-HEADER IN RETURN-HEADERS))
       (CL:SETQ VERSION VERSION)
       (CL:IF (CL:= RETURN-CODE 200)
        (CL:RETURN-FROM GET-WEB-PAGE (STREAM-TO-STRING IN))
        (CL:LET* ((SELF-001 (NEW-HTTP-EXCEPTION RETURN-MESSAGE)))
         (CL:SETF (%ERROR-CODE SELF-001) RETURN-CODE)
         (CL:LET* ((EX SELF-001))
          (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "code = "
           RETURN-CODE "    message = " RETURN-MESSAGE "    version = "
           VERSION)
          (CL:ERROR EX))))))
     (CL:WHEN (CL:NOT (CL:EQ IN NULL)) (FREE IN))
     (CL:WHEN (CL:NOT (CL:EQ OUT NULL)) (FREE OUT))))))

;;; (DEFUN (BUILD-FULL-URL-HIERARCHICAL-PART STRING) ...)

(CL:DECLAIM
 (CL:FTYPE
  (CL:FUNCTION (CL:SIMPLE-STRING CL:SIMPLE-STRING CL:SIMPLE-STRING)
   CL:SIMPLE-STRING)
  BUILD-FULL-URL-HIERARCHICAL-PART))
(CL:DEFUN BUILD-FULL-URL-HIERARCHICAL-PART (PATH QUERY FRAGMENT)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH QUERY FRAGMENT))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE QUERY CL:SIMPLE-STRING)
  #+MCL
  (CL:CHECK-TYPE FRAGMENT CL:SIMPLE-STRING)
  (CL:IF (STRING-EQL? QUERY "")
   (CL:IF (STRING-EQL? FRAGMENT "") PATH
    (CONCATENATE PATH "#" FRAGMENT))
   (CL:IF (STRING-EQL? FRAGMENT "") (CONCATENATE PATH "?" QUERY)
    (CONCATENATE PATH "?" QUERY "#" FRAGMENT))))

;;; (DEFUN (URL-PATH-TO-FILENAME STRING) ...)

(CL:DECLAIM
 (CL:FTYPE (CL:FUNCTION (CL:SIMPLE-STRING) CL:SIMPLE-STRING)
  URL-PATH-TO-FILENAME))
(CL:DEFUN URL-PATH-TO-FILENAME (PATH)
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING PATH))
  #+MCL
  (CL:CHECK-TYPE PATH CL:SIMPLE-STRING)
  (CL:LET* ((SEPARATOR (DIRECTORY-SEPARATOR)))
   (CL:IF (CL:EQL SEPARATOR #\/) (UNESCAPE-URL-STRING PATH)
    (CL:PROGN
     (CL:SETQ PATH
      (UNESCAPE-URL-STRING (SUBSTITUTE PATH SEPARATOR #\/)))
     (CL:WHEN
      (CL:AND (CL:EQ (OPERATING-SYSTEM) KWD-HTTP-MAC)
       (CL:EQL
        (CL:LET ((SELF PATH) (POSITION 0))
         (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING SELF)
          (CL:TYPE CL:FIXNUM POSITION))
         (CL:SCHAR (CL:THE CL:SIMPLE-STRING SELF)
          (CL:THE CL:FIXNUM POSITION)))
        SEPARATOR))
      (CL:SETQ PATH (SUBSEQUENCE PATH 1 NULL-INTEGER)))
     PATH))))

;;; (DEFUN (OPEN-URL-STREAM INPUT-STREAM) ...)

(CL:DEFUN OPEN-URL-STREAM (URL)
  "Opens an input stream to `url'.
Currently only http: with no user name or password and file: urls on the local
host with absolute pathnames are supported."
  (CL:DECLARE (CL:TYPE CL:SIMPLE-STRING URL))
  #+MCL
  (CL:CHECK-TYPE URL CL:SIMPLE-STRING)
  (CL:LET*
   ((PROTOCOL STELLA::NULL-STRING) (USER-INFO STELLA::NULL-STRING)
    (HOST STELLA::NULL-STRING) (PORT STELLA::NULL-STRING)
    (PATH STELLA::NULL-STRING) (QUERY STELLA::NULL-STRING)
    (FRAGMENT STELLA::NULL-STRING))
   (CL:DECLARE
    (CL:TYPE CL:SIMPLE-STRING PROTOCOL USER-INFO HOST PORT PATH QUERY
     FRAGMENT))
   (CL:MULTIPLE-VALUE-SETQ
    (PROTOCOL USER-INFO HOST PORT PATH QUERY FRAGMENT)
    (DECOMPOSE-INTERNET-URL URL))
   (CL:COND
    ((STRING-EQL? PROTOCOL "http")
     (CL:COND
      ((CL:NOT (STRING-EQL? USER-INFO ""))
       (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
        (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
         "Only URL without user information are supported: `" URL "'")
        (CL:ERROR
         (NEW-BAD-ARGUMENT-EXCEPTION (THE-STRING-READER STREAM-000)))))
      (CL:T
       (CL:LET*
        ((IN NULL) (OUT NULL) (RETURN-HEADERS (NEW-KEY-VALUE-LIST)))
        (CL:MULTIPLE-VALUE-SETQ (IN OUT)
         (OPEN-NETWORK-STREAM HOST
          (CL:IF (CL:NOT (STRING-EQL? PORT ""))
           (STRING-TO-INTEGER PORT) 80)))
        (WRITE-HTTP-REQUEST OUT "GET" HOST
         (BUILD-FULL-URL-HIERARCHICAL-PART PATH QUERY FRAGMENT) NULL
         STELLA::NULL-STRING)
        (CL:LET*
         ((RETURN-CODE NULL-INTEGER)
          (RETURN-MESSAGE STELLA::NULL-STRING)
          (VERSION STELLA::NULL-STRING))
         (CL:DECLARE (CL:TYPE CL:FIXNUM RETURN-CODE)
          (CL:TYPE CL:SIMPLE-STRING RETURN-MESSAGE VERSION))
         (CL:MULTIPLE-VALUE-SETQ (RETURN-CODE RETURN-MESSAGE VERSION)
          (READ-HTTP-HEADER IN RETURN-HEADERS))
         (CL:SETQ VERSION VERSION)
         (CL:IF (CL:= RETURN-CODE 200) IN
          (CL:LET* ((SELF-003 (NEW-HTTP-EXCEPTION RETURN-MESSAGE)))
           (CL:SETF (%ERROR-CODE SELF-003) RETURN-CODE)
           (CL:LET* ((EX SELF-003))
            (%%PRINT-STREAM (%NATIVE-STREAM STANDARD-OUTPUT) "code = "
             RETURN-CODE "    message = " RETURN-MESSAGE
             "    version = " VERSION)
            (CL:WHEN (CL:NOT (CL:EQ IN NULL)) (FREE IN))
            (CL:WHEN (CL:NOT (CL:EQ OUT NULL)) (FREE OUT))
            (CL:ERROR EX)))))))))
    ((STRING-EQL? PROTOCOL "file")
     (CL:COND
      ((CL:NOT (STRING-EQL? USER-INFO ""))
       (CL:LET* ((STREAM-001 (NEW-OUTPUT-STRING-STREAM)))
        (%%PRINT-STREAM (%NATIVE-STREAM STREAM-001)
         "Only URL without user information are supported: `" URL "'")
        (CL:ERROR
         (NEW-BAD-ARGUMENT-EXCEPTION (THE-STRING-READER STREAM-001)))))
      ((CL:OR (STRING-EQL? HOST "") (STRING-EQL? HOST "localhost"))
       (NEW-INPUT-FILE-STREAM (URL-PATH-TO-FILENAME PATH)))
      (CL:T
       (CL:LET* ((STREAM-002 (NEW-OUTPUT-STRING-STREAM)))
        (%%PRINT-STREAM (%NATIVE-STREAM STREAM-002)
         "Only file URLs on the local host are supported: `" URL "'")
        (CL:ERROR
         (NEW-BAD-ARGUMENT-EXCEPTION
          (THE-STRING-READER STREAM-002)))))))
    (CL:T
     (CL:LET* ((STREAM-003 (NEW-OUTPUT-STRING-STREAM)))
      (%%PRINT-STREAM (%NATIVE-STREAM STREAM-003)
       "Only http and file URLs are supported: `" URL "'")
      (CL:ERROR
       (NEW-BAD-ARGUMENT-EXCEPTION (THE-STRING-READER STREAM-003))))))))

;;; (DEFMACRO WITH-INPUT-URL ...)

(CL:DEFUN WITH-INPUT-URL (BINDING BODY)
  "Sets up an unwind-protected form which opens a URL for
input and closes it afterwards.  The stream for reading is bound to the
variable provided in the macro form.
Syntax is `(WITH-INPUT-URL (var url) body+)'."
  (CL:LET* ((VAR (%%VALUE BINDING)))
   (LIST* SYM-HTTP-STELLA-LET
    (CONS
     (CONS VAR
      (LIST* SYM-HTTP-STELLA-INPUT-STREAM SYM-HTTP-STELLA-NULL NIL))
     NIL)
    (LIST* SYM-HTTP-STELLA-UNWIND-PROTECT
     (LIST* SYM-HTTP-STELLA-PROGN
      (LIST* SYM-HTTP-STELLA-SETQ VAR
       (CONS
        (LIST* SYM-HTTP-UTILITIES-OPEN-URL-STREAM
         (%%VALUE (%%REST BINDING)) NIL)
        NIL))
      (CONCATENATE BODY NIL))
     (LIST* SYM-HTTP-STELLA-WHEN
      (LIST* SYM-HTTP-STELLA-DEFINED? VAR NIL)
      (LIST* SYM-HTTP-STELLA-FREE VAR NIL) NIL)
     NIL)
    NIL)))

(CL:DEFUN STARTUP-HTTP ()
  (CL:LET*
   ((*MODULE*
     (GET-STELLA-MODULE "/UTILITIES" (> *STARTUP-TIME-PHASE* 1)))
    (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2)
    (CL:SETQ KWD-HTTP-MAC
     (INTERN-RIGID-SYMBOL-WRT-MODULE "MAC" NULL 2))
    (CL:SETQ SYM-HTTP-STELLA-LET
     (INTERN-RIGID-SYMBOL-WRT-MODULE "LET"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-STELLA-INPUT-STREAM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "INPUT-STREAM"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-STELLA-NULL
     (INTERN-RIGID-SYMBOL-WRT-MODULE "NULL"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-STELLA-UNWIND-PROTECT
     (INTERN-RIGID-SYMBOL-WRT-MODULE "UNWIND-PROTECT"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-STELLA-PROGN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "PROGN"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-STELLA-SETQ
     (INTERN-RIGID-SYMBOL-WRT-MODULE "SETQ"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-UTILITIES-OPEN-URL-STREAM
     (INTERN-RIGID-SYMBOL-WRT-MODULE "OPEN-URL-STREAM" NULL 0))
    (CL:SETQ SYM-HTTP-STELLA-WHEN
     (INTERN-RIGID-SYMBOL-WRT-MODULE "WHEN"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-STELLA-DEFINED?
     (INTERN-RIGID-SYMBOL-WRT-MODULE "DEFINED?"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-STELLA-FREE
     (INTERN-RIGID-SYMBOL-WRT-MODULE "FREE"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0))
    (CL:SETQ SYM-HTTP-UTILITIES-STARTUP-HTTP
     (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-HTTP" NULL 0))
    (CL:SETQ SYM-HTTP-STELLA-METHOD-STARTUP-CLASSNAME
     (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME"
      (GET-STELLA-MODULE "/STELLA" CL:T) 0)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 5)
    (CL:LET*
     ((CLASS
       (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE "HTTP-EXCEPTION"
        "(DEFCLASS HTTP-EXCEPTION (READ-EXCEPTION) :PUBLIC-SLOTS ((ERROR-CODE :TYPE INTEGER)))")))
     (CL:SETF (%CLASS-CONSTRUCTOR-CODE CLASS)
      (CL:FUNCTION NEW-HTTP-EXCEPTION))))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7)
    (DEFINE-FUNCTION-OBJECT "HANDLE-HTTP-HEADER-FIRST-LINE"
     "(DEFUN (HANDLE-HTTP-HEADER-FIRST-LINE STRING INTEGER STRING) ((LINE STRING) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Handles the first line of an http header.  
Returns version, response code, response message.  The first
line is inserted into `fields' fields with the empty string key \\\"\\\"
This is a low-level utility routine that can be used to build custom
message parsing code.\")" (CL:FUNCTION HANDLE-HTTP-HEADER-FIRST-LINE)
     NULL)
    (DEFINE-FUNCTION-OBJECT "HANDLE-HTTP-HEADER-OTHER-LINE"
     "(DEFUN HANDLE-HTTP-HEADER-OTHER-LINE ((LINE STRING) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Handles header lines other than the first one.
Each such line is inserted into `fields' as keyword value pairs.
This is a low-level utility routine that can be used to build custom
message parsing code.\")" (CL:FUNCTION HANDLE-HTTP-HEADER-OTHER-LINE)
     NULL)
    (DEFINE-FUNCTION-OBJECT "DECOMPOSE-INTERNET-URL"
     "(DEFUN (DECOMPOSE-INTERNET-URL STRING STRING STRING STRING STRING STRING STRING) ((URL STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Takes an internet style URL and returns the components of
that URL as specified below.  Missing elements return the empty string \\\"\\\".
  PROTOCOL USERNAME:PASSWORD DOMAIN PORT PATH QUERY FRAGMENT

  o Protocol.  The access protocol.

       Those schemes which refer to internet protocols mostly have a
       common syntax for the rest of the object name. This starts with a
       double slash '//' to indicate its presence, and continues until
       the following slash '/':

  o An optional user name, if required (as it is with a few FTP servers).
    The password, if present, follows the user name, separated from it by a colon;
    the user name and optional password are followed by a commercial at sign '@'. 
  o The internet domain name of the host
  o The port number, if it is not the default number for the protocol,
    is given in decimal notation after a colon.
  o Path The path is a hierarchical representation of a particular path. It may 
    define details of how the client should communicate with the server, including
    information to be passed transparently to the server without any processing by
    the client.
    The path is interpreted in a manner dependent on the scheme being used.
    Generally, the reserved slash '/' character (ASCII 2F hex) denotes a level in a
    hierarchical structure, the higher level part to the left of the slash.
  o Query is the part of the hierarchical information following a '?' character.
  o Fragment is the part of the hierarchical information following a '#' character.

References:  http://www.gbiv.com/protocols/uri/rfc/rfc3986.html
\")" (CL:FUNCTION DECOMPOSE-INTERNET-URL) NULL)
    (DEFINE-FUNCTION-OBJECT "READ-HTTP-HEADER"
     "(DEFUN (READ-HTTP-HEADER INTEGER STRING STRING) ((STREAM INPUT-STREAM) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Reads the HTTP header from `stream', parses the header fields
and stores the results in `fields'.  The first line of the response will be
stored in `fields' with the empty string \\\"\\\" as the key.  Other values will
have the header name as the key.  The first return value is the response code
of the HTTP request.  A response of 200 indicates success.  Other common
responses are 404 (page not found).  The second return value is the message
associated with the code.  The third return value is the version information.
If the stream ends before a valid header is read, then `null' is returned for
all values.\")" (CL:FUNCTION READ-HTTP-HEADER) NULL)
    (DEFINE-FUNCTION-OBJECT "WRITE-HTTP-REQUEST"
     "(DEFUN WRITE-HTTP-REQUEST ((STREAM OUTPUT-STREAM) (METHOD STRING) (HOST STRING) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Send `content' as an HTTP 1.0 request on `stream' using `method'.
The request is sent to `url-path' at `host'.  The `stream' must be a TCP-stream
that is connected to `host' at the appropriate port.\")"
     (CL:FUNCTION WRITE-HTTP-REQUEST) NULL)
    (DEFINE-FUNCTION-OBJECT "WRITE-POST-REQUEST"
     "(DEFUN WRITE-POST-REQUEST ((STREAM OUTPUT-STREAM) (HOST STRING) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)))"
     (CL:FUNCTION WRITE-POST-REQUEST) NULL)
    (DEFINE-FUNCTION-OBJECT "POST-DATA"
     "(DEFUN (POST-DATA STRING) ((HOST STRING) (PORT INTEGER) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Posts `content' as data to `url-path' on `host' and `port'.
The port value for standard http servers is 80.  Returns the body of the
reply message as a string, if successful.  Otherwise an HTTP-EXCEPTION is
signaled.\")" (CL:FUNCTION POST-DATA) NULL)
    (DEFINE-FUNCTION-OBJECT "GET-WEB-PAGE"
     "(DEFUN (GET-WEB-PAGE STRING) ((HOST STRING) (PORT INTEGER) (URL-PATH STRING) (RETURN-HEADERS DICTIONARY)) :PUBLIC? TRUE :DOCUMENTATION \"Gets the webpage describe by path `url-path' on `host' and `port'.
The port value for standard http servers is 80.  If successful, 
returns the body of the web message as a string.  The headers
from the reply message will be set in `return-headers' if not
`null'.  If an error occurs an HTTP-EXCEPTION is signaled.\")"
     (CL:FUNCTION GET-WEB-PAGE) NULL)
    (DEFINE-FUNCTION-OBJECT "BUILD-FULL-URL-HIERARCHICAL-PART"
     "(DEFUN (BUILD-FULL-URL-HIERARCHICAL-PART STRING) ((PATH STRING) (QUERY STRING) (FRAGMENT STRING)))"
     (CL:FUNCTION BUILD-FULL-URL-HIERARCHICAL-PART) NULL)
    (DEFINE-FUNCTION-OBJECT "URL-PATH-TO-FILENAME"
     "(DEFUN (URL-PATH-TO-FILENAME STRING) ((PATH STRING)))"
     (CL:FUNCTION URL-PATH-TO-FILENAME) NULL)
    (DEFINE-FUNCTION-OBJECT "OPEN-URL-STREAM"
     "(DEFUN (OPEN-URL-STREAM INPUT-STREAM) ((URL STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Opens an input stream to `url'.
Currently only http: with no user name or password and file: urls on the local
host with absolute pathnames are supported.\")"
     (CL:FUNCTION OPEN-URL-STREAM) NULL)
    (DEFINE-FUNCTION-OBJECT "WITH-INPUT-URL"
     "(DEFUN WITH-INPUT-URL ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a URL for
input and closes it afterwards.  The stream for reading is bound to the
variable provided in the macro form.
Syntax is `(WITH-INPUT-URL (var url) body+)'.\")"
     (CL:FUNCTION WITH-INPUT-URL) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-HTTP"
     "(DEFUN STARTUP-HTTP () :PUBLIC? TRUE)" (CL:FUNCTION STARTUP-HTTP)
     NULL)
    (CL:LET*
     ((FUNCTION (LOOKUP-FUNCTION SYM-HTTP-UTILITIES-STARTUP-HTTP)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-HTTP-STELLA-METHOD-STARTUP-CLASSNAME
      (WRAP-STRING "_StartupHttp") NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))))
