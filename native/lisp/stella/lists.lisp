;;; -*- Mode: Lisp; Package: STELLA; Syntax: COMMON-LISP; Base: 10 -*-

;;; lists.lisp

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
| Portions created by the Initial Developer are Copyright (C) 1996-2006      |
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

(CL:DEFVAR SGT-LISTS-STELLA-LIST NULL)
(CL:DEFVAR SGT-LISTS-STELLA-SET NULL)
(CL:DEFVAR SGT-LISTS-STELLA-PROPERTY-LIST NULL)
(CL:DEFVAR SGT-LISTS-STELLA-KEY-VALUE-LIST NULL)
(CL:DEFVAR SGT-LISTS-STELLA-HASH-TABLE NULL)
(CL:DEFVAR SGT-LISTS-STELLA-STELLA-HASH-TABLE NULL)
(CL:DEFVAR SGT-LISTS-STELLA-KEY-VALUE-MAP NULL)
(CL:DEFVAR SYM-LISTS-STELLA-STARTUP-LISTS NULL)
(CL:DEFVAR SYM-LISTS-STELLA-METHOD-STARTUP-CLASSNAME NULL)

;;; Forward declarations:

(CL:DECLAIM (CL:SPECIAL *STELLA-MODULE* *MODULE* *PRINTLENGTH* NIL))

;;; (DEFGLOBAL NIL-LIST ...)

(CL:DEFVAR NIL-LIST NULL)

;;; (DEFUN (DEFINED-LIST? BOOLEAN) ...)

(CL:DEFUN DEFINED-LIST? (SELF)
  "Return TRUE unless `self' is NULL or the `NIL-LIST'."
  (CL:RETURN-FROM DEFINED-LIST?
   (CL:AND (CL:NOT (CL:EQ SELF NIL-LIST)) (CL:NOT (CL:EQ SELF NULL)))))

;;; (DEFUN (NULL-LIST? BOOLEAN) ...)

(CL:DEFUN NULL-LIST? (SELF)
  "Return TRUE iff `self' is NULL or the `NIL-LIST'."
  (CL:RETURN-FROM NULL-LIST? (CL:OR (CL:EQ SELF NIL-LIST) (CL:EQ SELF NULL))))

;;; (DEFMETHOD (EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD EMPTY? ((SELF LIST))
  "Return TRUE if the list `self' has no members."
  (CL:RETURN-FROM EMPTY? (CL:EQ (%THE-CONS-LIST SELF) NIL)))

;;; (DEFMETHOD (NON-EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD NON-EMPTY? ((SELF LIST))
  "Return TRUE if the list `self' has at least one member."
  (CL:RETURN-FROM NON-EMPTY? (CL:NOT (CL:EQ (%THE-CONS-LIST SELF) NIL))))

;;; (DEFUN (TERMINATE-LIST? BOOLEAN) ...)

(CL:DEFUN TERMINATE-LIST? (SELF)
  (CL:WHEN (CL:EQ SELF NIL-LIST)
   (CL:WHEN (CL:EQ SELF NIL-LIST)
    (CL:ERROR "Safety violation: Attempt to free NIL-LIST."))
   (CL:RETURN-FROM TERMINATE-LIST? CL:NIL))
  (CL:LET* ((CONS (%THE-CONS-LIST SELF)) (REST NULL))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CONS NIL)) DO (CL:SETQ REST (%%REST CONS))
    (FREE CONS) (CL:SETQ CONS REST))
   (CL:SETF (%THE-CONS-LIST SELF) NIL) (CL:RETURN-FROM TERMINATE-LIST? CL:T)))

;;; (DEFMETHOD (MEMBER? BOOLEAN) ...)

