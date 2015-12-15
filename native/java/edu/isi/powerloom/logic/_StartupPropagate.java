//  -*- Mode: Java -*-
//
// _StartupPropagate.java

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

public class _StartupPropagate {
  static void helpStartupPropagate1() {
    {
      Logic.SYM_LOGIC_DEFERRED_DEFAULT_PROPOSITIONS_INTERNAL = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFERRED-DEFAULT-PROPOSITIONS-INTERNAL", null, 0)));
      Logic.SYM_LOGIC_EVALUATION_STATE_TABLE = ((Symbol)(Stella.internRigidSymbolWrtModule("EVALUATION-STATE-TABLE", null, 0)));
      Logic.KWD_POSTED = ((Keyword)(Stella.internRigidSymbolWrtModule("POSTED", null, 2)));
      Logic.SYM_LOGIC_EVALUATION_QUEUE = ((Symbol)(Stella.internRigidSymbolWrtModule("EVALUATION-QUEUE", null, 0)));
      Logic.SGT_LOGIC_F_COLLECT_FORWARD_CHAINING_RULES_MEMO_TABLE_000 = ((Surrogate)(Stella.internRigidSymbolWrtModule("F-COLLECT-FORWARD-CHAINING-RULES-MEMO-TABLE-000", null, 1)));
      Logic.SYM_LOGIC_FORWARD_CHAINING_QUEUE = ((Symbol)(Stella.internRigidSymbolWrtModule("FORWARD-CHAINING-QUEUE", null, 0)));
      Logic.KWD_PROPAGATE = ((Keyword)(Stella.internRigidSymbolWrtModule("PROPAGATE", null, 2)));
      Logic.KWD_GOAL_TREE = ((Keyword)(Stella.internRigidSymbolWrtModule("GOAL-TREE", null, 2)));
      Logic.KWD_SINGLETONSp = ((Keyword)(Stella.internRigidSymbolWrtModule("SINGLETONS?", null, 2)));
      Logic.KWD_EVALUATED = ((Keyword)(Stella.internRigidSymbolWrtModule("EVALUATED", null, 2)));
      Logic.SYM_LOGIC_ELABORATED_IN_WORLDS = ((Symbol)(Stella.internRigidSymbolWrtModule("ELABORATED-IN-WORLDS", null, 0)));
      Logic.KWD_ELABORATE = ((Keyword)(Stella.internRigidSymbolWrtModule("ELABORATE", null, 2)));
      Logic.SGT_PL_KERNEL_KB_INEQUALITY = ((Surrogate)(Stella.internRigidSymbolWrtModule("INEQUALITY", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SGT_PL_KERNEL_KB_PHRASE = ((Surrogate)(Stella.internRigidSymbolWrtModule("PHRASE", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SYM_LOGIC_STARTUP_PROPAGATE = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-PROPAGATE", null, 0)));
    }
  }

  static void helpStartupPropagate2() {
    {
      Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT DEFERRED-DEFAULT-PROPOSITIONS-INTERNAL :TYPE (CONS OF PROPOSITION) :PUBLIC? TRUE :DOCUMENTATION \"List of propositions infered to be true or false by\ndefault before we enter default propagation mode.\" :DEFAULT NULL :ALLOCATION :DYNAMIC)");
      Stella.defineFunctionObject("DEFERRED-DEFAULT-PROPOSITIONS", "(DEFUN (DEFERRED-DEFAULT-PROPOSITIONS (CONS OF PROPOSITION)) ((SELF CONTEXT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "deferredDefaultPropositions", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context")}), null);
      Stella.defineFunctionObject("DEFERRED-DEFAULT-PROPOSITIONS-SETTER", "(DEFUN DEFERRED-DEFAULT-PROPOSITIONS-SETTER ((SELF CONTEXT) (NEWVALUE (CONS OF PROPOSITION))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "deferredDefaultPropositionsSetter", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT EVALUATION-QUEUE :TYPE (LIST OF PROPOSITION) :PUBLIC? TRUE :DOCUMENTATION \"List of propositions waiting for evaluation in \n*context*.\" :DEFAULT NULL :ALLOCATION :DYNAMIC)");
      Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT EVALUATION-STATE-TABLE :TYPE (HASH-TABLE OF PROPOSITION KEYWORD) :PUBLIC? TRUE :DOCUMENTATION \"Records which propositions have been evaluated at\nleast once in the world 'self'.\" :ALLOCATION :DYNAMIC)");
      Stella.defineFunctionObject("EVALUATION-STATE", "(DEFUN (EVALUATION-STATE KEYWORD) ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluationState", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EVALUATION-STATE-SETTER", "(DEFUN EVALUATION-STATE-SETTER ((PROPOSITION PROPOSITION) (STATE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluationStateSetter", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
      Stella.defineFunctionObject("POST-FOR-EVALUATION", "(DEFUN POST-FOR-EVALUATION ((SELF PROPOSITION)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "postForEvaluation", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT FORWARD-CHAINING-QUEUE :TYPE (LIST OF PROPOSITION) :PUBLIC? TRUE :DOCUMENTATION \"Queue of recently asserted or inferred propositions\nhaving applicable forward rules.  Rules are triggered for each queue entry.\" :DEFAULT NULL :ALLOCATION :DYNAMIC)");
      Stella.defineFunctionObject("HELP-COLLECT-FORWARD-RULES", "(DEFUN (HELP-COLLECT-FORWARD-RULES (CONS OF KEY-VALUE-LIST)) ((DESCRIPTION DESCRIPTION) (RULES KEY-VALUE-LIST) (INDICES KEY-VALUE-LIST) (TOUCHEDDEFAULT? BOOLEAN) (BEENTHERE LIST)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "helpCollectForwardRules", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.stella.KeyValueList"), Native.find_java_class("edu.isi.stella.KeyValueList"), java.lang.Boolean.TYPE, Native.find_java_class("edu.isi.stella.List")}), null);
      Stella.defineFunctionObject("COLLECT-FORWARD-CHAINING-RULES", "(DEFUN (COLLECT-FORWARD-CHAINING-RULES (KEY-VALUE-LIST OF PROPOSITION BOOLEAN-WRAPPER) (KEY-VALUE-LIST OF FORWARD-CHAINING-INDEX BOOLEAN-WRAPPER)) ((DESCRIPTION DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "collectForwardChainingRules", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("[Ljava.lang.Object;")}), null);
      Stella.defineFunctionObject("HAS-FORWARD-CHAINING-RULES?", "(DEFUN (HAS-FORWARD-CHAINING-RULES? BOOLEAN) ((DESCRIPTION DESCRIPTION) (PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "hasForwardChainingRulesP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("POST-TO-FORWARD-CHAINING-QUEUE", "(DEFUN POST-TO-FORWARD-CHAINING-QUEUE ((SELF PROPOSITION) (WORLD WORLD)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "postToForwardChainingQueue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.World")}), null);
      Stella.defineFunctionObject("APPLY-RULE-CONSEQUENT-TO-VECTOR", "(DEFUN APPLY-RULE-CONSEQUENT-TO-VECTOR ((CONSEQUENT DESCRIPTION) (ARGUMENTS ARGUMENTS-VECTOR) (RULE PROPOSITION) (TRIGGERDESCRIPTION DESCRIPTION) (TRIGGERPROPOSITION PROPOSITION) (TOUCHEDDEFAULT? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "applyRuleConsequentToVector", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("TRACE-FORWARD-RULE", "(DEFUN TRACE-FORWARD-RULE ((RULE PROPOSITION) (TRIGGER PROPOSITION) (CONSEQUENTS (CONS OF PROPOSITION))))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "traceForwardRule", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("APPLY-FORWARD-RULES-TO-VECTOR", "(DEFUN APPLY-FORWARD-RULES-TO-VECTOR ((TRIGGERDESCRIPTION DESCRIPTION) (ARGUMENTS ARGUMENTS-VECTOR) (TRIGGERPROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "applyForwardRulesToVector", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("APPLICABLE-FORWARD-RULE?", "(DEFUN (APPLICABLE-FORWARD-RULE? BOOLEAN) ((RULE PROPOSITION) (ARGUMENTS ARGUMENTS-VECTOR)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "applicableForwardRuleP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Vector")}), null);
      Stella.defineMethodObject("(DEFMETHOD REACT-TO-INFERENCE-UPDATE ((SELF SKOLEM)))", Native.find_java_method("edu.isi.powerloom.logic.Skolem", "reactToInferenceUpdate", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD REACT-TO-INFERENCE-UPDATE ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "reactToInferenceUpdate", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("REACT-TO-KB-UPDATE", "(DEFUN REACT-TO-KB-UPDATE ((CONTEXT CONTEXT) (OBJECT OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "reactToKbUpdate", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("INITIALIZE-CONSTRAINT-PROPAGATION-QUEUES", "(DEFUN INITIALIZE-CONSTRAINT-PROPAGATION-QUEUES ((WORLD WORLD)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "initializeConstraintPropagationQueues", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.World")}), null);
      Stella.defineFunctionObject("EXECUTE-CONSTRAINT-PROPAGATION-QUEUES", "(DEFUN EXECUTE-CONSTRAINT-PROPAGATION-QUEUES ())", Native.find_java_method("edu.isi.powerloom.logic.Logic", "executeConstraintPropagationQueues", new java.lang.Class [] {}), null);
      Stella.defineFunctionObject("EVALUATE-NEW-PROPOSITION", "(DEFUN EVALUATE-NEW-PROPOSITION ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluateNewProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EVALUATE-AND-PROPOSITION", "(DEFUN EVALUATE-AND-PROPOSITION ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluateAndProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EVALUATE-OR-PROPOSITION", "(DEFUN EVALUATE-OR-PROPOSITION ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluateOrProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EVALUATE-NOT-PROPOSITION", "(DEFUN EVALUATE-NOT-PROPOSITION ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluateNotProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EVALUATE-EQUIVALENT-PROPOSITION", "(DEFUN EVALUATE-EQUIVALENT-PROPOSITION ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluateEquivalentProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EQUATE-EQUIVALENT-FUNCTION-PROPOSITIONS", "(DEFUN EQUATE-EQUIVALENT-FUNCTION-PROPOSITIONS ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "equateEquivalentFunctionPropositions", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EVALUATE-FUNCTION-PROPOSITION", "(DEFUN EVALUATE-FUNCTION-PROPOSITION ((SELF PROPOSITION)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluateFunctionProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EVALUATE-PREDICATE-PROPOSITION", "(DEFUN EVALUATE-PREDICATE-PROPOSITION ((SELF PROPOSITION)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluatePredicateProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("EVALUATE-PROPOSITION", "(DEFUN EVALUATE-PROPOSITION ((SELF PROPOSITION)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "evaluateProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineMethodObject("(DEFMETHOD MARK-AS-INCOHERENT ((SELF LOGIC-OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "markAsIncoherent", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD MARK-AS-INCOHERENT ((SELF SKOLEM)))", Native.find_java_method("edu.isi.powerloom.logic.Skolem", "markAsIncoherent", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT LOGIC-OBJECT ELABORATED-IN-WORLDS :TYPE (LIST OF WORLD) :DOCUMENTATION \"List of worlds in which 'elaborate-instance' has\nbeen applied to 'self'.\" :ALLOCATION :DYNAMIC)");
      Stella.defineFunctionObject("RECURSIVELY-REACT-TO-INFERENCE-UPDATE", "(DEFUN RECURSIVELY-REACT-TO-INFERENCE-UPDATE ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "recursivelyReactToInferenceUpdate", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("ELABORATE-META-INSTANCE", "(DEFUN ELABORATE-META-INSTANCE ((SELF OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "elaborateMetaInstance", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("ELABORATE-INSTANCE", "(DEFUN ELABORATE-INSTANCE ((SELF OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "elaborateInstance", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("EVALUATE-REACHABLE-INEQUALITIES", "(DEFUN EVALUATE-REACHABLE-INEQUALITIES ((SELF LOGIC-OBJECT) (VISITEDLIST LIST)))", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "evaluateReachableInequalities", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject"), Native.find_java_class("edu.isi.stella.List")}), null);
      Stella.defineFunctionObject("ELABORATE-SURROGATES-IN-PROPOSITION", "(DEFUN ELABORATE-SURROGATES-IN-PROPOSITION ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "elaborateSurrogatesInProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
      Stella.defineFunctionObject("COLLECT-FUNCTION-PROPOSITION-FACTS", "(DEFUN COLLECT-FUNCTION-PROPOSITION-FACTS ((SELF PROPOSITION) (FACTS (LIST OF PROPOSITION)) (BEENTHERE (LIST OF PROPOSITION)) (INCLUDEUNKNOWN? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "collectFunctionPropositionFacts", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.List"), Native.find_java_class("edu.isi.stella.List"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("HELP-COLLECT-FACTS", "(DEFUN HELP-COLLECT-FACTS ((SELF OBJECT) (FACTS (LIST OF PROPOSITION)) (BEENTHERE (LIST OF PROPOSITION)) (INCLUDEUNKNOWN? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "helpCollectFacts", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.List"), Native.find_java_class("edu.isi.stella.List"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("ALL-FACTS-OF-INSTANCE", "(DEFUN (ALL-FACTS-OF-INSTANCE (LIST OF PROPOSITION)) ((SELF OBJECT) (INCLUDEUNKNOWNFACTS? BOOLEAN) (ELABORATE? BOOLEAN)) :DOCUMENTATION \"Return a list of all definite (TRUE or FALSE) propositions\nattached to `self'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "allFactsOfInstance", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE, java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("ALL-FACTS-OF", "(DEFUN (ALL-FACTS-OF (CONS OF PROPOSITION)) ((INSTANCEREF NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Return a cons list of all definite (TRUE or FALSE) propositions\nthat reference the instance `instanceRef'.  This includes propositions\nasserted to be true by default, but it does not include propositions\nthat are found to be TRUE only by running the query engine.  Facts\ninferred to be TRUE by the forward chainer will be included.\nHence, the returned list of facts may be longer in a context where the\nforward chainer has been run then in one where it has not (see\n`run-forward-rules').\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "allFactsOf", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("CALL-ALL-FACTS-OF", "(DEFUN (CALL-ALL-FACTS-OF (LIST OF PROPOSITION)) ((INSTANCEREF OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? TRUE :DOCUMENTATION \"Return a list of all definite (TRUE or FALSE) propositions\nthat reference the instance `instanceRef'.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "callAllFactsOf", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("RETRACT-FACTS-OF-INSTANCE", "(DEFUN RETRACT-FACTS-OF-INSTANCE ((SELF LOGIC-OBJECT)) :DOCUMENTATION \"Retract all definite (TRUE or FALSE) propositions attached to `self'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "retractFactsOfInstance", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject")}), null);
      Stella.defineFunctionObject("RETRACT-FACTS-OF", "(DEFUN RETRACT-FACTS-OF ((INSTANCEREF OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Retract all definite (TRUE or FALSE) propositions\nthat reference the instance `instanceRef'.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "retractFactsOf", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("EXPLODE-VARIABLIZED-STRING", "(DEFUN (EXPLODE-VARIABLIZED-STRING LIST) ((STRING STRING)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "explodeVariablizedString", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("FACT-TO-SENTENCE", "(DEFUN (FACT-TO-SENTENCE STRING) ((SELF PROPOSITION) (PERIOD? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "factToSentence", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("ALL-SENTENCES-OF", "(DEFUN (ALL-SENTENCES-OF (CONS OF STRING-WRAPPER)) ((INSTANCEREF OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? TRUE :DOCUMENTATION \"Return a list of sentences describing facts about 'instanceRef'.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "allSentencesOf", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("CALL-ALL-FACTS-OF-N", "(DEFUN (CALL-ALL-FACTS-OF-N (LIST OF PROPOSITION)) ((N INTEGER) (SEEDREFS CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "callAllFactsOfN", new java.lang.Class [] {java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("FILTERED-ALL-FACTS-OF-N", "(DEFUN (FILTERED-ALL-FACTS-OF-N (LIST OF PROPOSITION)) ((N INTEGER) (SEEDREFS CONS) (FILTER FUNCTION-CODE)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "filteredAllFactsOfN", new java.lang.Class [] {java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("java.lang.reflect.Method")}), null);
      Stella.defineFunctionObject("ALL-FACTS-OF-N", "(DEFUN (ALL-FACTS-OF-N (CONS OF PROPOSITION)) ((N INTEGER) |&REST| (INSTANCEREFS NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"This is a generalization of `all-facts-of' (which see).  With `n' = 0\nand only one instance this command behaves just like `all-facts-of'.\nOtherwise, returns a cons list of all definite (TRUE or FALSE) propositions\nthat reference any of the instances listed in `instanceRefs', plus if `n' >= 1\nall propositions that reference any instances that are arguments of\npropositions collected in the previous step, plus if `n' >= 2... and so on.\nThat is, if we only consider binary propositions, this can be viewed as\ngrowing a graph with instances as its nodes and predicates as its arcs\nstarting from the set of seed `instanceRefs' to depth `n'-1.\nCaution: with a fully connected KB and large enough `n' this could return\nthe whole knowledge base.\n\nThe returned propositions include those asserted to be true or false by\ndefault, but it does not include propositions that are found to be\ntrue only by running the query engine.  Facts inferred to be true by\nthe forward chainer will be included.  Hence, the returned list of\nfacts may be longer in a context where the forward chainer has been\nrun then in one where it has not (see `run-forward-rules').\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "allFactsOfN", new java.lang.Class [] {java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.Cons")}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "allFactsOfNEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
      Stella.defineFunctionObject("STARTUP-PROPAGATE", "(DEFUN STARTUP-PROPAGATE () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupPropagate", "startupPropagate", new java.lang.Class [] {}), null);
      { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_PROPAGATE);

        KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupPropagate"), Stella.NULL_STRING_WRAPPER);
      }
    }
  }

  public static void startupPropagate() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupPropagate.helpStartupPropagate1();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$FILLINGCONSTRAINTPROPAGATIONQUEUESp$.setDefaultValue(new Boolean(false));
          Logic.$DEFERINGDEFAULTFORWARDINFERENCESp$.setDefaultValue(new Boolean(false));
          Logic.$CURRENTLYEXECUTINGFORWARDCHAININGQUEUE$.setDefaultValue(null);
          Logic.$COLLECTFORWARDPROPOSITIONS$.setDefaultValue(null);
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          _StartupPropagate.helpStartupPropagate2();
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *FILLINGCONSTRAINTPROPAGATIONQUEUES?* BOOLEAN FALSE :DOCUMENTATION \"True if we are inside of 'react-to-kb-update'.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DEFERINGDEFAULTFORWARDINFERENCES?* BOOLEAN FALSE :DOCUMENTATION \"True if we are propagating strict inferences, and\nposting derived default propositions to temporary queues.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CURRENTLYEXECUTINGFORWARDCHAININGQUEUE* (LIST OF PROPOSITION) NULL :DOCUMENTATION \"Points to an active queue of propositions that will trigger\nforward inference.  New queue entries are posted to a separate queue\nattached to *context*.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *COLLECTFORWARDPROPOSITIONS* (CONS OF PROPOSITION) NULL :DOCUMENTATION \"Collect goes-true propositions produced by forward\nchaining.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *JUST-IN-TIME-FORWARD-INFERENCE?* BOOLEAN TRUE :DOCUMENTATION \"If TRUE, ensures that forward propagation has\nbeen applied to each instance 'touched' during a query.\")");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
