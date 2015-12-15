//  -*- Mode: Java -*-
//
// _StartupJustifications.java

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

public class _StartupJustifications {
  static void helpStartupJustifications1() {
    {
      Logic.SGT_LOGIC_JUSTIFICATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("JUSTIFICATION", null, 1)));
      Logic.SYM_LOGIC_INFERENCE_RULE = ((Symbol)(Stella.internRigidSymbolWrtModule("INFERENCE-RULE", null, 0)));
      Logic.SYM_LOGIC_ANTECEDENTS = ((Symbol)(Stella.internRigidSymbolWrtModule("ANTECEDENTS", null, 0)));
      Logic.SYM_LOGIC_PATTERN_JUSTIFICATION = ((Symbol)(Stella.internRigidSymbolWrtModule("PATTERN-JUSTIFICATION", null, 0)));
      Logic.SYM_LOGIC_SUBSTITUTION = ((Symbol)(Stella.internRigidSymbolWrtModule("SUBSTITUTION", null, 0)));
      Logic.KWD_PRIMITIVE_STRATEGY = ((Keyword)(Stella.internRigidSymbolWrtModule("PRIMITIVE-STRATEGY", null, 2)));
      Logic.SGT_LOGIC_PRIMITIVE_STRATEGY = ((Surrogate)(Stella.internRigidSymbolWrtModule("PRIMITIVE-STRATEGY", null, 1)));
      Logic.SYM_LOGIC_STRATEGY = ((Symbol)(Stella.internRigidSymbolWrtModule("STRATEGY", null, 0)));
      Logic.KWD_COMPUTED_PREDICATE = ((Keyword)(Stella.internRigidSymbolWrtModule("COMPUTED-PREDICATE", null, 2)));
      Logic.SGT_STELLA_KEY_VALUE_LIST = ((Surrogate)(Stella.internRigidSymbolWrtModule("KEY-VALUE-LIST", Stella.getStellaModule("/STELLA", true), 1)));
      Logic.KWD_MODUS_TOLLENS = ((Keyword)(Stella.internRigidSymbolWrtModule("MODUS-TOLLENS", null, 2)));
      Logic.KWD_MODUS_PONENS = ((Keyword)(Stella.internRigidSymbolWrtModule("MODUS-PONENS", null, 2)));
      Logic.KWD_AMPLIFICATION = ((Keyword)(Stella.internRigidSymbolWrtModule("AMPLIFICATION", null, 2)));
      Logic.KWD_AND_INTRODUCTION = ((Keyword)(Stella.internRigidSymbolWrtModule("AND-INTRODUCTION", null, 2)));
      Logic.KWD_PARTIAL = ((Keyword)(Stella.internRigidSymbolWrtModule("PARTIAL", null, 2)));
      Logic.KWD_REVERSE = ((Keyword)(Stella.internRigidSymbolWrtModule("REVERSE", null, 2)));
      Logic.KWD_OR_INTRODUCTION = ((Keyword)(Stella.internRigidSymbolWrtModule("OR-INTRODUCTION", null, 2)));
      Logic.KWD_DISPROOF = ((Keyword)(Stella.internRigidSymbolWrtModule("DISPROOF", null, 2)));
      Logic.KWD_FAIL_INTRODUCTION = ((Keyword)(Stella.internRigidSymbolWrtModule("FAIL-INTRODUCTION", null, 2)));
      Logic.KWD_CLOSED_NOT_INTRODUCTION = ((Keyword)(Stella.internRigidSymbolWrtModule("CLOSED-NOT-INTRODUCTION", null, 2)));
      Logic.KWD_EXISTENTIAL_INTRODUCTION = ((Keyword)(Stella.internRigidSymbolWrtModule("EXISTENTIAL-INTRODUCTION", null, 2)));
      Logic.KWD_RAW = ((Keyword)(Stella.internRigidSymbolWrtModule("RAW", null, 2)));
      Logic.KWD_INFERENCE_RULE = ((Keyword)(Stella.internRigidSymbolWrtModule("INFERENCE-RULE", null, 2)));
      Logic.KWD_TRUTH_VALUE = ((Keyword)(Stella.internRigidSymbolWrtModule("TRUTH-VALUE", null, 2)));
      Logic.KWD_POSITIVE_SCORE = ((Keyword)(Stella.internRigidSymbolWrtModule("POSITIVE-SCORE", null, 2)));
      Logic.KWD_SUBSTITUTION = ((Keyword)(Stella.internRigidSymbolWrtModule("SUBSTITUTION", null, 2)));
      Logic.SGT_LOGIC_FORWARD_GOAL_RECORD = ((Surrogate)(Stella.internRigidSymbolWrtModule("FORWARD-GOAL-RECORD", null, 1)));
      Logic.SYM_LOGIC_FORWARD_RULE = ((Symbol)(Stella.internRigidSymbolWrtModule("FORWARD-RULE", null, 0)));
      Logic.SYM_LOGIC_FORWARD_CHAINING_GOALS = ((Symbol)(Stella.internRigidSymbolWrtModule("FORWARD-CHAINING-GOALS", null, 0)));
      Logic.SGT_LOGIC_FORWARD_JUSTIFICATION = ((Surrogate)(Stella.internRigidSymbolWrtModule("FORWARD-JUSTIFICATION", null, 1)));
      Logic.SYM_LOGIC_FORWARD_JUSTIFICATIONS = ((Symbol)(Stella.internRigidSymbolWrtModule("FORWARD-JUSTIFICATIONS", null, 0)));
      Logic.SYM_LOGIC_STARTUP_JUSTIFICATIONS = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-JUSTIFICATIONS", null, 0)));
    }
  }

  public static void startupJustifications() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupJustifications.helpStartupJustifications1();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$RECORD_JUSTIFICATIONSp$.setDefaultValue(new Boolean(false));
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("JUSTIFICATION", "(DEFCLASS JUSTIFICATION (STANDARD-OBJECT) :SLOTS ((INFERENCE-RULE :TYPE KEYWORD :DOCUMENTATION \"Keyword describing the inference rule used to conclude the\nproposition of this justification.\") (PROPOSITION :TYPE PROPOSITION :DOCUMENTATION \"The proposition supported by this justification.\") (ANTECEDENTS :TYPE (CONS OF JUSTIFICATION) :INITIALLY NIL :DOCUMENTATION \"Antecedents justifications of this justification.\") (PATTERN-JUSTIFICATION :TYPE JUSTIFICATION :DOCUMENTATION \"Backpointer to the closest parent :PATTERN justification containing\nthe variable substitutions from the associated pattern control frame.  If this\nis a :PATTERN justification, the slot points to the parent pattern.\") (SUBSTITUTION :TYPE (ENTITY-MAPPING OF PATTERN-VARIABLE OBJECT) :DOCUMENTATION \"List of variable bindings recorded for :PATTERN justifications.\") (REVERSE-POLARITY? :TYPE BOOLEAN :DOCUMENTATION \"True if proposition was derived in reverse polarity.\") (TRUTH-VALUE :TYPE TRUTH-VALUE :DOCUMENTATION \"Truth value of the derived proposition.\") (POSITIVE-SCORE :TYPE PARTIAL-MATCH-SCORE :DOCUMENTATION \"Positive partial match score of the derived proposition.\") (NEGATIVE-SCORE :TYPE PARTIAL-MATCH-SCORE :DOCUMENTATION \"Negative partial match score of the derived proposition.\")) :METHODS ((INFERENCE-STRATEGY ((SELF JUSTIFICATION)) :TYPE KEYWORD (RETURN NULL))))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.Justification", "newJustification", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.Justification", "accessJustificationSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("PRIMITIVE-STRATEGY", "(DEFCLASS PRIMITIVE-STRATEGY (JUSTIFICATION) :SLOTS ((INFERENCE-RULE :TYPE KEYWORD :INITIALLY :PRIMITIVE-STRATEGY) (STRATEGY :TYPE KEYWORD)) :METHODS ((INFERENCE-STRATEGY ((SELF PRIMITIVE-STRATEGY)) :TYPE KEYWORD (RETURN (STRATEGY SELF)))))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.PrimitiveStrategy", "newPrimitiveStrategy", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.PrimitiveStrategy", "accessPrimitiveStrategySlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.PrimitiveStrategy"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("FORWARD-GOAL-RECORD", "(DEFCLASS FORWARD-GOAL-RECORD (STANDARD-OBJECT) :SLOTS ((FORWARD-GOAL :TYPE PROPOSITION) (FORWARD-RULE :TYPE PROPOSITION)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.ForwardGoalRecord", "newForwardGoalRecord", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.ForwardGoalRecord", "accessForwardGoalRecordSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ForwardGoalRecord"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("FORWARD-JUSTIFICATION", "(DEFCLASS FORWARD-JUSTIFICATION (STANDARD-OBJECT) :DOCUMENTATION \"Connects a proposition to other propositions\nthat collectively implied its truth.\" :SLOTS ((CONSEQUENT :TYPE PROPOSITION) (FORWARD-RULE :TYPE PROPOSITION) (ANTECEDENTS :TYPE (CONS OF PROPOSITION))))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.ForwardJustification", "newForwardJustification", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.ForwardJustification", "accessForwardJustificationSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ForwardJustification"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("JUSTIFICATION-ARGUMENT-BOUND-TO", "(DEFUN (JUSTIFICATION-ARGUMENT-BOUND-TO OBJECT) ((ARGUMENT OBJECT) (JUSTIFICATION JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "justificationArgumentBoundTo", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineFunctionObject("YIELD-JUSTIFICATION-SUBSTITUTION", "(DEFUN (YIELD-JUSTIFICATION-SUBSTITUTION ENTITY-MAPPING) ((JUSTIFICATION JUSTIFICATION) (SUBSTITUTION ENTITY-MAPPING) (ARGUMENT PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "yieldJustificationSubstitution", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.stella.KeyValueList"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("JUSTIFICATION-EQL?", "(DEFUN (JUSTIFICATION-EQL? BOOLEAN) ((JUST1 JUSTIFICATION) (JUST2 JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "justificationEqlP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineFunctionObject("JUSTIFICATION-PROPOSITIONS-EQL?", "(DEFUN (JUSTIFICATION-PROPOSITIONS-EQL? BOOLEAN) ((PROPOSITION1 PROPOSITION) (JUST1 JUSTIFICATION) (PROPOSITION2 PROPOSITION) (JUST2 JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "justificationPropositionsEqlP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineMethodObject("(DEFMETHOD (COPY (LIKE SELF)) ((SELF JUSTIFICATION)) :DOCUMENTATION \"Return a copy of the proof starting at `self'.  Allocates\nall new justification objects, but structure-shares other information such\nas propositions and substitutions.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Justification", "copy", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("RECORD-JUSTIFICATIONS?", "(DEFUN (RECORD-JUSTIFICATIONS? BOOLEAN) () :DOCUMENTATION \"Return TRUE if every query records justifications to enable\nthe explanation of concluded results.\" :GLOBALLY-INLINE? TRUE (RETURN *RECORD-JUSTIFICATIONS?*))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "recordJustificationsP", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("RECORD-GOAL-JUSTIFICATION", "(DEFUN RECORD-GOAL-JUSTIFICATION ((GOAL CONTROL-FRAME) (JUSTIFICATION JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordGoalJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineFunctionObject("RECORD-PRIMITIVE-JUSTIFICATION", "(DEFUN RECORD-PRIMITIVE-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordPrimitiveJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("RECORD-PATTERN-JUSTIFICATION", "(DEFUN RECORD-PATTERN-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordPatternJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("BACKLINK-TO-PATTERN-JUSTIFICATION", "(DEFUN BACKLINK-TO-PATTERN-JUSTIFICATION ((JUSTIFICATION JUSTIFICATION) (PATTERN JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "backlinkToPatternJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineFunctionObject("RECORD-MODUS-PONENS-JUSTIFICATION", "(DEFUN RECORD-MODUS-PONENS-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordModusPonensJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("RECORD-AND-INTRODUCTION-JUSTIFICATION", "(DEFUN RECORD-AND-INTRODUCTION-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordAndIntroductionJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("RECORD-OR-INTRODUCTION-JUSTIFICATION", "(DEFUN RECORD-OR-INTRODUCTION-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordOrIntroductionJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("RECORD-DISPROOF-JUSTIFICATION", "(DEFUN RECORD-DISPROOF-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordDisproofJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("RECORD-FAIL-JUSTIFICATION", "(DEFUN RECORD-FAIL-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordFailJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("RECORD-CLOSED-NOT-JUSTIFICATION", "(DEFUN RECORD-CLOSED-NOT-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordClosedNotJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("RECORD-EXISTENTIAL-INTRODUCTION-JUSTIFICATION", "(DEFUN RECORD-EXISTENTIAL-INTRODUCTION-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "recordExistentialIntroductionJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("FAILED-GOAL-JUSTIFICATION?", "(DEFUN (FAILED-GOAL-JUSTIFICATION? BOOLEAN) ((SELF JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "failedGoalJustificationP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineFunctionObject("CUTOFF-GOAL-JUSTIFICATION?", "(DEFUN (CUTOFF-GOAL-JUSTIFICATION? BOOLEAN) ((SELF JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "cutoffGoalJustificationP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineMethodObject("(DEFMETHOD (CONSIFY CONS) ((SELF JUSTIFICATION)) :DOCUMENTATION \"Return a CONS tree representation of the proof `self'.\nEach proof step is represented as a CONS tree of the form\n  (<proposition> (<key> <value>...) <antecedent>...)\nwhere each <antecedent> is a CONS tree representing a subproof.  The\nconsification follows the original proof structure literally, i.e., no\nuninteresting nodes such as patterns or AND-introductions are suppressed.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Justification", "consify", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("CONSIFY-JUSTIFICATION", "(DEFUN (CONSIFY-JUSTIFICATION CONS) ((SELF JUSTIFICATION) (STYLE KEYWORD)) :DOCUMENTATION \"Return a CONS tree representation of the proof `self'.\nEach proof step is represented as a CONS tree of the form\n  (<proposition> (<key> <value>...) <antecedent>...)\nwhere each <antecedent> is a CONS tree representing a subproof.\n`style' indicates what nodes in the proof tree should be suppressed.\n:RAW preserves the original structure literally, :VERBOSE keeps AND-\nintroductions but suppresses all auxiliary (non-logical) nodes such as\npattern nodes, and :BRIEF additionally suppresses AND-introduction nodes.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Justification", "consifyJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("GET-QUERY-JUSTIFICATIONS", "(DEFUN (GET-QUERY-JUSTIFICATIONS (LIST OF JUSTIFICATION)) ((QUERY QUERY-ITERATOR) (SOLUTIONINDEX INTEGER) (MAXJUSTIFICATIONS INTEGER) (CREATE? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.QueryIterator", "getQueryJustifications", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.QueryIterator"), java.lang.Integer.TYPE, java.lang.Integer.TYPE, java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("DERIVE-QUERY-JUSTIFICATIONS", "(DEFUN (DERIVE-QUERY-JUSTIFICATIONS (LIST OF JUSTIFICATION)) ((QUERY QUERY-ITERATOR) (OPTIONS OBJECT) (SOLUTIONINDEX INTEGER) (MAXJUSTIFICATIONS INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.QueryIterator", "deriveQueryJustifications", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.QueryIterator"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Integer.TYPE, java.lang.Integer.TYPE}), null);
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT PROPOSITION FORWARD-CHAINING-GOALS :TYPE (LIST OF FORWARD-GOAL-RECORD) :ALLOCATION :DYNAMIC)");
          Stella.defineMethodObject("(DEFMETHOD (DELETED? BOOLEAN) ((SELF FORWARD-GOAL-RECORD)))", Native.find_java_method("edu.isi.powerloom.logic.ForwardGoalRecord", "deletedP", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (DELETED?-SETTER BOOLEAN) ((SELF FORWARD-GOAL-RECORD) (VALUE BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.ForwardGoalRecord", "deletedPSetter", new java.lang.Class [] {java.lang.Boolean.TYPE}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("RECORD-FORWARD-GOAL", "(DEFUN RECORD-FORWARD-GOAL ((FORWARDRULE PROPOSITION) (ARGUMENTS ARGUMENTS-VECTOR) (CONSEQUENTPROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "recordForwardGoal", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("PREDICATION?", "(DEFUN (PREDICATION? BOOLEAN) ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "predicationP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("ASSERTED-AS-TRUE?", "(DEFUN (ASSERTED-AS-TRUE? BOOLEAN) ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "assertedAsTrueP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("ELABORATION-RULE?", "(DEFUN (ELABORATION-RULE? BOOLEAN) ((CONSEQUENTPROPOSITION PROPOSITION) (FORWARDRULE PROPOSITION) (ARGUMENTS ARGUMENTS-VECTOR)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "elaborationRuleP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Vector")}), null);
          Stella.defineFunctionObject("GET-FORWARD-GOALS", "(DEFUN (GET-FORWARD-GOALS (LIST OF FORWARD-GOAL-RECORD)) ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "getForwardGoals", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT PROPOSITION FORWARD-JUSTIFICATIONS :TYPE (LIST OF FORWARD-JUSTIFICATION) :ALLOCATION :DYNAMIC)");
          Stella.defineFunctionObject("CREATE-FORWARD-JUSTIFICATION", "(DEFUN (CREATE-FORWARD-JUSTIFICATION FORWARD-JUSTIFICATION) ((CONSEQUENTPROPOSITION PROPOSITION) (FORWARDRULE PROPOSITION) (ANTECEDENTS (CONS OF PROPOSITION))))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "createForwardJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("RECORD-FORWARD-JUSTIFICATION", "(DEFUN RECORD-FORWARD-JUSTIFICATION ((CONSEQUENTPROPOSITION PROPOSITION) (FORWARDRULE PROPOSITION) (ANTECEDENTS (CONS OF PROPOSITION))))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "recordForwardJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("STARTUP-JUSTIFICATIONS", "(DEFUN STARTUP-JUSTIFICATIONS () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupJustifications", "startupJustifications", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_JUSTIFICATIONS);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupJustifications"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *RECORD-JUSTIFICATIONS?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE every query records justifications to enable\nthe explanation of concluded results.\")");
          Logic.defineExplanationPhrase(Logic.KWD_SCAN_COLLECTION, Logic.KWD_TECHNICAL, "by explicit assertion", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_SCAN_PROPOSITIONS, Logic.KWD_TECHNICAL, "by explicit assertion", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_LOOKUP_ASSERTIONS, Logic.KWD_TECHNICAL, "by explicit assertion", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_SCAN_COLLECTION, Logic.KWD_LAY, "because the system was told this fact", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_SCAN_PROPOSITIONS, Logic.KWD_LAY, "because the system was told this fact", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_LOOKUP_ASSERTIONS, Logic.KWD_LAY, "because the system was told this fact", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_SPECIALIST, Logic.KWD_TECHNICAL, "because it was proven by an inference specialist", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_SPECIALIST, Logic.KWD_LAY, "because of a specialized reasoning procedure", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_COMPUTED_PREDICATE, Logic.KWD_TECHNICAL, "because of a computation", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_COMPUTED_PREDICATE, Logic.KWD_LAY, "because of a computation", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_GOAL_COMPLEMENT, Logic.KWD_TECHNICAL, "because its argument was proven false", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_GOAL_COMPLEMENT, Logic.KWD_LAY, "because its argument is false", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_EQUIVALENCE, Logic.KWD_TECHNICAL, "from equivalence", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_EQUIVALENCE, Logic.KWD_LAY, "because its arguments are equivalent", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_SUBSUMPTION_TEST, Logic.KWD_TECHNICAL, "because of a successful subsumption test", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_SUBSUMPTION_TEST, Logic.KWD_LAY, "because of a successful subsumption test", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_FAILURE, Logic.KWD_TECHNICAL, "could not be proven", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_FAILURE, Logic.KWD_LAY, "could not be proven", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_MODUS_PONENS, Logic.KWD_TECHNICAL, "by Modus Ponens", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_MODUS_PONENS, Logic.KWD_LAY, "because an if-then rule applies", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_MODUS_TOLLENS, Logic.KWD_TECHNICAL, "by Modus Tollens", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_MODUS_TOLLENS, Logic.KWD_TECHNICAL, "(p => q, ~q |= ~p)", Stella_Object.cons(Logic.KWD_AMPLIFICATION, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_MODUS_TOLLENS, Logic.KWD_LAY, "because an if-then rule was used backwards", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_MODUS_TOLLENS, Logic.KWD_LAY, "(if P then Q with Q false allows us to conclude P)", Stella_Object.cons(Logic.KWD_AMPLIFICATION, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_AND_INTRODUCTION, Logic.KWD_TECHNICAL, "by And-Introduction", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_AND_INTRODUCTION, Logic.KWD_LAY, "because all parts of an AND expression were true", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_AND_INTRODUCTION, Logic.KWD_LAY, "because parts of an AND expression were true", Stella_Object.cons(Logic.KWD_PARTIAL, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_AND_INTRODUCTION, Logic.KWD_TECHNICAL, "by Not-Or-Introduction", Stella_Object.cons(Logic.KWD_REVERSE, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_AND_INTRODUCTION, Logic.KWD_LAY, "because all parts of an OR expression were false", Stella_Object.cons(Logic.KWD_REVERSE, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_AND_INTRODUCTION, Logic.KWD_TECHNICAL, "(~p, ~q |= ~(p v q))", Stella_Object.cons(Logic.KWD_REVERSE, Stella_Object.cons(Logic.KWD_AMPLIFICATION, Stella.NIL)));
          Logic.defineExplanationPhrase(Logic.KWD_AND_INTRODUCTION, Logic.KWD_LAY, "(therefore the OR is also false)", Stella_Object.cons(Logic.KWD_REVERSE, Stella_Object.cons(Logic.KWD_AMPLIFICATION, Stella.NIL)));
          Logic.defineExplanationPhrase(Logic.KWD_OR_INTRODUCTION, Logic.KWD_TECHNICAL, "by Or-Introduction", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_OR_INTRODUCTION, Logic.KWD_LAY, "because at least one part of an OR expression was true", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_OR_INTRODUCTION, Logic.KWD_TECHNICAL, "by Not-And-Introduction", Stella_Object.cons(Logic.KWD_REVERSE, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_OR_INTRODUCTION, Logic.KWD_LAY, "because at least one part of an AND expression was false", Stella_Object.cons(Logic.KWD_REVERSE, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_OR_INTRODUCTION, Logic.KWD_TECHNICAL, "(~p |= ~(p & q))", Stella_Object.cons(Logic.KWD_REVERSE, Stella_Object.cons(Logic.KWD_AMPLIFICATION, Stella.NIL)));
          Logic.defineExplanationPhrase(Logic.KWD_OR_INTRODUCTION, Logic.KWD_LAY, "(therefore the AND is also false)", Stella_Object.cons(Logic.KWD_REVERSE, Stella_Object.cons(Logic.KWD_AMPLIFICATION, Stella.NIL)));
          Logic.defineExplanationPhrase(Logic.KWD_DISPROOF, Logic.KWD_TECHNICAL, "by disproof", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_DISPROOF, Logic.KWD_LAY, "by proving the negation", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_DISPROOF, Logic.KWD_TECHNICAL, "by Double-Negation-Introduction", Stella_Object.cons(Logic.KWD_REVERSE, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_DISPROOF, Logic.KWD_LAY, "by negating a negation", Stella_Object.cons(Logic.KWD_REVERSE, Stella.NIL));
          Logic.defineExplanationPhrase(Logic.KWD_CLOSED_NOT_INTRODUCTION, Logic.KWD_TECHNICAL, "because the argument proposition was not derivable and it uses closed-world semantics", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_CLOSED_NOT_INTRODUCTION, Logic.KWD_LAY, "because the argument proposition could not be proven and it is a closed-world proposition", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_FAIL_INTRODUCTION, Logic.KWD_TECHNICAL, "because the argument proposition was not derivable", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_FAIL_INTRODUCTION, Logic.KWD_LAY, "because the argument proposition could not be proven", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_EXISTENTIAL_INTRODUCTION, Logic.KWD_TECHNICAL, "by Existential Introduction", Stella.NIL);
          Logic.defineExplanationPhrase(Logic.KWD_EXISTENTIAL_INTRODUCTION, Logic.KWD_LAY, "because it was true for at least one case", Stella.NIL);
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
