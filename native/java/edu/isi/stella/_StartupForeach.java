//  -*- Mode: Java -*-
//
// _StartupForeach.java

/*
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
*/

package edu.isi.stella;

import edu.isi.stella.javalib.*;

public class _StartupForeach {
  static void helpStartupForeach1() {
    {
      Stella.SYM_STELLA_AS = ((Symbol)(Stella.internRigidSymbolWrtModule("AS", null, 0)));
      Stella.SYM_STELLA_COMMA = ((Symbol)(Stella.internRigidSymbolWrtModule("COMMA", null, 0)));
      Stella.SYM_STELLA_COLLECT = ((Symbol)(Stella.internRigidSymbolWrtModule("COLLECT", null, 0)));
      Stella.SYM_STELLA_PREFIX_FOREACH = ((Symbol)(Stella.internRigidSymbolWrtModule("PREFIX-FOREACH", null, 0)));
      Stella.SYM_STELLA_X = ((Symbol)(Stella.internRigidSymbolWrtModule("X", null, 0)));
      Stella.SYM_STELLA_WHERE = ((Symbol)(Stella.internRigidSymbolWrtModule("WHERE", null, 0)));
      Stella.SYM_STELLA_INTO = ((Symbol)(Stella.internRigidSymbolWrtModule("INTO", null, 0)));
      Stella.SYM_STELLA_COLLECT_INTO = ((Symbol)(Stella.internRigidSymbolWrtModule("COLLECT-INTO", null, 0)));
      Stella.SYM_STELLA_EXISTS = ((Symbol)(Stella.internRigidSymbolWrtModule("EXISTS", null, 0)));
      Stella.SYM_STELLA_FORALL = ((Symbol)(Stella.internRigidSymbolWrtModule("FORALL", null, 0)));
      Stella.SYM_STELLA_SOME = ((Symbol)(Stella.internRigidSymbolWrtModule("SOME", null, 0)));
      Stella.SGT_STELLA_INTEGER_INTERVAL = ((Surrogate)(Stella.internRigidSymbolWrtModule("INTEGER-INTERVAL", null, 1)));
      Stella.SGT_STELLA_ABSTRACT_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("ABSTRACT-ITERATOR", null, 1)));
      Stella.SYM_STELLA_ALLOCATE_ITERATOR = ((Symbol)(Stella.internRigidSymbolWrtModule("ALLOCATE-ITERATOR", null, 0)));
      Stella.SGT_STELLA_ARGUMENT_LIST = ((Surrogate)(Stella.internRigidSymbolWrtModule("ARGUMENT-LIST", null, 1)));
      Stella.SGT_STELLA_SEQUENCE_MIXIN = ((Surrogate)(Stella.internRigidSymbolWrtModule("SEQUENCE-MIXIN", null, 1)));
      Stella.SYM_STELLA_THE_ARRAY = ((Symbol)(Stella.internRigidSymbolWrtModule("THE-ARRAY", null, 0)));
      Stella.SYM_STELLA_NILp = ((Symbol)(Stella.internRigidSymbolWrtModule("NIL?", null, 0)));
      Stella.SYM_STELLA_NEXTp = ((Symbol)(Stella.internRigidSymbolWrtModule("NEXT?", null, 0)));
      Stella.SYM_STELLA_ANY_VALUE = ((Symbol)(Stella.internRigidSymbolWrtModule("ANY-VALUE", null, 0)));
      Stella.SYM_STELLA_ANY_KEY = ((Symbol)(Stella.internRigidSymbolWrtModule("ANY-KEY", null, 0)));
      Stella.SYM_STELLA_le = ((Symbol)(Stella.internRigidSymbolWrtModule("<=", null, 0)));
      Stella.SYM_STELLA_OR = ((Symbol)(Stella.internRigidSymbolWrtModule("OR", null, 0)));
      Stella.SYM_STELLA_1_ = ((Symbol)(Stella.internRigidSymbolWrtModule("1-", null, 0)));
      Stella.SYM_STELLA__ = ((Symbol)(Stella.internRigidSymbolWrtModule("-", null, 0)));
      Stella.SYM_STELLA_l = ((Symbol)(Stella.internRigidSymbolWrtModule("<", null, 0)));
      Stella.SYM_STELLA_LENGTH = ((Symbol)(Stella.internRigidSymbolWrtModule("LENGTH", null, 0)));
      Stella.SYM_STELLA_NTH = ((Symbol)(Stella.internRigidSymbolWrtModule("NTH", null, 0)));
      Stella.SGT_STELLA_ARGUMENT_LIST_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("ARGUMENT-LIST-ITERATOR", null, 1)));
      Stella.SYM_STELLA_SYS_CALL_METHOD = ((Symbol)(Stella.internRigidSymbolWrtModule("SYS-CALL-METHOD", null, 0)));
      Stella.SYM_STELLA_ON = ((Symbol)(Stella.internRigidSymbolWrtModule("ON", null, 0)));
      Stella.SYM_STELLA_EMPTYp = ((Symbol)(Stella.internRigidSymbolWrtModule("EMPTY?", null, 0)));
      Stella.SYM_STELLA_ADD_CONS_TO_END_OF_CONS_LIST = ((Symbol)(Stella.internRigidSymbolWrtModule("ADD-CONS-TO-END-OF-CONS-LIST", null, 0)));
      Stella.SYM_STELLA_CONSp = ((Symbol)(Stella.internRigidSymbolWrtModule("CONS?", null, 0)));
      Stella.SYM_STELLA_SYS_FOREACH = ((Symbol)(Stella.internRigidSymbolWrtModule("SYS-FOREACH", null, 0)));
      Stella.SYM_STELLA_BREAK = ((Symbol)(Stella.internRigidSymbolWrtModule("BREAK", null, 0)));
      Stella.SYM_STELLA_ALWAYS = ((Symbol)(Stella.internRigidSymbolWrtModule("ALWAYS", null, 0)));
      Stella.SYM_STELLA_STARTUP_FOREACH = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-FOREACH", null, 0)));
    }
  }

  public static void startupForeach() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.$STELLA_MODULE$);
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupForeach.helpStartupForeach1();
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("EXTRACT-ONE-IN-CLAUSE", "(DEFUN (EXTRACT-ONE-IN-CLAUSE CONS CONS) ((TAIL CONS)))", Native.find_java_method("edu.isi.stella.Cons", "extractOneInClause", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("EXTRACT-ONE-GENERATOR-TERM", "(DEFUN (EXTRACT-ONE-GENERATOR-TERM CONS CONS) ((TAIL CONS)))", Native.find_java_method("edu.isi.stella.Cons", "extractOneGeneratorTerm", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("EXTRACT-GENERATORS-CLAUSE", "(DEFUN (EXTRACT-GENERATORS-CLAUSE CONS CONS) ((TAIL CONS)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "extractGeneratorsClause", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("EXTRACT-OPTION-AND-RESIDUE", "(DEFUN (EXTRACT-OPTION-AND-RESIDUE OBJECT CONS) ((OPTION SYMBOL) (TAIL CONS)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Symbol", "extractOptionAndResidue", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("EXTRACT-DO-CLAUSE", "(DEFUN (EXTRACT-DO-CLAUSE CONS CONS) ((TAIL CONS)))", Native.find_java_method("edu.isi.stella.Cons", "extractDoClause", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("FOREACH-TO-PREFIX-FOREACH-TREE", "(DEFUN (FOREACH-TO-PREFIX-FOREACH-TREE CONS) ((FOREACHTREE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "foreachToPrefixForeachTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("WALK-FOREACH-TREE", "(DEFUN (WALK-FOREACH-TREE CONS TYPE-SPEC) ((TREE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "walkForeachTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("WALK-COLLECTION-TREE", "(DEFUN (WALK-COLLECTION-TREE OBJECT TYPE-SPEC) ((TREE OBJECT) (DONTOPTIMIZE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Stella_Object", "walkCollectionTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE, Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("YIELD-IN-CURSOR-CLAUSES", "(DEFUN (YIELD-IN-CURSOR-CLAUSES CONS CONS CONS OBJECT) ((INTREE CONS) (DONTOPTIMIZE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Cons", "yieldInCursorClauses", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Boolean.TYPE, Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("USE-VECTOR-STYLE-ITERATION?", "(DEFUN (USE-VECTOR-STYLE-ITERATION? BOOLEAN) ((COLLECTIONTYPE TYPE)))", Native.find_java_method("edu.isi.stella.Surrogate", "useVectorStyleIterationP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("YIELD-IN-CURSOR-CLAUSES-FOR-GENERAL-COLLECTION", "(DEFUN (YIELD-IN-CURSOR-CLAUSES-FOR-GENERAL-COLLECTION CONS CONS CONS OBJECT) ((COLLECTIONTREE OBJECT) (COLLECTIONTYPE TYPE-SPEC) (KEYVAR SYMBOL) (VALUEVAR SYMBOL)))", Native.find_java_method("edu.isi.stella.Stella_Object", "yieldInCursorClausesForGeneralCollection", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.StandardObject"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("YIELD-IN-CURSOR-CLAUSES-FOR-INTEGER-INTERVAL", "(DEFUN (YIELD-IN-CURSOR-CLAUSES-FOR-INTEGER-INTERVAL CONS CONS CONS OBJECT) ((COLLECTIONTREE CONS) (COLLECTIONTYPE TYPE-SPEC) (KEYVAR SYMBOL) (VALUEVAR SYMBOL)))", Native.find_java_method("edu.isi.stella.Cons", "yieldInCursorClausesForIntegerInterval", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.StandardObject"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("YIELD-OPTIMIZED-IN-CURSOR-CLAUSES-FOR-INTEGER-INTERVAL", "(DEFUN (YIELD-OPTIMIZED-IN-CURSOR-CLAUSES-FOR-INTEGER-INTERVAL CONS CONS CONS OBJECT) ((COLLECTIONTREE CONS) (COLLECTIONTYPE TYPE-SPEC) (KEYVAR SYMBOL) (VALUEVAR SYMBOL)))", Native.find_java_method("edu.isi.stella.Cons", "yieldOptimizedInCursorClausesForIntegerInterval", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.StandardObject"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("YIELD-IN-CURSOR-CLAUSES-FOR-VECTOR", "(DEFUN (YIELD-IN-CURSOR-CLAUSES-FOR-VECTOR CONS CONS CONS OBJECT) ((COLLECTIONTREE OBJECT) (COLLECTIONTYPE TYPE-SPEC) (KEYVAR SYMBOL) (VALUEVAR SYMBOL)))", Native.find_java_method("edu.isi.stella.Stella_Object", "yieldInCursorClausesForVector", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.StandardObject"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("YIELD-IN-CURSOR-CLAUSES-FOR-ARGUMENT-LIST", "(DEFUN (YIELD-IN-CURSOR-CLAUSES-FOR-ARGUMENT-LIST CONS CONS CONS OBJECT) ((COLLECTIONTREE OBJECT) (COLLECTIONTYPE TYPE-SPEC) (KEYVAR SYMBOL) (VALUEVAR SYMBOL)))", Native.find_java_method("edu.isi.stella.Stella_Object", "yieldInCursorClausesForArgumentList", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.StandardObject"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("YIELD-ON-CURSOR-CLAUSES", "(DEFUN (YIELD-ON-CURSOR-CLAUSES CONS CONS CONS OBJECT) ((ONTREE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "yieldOnCursorClauses", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("COLLECT-CURSOR-CLAUSES", "(DEFUN (COLLECT-CURSOR-CLAUSES CONS CONS CONS OBJECT) ((CURSORSTREE CONS) (DONTOPTIMIZE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Cons", "collectCursorClauses", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Boolean.TYPE, Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("WALK-CURSORS-TREE", "(DEFUN (WALK-CURSORS-TREE CONS CONS CONS OBJECT) ((CURSORSTREE CONS) (DONTOPTIMIZE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Cons", "walkCursorsTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Boolean.TYPE, Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("YIELD-COLLECT-INTO-LIST-CODE", "(DEFUN (YIELD-COLLECT-INTO-LIST-CODE CONS) ((COLLECTVARIABLE SYMBOL) (INTOVARIABLE OBJECT) (COLLECTTREE OBJECT)))", Native.find_java_method("edu.isi.stella.Symbol", "yieldCollectIntoListCode", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("YIELD-COLLECT-INTO-CONS-CODE", "(DEFUN (YIELD-COLLECT-INTO-CONS-CODE CONS) ((COLLECTVARIABLE SYMBOL) (INTOVARIABLE OBJECT) (COLLECTTREE OBJECT)))", Native.find_java_method("edu.isi.stella.Symbol", "yieldCollectIntoConsCode", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("YIELD-COLLECT-CODE", "(DEFUN (YIELD-COLLECT-CODE CONS) ((COLLECTVARIABLE SYMBOL) (INTOVARIABLE OBJECT) (COLLECTTREE OBJECT)))", Native.find_java_method("edu.isi.stella.Symbol", "yieldCollectCode", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("WALK-PREFIX-COLLECT-INTO-TREE", "(DEFUN (WALK-PREFIX-COLLECT-INTO-TREE CONS CONS) ((COLLECTINTOTREE CONS) (ITERATORS (CONS OF CONS)) (DOCODE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "walkPrefixCollectIntoTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("WRAP-WHERE-TEST", "(DEFUN (WRAP-WHERE-TEST CONS) ((WHERETEST OBJECT) (ACTIONS CONS)))", Native.find_java_method("edu.isi.stella.Stella_Object", "wrapWhereTest", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("WALK-PREFIX-FOREACH-BODY", "(DEFUN (WALK-PREFIX-FOREACH-BODY CONS) ((ITERATORCLAUSES CONS) (WHERETEST OBJECT) (DOACTIONS CONS)))", Native.find_java_method("edu.isi.stella.Cons", "walkPrefixForeachBody", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("WALK-PREFIX-FOREACH-TREE", "(DEFUN (WALK-PREFIX-FOREACH-TREE CONS TYPE-SPEC) ((TREE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "walkPrefixForeachTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("WALK-EXISTS-TREE", "(DEFUN (WALK-EXISTS-TREE CONS TYPE-SPEC) ((TREE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "walkExistsTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("WALK-FORALL-TREE", "(DEFUN (WALK-FORALL-TREE CONS TYPE-SPEC) ((TREE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "walkForallTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("WALK-SOME-TREE", "(DEFUN (WALK-SOME-TREE CONS TYPE-SPEC) ((TREE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "walkSomeTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("STARTUP-FOREACH", "(DEFUN STARTUP-FOREACH () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella._StartupForeach", "startupForeach", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Stella.SYM_STELLA_STARTUP_FOREACH);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Stella.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupForeach"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *AGGRESSIVELY-OPTIMIZE-INTERVAL-FOREACH?* BOOLEAN FALSE)");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
