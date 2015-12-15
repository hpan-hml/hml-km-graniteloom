//  -*- Mode: Java -*-
//
// _StartupLoomToKif.java

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
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 1997-2006      |
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
*/

package edu.isi.powerloom.logic;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

public class _StartupLoomToKif {
  static void helpStartupLoomToKif1() {
    {
      Logic.SYM_STELLA_INVERSE = ((Symbol)(Stella.internRigidSymbolWrtModule("INVERSE", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_PL_KERNEL_KB_INVERSE = ((Symbol)(Stella.internRigidSymbolWrtModule("INVERSE", Stella.getStellaModule("/PL-KERNEL-KB", true), 0)));
      Logic.KWD_BINARY = ((Keyword)(Stella.internRigidSymbolWrtModule("BINARY", null, 2)));
      Logic.KWD_UNARY = ((Keyword)(Stella.internRigidSymbolWrtModule("UNARY", null, 2)));
      Logic.SYM_LOGIC_AT_LEAST = ((Symbol)(Stella.internRigidSymbolWrtModule("AT-LEAST", null, 0)));
      Logic.SYM_LOGIC_AT_MOST = ((Symbol)(Stella.internRigidSymbolWrtModule("AT-MOST", null, 0)));
      Logic.SYM_LOGIC_EXACTLY = ((Symbol)(Stella.internRigidSymbolWrtModule("EXACTLY", null, 0)));
      Logic.SYM_STELLA_SOME = ((Symbol)(Stella.internRigidSymbolWrtModule("SOME", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_LOGIC_FILLED_BY = ((Symbol)(Stella.internRigidSymbolWrtModule("FILLED-BY", null, 0)));
      Logic.SYM_LOGIC_FILLERS = ((Symbol)(Stella.internRigidSymbolWrtModule("FILLERS", null, 0)));
      Logic.SYM_LOGIC_NOT_FILLED_BY = ((Symbol)(Stella.internRigidSymbolWrtModule("NOT-FILLED-BY", null, 0)));
      Logic.SYM_PL_KERNEL_KB_RANGE_CARDINALITY_LOWER_BOUND = ((Symbol)(Stella.internRigidSymbolWrtModule("RANGE-CARDINALITY-LOWER-BOUND", Stella.getStellaModule("/PL-KERNEL-KB", true), 0)));
      Logic.SYM_PL_KERNEL_KB_RANGE_CARDINALITY_UPPER_BOUND = ((Symbol)(Stella.internRigidSymbolWrtModule("RANGE-CARDINALITY-UPPER-BOUND", Stella.getStellaModule("/PL-KERNEL-KB", true), 0)));
      Logic.SYM_PL_KERNEL_KB_RANGE_CARDINALITY = ((Symbol)(Stella.internRigidSymbolWrtModule("RANGE-CARDINALITY", Stella.getStellaModule("/PL-KERNEL-KB", true), 0)));
      Logic.SYM_PL_KERNEL_KB_QUALIFIED_RANGE_CARDINALITY_LOWER_BOUND = ((Symbol)(Stella.internRigidSymbolWrtModule("QUALIFIED-RANGE-CARDINALITY-LOWER-BOUND", Stella.getStellaModule("/PL-KERNEL-KB", true), 0)));
      Logic.SYM_PL_KERNEL_KB_QUALIFIED_RANGE_CARDINALITY_UPPER_BOUND = ((Symbol)(Stella.internRigidSymbolWrtModule("QUALIFIED-RANGE-CARDINALITY-UPPER-BOUND", Stella.getStellaModule("/PL-KERNEL-KB", true), 0)));
      Logic.SYM_PL_KERNEL_KB_QUALIFIED_RANGE_CARDINALITY = ((Symbol)(Stella.internRigidSymbolWrtModule("QUALIFIED-RANGE-CARDINALITY", Stella.getStellaModule("/PL-KERNEL-KB", true), 0)));
      Logic.SYM_PL_KERNEL_KB_RANGE_TYPE = ((Symbol)(Stella.internRigidSymbolWrtModule("RANGE-TYPE", Stella.getStellaModule("/PL-KERNEL-KB", true), 0)));
      Logic.SYM_LOGIC_RELATES = ((Symbol)(Stella.internRigidSymbolWrtModule("RELATES", null, 0)));
      Logic.SYM_LOGIC_THROUGH = ((Symbol)(Stella.internRigidSymbolWrtModule("THROUGH", null, 0)));
      Logic.SYM_LOGIC_INTERVALii = ((Symbol)(Stella.internRigidSymbolWrtModule("INTERVAL++", null, 0)));
      Logic.SYM_LOGIC_INTERVALi_ = ((Symbol)(Stella.internRigidSymbolWrtModule("INTERVAL+-", null, 0)));
      Logic.SYM_LOGIC_INTERVAL_i = ((Symbol)(Stella.internRigidSymbolWrtModule("INTERVAL-+", null, 0)));
      Logic.SYM_LOGIC_INTERVAL__ = ((Symbol)(Stella.internRigidSymbolWrtModule("INTERVAL--", null, 0)));
      Logic.SYM_LOGIC_SAME_AS = ((Symbol)(Stella.internRigidSymbolWrtModule("SAME-AS", null, 0)));
      Logic.SYM_LOGIC_lg = ((Symbol)(Stella.internRigidSymbolWrtModule("<>", null, 0)));
      Logic.SYM_LOGIC_ONE_OF = ((Symbol)(Stella.internRigidSymbolWrtModule("ONE-OF", null, 0)));
      Logic.SYM_LOGIC_THE_ORDERED_SET = ((Symbol)(Stella.internRigidSymbolWrtModule("THE-ORDERED-SET", null, 0)));
      Logic.SYM_LOGIC_SATISFIES = ((Symbol)(Stella.internRigidSymbolWrtModule("SATISFIES", null, 0)));
      Logic.SYM_LOGIC_DOMAIN = ((Symbol)(Stella.internRigidSymbolWrtModule("DOMAIN", null, 0)));
      Logic.SYM_LOGIC_DOMAINS = ((Symbol)(Stella.internRigidSymbolWrtModule("DOMAINS", null, 0)));
      Logic.SYM_LOGIC_RANGE = ((Symbol)(Stella.internRigidSymbolWrtModule("RANGE", null, 0)));
      Logic.SYM_LOGIC_COMPOSE = ((Symbol)(Stella.internRigidSymbolWrtModule("COMPOSE", null, 0)));
      Logic.SYM_LOGIC_SUPERRELATIONS = ((Symbol)(Stella.internRigidSymbolWrtModule("SUPERRELATIONS", null, 0)));
      Logic.SYM_LOGIC_SUPERCONCEPTS = ((Symbol)(Stella.internRigidSymbolWrtModule("SUPERCONCEPTS", null, 0)));
      Logic.SYM_STELLA_RETRACT = ((Symbol)(Stella.internRigidSymbolWrtModule("RETRACT", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.KWD_3_VALUED_P = ((Keyword)(Stella.internRigidSymbolWrtModule("3-VALUED-P", null, 2)));
      Logic.SYM_STELLA_ASK = ((Symbol)(Stella.internRigidSymbolWrtModule("ASK", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_STELLA_CONSIFY = ((Symbol)(Stella.internRigidSymbolWrtModule("CONSIFY", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_STELLA_RETRIEVE = ((Symbol)(Stella.internRigidSymbolWrtModule("RETRIEVE", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_LOGIC_EVAL_WHEN = ((Symbol)(Stella.internRigidSymbolWrtModule("EVAL-WHEN", null, 0)));
      Logic.SYM_LOGIC_TELL = ((Symbol)(Stella.internRigidSymbolWrtModule("TELL", null, 0)));
      Logic.SYM_LOGIC_FORGET = ((Symbol)(Stella.internRigidSymbolWrtModule("FORGET", null, 0)));
      Logic.SYM_LOGIC_TELLM = ((Symbol)(Stella.internRigidSymbolWrtModule("TELLM", null, 0)));
      Logic.SYM_LOGIC_FORGETM = ((Symbol)(Stella.internRigidSymbolWrtModule("FORGETM", null, 0)));
      Logic.SYM_LOGIC_CREATEM = ((Symbol)(Stella.internRigidSymbolWrtModule("CREATEM", null, 0)));
      Logic.SYM_LOGIC_DEFSET = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFSET", null, 0)));
      Logic.SYM_LOGIC_DEFPROPERTY = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFPROPERTY", null, 0)));
      Logic.SYM_LOGIC_DEFCONTEXT = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFCONTEXT", null, 0)));
      Logic.SYM_LOGIC_ADD_VALUE = ((Symbol)(Stella.internRigidSymbolWrtModule("ADD-VALUE", null, 0)));
      Logic.SYM_LOGIC_SET_VALUE = ((Symbol)(Stella.internRigidSymbolWrtModule("SET-VALUE", null, 0)));
      Logic.SYM_LOGIC_FADD_VALUE = ((Symbol)(Stella.internRigidSymbolWrtModule("FADD-VALUE", null, 0)));
      Logic.SYM_STELLA_CHANGE_CONTEXT = ((Symbol)(Stella.internRigidSymbolWrtModule("CHANGE-CONTEXT", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_LOGIC_IN_CONTEXT = ((Symbol)(Stella.internRigidSymbolWrtModule("IN-CONTEXT", null, 0)));
      Logic.SYM_LOGIC_IN_KB = ((Symbol)(Stella.internRigidSymbolWrtModule("IN-KB", null, 0)));
      Logic.SYM_STELLA_NIL = ((Symbol)(Stella.internRigidSymbolWrtModule("NIL", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_LOGIC_COVERING = ((Symbol)(Stella.internRigidSymbolWrtModule("COVERING", null, 0)));
      Logic.KWD_SINGLE_VALUED = ((Keyword)(Stella.internRigidSymbolWrtModule("SINGLE-VALUED", null, 2)));
      Logic.SYM_LOGIC_CLOSED = ((Symbol)(Stella.internRigidSymbolWrtModule("CLOSED", null, 0)));
      Logic.KWD_COMMUTATIVE = ((Keyword)(Stella.internRigidSymbolWrtModule("COMMUTATIVE", null, 2)));
    }
  }

  static void helpStartupLoomToKif2() {
    {
      Logic.SYM_LOGIC_COMMUTATIVE = ((Symbol)(Stella.internRigidSymbolWrtModule("COMMUTATIVE", null, 0)));
      Logic.KWD_SYMMETRIC = ((Keyword)(Stella.internRigidSymbolWrtModule("SYMMETRIC", null, 2)));
      Logic.SYM_LOGIC_SYMMETRIC = ((Symbol)(Stella.internRigidSymbolWrtModule("SYMMETRIC", null, 0)));
      Logic.KWD_CLOS_CLASS = ((Keyword)(Stella.internRigidSymbolWrtModule("CLOS-CLASS", null, 2)));
      Logic.KWD_MULTIPLE_VALUED = ((Keyword)(Stella.internRigidSymbolWrtModule("MULTIPLE-VALUED", null, 2)));
      Logic.KWD_HASH_ON_DOMAINS = ((Keyword)(Stella.internRigidSymbolWrtModule("HASH-ON-DOMAINS", null, 2)));
      Logic.KWD_NON_EXPORTED = ((Keyword)(Stella.internRigidSymbolWrtModule("NON-EXPORTED", null, 2)));
      Logic.KWD_PERFECT = ((Keyword)(Stella.internRigidSymbolWrtModule("PERFECT", null, 2)));
      Logic.KWD_CLOSED_ON_CONSTANTS = ((Keyword)(Stella.internRigidSymbolWrtModule("CLOSED-ON-CONSTANTS", null, 2)));
      Logic.KWD_BACKWARD_CHAINING = ((Keyword)(Stella.internRigidSymbolWrtModule("BACKWARD-CHAINING", null, 2)));
      Logic.KWD_MONOTONIC = ((Keyword)(Stella.internRigidSymbolWrtModule("MONOTONIC", null, 2)));
      Logic.KWD_TEMPORAL = ((Keyword)(Stella.internRigidSymbolWrtModule("TEMPORAL", null, 2)));
      Logic.KWD_ATTRIBUTES = ((Keyword)(Stella.internRigidSymbolWrtModule("ATTRIBUTES", null, 2)));
      Logic.KWD_CHARACTERISTICS = ((Keyword)(Stella.internRigidSymbolWrtModule("CHARACTERISTICS", null, 2)));
      Logic.KWD_PARTITION = ((Keyword)(Stella.internRigidSymbolWrtModule("PARTITION", null, 2)));
      Logic.KWD_PARTITIONS = ((Keyword)(Stella.internRigidSymbolWrtModule("PARTITIONS", null, 2)));
      Logic.KWD_CONSTRAINTS = ((Keyword)(Stella.internRigidSymbolWrtModule("CONSTRAINTS", null, 2)));
      Logic.KWD_EXHAUSTIVE_PARTITION = ((Keyword)(Stella.internRigidSymbolWrtModule("EXHAUSTIVE-PARTITION", null, 2)));
      Logic.KWD_EXHAUSTIVE_PARTITIONS = ((Keyword)(Stella.internRigidSymbolWrtModule("EXHAUSTIVE-PARTITIONS", null, 2)));
      Logic.KWD_IS_PRIMITIVE = ((Keyword)(Stella.internRigidSymbolWrtModule("IS-PRIMITIVE", null, 2)));
      Logic.KWD_IS = ((Keyword)(Stella.internRigidSymbolWrtModule("IS", null, 2)));
      Logic.KWD_DEFAULTS = ((Keyword)(Stella.internRigidSymbolWrtModule("DEFAULTS", null, 2)));
      Logic.KWD_DOMAIN = ((Keyword)(Stella.internRigidSymbolWrtModule("DOMAIN", null, 2)));
      Logic.KWD_DOMAINS = ((Keyword)(Stella.internRigidSymbolWrtModule("DOMAINS", null, 2)));
      Logic.KWD_RANGE = ((Keyword)(Stella.internRigidSymbolWrtModule("RANGE", null, 2)));
      Logic.KWD_ARITY = ((Keyword)(Stella.internRigidSymbolWrtModule("ARITY", null, 2)));
      Logic.KWD_IN_PARTITION = ((Keyword)(Stella.internRigidSymbolWrtModule("IN-PARTITION", null, 2)));
      Logic.KWD_ANNOTATIONS = ((Keyword)(Stella.internRigidSymbolWrtModule("ANNOTATIONS", null, 2)));
      Logic.KWD_ROLES = ((Keyword)(Stella.internRigidSymbolWrtModule("ROLES", null, 2)));
      Logic.KWD_NAME = ((Keyword)(Stella.internRigidSymbolWrtModule("NAME", null, 2)));
      Logic.KWD_IDENTIFIER = ((Keyword)(Stella.internRigidSymbolWrtModule("IDENTIFIER", null, 2)));
      Logic.KWD_llegg = ((Keyword)(Stella.internRigidSymbolWrtModule("<<=>>", null, 2)));
      Logic.KWD_egg = ((Keyword)(Stella.internRigidSymbolWrtModule("=>>", null, 2)));
      Logic.SYM_LOGIC_STARTUP_LOOM_TO_KIF = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-LOOM-TO-KIF", null, 0)));
    }
  }

  public static void startupLoomToKif() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupLoomToKif.helpStartupLoomToKif1();
          _StartupLoomToKif.helpStartupLoomToKif2();
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("LOOM-ARGUMENT-DESCRIPTION-TO-KIF", "(DEFUN (LOOM-ARGUMENT-DESCRIPTION-TO-KIF OBJECT) ((TREE OBJECT) (ARITY KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "loomArgumentDescriptionToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("LOOM-RESTRICTION-TO-KIF", "(DEFUN (LOOM-RESTRICTION-TO-KIF CONS) ((TREE CONS) (IMPLICITVARIABLE SYMBOL)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "loomRestrictionToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("LOOM-RELATES-TO-KIF", "(DEFUN (LOOM-RELATES-TO-KIF CONS) ((TREE CONS) (IMPLICITVARIABLES (CONS OF SYMBOL))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "loomRelatesToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("SUBSTITUTE-VARIABLES-IN-TREE", "(DEFUN SUBSTITUTE-VARIABLES-IN-TREE ((TREE CONS) (SUBSTITUTION CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "substituteVariablesInTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("LOOM-THROUGH-TO-KIF", "(DEFUN (LOOM-THROUGH-TO-KIF CONS) ((TREE CONS) (IMPLICITVARIABLES (CONS OF SYMBOL))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "loomThroughToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("LOOM-SATISFIES-TO-KIF", "(DEFUN (LOOM-SATISFIES-TO-KIF CONS) ((TREE CONS) (IMPLICITVARIABLES (CONS OF SYMBOL))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "loomSatisfiesToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("LOOM-DESCRIPTION-TO-KIF", "(DEFUN (LOOM-DESCRIPTION-TO-KIF CONS) ((TREE OBJECT) (IMPLICITVARIABLES (CONS OF SYMBOL))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "loomDescriptionToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("LOOM-DESCRIPTION-OPERATOR?", "(DEFUN (LOOM-DESCRIPTION-OPERATOR? BOOLEAN) ((SELF OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "loomDescriptionOperatorP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("LOOM-SENTENCE-TO-KIF", "(DEFUN (LOOM-SENTENCE-TO-KIF OBJECT) ((TREE OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "loomSentenceToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("COMPUTE-LOOM-DESCRIPTION-ARITY", "(DEFUN (COMPUTE-LOOM-DESCRIPTION-ARITY INTEGER) ((TREE OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "computeLoomDescriptionArity", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("ELIMINATE-LOOM-KEYWORDS", "(DEFUN (ELIMINATE-LOOM-KEYWORDS OBJECT) ((TREE OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "eliminateLoomKeywords", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("YIELD-IMPLICIT-VARIABLES", "(DEFUN (YIELD-IMPLICIT-VARIABLES (CONS OF SYMBOL)) ((ARITY INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "yieldImplicitVariables", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
          Stella.defineFunctionObject("HELP-TRANSLATE-LOOM-DESCRIPTION-TO-KIF", "(DEFUN (HELP-TRANSLATE-LOOM-DESCRIPTION-TO-KIF CONS) ((TREE OBJECT) (IMPLICITVARIABLES (CONS OF SYMBOL))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "helpTranslateLoomDescriptionToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-DESCRIPTION-TO-KIF", "(DEFUN (TRANSLATE-LOOM-DESCRIPTION-TO-KIF CONS) ((TREE OBJECT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomDescriptionToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-SENTENCE-TO-KIF", "(DEFUN (TRANSLATE-LOOM-SENTENCE-TO-KIF OBJECT) ((TREE OBJECT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomSentenceToKif", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-ASSERTIONS", "(DEFUN (TRANSLATE-LOOM-ASSERTIONS CONS) ((TREE CONS) (RETRACT? BOOLEAN)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomAssertions", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-ASK", "(DEFUN (TRANSLATE-LOOM-ASK CONS) ((TREE CONS)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomAsk", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-RETRIEVE", "(DEFUN (TRANSLATE-LOOM-RETRIEVE CONS) ((TREE CONS)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomRetrieve", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("TRANSLATE-ONE-LOOM-FORM", "(DEFUN (TRANSLATE-ONE-LOOM-FORM CONS) ((TREE OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateOneLoomForm", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("SAFE-GET-NEXT-S-EXPRESSION", "(DEFUN (SAFE-GET-NEXT-S-EXPRESSION OBJECT) ((ITER S-EXPRESSION-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "safeGetNextSExpression", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SExpressionIterator")}), null);
          Stella.defineFunctionObject("DESTRUCTIVELY-UNQUOTE-TOP-LEVEL", "(DEFUN DESTRUCTIVELY-UNQUOTE-TOP-LEVEL ((TREE CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "destructivelyUnquoteTopLevel", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-FILE", "(DEFUN TRANSLATE-LOOM-FILE ((INPUT FILE-NAME) (OUTPUT FILE-NAME)) :DOCUMENTATION \"Translate the Loom file `input' to PowerLoom and write the\ntranslation to the file `output'.  Note that this will only\nwork for fairly vanilla Loom files that do not contain any\nLisp-isms.  It might require to clean the Loom file manually\nbefore this translation will work.\" :PUBLIC? TRUE :COMMAND? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomFile", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String")}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomFileEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("TRANSLATE-LOOM-STATEMENT", "(DEFUN (TRANSLATE-LOOM-STATEMENT CONS) ((TREE CONS)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomStatement", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-CREATE-CLAUSE", "(DEFUN (TRANSLATE-LOOM-CREATE-CLAUSE CONS) ((TREE CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomCreateClause", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("GUESS-LOOM-DEFINITION-ARITY", "(DEFUN (GUESS-LOOM-DEFINITION-ARITY INTEGER) ((ARITY INTEGER) (DEFINITION OBJECT) (CONSTRAINTS CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "guessLoomDefinitionArity", new java.lang.Class [] {java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("CONJOIN-SENTENCES", "(DEFUN (CONJOIN-SENTENCES OBJECT) ((SENTENCES CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "conjoinSentences", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-PARTITIONS", "(DEFUN (TRANSLATE-LOOM-PARTITIONS CONS) ((PARTITIONS OBJECT) (EXHAUSTIVE? BOOLEAN) (PARENTCONCEPT SYMBOL)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomPartitions", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE, Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-CHARACTERISTICS", "(DEFUN (TRANSLATE-LOOM-CHARACTERISTICS CONS) ((CHARACTERISTICS OBJECT) (NAME SYMBOL)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomCharacteristics", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-ANNOTATIONS", "(DEFUN (TRANSLATE-LOOM-ANNOTATIONS CONS) ((ANNOTATIONS OBJECT) (NAME SYMBOL)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomAnnotations", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-DEFAULTS", "(DEFUN (TRANSLATE-LOOM-DEFAULTS CONS) ((DEFAULT-TREE OBJECT) (VARIABLES CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomDefaults", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("SIMPLIFY-TOP-LEVEL-LOOM-KEYWORDS", "(DEFUN (SIMPLIFY-TOP-LEVEL-LOOM-KEYWORDS KEYWORD) ((KEYWORD KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "simplifyTopLevelLoomKeywords", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-DEFINITION", "(DEFUN (TRANSLATE-LOOM-DEFINITION CONS) ((TREE CONS)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomDefinition", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("TRANSLATE-LOOM-CONTEXT-CHANGE", "(DEFUN (TRANSLATE-LOOM-CONTEXT-CHANGE CONS) ((TREE CONS) (NEEDSQUOTE? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLoomContextChange", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("STARTUP-LOOM-TO-KIF", "(DEFUN STARTUP-LOOM-TO-KIF () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupLoomToKif", "startupLoomToKif", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_LOOM_TO_KIF);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupLoomToKif"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