(CL:DEFMETHOD MEMBER? ((SELF LIST) OBJECT)
  "Return TRUE iff `object' is a member of the list
`self' (uses an `eql?' test)."
  (CL:LET* ((I NULL) (ITER-000 (%THE-CONS-LIST SELF)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ I (%%VALUE ITER-000))
    (CL:WHEN (EQL? I OBJECT) (CL:RETURN-FROM MEMBER? CL:T))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (CL:RETURN-FROM MEMBER? CL:NIL))

;;; (DEFMETHOD (MEMB? BOOLEAN) ...)

(CL:DEFMETHOD MEMB? ((SELF LIST) OBJECT)
  "Return TRUE iff `object' is a member of the cons list
`self' (uses an 'eq?' test)."
  (CL:LET* ((I NULL) (ITER-000 (%THE-CONS-LIST SELF)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
    (CL:SETQ I (%%VALUE ITER-000))
    (CL:WHEN (CL:EQ I OBJECT) (CL:RETURN-FROM MEMB? CL:T))
    (CL:SETQ ITER-000 (%%REST ITER-000))))
  (CL:RETURN-FROM MEMB? CL:NIL))

;;; (DEFMETHOD (FIRST (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD FIRST ((SELF LIST))
  "Return the first item in the list `self', or NULL if empty."
  (CL:LET* ((CONS (%THE-CONS-LIST SELF)))
   (CL:RETURN-FROM FIRST
    (CL:IF (CL:NOT (CL:EQ CONS NIL)) (%%VALUE CONS) NULL))))

;;; (DEFMETHOD (SECOND (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD SECOND ((SELF LIST))
  "Return the second item in the list `self', or NULL if empty."
  (CL:RETURN-FROM SECOND (%%VALUE (%%REST (%THE-CONS-LIST SELF)))))

;;; (DEFMETHOD (THIRD (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD THIRD ((SELF LIST))
  "Return the third item in the list `self', or NULL if empty."
  (CL:RETURN-FROM THIRD (%%VALUE (%%REST (%%REST (%THE-CONS-LIST SELF))))))

;;; (DEFMETHOD (FOURTH (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD FOURTH ((SELF LIST))
  "Return the fourth item in the list `self', or NULL if empty."
  (CL:RETURN-FROM FOURTH (FOURTH (%THE-CONS-LIST SELF))))

;;; (DEFMETHOD (FIFTH (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD FIFTH ((SELF LIST))
  "Return the fifth item in the list `self', or NULL if empty."
  (CL:RETURN-FROM FIFTH (FIFTH (%THE-CONS-LIST SELF))))

;;; (DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD NTH ((SELF LIST) POSITION)
  "Return the nth item in the list `self', or NULL if empty."
  (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION))
  #+MCL
  (CL:CHECK-TYPE POSITION CL:FIXNUM)
  (CL:RETURN-FROM NTH (NTH (%THE-CONS-LIST SELF) POSITION)))

;;; (DEFMETHOD (LAST (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD LAST ((SELF LIST))
  "Return the last element of `self'."
  (CL:RETURN-FROM LAST (LAST (%THE-CONS-LIST SELF))))

;;; (DEFMETHOD (REST (CONS OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD REST ((SELF LIST))
  "Return a cons list of all but the first item in the list `self'."
  (CL:RETURN-FROM REST (%%REST (%THE-CONS-LIST SELF))))

;;; (DEFMETHOD (FIRST-SETTER (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD FIRST-SETTER ((SELF LIST) VALUE)
  (CL:RETURN-FROM FIRST-SETTER (FIRST-SETTER (%THE-CONS-LIST SELF) VALUE)))

;;; (DEFMETHOD (SECOND-SETTER (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD SECOND-SETTER ((SELF LIST) VALUE)
  (CL:RETURN-FROM SECOND-SETTER (SECOND-SETTER (%THE-CONS-LIST SELF) VALUE)))

;;; (DEFMETHOD (THIRD-SETTER (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD THIRD-SETTER ((SELF LIST) VALUE)
  (CL:RETURN-FROM THIRD-SETTER (THIRD-SETTER (%THE-CONS-LIST SELF) VALUE)))

;;; (DEFMETHOD (FOURTH-SETTER (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD FOURTH-SETTER ((SELF LIST) VALUE)
  (CL:RETURN-FROM FOURTH-SETTER (FOURTH-SETTER (%THE-CONS-LIST SELF) VALUE)))

;;; (DEFMETHOD (FIFTH-SETTER (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD FIFTH-SETTER ((SELF LIST) VALUE)
  (CL:RETURN-FROM FIFTH-SETTER (FIFTH-SETTER (%THE-CONS-LIST SELF) VALUE)))

;;; (DEFMETHOD (NTH-SETTER (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD NTH-SETTER ((SELF LIST) VALUE POSITION)
  (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION))
  #+MCL
  (CL:CHECK-TYPE POSITION CL:FIXNUM)
  (CL:RETURN-FROM NTH-SETTER (NTH-SETTER (%THE-CONS-LIST SELF) VALUE POSITION)))

;;; (DEFMETHOD (LENGTH INTEGER) ...)

(CL:DEFMETHOD LENGTH ((SELF LIST))
  (CL:DECLARE (CL:INLINE LENGTH))
  (CL:RETURN-FROM LENGTH (LENGTH (%THE-CONS-LIST SELF))))

;;; (DEFMETHOD (POSITION INTEGER) ...)

(CL:DEFMETHOD POSITION ((SELF LIST) OBJECT START)
  "Return the position of `object' within the list
`self' (counting from zero); or return NULL if `object' does not occur within 
`self' (uses an `eql?' test).  If `start' was supplied as non-NULL, only 
consider the sublist starting at `start', however, the returned position 
will always be relative to the entire list."
  (CL:DECLARE (CL:TYPE CL:FIXNUM START))
  #+MCL
  (CL:CHECK-TYPE START CL:FIXNUM)
  (CL:RETURN-FROM POSITION (POSITION (%THE-CONS-LIST SELF) OBJECT START)))

;;; (DEFMETHOD (LAST-POSITION INTEGER) ...)

(CL:DEFMETHOD LAST-POSITION ((SELF LIST) OBJECT END)
  "Return the position of `object' within the list
`self' (counting from zero); or return NULL if `object' does not occur within 
`self' (uses an `eql?' test).  If `end' was supplied as non-NULL, only 
consider the sublist ending at `end', however, the returned position 
will always be relative to the entire list."
  (CL:DECLARE (CL:TYPE CL:FIXNUM END))
  #+MCL
  (CL:CHECK-TYPE END CL:FIXNUM)
  (CL:RETURN-FROM LAST-POSITION
   (LAST-POSITION (%THE-CONS-LIST SELF) OBJECT END)))

;;; (DEFMETHOD INSERT ...)

(CL:DEFMETHOD INSERT ((SELF LIST) VALUE)
  "Add `value' to the front of the list `self'."
  (CL:WHEN (CL:EQ SELF NIL-LIST)
   (CL:ERROR "Safety violation: Attempt to insert into NIL-LIST."))
  (CL:SETF (%THE-CONS-LIST SELF) (CONS VALUE (%THE-CONS-LIST SELF)))
  :VOID)

;;; (DEFMETHOD PUSH ...)

(CL:DEFMETHOD PUSH ((SELF LIST) VALUE)
  "Add `value' to the front of the list `self'."
  (CL:WHEN (CL:EQ SELF NIL-LIST)
   (CL:ERROR "Safety violation: Attempt to insert into NIL-LIST."))
  (CL:SETF (%THE-CONS-LIST SELF) (CONS VALUE (%THE-CONS-LIST SELF)))
  :VOID)

;;; (DEFMETHOD INSERT-NEW ...)

(CL:DEFMETHOD INSERT-NEW ((SELF LIST) VALUE)
  "Add `value' to the front of the list `self' unless its 
already a member."
  (CL:WHEN (CL:EQ SELF NIL-LIST)
   (CL:ERROR "Safety violation: Attempt to insert into NIL-LIST."))
  (CL:WHEN (CL:NOT (MEMBER? (%THE-CONS-LIST SELF) VALUE))
   (CL:SETF (%THE-CONS-LIST SELF) (CONS VALUE (%THE-CONS-LIST SELF))))
  :VOID)

;;; (DEFMETHOD INSERT-LAST ...)

(CL:DEFMETHOD INSERT-LAST ((SELF LIST) VALUE)
  "Insert `value' as the last entry in the list `self'."
  (CL:WHEN (CL:EQ SELF NIL-LIST)
   (CL:ERROR "Safety violation: Attempt to insert into NIL-LIST."))
  (CL:LET* ((CURSOR (%THE-CONS-LIST SELF)) (LASTCONS (CONS VALUE NIL)))
   (CL:IF (CL:EQ CURSOR NIL) (CL:SETF (%THE-CONS-LIST SELF) LASTCONS)
    (ADD-CONS-TO-END-OF-CONS-LIST CURSOR LASTCONS)))
  :VOID)

;;; (DEFMETHOD (REMOVE (LIKE SELF)) ...)

(CL:DEFMETHOD REMOVE ((SELF LIST) VALUE)
  "Destructively remove all entries in `self' that match `value'."
  (CL:SETF (%THE-CONS-LIST SELF) (REMOVE (%THE-CONS-LIST SELF) VALUE))
  (CL:RETURN-FROM REMOVE SELF))

;;; (DEFMETHOD (REMOVE-IF (LIKE SELF)) ...)

(CL:DEFMETHOD REMOVE-IF ((SELF LIST) TEST?)
  "Destructively remove all members of the list `self' for which
'test?' evaluates to TRUE.  `test' takes a single argument of type OBJECT and
returns TRUE or FALSE.  Returns `self'."
  (CL:SETF (%THE-CONS-LIST SELF) (REMOVE-IF (%THE-CONS-LIST SELF) TEST?))
  (CL:RETURN-FROM REMOVE-IF SELF))

;;; (DEFMETHOD (REMOVE-DUPLICATES (LIKE SELF)) ...)

(CL:DEFMETHOD REMOVE-DUPLICATES ((SELF LIST))
  "Destructively remove duplicates from `self' and return the result.
Preserves the original order of the remaining members."
  (CL:WHEN (CL:NOT (CL:EQ (%THE-CONS-LIST SELF) NIL))
   (CL:SETF (%THE-CONS-LIST SELF) (REMOVE-DUPLICATES (%THE-CONS-LIST SELF))))
  (CL:RETURN-FROM REMOVE-DUPLICATES SELF))

;;; (DEFMETHOD (POP (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD POP ((SELF LIST))
  "Remove and return the first element in the list `self'.
Return NULL if the list is empty."
  (CL:LET* ((CONS (%THE-CONS-LIST SELF)) (VALUE NULL))
   (CL:WHEN (CL:EQ CONS NIL) (CL:RETURN-FROM POP NULL))
   (CL:SETQ VALUE (%%VALUE CONS))
   (CL:SETF (%THE-CONS-LIST SELF) (%%REST CONS)) (CL:RETURN-FROM POP VALUE)))

;;; (DEFMETHOD (REVERSE (LIKE SELF)) ...)

(CL:DEFMETHOD REVERSE ((SELF LIST))
  "Reverse the members of `self' (in place)."
  (CL:SETF (%THE-CONS-LIST SELF) (REVERSE (%THE-CONS-LIST SELF)))
  (CL:RETURN-FROM REVERSE SELF))

;;; (DEFMETHOD (SUBSTITUTE (LIKE SELF)) ...)

(CL:DEFMETHOD SUBSTITUTE ((SELF LIST) INVALUE OUTVALUE)
  "Destructively replace each appearance of `outValue' by
`inValue' in the list `self'."
  (CL:SETF (%THE-CONS-LIST SELF)
   (SUBSTITUTE (%THE-CONS-LIST SELF) INVALUE OUTVALUE))
  (CL:RETURN-FROM SUBSTITUTE SELF))

;;; (DEFMETHOD (CONCATENATE LIST) ...)

(CL:DEFMETHOD CONCATENATE ((LIST1 LIST) LIST2 CL:&REST OTHERLISTS)
  "Copy `list2' and all `otherLists' onto the end of `list1'.
The operation is destructive wrt `list1', but leaves all other lists intact.
The two mandatory parameters allow us to optimize the common binary case by
not relying on the somewhat less efficient variable arguments mechanism."
  (CL:LET*
   ((FIRSTLIST (%THE-CONS-LIST LIST1)) (LASTLIST (%THE-CONS-LIST LIST2))
    (COPY NIL))
   (CL:COND
    ((CL:EQ FIRSTLIST NIL) (CL:SETQ FIRSTLIST (COPY-CONS-LIST LASTLIST))
     (CL:SETQ LASTLIST FIRSTLIST))
    ((CL:EQ LASTLIST NIL) (CL:SETQ LASTLIST FIRSTLIST))
    (CL:T (CL:SETQ LASTLIST (COPY-CONS-LIST LASTLIST))
     (CL:SETF (%%REST (LAST-CONS FIRSTLIST)) LASTLIST)))
   (CL:WHEN (CL:> (CL:LENGTH OTHERLISTS) 0)
    (CL:LET* ((LIST NULL) (ITER-000 OTHERLISTS))
     (CL:LOOP WHILE ITER-000 DO (CL:SETQ LIST (CL:POP ITER-000))
      (CL:WHEN (NON-EMPTY? LIST)
       (CL:SETQ COPY (COPY-CONS-LIST (%THE-CONS-LIST LIST)))
       (CL:IF (CL:NOT (CL:EQ LASTLIST NIL))
        (CL:SETF (%%REST (LAST-CONS LASTLIST)) COPY) (CL:SETQ FIRSTLIST COPY))
       (CL:SETQ LASTLIST COPY)))))
   (CL:SETF (%THE-CONS-LIST LIST1) FIRSTLIST)
   (CL:RETURN-FROM CONCATENATE LIST1)))

;;; (DEFMETHOD (PREPEND (LIKE SELF)) ...)

(CL:DEFMETHOD PREPEND ((SELF LIST) LIST2)
  "Copy `list2' onto the front of the list `self'.
The operation is destructive wrt `self', but leaves `list2' intact."
  (CL:WHEN (EMPTY? LIST2) (CL:RETURN-FROM PREPEND SELF))
  (CL:SETF (%THE-CONS-LIST SELF)
   (CONCATENATE (COPY-CONS-LIST (%THE-CONS-LIST LIST2)) (%THE-CONS-LIST SELF)))
  (CL:RETURN-FROM PREPEND SELF))

;;; (DEFUN (CREATE-DERIVED-LIST LIST) ...)

(CL:DEFUN CREATE-DERIVED-LIST (SELF)
  "Create a new list object with the same type as `self'."
  (CL:LET* ((LISTTYPE (PRIMARY-TYPE SELF)))
   (CL:COND
    ((CL:EQ LISTTYPE SGT-LISTS-STELLA-LIST)
     (CL:RETURN-FROM CREATE-DERIVED-LIST (NEW-LIST)))
    ((CL:EQ LISTTYPE SGT-LISTS-STELLA-SET)
     (CL:RETURN-FROM CREATE-DERIVED-LIST (NEW-SET)))
    (CL:T (CL:RETURN-FROM CREATE-DERIVED-LIST (CREATE-OBJECT LISTTYPE))))))

;;; (DEFMETHOD (COPY (LIST OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD COPY ((SELF LIST))
  "Return a copy of the list `self'.  The conses in the copy are
freshly allocated."
  (CL:LET* ((COPY (CREATE-DERIVED-LIST SELF)))
   (CL:SETF (%THE-CONS-LIST COPY) (COPY-CONS-LIST (%THE-CONS-LIST SELF)))
   (CL:RETURN-FROM COPY COPY)))

;;; (DEFMETHOD CLEAR ...)

(CL:DEFMETHOD CLEAR ((SELF LIST))
  "Make `self' an empty list."
  (CL:SETF (%THE-CONS-LIST SELF) NIL)
  :VOID)

;;; (DEFMETHOD (SORT (LIST OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD SORT ((SELF LIST) PREDICATE)
  "Perform a stable, destructive sort of `self' according to
`predicate', and return the result.  If `predicate' has a '<' semantics, the
result will be in ascending order.  If `predicate' is NULL, a suitable
'<' predicate is chosen depending on the first element of `self', and it 
is assumed that all elements of `self' have the same type (supported
element types are GENERALIZED-SYMBOL, STRING, INTEGER, and FLOAT)."
  (CL:SETF (%THE-CONS-LIST SELF) (SORT (%THE-CONS-LIST SELF) PREDICATE))
  (CL:RETURN-FROM SORT SELF))

;;; (DEFUN (MAP-NULL-TO-NIL-LIST LIST) ...)

(CL:DEFUN MAP-NULL-TO-NIL-LIST (SELF)
  "Return NIL-LIST iff `self' is NULL or `self' otherwise."
  (CL:RETURN-FROM MAP-NULL-TO-NIL-LIST (CL:IF (CL:EQ SELF NULL) NIL-LIST SELF)))

;;; (DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ...)

(CL:DEFMETHOD OBJECT-EQUAL? ((X LIST) Y)
  "Return TRUE iff the lists `x' and `y' are structurally
equivalent.  Uses `equal?' to test equality of elements."
  (CL:COND
   ((SUBTYPE-OF? (SAFE-PRIMARY-TYPE Y) SGT-LISTS-STELLA-LIST)
    (CL:PROGN
     (CL:RETURN-FROM OBJECT-EQUAL?
      (EQUAL? (%THE-CONS-LIST X) (%THE-CONS-LIST Y)))))
   (CL:T))
  (CL:RETURN-FROM OBJECT-EQUAL? CL:NIL))

;;; (DEFMETHOD (EQUAL-HASH-CODE INTEGER) ...)

(CL:DEFMETHOD EQUAL-HASH-CODE ((SELF LIST))
  "Return an `equal?' hash code for `self'.  Note that this
is O(N) in the number of elements of `self'."
  (CL:LET* ((CODE 5619580)) (CL:DECLARE (CL:TYPE CL:FIXNUM CODE))
   (CL:RETURN-FROM EQUAL-HASH-CODE
    (CL:THE CL:FIXNUM
     (CL:LOGXOR CODE
      (CL:THE CL:FIXNUM (EQUAL-HASH-CODE (%THE-CONS-LIST SELF))))))))

;;; (DEFMETHOD (ALLOCATE-ITERATOR (LIST-ITERATOR OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD ALLOCATE-ITERATOR ((SELF LIST))
  (CL:LET* ((ITERATOR (NEW-LIST-ITERATOR)))
   (CL:SETF (%LIST-ITERATOR-CURSOR ITERATOR) (%THE-CONS-LIST SELF))
   (CL:SETF (%LIST-ITERATOR-COLLECTION ITERATOR) SELF)
   (CL:SETF (%FIRST-ITERATION? ITERATOR) CL:T)
   (CL:RETURN-FROM ALLOCATE-ITERATOR ITERATOR)))

;;; (DEFUN (TERMINATE-LIST-ITERATOR? BOOLEAN) ...)

(CL:DEFUN TERMINATE-LIST-ITERATOR? (SELF)
  (CL:SETF (%LIST-ITERATOR-CURSOR SELF) NIL)
  (CL:SETF (%LIST-ITERATOR-COLLECTION SELF) NULL)
  (CL:RETURN-FROM TERMINATE-LIST-ITERATOR? CL:T))

;;; (DEFMETHOD (NEXT? BOOLEAN) ...)

(CL:DEFMETHOD NEXT? ((SELF LIST-ITERATOR))
  (CL:IF (%FIRST-ITERATION? SELF)
   (CL:PROGN (CL:SETF (%FIRST-ITERATION? SELF) CL:NIL)
    (CL:SETF (%LIST-ITERATOR-CURSOR SELF)
     (%THE-CONS-LIST (%LIST-ITERATOR-COLLECTION SELF))))
   (CL:SETF (%LIST-ITERATOR-CURSOR SELF)
    (%%REST (%LIST-ITERATOR-CURSOR SELF))))
  (CL:SETF (%VALUE SELF) (%%VALUE (%LIST-ITERATOR-CURSOR SELF)))
  (CL:RETURN-FROM NEXT? (CL:NOT (CL:EQ (%LIST-ITERATOR-CURSOR SELF) NIL))))

;;; (DEFMETHOD (EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD EMPTY? ((SELF LIST-ITERATOR))
  (CL:RETURN-FROM EMPTY?
   (CL:IF (%FIRST-ITERATION? SELF)
    (CL:EQ (%THE-CONS-LIST (%LIST-ITERATOR-COLLECTION SELF)) NIL)
    (CL:EQ (%%REST (%LIST-ITERATOR-CURSOR SELF)) NIL))))

;;; (DEFMETHOD (VALUE-SETTER OBJECT) ...)

(CL:DEFMETHOD VALUE-SETTER ((SELF LIST-ITERATOR) VALUE)
  (CL:SETF (%%VALUE (%LIST-ITERATOR-CURSOR SELF)) VALUE)
  (CL:SETF (%VALUE SELF) VALUE)
  (CL:RETURN-FROM VALUE-SETTER VALUE))

;;; (DEFMETHOD (BUT-LAST (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD BUT-LAST ((SELF LIST))
  "Generate all but the last element of the list `self'."
  (CL:RETURN-FROM BUT-LAST (BUT-LAST (%THE-CONS-LIST SELF))))

;;; (DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ...)

(CL:DEFMETHOD REMOVE-DELETED-MEMBERS ((SELF LIST))
  (CL:SETF (%THE-CONS-LIST SELF)
   (REMOVE-DELETED-MEMBERS (%THE-CONS-LIST SELF)))
  (CL:RETURN-FROM REMOVE-DELETED-MEMBERS SELF))

;;; (DEFMETHOD INITIALIZE-OBJECT ...)

(CL:DEFMETHOD INITIALIZE-OBJECT ((SELF PROPERTY-LIST))
  (CL:SETF (%THE-PLIST SELF) NIL)
  :VOID)

;;; (DEFUN (SEARCH-PLIST OBJECT) ...)

(CL:DEFUN SEARCH-PLIST (PLIST KEY)
  (CL:LOOP WHILE (CL:NOT (CL:EQ PLIST NIL)) DO
   (CL:WHEN (EQL? (%%VALUE PLIST) KEY)
    (CL:RETURN-FROM SEARCH-PLIST (%%VALUE (%%REST PLIST))))
   (CL:SETQ PLIST (%%REST (%%REST PLIST))))
  (CL:RETURN-FROM SEARCH-PLIST NULL))

;;; (DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD LOOKUP ((SELF PROPERTY-LIST) KEY)
  (CL:DECLARE (CL:INLINE SEARCH-PLIST))
  (CL:RETURN-FROM LOOKUP (SEARCH-PLIST (%THE-PLIST SELF) KEY)))

;;; (DEFMETHOD (LOOKUP-WITH-DEFAULT (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD LOOKUP-WITH-DEFAULT ((SELF PROPERTY-LIST) KEY DEFAULT)
  "Lookup `key' in `self' and return the result.
Return `default' if no value was found."
  (CL:LET* ((VALUE (SEARCH-PLIST (%THE-PLIST SELF) KEY)))
   (CL:IF (CL:EQ VALUE NULL) (CL:RETURN-FROM LOOKUP-WITH-DEFAULT DEFAULT)
    (CL:RETURN-FROM LOOKUP-WITH-DEFAULT VALUE))))

;;; (DEFMETHOD (LENGTH INTEGER) ...)

(CL:DEFMETHOD LENGTH ((SELF PROPERTY-LIST))
  (CL:LET* ((CURSOR (%THE-PLIST SELF)) (LENGTH 0))
   (CL:DECLARE (CL:TYPE CL:FIXNUM LENGTH))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
    (CL:SETQ LENGTH (CL:1+ LENGTH)) (CL:SETQ CURSOR (%%REST (%%REST CURSOR))))
   (CL:RETURN-FROM LENGTH LENGTH)))

;;; (DEFMETHOD INSERT-AT ...)

(CL:DEFMETHOD INSERT-AT ((SELF PROPERTY-LIST) KEY VALUE)
  "Insert the entry <`key', `value'> into the property list `self'.
If a previous entry existed with key `key', that entry is replaced."
  (CL:LET* ((CURSOR (%THE-PLIST SELF)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
    (CL:WHEN (EQL? (%%VALUE CURSOR) KEY) (CL:SETQ CURSOR (%%REST CURSOR))
     (CL:SETF (%%VALUE CURSOR) VALUE) (CL:RETURN-FROM INSERT-AT))
    (CL:SETQ CURSOR (%%REST (%%REST CURSOR))))
   (CL:SETF (%THE-PLIST SELF) (CONS KEY (CONS VALUE (%THE-PLIST SELF)))))
  :VOID)

;;; (DEFMETHOD (REMOVE-AT OBJECT) ...)

(CL:DEFMETHOD REMOVE-AT ((SELF PROPERTY-LIST) KEY)
  "Remove the entry that matches the key `key'.  Return the
value of the matching entry, or NULL if there is no matching entry.  Assumes that at
most one entry matches `key'."
  (CL:LET* ((CURSOR (%THE-PLIST SELF)) (PREVIOUSCONS NULL) (VALUE NULL))
   (CL:WHEN (CL:NOT (CL:EQ CURSOR NIL))
    (CL:WHEN (EQL? (%%VALUE CURSOR) KEY)
     (CL:SETF (%THE-PLIST SELF) (%%REST (%%REST CURSOR)))
     (CL:SETQ VALUE (%%VALUE (%%REST CURSOR)))
     (CL:RETURN-FROM REMOVE-AT VALUE))
    (CL:SETQ PREVIOUSCONS (%%REST CURSOR))
    (CL:SETQ CURSOR (%%REST PREVIOUSCONS))
    (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
     (CL:WHEN (EQL? (%%VALUE CURSOR) KEY)
      (CL:SETF (%%REST PREVIOUSCONS) (%%REST (%%REST CURSOR)))
      (CL:SETQ VALUE (%%VALUE (%%REST CURSOR)))
      (CL:RETURN-FROM REMOVE-AT VALUE))
     (CL:SETQ PREVIOUSCONS (%%REST CURSOR))
     (CL:SETQ CURSOR (%%REST PREVIOUSCONS))))
   (CL:RETURN-FROM REMOVE-AT NULL)))

;;; (DEFMETHOD (EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD EMPTY? ((SELF PROPERTY-LIST))
  (CL:RETURN-FROM EMPTY? (CL:EQ (%THE-PLIST SELF) NIL)))

;;; (DEFMETHOD (NON-EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD NON-EMPTY? ((SELF PROPERTY-LIST))
  (CL:RETURN-FROM NON-EMPTY? (CL:NOT (CL:EQ (%THE-PLIST SELF) NIL))))

;;; (DEFMETHOD (COPY (LIKE SELF)) ...)

(CL:DEFMETHOD COPY ((SELF PROPERTY-LIST))
  "Return a copy of the list `self'.  The conses in the copy are
freshly allocated."
  (CL:LET* ((COPY (CREATE-OBJECT (PRIMARY-TYPE SELF))))
   (CL:SETF (%THE-PLIST COPY) (COPY-CONS-LIST (%THE-PLIST SELF)))
   (CL:RETURN-FROM COPY COPY)))

;;; (DEFMETHOD CLEAR ...)

(CL:DEFMETHOD CLEAR ((SELF PROPERTY-LIST))
  "Make `self' an empty property list."
  (CL:SETF (%THE-PLIST SELF) NIL)
  :VOID)

;;; (DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ...)

(CL:DEFMETHOD OBJECT-EQUAL? ((X PROPERTY-LIST) Y)
  "Return TRUE if `x' and `y' represent the same set of key/value pairs.."
  (CL:COND
   ((SUBTYPE-OF? (SAFE-PRIMARY-TYPE Y) SGT-LISTS-STELLA-PROPERTY-LIST)
    (CL:PROGN
     (CL:WHEN (CL:= (LENGTH X) (LENGTH Y))
      (CL:LET* ((KEY NULL) (VALUE NULL) (ITER-000 (%THE-PLIST X)))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
        (CL:SETQ KEY (%%VALUE ITER-000))
        (CL:SETQ VALUE (%%VALUE (%%REST ITER-000)))
        (CL:WHEN (CL:NOT (EQUAL? VALUE (LOOKUP Y KEY)))
         (CL:RETURN-FROM OBJECT-EQUAL? CL:NIL))
        (CL:SETQ ITER-000 (%%REST (%%REST ITER-000)))))
      (CL:RETURN-FROM OBJECT-EQUAL? CL:T))))
   (CL:T))
  (CL:RETURN-FROM OBJECT-EQUAL? CL:NIL))

;;; (DEFMETHOD (EQUAL-HASH-CODE INTEGER) ...)

(CL:DEFMETHOD EQUAL-HASH-CODE ((SELF PROPERTY-LIST))
  "Return an `equal?' hash code for `self'.  Note that this
is O(N) in the number of entries of `self'."
  (CL:LET* ((CODE 108398967)) (CL:DECLARE (CL:TYPE CL:FIXNUM CODE))
   (CL:LET* ((KEY NULL) (VALUE NULL) (ITER-000 (%THE-PLIST SELF)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ KEY (%%VALUE ITER-000))
     (CL:SETQ VALUE (%%VALUE (%%REST ITER-000)))
     (CL:SETQ CODE
      (CL:THE CL:FIXNUM
       (CL:LOGXOR CODE (CL:THE CL:FIXNUM (SAFE-EQUAL-HASH-CODE KEY)))))
     (CL:SETQ CODE
      (CL:THE CL:FIXNUM
       (CL:LOGXOR CODE (CL:THE CL:FIXNUM (SAFE-EQUAL-HASH-CODE VALUE)))))
     (CL:SETQ ITER-000 (%%REST (%%REST ITER-000)))))
   (CL:RETURN-FROM EQUAL-HASH-CODE CODE)))

;;; (DEFMETHOD (SUBSET? BOOLEAN) ...)

(CL:DEFMETHOD SUBSET? ((SELF LIST) OTHERLIST)
  "Return true if every element of `self' also occurs in `otherList'.
Uses an `eql?' test and a simple quadratic-time algorithm.  Note that
this does not check whether `self' and `otherList' actually are sets."
  (CL:RETURN-FROM SUBSET?
   (SUBSET? (%THE-CONS-LIST SELF) (%THE-CONS-LIST OTHERLIST))))

;;; (DEFMETHOD (EQUIVALENT-SETS? BOOLEAN) ...)

(CL:DEFMETHOD EQUIVALENT-SETS? ((SELF LIST) OTHERLIST)
  "Return true if every element of `self' occurs in `otherList' and vice versa.
Uses an `eql?' test and a simple quadratic-time algorithm.  Note that
this does not check whether `self' and `otherList' actually are sets."
  (CL:RETURN-FROM EQUIVALENT-SETS?
   (EQUIVALENT-SETS? (%THE-CONS-LIST SELF) (%THE-CONS-LIST OTHERLIST))))

;;; (DEFMETHOD (INTERSECTION LIST) ...)

(CL:DEFMETHOD INTERSECTION ((SELF LIST) OTHERLIST)
  "Return the set intersection of `self' and `otherList'.  Uses an `eql?'
test and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if both `self' and `otherList' are sets."
  (CL:LET* ((RESULT (CREATE-DERIVED-LIST SELF)))
   (CL:SETF (%THE-CONS-LIST RESULT)
    (INTERSECTION (%THE-CONS-LIST SELF) (%THE-CONS-LIST OTHERLIST)))
   (CL:RETURN-FROM INTERSECTION RESULT)))

;;; (DEFMETHOD (UNION LIST) ...)

(CL:DEFMETHOD UNION ((SELF LIST) OTHERLIST)
  "Return the set union of `self' and `otherList'.  Uses an `eql?' test
and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if both `self' and `otherList' are sets."
  (CL:LET* ((RESULT (CREATE-DERIVED-LIST SELF)))
   (CL:SETF (%THE-CONS-LIST RESULT)
    (UNION (%THE-CONS-LIST SELF) (%THE-CONS-LIST OTHERLIST)))
   (CL:RETURN-FROM UNION RESULT)))

;;; (DEFMETHOD (DIFFERENCE LIST) ...)

(CL:DEFMETHOD DIFFERENCE ((SELF LIST) OTHERLIST)
  "Return the set difference of `self' and `otherList' (i.e., all elements
that are in `self' but not in `otherSet').  Uses an `eql?' test and a simple
quadratic-time algorithm.  Note that the result is only guaranteed to be a
set if both `self' and `otherList' are sets."
  (CL:LET* ((RESULT (CREATE-DERIVED-LIST SELF)))
   (CL:SETF (%THE-CONS-LIST RESULT)
    (DIFFERENCE (%THE-CONS-LIST SELF) (%THE-CONS-LIST OTHERLIST)))
   (CL:RETURN-FROM DIFFERENCE RESULT)))

;;; (DEFMETHOD (SUBTRACT LIST) ...)

(CL:DEFMETHOD SUBTRACT ((SELF LIST) OTHERLIST)
  "Return the set difference of `self' and `otherList' by destructively
removing elements from `self' that also occur in `otherList'.  Uses an `eql?'
test and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if `self' is a set."
  (CL:SETF (%THE-CONS-LIST SELF)
   (SUBTRACT (%THE-CONS-LIST SELF) (%THE-CONS-LIST OTHERLIST)))
  (CL:RETURN-FROM SUBTRACT SELF))

;;; (DEFMETHOD (ALLOCATE-ITERATOR (PROPERTY-LIST-ITERATOR OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD ALLOCATE-ITERATOR ((SELF PROPERTY-LIST))
  (CL:LET* ((ITERATOR (NEW-PROPERTY-LIST-ITERATOR)))
   (CL:SETF (%PLIST-ITERATOR-CURSOR ITERATOR) (%THE-PLIST SELF))
   (CL:SETF (%PLIST-ITERATOR-COLLECTION ITERATOR) SELF)
   (CL:SETF (%FIRST-ITERATION? ITERATOR) CL:T)
   (CL:RETURN-FROM ALLOCATE-ITERATOR ITERATOR)))

;;; (DEFMETHOD (NEXT? BOOLEAN) ...)

(CL:DEFMETHOD NEXT? ((SELF PROPERTY-LIST-ITERATOR))
  (CL:IF (%FIRST-ITERATION? SELF) (CL:SETF (%FIRST-ITERATION? SELF) CL:NIL)
   (CL:SETF (%PLIST-ITERATOR-CURSOR SELF)
    (%%REST (%%REST (%PLIST-ITERATOR-CURSOR SELF)))))
  (CL:LET* ((REMAININGPLIST (%PLIST-ITERATOR-CURSOR SELF)))
   (CL:WHEN (CL:NOT (CL:EQ REMAININGPLIST NIL))
    (CL:SETF (%KEY SELF) (%%VALUE REMAININGPLIST))
    (CL:SETF (%VALUE SELF) (%%VALUE (%%REST REMAININGPLIST)))
    (CL:RETURN-FROM NEXT? CL:T))
   (CL:RETURN-FROM NEXT? CL:NIL)))

;;; (DEFMETHOD (VALUE-SETTER (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD VALUE-SETTER ((SELF PROPERTY-LIST-ITERATOR) VALUE)
  (CL:SETF (%%VALUE (%%REST (%PLIST-ITERATOR-CURSOR SELF))) VALUE)
  (CL:SETF (%VALUE SELF) VALUE)
  (CL:RETURN-FROM VALUE-SETTER VALUE))

;;; (DEFMETHOD (KEY-SETTER (LIKE (ANY-KEY SELF))) ...)

(CL:DEFMETHOD KEY-SETTER ((SELF PROPERTY-LIST-ITERATOR) KEY)
  (CL:SETF (%%VALUE (%PLIST-ITERATOR-CURSOR SELF)) KEY)
  (CL:SETF (%KEY SELF) KEY)
  (CL:RETURN-FROM KEY-SETTER KEY))

;;; (DEFUN (KV-CONS KV-CONS) ...)

(CL:DEFUN KV-CONS (KEY VALUE REST)
  "Create, fill-in, and return a new KV-CONS."
  (CL:LET* ((NEWKVC (NEW-KV-CONS))) (CL:SETF (%KEY NEWKVC) KEY)
   (CL:SETF (%VALUE NEWKVC) VALUE) (CL:SETF (%REST NEWKVC) REST)
   (CL:RETURN-FROM KV-CONS NEWKVC)))

;;; (DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD LOOKUP ((CURSOR KV-CONS) KEY)
  (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NULL)) DO
   (CL:WHEN (EQL? (%KEY CURSOR) KEY) (CL:RETURN-FROM LOOKUP (%VALUE CURSOR)))
   (CL:SETQ CURSOR (%REST CURSOR)))
  (CL:RETURN-FROM LOOKUP NULL))

;;; (DEFMETHOD (LENGTH INTEGER) ...)

(CL:DEFMETHOD LENGTH ((CURSOR KV-CONS))
  (CL:LET* ((LENGTH 0)) (CL:DECLARE (CL:TYPE CL:FIXNUM LENGTH))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NULL)) DO
    (CL:SETQ LENGTH (CL:1+ LENGTH)) (CL:SETQ CURSOR (%REST CURSOR)))
   (CL:RETURN-FROM LENGTH LENGTH)))

;;; (DEFUN FREE-KV-CONS ...)

(CL:DEFUN FREE-KV-CONS (KVCONS)
  (FREE KVCONS)
  :VOID)

;;; (DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD LOOKUP ((SELF KEY-VALUE-LIST) KEY)
  (CL:LET* ((CURSOR (%THE-KV-LIST SELF)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NULL)) DO
    (CL:WHEN (EQL? (%KEY CURSOR) KEY) (CL:RETURN-FROM LOOKUP (%VALUE CURSOR)))
    (CL:SETQ CURSOR (%REST CURSOR)))
   (CL:RETURN-FROM LOOKUP NULL)))

;;; (DEFMETHOD (LOOKUP-WITH-DEFAULT (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD LOOKUP-WITH-DEFAULT ((SELF KEY-VALUE-LIST) KEY DEFAULT)
  "Lookup `key' in `self' and return the result.
Return `default' if no value was found."
  (CL:LET* ((CURSOR (%THE-KV-LIST SELF)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NULL)) DO
    (CL:WHEN (EQL? (%KEY CURSOR) KEY)
     (CL:RETURN-FROM LOOKUP-WITH-DEFAULT (%VALUE CURSOR)))
    (CL:SETQ CURSOR (%REST CURSOR)))
   (CL:RETURN-FROM LOOKUP-WITH-DEFAULT DEFAULT)))

;;; (DEFMETHOD (LENGTH INTEGER) ...)

(CL:DEFMETHOD LENGTH ((SELF KEY-VALUE-LIST))
  (CL:LET* ((LENGTH 0) (CURSOR (%THE-KV-LIST SELF)))
   (CL:DECLARE (CL:TYPE CL:FIXNUM LENGTH))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NULL)) DO
    (CL:SETQ LENGTH (CL:1+ LENGTH)) (CL:SETQ CURSOR (%REST CURSOR)))
   (CL:RETURN-FROM LENGTH LENGTH)))

;;; (DEFMETHOD INSERT-AT ...)

(CL:DEFMETHOD INSERT-AT ((SELF KEY-VALUE-LIST) KEY VALUE)
  "Insert the entry <`key', `value'> into the association
`self'. If a previous entry existed with key `key', that entry is replaced."
  (CL:LET* ((CURSOR (%THE-KV-LIST SELF)))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NULL)) DO
    (CL:WHEN (EQL? (%KEY CURSOR) KEY) (CL:SETF (%VALUE CURSOR) VALUE)
     (CL:RETURN-FROM INSERT-AT))
    (CL:SETQ CURSOR (%REST CURSOR)))
   (CL:SETF (%THE-KV-LIST SELF) (KV-CONS KEY VALUE (%THE-KV-LIST SELF))))
  :VOID)

;;; (DEFMETHOD (REMOVE-AT OBJECT) ...)

(CL:DEFMETHOD REMOVE-AT ((SELF KEY-VALUE-LIST) KEY)
  "Remove the entry that matches the key `key'.
Return the value of the matching entry, or NULL if there is no matching entry.
Assumes that at most one entry matches `key'."
  (CL:LET* ((CURSOR (%THE-KV-LIST SELF)) (PREVIOUSCURSOR NULL) (VALUE NULL))
   (CL:WHEN (CL:NOT (CL:EQ CURSOR NULL))
    (CL:WHEN (EQL? (%KEY CURSOR) KEY)
     (CL:SETF (%THE-KV-LIST SELF) (%REST CURSOR))
     (CL:SETQ VALUE (%VALUE CURSOR)) (FREE-KV-CONS CURSOR)
     (CL:RETURN-FROM REMOVE-AT VALUE))
    (CL:LOOP WHILE (CL:NOT (CL:EQ (%REST CURSOR) NULL)) DO
     (CL:SETQ PREVIOUSCURSOR CURSOR) (CL:SETQ CURSOR (%REST CURSOR))
     (CL:WHEN (EQL? (%KEY CURSOR) KEY)
      (CL:SETF (%REST PREVIOUSCURSOR) (%REST CURSOR))
      (CL:SETQ VALUE (%VALUE CURSOR)) (FREE-KV-CONS CURSOR)
      (CL:RETURN-FROM REMOVE-AT VALUE))))
   (CL:RETURN-FROM REMOVE-AT NULL)))

;;; (DEFMETHOD INSERT-ENTRY ...)

(CL:DEFMETHOD INSERT-ENTRY ((SELF KEY-VALUE-LIST) KEY VALUE)
  "Insert an entry <`key',`value'> to `self' unless an identical
entry already exists.  This can generate duplicate entries for `key'."
  (CL:LET* ((FOUND?-000 CL:NIL))
   (CL:LET* ((K NULL) (V NULL) (ITER-000 (%THE-KV-LIST SELF)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO
     (CL:SETQ K (%KEY ITER-000)) (CL:SETQ V (%VALUE ITER-000))
     (CL:WHEN (CL:AND (CL:EQ K KEY) (CL:EQ V VALUE)) (CL:SETQ FOUND?-000 CL:T)
      (CL:RETURN))
     (CL:SETQ ITER-000 (%REST ITER-000))))
   (CL:WHEN (CL:NOT FOUND?-000)
    (CL:SETF (%THE-KV-LIST SELF) (KV-CONS KEY VALUE (%THE-KV-LIST SELF)))))
  :VOID)

;;; (DEFMETHOD REMOVE-ENTRY ...)

(CL:DEFMETHOD REMOVE-ENTRY ((SELF KEY-VALUE-LIST) KEY VALUE)
  "Remove the entry that matches <`key',`value'>.
Assumes that more than one entry can match `key'."
  (CL:LET* ((CURSOR (%THE-KV-LIST SELF)) (PREVIOUSCURSOR NULL))
   (CL:WHEN (CL:NOT (CL:EQ CURSOR NULL))
    (CL:WHEN (CL:AND (EQL? (%KEY CURSOR) KEY) (EQL? (%VALUE CURSOR) VALUE))
     (CL:SETF (%THE-KV-LIST SELF) (%REST CURSOR)) (FREE-KV-CONS CURSOR)
     (CL:RETURN-FROM REMOVE-ENTRY))
    (CL:LOOP WHILE (CL:NOT (CL:EQ (%REST CURSOR) NULL)) DO
     (CL:SETQ PREVIOUSCURSOR CURSOR) (CL:SETQ CURSOR (%REST CURSOR))
     (CL:WHEN (CL:AND (EQL? (%KEY CURSOR) KEY) (EQL? (%VALUE CURSOR) VALUE))
      (CL:SETF (%REST PREVIOUSCURSOR) (%REST CURSOR)) (FREE-KV-CONS CURSOR)
      (CL:RETURN-FROM REMOVE-ENTRY)))))
  :VOID)

;;; (DEFMETHOD PUSH ...)

(CL:DEFMETHOD PUSH ((SELF KEY-VALUE-LIST) VALUE)
  "Make `value' be the new first element of `self'.  Note that
the `rest' slot of `value' should be `null', since it will be overwritten.
This might duplicate an existing entry. If a previous entry existed with the
same key as `value', that entry is retained, but shadowed by this new entry."
  (CL:WHEN (CL:NOT (CL:EQ (%REST VALUE) NULL))
   (CL:ERROR "Safety violation: Push only supports single entry KV-CONSes"))
  (CL:SETF (%REST VALUE) (%THE-KV-LIST SELF))
  (CL:SETF (%THE-KV-LIST SELF) VALUE)
  :VOID)

;;; (DEFMETHOD KV-PUSH ...)

(CL:DEFMETHOD KV-PUSH ((SELF KEY-VALUE-LIST) KEY VALUE)
  "Add a new entry <`key', `value'> to the front of the association
`self'. This might duplicate an existing entry. If a previous entry existed with key
`key', that entry is retained, but shadowed by this new entry."
  (CL:SETF (%THE-KV-LIST SELF) (KV-CONS KEY VALUE (%THE-KV-LIST SELF)))
  :VOID)

;;; (DEFMETHOD (POP (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD POP ((SELF KEY-VALUE-LIST))
  "Remove and return the value of the first element of the
kv-list `self'.  It does NOT return the KV-CONS object.  Return `null' if
the list is empty."
  (CL:WHEN (EMPTY? SELF) (CL:RETURN-FROM POP NULL))
  (CL:LET* ((CONS (%THE-KV-LIST SELF)) (VALUE NULL))
   (CL:SETQ VALUE (%VALUE CONS)) (CL:SETF (%THE-KV-LIST SELF) (%REST CONS))
   (FREE-KV-CONS CONS) (CL:RETURN-FROM POP VALUE)))

;;; (DEFMETHOD (REVERSE (LIKE SELF)) ...)

(CL:DEFMETHOD REVERSE ((SELF KEY-VALUE-LIST))
  "Destructively reverse the members of the list `self'."
  (CL:LET*
   ((REVERSEDLIST (%THE-KV-LIST SELF)) (REMAININGLIST NULL) (TEMP NULL))
   (CL:WHEN (CL:EQ REVERSEDLIST NULL) (CL:RETURN-FROM REVERSE SELF))
   (CL:SETQ REMAININGLIST (%REST REVERSEDLIST))
   (CL:WHEN (CL:EQ REMAININGLIST NULL) (CL:RETURN-FROM REVERSE SELF))
   (CL:SETF (%REST REVERSEDLIST) NULL)
   (CL:LOOP WHILE (CL:NOT (CL:EQ REMAININGLIST NULL)) DO
    (CL:SETQ TEMP REMAININGLIST) (CL:SETQ REMAININGLIST (%REST REMAININGLIST))
    (CL:SETF (%REST TEMP) REVERSEDLIST) (CL:SETQ REVERSEDLIST TEMP))
   (CL:SETF (%THE-KV-LIST SELF) REVERSEDLIST) (CL:RETURN-FROM REVERSE SELF)))

;;; (DEFMETHOD (EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD EMPTY? ((SELF KEY-VALUE-LIST))
  (CL:RETURN-FROM EMPTY? (CL:EQ (%THE-KV-LIST SELF) NULL)))

;;; (DEFMETHOD (NON-EMPTY? BOOLEAN) ...)

(CL:DEFMETHOD NON-EMPTY? ((SELF KEY-VALUE-LIST))
  (CL:RETURN-FROM NON-EMPTY? (CL:NOT (CL:EQ (%THE-KV-LIST SELF) NULL))))

;;; (DEFUN (COPY-KV-CONS-LIST KV-CONS) ...)

(CL:DEFUN COPY-KV-CONS-LIST (KVCONSLIST)
  "Return a copy of the cons list `consList'."
  (CL:WHEN (CL:EQ KVCONSLIST NULL) (CL:RETURN-FROM COPY-KV-CONS-LIST NULL))
  (CL:LET*
   ((NEWKVCONSLIST (NEW-KV-CONS)) (NEXTKVCONS NEWKVCONSLIST)
    (COPYFROMKVCONS NULL) (PREVIOUSKVCONS NULL))
   (CL:SETF (%KEY NEXTKVCONS) (%KEY KVCONSLIST))
   (CL:SETF (%VALUE NEXTKVCONS) (%VALUE KVCONSLIST))
   (CL:SETQ COPYFROMKVCONS (%REST KVCONSLIST))
   (CL:LOOP WHILE (CL:NOT (CL:EQ COPYFROMKVCONS NULL)) DO
    (CL:SETQ PREVIOUSKVCONS NEXTKVCONS) (CL:SETQ NEXTKVCONS (NEW-KV-CONS))
    (CL:SETF (%REST PREVIOUSKVCONS) NEXTKVCONS)
    (CL:SETF (%KEY NEXTKVCONS) (%KEY COPYFROMKVCONS))
    (CL:SETF (%VALUE NEXTKVCONS) (%VALUE COPYFROMKVCONS))
    (CL:SETQ COPYFROMKVCONS (%REST COPYFROMKVCONS)))
   (CL:SETF (%REST NEXTKVCONS) NULL)
   (CL:RETURN-FROM COPY-KV-CONS-LIST NEWKVCONSLIST)))

;;; (DEFMETHOD (COPY (LIKE SELF)) ...)

(CL:DEFMETHOD COPY ((SELF KEY-VALUE-LIST))
  "Return a copy of the kv-list `self'.  The kv-conses in
the copy are freshly allocated."
  (CL:LET* ((COPY (NEW-KEY-VALUE-LIST)))
   (CL:SETF (%THE-KV-LIST COPY) (COPY-KV-CONS-LIST (%THE-KV-LIST SELF)))
   (CL:RETURN-FROM COPY COPY)))

;;; (DEFMETHOD CLEAR ...)

(CL:DEFMETHOD CLEAR ((SELF KEY-VALUE-LIST))
  "Make `self' an empty dictionary."
  (CL:LET* ((NEXT (%THE-KV-LIST SELF)) (CURRENT NULL))
   (CL:LOOP WHILE (CL:NOT (CL:EQ NEXT NULL)) DO (CL:SETQ CURRENT NEXT)
    (CL:SETQ NEXT (%REST NEXT)) (FREE-KV-CONS CURRENT))
   (CL:SETF (%THE-KV-LIST SELF) NULL))
  :VOID)

;;; (DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ...)

(CL:DEFMETHOD OBJECT-EQUAL? ((X KEY-VALUE-LIST) Y)
  "Return TRUE if `x' and `y' represent the same set of key/value pairs."
  (CL:COND
   ((SUBTYPE-OF? (SAFE-PRIMARY-TYPE Y) SGT-LISTS-STELLA-KEY-VALUE-LIST)
    (CL:PROGN
     (CL:WHEN (CL:= (LENGTH X) (LENGTH Y))
      (CL:LET* ((KEY NULL) (VALUE NULL) (ITER-000 (%THE-KV-LIST X)))
       (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO
        (CL:SETQ KEY (%KEY ITER-000)) (CL:SETQ VALUE (%VALUE ITER-000))
        (CL:WHEN (CL:NOT (EQUAL? VALUE (LOOKUP Y KEY)))
         (CL:RETURN-FROM OBJECT-EQUAL? CL:NIL))
        (CL:SETQ ITER-000 (%REST ITER-000))))
      (CL:RETURN-FROM OBJECT-EQUAL? CL:T))))
   (CL:T))
  (CL:RETURN-FROM OBJECT-EQUAL? CL:NIL))

;;; (DEFMETHOD (EQUAL-HASH-CODE INTEGER) ...)

(CL:DEFMETHOD EQUAL-HASH-CODE ((SELF KEY-VALUE-LIST))
  "Return an `equal?' hash code for `self'.  Note that this
is O(N) in the number of entries of `self'."
  (CL:LET* ((CODE 94797224)) (CL:DECLARE (CL:TYPE CL:FIXNUM CODE))
   (CL:LET* ((KEY NULL) (VALUE NULL) (ITER-000 (%THE-KV-LIST SELF)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO
     (CL:SETQ KEY (%KEY ITER-000)) (CL:SETQ VALUE (%VALUE ITER-000))
     (CL:SETQ CODE
      (CL:THE CL:FIXNUM
       (CL:LOGXOR CODE (CL:THE CL:FIXNUM (SAFE-EQUAL-HASH-CODE KEY)))))
     (CL:SETQ CODE
      (CL:THE CL:FIXNUM
       (CL:LOGXOR CODE (CL:THE CL:FIXNUM (SAFE-EQUAL-HASH-CODE VALUE)))))
     (CL:SETQ ITER-000 (%REST ITER-000))))
   (CL:RETURN-FROM EQUAL-HASH-CODE CODE)))

;;; (DEFMETHOD (ALLOCATE-ITERATOR (KV-LIST-ITERATOR OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD ALLOCATE-ITERATOR ((SELF KEY-VALUE-LIST))
  (CL:LET* ((ITERATOR (NEW-KV-LIST-ITERATOR)))
   (CL:SETF (%THE-KV-LIST ITERATOR) SELF)
   (CL:SETF (%KV-LIST-ITERATOR-CURSOR ITERATOR) (%THE-KV-LIST SELF))
   (CL:SETF (%FIRST-ITERATION? ITERATOR) CL:T)
   (CL:RETURN-FROM ALLOCATE-ITERATOR ITERATOR)))

;;; (DEFMETHOD (NEXT? BOOLEAN) ...)

(CL:DEFMETHOD NEXT? ((SELF KV-LIST-ITERATOR))
  (CL:IF (%FIRST-ITERATION? SELF) (CL:SETF (%FIRST-ITERATION? SELF) CL:NIL)
   (CL:SETF (%KV-LIST-ITERATOR-CURSOR SELF)
    (%REST (%KV-LIST-ITERATOR-CURSOR SELF))))
  (CL:WHEN (CL:EQ (%KV-LIST-ITERATOR-CURSOR SELF) NULL)
   (CL:RETURN-FROM NEXT? CL:NIL))
  (CL:SETF (%KEY SELF) (%KEY (%KV-LIST-ITERATOR-CURSOR SELF)))
  (CL:SETF (%VALUE SELF) (%VALUE (%KV-LIST-ITERATOR-CURSOR SELF)))
  (CL:RETURN-FROM NEXT? CL:T))

;;; (DEFMETHOD (VALUE-SETTER (LIKE (ANY-VALUE SELF))) ...)

(CL:DEFMETHOD VALUE-SETTER ((SELF KV-LIST-ITERATOR) VALUE)
  (CL:SETF (%VALUE (%KV-LIST-ITERATOR-CURSOR SELF)) VALUE)
  (CL:SETF (%VALUE SELF) VALUE)
  (CL:RETURN-FROM VALUE-SETTER VALUE))

;;; (DEFMETHOD (KEY-SETTER OBJECT) ...)

(CL:DEFMETHOD KEY-SETTER ((SELF KV-LIST-ITERATOR) KEY)
  (CL:SETF (%KEY (%KV-LIST-ITERATOR-CURSOR SELF)) KEY)
  (CL:SETF (%KEY SELF) KEY)
  (CL:RETURN-FROM KEY-SETTER KEY))

;;; (DEFUN (KVLIST-TO-PLIST (PROPERTY-LIST OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFUN KVLIST-TO-PLIST (SELF)
  "Convert `self' into a property list with identical and identically
ordered keys and values."
  (CL:LET* ((PLIST NIL))
   (CL:LET* ((KEY NULL) (VALUE NULL) (ITER-000 (%THE-KV-LIST SELF)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO
     (CL:SETQ KEY (%KEY ITER-000)) (CL:SETQ VALUE (%VALUE ITER-000))
     (CL:SETQ PLIST (CONS VALUE (CONS KEY PLIST)))
     (CL:SETQ ITER-000 (%REST ITER-000))))
   (CL:LET* ((SELF-000 (NEW-PROPERTY-LIST)))
    (CL:SETF (%THE-PLIST SELF-000) (REVERSE PLIST))
    (CL:LET* ((VALUE-000 SELF-000))
     (CL:RETURN-FROM KVLIST-TO-PLIST VALUE-000)))))

;;; (DEFUN (PLIST-TO-KVLIST (KEY-VALUE-LIST OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFUN PLIST-TO-KVLIST (SELF)
  "Convert `self' into a key-value list with identical and identically
ordered keys and values."
  (CL:LET* ((KVLIST (NEW-KEY-VALUE-LIST)) (KVCONS NULL))
   (CL:LET* ((KEY NULL) (VALUE NULL) (ITER-000 (%THE-PLIST SELF)))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NIL)) DO
     (CL:SETQ KEY (%%VALUE ITER-000))
     (CL:SETQ VALUE (%%VALUE (%%REST ITER-000)))
     (CL:COND
      ((CL:EQ KVCONS NULL) (CL:SETQ KVCONS (NEW-KV-CONS))
       (CL:SETF (%THE-KV-LIST KVLIST) KVCONS))
      (CL:T (CL:SETF (%REST KVCONS) (NEW-KV-CONS))
       (CL:SETQ KVCONS (%REST KVCONS))))
     (CL:SETF (%KEY KVCONS) KEY) (CL:SETF (%VALUE KVCONS) VALUE)
     (CL:SETQ ITER-000 (%%REST (%%REST ITER-000)))))
   (CL:RETURN-FROM PLIST-TO-KVLIST KVLIST)))

;;; (DEFMETHOD (MEMBER? BOOLEAN) ...)

(CL:DEFMETHOD MEMBER? ((SELF SEQUENCE) VALUE)
  "Return TRUE if `value' is a member of the sequence `self'."
  (CL:LET* ((M NULL) (ITER-000 (ALLOCATE-ITERATOR SELF)))
   (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ M (%VALUE ITER-000))
    (CL:WHEN (EQL? M VALUE) (CL:RETURN-FROM MEMBER? CL:T))))
  (CL:RETURN-FROM MEMBER? CL:NIL))

;;; (DEFUN (LIST LIST) ...)

(CL:DEFUN LIST (CL:&REST VALUES)
  "Return a list containing `values', in order."
  (CL:LET* ((LIST (NEW-LIST)))
   (CL:LET* ((V NULL) (ITER-000 VALUES) (COLLECT-000 NULL))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ V (CL:POP ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS V NIL))
       (CL:IF (CL:EQ (%THE-CONS-LIST LIST) NIL)
        (CL:SETF (%THE-CONS-LIST LIST) COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST (%THE-CONS-LIST LIST) COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS V NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:RETURN-FROM LIST LIST)))

;;; (DEFUN (SEQUENCE (SEQUENCE OF OBJECT)) ...)

(CL:DEFUN SEQUENCE (COLLECTIONTYPE CL:&REST VALUES)
  "Return a sequence containing `values', in order."
  (CL:LET* ((SEQUENCE (CREATE-OBJECT COLLECTIONTYPE)))
   (CL:LET* ((I NULL) (ITER-000 VALUES))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ I (CL:POP ITER-000))
     (CL:COND
      ((SUBTYPE-OF? (SAFE-PRIMARY-TYPE SEQUENCE) SGT-LISTS-STELLA-LIST)
       (CL:PROGN (INSERT-LAST SEQUENCE I)))
      (CL:T
       (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
        (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
         "sequence: Don't know how to `insert-last' into a `" COLLECTIONTYPE
         "'")
        (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000))))))))
   (CL:RETURN-FROM SEQUENCE SEQUENCE)))

;;; (DEFUN (DICTIONARY (ABSTRACT-DICTIONARY OF OBJECT OBJECT)) ...)

(CL:DEFUN DICTIONARY (COLLECTIONTYPE CL:&REST ALTERNATINGKEYSANDVALUES)
  "Return a dictionary of `collectionType' containing `values', in order.
Currently supported `collectionType's are @HASH-TABLE, @STELLA-HASH-TABLE,
@KEY-VALUE-LIST, @KEY-VALUE-MAP and @PROPERTY-LIST."
  (CL:LET*
   ((DICTIONARY (CREATE-OBJECT COLLECTIONTYPE)) (KEY NULL) (VALUE NULL)
    (COPY NIL) (CURSOR NULL))
   (CL:LET*
    ((ITEM NULL) (ITER-000 ALTERNATINGKEYSANDVALUES) (COLLECT-000 NULL))
    (CL:LOOP WHILE ITER-000 DO (CL:SETQ ITEM (CL:POP ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS ITEM NIL))
       (CL:IF (CL:EQ COPY NIL) (CL:SETQ COPY COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST COPY COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS ITEM NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))))
   (CL:SETQ CURSOR COPY)
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NIL)) DO
    (CL:SETQ KEY (%%VALUE CURSOR)) (CL:SETQ VALUE (%%VALUE (%%REST CURSOR)))
    (CL:LET* ((TEST-VALUE-000 (SAFE-PRIMARY-TYPE DICTIONARY)))
     (CL:COND
      ((SUBTYPE-OF? TEST-VALUE-000 SGT-LISTS-STELLA-HASH-TABLE)
       (CL:PROGN (INSERT-AT DICTIONARY KEY VALUE)))
      ((SUBTYPE-OF? TEST-VALUE-000 SGT-LISTS-STELLA-STELLA-HASH-TABLE)
       (CL:PROGN (INSERT-AT DICTIONARY KEY VALUE)))
      ((SUBTYPE-OF? TEST-VALUE-000 SGT-LISTS-STELLA-KEY-VALUE-LIST)
       (CL:PROGN (INSERT-AT DICTIONARY KEY VALUE)))
      ((SUBTYPE-OF? TEST-VALUE-000 SGT-LISTS-STELLA-KEY-VALUE-MAP)
       (CL:PROGN (INSERT-AT DICTIONARY KEY VALUE)))
      ((SUBTYPE-OF? TEST-VALUE-000 SGT-LISTS-STELLA-PROPERTY-LIST)
       (CL:PROGN (INSERT-AT DICTIONARY KEY VALUE)))
      (CL:T
       (CL:LET* ((STREAM-000 (NEW-OUTPUT-STRING-STREAM)))
        (%%PRINT-STREAM (%NATIVE-STREAM STREAM-000)
         "dictionary: Can't create dictionaries of type `" COLLECTIONTYPE "'")
        (CL:ERROR (NEW-STELLA-EXCEPTION (THE-STRING-READER STREAM-000)))))))
    (CL:SETQ CURSOR (%%REST (%%REST CURSOR))))
   (CL:RETURN-FROM DICTIONARY DICTIONARY)))

;;; (DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD LISTIFY ((SELF LIST))
  "Return `self'."
  (CL:RETURN-FROM LISTIFY SELF))

;;; (DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ...)

(%%DEFCONSMETHOD LISTIFY ((SELF CL:CONS))
  "Return a list of elements in `self'."
  (CL:LET* ((SELF-000 (NEW-LIST))) (CL:SETF (%THE-CONS-LIST SELF-000) SELF)
   (CL:LET* ((VALUE-000 SELF-000)) (CL:RETURN-FROM LISTIFY VALUE-000))))

;;; (DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD LISTIFY ((SELF KEY-VALUE-LIST))
  "Return a list of key-value pairs in `self'."
  (CL:LET* ((RESULT (NEW-LIST)))
   (CL:LET*
    ((K NULL) (V NULL) (ITER-000 (%THE-KV-LIST SELF)) (COLLECT-000 NULL))
    (CL:LOOP WHILE (CL:NOT (CL:EQ ITER-000 NULL)) DO
     (CL:SETQ K (%KEY ITER-000)) (CL:SETQ V (%VALUE ITER-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS (CONS K (CONS V NIL)) NIL))
       (CL:IF (CL:EQ (%THE-CONS-LIST RESULT) NIL)
        (CL:SETF (%THE-CONS-LIST RESULT) COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST (%THE-CONS-LIST RESULT) COLLECT-000)))
      (CL:PROGN
       (CL:SETF (%%REST COLLECT-000) (CONS (CONS K (CONS V NIL)) NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))
     (CL:SETQ ITER-000 (%REST ITER-000))))
   (CL:RETURN-FROM LISTIFY RESULT)))

;;; (DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD LISTIFY ((SELF VECTOR))
  "Return a list of elements in `self'."
  (CL:LET* ((RESULT (NEW-LIST)))
   (CL:LET*
    ((V NULL) (VECTOR-000 SELF) (INDEX-000 0) (LENGTH-000 (LENGTH VECTOR-000))
     (COLLECT-000 NULL))
    (CL:DECLARE (CL:TYPE CL:FIXNUM INDEX-000 LENGTH-000))
    (CL:LOOP WHILE (CL:< INDEX-000 LENGTH-000) DO
     (CL:SETQ V
      (CL:AREF (CL:THE CL:SIMPLE-VECTOR (%THE-ARRAY VECTOR-000)) INDEX-000))
     (CL:IF (CL:EQ COLLECT-000 NULL)
      (CL:PROGN (CL:SETQ COLLECT-000 (CONS V NIL))
       (CL:IF (CL:EQ (%THE-CONS-LIST RESULT) NIL)
        (CL:SETF (%THE-CONS-LIST RESULT) COLLECT-000)
        (ADD-CONS-TO-END-OF-CONS-LIST (%THE-CONS-LIST RESULT) COLLECT-000)))
      (CL:PROGN (CL:SETF (%%REST COLLECT-000) (CONS V NIL))
       (CL:SETQ COLLECT-000 (%%REST COLLECT-000))))
     (CL:SETQ INDEX-000 (CL:1+ INDEX-000))))
   (CL:RETURN-FROM LISTIFY RESULT)))

;;; (DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ...)

(CL:DEFMETHOD LISTIFY ((SELF ITERATOR))
  "Return a list of elements generated by `self'."
  (CL:LET* ((LIST (NEW-LIST)))
   (CL:LET* ((VALUE NULL) (ITER-000 SELF))
    (CL:LOOP WHILE (NEXT? ITER-000) DO (CL:SETQ VALUE (%VALUE ITER-000))
     (PUSH LIST VALUE)))
   (CL:RETURN-FROM LISTIFY (REVERSE LIST))))

;;; (DEFUN PRINT-KEY-VALUE-LIST ...)

(CL:DEFUN PRINT-KEY-VALUE-LIST (SELF STREAM)
  (%%PRINT-STREAM STREAM "|kv|(")
  (CL:LET* ((CURSOR (%THE-KV-LIST SELF)) (POSITION 1))
   (CL:DECLARE (CL:TYPE CL:FIXNUM POSITION))
   (CL:LOOP WHILE (CL:NOT (CL:EQ CURSOR NULL)) DO
    (CL:WHEN (CL:AND (DEFINED? *PRINTLENGTH*) (CL:> POSITION *PRINTLENGTH*))
     (%%PRINT-STREAM STREAM " ...") (CL:RETURN))
    (CL:WHEN (CL:NOT (CL:= POSITION 1)) (%%PRINT-STREAM STREAM " "))
    (%%PRINT-STREAM STREAM CURSOR) (CL:SETQ CURSOR (%REST CURSOR))
    (CL:SETQ POSITION (CL:1+ POSITION)))
   (%%PRINT-STREAM STREAM ")"))
  :VOID)

(CL:DEFUN HELP-STARTUP-LISTS1 ()
  (CL:PROGN
   (CL:SETQ SGT-LISTS-STELLA-LIST
    (INTERN-RIGID-SYMBOL-WRT-MODULE "LIST" NULL 1))
   (CL:SETQ SGT-LISTS-STELLA-SET
    (INTERN-RIGID-SYMBOL-WRT-MODULE "SET" NULL 1))
   (CL:SETQ SGT-LISTS-STELLA-PROPERTY-LIST
    (INTERN-RIGID-SYMBOL-WRT-MODULE "PROPERTY-LIST" NULL 1))
   (CL:SETQ SGT-LISTS-STELLA-KEY-VALUE-LIST
    (INTERN-RIGID-SYMBOL-WRT-MODULE "KEY-VALUE-LIST" NULL 1))
   (CL:SETQ SGT-LISTS-STELLA-HASH-TABLE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "HASH-TABLE" NULL 1))
   (CL:SETQ SGT-LISTS-STELLA-STELLA-HASH-TABLE
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STELLA-HASH-TABLE" NULL 1))
   (CL:SETQ SGT-LISTS-STELLA-KEY-VALUE-MAP
    (INTERN-RIGID-SYMBOL-WRT-MODULE "KEY-VALUE-MAP" NULL 1))
   (CL:SETQ SYM-LISTS-STELLA-STARTUP-LISTS
    (INTERN-RIGID-SYMBOL-WRT-MODULE "STARTUP-LISTS" NULL 0))
   (CL:SETQ SYM-LISTS-STELLA-METHOD-STARTUP-CLASSNAME
    (INTERN-RIGID-SYMBOL-WRT-MODULE "METHOD-STARTUP-CLASSNAME" NULL 0)))
  :VOID)

(CL:DEFUN HELP-STARTUP-LISTS2 ()
  (CL:PROGN
   (DEFINE-FUNCTION-OBJECT "DEFINED-LIST?"
    "(DEFUN (DEFINED-LIST? BOOLEAN) ((SELF LIST)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE unless `self' is NULL or the `NIL-LIST'.\")"
    (CL:FUNCTION DEFINED-LIST?) NULL)
   (DEFINE-FUNCTION-OBJECT "NULL-LIST?"
    "(DEFUN (NULL-LIST? BOOLEAN) ((SELF LIST)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE iff `self' is NULL or the `NIL-LIST'.\")"
    (CL:FUNCTION NULL-LIST?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF LIST)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the list `self' has no members.\")"
    (CL:FUNCTION EMPTY?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF LIST)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the list `self' has at least one member.\")"
    (CL:FUNCTION NON-EMPTY?) NULL)
   (DEFINE-FUNCTION-OBJECT "TERMINATE-LIST?"
    "(DEFUN (TERMINATE-LIST? BOOLEAN) ((SELF LIST)))"
    (CL:FUNCTION TERMINATE-LIST?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF LIST) (OBJECT OBJECT)) :DOCUMENTATION \"Return TRUE iff `object' is a member of the list
`self' (uses an `eql?' test).\" :PUBLIC? TRUE)" (CL:FUNCTION MEMBER?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (MEMB? BOOLEAN) ((SELF LIST) (OBJECT (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Return TRUE iff `object' is a member of the cons list
`self' (uses an 'eq?' test).\" :PUBLIC? TRUE)" (CL:FUNCTION MEMB?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FIRST (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the first item in the list `self', or NULL if empty.\" :PUBLIC? TRUE)"
    (CL:FUNCTION FIRST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (SECOND (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the second item in the list `self', or NULL if empty.\" :PUBLIC? TRUE)"
    (CL:FUNCTION SECOND) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (THIRD (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the third item in the list `self', or NULL if empty.\" :PUBLIC? TRUE)"
    (CL:FUNCTION THIRD) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FOURTH (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the fourth item in the list `self', or NULL if empty.\" :PUBLIC? TRUE)"
    (CL:FUNCTION FOURTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FIFTH (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the fifth item in the list `self', or NULL if empty.\" :PUBLIC? TRUE)"
    (CL:FUNCTION FIFTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ((SELF LIST) (POSITION INTEGER)) :DOCUMENTATION \"Return the nth item in the list `self', or NULL if empty.\" :PUBLIC? TRUE)"
    (CL:FUNCTION NTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LAST (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the last element of `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LAST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REST (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)) :DOCUMENTATION \"Return a cons list of all but the first item in the list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION REST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FIRST-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION FIRST-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (SECOND-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION SECOND-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (THIRD-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION THIRD-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FOURTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION FOURTH-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (FIFTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION FIFTH-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF))) (POSITION INTEGER)) :PUBLIC? TRUE)"
    (CL:FUNCTION NTH-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LENGTH INTEGER) ((SELF LIST)) :PUBLIC? TRUE)"
    (CL:FUNCTION LENGTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (POSITION INTEGER) ((SELF LIST) (OBJECT OBJECT) (START INTEGER)) :DOCUMENTATION \"Return the position of `object' within the list
`self' (counting from zero); or return NULL if `object' does not occur within 
`self' (uses an `eql?' test).  If `start' was supplied as non-NULL, only 
consider the sublist starting at `start', however, the returned position 
will always be relative to the entire list.\" :PUBLIC? TRUE)"
    (CL:FUNCTION POSITION) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LAST-POSITION INTEGER) ((SELF LIST) (OBJECT OBJECT) (END INTEGER)) :DOCUMENTATION \"Return the position of `object' within the list
`self' (counting from zero); or return NULL if `object' does not occur within 
`self' (uses an `eql?' test).  If `end' was supplied as non-NULL, only 
consider the sublist ending at `end', however, the returned position 
will always be relative to the entire list.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LAST-POSITION) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD INSERT ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Add `value' to the front of the list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION INSERT) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD PUSH ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Add `value' to the front of the list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PUSH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD INSERT-NEW ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Add `value' to the front of the list `self' unless its 
already a member.\" :PUBLIC? TRUE)" (CL:FUNCTION INSERT-NEW) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD INSERT-LAST ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Insert `value' as the last entry in the list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION INSERT-LAST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE (LIKE SELF)) ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Destructively remove all entries in `self' that match `value'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION REMOVE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE-IF (LIKE SELF)) ((SELF LIST) (TEST? FUNCTION-CODE)) :DOCUMENTATION \"Destructively remove all members of the list `self' for which
'test?' evaluates to TRUE.  `test' takes a single argument of type OBJECT and
returns TRUE or FALSE.  Returns `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION REMOVE-IF) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE-DUPLICATES (LIKE SELF)) ((SELF LIST)) :DOCUMENTATION \"Destructively remove duplicates from `self' and return the result.
Preserves the original order of the remaining members.\" :PUBLIC? TRUE)"
    (CL:FUNCTION REMOVE-DUPLICATES) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (POP (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Remove and return the first element in the list `self'.
Return NULL if the list is empty.\" :PUBLIC? TRUE)" (CL:FUNCTION POP) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REVERSE (LIKE SELF)) ((SELF LIST)) :DOCUMENTATION \"Reverse the members of `self' (in place).\" :PUBLIC? TRUE)"
    (CL:FUNCTION REVERSE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (SUBSTITUTE (LIKE SELF)) ((SELF LIST) (INVALUE OBJECT) (OUTVALUE OBJECT)) :DOCUMENTATION \"Destructively replace each appearance of `outValue' by
`inValue' in the list `self'.\")" (CL:FUNCTION SUBSTITUTE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (CONCATENATE LIST) ((LIST1 LIST) (LIST2 LIST) |&REST| (OTHERLISTS LIST)) :DOCUMENTATION \"Copy `list2' and all `otherLists' onto the end of `list1'.
The operation is destructive wrt `list1', but leaves all other lists intact.
The two mandatory parameters allow us to optimize the common binary case by
not relying on the somewhat less efficient variable arguments mechanism.\" :PUBLIC? TRUE)"
    (CL:FUNCTION CONCATENATE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (PREPEND (LIKE SELF)) ((SELF LIST) (LIST2 LIST)) :DOCUMENTATION \"Copy `list2' onto the front of the list `self'.
The operation is destructive wrt `self', but leaves `list2' intact.\" :PUBLIC? TRUE)"
    (CL:FUNCTION PREPEND) NULL)
   (DEFINE-FUNCTION-OBJECT "CREATE-DERIVED-LIST"
    "(DEFUN (CREATE-DERIVED-LIST LIST) ((SELF LIST)) :DOCUMENTATION \"Create a new list object with the same type as `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION CREATE-DERIVED-LIST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (COPY (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)) :DOCUMENTATION \"Return a copy of the list `self'.  The conses in the copy are
freshly allocated.\" :PUBLIC? TRUE)" (CL:FUNCTION COPY) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD CLEAR ((SELF LIST)) :DOCUMENTATION \"Make `self' an empty list.\" :PUBLIC? TRUE)"
    (CL:FUNCTION CLEAR) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (SORT (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST) (PREDICATE FUNCTION-CODE)) :PUBLIC? TRUE :DOCUMENTATION \"Perform a stable, destructive sort of `self' according to
`predicate', and return the result.  If `predicate' has a '<' semantics, the
result will be in ascending order.  If `predicate' is NULL, a suitable
'<' predicate is chosen depending on the first element of `self', and it 
is assumed that all elements of `self' have the same type (supported
element types are GENERALIZED-SYMBOL, STRING, INTEGER, and FLOAT).\")"
    (CL:FUNCTION SORT) NULL)
   (DEFINE-FUNCTION-OBJECT "MAP-NULL-TO-NIL-LIST"
    "(DEFUN (MAP-NULL-TO-NIL-LIST LIST) ((SELF LIST)) :DOCUMENTATION \"Return NIL-LIST iff `self' is NULL or `self' otherwise.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (CHOOSE (NULL? SELF) NIL-LIST SELF)))"
    (CL:FUNCTION MAP-NULL-TO-NIL-LIST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ((X LIST) (Y OBJECT)) :DOCUMENTATION \"Return TRUE iff the lists `x' and `y' are structurally
equivalent.  Uses `equal?' to test equality of elements.\" :PUBLIC? TRUE)"
    (CL:FUNCTION OBJECT-EQUAL?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (EQUAL-HASH-CODE INTEGER) ((SELF LIST)) :DOCUMENTATION \"Return an `equal?' hash code for `self'.  Note that this
is O(N) in the number of elements of `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION EQUAL-HASH-CODE) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (ALLOCATE-ITERATOR (LIST-ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)))"
    (CL:FUNCTION ALLOCATE-ITERATOR) NULL)
   (DEFINE-FUNCTION-OBJECT "TERMINATE-LIST-ITERATOR?"
    "(DEFUN (TERMINATE-LIST-ITERATOR? BOOLEAN) ((SELF LIST-ITERATOR)))"
    (CL:FUNCTION TERMINATE-LIST-ITERATOR?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NEXT? BOOLEAN) ((SELF LIST-ITERATOR)) :PUBLIC? TRUE)"
    (CL:FUNCTION NEXT?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF LIST-ITERATOR)) :PUBLIC? TRUE)"
    (CL:FUNCTION EMPTY?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (VALUE-SETTER OBJECT) ((SELF LIST-ITERATOR) (VALUE (LIKE (ANY-VALUE SELF)))))"
    (CL:FUNCTION VALUE-SETTER) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (BUT-LAST (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)) :DOCUMENTATION \"Generate all but the last element of the list `self'.\" :PUBLIC? TRUE)"
    (CL:FUNCTION BUT-LAST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE-DELETED-MEMBERS (LIKE SELF)) ((SELF LIST)) :PUBLIC? TRUE)"
    (CL:FUNCTION REMOVE-DELETED-MEMBERS) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD INITIALIZE-OBJECT ((SELF PROPERTY-LIST)))"
    (CL:FUNCTION INITIALIZE-OBJECT) NULL)
   (DEFINE-FUNCTION-OBJECT "SEARCH-PLIST"
    "(DEFUN (SEARCH-PLIST OBJECT) ((PLIST CONS) (KEY OBJECT)))"
    (CL:FUNCTION SEARCH-PLIST) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF PROPERTY-LIST) (KEY (LIKE (ANY-KEY SELF)))) :PUBLIC? TRUE)"
    (CL:FUNCTION LOOKUP) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LOOKUP-WITH-DEFAULT (LIKE (ANY-VALUE SELF))) ((SELF PROPERTY-LIST) (KEY (LIKE (ANY-KEY SELF))) (DEFAULT (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Lookup `key' in `self' and return the result.
Return `default' if no value was found.\" :PUBLIC? TRUE)"
    (CL:FUNCTION LOOKUP-WITH-DEFAULT) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (LENGTH INTEGER) ((SELF PROPERTY-LIST)) :PUBLIC? TRUE)"
    (CL:FUNCTION LENGTH) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD INSERT-AT ((SELF PROPERTY-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Insert the entry <`key', `value'> into the property list `self'.
If a previous entry existed with key `key', that entry is replaced.\" :PUBLIC? TRUE)"
    (CL:FUNCTION INSERT-AT) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (REMOVE-AT OBJECT) ((SELF PROPERTY-LIST) (KEY (LIKE (ANY-KEY SELF)))) :DOCUMENTATION \"Remove the entry that matches the key `key'.  Return the
value of the matching entry, or NULL if there is no matching entry.  Assumes that at
most one entry matches `key'.\" :PUBLIC? TRUE)" (CL:FUNCTION REMOVE-AT) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF PROPERTY-LIST)) :PUBLIC? TRUE)"
    (CL:FUNCTION EMPTY?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF PROPERTY-LIST)) :PUBLIC? TRUE)"
    (CL:FUNCTION NON-EMPTY?) NULL)
   (DEFINE-METHOD-OBJECT
    "(DEFMETHOD (COPY (LIKE SELF)) ((SELF PROPERTY-LIST)) :DOCUMENTATION \"Return a copy of the list `self'.  The conses in the copy are
freshly allocated.\" :PUBLIC? TRUE)" (CL:FUNCTION COPY) NULL))
  :VOID)

(CL:DEFUN STARTUP-LISTS ()
  (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 0)
   (CL:WHEN (CL:EQ NIL-LIST NULL)
    (CL:SETQ NIL-LIST (CL:MAKE-INSTANCE (CL:QUOTE LIST))))
   (CL:SETF (%THE-CONS-LIST NIL-LIST) NIL))
  (CL:LET* ((*MODULE* *STELLA-MODULE*) (*CONTEXT* *MODULE*))
   (CL:DECLARE (CL:SPECIAL *MODULE* *CONTEXT*))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 2) (HELP-STARTUP-LISTS1))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 6) (FINALIZE-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 7) (HELP-STARTUP-LISTS2)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD CLEAR ((SELF PROPERTY-LIST)) :DOCUMENTATION \"Make `self' an empty property list.\")"
     (CL:FUNCTION CLEAR) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ((X PROPERTY-LIST) (Y OBJECT)) :DOCUMENTATION \"Return TRUE if `x' and `y' represent the same set of key/value pairs..\" :PUBLIC? TRUE)"
     (CL:FUNCTION OBJECT-EQUAL?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (EQUAL-HASH-CODE INTEGER) ((SELF PROPERTY-LIST)) :DOCUMENTATION \"Return an `equal?' hash code for `self'.  Note that this
is O(N) in the number of entries of `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION EQUAL-HASH-CODE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SUBSET? BOOLEAN) ((SELF LIST) (OTHERLIST LIST)) :DOCUMENTATION \"Return true if every element of `self' also occurs in `otherList'.
Uses an `eql?' test and a simple quadratic-time algorithm.  Note that
this does not check whether `self' and `otherList' actually are sets.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SUBSET?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (EQUIVALENT-SETS? BOOLEAN) ((SELF LIST) (OTHERLIST LIST)) :DOCUMENTATION \"Return true if every element of `self' occurs in `otherList' and vice versa.
Uses an `eql?' test and a simple quadratic-time algorithm.  Note that
this does not check whether `self' and `otherList' actually are sets.\" :PUBLIC? TRUE)"
     (CL:FUNCTION EQUIVALENT-SETS?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (INTERSECTION LIST) ((SELF LIST) (OTHERLIST LIST)) :DOCUMENTATION \"Return the set intersection of `self' and `otherList'.  Uses an `eql?'
test and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if both `self' and `otherList' are sets.\" :PUBLIC? TRUE)"
     (CL:FUNCTION INTERSECTION) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (UNION LIST) ((SELF LIST) (OTHERLIST LIST)) :DOCUMENTATION \"Return the set union of `self' and `otherList'.  Uses an `eql?' test
and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if both `self' and `otherList' are sets.\" :PUBLIC? TRUE)"
     (CL:FUNCTION UNION) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (DIFFERENCE LIST) ((SELF LIST) (OTHERLIST LIST)) :DOCUMENTATION \"Return the set difference of `self' and `otherList' (i.e., all elements
that are in `self' but not in `otherSet').  Uses an `eql?' test and a simple
quadratic-time algorithm.  Note that the result is only guaranteed to be a
set if both `self' and `otherList' are sets.\" :PUBLIC? TRUE)"
     (CL:FUNCTION DIFFERENCE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (SUBTRACT LIST) ((SELF LIST) (OTHERLIST LIST)) :DOCUMENTATION \"Return the set difference of `self' and `otherList' by destructively
removing elements from `self' that also occur in `otherList'.  Uses an `eql?'
test and a simple quadratic-time algorithm.  Note that the result is only
guaranteed to be a set if `self' is a set.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SUBTRACT) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (ALLOCATE-ITERATOR (PROPERTY-LIST-ITERATOR OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF)))) ((SELF PROPERTY-LIST)))"
     (CL:FUNCTION ALLOCATE-ITERATOR) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (NEXT? BOOLEAN) ((SELF PROPERTY-LIST-ITERATOR)) :PUBLIC? TRUE)"
     (CL:FUNCTION NEXT?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (VALUE-SETTER (LIKE (ANY-VALUE SELF))) ((SELF PROPERTY-LIST-ITERATOR) (VALUE (LIKE (ANY-VALUE SELF)))))"
     (CL:FUNCTION VALUE-SETTER) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (KEY-SETTER (LIKE (ANY-KEY SELF))) ((SELF PROPERTY-LIST-ITERATOR) (KEY (LIKE (ANY-KEY SELF)))))"
     (CL:FUNCTION KEY-SETTER) NULL)
    (DEFINE-FUNCTION-OBJECT "KV-CONS"
     "(DEFUN (KV-CONS KV-CONS) ((KEY OBJECT) (VALUE OBJECT) (REST KV-CONS)) :DOCUMENTATION \"Create, fill-in, and return a new KV-CONS.\")"
     (CL:FUNCTION KV-CONS) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((CURSOR KV-CONS) (KEY (LIKE (ANY-KEY SELF)))) :PUBLIC? TRUE)"
     (CL:FUNCTION LOOKUP) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LENGTH INTEGER) ((CURSOR KV-CONS)) :PUBLIC? TRUE)"
     (CL:FUNCTION LENGTH) NULL)
    (DEFINE-FUNCTION-OBJECT "FREE-KV-CONS"
     "(DEFUN FREE-KV-CONS ((KVCONS KV-CONS)))" (CL:FUNCTION FREE-KV-CONS)
     NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF)))) :PUBLIC? TRUE)"
     (CL:FUNCTION LOOKUP) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LOOKUP-WITH-DEFAULT (LIKE (ANY-VALUE SELF))) ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF))) (DEFAULT (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Lookup `key' in `self' and return the result.
Return `default' if no value was found.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LOOKUP-WITH-DEFAULT) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LENGTH INTEGER) ((SELF KEY-VALUE-LIST)) :PUBLIC? TRUE)"
     (CL:FUNCTION LENGTH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD INSERT-AT ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE :DOCUMENTATION \"Insert the entry <`key', `value'> into the association
`self'. If a previous entry existed with key `key', that entry is replaced.\")"
     (CL:FUNCTION INSERT-AT) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (REMOVE-AT OBJECT) ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF)))) :PUBLIC? TRUE :DOCUMENTATION \"Remove the entry that matches the key `key'.
Return the value of the matching entry, or NULL if there is no matching entry.
Assumes that at most one entry matches `key'.\")" (CL:FUNCTION REMOVE-AT)
     NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD INSERT-ENTRY ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE :DOCUMENTATION \"Insert an entry <`key',`value'> to `self' unless an identical
entry already exists.  This can generate duplicate entries for `key'.\")"
     (CL:FUNCTION INSERT-ENTRY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD REMOVE-ENTRY ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE :DOCUMENTATION \"Remove the entry that matches <`key',`value'>.
Assumes that more than one entry can match `key'.\")"
     (CL:FUNCTION REMOVE-ENTRY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD PUSH ((SELF KEY-VALUE-LIST) (VALUE KV-CONS)) :DOCUMENTATION \"Make `value' be the new first element of `self'.  Note that
the `rest' slot of `value' should be `null', since it will be overwritten.
This might duplicate an existing entry. If a previous entry existed with the
same key as `value', that entry is retained, but shadowed by this new entry.\" :PUBLIC? TRUE)"
     (CL:FUNCTION PUSH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD KV-PUSH ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Add a new entry <`key', `value'> to the front of the association
`self'. This might duplicate an existing entry. If a previous entry existed with key
`key', that entry is retained, but shadowed by this new entry.\")"
     (CL:FUNCTION KV-PUSH) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (POP (LIKE (ANY-VALUE SELF))) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Remove and return the value of the first element of the
kv-list `self'.  It does NOT return the KV-CONS object.  Return `null' if
the list is empty.\" :PUBLIC? TRUE)" (CL:FUNCTION POP) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (REVERSE (LIKE SELF)) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Destructively reverse the members of the list `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION REVERSE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF KEY-VALUE-LIST)) :PUBLIC? TRUE)"
     (CL:FUNCTION EMPTY?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF KEY-VALUE-LIST)) :PUBLIC? TRUE)"
     (CL:FUNCTION NON-EMPTY?) NULL)
    (DEFINE-FUNCTION-OBJECT "COPY-KV-CONS-LIST"
     "(DEFUN (COPY-KV-CONS-LIST KV-CONS) ((KVCONSLIST KV-CONS)) :DOCUMENTATION \"Return a copy of the cons list `consList'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION COPY-KV-CONS-LIST) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (COPY (LIKE SELF)) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Return a copy of the kv-list `self'.  The kv-conses in
the copy are freshly allocated.\" :PUBLIC? TRUE)" (CL:FUNCTION COPY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD CLEAR ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Make `self' an empty dictionary.\" :PUBLIC? TRUE)"
     (CL:FUNCTION CLEAR) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (OBJECT-EQUAL? BOOLEAN) ((X KEY-VALUE-LIST) (Y OBJECT)) :DOCUMENTATION \"Return TRUE if `x' and `y' represent the same set of key/value pairs.\" :PUBLIC? TRUE)"
     (CL:FUNCTION OBJECT-EQUAL?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (EQUAL-HASH-CODE INTEGER) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Return an `equal?' hash code for `self'.  Note that this
is O(N) in the number of entries of `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION EQUAL-HASH-CODE) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (ALLOCATE-ITERATOR (KV-LIST-ITERATOR OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF)))) ((SELF KEY-VALUE-LIST)) :PUBLIC? TRUE)"
     (CL:FUNCTION ALLOCATE-ITERATOR) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (NEXT? BOOLEAN) ((SELF KV-LIST-ITERATOR)) :PUBLIC? TRUE)"
     (CL:FUNCTION NEXT?) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (VALUE-SETTER (LIKE (ANY-VALUE SELF))) ((SELF KV-LIST-ITERATOR) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE)"
     (CL:FUNCTION VALUE-SETTER) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (KEY-SETTER OBJECT) ((SELF KV-LIST-ITERATOR) (KEY OBJECT)) :PUBLIC? TRUE)"
     (CL:FUNCTION KEY-SETTER) NULL)
    (DEFINE-FUNCTION-OBJECT "KVLIST-TO-PLIST"
     "(DEFUN (KVLIST-TO-PLIST (PROPERTY-LIST OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF)))) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Convert `self' into a property list with identical and identically
ordered keys and values.\" :PUBLIC? TRUE)" (CL:FUNCTION KVLIST-TO-PLIST) NULL)
    (DEFINE-FUNCTION-OBJECT "PLIST-TO-KVLIST"
     "(DEFUN (PLIST-TO-KVLIST (KEY-VALUE-LIST OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF)))) ((SELF PROPERTY-LIST)) :DOCUMENTATION \"Convert `self' into a key-value list with identical and identically
ordered keys and values.\" :PUBLIC? TRUE)" (CL:FUNCTION PLIST-TO-KVLIST) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF SEQUENCE) (VALUE OBJECT)) :DOCUMENTATION \"Return TRUE if `value' is a member of the sequence `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION MEMBER?) NULL)
    (DEFINE-FUNCTION-OBJECT "LIST"
     "(DEFUN (LIST LIST) (|&REST| (VALUES OBJECT)) :DOCUMENTATION \"Return a list containing `values', in order.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LIST) NULL)
    (DEFINE-FUNCTION-OBJECT "SEQUENCE"
     "(DEFUN (SEQUENCE (SEQUENCE OF OBJECT)) ((COLLECTIONTYPE TYPE) |&REST| (VALUES OBJECT)) :DOCUMENTATION \"Return a sequence containing `values', in order.\" :PUBLIC? TRUE)"
     (CL:FUNCTION SEQUENCE) NULL)
    (DEFINE-FUNCTION-OBJECT "DICTIONARY"
     "(DEFUN (DICTIONARY (ABSTRACT-DICTIONARY OF OBJECT OBJECT)) ((COLLECTIONTYPE TYPE) |&REST| (ALTERNATINGKEYSANDVALUES OBJECT)) :DOCUMENTATION \"Return a dictionary of `collectionType' containing `values', in order.
Currently supported `collectionType's are @HASH-TABLE, @STELLA-HASH-TABLE,
@KEY-VALUE-LIST, @KEY-VALUE-MAP and @PROPERTY-LIST.\" :PUBLIC? TRUE)"
     (CL:FUNCTION DICTIONARY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)) :DOCUMENTATION \"Return `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LISTIFY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS)) :DOCUMENTATION \"Return a list of elements in `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LISTIFY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Return a list of key-value pairs in `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LISTIFY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF VECTOR)) :DOCUMENTATION \"Return a list of elements in `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LISTIFY) NULL)
    (DEFINE-METHOD-OBJECT
     "(DEFMETHOD (LISTIFY (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF ITERATOR)) :DOCUMENTATION \"Return a list of elements generated by `self'.\" :PUBLIC? TRUE)"
     (CL:FUNCTION LISTIFY) NULL)
    (DEFINE-FUNCTION-OBJECT "PRINT-KEY-VALUE-LIST"
     "(DEFUN PRINT-KEY-VALUE-LIST ((SELF KEY-VALUE-LIST) (STREAM NATIVE-OUTPUT-STREAM)))"
     (CL:FUNCTION PRINT-KEY-VALUE-LIST) NULL)
    (DEFINE-FUNCTION-OBJECT "STARTUP-LISTS"
     "(DEFUN STARTUP-LISTS () :PUBLIC? TRUE)" (CL:FUNCTION STARTUP-LISTS)
     NULL)
    (CL:LET* ((FUNCTION (LOOKUP-FUNCTION SYM-LISTS-STELLA-STARTUP-LISTS)))
     (SET-DYNAMIC-SLOT-VALUE (%DYNAMIC-SLOTS FUNCTION)
      SYM-LISTS-STELLA-METHOD-STARTUP-CLASSNAME (WRAP-STRING "_StartupLists")
      NULL-STRING-WRAPPER)))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 8) (FINALIZE-SLOTS)
    (CLEANUP-UNFINALIZED-CLASSES))
   (CL:WHEN (CURRENT-STARTUP-TIME-PHASE? 9)
    (DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE
     "(DEFGLOBAL NIL-LIST LIST NULL :PUBLIC? TRUE)")))
  :VOID)
