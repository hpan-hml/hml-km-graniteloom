//  -*- Mode: C++ -*-

// query.cc

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

#include "logic/logic-system.hh"

namespace logic {
  using namespace stella;

InferenceLevel* newInferenceLevel() {
  { InferenceLevel* self = NULL;

    self = new InferenceLevel();
    self->keyword = NULL;
    return (self);
  }
}

Surrogate* InferenceLevel::primaryType() {
  { InferenceLevel* self = this;

    return (SGT_QUERY_LOGIC_INFERENCE_LEVEL);
  }
}

Object* accessInferenceLevelSlotValue(InferenceLevel* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_STELLA_KEYWORD) {
    if (setvalueP) {
      self->keyword = ((Keyword*)(value));
    }
    else {
      value = self->keyword;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

NormalInferenceLevel* newNormalInferenceLevel() {
  { NormalInferenceLevel* self = NULL;

    self = new NormalInferenceLevel();
    self->keyword = NULL;
    return (self);
  }
}

Surrogate* NormalInferenceLevel::primaryType() {
  { NormalInferenceLevel* self = this;

    return (SGT_QUERY_LOGIC_NORMAL_INFERENCE_LEVEL);
  }
}

BacktrackingInferenceLevel* newBacktrackingInferenceLevel() {
  { BacktrackingInferenceLevel* self = NULL;

    self = new BacktrackingInferenceLevel();
    self->keyword = NULL;
    return (self);
  }
}

Surrogate* BacktrackingInferenceLevel::primaryType() {
  { BacktrackingInferenceLevel* self = this;

    return (SGT_QUERY_LOGIC_BACKTRACKING_INFERENCE_LEVEL);
  }
}

SubsumptionInferenceLevel* newSubsumptionInferenceLevel() {
  { SubsumptionInferenceLevel* self = NULL;

    self = new SubsumptionInferenceLevel();
    self->keyword = NULL;
    return (self);
  }
}

Surrogate* SubsumptionInferenceLevel::primaryType() {
  { SubsumptionInferenceLevel* self = this;

    return (SGT_QUERY_LOGIC_SUBSUMPTION_INFERENCE_LEVEL);
  }
}

ShallowInferenceLevel* newShallowInferenceLevel() {
  { ShallowInferenceLevel* self = NULL;

    self = new ShallowInferenceLevel();
    self->keyword = NULL;
    return (self);
  }
}

Surrogate* ShallowInferenceLevel::primaryType() {
  { ShallowInferenceLevel* self = this;

    return (SGT_QUERY_LOGIC_SHALLOW_INFERENCE_LEVEL);
  }
}

AssertionInferenceLevel* newAssertionInferenceLevel() {
  { AssertionInferenceLevel* self = NULL;

    self = new AssertionInferenceLevel();
    self->keyword = NULL;
    return (self);
  }
}

Surrogate* AssertionInferenceLevel::primaryType() {
  { AssertionInferenceLevel* self = this;

    return (SGT_QUERY_LOGIC_ASSERTION_INFERENCE_LEVEL);
  }
}

RefutationInferenceLevel* newRefutationInferenceLevel() {
  { RefutationInferenceLevel* self = NULL;

    self = new RefutationInferenceLevel();
    self->keyword = NULL;
    return (self);
  }
}

Surrogate* RefutationInferenceLevel::primaryType() {
  { RefutationInferenceLevel* self = this;

    return (SGT_QUERY_LOGIC_REFUTATION_INFERENCE_LEVEL);
  }
}

NormalInferenceLevel* NORMAL_INFERENCE = NULL;

BacktrackingInferenceLevel* BACKTRACKING_INFERENCE = NULL;

SubsumptionInferenceLevel* SUBSUMPTION_INFERENCE = NULL;

ShallowInferenceLevel* SHALLOW_INFERENCE = NULL;

AssertionInferenceLevel* ASSERTION_INFERENCE = NULL;

RefutationInferenceLevel* REFUTATION_INFERENCE = NULL;

// Specifies the level/depth of inference applied
// during a query.  Possible values are:
//   :ASSERTION -- database lookup with no inheritance;
//   :SHALLOW -- includes database lookup, computed predicates and specialists;
//   :SUBSUMPTION -- shallow plus cached subsumption links and equality reasoning;
//   :BACKTRACKING -- all of the above plus backtracking over rules;
//   :NORMAL -- all of the above plus universal introduction;
//   :REFUTATION -- all of the above plus disjunctive implication introduction and refutation.
DEFINE_STELLA_SPECIAL(oINFERENCELEVELo, NormalInferenceLevel* , NULL);

NormalInferenceLevel* currentInferenceLevel() {
  // Return the current inference level that is active in the
  // current query, the current module, or, otherwise, globally.
  { InferenceLevel* level = (((boolean)(oQUERYITERATORo.get())) ? oQUERYITERATORo.get()->inferenceLevel : ((InferenceLevel*)(dynamicSlotValue(oMODULEo.get()->dynamicSlots, SYM_QUERY_LOGIC_INFERENCE_LEVEL, NULL))));

    if (((boolean)(level))) {
      return (((NormalInferenceLevel*)(level)));
    }
    else {
      return (oINFERENCELEVELo.get());
    }
  }
}

InferenceLevel* getInferenceLevel(Keyword* levelkeyword) {
  if (levelkeyword == KWD_QUERY_NORMAL) {
    return (NORMAL_INFERENCE);
  }
  else if (levelkeyword == KWD_QUERY_SHALLOW) {
    return (SHALLOW_INFERENCE);
  }
  else if (levelkeyword == KWD_QUERY_ASSERTION) {
    return (ASSERTION_INFERENCE);
  }
  else if (levelkeyword == KWD_QUERY_SUBSUMPTION) {
    return (SUBSUMPTION_INFERENCE);
  }
  else if (levelkeyword == KWD_QUERY_BACKTRACKING) {
    return (BACKTRACKING_INFERENCE);
  }
  else if (levelkeyword == KWD_QUERY_REFUTATION) {
    return (REFUTATION_INFERENCE);
  }
  else {
    *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal inference level: " << "`" << levelkeyword << "'" << "." << std::endl << "   Legal values are :ASSERTION :SHALLOW :SUBSUMPTION :BACKTRACKING :NORMAL :REFUTATION." << std::endl << std::endl;
  }
  return (oINFERENCELEVELo.get());
}

Keyword* setInferenceLevel(Object* level, Object* module) {
  // Set the inference level of `module' to the level specified
  // by 'levelKeyword'.  If `module' is NULL, set the level globally.
  { Module* themodule = coerceToModule(module, true);
    Keyword* thelevel = stringKeywordify(coerceToString(level));

    if (!((boolean)(module))) {
      themodule = NULL;
    }
    return (callSetInferenceLevel(thelevel, themodule));
  }
}

Keyword* callSetInferenceLevel(Keyword* levelkeyword, Module* module) {
  // Set the inference level of `module' to the level specified
  // by 'levelKeyword'.  If `module' is NULL and we are inside a query, set the
  // level of the current query iterator.  Otherwise, set the level globally.
  { InferenceLevel* level = getInferenceLevel(levelkeyword);

    if (((boolean)(module))) {
      setDynamicSlotValue(module->dynamicSlots, SYM_QUERY_LOGIC_INFERENCE_LEVEL, level, NULL);
    }
    else if (((boolean)(oQUERYITERATORo.get()))) {
      oQUERYITERATORo.get()->inferenceLevel = level;
    }
    else {
      oINFERENCELEVELo.set(((NormalInferenceLevel*)(level)));
    }
    return (level->keyword);
  }
}

// Controls whether queries use default knowledge or not.
DEFINE_STELLA_SPECIAL(oDONTUSEDEFAULTKNOWLEDGEpo, boolean , false);

boolean usingDefaultKnowledgeP() {
  return (!oDONTUSEDEFAULTKNOWLEDGEpo.get());
}

// Value for the maximum depth allowable during
// backtrack search.
int oMAXIMUM_BACKTRACKING_DEPTHo = NULL_INTEGER;

// Determines whether there is a slow but thorough type test
// when variables are bound, a fast but very shallow one, or none.  Values
// are :NONE, :LOOKUP, :DISJOINT.  The default is :LOOKUP.
DEFINE_STELLA_SPECIAL(oTYPE_CHECK_STRATEGYo, Keyword* , NULL);

// Determines what kind of duplicate subgoal test to use.  Choices
// are :DUPLICATE-RULES, :DUPLICATE-GOALS, and :DUPLICATE-GOALS-WITH-CACHING.
Keyword* oDUPLICATE_SUBGOAL_STRATEGYo = NULL;

// Sets the maximum number of frames search looking for
// a duplicate subgoal.  Default value is infinite.  Possibly this should
// be replaced by a function that increases with depth of search.
int oDUPLICATE_GOAL_SEARCH_DEPTHo = NULL_INTEGER;

// Set limit on number of frames searched looking for
// a duplicate rule.  Default value is infinite.
int oDUPLICATE_RULE_SEARCH_DEPTHo = NULL_INTEGER;

// If TRUE, all collections are assumed to be closed.
boolean oGLOBALLY_CLOSED_COLLECTIONSpo = false;

// If TRUE, the backchainer follows all lines of proof
// for each goal, rather than switching to a new goal once the first proof
// of a goal is achieved.  The partial matcher sets this variable to
// TRUE to force generation of proofs having possibly different
// weights.
DEFINE_STELLA_SPECIAL(oGENERATE_ALL_PROOFSpo, boolean , false);

void traceSubgoals() {
  setFeature(consList(1, KWD_QUERY_TRACE_SUBGOALS));
}

void untraceSubgoals() {
  unsetFeature(consList(1, KWD_QUERY_TRACE_SUBGOALS));
}

void traceRules() {
  addTrace(consList(1, KWD_QUERY_PROPAGATE));
}

void untraceRules() {
  dropTrace(consList(1, KWD_QUERY_PROPAGATE));
}

char* toggleTraceSubgoals() {
  if (oCURRENT_POWERLOOM_FEATURESo->memberP(KWD_QUERY_TRACE_SUBGOALS)) {
    {
      unsetFeature(consList(1, KWD_QUERY_TRACE_SUBGOALS));
      dropTrace(consList(1, KWD_QUERY_STRATEGIES));
      return ("Subgoal tracing disabled.");
    }
  }
  else {
    {
      setFeature(consList(1, KWD_QUERY_TRACE_SUBGOALS));
      addTrace(consList(1, KWD_QUERY_STRATEGIES));
      return ("Subgoal tracing enabled.");
    }
  }
}

char* toggleTraceRules() {
  if (((boolean)(oTRACED_KEYWORDSo)) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_PROPAGATE)) {
    {
      dropTrace(consList(1, KWD_QUERY_PROPAGATE));
      return ("Rule tracing disabled.");
    }
  }
  else {
    {
      addTrace(consList(1, KWD_QUERY_PROPAGATE));
      return ("Rule tracing enabled.");
    }
  }
}

QueryIterator* newQueryIterator() {
  { QueryIterator* self = NULL;

    self = new QueryIterator();
    self->dynamicSlots = newKeyValueList();
    self->firstIterationP = true;
    self->value = NULL;
    self->timeoutP = false;
    self->currentClockTicks = 0;
    self->allottedClockTicks = NULL_INTEGER;
    self->allottedTime = NULL_FLOAT;
    self->maximumDepth = NULL_INTEGER;
    self->currentDepthCutoff = NULL_INTEGER;
    self->inferenceLevel = NULL;
    self->partialMatchStrategy = NULL;
    self->timestamp = NULL_INTEGER;
    self->foundAtLeastOneSolutionP = false;
    self->failedToFindDuplicateSubgoalP = false;
    self->triggeredDepthCutoffP = false;
    self->activeGoalCaches = newList();
    self->augmentedGoalCacheP = false;
    self->controlFramePriorityQueue = NULL;
    self->currentParallelThread = NULL;
    self->currentPatternRecord = NULL;
    self->currentControlFrame = NULL;
    self->baseControlFrame = NULL;
    self->queryContext = NULL;
    self->solutions = newQuerySolutionTable();
    self->options = newPropertyList();
    self->exhaustedP = false;
    self->externalVariables = NULL;
    return (self);
  }
}

Surrogate* QueryIterator::primaryType() {
  { QueryIterator* self = this;

    return (SGT_QUERY_LOGIC_QUERY_ITERATOR);
  }
}

List* QueryIterator::residueGoals_reader() {
  { QueryIterator* self = this;

    { List* answer = ((List*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_RESIDUE_GOALS, NULL)));

      if (!((boolean)(answer))) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* QueryIterator::bestGoalSequence_reader() {
  { QueryIterator* self = this;

    { List* answer = ((List*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_BEST_GOAL_SEQUENCE, NULL)));

      if (!((boolean)(answer))) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

BooleanWrapper* QueryIterator::badP_reader() {
  { QueryIterator* self = this;

    { BooleanWrapper* answer = ((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_STELLA_BADp, NULL)));

      if (!((boolean)(answer))) {
        return ((false ? TRUE_WRAPPER : FALSE_WRAPPER));
      }
      else {
        return (answer);
      }
    }
  }
}

Object* accessQueryIteratorSlotValue(QueryIterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_LOGIC_EXTERNAL_VARIABLES) {
    if (setvalueP) {
      self->externalVariables = ((Vector*)(value));
    }
    else {
      value = self->externalVariables;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_EXHAUSTEDp) {
    if (setvalueP) {
      self->exhaustedP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->exhaustedP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_STELLA_OPTIONS) {
    if (setvalueP) {
      self->options = ((PropertyList*)(value));
    }
    else {
      value = self->options;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_SOLUTIONS) {
    if (setvalueP) {
      self->solutions = ((QuerySolutionTable*)(value));
    }
    else {
      value = self->solutions;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_QUERY_CONTEXT) {
    if (setvalueP) {
      self->queryContext = ((Context*)(value));
    }
    else {
      value = self->queryContext;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_BASE_CONTROL_FRAME) {
    if (setvalueP) {
      self->baseControlFrame = ((ControlFrame*)(value));
    }
    else {
      value = self->baseControlFrame;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CURRENT_CONTROL_FRAME) {
    if (setvalueP) {
      self->currentControlFrame = ((ControlFrame*)(value));
    }
    else {
      value = self->currentControlFrame;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CURRENT_PATTERN_RECORD) {
    if (setvalueP) {
      self->currentPatternRecord = ((PatternRecord*)(value));
    }
    else {
      value = self->currentPatternRecord;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CURRENT_PARALLEL_THREAD) {
    if (setvalueP) {
      self->currentParallelThread = ((ParallelThread*)(value));
    }
    else {
      value = self->currentParallelThread;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CONTROL_FRAME_PRIORITY_QUEUE) {
    if (setvalueP) {
      self->controlFramePriorityQueue = ((ControlFramePriorityQueue*)(value));
    }
    else {
      value = self->controlFramePriorityQueue;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_AUGMENTED_GOAL_CACHEp) {
    if (setvalueP) {
      self->augmentedGoalCacheP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->augmentedGoalCacheP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_ACTIVE_GOAL_CACHES) {
    if (setvalueP) {
      self->activeGoalCaches = ((List*)(value));
    }
    else {
      value = self->activeGoalCaches;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_TRIGGERED_DEPTH_CUTOFFp) {
    if (setvalueP) {
      self->triggeredDepthCutoffP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->triggeredDepthCutoffP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_FAILED_TO_FIND_DUPLICATE_SUBGOALp) {
    if (setvalueP) {
      self->failedToFindDuplicateSubgoalP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->failedToFindDuplicateSubgoalP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_FOUND_AT_LEAST_ONE_SOLUTIONp) {
    if (setvalueP) {
      self->foundAtLeastOneSolutionP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->foundAtLeastOneSolutionP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_TIMESTAMP) {
    if (setvalueP) {
      self->timestamp = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->timestamp);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_PARTIAL_MATCH_STRATEGY) {
    if (setvalueP) {
      self->partialMatchStrategy = ((PartialMatchFrame*)(value));
    }
    else {
      value = self->partialMatchStrategy;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_RESIDUE_GOALS) {
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_RESIDUE_GOALS, ((List*)(value)), NULL);
    }
    else {
      value = self->residueGoals_reader();
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_BEST_GOAL_SEQUENCE) {
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_BEST_GOAL_SEQUENCE, ((List*)(value)), NULL);
    }
    else {
      value = self->bestGoalSequence_reader();
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_INFERENCE_LEVEL) {
    if (setvalueP) {
      self->inferenceLevel = ((InferenceLevel*)(value));
    }
    else {
      value = self->inferenceLevel;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CURRENT_DEPTH_CUTOFF) {
    if (setvalueP) {
      self->currentDepthCutoff = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->currentDepthCutoff);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_MAXIMUM_DEPTH) {
    if (setvalueP) {
      self->maximumDepth = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->maximumDepth);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_ALLOTTED_TIME) {
    if (setvalueP) {
      self->allottedTime = ((FloatWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapFloat(self->allottedTime);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_ALLOTTED_CLOCK_TICKS) {
    if (setvalueP) {
      self->allottedClockTicks = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->allottedClockTicks);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CURRENT_CLOCK_TICKS) {
    if (setvalueP) {
      self->currentClockTicks = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->currentClockTicks);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_TIMEOUTp) {
    if (setvalueP) {
      self->timeoutP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->timeoutP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else {
    if (slotname == SYM_QUERY_LOGIC_NEGATED_QUERY) {
      slotname = SYM_QUERY_LOGIC_AUXILIARY_QUERY;
    }
    else if (slotname == SYM_QUERY_LOGIC_LATEST_PARTIAL_SCORE) {
      slotname = SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE;
    }
    else {
    }
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, slotname, value, NULL);
    }
    else {
      value = self->dynamicSlots->lookup(slotname);
    }
  }
  return (value);
}

boolean QueryIterator::deletedP() {
  { QueryIterator* self = this;

    { BooleanWrapper* deletedP = ((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_STELLA_DELETED_OBJECTp, NULL)));

      if (((boolean)(deletedP))) {
        return (coerceWrappedBooleanToBoolean(deletedP));
      }
      else {
        return (false);
      }
    }
  }
}

boolean QueryIterator::deletedPSetter(boolean value) {
  { QueryIterator* self = this;

    setDynamicSlotValue(self->dynamicSlots, SYM_QUERY_STELLA_DELETED_OBJECTp, (value ? TRUE_WRAPPER : FALSE_WRAPPER), NULL);
    return (value);
  }
}

void QueryIterator::printObject(std::ostream* stream) {
  { QueryIterator* self = this;

    printQueryIterator(self, stream);
  }
}

ControlFrame* newControlFrame() {
  { ControlFrame* self = NULL;

    self = new ControlFrame();
    self->dynamicSlots = newKeyValueList();
    self->dontCacheGoalFailureP = false;
    self->cachedGoalResultP = false;
    self->goalBindings = NULL;
    self->justifications = newList();
    self->partialMatchFrame = NULL;
    self->nextStrategies = NIL;
    self->currentStrategy = NULL;
    self->choicePointUnbindingOffset = NULL_INTEGER;
    self->inheritedPatternRecord = NULL;
    self->patternRecord = NULL;
    self->argumentCursor = 0;
    self->result = NULL;
    self->down = NULL;
    self->up = NULL;
    self->allottedClockTicks = NULL_INTEGER;
    self->startingClockTicks = NULL_INTEGER;
    self->reversePolarityP = false;
    self->truthValue = NULL;
    self->proposition = NULL;
    self->state = NULL;
    return (self);
  }
}

Surrogate* ControlFrame::primaryType() {
  { ControlFrame* self = this;

    return (SGT_QUERY_LOGIC_CONTROL_FRAME);
  }
}

boolean ControlFrame::holdsByDefaultP() {
  { ControlFrame* self = this;

    return ((self->truthValue == DEFAULT_TRUE_TRUTH_VALUE) ||
        (self->truthValue == DEFAULT_FALSE_TRUTH_VALUE));
  }
}

BooleanWrapper* ControlFrame::badP_reader() {
  { ControlFrame* self = this;

    { BooleanWrapper* answer = ((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_STELLA_BADp, NULL)));

      if (!((boolean)(answer))) {
        return ((false ? TRUE_WRAPPER : FALSE_WRAPPER));
      }
      else {
        return (answer);
      }
    }
  }
}

Object* accessControlFrameSlotValue(ControlFrame* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_STELLA_STATE) {
    if (setvalueP) {
      self->state = ((Keyword*)(value));
    }
    else {
      value = self->state;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_PROPOSITION) {
    if (setvalueP) {
      self->proposition = ((Proposition*)(value));
    }
    else {
      value = self->proposition;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_TRUTH_VALUE) {
    if (setvalueP) {
      self->truthValue = ((TruthValue*)(value));
    }
    else {
      value = self->truthValue;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_REVERSE_POLARITYp) {
    if (setvalueP) {
      self->reversePolarityP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->reversePolarityP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_STARTING_CLOCK_TICKS) {
    if (setvalueP) {
      self->startingClockTicks = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->startingClockTicks);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_ALLOTTED_CLOCK_TICKS) {
    if (setvalueP) {
      self->allottedClockTicks = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->allottedClockTicks);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_UP) {
    if (setvalueP) {
      self->up = ((ControlFrame*)(value));
    }
    else {
      value = self->up;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_DOWN) {
    if (setvalueP) {
      self->down = ((ControlFrame*)(value));
    }
    else {
      value = self->down;
    }
  }
  else if (slotname == SYM_QUERY_STELLA_RESULT) {
    if (setvalueP) {
      self->result = ((ControlFrame*)(value));
    }
    else {
      value = self->result;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_ARGUMENT_CURSOR) {
    if (setvalueP) {
      self->argumentCursor = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->argumentCursor);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_PATTERN_RECORD) {
    if (setvalueP) {
      self->patternRecord = ((PatternRecord*)(value));
    }
    else {
      value = self->patternRecord;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_INHERITED_PATTERN_RECORD) {
    if (setvalueP) {
      self->inheritedPatternRecord = ((PatternRecord*)(value));
    }
    else {
      value = self->inheritedPatternRecord;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CHOICE_POINT_UNBINDING_OFFSET) {
    if (setvalueP) {
      self->choicePointUnbindingOffset = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->choicePointUnbindingOffset);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CURRENT_STRATEGY) {
    if (setvalueP) {
      self->currentStrategy = ((Keyword*)(value));
    }
    else {
      value = self->currentStrategy;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_NEXT_STRATEGIES) {
    if (setvalueP) {
      self->nextStrategies = ((Cons*)(value));
    }
    else {
      value = self->nextStrategies;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_PARTIAL_MATCH_FRAME) {
    if (setvalueP) {
      self->partialMatchFrame = ((PartialMatchFrame*)(value));
    }
    else {
      value = self->partialMatchFrame;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_JUSTIFICATIONS) {
    if (setvalueP) {
      self->justifications = ((List*)(value));
    }
    else {
      value = self->justifications;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_GOAL_BINDINGS) {
    if (setvalueP) {
      self->goalBindings = ((Cons*)(value));
    }
    else {
      value = self->goalBindings;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CACHED_GOAL_RESULTp) {
    if (setvalueP) {
      self->cachedGoalResultP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->cachedGoalResultP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_DONT_CACHE_GOAL_FAILUREp) {
    if (setvalueP) {
      self->dontCacheGoalFailureP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->dontCacheGoalFailureP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else {
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, slotname, value, NULL);
    }
    else {
      value = self->dynamicSlots->lookup(slotname);
    }
  }
  return (value);
}

boolean ControlFrame::deletedP() {
  { ControlFrame* self = this;

    { BooleanWrapper* deletedP = ((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_STELLA_DELETED_OBJECTp, NULL)));

      if (((boolean)(deletedP))) {
        return (coerceWrappedBooleanToBoolean(deletedP));
      }
      else {
        return (false);
      }
    }
  }
}

boolean ControlFrame::deletedPSetter(boolean value) {
  { ControlFrame* self = this;

    setDynamicSlotValue(self->dynamicSlots, SYM_QUERY_STELLA_DELETED_OBJECTp, (value ? TRUE_WRAPPER : FALSE_WRAPPER), NULL);
    return (value);
  }
}

void ControlFrame::printObject(std::ostream* stream) {
  { ControlFrame* self = this;

    printControlFrame(self, stream);
  }
}

ParallelThread* newParallelThread() {
  { ParallelThread* self = NULL;

    self = new ParallelThread();
    self->status = NULL;
    self->priority = NULL_INTEGER;
    self->topUnbindingStackOffset = NULL_INTEGER;
    self->unbindingStack = NULL;
    self->variableBindings = NULL;
    self->hypotheticalWorld = NULL;
    self->topControlFrame = NULL;
    return (self);
  }
}

Surrogate* ParallelThread::primaryType() {
  { ParallelThread* self = this;

    return (SGT_QUERY_LOGIC_PARALLEL_THREAD);
  }
}

Object* accessParallelThreadSlotValue(ParallelThread* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_LOGIC_TOP_CONTROL_FRAME) {
    if (setvalueP) {
      self->topControlFrame = ((ControlFrame*)(value));
    }
    else {
      value = self->topControlFrame;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_HYPOTHETICAL_WORLD) {
    if (setvalueP) {
      self->hypotheticalWorld = ((World*)(value));
    }
    else {
      value = self->hypotheticalWorld;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_VARIABLE_BINDINGS) {
    if (setvalueP) {
      self->variableBindings = ((Vector*)(value));
    }
    else {
      value = self->variableBindings;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_UNBINDING_STACK) {
    if (setvalueP) {
      self->unbindingStack = ((IntegerVector*)(value));
    }
    else {
      value = self->unbindingStack;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_TOP_UNBINDING_STACK_OFFSET) {
    if (setvalueP) {
      self->topUnbindingStackOffset = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->topUnbindingStackOffset);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_PRIORITY) {
    if (setvalueP) {
      self->priority = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->priority);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_STATUS) {
    if (setvalueP) {
      self->status = ((Keyword*)(value));
    }
    else {
      value = self->status;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

ParallelControlFrame* newParallelControlFrame() {
  { ParallelControlFrame* self = NULL;

    self = new ParallelControlFrame();
    self->dynamicSlots = newKeyValueList();
    self->dontCacheGoalFailureP = false;
    self->cachedGoalResultP = false;
    self->goalBindings = NULL;
    self->justifications = newList();
    self->partialMatchFrame = NULL;
    self->nextStrategies = NIL;
    self->currentStrategy = NULL;
    self->choicePointUnbindingOffset = NULL_INTEGER;
    self->inheritedPatternRecord = NULL;
    self->patternRecord = NULL;
    self->argumentCursor = 0;
    self->result = NULL;
    self->down = NULL;
    self->up = NULL;
    self->allottedClockTicks = NULL_INTEGER;
    self->startingClockTicks = NULL_INTEGER;
    self->reversePolarityP = false;
    self->truthValue = NULL;
    self->proposition = NULL;
    self->state = NULL;
    self->savedParentParallelThread = NULL;
    self->savedParentContext = NULL;
    self->currentChildThread = NULL;
    self->unboundVariablesP = false;
    self->childThreads = newList();
    return (self);
  }
}

Surrogate* ParallelControlFrame::primaryType() {
  { ParallelControlFrame* self = this;

    return (SGT_QUERY_LOGIC_PARALLEL_CONTROL_FRAME);
  }
}

Object* accessParallelControlFrameSlotValue(ParallelControlFrame* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_LOGIC_CHILD_THREADS) {
    if (setvalueP) {
      self->childThreads = ((List*)(value));
    }
    else {
      value = self->childThreads;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_UNBOUND_VARIABLESp) {
    if (setvalueP) {
      self->unboundVariablesP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->unboundVariablesP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_CURRENT_CHILD_THREAD) {
    if (setvalueP) {
      self->currentChildThread = ((ParallelThread*)(value));
    }
    else {
      value = self->currentChildThread;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_SAVED_PARENT_CONTEXT) {
    if (setvalueP) {
      self->savedParentContext = ((Context*)(value));
    }
    else {
      value = self->savedParentContext;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_SAVED_PARENT_PARALLEL_THREAD) {
    if (setvalueP) {
      self->savedParentParallelThread = ((ParallelThread*)(value));
    }
    else {
      value = self->savedParentParallelThread;
    }
  }
  else {
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, slotname, value, NULL);
    }
    else {
      value = self->dynamicSlots->lookup(slotname);
    }
  }
  return (value);
}

ControlFramePriorityQueue* newControlFramePriorityQueue() {
  { ControlFramePriorityQueue* self = NULL;

    self = new ControlFramePriorityQueue();
    self->queue = NULL;
    return (self);
  }
}

Surrogate* ControlFramePriorityQueue::primaryType() {
  { ControlFramePriorityQueue* self = this;

    return (SGT_QUERY_LOGIC_CONTROL_FRAME_PRIORITY_QUEUE);
  }
}

Object* accessControlFramePriorityQueueSlotValue(ControlFramePriorityQueue* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_LOGIC_QUEUE) {
    if (setvalueP) {
      self->queue = ((List*)(value));
    }
    else {
      value = self->queue;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

// Points to the query iterator for the currently executing query.
DEFINE_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator* , NULL);

// Possibly a good value for the maximum backtracking depth.
// More testing is needed.
int oDEFAULT_MAXIMUM_DEPTHo = 25;

// Value of the initial depth used during an interative
// deepening search.
int oINITIAL_BACKTRACKING_DEPTHo = 5;

// Default setting.  If TRUE, queries are evaluated
// using iterative deepening from depth '*initial-backtracking-depth*'
// to depth '*maximum-backtracking-depth*'.
boolean oITERATIVE_DEEPENING_MODEpo = false;

// When TRUE, various kinds of characters are
// emitted to STANDARD-OUTPUT while PowerLoom is 'thinking'.
boolean oEMIT_THINKING_DOTSpo = true;

// Used to determine when to generate linefeeds
// after forty-or-so thinking dots.
int oTHINKING_DOT_COUNTERo = 0;

// Maps kind of thinking keywords to characters.
PropertyList* oTHINKING_DOT_TABLEo = NULL;

void emitThinkingDot(Keyword* kindofthinking) {
  if (oEMIT_THINKING_DOTSpo) {
    { CharacterWrapper* character = ((CharacterWrapper*)(oTHINKING_DOT_TABLEo->lookup(kindofthinking)));

      if (((boolean)(character))) {
        std::cout << character->wrapperValue;
        oTHINKING_DOT_COUNTERo = oTHINKING_DOT_COUNTERo + 1;
        if (oTHINKING_DOT_COUNTERo >= 70) {
          std::cout << std::endl;
          oTHINKING_DOT_COUNTERo = 0;
        }
      }
    }
  }
}

ProofAdjunct* newProofAdjunct() {
  { ProofAdjunct* self = NULL;

    self = new ProofAdjunct();
    return (self);
  }
}

Surrogate* ProofAdjunct::primaryType() {
  { ProofAdjunct* self = this;

    return (SGT_QUERY_LOGIC_PROOF_ADJUNCT);
  }
}

PatternRecord* newPatternRecord() {
  { PatternRecord* self = NULL;

    self = new PatternRecord();
    self->collectionList = NULL;
    self->optimalPattern = NULL;
    self->booleanVector = NULL;
    self->externalArguments = NULL;
    self->description = NULL;
    self->topUnbindingStackOffset = NULL_INTEGER;
    self->unbindingStack = NULL;
    self->variableBindings = NULL;
    self->controlFrame = NULL;
    return (self);
  }
}

void PatternRecord::free() {
  { PatternRecord* self = this;

    if (terminatePatternRecordP(self)) {
      unmake(self);
    }
  }
}

Surrogate* PatternRecord::primaryType() {
  { PatternRecord* self = this;

    return (SGT_QUERY_LOGIC_PATTERN_RECORD);
  }
}

Object* accessPatternRecordSlotValue(PatternRecord* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_LOGIC_CONTROL_FRAME) {
    if (setvalueP) {
      self->controlFrame = ((ControlFrame*)(value));
    }
    else {
      value = self->controlFrame;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_VARIABLE_BINDINGS) {
    if (setvalueP) {
      self->variableBindings = ((Vector*)(value));
    }
    else {
      value = self->variableBindings;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_UNBINDING_STACK) {
    if (setvalueP) {
      self->unbindingStack = ((IntegerVector*)(value));
    }
    else {
      value = self->unbindingStack;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_TOP_UNBINDING_STACK_OFFSET) {
    if (setvalueP) {
      self->topUnbindingStackOffset = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->topUnbindingStackOffset);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_DESCRIPTION) {
    if (setvalueP) {
      self->description = ((Description*)(value));
    }
    else {
      value = self->description;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_EXTERNAL_ARGUMENTS) {
    if (setvalueP) {
      self->externalArguments = ((Vector*)(value));
    }
    else {
      value = self->externalArguments;
    }
  }
  else if (slotname == SYM_QUERY_STELLA_BOOLEAN_VECTOR) {
    if (setvalueP) {
      self->booleanVector = ((BooleanVector*)(value));
    }
    else {
      value = self->booleanVector;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_OPTIMAL_PATTERN) {
    if (setvalueP) {
      self->optimalPattern = ((Description*)(value));
    }
    else {
      value = self->optimalPattern;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_COLLECTION_LIST) {
    if (setvalueP) {
      self->collectionList = ((List*)(value));
    }
    else {
      value = self->collectionList;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

BooleanVectorIndexNode* newBooleanVectorIndexNode() {
  { BooleanVectorIndexNode* self = NULL;

    self = new BooleanVectorIndexNode();
    self->theVector = NULL;
    self->falseLink = NULL;
    self->trueLink = NULL;
    return (self);
  }
}

Surrogate* BooleanVectorIndexNode::primaryType() {
  { BooleanVectorIndexNode* self = this;

    return (SGT_QUERY_LOGIC_BOOLEAN_VECTOR_INDEX_NODE);
  }
}

Object* accessBooleanVectorIndexNodeSlotValue(BooleanVectorIndexNode* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_LOGIC_TRUE_LINK) {
    if (setvalueP) {
      self->trueLink = ((BooleanVectorIndexNode*)(value));
    }
    else {
      value = self->trueLink;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_FALSE_LINK) {
    if (setvalueP) {
      self->falseLink = ((BooleanVectorIndexNode*)(value));
    }
    else {
      value = self->falseLink;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_THE_VECTOR) {
    if (setvalueP) {
      self->theVector = ((BooleanVector*)(value));
    }
    else {
      value = self->theVector;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

// Points to the head of a discrimination tree of containing
// all boolean vectors.
BooleanVectorIndexNode* oBOOLEAN_VECTOR_INDEXo = NULL;

BooleanVectorIndexNode* createBooleanVectorIndexNode(BooleanVectorIndexNode* parentnode, boolean lastvalue) {
  { BooleanVectorIndexNode* node = newBooleanVectorIndexNode();
    int vectorlength = parentnode->theVector->length() + 1;
    BooleanVector* vector = newBooleanVector(vectorlength);

    node->theVector = vector;
    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = vectorlength - 2;

      for  (i, iter000, upperBound000; 
            iter000 <= upperBound000; 
            iter000 = iter000 + 1) {
        i = iter000;
        (vector->theArray)[i] = (((BooleanWrapper*)((parentnode->theVector->theArray)[i])));
      }
    }
    (vector->theArray)[(vectorlength - 1)] = ((lastvalue ? TRUE_WRAPPER : FALSE_WRAPPER));
    if (lastvalue) {
      parentnode->trueLink = node;
    }
    else {
      parentnode->falseLink = node;
    }
    return (node);
  }
}

BooleanVector* argumentsVectorToBooleanVector(Vector* argumentsvector) {
  { BooleanVectorIndexNode* node = oBOOLEAN_VECTOR_INDEXo;
    BooleanVectorIndexNode* nextnode = NULL;
    boolean boundP = false;

    { Object* arg = NULL;
      Vector* vector000 = argumentsvector;
      int index000 = 0;
      int length000 = vector000->length();

      for  (arg, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        boundP = true;
        if (subtypeOfP(safePrimaryType(arg), SGT_QUERY_LOGIC_PATTERN_VARIABLE)) {
          { Object* arg000 = arg;
            PatternVariable* arg = ((PatternVariable*)(arg000));

            boundP = ((boolean)((oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(arg->boundToOffset)]));
          }
        }
        else {
        }
        if (boundP) {
          {
            nextnode = node->trueLink;
            if (!((boolean)(nextnode))) {
              nextnode = createBooleanVectorIndexNode(node, true);
            }
          }
        }
        else {
          {
            nextnode = node->falseLink;
            if (!((boolean)(nextnode))) {
              nextnode = createBooleanVectorIndexNode(node, false);
            }
          }
        }
        node = nextnode;
      }
    }
    return (node->theVector);
  }
}

BooleanVector* zeroOneListToBooleanVector(List* zeroonelist) {
  { BooleanVectorIndexNode* node = oBOOLEAN_VECTOR_INDEXo;
    BooleanVectorIndexNode* nextnode = NULL;

    { IntegerWrapper* bit = NULL;
      Cons* iter000 = zeroonelist->theConsList;

      for (bit, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        bit = ((IntegerWrapper*)(iter000->value));
        if (eqlP(bit, ONE_WRAPPER)) {
          {
            nextnode = node->trueLink;
            if (!((boolean)(nextnode))) {
              nextnode = createBooleanVectorIndexNode(node, true);
            }
          }
        }
        else {
          {
            nextnode = node->falseLink;
            if (!((boolean)(nextnode))) {
              nextnode = createBooleanVectorIndexNode(node, false);
            }
          }
        }
        node = nextnode;
      }
    }
    return (node->theVector);
  }
}

void popControlFrame(ControlFrame* frame) {
  if ((frame->state == KWD_QUERY_PATTERN) ||
      (frame->state == KWD_QUERY_CONTAINED_BY)) {
    resetCurrentPatternRecord(frame, KWD_QUERY_PARENT);
  }
  if (((boolean)(((Iterator*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR, NULL)))))) {
    ((Iterator*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR, NULL)))->free();
    setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR, NULL, NULL);
  }
  frame->choicePointUnbindingOffset = NULL_INTEGER;
  frame->free();
  frame->state = KWD_QUERY_POPPED;
}

void popFramesUpTo(ControlFrame* frame) {
  if (((boolean)(frame->down))) {
    popFramesUpTo(frame->down);
  }
  if (((boolean)(frame->up))) {
    frame->up->down = NULL;
  }
  popControlFrame(frame);
}

void popDownFrame(ControlFrame* frame) {
  popControlFrame(frame->down);
  frame->down = NULL;
}

void activatePatternRecord(PatternRecord* patternrecord, int variablecount) {
  { Vector* vector = patternrecord->variableBindings;
    IntegerVector* stack = patternrecord->unbindingStack;

    if (((boolean)(vector)) &&
        (vector->arraySize >= variablecount)) {
      { int i = NULL_INTEGER;
        int iter000 = 0;
        int upperBound000 = variablecount - 1;

        for  (i, iter000, upperBound000; 
              iter000 <= upperBound000; 
              iter000 = iter000 + 1) {
          i = iter000;
          (vector->theArray)[i] = NULL;
          (stack->theArray)[i] = NULL;
        }
      }
    }
    else {
      {
        patternrecord->variableBindings = newVector(variablecount);
        patternrecord->unbindingStack = newIntegerVector(variablecount);
      }
    }
    patternrecord->topUnbindingStackOffset = -1;
    oQUERYITERATORo.get()->currentPatternRecord = patternrecord;
  }
}

void resetCurrentPatternRecord(ControlFrame* frame, Keyword* localorparent) {
  if (localorparent == KWD_QUERY_LOCAL) {
    oQUERYITERATORo.get()->currentPatternRecord = frame->patternRecord;
  }
  else if (localorparent == KWD_QUERY_PARENT) {
    if (((boolean)(frame->inheritedPatternRecord))) {
      oQUERYITERATORo.get()->currentPatternRecord = frame->inheritedPatternRecord;
    }
    else {
      oQUERYITERATORo.get()->currentPatternRecord = oQUERYITERATORo.get()->baseControlFrame->patternRecord;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << localorparent << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

void printEnvironmentStacks() {
  { ControlFrame* frame = oQUERYITERATORo.get()->currentControlFrame;
    PatternRecord* currentpatternrecord = oQUERYITERATORo.get()->currentPatternRecord;

    std::cout << "-------------------------" << std::endl;
    std::cout << "current-control-frame " << frame << std::endl;
    std::cout << "    ";
    { Object* arg = NULL;
      Vector* vector000 = currentpatternrecord->variableBindings;
      int index000 = 0;
      int length000 = vector000->length();

      for  (arg, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        if (((boolean)(arg))) {
          std::cout << arg << " ";
        }
        else {
          std::cout << "_ ";
        }
      }
    }
    std::cout << std::endl;
    std::cout << "    " << currentpatternrecord->unbindingStack << std::endl;
    std::cout << "-------------------------" << std::endl;
  }
}

void setPatternVariableBinding(PatternVariable* variable, Object* value) {
  if (((boolean)(oTRACED_KEYWORDSo)) &&
      oTRACED_KEYWORDSo->membP(KWD_QUERY_QUERY_STACKS)) {
    std::cout << "set-pattern-variable-binding: " << variable << " " << value << "  F" << debugFrameId(oQUERYITERATORo.get()->currentPatternRecord->controlFrame) << std::endl;
  }
  { PatternRecord* patternrecord = oQUERYITERATORo.get()->currentPatternRecord;
    int vboffset = variable->boundToOffset;
    int ubstackoffset = patternrecord->topUnbindingStackOffset + 1;

    (patternrecord->variableBindings->theArray)[vboffset] = value;
    patternrecord->topUnbindingStackOffset = ubstackoffset;
    (patternrecord->unbindingStack->theArray)[ubstackoffset] = (wrapInteger(vboffset));
  }
}

void changePatternVariableBinding(PatternVariable* variable, Object* newvalue) {
  { PatternRecord* patternrecord = oQUERYITERATORo.get()->currentPatternRecord;
    int vboffset = variable->boundToOffset;

    (patternrecord->variableBindings->theArray)[vboffset] = newvalue;
  }
}

void unbindVariablesBeginningAt(PatternRecord* patternrecord, int ubstackoffset) {
  { Vector* variablebindingsvector = patternrecord->variableBindings;
    IntegerVector* unbindingstack = patternrecord->unbindingStack;

    if (patternrecord->topUnbindingStackOffset < ubstackoffset) {
      return;
    }
    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_QUERY_STACKS)) {
      std::cout << "unbind-variables-beginning-at: " << "UBS= " << ubstackoffset << "  F" << debugFrameId(patternrecord->controlFrame) << "  #bindings= " << ((patternrecord->topUnbindingStackOffset - ubstackoffset) + 1) << std::endl;
    }
    { int i = NULL_INTEGER;
      int iter000 = ubstackoffset;
      int upperBound000 = patternrecord->topUnbindingStackOffset;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      for  (i, iter000, upperBound000, unboundedP000; 
            unboundedP000 ||
                (iter000 <= upperBound000); 
            iter000 = iter000 + 1) {
        i = iter000;
        (variablebindingsvector->theArray)[(((IntegerWrapper*)((unbindingstack->theArray)[i]))->wrapperValue)] = NULL;
        (unbindingstack->theArray)[i] = NULL;
      }
    }
    patternrecord->topUnbindingStackOffset = ubstackoffset - 1;
  }
}

void createChoicePoint(ControlFrame* frame) {
  { PatternRecord* patternrecord = frame->inheritedPatternRecord;

    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_QUERY_STACKS)) {
      std::cout << "create-choice-point: " << "F " << debugFrameId(frame) << " CP= " << frame->choicePointUnbindingOffset << " NEWCP= " << (patternrecord->topUnbindingStackOffset + 1) << std::endl;
    }
    if (frame->choicePointUnbindingOffset == NULL_INTEGER) {
      frame->choicePointUnbindingOffset = patternrecord->topUnbindingStackOffset + 1;
    }
    else {
      unbindVariablesBeginningAt(patternrecord, frame->choicePointUnbindingOffset);
    }
  }
}

void unwindToChoicePoint(ControlFrame* frame) {
  { int choicepoint = frame->choicePointUnbindingOffset;

    if (choicepoint != NULL_INTEGER) {
      unbindVariablesBeginningAt(frame->inheritedPatternRecord, choicepoint);
    }
  }
}

boolean newBindingsSinceLastChoicePointP(ControlFrame* frame) {
  return (frame->choicePointUnbindingOffset <= frame->inheritedPatternRecord->topUnbindingStackOffset);
}

Object* boundTo(PatternVariable* self) {
  return ((oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(self->boundToOffset)]);
}

Object* safeBoundTo(PatternVariable* self) {
  if (((boolean)(oQUERYITERATORo.get()))) {
    { Vector* bindings = oQUERYITERATORo.get()->currentPatternRecord->variableBindings;
      int offset = self->boundToOffset;

      if (((boolean)(bindings)) &&
          ((offset != NULL_INTEGER) &&
           (offset < bindings->length()))) {
        return ((bindings->theArray)[offset]);
      }
    }
  }
  return (NULL);
}

Object* boundToInFrame(PatternVariable* self, ControlFrame* frame) {
  { Vector* bindings = operativePatternRecord(frame)->variableBindings;
    int offset = self->boundToOffset;

    if (((boolean)(bindings)) &&
        ((offset != NULL_INTEGER) &&
         (offset < bindings->length()))) {
      return ((bindings->theArray)[offset]);
    }
    else {
      return (NULL);
    }
  }
}

Object* boundToInRecord(PatternVariable* self, PatternRecord* record) {
  return ((record->variableBindings->theArray)[(self->boundToOffset)]);
}

boolean containsOperatorP(Proposition* proposition, Surrogate* operatoR) {
  { boolean testValue000 = false;

    if (proposition->operatoR == operatoR) {
      testValue000 = true;
    }
    else {
      { boolean foundP000 = false;

        { Object* arg = NULL;
          Vector* vector000 = proposition->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          for  (arg, vector000, index000, length000; 
                index000 < length000; 
                index000 = index000 + 1) {
            arg = (vector000->theArray)[index000];
            if (isaP(arg, SGT_QUERY_LOGIC_PROPOSITION) &&
                containsOperatorP(((Proposition*)(arg)), operatoR)) {
              foundP000 = true;
              break;
            }
          }
        }
        testValue000 = foundP000;
      }
    }
    { boolean value000 = testValue000;

      return (value000);
    }
  }
}

Object* argumentBoundTo(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_PATTERN_VARIABLE)) {
      { Object* self000 = self;
        PatternVariable* self = ((PatternVariable*)(self000));

        { Object* value = (oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(self->boundToOffset)];

          if ((!((boolean)(value))) &&
              ((boolean)(((Object*)(accessInContext(self->variableValue, self->homeContext, false)))))) {
            value = valueOf(self);
            if (skolemP(value)) {
              return (NULL);
            }
            bindVariableToValueP(self, value, true);
          }
          return (value);
        }
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* self001 = self;
        Surrogate* self = ((Surrogate*)(self001));

        return (valueOf(self));
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_DESCRIPTION)) {
      { Object* self002 = self;
        Description* self = ((Description*)(self002));

        if (((boolean)(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_EXTERNAL_VARIABLES, NULL))))) &&
            containsOperatorP(self->proposition, SGT_QUERY_PL_KERNEL_KB_HOLDS)) {
          { Description* temp000 = findDuplicateDescription(self);

            { Description* value000 = (((boolean)(temp000)) ? temp000 : self);

              return (value000);
            }
          }
        }
        return (valueOf(self));
      }
    }
    else {
      return (valueOf(self));
    }
  }
}

boolean helpUnifyAttributesP(Object* value1, Object* value2) {
  return (eqlP(value1, value2) ||
      (skolemP(value1) &&
       helpBindVariableToValueP(((PatternVariable*)(value1)), value2)));
}

boolean failsUnificationTypeCheckP(PatternVariable* v1, Object* i2) {
  if (oTYPE_CHECK_STRATEGYo.get() == KWD_QUERY_NONE) {
    return (false);
  }
  else if (oTYPE_CHECK_STRATEGYo.get() == KWD_QUERY_LOOKUP) {
    { Surrogate* type = v1->skolemType;
      boolean typeisokP = (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) ||
          checkStrictTypeP(i2, type, true);

      if ((!typeisokP) &&
          nonInferableP(surrogateToDescription(type))) {
        return (true);
      }
      else {
        return (false);
      }
    }
  }
  else if (oTYPE_CHECK_STRATEGYo.get() == KWD_QUERY_SHALLOW_DISJOINT) {
    if (((boolean)(v1->skolemType)) &&
        disjointClassesP(getDescription(v1->skolemType), getDescription(logicalType(i2)))) {
      return (true);
    }
    return (false);
  }
  else if (oTYPE_CHECK_STRATEGYo.get() == KWD_QUERY_DISJOINT) {
    { Surrogate* type1 = NULL;
      Surrogate* type2 = NULL;

      { Proposition* p = NULL;
        Iterator* iter000 = unfilteredDependentIsaPropositions(v1)->allocateIterator();

        for (p, iter000; iter000->nextP(); ) {
          p = ((Proposition*)(iter000->value));
          if (p->kind == KWD_QUERY_ISA) {
            type1 = ((Surrogate*)((p->arguments->theArray)[1]));
            break;
          }
        }
      }
      if (!((boolean)(type1))) {
        return (false);
      }
      if (subtypeOfP(safePrimaryType(i2), SGT_QUERY_LOGIC_LOGIC_OBJECT)) {
        { Object* i2000 = i2;
          LogicObject* i2 = ((LogicObject*)(i2000));

          { Proposition* p = NULL;
            Iterator* iter001 = unfilteredDependentIsaPropositions(i2)->allocateIterator();

            for (p, iter001; iter001->nextP(); ) {
              p = ((Proposition*)(iter001->value));
              if (p->kind == KWD_QUERY_ISA) {
                type2 = ((Surrogate*)((p->arguments->theArray)[1]));
                break;
              }
            }
          }
        }
      }
      else {
        type2 = logicalType(i2);
      }
      if (!((boolean)(type2))) {
        return (false);
      }
      return (disjointClassesP(getDescription(type1), getDescription(type2)));
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << oTYPE_CHECK_STRATEGYo.get() << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

boolean failsAntecedentTypeCheckP(PatternVariable* v1, Object* i2) {
  if (oTYPE_CHECK_STRATEGYo.get() == KWD_QUERY_LOOKUP) {
    { Surrogate* type = v1->skolemType;
      boolean typeisokP = (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) ||
          checkStrictTypeP(i2, type, true);

      if ((!typeisokP) &&
          nonInferableP(surrogateToDescription(type))) {
        return (true);
      }
      else {
        return (false);
      }
    }
  }
  else if (oTYPE_CHECK_STRATEGYo.get() == KWD_QUERY_NONE) {
    return (false);
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << oTYPE_CHECK_STRATEGYo.get() << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

boolean helpBindVariableToValueP(PatternVariable* variable, Object* value) {
  if (oTYPE_CHECK_STRATEGYo.get() == KWD_QUERY_LOOKUP) {
    { boolean typeisokP = false;

      typeisokP = checkCoercedTypeP(value, variable->skolemType, true, value);
      if ((!typeisokP) &&
          nonInferableP(surrogateToDescription(variable->skolemType))) {
        if (((boolean)(oTRACED_KEYWORDSo)) &&
            oTRACED_KEYWORDSo->membP(KWD_QUERY_PERFORMANCE_CLUES)) {
          std::cout << "TYPE CHECK VIOLATION in 'bind-variable-to-value?'.  Type= " << variable->skolemType << " Value= " << value << std::endl;
        }
        return (false);
      }
    }
  }
  else if (oTYPE_CHECK_STRATEGYo.get() == KWD_QUERY_NONE) {
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << oTYPE_CHECK_STRATEGYo.get() << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  { Object* boundtovalue = (oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(variable->boundToOffset)];
    Object* variablevalue = ((Object*)(accessInContext(variable->variableValue, variable->homeContext, false)));

    elaborateInstance(value);
    if (((boolean)(variablevalue)) &&
        (!((boolean)(boundtovalue)))) {
      variablevalue = valueOf(variablevalue);
      setPatternVariableBinding(variable, variablevalue);
      return (eqlP(variablevalue, value));
    }
    else if (!((boolean)(boundtovalue))) {
      setPatternVariableBinding(variable, value);
    }
    else if (equalP(valueOf(boundtovalue), valueOf(value))) {
      if (!(eqlP(boundtovalue, valueOf(boundtovalue)))) {
        changePatternVariableBinding(variable, valueOf(boundtovalue));
      }
      return (true);
    }
    else {
      return (false);
    }
    return (true);
  }
}

boolean bindVariableToValueP(PatternVariable* variable, Object* value, boolean autocleanupP) {
  if (!((boolean)(value))) {
    if ((((boolean)(oQUERYITERATORo.get())) &&
        ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) &&
        oQUERYITERATORo.get()->partialMatchStrategy->allowUnboundVariablesP()) {
      return (true);
    }
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
      *(STANDARD_WARNING->nativeStream) << "WARNING: " << "Tried to bind " << variable << " to NULL value.  Potentially a PowerLoom bug" << std::endl;
      helpSignalPropositionError(STANDARD_WARNING, KWD_QUERY_WARNING);
    }
    return (false);
  }
  if (autocleanupP) {
    { PatternRecord* patternrecord = oQUERYITERATORo.get()->currentPatternRecord;
      int ubstackoffset = patternrecord->topUnbindingStackOffset;
      boolean successP = false;

      successP = helpBindVariableToValueP(variable, value);
      if (!successP) {
        unbindVariablesBeginningAt(patternrecord, ubstackoffset + 1);
      }
      return (successP);
    }
  }
  else {
    return (helpBindVariableToValueP(variable, value));
  }
}

boolean bindArgumentToValueP(Object* argument, Object* value, boolean autocleanupP) {
  if (!((boolean)(value))) {
    if ((((boolean)(oQUERYITERATORo.get())) &&
        ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) &&
        oQUERYITERATORo.get()->partialMatchStrategy->allowUnboundVariablesP()) {
      return (true);
    }
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
      *(STANDARD_WARNING->nativeStream) << "WARNING: " << "Tried to bind " << argument << " to NULL value.  Potentially a PowerLoom bug" << std::endl;
      helpSignalPropositionError(STANDARD_WARNING, KWD_QUERY_WARNING);
    }
    return (false);
  }
  { Surrogate* testValue000 = safePrimaryType(argument);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_PATTERN_VARIABLE)) {
      { Object* argument000 = argument;
        PatternVariable* argument = ((PatternVariable*)(argument000));

        return (bindVariableToValueP(argument, value, autocleanupP));
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* argument001 = argument;
        Surrogate* argument = ((Surrogate*)(argument001));

        return (eqlP(valueOf(argument), value));
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_PROPOSITION)) {
      { Object* argument002 = argument;
        Proposition* argument = ((Proposition*)(argument002));

        if (isaP(value, SGT_QUERY_LOGIC_PROPOSITION)) {
          { KeyValueList* mapping = newKeyValueList();

            { boolean testValue001 = false;

              testValue001 = unifyPropositionsP(argument, ((Proposition*)(value)), mapping);
              if (testValue001) {
                { boolean alwaysP000 = true;

                  { Object* var = NULL;
                    Object* val = NULL;
                    KvCons* iter000 = mapping->theKvList;

                    for  (var, val, iter000; 
                          ((boolean)(iter000)); 
                          iter000 = iter000->rest) {
                      var = iter000->key;
                      val = iter000->value;
                      if (!bindVariableToValueP(((PatternVariable*)(var)), val, autocleanupP)) {
                        alwaysP000 = false;
                        break;
                      }
                    }
                  }
                  testValue001 = alwaysP000;
                }
              }
              if (testValue001) {
                return (true);
              }
            }
          }
        }
        return (false);
      }
    }
    else {
      return (eqlP(argument, value));
    }
  }
}

boolean bindVectorOfArgumentsToValuesP(Vector* arguments, Cons* values) {
  { PatternRecord* patternrecord = oQUERYITERATORo.get()->currentPatternRecord;
    int ubstackoffset = patternrecord->topUnbindingStackOffset;
    boolean successP = false;

    { boolean alwaysP000 = true;

      { Object* arg = NULL;
        Vector* vector000 = arguments;
        int index000 = 0;
        int length000 = vector000->length();
        Object* v = NULL;
        Cons* iter000 = values;

        for  (arg, vector000, index000, length000, v, iter000; 
              (index000 < length000) &&
                  (!(iter000 == NIL)); 
              index000 = index000 + 1,
              iter000 = iter000->rest) {
          arg = (vector000->theArray)[index000];
          v = iter000->value;
          if (!bindArgumentToValueP(arg, v, false)) {
            alwaysP000 = false;
            break;
          }
        }
      }
      successP = alwaysP000;
    }
    if (!successP) {
      unbindVariablesBeginningAt(patternrecord, ubstackoffset + 1);
    }
    return (successP);
  }
}

void printControlFrameStack(ControlFrame* frame) {
  std::cout << frame << std::endl;
  if (((boolean)(frame->down))) {
    printControlFrameStack(frame->down);
  }
}

void pcs() {
  printControlFrameStack(oQUERYITERATORo.get()->baseControlFrame);
}

PatternVariable* variableFromUnbindingOffset(Description* description, int uboffset) {
  { PatternRecord* patternrecord = oQUERYITERATORo.get()->currentPatternRecord;
    int offset = ((IntegerWrapper*)((patternrecord->unbindingStack->theArray)[uboffset]))->wrapperValue;

    { PatternVariable* vbl = NULL;
      Vector* vector000 = description->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();

      for  (vbl, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        vbl = ((PatternVariable*)((vector000->theArray)[index000]));
        if (vbl->boundToOffset == offset) {
          return (vbl);
        }
      }
    }
    { PatternVariable* vbl = NULL;
      Vector* vector001 = description->internalVariables;
      int index001 = 0;
      int length001 = vector001->length();

      for  (vbl, vector001, index001, length001; 
            index001 < length001; 
            index001 = index001 + 1) {
        vbl = ((PatternVariable*)((vector001->theArray)[index001]));
        if (vbl->boundToOffset == offset) {
          return (vbl);
        }
      }
    }
    return (NULL);
  }
}

// If set, controls diagnostic printing by making
// variable bindings appear relative to the frame '*printInFrame*'.
DEFINE_STELLA_SPECIAL(oPRINTINFRAMEo, ControlFrame* , NULL);

void printOneVariableBinding(PatternVariable* variable) {
  std::cout << variable->skolemName << "=";
  if (variable->boundToOffset != NULL_INTEGER) {
    { Object* value = (((boolean)(oPRINTINFRAMEo.get())) ? boundToInFrame(variable, oPRINTINFRAMEo.get()) : safeBoundTo(variable));

      printUnformattedLogicalForm(value, STANDARD_OUTPUT);
    }
  }
  else {
    std::cout << SYM_QUERY_STELLA_NULL;
  }
  std::cout << " ";
}

void printVariableBindings(ControlFrame* frame) {
  { PatternRecord* patternrecord = operativePatternRecord(frame);
    Description* description = NULL;

    if (((boolean)(patternrecord))) {
      if (frame->state == KWD_QUERY_CONTAINED_BY) {
        { Proposition* memberproposition = ((Proposition*)((frame->proposition->arguments->theArray)[0]));
          Object* member = (memberproposition->arguments->theArray)[0];

          { Surrogate* testValue000 = safePrimaryType(member);

            if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_PATTERN_VARIABLE)) {
              { Object* member000 = member;
                PatternVariable* member = ((PatternVariable*)(member000));

                printOneVariableBinding(member);
              }
            }
            else if (subtypeOfP(testValue000, SGT_QUERY_STELLA_LIST)) {
              { Object* member001 = member;
                List* member = ((List*)(member001));

                { Object* m = NULL;
                  Cons* iter000 = member->theConsList;

                  for (m, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
                    m = iter000->value;
                    printOneVariableBinding(((PatternVariable*)(m)));
                  }
                }
              }
            }
            else {
              { OutputStringStream* stream000 = newOutputStringStream();

                *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
                throw *newStellaException(stream000->theStringReader());
              }
            }
          }
        }
        return;
      }
      description = patternrecord->optimalPattern;
      if (((boolean)(description))) {
        { PatternVariable* vbl = NULL;
          Vector* vector000 = description->ioVariables;
          int index000 = 0;
          int length000 = vector000->length();

          for  (vbl, vector000, index000, length000; 
                index000 < length000; 
                index000 = index000 + 1) {
            vbl = ((PatternVariable*)((vector000->theArray)[index000]));
            if (((boolean)((patternrecord->variableBindings->theArray)[(vbl->boundToOffset)]))) {
              printOneVariableBinding(vbl);
            }
          }
        }
        { PatternVariable* vbl = NULL;
          Vector* vector001 = description->internalVariables;
          int index001 = 0;
          int length001 = vector001->length();

          for  (vbl, vector001, index001, length001; 
                index001 < length001; 
                index001 = index001 + 1) {
            vbl = ((PatternVariable*)((vector001->theArray)[index001]));
            if (((boolean)((patternrecord->variableBindings->theArray)[(vbl->boundToOffset)]))) {
              printOneVariableBinding(vbl);
            }
          }
        }
      }
    }
  }
}

void printRuleInGoalTree(ControlFrame* frame, Proposition* impliesprop, int depth) {
  { PatternRecord* patternrecord = frame->patternRecord;
    boolean reversepolarityP = frame->reversePolarityP;

    std::cout << "RULE: ";
    { Surrogate* rulename = ((Surrogate*)(dynamicSlotValue(impliesprop->dynamicSlots, SYM_QUERY_STELLA_SURROGATE_VALUE_INVERSE, NULL)));

      if ((!((boolean)(rulename))) &&
          ((boolean)(((Proposition*)(dynamicSlotValue(impliesprop->dynamicSlots, SYM_QUERY_LOGIC_MASTER_PROPOSITION, NULL)))))) {
        rulename = ((Surrogate*)(dynamicSlotValue(((Proposition*)(dynamicSlotValue(impliesprop->dynamicSlots, SYM_QUERY_LOGIC_MASTER_PROPOSITION, NULL)))->dynamicSlots, SYM_QUERY_STELLA_SURROGATE_VALUE_INVERSE, NULL)));
      }
      if (((boolean)(rulename))) {
        std::cout << rulename->symbolName << std::endl;
        printIndent(STANDARD_OUTPUT, (2 * depth) + 6);
      }
    }
    { 
      BIND_STELLA_SPECIAL(oPRINTMODEo, Keyword*, KWD_QUERY_FLAT);
      BIND_STELLA_SPECIAL(oPRINTLOGICALFORMSTREAMo, OutputStream*, STANDARD_OUTPUT);
      BIND_STELLA_SPECIAL(oINDENTCOUNTERo, int, (2 * depth) + 7);
      BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, NULL);
      { Description* chooseValue000 = NULL;

        if (reversepolarityP) {
          { Description* temp000 = patternrecord->optimalPattern;

            chooseValue000 = (((boolean)(temp000)) ? temp000 : patternrecord->description);
          }
        }
        else {
          chooseValue000 = ((Description*)((impliesprop->arguments->theArray)[1]));
        }
        { Description* chooseValue001 = NULL;

          if (reversepolarityP) {
            chooseValue001 = ((Description*)((impliesprop->arguments->theArray)[0]));
          }
          else {
            { Description* temp001 = patternrecord->optimalPattern;

              chooseValue001 = (((boolean)(temp001)) ? temp001 : patternrecord->description);
            }
          }
          printDescriptionsAsKifRule(chooseValue000, chooseValue001, impliesprop, reversepolarityP);
        }
      }
    }
  }
}

void printGoalInGoalTree(ControlFrame* frame, int depth) {
  if (((boolean)(frame->proposition))) {
    { boolean invertP = frame->reversePolarityP;

      std::cout << "GOAL: ";
      if (invertP) {
        std::cout << "~";
      }
      { 
        BIND_STELLA_SPECIAL(oPRINTMODEo, Keyword*, KWD_QUERY_REALISTIC);
        BIND_STELLA_SPECIAL(oPRINTLOGICALFORMSTREAMo, OutputStream*, STANDARD_OUTPUT);
        BIND_STELLA_SPECIAL(oINDENTCOUNTERo, int, (2 * depth) + 7);
        printUnformattedLogicalForm(frame->proposition, STANDARD_OUTPUT);
        if (frame->allottedClockTicks != NULL_INTEGER) {
          std::cout << " ticks=" << frame->allottedClockTicks;
        }
      }
    }
  }
  else {
    std::cout << "STRATEGY: " << frame->up->currentStrategy;
  }
}

int computeFrameDepth(ControlFrame* frame) {
  { int depth = 0;
    ControlFrame* cursor = (((boolean)(oQUERYITERATORo.get())) ? oQUERYITERATORo.get()->baseControlFrame : ((ControlFrame*)(NULL)));

    while (((boolean)(cursor))) {
      if (cursor == frame) {
        break;
      }
      cursor = cursor->down;
      depth = depth + 1;
    }
    if (cursor == frame) {
      return (depth);
    }
    else {
      return (NULL_INTEGER);
    }
  }
}

void printVerticalBars(int depth) {
  { IntegerIntervalIterator* i = interval(1, depth);

    for (i; i->nextP(); ) {
      std::cout << "| ";
    }
  }
}

void unwindToChoicePointsBelowFrame(ControlFrame* frame) {
  if (((boolean)(frame))) {
    unwindToChoicePoint(frame);
    unwindToChoicePointsBelowFrame(frame->down);
  }
}

void traceGoalTree(ControlFrame* frame, int depth, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    unwindToChoicePointsBelowFrame(frame);
  }
  if ((frame->state == KWD_QUERY_ITERATIVE_FORALL) &&
      (lastmove == KWD_QUERY_DOWN)) {
    return;
  }
  if (traceKeywordP(KWD_QUERY_STATE_MACHINE)) {
    if (subtypeOfP(safePrimaryType(frame), SGT_QUERY_LOGIC_PARALLEL_CONTROL_FRAME)) {
      { ControlFrame* frame000 = frame;
        ParallelControlFrame* frame = ((ParallelControlFrame*)(frame000));

        std::cout << "P" << debugFrameId(frame);
      }
    }
    else {
      std::cout << "F" << debugFrameId(frame);
    }
    if (frame->choicePointUnbindingOffset != NULL_INTEGER) {
      std::cout << "," << frame->choicePointUnbindingOffset << " ";
    }
    else {
      std::cout << "   ";
    }
    std::cout << ((((frame->truthValue == DEFAULT_TRUE_TRUTH_VALUE) ||
        (frame->truthValue == DEFAULT_FALSE_TRUTH_VALUE)) ? (char*)"D " : (char*)"S "));
  }
  if ((frame->state == KWD_QUERY_PARALLEL_STRATEGIES) ||
      ((frame->state == KWD_QUERY_STRATEGY) &&
       (!((boolean)(frame->currentStrategy))))) {
    return;
  }
  if (!((lastmove == KWD_QUERY_DOWN) &&
      (getQuotedTree("((:ATOMIC-GOAL :STRATEGY) \"/LOGIC\")", "/LOGIC")->memberP(frame->state) &&
       ((((Keyword*)(frame->nextStrategies->value)) == KWD_QUERY_SPECIALIST) &&
        (!traceKeywordP(KWD_QUERY_STRATEGIES)))))) {
    printVerticalBars(depth);
  }
  if (lastmove == KWD_QUERY_DOWN) {
    { Keyword* testValue000 = frame->state;

      if ((testValue000 == KWD_QUERY_ATOMIC_GOAL) ||
          (testValue000 == KWD_QUERY_STRATEGY)) {
        if (((Keyword*)(frame->nextStrategies->value)) == KWD_QUERY_SPECIALIST) {
          {
            if (traceKeywordP(KWD_QUERY_STRATEGIES)) {
              std::cout << "TRY STRATEGIES: ";
            }
            return;
          }
        }
        else {
          {
            printGoalInGoalTree(frame, depth);
            if (traceKeywordP(KWD_QUERY_STRATEGIES)) {
              std::cout << std::endl;
              printVerticalBars(depth);
              std::cout << "STRATEGY: ";
              return;
            }
          }
        }
      }
      else if (testValue000 == KWD_QUERY_PATTERN) {
        if (((boolean)(oTRACED_KEYWORDSo)) &&
            oTRACED_KEYWORDSo->membP(KWD_QUERY_STRATEGIES)) {
          std::cout << std::endl;
        }
        { ControlFrame* upframe = frame->up;

          if (((boolean)(upframe)) &&
              ((boolean)(((Proposition*)(dynamicSlotValue(upframe->dynamicSlots, SYM_QUERY_LOGIC_ANTECEDENTS_RULE, NULL)))))) {
            printRuleInGoalTree(frame, ((Proposition*)(dynamicSlotValue(upframe->dynamicSlots, SYM_QUERY_LOGIC_ANTECEDENTS_RULE, NULL))), depth);
          }
          else {
            {
              if (((boolean)(oQUERYITERATORo.get())) &&
                  ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
                std::cout << std::endl;
              }
              if (((boolean)(frame->patternRecord->collectionList))) {
                std::cout << "COLLECTION: [";
              }
              else {
                std::cout << "PATTERN: [";
              }
              { boolean firsttimeP = true;

                { BooleanWrapper* tv = NULL;
                  BooleanVector* vector000 = frame->patternRecord->booleanVector;
                  int index000 = 0;
                  int length000 = vector000->length();

                  for  (tv, vector000, index000, length000; 
                        index000 < length000; 
                        index000 = index000 + 1) {
                    tv = ((BooleanWrapper*)((vector000->theArray)[index000]));
                    if (firsttimeP) {
                      firsttimeP = false;
                    }
                    else {
                      std::cout << ",";
                    }
                    if (coerceWrappedBooleanToBoolean(tv)) {
                      std::cout << "T";
                    }
                    else {
                      std::cout << "F";
                    }
                  }
                }
              }
              std::cout << "]";
            }
          }
        }
      }
      else {
        printGoalInGoalTree(frame, depth);
      }
    }
  }
  else if (lastmove == KWD_QUERY_UP_TRUE) {
    if (TRUE) {
      std::cout << "| SUCC: ";
      { 
        BIND_STELLA_SPECIAL(oPRINTINFRAMEo, ControlFrame*, frame);
        printVariableBindings(frame);
      }
      { TruthValue* truthvalue = frame->truthValue;

        if (((boolean)(truthvalue))) {
          std::cout << "truth=";
          if ((truthvalue == TRUE_TRUTH_VALUE) ||
              (truthvalue == DEFAULT_TRUE_TRUTH_VALUE)) {
            if ((truthvalue == DEFAULT_TRUE_TRUTH_VALUE) ||
                (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
              std::cout << "t";
            }
            else {
              std::cout << "T";
            }
          }
          else if ((truthvalue == FALSE_TRUTH_VALUE) ||
              (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
            if ((truthvalue == DEFAULT_TRUE_TRUTH_VALUE) ||
                (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
              std::cout << "f";
            }
            else {
              std::cout << "F";
            }
          }
          else if ((truthvalue == UNKNOWN_TRUTH_VALUE) ||
              (!((boolean)(truthvalue)))) {
            std::cout << "U";
          }
          else {
            std::cout << "?";
          }
        }
      }
    }
  }
  else if (lastmove == KWD_QUERY_UP_FAIL) {
    std::cout << "| FAIL";
    { Keyword* testValue001 = frame->state;

      if ((testValue001 == KWD_QUERY_ATOMIC_GOAL) ||
          (testValue001 == KWD_QUERY_STRATEGY)) {
        if (traceKeywordP(KWD_QUERY_STRATEGIES) &&
            (!(frame->nextStrategies == NIL))) {
          std::cout << std::endl;
          printVerticalBars(depth);
          std::cout << "TRY STRATEGIES: ";
          return;
        }
      }
      else {
      }
    }
    { TruthValue* truthvalue = frame->truthValue;

      if (((boolean)(truthvalue)) ||
          ((boolean)(frame->partialMatchFrame))) {
        std::cout << ":";
      }
      if (((boolean)(truthvalue))) {
        std::cout << " truth=";
        if ((truthvalue == TRUE_TRUTH_VALUE) ||
            (truthvalue == DEFAULT_TRUE_TRUTH_VALUE)) {
          if ((truthvalue == DEFAULT_TRUE_TRUTH_VALUE) ||
              (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
            std::cout << "t";
          }
          else {
            std::cout << "T";
          }
        }
        else if ((truthvalue == FALSE_TRUTH_VALUE) ||
            (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
          if ((truthvalue == DEFAULT_TRUE_TRUTH_VALUE) ||
              (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
            std::cout << "f";
          }
          else {
            std::cout << "F";
          }
        }
        else if ((truthvalue == UNKNOWN_TRUTH_VALUE) ||
            (!((boolean)(truthvalue)))) {
          std::cout << "U";
        }
        else {
          std::cout << "?";
        }
      }
    }
  }
  else {
    std::cout << "????: ";
  }
  if (traceKeywordP(KWD_QUERY_STATE_MACHINE)) {
    std::cout << " state= " << frame->state << "  lastMove= " << lastmove << " depth= " << depth << " revPty?= " << frame->reversePolarityP;
  }
  if (!((boolean)(frame->partialMatchFrame))) {
    std::cout << std::endl;
  }
  else {
    std::cout << " ";
    if ((lastmove == KWD_QUERY_DOWN) ||
        ((lastmove == KWD_QUERY_UP_TRUE) ||
         (lastmove == KWD_QUERY_UP_FAIL))) {
      frame->partialMatchFrame->traceFramePartialTruth(lastmove, STANDARD_OUTPUT);
      std::cout << std::endl;
    }
    else {
    }
  }
}

Keyword* oldInterpretAndScores(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    { PartialMatchFrame* pmf = frame->partialMatchFrame;

      if (!((boolean)(pmf))) {
        createAndLinkPartialMatchFrame(frame, KWD_QUERY_AND);
      }
      else {
        {
          while (frame->partialMatchFrame->argumentScores->length() > frame->argumentCursor) {
            frame->partialMatchFrame->popPartialMatchScore();
          }
          pmf->setDynamicCutoff();
        }
      }
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    { PartialMatchFrame* pmf = frame->partialMatchFrame;
      int arity = frame->proposition->arguments->length();
      int i = 0;

      pmf->successP = lastmove == KWD_QUERY_UP_TRUE;
      recordLatestPartialMatchScore(frame);
      if (traceKeywordP(KWD_QUERY_GOAL_TREE)) {
        std::cout << ((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, NULL_FLOAT_WRAPPER)))->wrapperValue << ", " << frame->partialMatchFrame->computeAndScore() << std::endl;
      }
      if (!(pmf->unboundVars == NIL)) {
        setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, wrapFloat(0.0), NULL_FLOAT_WRAPPER);
        for (;;) {
          { boolean testValue000 = false;

            testValue000 = (frame->argumentCursor + 1) < arity;
            if (testValue000) {
              { boolean foundP000 = false;

                { Object* var = NULL;
                  Cons* iter000 = getUnboundVariables(((Proposition*)((frame->proposition->arguments->theArray)[(frame->argumentCursor + 1)])));

                  for (var, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
                    var = iter000->value;
                    if (searchConsTreeP(pmf->unboundVars, var)) {
                      foundP000 = true;
                      break;
                    }
                  }
                }
                testValue000 = foundP000;
              }
            }
            if (!(testValue000)) {
              break;
            }
          }
          i = i + 1;
          frame->argumentCursor = frame->argumentCursor + 1;
          recordLatestPartialMatchScore(frame);
        }
        pmf->unboundVars = NIL;
        if (traceKeywordP(KWD_QUERY_GOAL_TREE)) {
          std::cout << "   *** Skipping " << i << " propositions . . ." << std::endl;
        }
      }
      if (oFAIL_UNBOUND_CLAUSESpo) {
        while (((frame->argumentCursor + 1) < arity) &&
            allVariablesUnboundP(((Proposition*)((frame->proposition->arguments->theArray)[(frame->argumentCursor + 1)])))) {
          i = i + 1;
          frame->argumentCursor = frame->argumentCursor + 1;
          setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, wrapFloat(0.0), NULL_FLOAT_WRAPPER);
          recordLatestPartialMatchScore(frame);
        }
        if ((i > 0) &&
            traceKeywordP(KWD_QUERY_GOAL_TREE)) {
          std::cout << "   *** Skipping " << i << " propositions . . ." << std::endl;
        }
      }
      if (computePartialMatchAndFailureP(frame)) {
        lastmove = KWD_QUERY_UP_FAIL;
      }
      else if (((frame->argumentCursor + 1) == arity) &&
          (!computePartialMatchScoreP(frame))) {
        lastmove = KWD_QUERY_UP_FAIL;
      }
      else {
        lastmove = KWD_QUERY_UP_TRUE;
      }
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  if ((lastmove == KWD_QUERY_UP_FAIL) &&
      ((boolean)(frame->down))) {
    frame->down = NULL;
  }
  return (lastmove);
}

Keyword* ControlFrame::continuePartialAndProof(ControlFrame* frame, Keyword* lastmove) {
  { ControlFrame* self = this;

    { PartialMatchFrame* pmf = self->partialMatchFrame;

      if (!((boolean)(pmf))) {
        createAndLinkPartialMatchFrame(self, KWD_QUERY_AND);
      }
      return (self->partialMatchFrame->continuePartialAndProof(frame, lastmove));
    }
  }
}

Keyword* interpretIterativeForallScores(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    if (!((boolean)(frame->partialMatchFrame))) {
      createAndLinkPartialMatchFrame(frame, KWD_QUERY_ITERATIVE_FORALL);
    }
    else {
      while (frame->partialMatchFrame->argumentScores->length() > frame->argumentCursor) {
        frame->partialMatchFrame->popPartialMatchScore();
      }
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    recordLatestPartialMatchScore(frame);
    if (traceKeywordP(KWD_QUERY_GOAL_TREE)) {
      std::cout << "ITERATIVE-FORALL " << ((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, NULL_FLOAT_WRAPPER)))->wrapperValue << std::endl;
    }
    if (((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, NULL_FLOAT_WRAPPER)))->wrapperValue < 0.9) {
      lastmove = KWD_QUERY_UP_FAIL;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (lastmove);
}

Keyword* oldInterpretOrScores(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    { PartialMatchFrame* pmf = frame->partialMatchFrame;

      if (!((boolean)(pmf))) {
        createAndLinkPartialMatchFrame(frame, KWD_QUERY_OR);
      }
      else {
        {
          while (frame->partialMatchFrame->argumentScores->length() > frame->argumentCursor) {
            frame->partialMatchFrame->popPartialMatchScore();
          }
          pmf->setDynamicCutoff();
        }
      }
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    recordLatestPartialMatchScore(frame);
    if (traceKeywordP(KWD_QUERY_GOAL_TREE)) {
      std::cout << ((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, NULL_FLOAT_WRAPPER)))->wrapperValue << ", " << frame->partialMatchFrame->computeOrScore() << std::endl;
    }
    if (computePartialMatchOrSuccessP(frame)) {
      lastmove = KWD_QUERY_UP_TRUE;
    }
    else if (((frame->argumentCursor + 1) == frame->proposition->arguments->length()) &&
        computePartialMatchScoreP(frame)) {
      lastmove = KWD_QUERY_UP_TRUE;
    }
    else {
      lastmove = KWD_QUERY_UP_FAIL;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (lastmove);
}

Keyword* ControlFrame::continuePartialOrProof(Keyword* lastmove) {
  { ControlFrame* self = this;

    { PartialMatchFrame* pmf = self->partialMatchFrame;

      if (!((boolean)(pmf))) {
        createAndLinkPartialMatchFrame(self, KWD_QUERY_OR);
      }
      return (self->partialMatchFrame->continuePartialOrProof(lastmove));
    }
  }
}

Keyword* oldInterpretFailScore(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, wrapFloat(0.0), NULL_FLOAT_WRAPPER);
    if (!((boolean)(frame->partialMatchFrame))) {
      createAndLinkPartialMatchFrame(frame, KWD_QUERY_NOT);
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    recordLatestPartialMatchScore(frame);
    if (computePartialMatchScoreP(frame)) {
      lastmove = KWD_QUERY_UP_TRUE;
    }
    else {
      lastmove = KWD_QUERY_UP_FAIL;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (lastmove);
}

Keyword* ControlFrame::continuePartialNotProof(Keyword* lastmove) {
  { ControlFrame* self = this;

    { PartialMatchFrame* pmf = self->partialMatchFrame;

      if (!((boolean)(pmf))) {
        createAndLinkPartialMatchFrame(self, KWD_QUERY_NOT);
      }
      return (self->partialMatchFrame->continuePartialNotProof(lastmove));
    }
  }
}

Keyword* oldInterpretGoalScores(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    { PartialMatchFrame* pmf = frame->partialMatchFrame;

      if (!((boolean)(pmf))) {
        createAndLinkPartialMatchFrame(frame, KWD_QUERY_ATOMIC_GOAL);
      }
      else {
        pmf->setDynamicCutoff();
      }
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    if (traceKeywordP(KWD_QUERY_GOAL_TREE)) {
      std::cout << ((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, NULL_FLOAT_WRAPPER)))->wrapperValue << std::endl;
    }
    if ((frame->currentStrategy == KWD_QUERY_FULL_SUBQUERY) ||
        (frame->currentStrategy == KWD_QUERY_ANTECEDENTS)) {
      recordLatestPartialMatchScore(frame);
      if (computePartialMatchOrSuccessP(frame) &&
          (!unboundVariablesInFrameP(frame))) {
        lastmove = KWD_QUERY_UP_TRUE;
      }
      else if (((Iterator*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_STELLA_ITERATOR, NULL)))->emptyP() &&
          ((!unboundVariablesInFrameP(frame)) &&
           computePartialMatchScoreP(frame))) {
        lastmove = KWD_QUERY_UP_TRUE;
      }
      else {
        lastmove = KWD_QUERY_UP_FAIL;
      }
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  attachSupport(frame, lastmove);
  if ((lastmove == KWD_QUERY_UP_FAIL) &&
      ((boolean)(frame->down))) {
    frame->down = NULL;
  }
  { Keyword* result = continueStrategiesProofs(frame, lastmove);

    if ((result == KWD_QUERY_FAILURE) &&
        computePartialMatchScoreP(frame)) {
      lastmove = KWD_QUERY_UP_TRUE;
      return (KWD_QUERY_FINAL_SUCCESS);
    }
    else {
      return (result);
    }
  }
}

void attachSupport(ControlFrame* frame, Keyword* lastmove) {
  if ((!(lastmove == KWD_QUERY_DOWN)) &&
      ((frame->currentStrategy == KWD_QUERY_ANTECEDENTS) &&
       (isaP(frame->partialMatchFrame, SGT_QUERY_LOGIC_NN_PARTIAL_MATCH) &&
        (!(!((boolean)(frame->partialMatchFrame->child))))))) {
    { NnPartialMatch* pmf = ((NnPartialMatch*)(frame->partialMatchFrame));
      PartialSupport* support = newPartialSupport();

      support->id = oPARTIAL_SUPPORT_COUNTERo = oPARTIAL_SUPPORT_COUNTERo + 1;
      support->axiom = ((Proposition*)(pmf->rules->value));
      support->fact = ((NnPartialMatch*)(pmf->child))->controlFrame->proposition;
      support->argumentScores = copyConsList(((NnPartialMatch*)(pmf->child))->argumentScores)->reverse();
      support->score = ((FloatWrapper*)(dynamicSlotValue(support->fact->dynamicSlots, SYM_QUERY_LOGIC_MATCH_SCORE, NULL_FLOAT_WRAPPER)))->wrapperValue;
      if (((boolean)(frame->proposition->support_reader()))) {
        setDynamicSlotValue(frame->proposition->dynamicSlots, SYM_QUERY_LOGIC_SUPPORT, cons(support, frame->proposition->support_reader()), NULL);
      }
      else {
        setDynamicSlotValue(frame->proposition->dynamicSlots, SYM_QUERY_LOGIC_SUPPORT, consList(1, support), NULL);
      }
    }
  }
  else {
    setDynamicSlotValue(frame->proposition->dynamicSlots, SYM_QUERY_LOGIC_SUPPORT, NULL, NULL);
  }
}

Keyword* ControlFrame::continuePartialStrategiesProofs(Keyword* lastmove) {
  { ControlFrame* self = this;

    if (self->currentStrategy == KWD_QUERY_FULL_SUBQUERY) {
      return (continueStrategiesProofs(self, lastmove));
    }
    { PartialMatchFrame* pmf = self->partialMatchFrame;

      if (!((boolean)(pmf))) {
        createAndLinkPartialMatchFrame(self, KWD_QUERY_ATOMIC_GOAL);
      }
      return (self->partialMatchFrame->continuePartialStrategiesProofs(lastmove));
    }
  }
}

PatternRecord* operativePatternRecord(ControlFrame* frame) {
  return ((((boolean)(frame->patternRecord)) ? frame->patternRecord : frame->inheritedPatternRecord));
}

ControlFrame* createDownFrame(ControlFrame* upframe, Proposition* downproposition) {
  { ControlFrame* downframe = newControlFrame();

    upframe->down = downframe;
    downframe->up = upframe;
    downframe->reversePolarityP = upframe->reversePolarityP;
    downframe->proposition = downproposition;
    downframe->down = NULL;
    setDynamicSlotValue(downframe->dynamicSlots, SYM_QUERY_LOGIC_BACK, NULL, NULL);
    downframe->patternRecord = NULL;
    downframe->truthValue = NULL;
    downframe->justifications->clear();
    setDynamicSlotValue(downframe->dynamicSlots, SYM_QUERY_LOGIC_JUSTIFICATION, NULL, NULL);
    setDynamicSlotValue(downframe->dynamicSlots, SYM_QUERY_LOGIC_GOAL_CACHE, NULL, NULL);
    downframe->goalBindings = NULL;
    setDynamicSlotValue(downframe->dynamicSlots, SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR, NULL, NULL);
    if (((boolean)(downproposition))) {
      downframe->state = downproposition->kind;
      if (downframe->reversePolarityP) {
        { Keyword* testValue000 = downframe->state;

          if (testValue000 == KWD_QUERY_AND) {
            downframe->state = KWD_QUERY_OR;
          }
          else if (testValue000 == KWD_QUERY_OR) {
            downframe->state = KWD_QUERY_AND;
          }
          else {
          }
        }
      }
      downframe->argumentCursor = 0;
    }
    downframe->inheritedPatternRecord = operativePatternRecord(upframe);
    return (downframe);
  }
}

TruthValue* setFrameTruthValue(ControlFrame* frame, TruthValue* truthvalue) {
  return (frame->truthValue = (frame->reversePolarityP ? invertTruthValue(truthvalue) : truthvalue));
}

TruthValue* propagateFrameTruthValue(ControlFrame* source, ControlFrame* target) {
  return (target->truthValue = ((!(source->reversePolarityP == target->reversePolarityP)) ? invertTruthValue(source->truthValue) : source->truthValue));
}

// Generates unique IDs for control frames.  Used only for debugging.
int oCONTROL_FRAME_ID_COUNTERo = -1;

int debugFrameId(ControlFrame* frame) {
  { int id = ((IntegerWrapper*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_DEBUG_FRAME_ID_INTERNAL, NULL_INTEGER_WRAPPER)))->wrapperValue;

    if (id == NULL_INTEGER) {
      oCONTROL_FRAME_ID_COUNTERo = oCONTROL_FRAME_ID_COUNTERo + 1;
      id = oCONTROL_FRAME_ID_COUNTERo;
      setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_DEBUG_FRAME_ID_INTERNAL, wrapInteger(id), NULL_INTEGER_WRAPPER);
    }
    return (id);
  }
}

void copyFrameState(ControlFrame* fromframe, ControlFrame* toframe) {
  toframe->proposition = fromframe->proposition;
  setDynamicSlotValue(toframe->dynamicSlots, SYM_QUERY_LOGIC_DESCRIPTION, ((Description*)(dynamicSlotValue(fromframe->dynamicSlots, SYM_QUERY_LOGIC_DESCRIPTION, NULL))), NULL);
  toframe->reversePolarityP = fromframe->reversePolarityP;
  toframe->up = fromframe->up;
  toframe->partialMatchFrame = fromframe->partialMatchFrame;
  toframe->inheritedPatternRecord = fromframe->inheritedPatternRecord;
  toframe->choicePointUnbindingOffset = fromframe->choicePointUnbindingOffset;
  toframe->nextStrategies = fromframe->nextStrategies;
  setDynamicSlotValue(toframe->dynamicSlots, SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR, ((Iterator*)(dynamicSlotValue(fromframe->dynamicSlots, SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR, NULL))), NULL);
  toframe->goalBindings = fromframe->goalBindings;
  setDynamicSlotValue(toframe->dynamicSlots, SYM_QUERY_LOGIC_GOAL_CACHE, ((GoalCache*)(dynamicSlotValue(fromframe->dynamicSlots, SYM_QUERY_LOGIC_GOAL_CACHE, NULL))), NULL);
}

ParallelControlFrame* parallelizeControlFrame(ControlFrame* frame) {
  if (frame->state == KWD_QUERY_PARALLEL_STRATEGIES) {
    return (((ParallelControlFrame*)(frame)));
  }
  { ParallelControlFrame* parallelparent = newParallelControlFrame();

    parallelparent->state = KWD_QUERY_PARALLEL_STRATEGIES;
    copyFrameState(frame, parallelparent);
    frame->up->down = parallelparent;
    frame->nextStrategies = NIL;
    setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR, NULL, NULL);
    setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_GOAL_CACHE, NULL, NULL);
    parallelparent->unboundVariablesP = !allArgumentsBoundP(parallelparent->proposition);
    if (((boolean)(frame->down)) ||
        ((boolean)(((Iterator*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_STELLA_ITERATOR, NULL)))))) {
      { ParallelThread* childthread = newParallelThread();

        frame->up = parallelparent;
        childthread->topControlFrame = frame;
        parallelparent->childThreads->insert(childthread);
        if (parallelparent->unboundVariablesP) {
          { PatternRecord* patternrecord = frame->inheritedPatternRecord;

            childthread->variableBindings = patternrecord->variableBindings->copy();
            childthread->unbindingStack = ((IntegerVector*)(patternrecord->unbindingStack->copy()));
            childthread->topUnbindingStackOffset = patternrecord->topUnbindingStackOffset;
          }
        }
      }
    }
    if (oQUERYITERATORo.get()->currentControlFrame == frame) {
      oQUERYITERATORo.get()->currentControlFrame = parallelparent;
    }
    return (parallelparent);
  }
}

void enterParallelThread(ParallelControlFrame* pframe, ParallelThread* childthread) {
  if (((boolean)(childthread))) {
    {
      pframe->currentChildThread = childthread;
      pframe->down = childthread->topControlFrame;
    }
  }
  else {
    childthread = pframe->currentChildThread;
  }
  pframe->savedParentParallelThread = oQUERYITERATORo.get()->currentParallelThread;
  oQUERYITERATORo.get()->currentParallelThread = childthread;
  pframe->savedParentContext = oCONTEXTo.get();
  if (((boolean)(childthread->hypotheticalWorld))) {
    childthread->hypotheticalWorld->changeContext();
  }
}

void exitParallelThread(ParallelControlFrame* pframe) {
  oQUERYITERATORo.get()->currentParallelThread = pframe->savedParentParallelThread;
  if (((boolean)(pframe->savedParentContext))) {
    if ((!((boolean)(pframe->down))) &&
        ((boolean)(pframe->currentChildThread->hypotheticalWorld))) {
      {
        popWorld();
      }
    }
    else {
      pframe->savedParentContext->changeContext();
    }
    pframe->savedParentContext = NULL;
  }
  if (!((boolean)(pframe->down))) {
    pframe->childThreads->remove(pframe->currentChildThread);
    pframe->currentChildThread = NULL;
  }
}

World* enterHypotheticalWorld(ParallelControlFrame* pframe) {
  { ParallelThread* childthread = pframe->currentChildThread;
    World* world = childthread->hypotheticalWorld;

    if (!((boolean)(world))) {
      {
        childthread->hypotheticalWorld = pushMonotonicWorld();
        initializeInferenceWorld(((World*)(oCONTEXTo.get())));
      }
    }
    else {
    }
    return (world);
  }
}

boolean partialMatchModeP() {
  return (((boolean)(oQUERYITERATORo.get())) &&
      ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)));
}

boolean executeBackwardChainingProofP(QueryIterator* query) {
  if (!((boolean)(query->baseControlFrame->down))) {
    return (false);
  }
  { 
    BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, query);
    { ControlFrame* frame = query->baseControlFrame;
      int depth = 0;
      Keyword* lastmove = KWD_QUERY_DOWN;
      Keyword* resultofnextmove = NULL;
      int clockticks = query->currentClockTicks;
      clock_t starttime = getTicktock();
      int startticks = clockticks;
      double allottedtime = query->allottedTime;
      int allottedticks = query->allottedClockTicks;
      boolean checkfortimeoutP = allottedtime != NULL_FLOAT;
      boolean checkformoveoutP = allottedticks != NULL_INTEGER;
      boolean tracesubgoalsP = traceKeywordP(KWD_QUERY_GOAL_TREE);
      boolean timeoutP = false;
      boolean successP = false;

      query->timeoutP = false;
      frame->startingClockTicks = clockticks;
      if (checkformoveoutP) {
        frame->allottedClockTicks = allottedticks;
      }
      frame->truthValue = NULL;
      setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_JUSTIFICATION, NULL, NULL);
      if (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
        frame->partialMatchFrame = query->partialMatchStrategy;
        frame->partialMatchFrame->clearFramePartialTruth();
      }
      lastmove = KWD_QUERY_DOWN;
      for (;;) {
        query->currentControlFrame = frame;
        if (tracesubgoalsP) {
          if ((lastmove == KWD_QUERY_UP_TRUE) ||
              (lastmove == KWD_QUERY_UP_FAIL)) {
            traceGoalTree(frame->result, depth, lastmove);
          }
          else {
            traceGoalTree(frame, depth, lastmove);
          }
        }
        if (checkfortimeoutP &&
            ((clockticks & 15) == 0)) {
          { clock_t currenttime = getTicktock();
            double difference = ticktockDifference(starttime, currenttime);

            if (difference >= 0.02) {
              allottedtime = allottedtime - difference;
              starttime = currenttime;
            }
            if (allottedtime <= 0.0) {
              timeoutP = true;
            }
          }
        }
        resultofnextmove = evaluateNextMove(frame, lastmove, clockticks);
        frame = query->currentControlFrame;
        if (resultofnextmove == KWD_QUERY_MOVE_DOWN) {
          { ControlFrame* upframe = frame;
            ControlFrame* downframe = frame->down;

            depth = depth + 1;
            query->currentClockTicks = clockticks = clockticks + 1;
            if (((boolean)(downframe))) {
              frame = downframe;
              frame->startingClockTicks = clockticks;
              if (checkformoveoutP &&
                  (frame->allottedClockTicks == NULL_INTEGER)) {
                frame->allottedClockTicks = upframe->allottedClockTicks - 1;
              }
              frame->truthValue = NULL;
              setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_JUSTIFICATION, NULL, NULL);
              if (((boolean)(frame->partialMatchFrame))) {
                frame->partialMatchFrame->clearFramePartialTruth();
              }
              lastmove = KWD_QUERY_DOWN;
            }
            else {
              { Object* proposition = (upframe->proposition->arguments->theArray)[(upframe->argumentCursor)];

                downframe = createDownFrame(upframe, ((Proposition*)(proposition)));
                frame = downframe;
                frame->startingClockTicks = clockticks;
                if (checkformoveoutP) {
                  frame->allottedClockTicks = upframe->allottedClockTicks - 1;
                }
                lastmove = KWD_QUERY_DOWN;
              }
            }
            if ((depth > query->currentDepthCutoff) &&
                (upframe->state == KWD_QUERY_PATTERN)) {
              popFramesUpTo(frame);
              frame = handleDepthViolation(frame, depth, depth);
              lastmove = KWD_QUERY_UP_FAIL;
            }
            if (checkformoveoutP) {
              if ((frame->allottedClockTicks <= 0) &&
                  (!(lastmove == KWD_QUERY_UP_FAIL))) {
                popFramesUpTo(frame);
                frame = handleTimeout(frame, depth, depth);
                lastmove = KWD_QUERY_UP_FAIL;
              }
              if (lastmove == KWD_QUERY_UP_FAIL) {
                frame->allottedClockTicks = frame->allottedClockTicks - ((clockticks - downframe->startingClockTicks) + 1);
              }
            }
          }
          if (timeoutP &&
              (lastmove == KWD_QUERY_DOWN)) {
            successP = false;
            break;
          }
        }
        else if (resultofnextmove == KWD_QUERY_FINAL_SUCCESS) {
          { ControlFrame* parent = frame->up;

            if (((boolean)(parent))) {
              parent->result = frame;
              if ((oCACHE_SUCCEEDED_GOALSpo ||
                  oCACHE_FAILED_GOALSpo) &&
                  ((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) &&
                   (!(((boolean)(oQUERYITERATORo.get())) &&
                  ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)))))) {
                cacheGoal(frame, true, false, clockticks);
              }
              else {
                updateGoalCache(frame, true);
              }
            }
            depth = depth - 1;
            if (checkformoveoutP) {
              frame->allottedClockTicks = NULL_INTEGER;
              if (((boolean)(parent))) {
                parent->allottedClockTicks = (parent->allottedClockTicks - (clockticks - frame->startingClockTicks)) - 1;
              }
            }
            frame = parent;
            if (!((boolean)(frame))) {
              successP = true;
              break;
            }
            popDownFrame(frame);
            lastmove = KWD_QUERY_UP_TRUE;
          }
        }
        else if (resultofnextmove == KWD_QUERY_CONTINUING_SUCCESS) {
          { ControlFrame* parent = frame->up;

            if (((boolean)(parent))) {
              parent->result = frame;
              if ((oCACHE_SUCCEEDED_GOALSpo ||
                  oCACHE_FAILED_GOALSpo) &&
                  ((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) &&
                   (!(((boolean)(oQUERYITERATORo.get())) &&
                  ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)))))) {
                cacheGoal(frame, true, true, clockticks);
              }
              else {
                updateGoalCache(frame, true);
              }
            }
            depth = depth - 1;
            if (checkformoveoutP) {
              frame->allottedClockTicks = NULL_INTEGER;
              if (((boolean)(parent))) {
                parent->allottedClockTicks = (parent->allottedClockTicks - (clockticks - frame->startingClockTicks)) - 1;
              }
            }
            frame = parent;
            if (!((boolean)(frame))) {
              successP = true;
              break;
            }
            lastmove = KWD_QUERY_UP_TRUE;
          }
        }
        else if (resultofnextmove == KWD_QUERY_FAILURE) {
          { ControlFrame* parent = frame->up;

            if (((boolean)(parent))) {
              parent->result = frame;
              if ((oCACHE_SUCCEEDED_GOALSpo ||
                  oCACHE_FAILED_GOALSpo) &&
                  ((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) &&
                   (!(((boolean)(oQUERYITERATORo.get())) &&
                  ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)))))) {
                cacheGoal(frame, false, false, clockticks);
              }
              else {
                updateGoalCache(frame, false);
              }
            }
            depth = depth - 1;
            if (checkformoveoutP) {
              frame->allottedClockTicks = NULL_INTEGER;
              if (((boolean)(parent))) {
                parent->allottedClockTicks = (parent->allottedClockTicks - (clockticks - frame->startingClockTicks)) - 1;
              }
            }
            frame = parent;
            if (!((boolean)(frame))) {
              successP = false;
              break;
            }
            popDownFrame(frame);
            lastmove = KWD_QUERY_UP_FAIL;
          }
        }
        else if (resultofnextmove == KWD_QUERY_MOVE_IN_PLACE) {
          {
            frame->truthValue = NULL;
            setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_JUSTIFICATION, NULL, NULL);
            if (((boolean)(frame->partialMatchFrame))) {
              frame->partialMatchFrame->clearFramePartialTruth();
            }
            lastmove = KWD_QUERY_DOWN;
            if (checkformoveoutP) {
              { ControlFrame* parent = frame->up;
                int startticks = frame->startingClockTicks;
                int availableticks = (parent->allottedClockTicks - (clockticks - startticks)) - 1;

                parent->allottedClockTicks = availableticks;
                availableticks = availableticks - 1;
                frame->allottedClockTicks = availableticks;
                query->currentClockTicks = clockticks = clockticks + 1;
                frame->startingClockTicks = clockticks;
                if (availableticks <= 0) {
                  popFramesUpTo(frame);
                  frame = handleTimeout(frame, depth, depth);
                  lastmove = KWD_QUERY_UP_FAIL;
                  frame->allottedClockTicks = frame->allottedClockTicks - ((clockticks - startticks) + 1);
                }
              }
            }
            else {
              query->currentClockTicks = clockticks = clockticks + 1;
              frame->startingClockTicks = clockticks;
            }
          }
        }
        else if (resultofnextmove == KWD_QUERY_TIMEOUT) {
          { ControlFrame* parent = frame->up;

            if (((boolean)(parent))) {
              parent->result = frame;
              if ((oCACHE_SUCCEEDED_GOALSpo ||
                  oCACHE_FAILED_GOALSpo) &&
                  ((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) &&
                   (!(((boolean)(oQUERYITERATORo.get())) &&
                  ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)))))) {
                cacheGoal(frame, false, true, clockticks);
              }
              else {
                updateGoalCache(frame, false);
              }
            }
            depth = depth - 1;
            if (checkformoveoutP) {
              frame->allottedClockTicks = NULL_INTEGER;
              if (((boolean)(parent))) {
                parent->allottedClockTicks = (parent->allottedClockTicks - (clockticks - frame->startingClockTicks)) - 1;
              }
            }
            frame = parent;
            if (!((boolean)(frame))) {
              successP = false;
              break;
            }
            lastmove = KWD_QUERY_UP_FAIL;
          }
        }
        else {
          { OutputStringStream* stream000 = newOutputStringStream();

            *(stream000->nativeStream) << "`" << resultofnextmove << "'" << " is not a valid case option";
            throw *newStellaException(stream000->theStringReader());
          }
        }
      }
      query->allottedTime = allottedtime;
      query->timeoutP = timeoutP;
      if (checkformoveoutP) {
        query->allottedClockTicks = stella::max(allottedticks - (clockticks - startticks), 0);
        if (!(timeoutP)) {
          query->timeoutP = query->allottedClockTicks == 0;
        }
      }
      return (successP);
    }
  }
}

Keyword* evaluateNextMove(ControlFrame* frame, Keyword* lastmove, int clockticks) {
  { Keyword* testValue000 = frame->state;

    if (testValue000 == KWD_QUERY_AND) {
      if (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
        return (frame->continuePartialAndProof(frame, lastmove));
      }
      else {
        return (continueAndProof(frame, lastmove));
      }
    }
    else if (testValue000 == KWD_QUERY_OR) {
      if (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
        return (frame->continuePartialOrProof(lastmove));
      }
      else {
        return (continueOrProof(frame, lastmove));
      }
    }
    else if (testValue000 == KWD_QUERY_NOT) {
      if (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
        return (frame->continuePartialNotProof(lastmove));
      }
      else {
        return (continueNotProof(frame, lastmove));
      }
    }
    else if ((testValue000 == KWD_QUERY_ISA) ||
        ((testValue000 == KWD_QUERY_FUNCTION) ||
         ((testValue000 == KWD_QUERY_PREDICATE) ||
          ((testValue000 == KWD_QUERY_EQUIVALENT) ||
           (testValue000 == KWD_QUERY_IMPLIES))))) {
      createChoicePoint(frame);
      return (initiateAtomicGoalProofs(frame));
    }
    else if ((testValue000 == KWD_QUERY_ATOMIC_GOAL) ||
        (testValue000 == KWD_QUERY_STRATEGY)) {
      if (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
        return (frame->continuePartialStrategiesProofs(lastmove));
      }
      else {
        return (continueStrategiesProofs(frame, lastmove));
      }
    }
    else if (testValue000 == KWD_QUERY_SCAN_CACHED_BINDINGS) {
      return (continueCachedBindingsProof(frame, lastmove));
    }
    else if (testValue000 == KWD_QUERY_PATTERN) {
      return (continuePatternProof(frame, lastmove));
    }
    else if (testValue000 == KWD_QUERY_FORALL) {
      return (continueForallProof(frame, lastmove));
    }
    else if ((testValue000 == KWD_QUERY_CONTAINED_BY) ||
        (testValue000 == KWD_QUERY_ITERATIVE_FORALL)) {
      if (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
        lastmove = interpretIterativeForallScores(frame, lastmove);
      }
      return (continueContainedByProof(frame, lastmove));
    }
    else if (testValue000 == KWD_QUERY_EXISTS) {
      return (continueExistsProof(frame, lastmove));
    }
    else if (testValue000 == KWD_QUERY_CONSTANT) {
      return (continueConstantProof(frame, lastmove));
    }
    else if (testValue000 == KWD_QUERY_FAIL) {
      if (((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
        return (frame->continuePartialFailProof(lastmove));
      }
      else {
        return (continueFailProof(frame, lastmove));
      }
    }
    else if (testValue000 == KWD_QUERY_PARALLEL_STRATEGIES) {
      return (continueParallelStrategiesProofs(((ParallelControlFrame*)(frame)), lastmove));
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Error.  No query state implemented for operator " << "`" << frame->state << "'" << std::endl;
        throw *newFailException(stream000->theStringReader());
      }
    }
  }
}

boolean Proposition::clusteredConjunctionP() {
  { Proposition* self = this;

    { boolean foundP000 = false;

      { Object* conjunct = NULL;
        Vector* vector000 = self->arguments;
        int index000 = 0;
        int length000 = vector000->length();

        for  (conjunct, vector000, index000, length000; 
              index000 < length000; 
              index000 = index000 + 1) {
          conjunct = (vector000->theArray)[index000];
          if (((Proposition*)(conjunct))->kind == KWD_QUERY_AND) {
            foundP000 = true;
            break;
          }
        }
      }
      { boolean value000 = foundP000;

        return (value000);
      }
    }
  }
}

Keyword* continueAndProof(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;
    Vector* conjuncts = NULL;

    if (lastmove == KWD_QUERY_DOWN) {
      if (proposition->clusteredConjunctionP()) {
        overlayWithStrategyFrame(frame, KWD_QUERY_CLUSTERED_CONJUNCTION);
        return (KWD_QUERY_MOVE_IN_PLACE);
      }
      else if (frame->reversePolarityP &&
          closedPropositionP(proposition)) {
        return (overlayWithFailFrame(frame, proposition));
      }
      else {
        conjuncts = ((Vector*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_STELLA_ARGUMENTS, NULL)));
        if (!((boolean)(conjuncts))) {
          conjuncts = newVector(proposition->arguments->length());
          setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_STELLA_ARGUMENTS, conjuncts, NULL);
          if (dynamicallyOptimizePropositionP(proposition)) {
            proposition = shallowCopyProposition(proposition);
            frame->proposition = proposition;
          }
        }
        if (dynamicallyOptimizePropositionP(proposition) &&
            (!((boolean)(frame->down)))) {
          dynamicallyReoptimizeArguments(proposition->arguments, frame->argumentCursor);
        }
        return (KWD_QUERY_MOVE_DOWN);
      }
    }
    else if (lastmove == KWD_QUERY_UP_TRUE) {
      conjuncts = ((Vector*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_STELLA_ARGUMENTS, NULL)));
      (conjuncts->theArray)[(frame->argumentCursor)] = (frame->result);
      if (frame->argumentCursor == (conjuncts->length() - 1)) {
        frame->down = NULL;
        { ControlFrame* conjunct = NULL;
          Vector* vector000 = conjuncts;
          int index000 = 0;
          int length000 = vector000->length();
          int i = NULL_INTEGER;
          int iter000 = 0;

          for  (conjunct, vector000, index000, length000, i, iter000; 
                index000 < length000; 
                index000 = index000 + 1,
                iter000 = iter000 + 1) {
            conjunct = ((ControlFrame*)((vector000->theArray)[index000]));
            i = iter000;
            frame->truthValue = ((i == 0) ? conjunct->truthValue : conjoinTruthValues(frame->truthValue, conjunct->truthValue));
            if (!(conjunct->state == KWD_QUERY_POPPED)) {
              frame->argumentCursor = i;
              frame->down = conjunct;
            }
          }
        }
        if (oRECORD_JUSTIFICATIONSpo.get()) {
          recordAndIntroductionJustification(frame, lastmove);
        }
        if (((boolean)(frame->down))) {
          return (KWD_QUERY_CONTINUING_SUCCESS);
        }
        else {
          return (KWD_QUERY_FINAL_SUCCESS);
        }
      }
      else {
        frame->down = NULL;
        frame->argumentCursor = frame->argumentCursor + 1;
        if (dynamicallyOptimizePropositionP(proposition)) {
          dynamicallyReoptimizeArguments(proposition->arguments, frame->argumentCursor);
        }
        return (KWD_QUERY_MOVE_DOWN);
      }
    }
    else if (lastmove == KWD_QUERY_UP_FAIL) {
      conjuncts = ((Vector*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_STELLA_ARGUMENTS, NULL)));
      if (!((boolean)(conjuncts))) {
        frame->truthValue = conjoinTruthValues(UNKNOWN_TRUTH_VALUE, frame->result->truthValue);
        return (KWD_QUERY_FAILURE);
      }
      frame->down = NULL;
      { ControlFrame* conjunct = NULL;
        Vector* vector001 = conjuncts;
        int index001 = 0;
        int length001 = vector001->length();
        int i = NULL_INTEGER;
        int iter001 = 0;

        for  (conjunct, vector001, index001, length001, i, iter001; 
              index001 < length001; 
              index001 = index001 + 1,
              iter001 = iter001 + 1) {
          conjunct = ((ControlFrame*)((vector001->theArray)[index001]));
          i = iter001;
          if (!((boolean)(conjunct))) {
            break;
          }
          if (!(conjunct->state == KWD_QUERY_POPPED)) {
            frame->argumentCursor = i;
            frame->down = conjunct;
          }
        }
      }
      if (((boolean)(frame->down))) {
        return (KWD_QUERY_MOVE_DOWN);
      }
      else {
        propagateFrameTruthValue(frame->result, frame);
        (conjuncts->theArray)[(frame->argumentCursor)] = (frame->result);
        { ControlFrame* conjunct = NULL;
          Vector* vector002 = conjuncts;
          int index002 = 0;
          int length002 = vector002->length();
          int i = NULL_INTEGER;
          int iter002 = 0;
          int upperBound000 = frame->argumentCursor;
          boolean unboundedP000 = upperBound000 == NULL_INTEGER;

          for  (conjunct, vector002, index002, length002, i, iter002, upperBound000, unboundedP000; 
                (index002 < length002) &&
                    (unboundedP000 ||
                     (iter002 <= upperBound000)); 
                index002 = index002 + 1,
                iter002 = iter002 + 1) {
            conjunct = ((ControlFrame*)((vector002->theArray)[index002]));
            i = iter002;
            i = i;
            if (!((boolean)(conjunct))) {
              break;
            }
            frame->truthValue = conjoinTruthValues(frame->truthValue, conjunct->truthValue);
          }
        }
        return (KWD_QUERY_FAILURE);
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Keyword* continueOrProof(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;

    if (lastmove == KWD_QUERY_DOWN) {
      if (frame->reversePolarityP &&
          closedPropositionP(proposition)) {
        return (overlayWithFailFrame(frame, proposition));
      }
      createChoicePoint(frame);
      return (KWD_QUERY_MOVE_DOWN);
    }
    else if (lastmove == KWD_QUERY_UP_TRUE) {
      frame->truthValue = frame->result->truthValue;
      if (oRECORD_JUSTIFICATIONSpo.get()) {
        recordOrIntroductionJustification(frame, lastmove);
      }
      if (!((boolean)(frame->down))) {
        frame->argumentCursor = frame->argumentCursor + 1;
      }
      if ((frame->argumentCursor >= proposition->arguments->length()) ||
          ((!newBindingsSinceLastChoicePointP(frame)) &&
           (!oGENERATE_ALL_PROOFSpo.get()))) {
        if (((boolean)(frame->down))) {
          popFramesUpTo(frame->down);
        }
        return (KWD_QUERY_FINAL_SUCCESS);
      }
      else {
        return (KWD_QUERY_CONTINUING_SUCCESS);
      }
    }
    else if (lastmove == KWD_QUERY_UP_FAIL) {
      { TruthValue* chooseValue000 = NULL;

        if (!((boolean)(frame->truthValue))) {
          { TruthValue* temp000 = frame->result->truthValue;

            chooseValue000 = (((boolean)(temp000)) ? temp000 : UNKNOWN_TRUTH_VALUE);
          }
        }
        else {
          chooseValue000 = disjoinTruthValues(frame->truthValue, frame->result->truthValue);
        }
        frame->truthValue = chooseValue000;
      }
      frame->argumentCursor = frame->argumentCursor + 1;
      if (frame->argumentCursor < proposition->arguments->length()) {
        {
          createChoicePoint(frame);
          return (KWD_QUERY_MOVE_DOWN);
        }
      }
      else {
        if (currentInferenceLevel()->keyword == KWD_QUERY_REFUTATION) {
          overlayWithStrategyFrame(frame, KWD_QUERY_DISJUNCTIVE_IMPLICATION_INTRODUCTION);
          return (KWD_QUERY_MOVE_IN_PLACE);
        }
        else {
          return (KWD_QUERY_FAILURE);
        }
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Keyword* continueNotProof(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    if (((boolean)(frame->down))) {
      return (KWD_QUERY_MOVE_DOWN);
    }
    { Proposition* argument = ((Proposition*)((frame->proposition->arguments->theArray)[0]));

      if ((!frame->reversePolarityP) &&
          closedPropositionP(argument)) {
        return (overlayWithFailFrame(frame, argument));
      }
      createDownFrame(frame, argument);
      frame->down->reversePolarityP = !frame->reversePolarityP;
      return (KWD_QUERY_MOVE_DOWN);
    }
  }
  else if (lastmove == KWD_QUERY_UP_TRUE) {
    frame->truthValue = invertTruthValue(frame->result->truthValue);
    if (oRECORD_JUSTIFICATIONSpo.get()) {
      recordDisproofJustification(frame, lastmove);
    }
    if (!((boolean)(frame->down))) {
      return (KWD_QUERY_FINAL_SUCCESS);
    }
    else {
      return (KWD_QUERY_CONTINUING_SUCCESS);
    }
  }
  else if (lastmove == KWD_QUERY_UP_FAIL) {
    frame->truthValue = invertTruthValue(frame->result->truthValue);
    if (oRECORD_JUSTIFICATIONSpo.get()) {
      recordDisproofJustification(frame, lastmove);
    }
    return (KWD_QUERY_FAILURE);
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

Keyword* overlayWithFailFrame(ControlFrame* frame, Proposition* proposition) {
  { Proposition* failproposition = createProposition(SYM_QUERY_LOGIC_FAIL, 1);

    (failproposition->arguments->theArray)[0] = proposition;
    frame->proposition = failproposition;
    frame->state = KWD_QUERY_FAIL;
    frame->reversePolarityP = false;
    return (KWD_QUERY_MOVE_IN_PLACE);
  }
}

// Signals atomic proposition provers that polarity is negative.
DEFINE_STELLA_SPECIAL(oREVERSEPOLARITYpo, boolean , false);

Keyword* overlayWithStrategyFrame(ControlFrame* frame, Keyword* strategy) {
  frame->nextStrategies = consList(1, strategy);
  frame->state = KWD_QUERY_STRATEGY;
  return (KWD_QUERY_MOVE_IN_PLACE);
}

boolean checkForDuplicateGoalP(ControlFrame* frame) {
  if (!((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) ||
      (oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS_WITH_CACHING))) {
    return (false);
  }
  { GeneralizedSymbol* operatoR = frame->proposition->operatoR;
    Cons* goalbindings = frame->goalBindings;
    ControlFrame* previousframe = frame->up;
    ControlFrame* duplicateframe = NULL;

    { int i = NULL_INTEGER;
      int iter000 = 1;
      int upperBound000 = oDUPLICATE_GOAL_SEARCH_DEPTHo;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      for  (i, iter000, upperBound000, unboundedP000; 
            unboundedP000 ||
                (iter000 <= upperBound000); 
            iter000 = iter000 + 1) {
        i = iter000;
        i = i;
        if (!((boolean)(previousframe))) {
          break;
        }
        { boolean testValue000 = false;

          testValue000 = ((boolean)(previousframe->goalBindings));
          if (testValue000) {
            testValue000 = operatoR == previousframe->proposition->operatoR;
            if (testValue000) {
              { boolean alwaysP000 = true;

                { Object* b1 = NULL;
                  Cons* iter001 = goalbindings;
                  Object* b2 = NULL;
                  Cons* iter002 = previousframe->goalBindings;

                  for  (b1, iter001, b2, iter002; 
                        (!(iter001 == NIL)) &&
                            (!(iter002 == NIL)); 
                        iter001 = iter001->rest,
                        iter002 = iter002->rest) {
                    b1 = iter001->value;
                    b2 = iter002->value;
                    if (!eqlP(b1, b2)) {
                      alwaysP000 = false;
                      break;
                    }
                  }
                }
                testValue000 = alwaysP000;
              }
              if (testValue000) {
                testValue000 = frame->reversePolarityP == previousframe->reversePolarityP;
              }
            }
          }
          if (testValue000) {
            duplicateframe = previousframe;
            break;
          }
        }
        previousframe = previousframe->up;
      }
    }
    if (((boolean)(duplicateframe))) {
      traceGoalCache("DUPLICATE GOAL:", frame);
      if ((oCACHE_SUCCEEDED_GOALSpo ||
          oCACHE_FAILED_GOALSpo) &&
          ((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) &&
           (!(((boolean)(oQUERYITERATORo.get())) &&
          ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)))))) {
        dontCacheGoalFailureBetweenFrames(frame, duplicateframe->down);
      }
      return (true);
    }
    else {
      return (false);
    }
  }
}

Keyword* initiateAtomicGoalProofs(ControlFrame* frame) {
  { 
    BIND_STELLA_SPECIAL(oREVERSEPOLARITYpo, boolean, frame->reversePolarityP);
    { Proposition* proposition = frame->proposition;
      Keyword* inferencelevel = currentInferenceLevel()->keyword;
      Cons* strategies = NULL;

      { Keyword* testValue000 = proposition->kind;

        if ((testValue000 == KWD_QUERY_PREDICATE) ||
            ((testValue000 == KWD_QUERY_ISA) ||
             (testValue000 == KWD_QUERY_FUNCTION))) {
          frame->goalBindings = yieldGoalBindings(proposition);
          if (checkForDuplicateGoalP(frame)) {
            if (oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) {
              inferencelevel = KWD_QUERY_SHALLOW;
            }
            else if (oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS_WITH_CACHING) {
              frame->state = KWD_QUERY_SCAN_CACHED_BINDINGS;
              return (KWD_QUERY_MOVE_IN_PLACE);
            }
            else {
              { OutputStringStream* stream000 = newOutputStringStream();

                *(stream000->nativeStream) << "`" << oDUPLICATE_SUBGOAL_STRATEGYo << "'" << " is not a valid case option";
                throw *newStellaException(stream000->theStringReader());
              }
            }
          }
          if ((inferencelevel == KWD_QUERY_NORMAL) ||
              (inferencelevel == KWD_QUERY_BACKTRACKING)) {
            strategies = getQuotedTree("((:SPECIALIST :LOOKUP-GOAL-CACHES :LOOKUP-ASSERTIONS :SHALLOW-DISPROOF :ALL-SUBGOAL-STRATEGIES) \"/LOGIC\")", "/LOGIC");
          }
          else if (inferencelevel == KWD_QUERY_REFUTATION) {
            strategies = getQuotedTree("((:SPECIALIST :LOOKUP-GOAL-CACHES :LOOKUP-ASSERTIONS :SHALLOW-DISPROOF :ALL-SUBGOAL-STRATEGIES :REFUTATION) \"/LOGIC\")", "/LOGIC");
          }
          else {
            strategies = getQuotedTree("((:SPECIALIST :LOOKUP-ASSERTIONS :SHALLOW-DISPROOF) \"/LOGIC\")", "/LOGIC");
          }
          if ((proposition->kind == KWD_QUERY_FUNCTION) &&
              (!oREVERSEPOLARITYpo.get())) {
            strategies = copyConsList(strategies)->concatenate(consList(1, KWD_QUERY_MANUFACTURE_SKOLEM), 0);
          }
        }
        else if (testValue000 == KWD_QUERY_EQUIVALENT) {
          strategies = getQuotedTree("((:EQUIVALENCE) \"/LOGIC\")", "/LOGIC");
        }
        else if (testValue000 == KWD_QUERY_IMPLIES) {
          strategies = getQuotedTree("((:SPECIALIST :ALL-SUBGOAL-STRATEGIES :IMPLIES) \"/LOGIC\")", "/LOGIC");
        }
        else {
          { OutputStringStream* stream001 = newOutputStringStream();

            *(stream001->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
            throw *newStellaException(stream001->theStringReader());
          }
        }
      }
      frame->nextStrategies = strategies;
      frame->state = KWD_QUERY_ATOMIC_GOAL;
      return (KWD_QUERY_MOVE_IN_PLACE);
    }
  }
}

boolean allArgumentsBoundP(Proposition* goal) {
  if (((boolean)(((Vector*)(dynamicSlotValue(goal->dynamicSlots, SYM_QUERY_LOGIC_IO_VARIABLES, NULL)))))) {
    return (quantifiedArgumentBoundP(goal, NULL));
  }
  else {
    return (argumentBoundP(goal));
  }
}

boolean allKeyArgumentsBoundP(Proposition* goal) {
  if ((goal->kind == KWD_QUERY_FUNCTION) ||
      singleValuedPredicateP(goal)) {
    if (((boolean)(((Vector*)(dynamicSlotValue(goal->dynamicSlots, SYM_QUERY_LOGIC_IO_VARIABLES, NULL)))))) {
      { boolean alwaysP000 = true;

        { int i = NULL_INTEGER;
          int iter000 = 0;
          int upperBound000 = goal->arguments->length() - 2;

          for  (i, iter000, upperBound000; 
                iter000 <= upperBound000; 
                iter000 = iter000 + 1) {
            i = iter000;
            if (!quantifiedArgumentBoundP((goal->arguments->theArray)[i], NULL)) {
              alwaysP000 = false;
              break;
            }
          }
        }
        { boolean value000 = alwaysP000;

          return (value000);
        }
      }
    }
    else {
      { boolean alwaysP001 = true;

        { int i = NULL_INTEGER;
          int iter001 = 0;
          int upperBound001 = goal->arguments->length() - 2;

          for  (i, iter001, upperBound001; 
                iter001 <= upperBound001; 
                iter001 = iter001 + 1) {
            i = iter001;
            if (!argumentBoundP((goal->arguments->theArray)[i])) {
              alwaysP001 = false;
              break;
            }
          }
        }
        { boolean value001 = alwaysP001;

          return (value001);
        }
      }
    }
  }
  else {
    return (false);
  }
}

PatternRecord* createPatternRecord(ControlFrame* frame, Description* description, Vector* externalarguments) {
  { PatternRecord* patternrecord = newPatternRecord();

    if (((boolean)(description))) {
      patternrecord->description = description;
      if (((boolean)(externalarguments))) {
        { Vector* externalargumentscopy = copyPatternArguments(externalarguments, description);

          patternrecord->externalArguments = externalargumentscopy;
          patternrecord->booleanVector = argumentsVectorToBooleanVector(externalargumentscopy);
        }
      }
      else {
        { List* oneslist = newList();

          { Iterator* v = ((Iterator*)(description->ioVariables->allocateIterator()));
            Cons* collect000 = NULL;

            for (v, collect000; v->nextP(); ) {
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(ZERO_WRAPPER, NIL);
                  if (oneslist->theConsList == NIL) {
                    oneslist->theConsList = collect000;
                  }
                  else {
                    addConsToEndOfConsList(oneslist->theConsList, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(ZERO_WRAPPER, NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
          patternrecord->booleanVector = zeroOneListToBooleanVector(oneslist);
          oneslist->free();
        }
      }
    }
    patternrecord->collectionList = NULL;
    frame->patternRecord = patternrecord;
    patternrecord->controlFrame = frame;
    return (patternrecord);
  }
}

boolean terminatePatternRecordP(PatternRecord* self) {
  if (((boolean)(self->externalArguments))) {
    self->externalArguments->free();
  }
  self->optimalPattern = NULL;
  return (true);
}

Vector* copyPatternArguments(Vector* arguments, Description* description) {
  if (!((boolean)(arguments))) {
    return (NULL);
  }
  { int argumentcount = description->arity();
    Vector* copiedarguments = newVector(argumentcount);

    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = argumentcount - 1;

      for  (i, iter000, upperBound000; 
            iter000 <= upperBound000; 
            iter000 = iter000 + 1) {
        i = iter000;
        (copiedarguments->theArray)[i] = ((arguments->theArray)[i]);
      }
    }
    return (copiedarguments);
  }
}

Cons* computeExternalBindings(Vector* externalarguments) {
  { Cons* externalbindings = NIL;

    if (!((boolean)(externalarguments))) {
      return (NIL);
    }
    { Object* arg = NULL;
      Vector* vector000 = externalarguments;
      int index000 = 0;
      int length000 = vector000->length();
      Cons* collect000 = NULL;

      for  (arg, vector000, index000, length000, collect000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(instantiateExternalBindings(argumentBoundTo(arg)), NIL);
            if (externalbindings == NIL) {
              externalbindings = collect000;
            }
            else {
              addConsToEndOfConsList(externalbindings, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(instantiateExternalBindings(argumentBoundTo(arg)), NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    return (externalbindings);
  }
}

Object* instantiateExternalBindings(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_NAMED_DESCRIPTION)) {
      { Object* self000 = self;
        NamedDescription* self = ((NamedDescription*)(self000));

      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_DESCRIPTION)) {
      { Object* self001 = self;
        Description* self = ((Description*)(self001));

        if (((boolean)(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_EXTERNAL_VARIABLES, NULL)))))) {
          { KeyValueList* mapping = newKeyValueList();

            { PatternVariable* var = NULL;
              Vector* vector000 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_EXTERNAL_VARIABLES, NULL)));
              int index000 = 0;
              int length000 = vector000->length();

              for  (var, vector000, index000, length000; 
                    index000 < length000; 
                    index000 = index000 + 1) {
                var = ((PatternVariable*)((vector000->theArray)[index000]));
                if (argumentBoundP(var)) {
                  mapping->insertAt(var, argumentBoundTo(var));
                }
              }
            }
            if (!(mapping->emptyP())) {
              return (instantiateExternalVariables(self, mapping));
            }
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_PROPOSITION)) {
      { Object* self002 = self;
        Proposition* self = ((Proposition*)(self002));

      }
    }
    else {
    }
  }
  return (self);
}

Description* instantiateExternalVariables(Description* self, KeyValueList* bindings) {
  if (!(bindings->emptyP())) {
    { 
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_QUERY_DESCRIPTION);
      BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, NULL);
      { Description* description = newDescription();

        { Object* var = NULL;
          Object* binding = NULL;
          KvCons* iter000 = bindings->theKvList;

          for  (var, binding, iter000; 
                ((boolean)(iter000)); 
                iter000 = iter000->rest) {
            var = iter000->key;
            binding = iter000->value;
            bindings->insertAt(var, evaluateTerm(binding));
          }
        }
        description->ioVariables = self->ioVariables->copy();
        { PatternVariable* var = NULL;
          Vector* vector000 = self->ioVariables;
          int index000 = 0;
          int length000 = vector000->length();

          for  (var, vector000, index000, length000; 
                index000 < length000; 
                index000 = index000 + 1) {
            var = ((PatternVariable*)((vector000->theArray)[index000]));
            bindings->insertAt(var, var);
          }
        }
        { PatternVariable* var = NULL;
          Vector* vector001 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_EXTERNAL_VARIABLES, NULL)));
          int index001 = 0;
          int length001 = vector001->length();

          for  (var, vector001, index001, length001; 
                index001 < length001; 
                index001 = index001 + 1) {
            var = ((PatternVariable*)((vector001->theArray)[index001]));
            if (!((boolean)(bindings->lookup(var)))) {
              bindings->insertAt(var, var);
            }
          }
        }
        { PatternVariable* var = NULL;
          Vector* vector002 = self->internalVariables;
          int index002 = 0;
          int length002 = vector002->length();

          for  (var, vector002, index002, length002; 
                index002 < length002; 
                index002 = index002 + 1) {
            var = ((PatternVariable*)((vector002->theArray)[index002]));
            bindings->insertAt(var, var);
          }
        }
        description->proposition = inheritProposition(self->proposition, bindings);
        return (finishBuildingDescription(description, true));
      }
    }
  }
  return (self);
}

boolean checkForSingleValuedGoalP(Description* pattern, Cons* iobindings) {
  { Cons* iovariables = NIL;
    Cons* boundvariables = NIL;

    { PatternVariable* vbl = NULL;
      Vector* vector000 = pattern->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();
      Cons* collect000 = NULL;

      for  (vbl, vector000, index000, length000, collect000; 
            index000 < length000; 
            index000 = index000 + 1) {
        vbl = ((PatternVariable*)((vector000->theArray)[index000]));
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(vbl, NIL);
            if (iovariables == NIL) {
              iovariables = collect000;
            }
            else {
              addConsToEndOfConsList(iovariables, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(vbl, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    { Object* v1 = NULL;
      Cons* iter000 = iovariables;
      Object* v2 = NULL;
      Cons* iter001 = iobindings;

      for  (v1, iter000, v2, iter001; 
            (!(iter000 == NIL)) &&
                (!(iter001 == NIL)); 
            iter000 = iter000->rest,
            iter001 = iter001->rest) {
        v1 = iter000->value;
        v2 = iter001->value;
        if (((boolean)(v2))) {
          boundvariables = cons(v1, boundvariables);
        }
      }
    }
    return (singleValuedGoalP(pattern->proposition, iovariables, boundvariables));
  }
}

boolean overlayWithPatternFrameP(ControlFrame* frame, Description* description, Vector* ioarguments) {
  { Cons* iobindings = computeExternalBindings(ioarguments);
    Cons* externalbindings = (((boolean)(((Vector*)(dynamicSlotValue(description->dynamicSlots, SYM_QUERY_LOGIC_EXTERNAL_VARIABLES, NULL))))) ? computeExternalBindings(((Vector*)(dynamicSlotValue(description->dynamicSlots, SYM_QUERY_LOGIC_EXTERNAL_VARIABLES, NULL)))) : NIL);
    PatternRecord* patternrecord = createPatternRecord(frame, description, ioarguments);
    Description* optimalpattern = NULL;

    if (!((boolean)(ioarguments))) {
      { Iterator* v = ((Iterator*)(description->ioVariables->allocateIterator()));
        Cons* collect000 = NULL;

        for (v, collect000; v->nextP(); ) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(NULL, NIL);
              if (iobindings == NIL) {
                iobindings = collect000;
              }
              else {
                addConsToEndOfConsList(iobindings, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(NULL, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    frame->state = KWD_QUERY_PATTERN;
    optimalpattern = selectOptimalQueryPattern(description, patternrecord->booleanVector, frame);
    patternrecord->optimalPattern = optimalpattern;
    if (checkForSingleValuedGoalP(optimalpattern, iobindings)) {
      setDynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_CACHED_SINGLE_VALUEDp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
    frame->proposition = optimalpattern->proposition;
    { int variablescount = iobindings->length() + optimalpattern->internalVariables->length() + externalbindings->length();

      activatePatternRecord(patternrecord, variablescount);
    }
    { PatternVariable* iovar = NULL;
      Vector* vector000 = optimalpattern->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();
      Object* binding = NULL;
      Cons* iter000 = iobindings;

      for  (iovar, vector000, index000, length000, binding, iter000; 
            (index000 < length000) &&
                (!(iter000 == NIL)); 
            index000 = index000 + 1,
            iter000 = iter000->rest) {
        iovar = ((PatternVariable*)((vector000->theArray)[index000]));
        binding = iter000->value;
        if (((boolean)(binding)) &&
            (!bindVariableToValueP(iovar, binding, false))) {
          return (false);
        }
      }
    }
    if (!(externalbindings == NIL)) {
      { PatternVariable* externalvar = NULL;
        Vector* vector001 = ((Vector*)(dynamicSlotValue(optimalpattern->dynamicSlots, SYM_QUERY_LOGIC_EXTERNAL_VARIABLES, NULL)));
        int index001 = 0;
        int length001 = vector001->length();
        Object* binding = NULL;
        Cons* iter001 = externalbindings;

        for  (externalvar, vector001, index001, length001, binding, iter001; 
              (index001 < length001) &&
                  (!(iter001 == NIL)); 
              index001 = index001 + 1,
              iter001 = iter001->rest) {
          externalvar = ((PatternVariable*)((vector001->theArray)[index001]));
          binding = iter001->value;
          if (((boolean)(binding)) &&
              (!bindVariableToValueP(externalvar, binding, false))) {
            return (false);
          }
        }
      }
    }
    if (!((boolean)(frame->down))) {
      createDownFrame(frame, optimalpattern->proposition);
    }
    elaborateSurrogatesInProposition(optimalpattern->proposition);
    return (true);
  }
}

boolean transferPatternQueryBindingsP(ControlFrame* frame, boolean futurebindingsP) {
  if (((boolean)(oTRACED_KEYWORDSo)) &&
      oTRACED_KEYWORDSo->membP(KWD_QUERY_QUERY_STACKS)) {
    std::cout << "TRANSFER-pattern-query-bindings?: " << std::endl;
  }
  { PatternRecord* childpatternrecord = frame->patternRecord;
    BooleanVector* booleanvector = childpatternrecord->booleanVector;
    Vector* externalarguments = childpatternrecord->externalArguments;
    Vector* iovariables = childpatternrecord->optimalPattern->ioVariables;
    int lastindex = booleanvector->length() - 1;
    Cons* iovariablevalues = NIL;
    int topunbindingoffset = NULL_INTEGER;

    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = lastindex;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;
      Cons* collect000 = NULL;

      for  (i, iter000, upperBound000, unboundedP000, collect000; 
            unboundedP000 ||
                (iter000 <= upperBound000); 
            iter000 = iter000 + 1) {
        i = iter000;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(((!coerceWrappedBooleanToBoolean(((BooleanWrapper*)((booleanvector->theArray)[i])))) ? (oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(((PatternVariable*)((iovariables->theArray)[i]))->boundToOffset)] : NULL), NIL);
            if (iovariablevalues == NIL) {
              iovariablevalues = collect000;
            }
            else {
              addConsToEndOfConsList(iovariablevalues, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(((!coerceWrappedBooleanToBoolean(((BooleanWrapper*)((booleanvector->theArray)[i])))) ? (oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(((PatternVariable*)((iovariables->theArray)[i]))->boundToOffset)] : NULL), NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    resetCurrentPatternRecord(frame, KWD_QUERY_PARENT);
    { PatternRecord* parentpatternrecord = oQUERYITERATORo.get()->currentPatternRecord;

      topunbindingoffset = parentpatternrecord->topUnbindingStackOffset;
      { Object* value = NULL;
        Cons* iter001 = iovariablevalues;
        Object* externalarg = NULL;
        Vector* vector000 = externalarguments;
        int index000 = 0;
        int length000 = vector000->length();
        BooleanWrapper* initiallyboundP = NULL;
        BooleanVector* vector001 = booleanvector;
        int index001 = 0;
        int length001 = vector001->length();

        for  (value, iter001, externalarg, vector000, index000, length000, initiallyboundP, vector001, index001, length001; 
              (!(iter001 == NIL)) &&
                  ((index000 < length000) &&
                   (index001 < length001)); 
              iter001 = iter001->rest,
              index000 = index000 + 1,
              index001 = index001 + 1) {
          value = iter001->value;
          externalarg = (vector000->theArray)[index000];
          initiallyboundP = ((BooleanWrapper*)((vector001->theArray)[index001]));
          if (!coerceWrappedBooleanToBoolean(initiallyboundP)) {
            if (!bindArgumentToValueP(externalarg, value, false)) {
              if (((boolean)(oTRACED_KEYWORDSo)) &&
                  oTRACED_KEYWORDSo->membP(KWD_QUERY_QUERY_STACKS)) {
                std::cout << "TRANSFER FAILS! " << std::endl;
              }
              unbindVariablesBeginningAt(parentpatternrecord, topunbindingoffset + 1);
              if (futurebindingsP) {
                resetCurrentPatternRecord(frame, KWD_QUERY_LOCAL);
              }
              return (false);
            }
          }
        }
      }
    }
    return (true);
  }
}

void collectPatternQueryBindings(ControlFrame* frame) {
  { PatternRecord* patternrecord = frame->patternRecord;
    Vector* iovariables = patternrecord->optimalPattern->ioVariables;
    Cons* iovariablevalues = NIL;

    { PatternVariable* v = NULL;
      Vector* vector000 = iovariables;
      int index000 = 0;
      int length000 = vector000->length();
      Cons* collect000 = NULL;

      for  (v, vector000, index000, length000, collect000; 
            index000 < length000; 
            index000 = index000 + 1) {
        v = ((PatternVariable*)((vector000->theArray)[index000]));
        if (!((boolean)(collect000))) {
          {
            collect000 = cons((oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(v->boundToOffset)], NIL);
            if (iovariablevalues == NIL) {
              iovariablevalues = collect000;
            }
            else {
              addConsToEndOfConsList(iovariablevalues, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons((oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(v->boundToOffset)], NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    switch (iovariablevalues->length()) {
      case 1: 
        if (!((boolean)(iovariablevalues->value))) {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Pushing NULL binding onto collection.  Variable= " << "`" << ((PatternVariable*)((iovariables->theArray)[0])) << "'" << std::endl;
          return;
        }
        patternrecord->collectionList->push(iovariablevalues->value);
      break;
      default:
        patternrecord->collectionList->push(iovariablevalues);
      break;
    }
  }
}

Proposition* getRuleOfAntecedentFrame(ControlFrame* frame) {
  if (frame->state == KWD_QUERY_PATTERN) {
    { ControlFrame* parent = frame->up;

      if (((boolean)(parent))) {
        return (((Proposition*)(dynamicSlotValue(parent->dynamicSlots, SYM_QUERY_LOGIC_ANTECEDENTS_RULE, NULL))));
      }
    }
  }
  return (NULL);
}

Keyword* continuePatternProof(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    resetCurrentPatternRecord(frame, KWD_QUERY_LOCAL);
    return (KWD_QUERY_MOVE_DOWN);
  }
  else if (lastmove == KWD_QUERY_UP_TRUE) {
    { boolean futurebindingsP = ((boolean)(frame->down));
      ControlFrame* result = frame->result;
      Proposition* rule = getRuleOfAntecedentFrame(frame);

      frame->truthValue = weakenTruthValue(propagateFrameTruthValue(result, frame), (((boolean)(rule)) ? ((TruthValue*)(accessInContext(rule->truthValue, rule->homeContext, false))) : TRUE_TRUTH_VALUE));
      if (((boolean)(result->partialMatchFrame))) {
        result->partialMatchFrame->propagateFramePartialTruth(frame);
      }
      if (oRECORD_JUSTIFICATIONSpo.get()) {
        recordPatternJustification(frame, lastmove);
      }
      if (((boolean)(frame->patternRecord->collectionList))) {
        collectPatternQueryBindings(frame);
        if (futurebindingsP) {
          return (KWD_QUERY_MOVE_DOWN);
        }
        else {
          {
            resetCurrentPatternRecord(frame, KWD_QUERY_PARENT);
            return (KWD_QUERY_CONTINUING_SUCCESS);
          }
        }
      }
      else if (transferPatternQueryBindingsP(frame, futurebindingsP)) {
        if (futurebindingsP) {
          {
            if (((BooleanWrapper*)(dynamicSlotValue(frame->dynamicSlots, SYM_QUERY_LOGIC_CACHED_SINGLE_VALUEDp, FALSE_WRAPPER)))->wrapperValue &&
                (!oGENERATE_ALL_PROOFSpo.get())) {
              popFramesUpTo(frame->down);
              return (KWD_QUERY_FINAL_SUCCESS);
            }
            return (KWD_QUERY_CONTINUING_SUCCESS);
          }
        }
        else {
          return (KWD_QUERY_FINAL_SUCCESS);
        }
      }
      else if (futurebindingsP) {
        return (KWD_QUERY_MOVE_DOWN);
      }
      else {
        return (KWD_QUERY_FAILURE);
      }
    }
  }
  else if ((lastmove == KWD_QUERY_UP_FAIL) ||
      (lastmove == KWD_QUERY_FAILED_OVERLAY)) {
    { ControlFrame* result = frame->result;

      propagateFrameTruthValue(result, frame);
      if (((boolean)(result->partialMatchFrame))) {
        result->partialMatchFrame->propagateFramePartialTruth(frame);
      }
      if (oRECORD_JUSTIFICATIONSpo.get()) {
        recordPatternJustification(frame, lastmove);
      }
      if (((boolean)(frame->patternRecord->collectionList))) {
        {
          resetCurrentPatternRecord(frame, KWD_QUERY_PARENT);
          return (KWD_QUERY_CONTINUING_SUCCESS);
        }
      }
      else {
        return (KWD_QUERY_FAILURE);
      }
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << lastmove << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

boolean disjointClassesP(NamedDescription* desc1, NamedDescription* desc2) {
  return ((!(desc1 == desc2)) &&
      ((!collectionImpliesCollectionP(desc1, desc2)) &&
       (!collectionImpliesCollectionP(desc2, desc1))));
}

boolean disjointTermsP(Description* d1, Description* d2) {
  // Return TRUE if 'd1' and 'd2' belong to disjoint partitions.
  { TruthValue* dummy1;

    if (oCYC_KLUDGES_ENABLEDpo) {
      if (isaP(d1, SGT_QUERY_LOGIC_NAMED_DESCRIPTION) &&
          isaP(d2, SGT_QUERY_LOGIC_NAMED_DESCRIPTION)) {
        return (trueTruthValueP(evaluateSelectionPattern(makeRelationPattern2(SGT_QUERY_PL_KERNEL_KB_DISJOINT, d1, d2))));
      }
    }
    return (applyCachedAsk(listO(3, SYM_QUERY_LOGIC_pD1, SYM_QUERY_LOGIC_pD2, NIL), listO(4, SYM_QUERY_LOGIC_DISJOINT, SYM_QUERY_LOGIC_pD1, SYM_QUERY_LOGIC_pD2, NIL), consList(2, d1, d2), consList(0), SYM_QUERY_LOGIC_F_DISJOINT_TERMSp_QUERY_000, dummy1));
  }
}

boolean expensiveDisjointTermsP(Description* d1, Description* d2) {
  { TruthValue* dummy1;

    return (applyCachedAsk(listO(3, SYM_QUERY_LOGIC_pD1, SYM_QUERY_LOGIC_pD2, NIL), listO(4, SYM_QUERY_STELLA_OR, listO(4, SYM_QUERY_LOGIC_DISJOINT, SYM_QUERY_LOGIC_pD1, SYM_QUERY_LOGIC_pD2, NIL), listO(5, SYM_QUERY_STELLA_AND, listO(3, SYM_QUERY_PL_KERNEL_KB_CLASS, SYM_QUERY_LOGIC_pD1, NIL), listO(3, SYM_QUERY_PL_KERNEL_KB_CLASS, SYM_QUERY_LOGIC_pD2, NIL), listO(4, SYM_QUERY_LOGIC_REFUTATION_DISJOINT, SYM_QUERY_LOGIC_pD1, SYM_QUERY_LOGIC_pD2, NIL), NIL), NIL), consList(2, d1, d2), consList(0), SYM_QUERY_LOGIC_F_EXPENSIVE_DISJOINT_TERMSp_QUERY_000, dummy1));
  }
}

boolean collectionofPropositionP(Proposition* definingproposition) {
  return (logicalSubtypeOfP(((Surrogate*)(definingproposition->operatoR)), SGT_QUERY_PL_KERNEL_KB_COLLECTIONOF));
}

boolean memberOfCollectionP(Object* member, Object* collection) {
  { Surrogate* testValue000 = safePrimaryType(collection);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_NAMED_DESCRIPTION)) {
      { Object* collection000 = collection;
        NamedDescription* collection = ((NamedDescription*)(collection000));

        return (allTrueDependentPropositions(member, collection->surrogateValueInverse, true)->nextP());
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_STELLA_COLLECTION)) {
      { Object* collection001 = collection;
        Collection* collection = ((Collection*)(collection001));

        { boolean foundP000 = false;

          { Object* m = NULL;
            Iterator* iter000 = ((Iterator*)(collection->allocateIterator()));

            for (m, iter000; iter000->nextP(); ) {
              m = iter000->value;
              if (eqlP(valueOf(m), member)) {
                foundP000 = true;
                break;
              }
            }
          }
          { boolean memberP = foundP000;

            if (oREVERSEPOLARITYpo.get()) {
              return (!memberP);
            }
            else {
              return (memberP);
            }
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_SKOLEM)) {
      { Object* collection002 = collection;
        Skolem* collection = ((Skolem*)(collection002));

        { boolean successP = false;
          Cons* enumeratedcollections = allDefiningPropositions(collection, SGT_QUERY_PL_KERNEL_KB_COLLECTIONOF, true);

          if (!(enumeratedcollections == NIL)) {
            { Proposition* col = NULL;
              Cons* iter001 = enumeratedcollections;

              for (col, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
                col = ((Proposition*)(iter001->value));
                { Object* arg = NULL;
                  Vector* vector000 = col->arguments;
                  int index000 = 0;
                  int length000 = vector000->length();
                  int i = NULL_INTEGER;
                  int iter002 = 2;
                  int upperBound000 = col->arguments->length();

                  for  (arg, vector000, index000, length000, i, iter002, upperBound000; 
                        (index000 < length000) &&
                            (iter002 <= upperBound000); 
                        index000 = index000 + 1,
                        iter002 = iter002 + 1) {
                    arg = (vector000->theArray)[index000];
                    i = iter002;
                    if (eqlP(valueOf(arg), member)) {
                      i = i;
                      successP = true;
                      break;
                    }
                  }
                }
              }
            }
            if (oREVERSEPOLARITYpo.get()) {
              return (!successP);
            }
            else {
              return (successP);
            }
          }
          else {
            { Proposition* p = NULL;
              Iterator* iter003 = allTrueDependentPropositions(member, SGT_QUERY_PL_KERNEL_KB_MEMBER_OF, false);

              for (p, iter003; iter003->nextP(); ) {
                p = ((Proposition*)(iter003->value));
                { LogicObject* subcollection = ((LogicObject*)(valueOf((p->arguments->theArray)[1])));

                  if ((oREVERSEPOLARITYpo.get() ? collectionImpliesCollectionP(collection, subcollection) : collectionImpliesCollectionP(subcollection, collection))) {
                    return (true);
                  }
                }
              }
            }
            return (false);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_LOGIC_OBJECT)) {
      { Object* collection003 = collection;
        LogicObject* collection = ((LogicObject*)(collection003));

        { Skolem* equivalentskolem = ((Skolem*)(((LogicObject*)(collection->variableValueInverse_reader()->value))));

          if (((boolean)(equivalentskolem))) {
            return (memberOfCollectionP(member, equivalentskolem));
          }
        }
      }
    }
    else {
    }
  }
  *(STANDARD_WARNING->nativeStream) << "Warning: " << "member-of-collection?: Illegal collection type: " << "`" << wrappedTypeToType(collection->primaryType())->symbolName << "'" << std::endl << "   member=" << "`" << member << "'" << " collection=" << "`" << collection << "'" << std::endl << std::endl;
  return (false);
}

List* assertedCollectionMembers(Object* self, boolean directP) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_QUERY_STELLA_COLLECTION)) {
      { Object* self000 = self;
        Collection* self = ((Collection*)(self000));

        { List* members = newList();

          { Object* m = NULL;
            Iterator* iter000 = ((Iterator*)(self->allocateIterator()));
            Cons* collect000 = NULL;

            for  (m, iter000, collect000; 
                  iter000->nextP(); ) {
              m = iter000->value;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(m, NIL);
                  if (members->theConsList == NIL) {
                    members->theConsList = collect000;
                  }
                  else {
                    addConsToEndOfConsList(members->theConsList, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(m, NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
          return (members);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_NAMED_DESCRIPTION)) {
      { Object* self001 = self;
        NamedDescription* self = ((NamedDescription*)(self001));

        { List* members = list(0);

          { Proposition* prop = NULL;
            DescriptionExtensionIterator* iter001 = allTrueExtensionMembers(self, !directP);
            Cons* collect001 = NULL;

            for  (prop, iter001, collect001; 
                  iter001->nextP(); ) {
              prop = ((Proposition*)(iter001->value));
              if (!((boolean)(collect001))) {
                {
                  collect001 = cons((prop->arguments->theArray)[0], NIL);
                  if (members->theConsList == NIL) {
                    members->theConsList = collect001;
                  }
                  else {
                    addConsToEndOfConsList(members->theConsList, collect001);
                  }
                }
              }
              else {
                {
                  collect001->rest = cons((prop->arguments->theArray)[0], NIL);
                  collect001 = collect001->rest;
                }
              }
            }
          }
          return (members);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_DESCRIPTION)) {
      { Object* self002 = self;
        Description* self = ((Description*)(self002));

        return (NULL);
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_SKOLEM)) {
      { Object* self003 = self;
        Skolem* self = ((Skolem*)(self003));

        { List* members = newList();
          Cons* enumeratedcollections = allDefiningPropositions(self, SGT_QUERY_PL_KERNEL_KB_COLLECTIONOF, true);

          if (!(enumeratedcollections == NIL)) {
            { Proposition* col = NULL;
              Cons* iter002 = enumeratedcollections;

              for (col, iter002; !(iter002 == NIL); iter002 = iter002->rest) {
                col = ((Proposition*)(iter002->value));
                { Object* arg = NULL;
                  Vector* vector000 = col->arguments;
                  int index000 = 0;
                  int length000 = vector000->length();
                  int i = NULL_INTEGER;
                  int iter003 = 2;
                  int upperBound000 = col->arguments->length();
                  Cons* collect002 = NULL;

                  for  (arg, vector000, index000, length000, i, iter003, upperBound000, collect002; 
                        (index000 < length000) &&
                            (iter003 <= upperBound000); 
                        index000 = index000 + 1,
                        iter003 = iter003 + 1) {
                    arg = (vector000->theArray)[index000];
                    i = iter003;
                    if (!((boolean)(collect002))) {
                      {
                        collect002 = cons(valueOf(arg), NIL);
                        if (members->theConsList == NIL) {
                          members->theConsList = collect002;
                        }
                        else {
                          addConsToEndOfConsList(members->theConsList, collect002);
                        }
                      }
                    }
                    else {
                      {
                        collect002->rest = cons(valueOf(arg), NIL);
                        collect002 = collect002->rest;
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            { Proposition* p = NULL;
              Iterator* iter004 = allTrueDependentPropositions(self, SGT_QUERY_PL_KERNEL_KB_MEMBER_OF, false);
              Cons* collect003 = NULL;

              for  (p, iter004, collect003; 
                    iter004->nextP(); ) {
                p = ((Proposition*)(iter004->value));
                if ((directP &&
                    eqlP(valueOf((p->arguments->theArray)[1]), valueOf(self))) ||
                    ((!directP) &&
                     collectionImpliesCollectionP(((LogicObject*)(valueOf((p->arguments->theArray)[1]))), ((LogicObject*)(valueOf(self)))))) {
                  if (!((boolean)(collect003))) {
                    {
                      collect003 = cons((p->arguments->theArray)[0], NIL);
                      if (members->theConsList == NIL) {
                        members->theConsList = collect003;
                      }
                      else {
                        addConsToEndOfConsList(members->theConsList, collect003);
                      }
                    }
                  }
                  else {
                    {
                      collect003->rest = cons((p->arguments->theArray)[0], NIL);
                      collect003 = collect003->rest;
                    }
                  }
                }
              }
            }
          }
          return (members);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_LOGIC_OBJECT)) {
      { Object* self004 = self;
        LogicObject* self = ((LogicObject*)(self004));

        { Skolem* equivalentskolem = ((Skolem*)(((LogicObject*)(self->variableValueInverse_reader()->value))));

          if (((boolean)(equivalentskolem))) {
            return (assertedCollectionMembers(equivalentskolem, directP));
          }
        }
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Hmm. PowerLoom doesn't know how to interpret the LOGIC-OBJECT: " << "`" << self << "'" << std::endl << "   as a collection." << std::endl << std::endl;
        return (NIL_LIST);
      }
    }
    else {
      return (NULL);
    }
  }
}

DescriptionExtensionIterator* newDescriptionExtensionIterator() {
  { DescriptionExtensionIterator* self = NULL;

    self = new DescriptionExtensionIterator();
    self->firstIterationP = true;
    self->value = NULL;
    self->truthValue = NULL;
    self->removingDuplicatesP = false;
    self->alreadyGeneratedTable = NULL;
    self->alreadyGeneratedList = newList();
    self->referenceProposition = NULL;
    self->extensionIterator = NULL;
    self->subcollections = NULL;
    self->rootDescription = NULL;
    return (self);
  }
}

Surrogate* DescriptionExtensionIterator::primaryType() {
  { DescriptionExtensionIterator* self = this;

    return (SGT_QUERY_LOGIC_DESCRIPTION_EXTENSION_ITERATOR);
  }
}

Object* accessDescriptionExtensionIteratorSlotValue(DescriptionExtensionIterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_LOGIC_ROOT_DESCRIPTION) {
    if (setvalueP) {
      self->rootDescription = ((NamedDescription*)(value));
    }
    else {
      value = self->rootDescription;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_SUBCOLLECTIONS) {
    if (setvalueP) {
      self->subcollections = ((Cons*)(value));
    }
    else {
      value = self->subcollections;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_EXTENSION_ITERATOR) {
    if (setvalueP) {
      self->extensionIterator = ((Iterator*)(value));
    }
    else {
      value = self->extensionIterator;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_REFERENCE_PROPOSITION) {
    if (setvalueP) {
      self->referenceProposition = ((Proposition*)(value));
    }
    else {
      value = self->referenceProposition;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_ALREADY_GENERATED_LIST) {
    if (setvalueP) {
      self->alreadyGeneratedList = ((List*)(value));
    }
    else {
      value = self->alreadyGeneratedList;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_ALREADY_GENERATED_TABLE) {
    if (setvalueP) {
      self->alreadyGeneratedTable = ((HashTable*)(value));
    }
    else {
      value = self->alreadyGeneratedTable;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_REMOVING_DUPLICATESp) {
    if (setvalueP) {
      self->removingDuplicatesP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->removingDuplicatesP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_TRUTH_VALUE) {
    if (setvalueP) {
      self->truthValue = ((TruthValue*)(value));
    }
    else {
      value = self->truthValue;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

DescriptionExtensionIterator* allTrueExtensionMembers(NamedDescription* self, boolean specializeP) {
  { DescriptionExtensionIterator* iterator = newDescriptionExtensionIterator();

    iterator->rootDescription = self;
    iterator->extensionIterator = allExtensionMembers(self);
    if (specializeP) {
      iterator->subcollections = NULL;
    }
    else {
      iterator->subcollections = NIL;
    }
    iterator->removingDuplicatesP = specializeP &&
        (self->arity() == 1);
    return (iterator);
  }
}

Iterator* allMatchingExtensionMembers(Proposition* self, boolean specializeP) {
  { DescriptionExtensionIterator* iterator = allTrueExtensionMembers(surrogateToDescription(((Surrogate*)(self->operatoR))), specializeP);

    iterator->referenceProposition = self;
    return (iterator);
  }
}

// Point where a cache of generated instances in a 
// description extension iterator is switched from a list to a hash table
int oDUPLICATEINSTANCESCACHECROSSOVERPOINTo = 20;

boolean DescriptionExtensionIterator::nextP() {
  { DescriptionExtensionIterator* self = this;

    { boolean withinqueryP = ((boolean)(oQUERYITERATORo.get()));
      PatternRecord* patternrecord = (withinqueryP ? oQUERYITERATORo.get()->currentPatternRecord : ((PatternRecord*)(NULL)));
      int ubstackoffset = (withinqueryP ? (patternrecord->topUnbindingStackOffset + 1) : ((int)(NULL_INTEGER)));

      for (;;) {
        for (;;) {
          if (!self->extensionIterator->nextP()) {
            break;
          }
          { Proposition* value = ((Proposition*)(self->extensionIterator->value));

            if (!(((!value->deletedP()) &&
                ((oREVERSEPOLARITYpo.get() ? falseP(value) : (trueP(value) ||
                functionWithDefinedValueP(value))))) &&
                ((!((boolean)(self->referenceProposition))) ||
                 argumentsMatchArgumentsP(value, self->referenceProposition)))) {
              continue;
            }
            self->value = value;
            self->truthValue = propositionTruthValue(value);
            if (((boolean)(self->subcollections)) &&
                (!(self->subcollections == NIL))) {
              self->truthValue = conjoinTruthValues(self->truthValue, ((TruthValue*)(((Cons*)(self->subcollections->value))->rest->value)));
            }
            if (!self->removingDuplicatesP) {
              return (true);
            }
            { Object* instance = (value->arguments->theArray)[0];

              if ((!((boolean)(self->alreadyGeneratedTable))) &&
                  (self->alreadyGeneratedList->length() >= oDUPLICATEINSTANCESCACHECROSSOVERPOINTo)) {
                { HashTable* hashtable = newHashTable();

                  { Object* m = NULL;
                    Cons* iter000 = self->alreadyGeneratedList->theConsList;

                    for (m, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
                      m = iter000->value;
                      hashtable->insertAt(m, m);
                    }
                  }
                  self->alreadyGeneratedTable = hashtable;
                }
              }
              if (((boolean)(self->alreadyGeneratedTable))) {
                if (!((boolean)(self->alreadyGeneratedTable->lookup(instance)))) {
                  self->alreadyGeneratedTable->insertAt(instance, instance);
                  return (true);
                }
              }
              else {
                if (!self->alreadyGeneratedList->memberP(instance)) {
                  self->alreadyGeneratedList->push(instance);
                  return (true);
                }
              }
              if (withinqueryP) {
                unbindVariablesBeginningAt(patternrecord, ubstackoffset);
              }
            }
          }
        }
        { Cons* subcollections = self->subcollections;
          NamedDescription* subcollection = NULL;

          if (!((boolean)(subcollections))) {
            subcollections = allSupportedNamedSubcollections(self->rootDescription);
          }
          else {
            subcollections = subcollections->rest;
          }
          while (!(subcollections == NIL)) {
            subcollection = ((NamedDescription*)(((Cons*)(subcollections->value))->value));
            if (!getDescriptionExtension(subcollection, true)->emptyP()) {
              break;
            }
            else {
              subcollections = subcollections->rest;
            }
          }
          if (!((boolean)(subcollection))) {
            break;
          }
          self->extensionIterator = allExtensionMembers(subcollection);
          self->subcollections = subcollections;
        }
      }
      return (false);
    }
  }
}

ControlFrame* helpFindDuplicatedGoal(ControlFrame* goalframe, ControlFrame*& _Return1, int& _Return2) {
  { Proposition* atomicgoal = goalframe->proposition;
    Cons* bindings = goalframe->goalBindings;
    int depth = 1;
    ControlFrame* firstgoalframe = NULL;
    Proposition* testgoal = NULL;
    ControlFrame* testframe = NULL;
    ControlFrame* restartframe = NULL;
    int restartdepth = NULL_INTEGER;

    testframe = oQUERYITERATORo.get()->baseControlFrame->down;
    for (;;) {
      testgoal = testframe->proposition;
      { boolean testValue000 = false;

        testValue000 = ((boolean)(testgoal));
        if (testValue000) {
          testValue000 = testgoal->operatoR == atomicgoal->operatoR;
          if (testValue000) {
            testValue000 = testframe->reversePolarityP == goalframe->reversePolarityP;
            if (testValue000) {
              if ((!((boolean)(bindings))) &&
                  (!((boolean)(testframe->goalBindings)))) {
                testValue000 = true;
              }
              else {
                {
                  testValue000 = ((boolean)(bindings));
                  if (testValue000) {
                    testValue000 = ((boolean)(testframe->goalBindings));
                    if (testValue000) {
                      { boolean alwaysP000 = true;

                        { Object* b1 = NULL;
                          Cons* iter000 = bindings;
                          Object* b2 = NULL;
                          Cons* iter001 = testframe->goalBindings;

                          for  (b1, iter000, b2, iter001; 
                                (!(iter000 == NIL)) &&
                                    (!(iter001 == NIL)); 
                                iter000 = iter000->rest,
                                iter001 = iter001->rest) {
                            b1 = iter000->value;
                            b2 = iter001->value;
                            if (!eqlP(b1, b2)) {
                              alwaysP000 = false;
                              break;
                            }
                          }
                        }
                        testValue000 = alwaysP000;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if (testValue000) {
          if (!((boolean)(firstgoalframe))) {
            firstgoalframe = testframe;
          }
          else {
            _Return1 = restartframe;
            _Return2 = restartdepth;
            return (firstgoalframe);
          }
        }
      }
      restartframe = testframe;
      restartdepth = depth;
      testframe = testframe->down;
      depth = depth + 1;
      if (!((boolean)(testframe))) {
        _Return1 = NULL;
        _Return2 = NULL_INTEGER;
        return (NULL);
      }
    }
  }
}

ControlFrame* findDuplicatedGoal(ControlFrame* frame, ControlFrame*& _Return1, int& _Return2) {
  { ControlFrame* trialframe = frame;
    Proposition* trialgoal = NULL;
    ControlFrame* firstrealcontrolframe = oQUERYITERATORo.get()->baseControlFrame->down;

    while (!(trialframe == firstrealcontrolframe)) {
      trialgoal = trialframe->proposition;
      if (((boolean)(trialgoal))) {
        { Keyword* testValue000 = trialgoal->kind;

          if ((testValue000 == KWD_QUERY_ISA) ||
              ((testValue000 == KWD_QUERY_PREDICATE) ||
               (testValue000 == KWD_QUERY_FUNCTION))) {
            { ControlFrame* goalframe = NULL;
              ControlFrame* restartframe = NULL;
              int restartdepth = NULL_INTEGER;

              goalframe = helpFindDuplicatedGoal(trialframe, restartframe, restartdepth);
              if (((boolean)(goalframe))) {
                traceGoalCache("DUPLICATED GOAL: ", trialframe);
                if (((boolean)(oTRACED_KEYWORDSo)) &&
                    oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_CACHES)) {
                  std::cout << "   RESTART DEPTH " << restartdepth << std::endl;
                }
                _Return1 = restartframe;
                _Return2 = restartdepth;
                return (goalframe);
              }
            }
          }
          else {
          }
        }
      }
      trialframe = trialframe->up;
    }
    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_CACHES)) {
      std::cout << "FAILED TO FIND DUPLICATE GOAL" << std::endl;
    }
    oQUERYITERATORo.get()->failedToFindDuplicateSubgoalP = true;
    _Return1 = NULL;
    _Return2 = NULL_INTEGER;
    return (NULL);
  }
}

ControlFrame* handleDepthViolation(ControlFrame* frame, int depth, int& _Return1) {
  if (((boolean)(oTRACED_KEYWORDSo)) &&
      (oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE) ||
       oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_CACHES))) {
    std::cout << "*** Inference depth cutoff: depth=" << depth << std::endl;
  }
  oQUERYITERATORo.get()->triggeredDepthCutoffP = true;
  if ((oCACHE_SUCCEEDED_GOALSpo ||
      oCACHE_FAILED_GOALSpo) &&
      ((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) &&
       (!(((boolean)(oQUERYITERATORo.get())) &&
      ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)))))) {
    dontCacheGoalFailureBetweenFrames(frame, oQUERYITERATORo.get()->baseControlFrame);
  }
  registerInferenceCutoff(frame, KWD_QUERY_DEPTH_VIOLATION);
  if ((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) ||
      (oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS_WITH_CACHING)) {
    setFrameTruthValue(frame, UNKNOWN_TRUTH_VALUE);
    if ((((boolean)(oQUERYITERATORo.get())) &&
        ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) &&
        (!((boolean)(frame->partialMatchFrame)))) {
      createAndLinkPartialMatchFrame(frame, NULL);
      frame->partialMatchFrame->setFramePartialTruth(NULL, 0.0, NULL_FLOAT, true);
    }
    if (oRECORD_JUSTIFICATIONSpo.get()) {
      { PrimitiveStrategy* self000 = newPrimitiveStrategy();

        self000->inferenceRule = KWD_QUERY_DEPTH_CUTOFF;
        self000->strategy = KWD_QUERY_FAILURE;
        recordGoalJustification(frame, self000);
      }
    }
    frame->state = KWD_QUERY_POPPED;
    frame->up->result = frame;
    frame = frame->up;
    depth = depth - 1;
  }
  else {
    { ControlFrame* goalframe = NULL;
      ControlFrame* restartframe = NULL;
      int restartdepth = NULL_INTEGER;

      goalframe = findDuplicatedGoal(frame, restartframe, restartdepth);
      if (((boolean)(goalframe)) &&
          ((!((boolean)(findGoalCache(goalframe)))) &&
           createGoalCacheP(goalframe))) {
        if (((boolean)(oTRACED_KEYWORDSo)) &&
            oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_CACHES)) {
          std::cout << "*** Inference restart: restartDepth=" << restartdepth << std::endl;
        }
        if (((boolean)(restartframe->down))) {
          popFramesUpTo(restartframe->down);
          restartframe->down = NULL;
        }
        frame = restartframe;
        depth = restartdepth;
      }
    }
  }
  _Return1 = depth;
  return (frame);
}

ControlFrame* handleTimeout(ControlFrame* frame, int depth, int& _Return1) {
  if (((boolean)(oTRACED_KEYWORDSo)) &&
      oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE)) {
    std::cout << "*** Timeout: start=" << frame->startingClockTicks << " depth=" << depth << std::endl;
  }
  if ((oCACHE_SUCCEEDED_GOALSpo ||
      oCACHE_FAILED_GOALSpo) &&
      ((oDUPLICATE_SUBGOAL_STRATEGYo == KWD_QUERY_DUPLICATE_GOALS) &&
       (!(((boolean)(oQUERYITERATORo.get())) &&
      ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)))))) {
    dontCacheGoalFailureBetweenFrames(frame, oQUERYITERATORo.get()->baseControlFrame);
  }
  registerInferenceCutoff(frame, KWD_QUERY_TIMEOUT);
  setFrameTruthValue(frame, UNKNOWN_TRUTH_VALUE);
  if (((boolean)(oQUERYITERATORo.get())) &&
      ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
    if (!((boolean)(frame->partialMatchFrame))) {
      createAndLinkPartialMatchFrame(frame, NULL);
    }
    frame->partialMatchFrame->setFramePartialTruth(NULL, 0.0, NULL_FLOAT, true);
  }
  if (oRECORD_JUSTIFICATIONSpo.get()) {
    { PrimitiveStrategy* self000 = newPrimitiveStrategy();

      self000->inferenceRule = KWD_QUERY_TIMEOUT;
      self000->strategy = KWD_QUERY_FAILURE;
      recordGoalJustification(frame, self000);
    }
  }
  frame->state = KWD_QUERY_POPPED;
  frame->up->result = frame;
  frame = frame->up;
  depth = depth - 1;
  _Return1 = depth;
  return (frame);
}

QuerySolutionTable* newQuerySolutionTable() {
  { QuerySolutionTable* self = NULL;

    self = new QuerySolutionTable();
    self->last = NULL;
    self->first = NULL;
    self->query = NULL;
    { KeyValueMap* self000 = newKeyValueMap();

      self000->equalTestP = true;
      self->theMap = self000;
    }
    return (self);
  }
}

Surrogate* QuerySolutionTable::primaryType() {
  { QuerySolutionTable* self = this;

    return (SGT_QUERY_LOGIC_QUERY_SOLUTION_TABLE);
  }
}

Object* accessQuerySolutionTableSlotValue(QuerySolutionTable* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_STELLA_THE_MAP) {
    if (setvalueP) {
      self->theMap = ((KeyValueMap*)(value));
    }
    else {
      value = self->theMap;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_QUERY) {
    if (setvalueP) {
      self->query = ((QueryIterator*)(value));
    }
    else {
      value = self->query;
    }
  }
  else if (slotname == SYM_QUERY_STELLA_FIRST) {
    if (setvalueP) {
      self->first = ((QuerySolution*)(value));
    }
    else {
      value = self->first;
    }
  }
  else if (slotname == SYM_QUERY_STELLA_LAST) {
    if (setvalueP) {
      self->last = ((QuerySolution*)(value));
    }
    else {
      value = self->last;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

QuerySolution* newQuerySolution() {
  { QuerySolution* self = NULL;

    self = new QuerySolution();
    self->next = NULL;
    self->allJustifications = NULL;
    self->justification = NULL;
    self->matchScore = NULL_FLOAT;
    self->truthValue = NULL;
    self->bindings = NULL;
    return (self);
  }
}

Surrogate* QuerySolution::primaryType() {
  { QuerySolution* self = this;

    return (SGT_QUERY_LOGIC_QUERY_SOLUTION);
  }
}

Object* accessQuerySolutionSlotValue(QuerySolution* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_LOGIC_BINDINGS) {
    if (setvalueP) {
      self->bindings = ((Vector*)(value));
    }
    else {
      value = self->bindings;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_TRUTH_VALUE) {
    if (setvalueP) {
      self->truthValue = ((TruthValue*)(value));
    }
    else {
      value = self->truthValue;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_MATCH_SCORE) {
    if (setvalueP) {
      self->matchScore = ((FloatWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapFloat(self->matchScore);
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_JUSTIFICATION) {
    if (setvalueP) {
      self->justification = ((Justification*)(value));
    }
    else {
      value = self->justification;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_BEST_JUSTIFICATION) {
    if (setvalueP) {
      self->justification = ((Justification*)(value));
    }
    else {
      value = self->justification;
    }
  }
  else if (slotname == SYM_QUERY_LOGIC_ALL_JUSTIFICATIONS) {
    if (setvalueP) {
      self->allJustifications = ((List*)(value));
    }
    else {
      value = self->allJustifications;
    }
  }
  else if (slotname == SYM_QUERY_STELLA_NEXT) {
    if (setvalueP) {
      self->next = ((QuerySolution*)(value));
    }
    else {
      value = self->next;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

Object* QuerySolutionTable::lookup(Vector* key) {
  // Lookup the solution identified by `key' in `self' and
  // return its value, or NULL if no such solution exists.
  { QuerySolutionTable* self = this;

    return (((QuerySolution*)(self->theMap->lookup(key))));
  }
}

void QuerySolutionTable::insertAt(Vector* key, QuerySolution* value) {
  // Insert `value' identified by `key' into `self'.  If a solution
  // with that key already exists, destructively modify it with the slot values of
  // `value'.  This is necessary to preserve the order of solutions in `self'.
  { QuerySolutionTable* self = this;

    { KeyValueMap* map = self->theMap;
      QuerySolution* duplicate = ((QuerySolution*)(map->lookup(key)));

      if (((boolean)(duplicate))) {
        duplicate->truthValue = value->truthValue;
        duplicate->matchScore = value->matchScore;
        duplicate->justification = value->justification;
        duplicate->allJustifications = value->allJustifications;
      }
      else {
        map->insertAt(key, value);
        if (!((boolean)(self->first))) {
          self->first = value;
          self->last = value;
        }
        else {
          self->last->next = value;
          self->last = value;
        }
      }
    }
  }
}

boolean QuerySolution::deletedP() {
  { QuerySolution* self = this;

    return (!((boolean)(self->bindings)));
  }
}

boolean QuerySolution::deletedPSetter(boolean value) {
  { QuerySolution* self = this;

    if (value) {
      self->bindings = NULL;
    }
    else {
      self->bindings = stella::vector(0);
    }
    return (value);
  }
}

void QuerySolutionTable::removeAt(Vector* key) {
  // Remove the solution identified by `key' from `self'.
  // To preserve the solution ordering chain, the solution is marked as deleted
  // and will be completely removed upon the next iteration through `self'.
  { QuerySolutionTable* self = this;

    { KeyValueMap* map = self->theMap;
      QuerySolution* solution = ((QuerySolution*)(map->lookup(key)));

      if (((boolean)(solution))) {
        map->removeAt(key);
        solution->deletedPSetter(true);
      }
    }
  }
}

QuerySolution* QuerySolutionTable::pop() {
  // Remove and return the first solution of `self' or NULL
  // if the table is empty.
  { QuerySolutionTable* self = this;

    { QuerySolution* first = self->first;

      if (((boolean)(first))) {
        self->first = first->next;
        if (first == self->last) {
          self->last = NULL;
        }
        self->theMap->removeAt(first->bindings);
      }
      return (first);
    }
  }
}

int QuerySolutionTable::length() {
  // Return the number of entries in `self'.
  { QuerySolutionTable* self = this;

    return (self->theMap->length());
  }
}

boolean QuerySolutionTable::emptyP() {
  // Return TRUE if `self' has zero entries.
  { QuerySolutionTable* self = this;

    return (self->theMap->emptyP());
  }
}

boolean QuerySolutionTable::nonEmptyP() {
  // Return TRUE if `self' has at least 1 entry.
  { QuerySolutionTable* self = this;

    return (self->theMap->nonEmptyP());
  }
}

QuerySolution* QuerySolutionTable::nth(int position) {
  // Return the nth solution in `self', or NULL if it is empty.
  { QuerySolutionTable* self = this;

    { QuerySolution* solution = NULL;
      DictionaryIterator* iter000 = ((DictionaryIterator*)(self->allocateIterator()));

      for (solution, iter000; iter000->nextP(); ) {
        solution = ((QuerySolution*)(iter000->value));
        if (position == 0) {
          return (solution);
        }
        else {
          position = position - 1;
        }
      }
    }
    return (NULL);
  }
}

void QuerySolutionTable::clear() {
  { QuerySolutionTable* self = this;

    self->theMap->clear();
    self->first = NULL;
    self->last = NULL;
  }
}

Cons* QuerySolutionTable::consify() {
  // Collect all solutions of `self' into a cons list and return the result.
  { QuerySolutionTable* self = this;

    { Cons* result = NIL;

      { QuerySolution* solution = NULL;
        DictionaryIterator* iter000 = ((DictionaryIterator*)(self->allocateIterator()));
        Cons* collect000 = NULL;

        for  (solution, iter000, collect000; 
              iter000->nextP(); ) {
          solution = ((QuerySolution*)(iter000->value));
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(solution, NIL);
              if (result == NIL) {
                result = collect000;
              }
              else {
                addConsToEndOfConsList(result, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(solution, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      return (result);
    }
  }
}

QuerySolutionTable* QuerySolutionTable::sort(cpp_function_code predicate) {
  // Perform a stable, destructive sort of `self' according to
  // `predicate', and return the result.  If `predicate' has a '<' semantics, the
  // result will be in ascending order.
  { QuerySolutionTable* self = this;

    { Cons* solutions = self->consify()->sort(predicate);
      QuerySolution* current = NULL;
      QuerySolution* next = NULL;

      self->first = ((QuerySolution*)(solutions->value));
      self->last = ((QuerySolution*)(solutions->value));
      for (;;) {
        current = ((QuerySolution*)(solutions->value));
        if (((boolean)(current))) {
          next = ((QuerySolution*)(solutions->rest->value));
          current->next = next;
          if (!((boolean)(next))) {
            self->last = current;
          }
          solutions = solutions->rest;
        }
        else {
          break;
        }
      }
      return (self);
    }
  }
}

QuerySolutionTableIterator* newQuerySolutionTableIterator() {
  { QuerySolutionTableIterator* self = NULL;

    self = new QuerySolutionTableIterator();
    self->firstIterationP = true;
    self->value = NULL;
    self->key = NULL;
    self->cursor = NULL;
    self->theTable = NULL;
    return (self);
  }
}

Surrogate* QuerySolutionTableIterator::primaryType() {
  { QuerySolutionTableIterator* self = this;

    return (SGT_QUERY_LOGIC_QUERY_SOLUTION_TABLE_ITERATOR);
  }
}

Object* accessQuerySolutionTableIteratorSlotValue(QuerySolutionTableIterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_STELLA_THE_TABLE) {
    if (setvalueP) {
      self->theTable = ((QuerySolutionTable*)(value));
    }
    else {
      value = self->theTable;
    }
  }
  else if (slotname == SYM_QUERY_STELLA_CURSOR) {
    if (setvalueP) {
      self->cursor = ((QuerySolution*)(value));
    }
    else {
      value = self->cursor;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

AbstractIterator* QuerySolutionTable::allocateIterator() {
  { QuerySolutionTable* self = this;

    { QuerySolutionTableIterator* self000 = newQuerySolutionTableIterator();

      self000->theTable = self;
      { QuerySolutionTableIterator* value000 = self000;

        return (value000);
      }
    }
  }
}

boolean QuerySolutionTableIterator::nextP() {
  { QuerySolutionTableIterator* self = this;

    { QuerySolutionTable* table = self->theTable;
      QuerySolution* cursor = self->cursor;
      QuerySolution* previous = cursor;

      if (self->firstIterationP) {
        previous = NULL;
        cursor = table->first;
        self->firstIterationP = false;
      }
      else {
        previous = cursor;
        cursor = cursor->next;
      }
      while (((boolean)(cursor)) &&
          cursor->deletedP()) {
        cursor = cursor->next;
      }
      self->cursor = cursor;
      if (((boolean)(cursor))) {
        if (!((boolean)(previous))) {
          table->first = cursor;
        }
        else {
          previous->next = cursor;
        }
        self->key = cursor->bindings;
        self->value = cursor;
        return (true);
      }
      else if (((boolean)(previous))) {
        previous->next = NULL;
        table->last = previous;
      }
      return (false);
    }
  }
}

void printControlFrame(ControlFrame* self, std::ostream* stream) {
  if (subtypeOfP(safePrimaryType(self), SGT_QUERY_LOGIC_PARALLEL_CONTROL_FRAME)) {
    { ControlFrame* self000 = self;
      ParallelControlFrame* self = ((ParallelControlFrame*)(self000));

      *(stream) << "|PLL-CF|" << debugFrameId(self) << "[";
    }
  }
  else {
    *(stream) << "|CF|" << debugFrameId(self) << "[";
  }
  if (self->choicePointUnbindingOffset != NULL_INTEGER) {
    *(stream) << self->choicePointUnbindingOffset;
  }
  else {
    *(stream) << "_";
  }
  { 
    BIND_STELLA_SPECIAL(oPRINTINFRAMEo, ControlFrame*, self);
    { boolean printtimesP = self->allottedClockTicks != NULL_INTEGER;

      *(stream) << " " << self->state << " " << self->currentStrategy;
      if (((boolean)(self->up))) {
        *(stream) << "  UP: " << debugFrameId(self->up);
      }
      else {
        *(stream) << "  UP: -";
      }
      if (((boolean)(self->down))) {
        *(stream) << "  DOWN: " << debugFrameId(self->down);
      }
      else {
        *(stream) << "  DOWN: -";
      }
      *(stream) << "  DEPTH: " << computeFrameDepth(self);
      if (((boolean)(((Description*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_DESCRIPTION, NULL)))))) {
        *(stream) << " DESC: " << ((Description*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_DESCRIPTION, NULL)));
      }
      if (printtimesP) {
        *(stream) << " CLOCK: " << oQUERYITERATORo.get()->currentClockTicks << " START: " << self->startingClockTicks << " TICKS: " << self->allottedClockTicks;
      }
      *(stream) << " " << self->proposition << "]";
    }
  }
}

void printGoalStack(ControlFrame* frame, boolean verboseP) {
  // Print stack of goals.  Assumes that query has been interrupted
  // with a full stack of control frames.
  if (((boolean)(frame->proposition))) {
    { 
      BIND_STELLA_SPECIAL(oPRINTINFRAMEo, ControlFrame*, frame);
      if (verboseP) {
        {
          printControlFrame(frame, STANDARD_OUTPUT->nativeStream);
          std::cout << std::endl;
        }
      }
      else {
        std::cout << frame->proposition << std::endl;
      }
    }
  }
  if (((boolean)(frame->down))) {
    printGoalStack(frame->down, verboseP);
  }
}

void pgs() {
  printGoalStack(oQUERYITERATORo.get()->baseControlFrame, false);
}

void vpgs() {
  printGoalStack(oQUERYITERATORo.get()->baseControlFrame, true);
}

void printQueryIterator(QueryIterator* self, std::ostream* stream) {
  if (oPRINTREADABLYpo.get()) {
    printQueryIteratorReadably(self, stream);
  }
  else {
    printQueryIteratorOrnately(self, stream);
  }
}

void printQueryIteratorOrnately(QueryIterator* self, std::ostream* stream) {
  { QuerySolutionTable* solutions = self->solutions;
    int nofsolutions = solutions->length();
    boolean exhaustedP = self->exhaustedP;

    switch (nofsolutions) {
      case 0: 
        *(stream) << "No solutions";
      break;
      case 1: 
        *(stream) << "There is 1 solution";
      break;
      default:
        *(stream) << "There are " << nofsolutions << " solutions";
      break;
    }
    if (!(exhaustedP)) {
      *(stream) << " so far";
    }
    if (self->timeoutP) {
      *(stream) << " (timeout)";
    }
    if (nofsolutions == 0) {
      *(stream) << "." << std::endl;
      return;
    }
    *(stream) << ":" << std::endl;
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
      { QuerySolution* solution = NULL;
        DictionaryIterator* iter000 = ((DictionaryIterator*)(solutions->allocateIterator()));
        int i = NULL_INTEGER;
        int iter001 = 1;
        int upperBound000 = oPRINTLENGTHo.get();
        boolean unboundedP000 = upperBound000 == NULL_INTEGER;

        for  (solution, iter000, i, iter001, upperBound000, unboundedP000; 
              iter000->nextP() &&
                  (unboundedP000 ||
                   (iter001 <= upperBound000)); 
              iter001 = iter001 + 1) {
          solution = ((QuerySolution*)(iter000->value));
          i = iter001;
          printQueryIteratorSolutionOrnately(self, solution, i, stream);
          if (i < nofsolutions) {
            *(stream) << std::endl;
          }
          if ((i == oPRINTLENGTHo.get()) &&
              (i < nofsolutions)) {
            *(stream) << "  ......" << std::endl;
          }
        }
      }
    }
  }
}

void printQueryIteratorSolutionOrnately(QueryIterator* self, QuerySolution* solution, int solutionnumber, std::ostream* stream) {
  if (solutionnumber == NULL_INTEGER) {
    solutionnumber = 0;
    { QuerySolution* solution = NULL;
      DictionaryIterator* iter000 = ((DictionaryIterator*)(self->solutions->allocateIterator()));

      for (solution, iter000; iter000->nextP(); ) {
        solution = ((QuerySolution*)(iter000->value));
        if (!equalP(solution->bindings, solution)) {
          solutionnumber = solutionnumber + 1;
        }
      }
    }
  }
  { 
    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
    *(stream) << "  #" << solutionnumber << ": ";
    { Object* value = NULL;
      Vector* vector000 = solution->bindings;
      int index000 = 0;
      int length000 = vector000->length();
      PatternVariable* variable = NULL;
      Vector* vector001 = self->externalVariables;
      int index001 = 0;
      int length001 = vector001->length();
      int vi = NULL_INTEGER;
      int iter001 = 0;

      for  (value, vector000, index000, length000, variable, vector001, index001, length001, vi, iter001; 
            (index000 < length000) &&
                (index001 < length001); 
            index000 = index000 + 1,
            index001 = index001 + 1,
            iter001 = iter001 + 1) {
        value = (vector000->theArray)[index000];
        variable = ((PatternVariable*)((vector001->theArray)[index001]));
        vi = iter001;
        *(stream) << (((vi == 0) ? (char*)"" : (char*)", ")) << variable->skolemName << "=" << value;
      }
    }
    if (((boolean)(self->partialMatchStrategy)) &&
        (solution->matchScore != NULL_FLOAT)) {
      *(stream) << " " << solution->matchScore;
    }
  }
}

void traceSolution(QueryIterator* self, QuerySolution* solution, int solutionnumber) {
  if (traceKeywordP(KWD_QUERY_TRACE_SOLUTIONS)) {
    std::cout << "SOLUTION ";
    printQueryIteratorSolutionOrnately(oQUERYITERATORo.get(), solution, solutionnumber, STANDARD_OUTPUT->nativeStream);
    std::cout << std::endl;
  }
}

void printQueryIteratorReadably(QueryIterator* self, std::ostream* stream) {
  { QuerySolutionTable* solutions = self->solutions;
    boolean firstP = true;
    boolean atomicsingletonsP = ((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_ATOMIC_SINGLETONSp, FALSE_WRAPPER)))->wrapperValue &&
        (!((boolean)(self->partialMatchStrategy)));

    *(stream) << "(";
    { QuerySolution* solution = NULL;
      DictionaryIterator* iter000 = ((DictionaryIterator*)(solutions->allocateIterator()));
      int i = NULL_INTEGER;
      int iter001 = 1;
      int upperBound000 = oPRINTLENGTHo.get();
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      for  (solution, iter000, i, iter001, upperBound000, unboundedP000; 
            iter000->nextP() &&
                (unboundedP000 ||
                 (iter001 <= upperBound000)); 
            iter001 = iter001 + 1) {
        solution = ((QuerySolution*)(iter000->value));
        i = iter001;
        if (!(firstP)) {
          if (atomicsingletonsP) {
            *(stream) << " ";
          }
          else {
            *(stream) << std::endl << " ";
          }
        }
        firstP = false;
        if (!(atomicsingletonsP)) {
          *(stream) << "(";
        }
        { Object* value = NULL;
          Vector* vector000 = solution->bindings;
          int index000 = 0;
          int length000 = vector000->length();
          int vi = NULL_INTEGER;
          int iter002 = 0;

          for  (value, vector000, index000, length000, vi, iter002; 
                index000 < length000; 
                index000 = index000 + 1,
                iter002 = iter002 + 1) {
            value = (vector000->theArray)[index000];
            vi = iter002;
            *(stream) << (((vi == 0) ? (char*)"" : (char*)" ")) << value;
            if (((boolean)(self->partialMatchStrategy))) {
              *(stream) << " " << solution->matchScore;
            }
          }
        }
        if (!(atomicsingletonsP)) {
          *(stream) << ")";
        }
        if ((i == oPRINTLENGTHo.get()) &&
            (i < solutions->length())) {
          *(stream) << " ...";
        }
      }
    }
    *(stream) << ")" << std::endl;
  }
}

QueryIterator* allocateQueryIterator() {
  { QueryIterator* queryiterator = newQueryIterator();

    updateNowTimestamp(KWD_QUERY_EXECUTE_QUERY);
    queryiterator->timestamp = getNowTimestamp();
    return (queryiterator);
  }
}

void QueryIterator::free() {
  { QueryIterator* self = this;

    freeQueryIterator(self);
  }
}

void freeQueryIterator(QueryIterator* self) {
  if (!((boolean)(self->baseControlFrame))) {
    return;
  }
  ((QuerySolution*)(self->value))->free();
  self->baseControlFrame = NULL;
}

Vector* allocateCollectionVariables(ControlFrame* frame, Description* description) {
  { int variablescount = description->ioVariables->length();
    Vector* externalvariables = newVector(variablescount);

    { PatternVariable* iovar = NULL;
      Vector* vector000 = description->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();
      int i = NULL_INTEGER;
      int iter000 = 0;

      for  (iovar, vector000, index000, length000, i, iter000; 
            index000 < length000; 
            index000 = index000 + 1,
            iter000 = iter000 + 1) {
        iovar = ((PatternVariable*)((vector000->theArray)[index000]));
        i = iter000;
        (externalvariables->theArray)[i] = (createVariable(iovar->skolemType, iovar->skolemName, false));
        ((PatternVariable*)((externalvariables->theArray)[i]))->boundToOffset = i;
      }
    }
    if (!((boolean)(frame->patternRecord))) {
      createPatternRecord(frame, NULL, NULL);
    }
    activatePatternRecord(frame->patternRecord, variablescount);
    return (externalvariables);
  }
}

QueryIterator* createQueryIterator(Description* description, Vector* outsidebindings) {
  return (initializeQueryIterator(allocateQueryIterator(), description, outsidebindings));
}

QueryIterator* initializeQueryIterator(QueryIterator* queryiterator, Description* description, Vector* outsidebindings) {
  { ControlFrame* basecontrolframe = newControlFrame();
    Vector* externalvariables = NULL;

    { 
      BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, queryiterator);
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_QUERY_DESCRIPTION);
      if (testQueryOptionP(queryiterator, KWD_QUERY_DONT_OPTIMIZEp)) {
        setDynamicSlotValue(description->dynamicSlots, SYM_QUERY_LOGIC_DONT_OPTIMIZEp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
        setDynamicSlotValue(description->proposition->dynamicSlots, SYM_QUERY_LOGIC_DONT_OPTIMIZEp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
      }
      queryiterator->queryContext = oCONTEXTo.get();
      queryiterator->baseControlFrame = basecontrolframe;
      queryiterator->currentControlFrame = basecontrolframe;
      oCONTROL_FRAME_ID_COUNTERo = 0;
      basecontrolframe->proposition = description->proposition;
      basecontrolframe->up = NULL;
      setDynamicSlotValue(basecontrolframe->dynamicSlots, SYM_QUERY_LOGIC_GOAL_CACHE, NULL, NULL);
      basecontrolframe->goalBindings = NULL;
      externalvariables = allocateCollectionVariables(basecontrolframe, description);
      { 
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, getQueryContext());
        BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
        if (((boolean)(outsidebindings))) {
          setDynamicSlotValue(queryiterator->dynamicSlots, SYM_QUERY_LOGIC_INITIAL_BINDINGS, outsidebindings, NULL);
          if (outsidebindings->length() > externalvariables->length()) {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "Arity mismatch between bindings " << "`" << outsidebindings << "'" << " and external variables " << "`" << externalvariables << "'" << ".";
              throw *newFailException(stream000->theStringReader());
            }
          }
          { PatternVariable* arg = NULL;
            Vector* vector000 = externalvariables;
            int index000 = 0;
            int length000 = vector000->length();
            Object* value = NULL;
            Vector* vector001 = outsidebindings;
            int index001 = 0;
            int length001 = vector001->length();

            for  (arg, vector000, index000, length000, value, vector001, index001, length001; 
                  (index000 < length000) &&
                      (index001 < length001); 
                  index000 = index000 + 1,
                  index001 = index001 + 1) {
              arg = ((PatternVariable*)((vector000->theArray)[index000]));
              value = (vector001->theArray)[index001];
              if (((boolean)(value)) &&
                  (!bindArgumentToValueP(arg, value, false))) {
                { OutputStringStream* stream001 = newOutputStringStream();

                  *(stream001->nativeStream) << "Binding of " << "`" << arg << "'" << " to " << "`" << value << "'" << " failed.";
                  throw *newFailException(stream001->theStringReader());
                }
              }
            }
          }
        }
        overlayWithPatternFrameP(basecontrolframe, description, externalvariables);
      }
      queryiterator->controlFramePriorityQueue = newControlFramePriorityQueue();
      if (queryiterator->maximumDepth == NULL_INTEGER) {
        queryiterator->maximumDepth = oMAXIMUM_BACKTRACKING_DEPTHo;
      }
      queryiterator->augmentedGoalCacheP = false;
      queryiterator->activeGoalCaches->clear();
      if (oITERATIVE_DEEPENING_MODEpo &&
          (!testQueryOptionP(queryiterator, KWD_QUERY_ITERATIVE_DEEPENINGp))) {
        setDynamicSlotValue(queryiterator->dynamicSlots, SYM_QUERY_LOGIC_ITERATIVE_DEEPENINGp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
      }
      queryiterator->currentDepthCutoff = (((BooleanWrapper*)(dynamicSlotValue(queryiterator->dynamicSlots, SYM_QUERY_LOGIC_ITERATIVE_DEEPENINGp, FALSE_WRAPPER)))->wrapperValue ? stella::min(oINITIAL_BACKTRACKING_DEPTHo, queryiterator->maximumDepth) : queryiterator->maximumDepth);
      queryiterator->triggeredDepthCutoffP = false;
      queryiterator->failedToFindDuplicateSubgoalP = false;
      queryiterator->foundAtLeastOneSolutionP = false;
      queryiterator->externalVariables = externalvariables;
      return (queryiterator);
    }
  }
}

Proposition* QueryIterator::queryProposition() {
  { QueryIterator* self = this;

    return (self->baseControlFrame->proposition);
  }
}

Description* QueryIterator::queryDescription() {
  { QueryIterator* self = this;

    return (self->baseControlFrame->patternRecord->description);
  }
}

boolean QueryIterator::queryIsTrueFalseP() {
  { QueryIterator* self = this;

    if (self->externalVariables->arraySize == 0) {
      return (true);
    }
    { PatternRecord* patternrecord = self->baseControlFrame->patternRecord;

      { boolean alwaysP000 = true;

        { Object* ignoredArg = NULL;
          Vector* vector000 = patternrecord->externalArguments;
          int index000 = 0;
          int length000 = vector000->length();
          BooleanWrapper* boundP = NULL;
          BooleanVector* vector001 = patternrecord->booleanVector;
          int index001 = 0;
          int length001 = vector001->length();

          for  (ignoredArg, vector000, index000, length000, boundP, vector001, index001, length001; 
                (index000 < length000) &&
                    (index001 < length001); 
                index000 = index000 + 1,
                index001 = index001 + 1) {
            ignoredArg = (vector000->theArray)[index000];
            boundP = ((BooleanWrapper*)((vector001->theArray)[index001]));
            if (!coerceWrappedBooleanToBoolean(boundP)) {
              alwaysP000 = false;
              break;
            }
          }
        }
        { boolean value000 = alwaysP000;

          return (value000);
        }
      }
    }
  }
}

boolean QueryIterator::queryIsPartialP() {
  { QueryIterator* self = this;

    if (((boolean)(self->partialMatchStrategy))) {
      return (true);
    }
    { Object* matchmode = lookupQueryOption(self, KWD_QUERY_MATCH_MODE);

      return (((boolean)(matchmode)) &&
          (!(matchmode == KWD_QUERY_STRICT)));
    }
  }
}

boolean QueryIterator::querySucceededP() {
  { QueryIterator* self = this;

    return (self->solutions->nonEmptyP());
  }
}

boolean QueryIterator::nextP() {
  { QueryIterator* self = this;

    if (self->exhaustedP) {
      return (false);
    }
    { ControlFrame* baseframe = self->baseControlFrame;

      { QuerySolution* self000 = newQuerySolution();

        self000->bindings = newVector(self->externalVariables->length());
        self000->truthValue = UNKNOWN_TRUTH_VALUE;
        { QuerySolution* solution = self000;
          QuerySolution* duplicate = NULL;

          self->value = solution;
          if (self->firstIterationP) {
            self->firstIterationP = false;
            { PropertyList* skippedoptions = ((PropertyList*)(lookupQueryOption(self, KWD_QUERY_DEFERRED_OPTIONS)));

              if (((boolean)(skippedoptions)) &&
                  skippedoptions->nonEmptyP()) {
                { OutputStringStream* stream000 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream000->nativeStream) << "PARSING ERROR: " << "Illegal query option(s): " << "`" << skippedoptions << "'" << "." << std::endl;
                    helpSignalPropositionError(stream000, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream000->theStringReader());
                }
              }
            }
          }
          for (;;) {
            { 
              BIND_STELLA_SPECIAL(oCONTEXTo, Context*, getQueryContext());
              BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
              for (;;) {
                solution->bindings->clear();
                solution->truthValue = UNKNOWN_TRUTH_VALUE;
                solution->justification = NULL;
                solution->matchScore = NULL_FLOAT;
                if (!executeBackwardChainingProofP(self)) {
                  break;
                }
                { PatternVariable* ev = NULL;
                  Vector* vector000 = self->externalVariables;
                  int index000 = 0;
                  int length000 = vector000->length();
                  int i = NULL_INTEGER;
                  int iter000 = 0;

                  for  (ev, vector000, index000, length000, i, iter000; 
                        index000 < length000; 
                        index000 = index000 + 1,
                        iter000 = iter000 + 1) {
                    ev = ((PatternVariable*)((vector000->theArray)[index000]));
                    i = iter000;
                    (solution->bindings->theArray)[i] = ((oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(ev->boundToOffset)]);
                  }
                }
                self->foundAtLeastOneSolutionP = true;
                { TruthValue* temp000 = baseframe->truthValue;

                  solution->truthValue = (((boolean)(temp000)) ? temp000 : UNKNOWN_TRUTH_VALUE);
                }
                solution->justification = ((Justification*)(dynamicSlotValue(baseframe->dynamicSlots, SYM_QUERY_LOGIC_JUSTIFICATION, NULL)));
                if (((boolean)(oQUERYITERATORo.get())) &&
                    ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
                  solution->matchScore = ((((boolean)(baseframe->partialMatchFrame)) &&
                      ((baseframe->partialMatchFrame->positiveScore != NULL_FLOAT) ||
                       (baseframe->partialMatchFrame->negativeScore != NULL_FLOAT))) ? baseframe->partialMatchFrame->positiveScore : ((FloatWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE, NULL_FLOAT_WRAPPER)))->wrapperValue);
                }
                duplicate = ((QuerySolution*)(self->solutions->lookup(solution->bindings)));
                if (((boolean)(duplicate)) &&
                    ((!(((boolean)(oQUERYITERATORo.get())) &&
                    ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy)))) ||
                     (solution->matchScore <= duplicate->matchScore))) {
                  continue;
                }
                if (((baseframe->truthValue == DEFAULT_TRUE_TRUTH_VALUE) ||
                    (baseframe->truthValue == DEFAULT_FALSE_TRUTH_VALUE)) &&
                    tryToDefeatLastAnswerP(self)) {
                  continue;
                }
                baseframe->truthValue = solution->truthValue;
                setDynamicSlotValue(baseframe->dynamicSlots, SYM_QUERY_LOGIC_JUSTIFICATION, solution->justification, NULL);
                self->solutions->insertAt(solution->bindings, solution);
                return (true);
              }
            }
            if (self->timeoutP) {
              return (false);
            }
            else if (self->augmentedGoalCacheP) {
              self->reset();
            }
            else if (((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_ITERATIVE_DEEPENINGp, FALSE_WRAPPER)))->wrapperValue &&
                (self->triggeredDepthCutoffP &&
                 (self->currentDepthCutoff < self->maximumDepth))) {
              self->currentDepthCutoff = self->currentDepthCutoff + 1;
              self->reset();
            }
            else {
              if (self->failedToFindDuplicateSubgoalP &&
                  (!self->foundAtLeastOneSolutionP)) {
                std::cout << "Failed to find a duplicate subgoal on one or more occurrences when" << std::endl << "   the depth cutoff " << self->currentDepthCutoff << " was exceeded.  Consider increasing the cutoff" << std::endl << "   (by setting the variable *maximum-backtracking-depth*)" << std::endl << "   and trying again." << std::endl;
              }
              self->exhaustedP = true;
              return (false);
            }
          }
        }
      }
    }
  }
}

boolean tryToDefeatLastAnswerP(QueryIterator* self) {
  { QueryIterator* negatedquery = (self->queryIsTrueFalseP() ? self : ((QueryIterator*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_AUXILIARY_QUERY, NULL))));
    Context* querycontext = self->queryContext;
    boolean strictpositiveanswerP = false;
    boolean strictnegativeanswerP = false;
    boolean defeatedP = false;

    if (!((boolean)(negatedquery))) {
      negatedquery = createQueryIterator(self->queryDescription(), ((QuerySolution*)(self->value))->bindings);
      negatedquery->queryContext = querycontext;
    }
    else {
      if (self == ((QueryIterator*)(dynamicSlotValue(negatedquery->dynamicSlots, SYM_QUERY_LOGIC_AUXILIARY_QUERY, NULL)))) {
        return (false);
      }
      setDynamicSlotValue(negatedquery->dynamicSlots, SYM_QUERY_LOGIC_INITIAL_BINDINGS, ((QuerySolution*)(self->value))->bindings, NULL);
    }
    setDynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_AUXILIARY_QUERY, negatedquery, NULL);
    setDynamicSlotValue(negatedquery->dynamicSlots, SYM_QUERY_LOGIC_AUXILIARY_QUERY, self, NULL);
    negatedquery->baseControlFrame->reversePolarityP = true;
    negatedquery->reset();
    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE)) {
      std::cout << "Looking for conflicting default conclusion:" << std::endl;
    }
    if (negatedquery->nextP()) {
      negatedquery->reset();
      { 
        BIND_STELLA_SPECIAL(oDONTUSEDEFAULTKNOWLEDGEpo, boolean, true);
        if (((boolean)(oTRACED_KEYWORDSo)) &&
            oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE)) {
          std::cout << "Looking for conflicting strict conclusion:" << std::endl;
        }
        strictnegativeanswerP = negatedquery->nextP();
      }
      negatedquery->baseControlFrame->reversePolarityP = false;
      negatedquery->reset();
      { 
        BIND_STELLA_SPECIAL(oDONTUSEDEFAULTKNOWLEDGEpo, boolean, true);
        if (((boolean)(oTRACED_KEYWORDSo)) &&
            oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE)) {
          std::cout << "Looking for strict conclusion:" << std::endl;
        }
        strictpositiveanswerP = negatedquery->nextP();
      }
      if (strictpositiveanswerP) {
        if (strictnegativeanswerP) {
          { 
            BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, negatedquery);
            std::cout << std::endl << "CONTRADICTION: Discovered strict arguments for" << std::endl << "    " << "`" << negatedquery->baseControlFrame->proposition << "'" << std::endl << "and its negation." << std::endl << std::endl;
          }
          defeatedP = true;
        }
        else {
          defeatedP = false;
        }
      }
      else {
        defeatedP = true;
      }
    }
    setDynamicSlotValue(negatedquery->dynamicSlots, SYM_QUERY_LOGIC_AUXILIARY_QUERY, NULL, NULL);
    return (defeatedP);
  }
}

void QueryIterator::reset() {
  { QueryIterator* self = this;

    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_CACHES)) {
      std::cout << "------------- RESET -------------" << std::endl;
    }
    { ControlFrame* initialframe = self->baseControlFrame;

      if (((boolean)(initialframe->down))) {
        popFramesUpTo(initialframe->down);
      }
      { PatternRecord* patternrecord = initialframe->patternRecord;

        self->currentPatternRecord = patternrecord;
        { 
          BIND_STELLA_SPECIAL(oCONTEXTo, Context*, getQueryContext());
          BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, self);
          unbindVariablesBeginningAt(patternrecord, 0);
          if (((boolean)(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_INITIAL_BINDINGS, NULL)))))) {
            { PatternVariable* arg = NULL;
              Vector* vector000 = self->externalVariables;
              int index000 = 0;
              int length000 = vector000->length();
              Object* value = NULL;
              Vector* vector001 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_INITIAL_BINDINGS, NULL)));
              int index001 = 0;
              int length001 = vector001->length();

              for  (arg, vector000, index000, length000, value, vector001, index001, length001; 
                    (index000 < length000) &&
                        (index001 < length001); 
                    index000 = index000 + 1,
                    index001 = index001 + 1) {
                arg = ((PatternVariable*)((vector000->theArray)[index000]));
                value = (vector001->theArray)[index001];
                if (((boolean)(value))) {
                  if (!(bindArgumentToValueP(arg, value, false))) {
                    { OutputStringStream* stream000 = newOutputStringStream();

                      *(stream000->nativeStream) << "reset: binding of " << "`" << arg << "'" << " to " << "`" << value << "'" << " failed.";
                      throw *newFailException(stream000->theStringReader());
                    }
                  }
                }
              }
            }
          }
          overlayWithPatternFrameP(initialframe, patternrecord->description, patternrecord->externalArguments);
        }
      }
      self->exhaustedP = false;
      self->timeoutP = false;
      self->solutions->clear();
      initialframe->truthValue = NULL;
      self->augmentedGoalCacheP = false;
      self->triggeredDepthCutoffP = false;
    }
  }
}

Cons* standardizeQueryTree(Object* iovariables, Object* querybody, Cons* externalvariables) {
  if (!((boolean)(iovariables))) {
    iovariables = NIL;
  }
  else if (!consP(iovariables)) {
    iovariables = consList(1, iovariables);
  }
  { Cons* standardizedtree = NULL;
    Cons* allvariables = ((Cons*)(iovariables));

    { Object* v = NULL;
      Cons* iter000 = externalvariables->reverse();

      for (v, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        v = iter000->value;
        allvariables = cons(v, allvariables);
      }
    }
    if (!((boolean)(querybody))) {
      querybody = SYM_QUERY_STELLA_TRUE;
    }
    if (allvariables == NIL) {
      standardizedtree = listO(4, SYM_QUERY_LOGIC_KAPPA, NIL, querybody, NIL);
    }
    else {
      standardizedtree = listO(3, SYM_QUERY_STELLA_EXISTS, allvariables, cons(querybody, NIL));
    }
    standardizedtree = ((Cons*)(standardizeLogicalParseTree(standardizedtree)));
    standardizedtree->firstSetter(SYM_QUERY_LOGIC_KAPPA);
    return (standardizedtree);
  }
}

QueryIterator* makeQuery(Object* iovariables, Object* querytree, Cons* externalbindings, Object* options) {
  finalizeObjects();
  processCheckTypesAgenda();
  { Cons* prefixquerytree = standardizeQueryTree(iovariables, querytree, NIL);
    Vector* externalvector = ((!(externalbindings == NIL)) ? copyListToArgumentsVector(externalbindings->listify()) : ((Vector*)(NULL)));
    Description* description = NULL;
    QueryIterator* query = allocateQueryIterator();

    if ((!consP(iovariables)) ||
        surrogateP(((Cons*)(iovariables))->rest->value)) {
      setDynamicSlotValue(query->dynamicSlots, SYM_QUERY_LOGIC_ATOMIC_SINGLETONSp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
    { 
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_QUERY_DESCRIPTION);
      BIND_STELLA_SPECIAL(oLOGICVARIABLETABLEo, Cons*, NIL);
      BIND_STELLA_SPECIAL(oTERMUNDERCONSTRUCTIONo, Object*, prefixquerytree);
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, oMODULEo.get());
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
        description = evaluateDescriptionTerm(prefixquerytree, false);
      }
    }
    processCheckTypesAgenda();
    if (((boolean)(options))) {
      processQueryOptions(query, options);
    }
    return (initializeQueryIterator(query, description, externalvector));
  }
}

Object* parseQueryAndOptions(Cons* queryAoptions, Object*& _Return1, PropertyList*& _Return2) {
  if ((!((boolean)(queryAoptions))) ||
      (queryAoptions == NIL)) {
    { Object* _Return0 = NULL;

      _Return1 = NULL;
      _Return2 = newPropertyList();
      return (_Return0);
    }
  }
  { Object* firstarg = queryAoptions->value;
    Object* variables = NULL;
    Object* proposition = NULL;
    PropertyList* options = newPropertyList();

    { Surrogate* testValue000 = safePrimaryType(firstarg);

      if (subtypeOfIntegerP(testValue000)) {
        { Object* firstarg000 = firstarg;
          IntegerWrapper* firstarg = ((IntegerWrapper*)(firstarg000));

          options->insertAt(KWD_QUERY_HOW_MANY, firstarg);
          queryAoptions = queryAoptions->rest;
        }
      }
      else if (subtypeOfSymbolP(testValue000)) {
        { Object* firstarg001 = firstarg;
          Symbol* firstarg = ((Symbol*)(firstarg001));

          if (stringEqualP(firstarg->symbolName, "ALL")) {
            options->insertAt(KWD_QUERY_HOW_MANY, wrapInteger(NULL_INTEGER));
            queryAoptions = queryAoptions->rest;
          }
          else if (stringEqualP(firstarg->symbolName, "BEST")) {
            options->insertAt(KWD_QUERY_HOW_MANY, wrapInteger(NULL_INTEGER));
            options->insertAt(KWD_QUERY_SORT_BY, KWD_QUERY_SCORE);
            queryAoptions = queryAoptions->rest;
          }
        }
      }
      else if (subtypeOfKeywordP(testValue000)) {
        { Object* firstarg002 = firstarg;
          Keyword* firstarg = ((Keyword*)(firstarg002));

          if (stringEqualP(firstarg->symbolName, "ALL")) {
            options->insertAt(KWD_QUERY_HOW_MANY, wrapInteger(NULL_INTEGER));
            queryAoptions = queryAoptions->rest;
          }
          else if (stringEqualP(firstarg->symbolName, "BEST")) {
            options->insertAt(KWD_QUERY_HOW_MANY, wrapInteger(NULL_INTEGER));
            options->insertAt(KWD_QUERY_SORT_BY, KWD_QUERY_SCORE);
            queryAoptions = queryAoptions->rest;
          }
        }
      }
      else {
      }
    }
    if (!keywordP(queryAoptions->value)) {
      variables = queryAoptions->value;
      queryAoptions = queryAoptions->rest;
    }
    if (!keywordP(queryAoptions->value)) {
      proposition = queryAoptions->value;
      queryAoptions = queryAoptions->rest;
    }
    if (((boolean)(variables)) &&
        ((!((boolean)(proposition))) &&
         (!kifVariableDeclarationP(variables)))) {
      proposition = variables;
      variables = NULL;
    }
    if (consP(proposition)) {
      { List* freevariables = newList();
        Cons* declaredvariables = NULL;

        if (!((boolean)(variables))) {
          declaredvariables = NIL;
        }
        else if (!consP(variables)) {
          declaredvariables = cons(variables, NIL);
        }
        else {
          declaredvariables = ((Cons*)(variables));
        }
        declaredvariables = extractVariablesFromDeclarations(declaredvariables);
        collectUndeclaredVariables(proposition, NIL, freevariables);
        if ((declaredvariables == NIL) &&
            freevariables->nonEmptyP()) {
          if (freevariables->length() == 1) {
            variables = ((Symbol*)(freevariables->first()));
          }
          else {
            variables = freevariables->theConsList;
          }
        }
        else if ((declaredvariables == NIL) &&
            freevariables->emptyP()) {
        }
        else if (!freevariables->theConsList->equivalentSetsP(declaredvariables)) {
          { OutputStringStream* stream000 = newOutputStringStream();

            { 
              BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
              *(stream000->nativeStream) << "PARSING ERROR: " << "Declared query variables " << "`" << declaredvariables << "'" << " do not match" << std::endl << "   the free variables " << "`" << freevariables->theConsList << "'" << " referenced in the query body." << std::endl << "   To simply use the free variables, omit the declaration" << "." << std::endl;
              helpSignalPropositionError(stream000, KWD_QUERY_ERROR);
            }
            throw *newParsingError(stream000->theStringReader());
          }
        }
      }
    }
    while (!(queryAoptions == NIL)) {
      if (!keywordP(queryAoptions->value)) {
        { OutputStringStream* stream001 = newOutputStringStream();

          { 
            BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
            *(stream001->nativeStream) << "PARSING ERROR: " << "Illegal query option: " << "`" << queryAoptions->value << "'" << "." << std::endl;
            helpSignalPropositionError(stream001, KWD_QUERY_ERROR);
          }
          throw *newParsingError(stream001->theStringReader());
        }
      }
      if (!((boolean)(queryAoptions->rest->value))) {
        { OutputStringStream* stream002 = newOutputStringStream();

          { 
            BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
            *(stream002->nativeStream) << "PARSING ERROR: " << "Missing value for option " << "`" << queryAoptions->value << "'" << "." << std::endl;
            helpSignalPropositionError(stream002, KWD_QUERY_ERROR);
          }
          throw *newParsingError(stream002->theStringReader());
        }
      }
      options->insertAt(queryAoptions->value, queryAoptions->rest->value);
      queryAoptions = queryAoptions->rest->rest;
    }
    _Return1 = proposition;
    _Return2 = options;
    return (variables);
  }
}

void processQueryOptions(QueryIterator* query, Object* options) {
  { PropertyList* theoptions = vetOptions(options, NULL);
    PropertyList* deferredoptions = NULL;

    query->options = theoptions;
    { Object* key = NULL;
      Object* value = NULL;
      Cons* iter000 = theoptions->thePlist;

      for  (key, value, iter000; 
            !(iter000 == NIL); 
            iter000 = iter000->rest->rest) {
        key = iter000->value;
        value = iter000->rest->value;
        { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(key));

          if (testValue000 == KWD_QUERY_TIMEOUT) {
            { Surrogate* testValue001 = safePrimaryType(value);

              if (subtypeOfIntegerP(testValue001)) {
                { Object* value000 = value;
                  IntegerWrapper* value = ((IntegerWrapper*)(value000));

                  query->allottedTime = value->numberWrapperToFloat();
                  theoptions->insertAt(key, wrapFloat(query->allottedTime));
                }
              }
              else if (subtypeOfFloatP(testValue001)) {
                { Object* value001 = value;
                  FloatWrapper* value = ((FloatWrapper*)(value001));

                  query->allottedTime = value->wrapperValue;
                  theoptions->insertAt(key, wrapFloat(query->allottedTime));
                }
              }
              else {
                { OutputStringStream* stream000 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream000->nativeStream) << "PARSING ERROR: " << "Illegal :TIMEOUT value: " << "`" << value << "'" << "." << std::endl;
                    helpSignalPropositionError(stream000, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream000->theStringReader());
                }
              }
            }
            query->timeoutP = false;
          }
          else if (testValue000 == KWD_QUERY_MOVEOUT) {
            { Surrogate* testValue002 = safePrimaryType(value);

              if (subtypeOfIntegerP(testValue002)) {
                { Object* value002 = value;
                  IntegerWrapper* value = ((IntegerWrapper*)(value002));

                  query->allottedClockTicks = stella::floor(value->wrapperValue);
                  theoptions->insertAt(key, wrapInteger(stella::floor(value->wrapperValue)));
                }
              }
              else if (subtypeOfFloatP(testValue002)) {
                { Object* value003 = value;
                  FloatWrapper* value = ((FloatWrapper*)(value003));

                  query->allottedClockTicks = stella::floor(value->wrapperValue);
                  theoptions->insertAt(key, wrapInteger(stella::floor(value->wrapperValue)));
                }
              }
              else {
                { OutputStringStream* stream001 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream001->nativeStream) << "PARSING ERROR: " << "Illegal :MOVEOUT value: " << "`" << value << "'" << "." << std::endl;
                    helpSignalPropositionError(stream001, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream001->theStringReader());
                }
              }
            }
          }
          else if (testValue000 == KWD_QUERY_MAXIMUM_DEPTH) {
            { Surrogate* testValue003 = safePrimaryType(value);

              if (subtypeOfIntegerP(testValue003)) {
                { Object* value004 = value;
                  IntegerWrapper* value = ((IntegerWrapper*)(value004));

                  theoptions->insertAt(key, wrapInteger(stella::floor(value->wrapperValue)));
                  query->maximumDepth = ((IntegerWrapper*)(lookupQueryOption(query, KWD_QUERY_MAXIMUM_DEPTH)))->wrapperValue;
                }
              }
              else if (subtypeOfFloatP(testValue003)) {
                { Object* value005 = value;
                  FloatWrapper* value = ((FloatWrapper*)(value005));

                  theoptions->insertAt(key, wrapInteger(stella::floor(value->wrapperValue)));
                  query->maximumDepth = ((IntegerWrapper*)(lookupQueryOption(query, KWD_QUERY_MAXIMUM_DEPTH)))->wrapperValue;
                }
              }
              else {
                { OutputStringStream* stream002 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream002->nativeStream) << "PARSING ERROR: " << "Illegal :MAXIMUM-DEPTH value: " << "`" << value << "'" << "." << std::endl;
                    helpSignalPropositionError(stream002, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream002->theStringReader());
                }
              }
            }
          }
          else if (testValue000 == KWD_QUERY_INFERENCE_LEVEL) {
            { Surrogate* testValue004 = safePrimaryType(value);

              if (subtypeOfP(testValue004, SGT_QUERY_STELLA_GENERALIZED_SYMBOL)) {
                { Object* value006 = value;
                  GeneralizedSymbol* value = ((GeneralizedSymbol*)(value006));

                  theoptions->insertAt(key, stringKeywordify(coerceToString(value)));
                  query->inferenceLevel = getInferenceLevel(((Keyword*)(lookupQueryOption(query, KWD_QUERY_INFERENCE_LEVEL))));
                }
              }
              else if (subtypeOfStringP(testValue004)) {
                { Object* value007 = value;
                  StringWrapper* value = ((StringWrapper*)(value007));

                  theoptions->insertAt(key, stringKeywordify(coerceToString(value)));
                  query->inferenceLevel = getInferenceLevel(((Keyword*)(lookupQueryOption(query, KWD_QUERY_INFERENCE_LEVEL))));
                }
              }
              else {
                { OutputStringStream* stream003 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream003->nativeStream) << "PARSING ERROR: " << "Illegal :INFERENCE-LEVEL value: " << "`" << value << "'" << "." << std::endl;
                    helpSignalPropositionError(stream003, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream003->theStringReader());
                }
              }
            }
          }
          else if (testValue000 == KWD_QUERY_THREE_VALUEDp) {
            value = coerceToBoolean(value);
            theoptions->insertAt(key, value);
          }
          else if (testValue000 == KWD_QUERY_ITERATIVE_DEEPENINGp) {
            value = coerceToBoolean(value);
            theoptions->insertAt(key, value);
            if (eqlP(value, TRUE_WRAPPER)) {
              setDynamicSlotValue(query->dynamicSlots, SYM_QUERY_LOGIC_ITERATIVE_DEEPENINGp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
            }
          }
          else if (testValue000 == KWD_QUERY_SINGLETONSp) {
            theoptions->insertAt(key, coerceToBoolean(value));
            setDynamicSlotValue(query->dynamicSlots, SYM_QUERY_LOGIC_ATOMIC_SINGLETONSp, (eqlP(value, TRUE_WRAPPER) ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
          }
          else if (testValue000 == KWD_QUERY_DONT_OPTIMIZEp) {
            value = coerceToBoolean(value);
            theoptions->insertAt(key, value);
          }
          else if (testValue000 == KWD_QUERY_HOW_MANY) {
            { Surrogate* testValue005 = safePrimaryType(value);

              if (subtypeOfIntegerP(testValue005)) {
                { Object* value008 = value;
                  IntegerWrapper* value = ((IntegerWrapper*)(value008));

                }
              }
              else if (subtypeOfP(testValue005, SGT_QUERY_STELLA_GENERALIZED_SYMBOL)) {
                { Object* value009 = value;
                  GeneralizedSymbol* value = ((GeneralizedSymbol*)(value009));

                  if (stringEqlP(value->symbolName, "ALL")) {
                    theoptions->insertAt(key, wrapInteger(NULL_INTEGER));
                  }
                  else {
                    { OutputStringStream* stream004 = newOutputStringStream();

                      { 
                        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                        *(stream004->nativeStream) << "PARSING ERROR: " << "Illegal :HOW-MANY value: " << "`" << value << "'" << "." << std::endl;
                        helpSignalPropositionError(stream004, KWD_QUERY_ERROR);
                      }
                      throw *newParsingError(stream004->theStringReader());
                    }
                  }
                }
              }
              else {
                { OutputStringStream* stream005 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream005->nativeStream) << "PARSING ERROR: " << "Illegal :HOW-MANY value: " << "`" << value << "'" << "." << std::endl;
                    helpSignalPropositionError(stream005, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream005->theStringReader());
                }
              }
            }
          }
          else if (testValue000 == KWD_QUERY_SORT_BY) {
            if (subtypeOfP(safePrimaryType(value), SGT_QUERY_STELLA_GENERALIZED_SYMBOL)) {
              { Object* value010 = value;
                GeneralizedSymbol* value = ((GeneralizedSymbol*)(value010));

                if (stringEqlP(value->symbolName, "SCORE")) {
                  theoptions->insertAt(key, KWD_QUERY_SCORE);
                }
                else {
                  { OutputStringStream* stream006 = newOutputStringStream();

                    { 
                      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                      *(stream006->nativeStream) << "PARSING ERROR: " << "Illegal :SORT-BY value: " << "`" << value << "'" << "." << std::endl;
                      helpSignalPropositionError(stream006, KWD_QUERY_ERROR);
                    }
                    throw *newParsingError(stream006->theStringReader());
                  }
                }
              }
            }
            else {
              { OutputStringStream* stream007 = newOutputStringStream();

                { 
                  BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                  *(stream007->nativeStream) << "PARSING ERROR: " << "Illegal :SORT-BY value: " << "`" << value << "'" << "." << std::endl;
                  helpSignalPropositionError(stream007, KWD_QUERY_ERROR);
                }
                throw *newParsingError(stream007->theStringReader());
              }
            }
          }
          else if (testValue000 == KWD_QUERY_MATCH_MODE) {
            { Surrogate* testValue006 = safePrimaryType(value);

              if (subtypeOfP(testValue006, SGT_QUERY_STELLA_GENERALIZED_SYMBOL)) {
                { Object* value011 = value;
                  GeneralizedSymbol* value = ((GeneralizedSymbol*)(value011));

                  if (stringP(value)) {
                    theoptions->insertAt(key, value->keywordify());
                  }
                  else {
                    theoptions->insertAt(key, value);
                  }
                }
              }
              else if (subtypeOfStringP(testValue006)) {
                { Object* value012 = value;
                  StringWrapper* value = ((StringWrapper*)(value012));

                  if (stringP(value)) {
                    theoptions->insertAt(key, value->keywordify());
                  }
                  else {
                    theoptions->insertAt(key, value);
                  }
                }
              }
              else {
                { OutputStringStream* stream008 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream008->nativeStream) << "PARSING ERROR: " << "Illegal :MATCH-MODE value: " << "`" << value << "'" << "." << std::endl;
                    helpSignalPropositionError(stream008, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream008->theStringReader());
                }
              }
            }
          }
          else if (testValue000 == KWD_QUERY_MINIMUM_SCORE) {
            { Surrogate* testValue007 = safePrimaryType(value);

              if (subtypeOfIntegerP(testValue007)) {
                { Object* value013 = value;
                  IntegerWrapper* value = ((IntegerWrapper*)(value013));

                  theoptions->insertAt(key, wrapFloat(((double)(value->wrapperValue))));
                }
              }
              else if (subtypeOfFloatP(testValue007)) {
                { Object* value014 = value;
                  FloatWrapper* value = ((FloatWrapper*)(value014));

                }
              }
              else {
                { OutputStringStream* stream009 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream009->nativeStream) << "PARSING ERROR: " << "Illegal :MINIMUM-SCORE value: " << "`" << value << "'" << "." << std::endl;
                    helpSignalPropositionError(stream009, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream009->theStringReader());
                }
              }
            }
          }
          else if (testValue000 == KWD_QUERY_MAXIMIZE_SCOREp) {
            theoptions->insertAt(key, coerceToBoolean(value));
          }
          else if (testValue000 == KWD_QUERY_MAXIMUM_UNKNOWNS) {
            { Surrogate* testValue008 = safePrimaryType(value);

              if (subtypeOfIntegerP(testValue008)) {
                { Object* value015 = value;
                  IntegerWrapper* value = ((IntegerWrapper*)(value015));

                }
              }
              else if (subtypeOfFloatP(testValue008)) {
                { Object* value016 = value;
                  FloatWrapper* value = ((FloatWrapper*)(value016));

                  theoptions->insertAt(key, wrapInteger(((int)(value->wrapperValue))));
                }
              }
              else {
                { OutputStringStream* stream010 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream010->nativeStream) << "PARSING ERROR: " << "Illegal :MAXIMUM-UNKNOWNS value: " << "`" << value << "'" << "." << std::endl;
                    helpSignalPropositionError(stream010, KWD_QUERY_ERROR);
                  }
                  throw *newParsingError(stream010->theStringReader());
                }
              }
            }
          }
          else {
            if (!((boolean)(deferredoptions))) {
              deferredoptions = newPropertyList();
            }
            deferredoptions->insertAt(key, value);
          }
        }
      }
    }
    if (((boolean)(deferredoptions))) {
      theoptions->insertAt(KWD_QUERY_DEFERRED_OPTIONS, deferredoptions);
    }
  }
}

Object* lookupQueryOption(Object* queryoroptions, Keyword* key) {
  { PropertyList* options = NULL;

    { Surrogate* testValue000 = safePrimaryType(queryoroptions);

      if (subtypeOfP(testValue000, SGT_QUERY_STELLA_PROPERTY_LIST)) {
        { Object* queryoroptions000 = queryoroptions;
          PropertyList* queryoroptions = ((PropertyList*)(queryoroptions000));

          options = queryoroptions;
        }
      }
      else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_QUERY_ITERATOR)) {
        { Object* queryoroptions001 = queryoroptions;
          QueryIterator* queryoroptions = ((QueryIterator*)(queryoroptions001));

          options = queryoroptions->options;
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    return (options->lookup(key));
  }
}

boolean testQueryOptionP(Object* queryoroptions, Keyword* key) {
  return (eqlP(lookupQueryOption(queryoroptions, key), TRUE_WRAPPER));
}

Object* lookupDeferredQueryOption(Object* queryoroptions, Keyword* key, Surrogate* coercetotype) {
  { PropertyList* options = NULL;
    PropertyList* deferredoptions = NULL;
    Object* value = NULL;
    Object* coercedvalue = NULL;
    boolean processeddeferredoptionP = false;

    { Surrogate* testValue000 = safePrimaryType(queryoroptions);

      if (subtypeOfP(testValue000, SGT_QUERY_STELLA_PROPERTY_LIST)) {
        { Object* queryoroptions000 = queryoroptions;
          PropertyList* queryoroptions = ((PropertyList*)(queryoroptions000));

          options = queryoroptions;
        }
      }
      else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_QUERY_ITERATOR)) {
        { Object* queryoroptions001 = queryoroptions;
          QueryIterator* queryoroptions = ((QueryIterator*)(queryoroptions001));

          options = queryoroptions->options;
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    deferredoptions = ((PropertyList*)(options->lookup(KWD_QUERY_DEFERRED_OPTIONS)));
    if (((boolean)(deferredoptions))) {
      value = deferredoptions->lookup(key);
      if (!((boolean)(value))) {
        value = options->lookup(key);
      }
      else {
        processeddeferredoptionP = true;
      }
      if (((boolean)(value))) {
        if (((boolean)(coercetotype))) {
          coercedvalue = coerceOptionValue(value, coercetotype);
          if (!((boolean)(coercedvalue))) {
            { OutputStringStream* stream001 = newOutputStringStream();

              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                *(stream001->nativeStream) << "PARSING ERROR: " << "Illegal " << "`" << key << "'" << " value: " << "`" << value << "'" << "." << std::endl;
                helpSignalPropositionError(stream001, KWD_QUERY_ERROR);
              }
              throw *newParsingError(stream001->theStringReader());
            }
          }
          else {
            value = coercedvalue;
          }
        }
        if (processeddeferredoptionP) {
          deferredoptions->removeAt(key);
          options->insertAt(key, value);
        }
      }
    }
    return (value);
  }
}

int lookupHowManySolutions(Object* queryoroptions) {
  { Object* howmany = lookupQueryOption(queryoroptions, KWD_QUERY_HOW_MANY);

    if (((boolean)(howmany))) {
      return (((IntegerWrapper*)(howmany))->wrapperValue);
    }
    else {
      return (1);
    }
  }
}

BooleanWrapper* runYesOrNoQueryP(QueryIterator* query) {
  { TruthValue* truthvalue = callAsk(query);

    if ((truthvalue == TRUE_TRUTH_VALUE) ||
        (truthvalue == DEFAULT_TRUE_TRUTH_VALUE)) {
      return ((true ? TRUE_WRAPPER : FALSE_WRAPPER));
    }
    else if ((truthvalue == FALSE_TRUTH_VALUE) ||
        (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
      return ((false ? TRUE_WRAPPER : FALSE_WRAPPER));
    }
    else {
      return (NULL);
    }
  }
}

Object* coerceToTree(Object* self) {
  if (subtypeOfStringP(safePrimaryType(self))) {
    { Object* self000 = self;
      StringWrapper* self = ((StringWrapper*)(self000));

      return (readSExpressionFromString(self->wrapperValue));
    }
  }
  else {
    return (self);
  }
}

char* coerceToString(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfStringP(testValue000)) {
      { Object* self000 = self;
        StringWrapper* self = ((StringWrapper*)(self000));

        return (self->wrapperValue);
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* self001 = self;
        Symbol* self = ((Symbol*)(self001));

        return (self->symbolName);
      }
    }
    else if (subtypeOfKeywordP(testValue000)) {
      { Object* self002 = self;
        Keyword* self = ((Keyword*)(self002));

        return (self->symbolName);
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* self003 = self;
        Surrogate* self = ((Surrogate*)(self003));

        return (self->symbolName);
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
          *(stream000->nativeStream) << "PARSING ERROR: " << "Can't convert " << "`" << self << "'" << " into a string" << "." << std::endl;
          helpSignalPropositionError(stream000, KWD_QUERY_ERROR);
        }
        throw *newParsingError(stream000->theStringReader());
      }
    }
  }
}

QueryIterator* createAskQuery(Object* query) {
  { Surrogate* testValue000 = safePrimaryType(query);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_QUERY_ITERATOR)) {
      { Object* query000 = query;
        QueryIterator* query = ((QueryIterator*)(query000));

        return (query);
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_PROPOSITION)) {
      { Object* query001 = query;
        Proposition* query = ((Proposition*)(query001));

        return (createAskQuery(propositionToCons(query)));
      }
    }
    else if (testValue000 == SGT_QUERY_STELLA_CONS) {
      { Object* query002 = query;
        Cons* query = ((Cons*)(query002));

        { Object* iovariables = NULL;
          Object* proposition = NULL;
          PropertyList* options = NULL;

          iovariables = parseQueryAndOptions(query, proposition, options);
          if ((!((boolean)(iovariables))) &&
              ((boolean)(proposition))) {
            return (makeQuery(NIL, proposition, NIL, options));
          }
          else {
            { OutputStringStream* stream000 = newOutputStringStream();

              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                *(stream000->nativeStream) << "PARSING ERROR: " << "Illegal ASK query: " << "`" << query << "'" << "." << std::endl;
                helpSignalPropositionError(stream000, KWD_QUERY_ERROR);
              }
              throw *newParsingError(stream000->theStringReader());
            }
          }
        }
      }
    }
    else {
      { OutputStringStream* stream001 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
          *(stream001->nativeStream) << "PARSING ERROR: " << "Illegal ASK query: " << "`" << query << "'" << "." << std::endl;
          helpSignalPropositionError(stream001, KWD_QUERY_ERROR);
        }
        throw *newParsingError(stream001->theStringReader());
      }
    }
  }
}

TruthValue* callAsk(Object* query) {
  // Callable version of `ask' (which see).  Accepts queries
  // specified by a query iterator, or specified as a CONS-list of arguments as they
  // would be supplied to `ask'.  Raises LOGIC-EXCEPTIONs in case of illegal
  // queries and logical expressions.
  { 
    BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, createAskQuery(query));
    BIND_STELLA_SPECIAL(oREVERSEPOLARITYpo, boolean, false);
    BIND_STELLA_SPECIAL(oINFERENCELEVELo, NormalInferenceLevel*, currentInferenceLevel());
    BIND_STELLA_SPECIAL(oGENERATE_ALL_PROOFSpo, boolean, false);
    { TruthValue* truthvalue = NULL;
      boolean threevaluedaskP = testQueryOptionP(oQUERYITERATORo.get(), KWD_QUERY_THREE_VALUEDp);

      if (!((boolean)(oMOST_RECENT_QUERYo))) {
        oMOST_RECENT_QUERYo = oQUERYITERATORo.get();
      }
      oQUERYITERATORo.get()->nextP();
      { TruthValue* temp000 = oQUERYITERATORo.get()->baseControlFrame->truthValue;

        truthvalue = (((boolean)(temp000)) ? temp000 : UNKNOWN_TRUTH_VALUE);
      }
      if (threevaluedaskP &&
          ((truthvalue == UNKNOWN_TRUTH_VALUE) ||
           (!((boolean)(truthvalue))))) {
        oQUERYITERATORo.get()->baseControlFrame->reversePolarityP = true;
        oQUERYITERATORo.get()->reset();
        oQUERYITERATORo.get()->nextP();
        { TruthValue* temp001 = oQUERYITERATORo.get()->baseControlFrame->truthValue;

          truthvalue = (((boolean)(temp001)) ? temp001 : UNKNOWN_TRUTH_VALUE);
        }
      }
      return (truthvalue);
    }
  }
}

TruthValue* ask(Cons* propositionAoptions) {
  // Perform inference to determine whether the proposition specified in
  // `proposition&options' is true.  Return the truth-value found.  `ask'
  // will spend most of its effort to determine whether the proposition
  // is true and only a little effort via shallow inference strategies to
  // determine whether it is false.  To find out whether a proposition is
  // false with full inference effort `ask' its negation.
  // 
  // KIF example: `(ask (happy Fred))' will return TRUE if Fred was indeed
  // found to be happy.  Note, that for this query to run, the logic
  // constant `Fred' and the relation `happy' must already be defined (see
  // `assert').  Use `(set/unset-feature goal-trace)' to en/disable goal
  // tracing of the inference engine.
  // 
  // The `ask' command supports the following options: `:TIMEOUT' is an
  // integer or floating point time limit, specified in seconds.  For
  // example, the command `(ask (nervous Fred) :timeout 2.0)' will cease
  // inference after two seconds if a proof has not been found by then.
  // If the `:DONT-OPTIMIZE?' is given as TRUE, it tells PowerLoom to
  // not optimize the order of clauses in the query before evaluating it.
  // This is useful for cases where a specific evaluation order of the
  // clauses is required (or the optimizer doesn't do the right thing).
  // If `:THREE-VALUED?' is given as TRUE, PowerLoom will try to prove
  // the negation of the query with full effort in case the given query
  // returned UNKNOWN.  By default, PowerLoom uses full effort to prove
  // the query as stated and only a little opportunistic effort to see
  // whether it is actually false.
  oMOST_RECENT_QUERYo = NULL;
  try {
    return (callAsk(propositionAoptions));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    oMOST_RECENT_QUERYo = NULL;
    return (NULL);
  }
}

TruthValue* askEvaluatorWrapper(Cons* arguments) {
  return (ask(arguments));
}

QueryIterator* retrieveBindings(Object* query, int nofbindings) {
  { QueryIterator* thequery = NULL;

    { Surrogate* testValue000 = safePrimaryType(query);

      if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_QUERY_ITERATOR)) {
        { Object* query000 = query;
          QueryIterator* query = ((QueryIterator*)(query000));

          thequery = query;
        }
      }
      else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_PROPOSITION)) {
        { Object* query001 = query;
          Proposition* query = ((Proposition*)(query001));

          thequery = makeQuery(((Vector*)(dynamicSlotValue(query->dynamicSlots, SYM_QUERY_LOGIC_IO_VARIABLES, NULL)))->consify(), propositionToCons(query), NIL, listO(3, KWD_QUERY_HOW_MANY, wrapInteger(nofbindings), NIL));
        }
      }
      else if (testValue000 == SGT_QUERY_STELLA_CONS) {
        { Object* query002 = query;
          Cons* query = ((Cons*)(query002));

          thequery = makeQuery(query->value, query->rest->value, NIL, query->rest->rest);
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    thequery->options->insertAt(KWD_QUERY_HOW_MANY, wrapInteger(nofbindings));
    return (callRetrieve(thequery));
  }
}

QueryIterator* createRetrieveQuery(Object* query) {
  { Surrogate* testValue000 = safePrimaryType(query);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_QUERY_ITERATOR)) {
      { Object* query000 = query;
        QueryIterator* query = ((QueryIterator*)(query000));

        return (query);
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_PROPOSITION)) {
      { Object* query001 = query;
        Proposition* query = ((Proposition*)(query001));

        return (createRetrieveQuery(propositionToCons(query)));
      }
    }
    else if (testValue000 == SGT_QUERY_STELLA_CONS) {
      { Object* query002 = query;
        Cons* query = ((Cons*)(query002));

        { Object* iovariables = NULL;
          Object* queryproposition = NULL;
          PropertyList* options = NULL;

          iovariables = parseQueryAndOptions(query, queryproposition, options);
          if ((!((boolean)(iovariables))) &&
              (!((boolean)(queryproposition)))) {
            if (!((boolean)(oMOST_RECENT_QUERYo))) {
              { OutputStringStream* stream000 = newOutputStringStream();

                { 
                  BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                  *(stream000->nativeStream) << "PARSING ERROR: " << "No preceding context for follow-up retrieval" << "." << std::endl;
                  helpSignalPropositionError(stream000, KWD_QUERY_ERROR);
                }
                throw *newParsingError(stream000->theStringReader());
              }
            }
            processQueryOptions(oMOST_RECENT_QUERYo, options);
            return (oMOST_RECENT_QUERYo);
          }
          else if (!((boolean)(iovariables))) {
            { OutputStringStream* stream001 = newOutputStringStream();

              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                *(stream001->nativeStream) << "PARSING ERROR: " << "Missing IO-variable specification in retrieval query: " << "`" << query << "'" << "." << std::endl;
                helpSignalPropositionError(stream001, KWD_QUERY_ERROR);
              }
              throw *newParsingError(stream001->theStringReader());
            }
          }
          else {
            return (makeQuery(iovariables, queryproposition, NIL, options));
          }
        }
      }
    }
    else {
      { OutputStringStream* stream002 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
          *(stream002->nativeStream) << "PARSING ERROR: " << "Illegal retrieval query: " << "`" << query << "'" << "." << std::endl;
          helpSignalPropositionError(stream002, KWD_QUERY_ERROR);
        }
        throw *newParsingError(stream002->theStringReader());
      }
    }
  }
}

QueryIterator* callRetrieve(Object* query) {
  // Callable version of `retrieve' (which see).  Accepts queries
  // specified by a query iterator, or specified as a CONS-list of arguments as they
  // would be supplied to `retrieve'.  Raises LOGIC-EXCEPTIONs in case of illegal
  // queries and logical expressions.
  { QueryIterator* thequery = createRetrieveQuery(query);
    Object* matchmode = lookupQueryOption(thequery, KWD_QUERY_MATCH_MODE);

    if (((boolean)(matchmode)) &&
        (!stringEqualP(coerceToString(matchmode), "STRICT"))) {
      return (callRetrievePartial(thequery));
    }
    { 
      BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, thequery);
      BIND_STELLA_SPECIAL(oREVERSEPOLARITYpo, boolean, false);
      BIND_STELLA_SPECIAL(oINFERENCELEVELo, NormalInferenceLevel*, currentInferenceLevel());
      BIND_STELLA_SPECIAL(oGENERATE_ALL_PROOFSpo, boolean, false);
      { int i = NULL_INTEGER;
        int iter000 = 1;
        int upperBound000 = lookupHowManySolutions(oQUERYITERATORo.get());
        boolean unboundedP000 = upperBound000 == NULL_INTEGER;
        QuerySolution* solution = NULL;
        QueryIterator* iter001 = oQUERYITERATORo.get();

        for  (i, iter000, upperBound000, unboundedP000, solution, iter001; 
              (unboundedP000 ||
                  (iter000 <= upperBound000)) &&
                  iter001->nextP(); 
              iter000 = iter000 + 1) {
          i = iter000;
          solution = ((QuerySolution*)(iter001->value));
          if (traceKeywordP(KWD_QUERY_TRACE_SOLUTIONS)) {
            traceSolution(oQUERYITERATORo.get(), solution, i);
          }
        }
      }
      return (oQUERYITERATORo.get());
    }
  }
}

QueryIterator* oMOST_RECENT_QUERYo = NULL;

QueryIterator* retrieve(Cons* query) {
  // Retrieve elements of a relation (tuples) that satisfy a proposition.
  // The accepted syntax is:
  // 	 
  //   (retrieve [<integer> | all]
  //             [[{<vardecl> | (<vardecl>+)}]
  //             <proposition>])
  // 	
  // The variables and proposition are similar to an `exists' sentence or
  // `kappa' term without the explicit quantifier.  If variables are declared,
  // they must match the free variables referenced by <proposition>.  Otherwise,
  // the free variables referenced in <proposition> will be used as the query
  // variables.  If <proposition> is omitted, the most recently asked query
  // will be continued.
  // 
  // A solution is a set of bindings for the listed variables for which
  // <proposition> is true.  The optional first argument controls how many
  // solutions should be generated before control is returned.  The keyword
  // `all' indicates that all solutions should be generated.  By default,
  // `retrieve' returns after it has found one new solution or if it cannot
  // find any more solutions.
  // 
  // `retrieve' returns an iterator which saves all the necessary state of
  // a query and stores all generated solutions.  When used interactively,
  // the returned iterator will print out with the set of solutions collected
  // so far.  Calling `retrieve' without any arguments (or only with the first
  // argument) will generate one (or more) solutions to the most recently
  // asked query.
  // 
  // KIF examples:
  // 	 
  //   (retrieve (happy ?x))
  // 	
  // will try to find one happy entity and store it in the returned 
  // query iterator.
  // 	 
  //   (retrieve 10 (happy ?x))
  // 	
  // will try to find 10 happy entities.
  // 	 
  //   (retrieve 10)
  // 	
  // will try to find the next 10 happy entities..
  // 	 
  //   (retrieve all (happy ?x))
  // 	
  // will find all happy entities.
  // 	 
  //   (retrieve all (?x Person) (happy ?x))
  // 	
  // will to find all happy people.  Here we used the optional retrieve variable
  // syntax to restrict the acceptable solutions.  The above is equivalent to
  // the following query:
  // 	 
  //   (retrieve all (and (Person ?x) (happy ?x)))
  // 	
  // Similarly,
  // 	 
  //   (retrieve all (?x Person))
  //   (retrieve all (Person ?x))
  //   (retrieve all ?x (Person ?x))
  // 	
  // will find all people.  Note that in the first case we only specify a query
  // variable and its type but omit the logic sentence which defaults to TRUE.  This
  // somewhat impoverished looking query can be paraphrased as "retrieve all ?x of
  // type Person such that TRUE."
  // 	 
  //   (retrieve ?x (or (happy ?x) (parent-of Fred ?x)))
  // 	
  // will try to find a person that is happy or has Fred as a parent.
  // 	 
  //   (retrieve (?y ?x) (parent-of ?x ?y))
  // 	
  // will try to find the one pair of parent/child and return it in the order
  // of child/parent.
  // 	 
  //   (retrieve all (?x Person)
  //             (exists (?y Person) (parent-of ?x ?y)))
  // 	
  // will generate the set of all parents.  Note, that for these queries to run,
  // the class `Person', the relations `happy' and `parent-of', and the logic
  // constant `Fred' must already be defined (see `assert').
  // 
  // Use `(set/unset-feature trace-subgoals)' to en/disable goal tracing of the
  // inference engine.
  try {
    return (oMOST_RECENT_QUERYo = callRetrieve(query));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    return (oMOST_RECENT_QUERYo = NULL);
  }
}

QueryIterator* retrieveEvaluatorWrapper(Cons* arguments) {
  return (retrieve(arguments));
}

Cons* QueryIterator::consifyCurrentSolutions() {
  // Collect the current solutions of `self' into a cons list
  // of result tuples.  If `:SINGLETONS? TRUE', collect a list of atoms rather than a
  // list of lists for tuples of arity=1.
  { QueryIterator* self = this;

    if (!((boolean)(self))) {
      return (NIL);
    }
    { QuerySolutionTable* solutions = self->solutions;
      Cons* listifiedsolutions = NIL;
      int arity = self->queryDescription()->arity();
      boolean atomicsingletonsP = ((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_QUERY_LOGIC_ATOMIC_SINGLETONSp, FALSE_WRAPPER)))->wrapperValue;

      { QuerySolution* solution = NULL;
        DictionaryIterator* iter000 = ((DictionaryIterator*)(solutions->allocateIterator()));
        Cons* collect000 = NULL;

        for  (solution, iter000, collect000; 
              iter000->nextP(); ) {
          solution = ((QuerySolution*)(iter000->value));
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(((atomicsingletonsP &&
                  (arity == 1)) ? (solution->bindings->theArray)[0] : solution->bindings->consify()), NIL);
              if (listifiedsolutions == NIL) {
                listifiedsolutions = collect000;
              }
              else {
                addConsToEndOfConsList(listifiedsolutions, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(((atomicsingletonsP &&
                  (arity == 1)) ? (solution->bindings->theArray)[0] : solution->bindings->consify()), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      return (listifiedsolutions);
    }
  }
}

Cons* QueryIterator::consify() {
  // Generate all solutions for the query self, and collect them into a cons list
  // of result tuples.  If `:SINGLETONS? TRUE', collect a list of atoms rather than a
  // list of lists for tuples of arity=1.
  { QueryIterator* self = this;

    if (!((boolean)(self))) {
      return (NIL);
    }
    { 
      BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, self);
      BIND_STELLA_SPECIAL(oREVERSEPOLARITYpo, boolean, false);
      while (self->nextP()) {
      }
    }
    return (self->consifyCurrentSolutions());
  }
}

Cons* consifyQuery(QueryIterator* self) {
  return (self->consify());
}

List* QueryIterator::listify() {
  // Just like `QUERY-ITERATOR.consify' but return a LIST instead.
  { QueryIterator* self = this;

    { List* self000 = newList();

      self000->theConsList = self->consify();
      { List* value000 = self000;

        return (value000);
      }
    }
  }
}

// Caches in-line queries, so that they
// don't have to be reparsed and reoptimized each time they
// are invoked.
HashTable* oQUERY_CACHEo = NULL;

void flushInlineQueryCaches() {
  oQUERY_CACHEo = newHashTable();
}

QueryIterator* makeCachedQuery(Cons* variables, Cons* querybody, Cons* inputbindings, Object* options, Symbol* cacheid) {
  { QueryIterator* queryiterator = ((QueryIterator*)(oQUERY_CACHEo->lookup(cacheid)));
    Cons* cursor = inputbindings;

    if (!(variables->length() == inputbindings->length())) {
      std::cout << "make-cached-query: number of variables does not equal number of input bindings." << std::endl;
      return (NULL);
    }
    while (!(cursor == NIL)) {
      if (((boolean)(cursor->value))) {
        cursor->value = valueOf(cursor->value);
      }
      cursor = cursor->rest;
    }
    if (((boolean)(queryiterator)) &&
        ((!(oQUERY_OPTIMIZATION_STRATEGYo == KWD_QUERY_NONE)) &&
         (!((oQUERY_OPTIMIZATION_STRATEGYo == KWD_QUERY_DYNAMIC) ||
        (oQUERY_OPTIMIZATION_STRATEGYo == KWD_QUERY_DYNAMIC_WITH_CLUSTERING))))) {
      { Object* oldb = NULL;
        Vector* vector000 = ((Vector*)(dynamicSlotValue(queryiterator->dynamicSlots, SYM_QUERY_LOGIC_INITIAL_BINDINGS, NULL)));
        int index000 = 0;
        int length000 = vector000->length();
        Object* newb = NULL;
        Cons* iter000 = inputbindings;

        for  (oldb, vector000, index000, length000, newb, iter000; 
              (index000 < length000) &&
                  (!(iter000 == NIL)); 
              index000 = index000 + 1,
              iter000 = iter000->rest) {
          oldb = (vector000->theArray)[index000];
          newb = iter000->value;
          if (!((!((boolean)(oldb))) == (!((boolean)(newb))))) {
            queryiterator = NULL;
            break;
          }
        }
      }
    }
    if (!((boolean)(queryiterator))) {
      {
        try {
          queryiterator = makeQuery(copyConsList(variables), ((Cons*)(copyConsTree(querybody))), inputbindings, options);
        }
        catch (LogicException& _e) {
          LogicException* e = &_e;

          *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
          return (NULL);
        }
        if (((boolean)(cacheid))) {
          oQUERY_CACHEo->insertAt(cacheid, queryiterator);
        }
      }
    }
    else {
      {
        { Object* newb = NULL;
          Cons* iter001 = inputbindings;
          int i = NULL_INTEGER;
          int iter002 = 0;

          for  (newb, iter001, i, iter002; 
                !(iter001 == NIL); 
                iter001 = iter001->rest,
                iter002 = iter002 + 1) {
            newb = iter001->value;
            i = iter002;
            (((Vector*)(dynamicSlotValue(queryiterator->dynamicSlots, SYM_QUERY_LOGIC_INITIAL_BINDINGS, NULL)))->theArray)[i] = newb;
          }
        }
        queryiterator->reset();
      }
    }
    if (((boolean)(options))) {
      processQueryOptions(queryiterator, options);
    }
    return (queryiterator);
  }
}

Cons* applyCachedRetrieve(Cons* variables, Cons* querybody, Cons* inputbindings, Object* options, Symbol* cacheid, Cons*& _Return1) {
  { QueryIterator* queryiterator = NULL;
    int bindingscount = 0;
    Cons* outputbindings = NIL;
    Cons* truthvalues = NIL;
    boolean forcesingletonsP = false;

    { ConsIterator* it = inputbindings->allocateIterator();

      for (it; it->nextP(); ) {
        if (((boolean)(it->value))) {
          bindingscount = bindingscount + 1;
        }
      }
    }
    queryiterator = makeCachedQuery(variables, querybody, inputbindings, options, cacheid);
    if (!((boolean)(queryiterator))) {
      _Return1 = NIL;
      return (NIL);
    }
    if (eqlP(queryiterator->options->lookup(KWD_QUERY_SINGLETONSp), TRUE_WRAPPER)) {
      forcesingletonsP = true;
    }
    { 
      BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, queryiterator);
      BIND_STELLA_SPECIAL(oREVERSEPOLARITYpo, boolean, false);
      while (queryiterator->nextP()) {
      }
    }
    { Object* tuple = NULL;
      boolean atomicsingletonsP = (inputbindings->length() == (bindingscount + 1)) &&
          (!forcesingletonsP);

      { QuerySolution* s = NULL;
        DictionaryIterator* iter000 = ((DictionaryIterator*)(queryiterator->solutions->allocateIterator()));

        for (s, iter000; iter000->nextP(); ) {
          s = ((QuerySolution*)(iter000->value));
          if (atomicsingletonsP) {
            { Object* v = NULL;
              Vector* vector000 = s->bindings;
              int index000 = 0;
              int length000 = vector000->length();
              Object* b = NULL;
              Cons* iter001 = inputbindings;

              for  (v, vector000, index000, length000, b, iter001; 
                    (index000 < length000) &&
                        (!(iter001 == NIL)); 
                    index000 = index000 + 1,
                    iter001 = iter001->rest) {
                v = (vector000->theArray)[index000];
                b = iter001->value;
                if (!((boolean)(b))) {
                  tuple = v;
                }
              }
            }
          }
          else {
            { Cons* values = NIL;

              { Object* v = NULL;
                Vector* vector001 = s->bindings;
                int index001 = 0;
                int length001 = vector001->length();
                Object* b = NULL;
                Cons* iter002 = inputbindings;
                Cons* collect000 = NULL;

                for  (v, vector001, index001, length001, b, iter002, collect000; 
                      (index001 < length001) &&
                          (!(iter002 == NIL)); 
                      index001 = index001 + 1,
                      iter002 = iter002->rest) {
                  v = (vector001->theArray)[index001];
                  b = iter002->value;
                  if (!((boolean)(b))) {
                    if (!((boolean)(collect000))) {
                      {
                        collect000 = cons(v, NIL);
                        if (values == NIL) {
                          values = collect000;
                        }
                        else {
                          addConsToEndOfConsList(values, collect000);
                        }
                      }
                    }
                    else {
                      {
                        collect000->rest = cons(v, NIL);
                        collect000 = collect000->rest;
                      }
                    }
                  }
                }
              }
              tuple = values;
            }
          }
          outputbindings = cons(tuple, outputbindings);
          truthvalues = cons(s->truthValue, truthvalues);
        }
      }
    }
    { Cons* _Return0 = outputbindings->reverse();

      _Return1 = truthvalues->reverse();
      return (_Return0);
    }
  }
}

boolean applyCachedAsk(Cons* inputvariables, Cons* querybody, Cons* inputbindings, Object* options, Symbol* cacheid, TruthValue*& _Return1) {
  { QueryIterator* queryiterator = makeCachedQuery(inputvariables, querybody, inputbindings, options, cacheid);

    if (!((boolean)(queryiterator))) {
      _Return1 = NULL;
      return (false);
    }
    { boolean _Return0 = trueTruthValueP(callAsk(queryiterator));

      _Return1 = ((QuerySolution*)(queryiterator->value))->truthValue;
      return (_Return0);
    }
  }
}

LogicObject* getPrototype(Description* description) {
  { Cons* dummy1;

    if (!((boolean)(description))) {
      return (NULL);
    }
    { Object* prototype = accessBinaryValue(description, SGT_QUERY_PL_KERNEL_KB_CONCEPT_PROTOTYPE);

      if (!((boolean)(prototype))) {
        prototype = applyCachedRetrieve(listO(3, SYM_QUERY_LOGIC_pC, SYM_QUERY_LOGIC_pP, NIL), listO(4, SYM_QUERY_PL_KERNEL_KB_CONCEPT_PROTOTYPE, SYM_QUERY_LOGIC_pC, SYM_QUERY_LOGIC_pP, NIL), consList(2, description, NULL), consList(0), SYM_QUERY_LOGIC_F_GET_PROTOTYPE_QUERY_000, dummy1)->value;
      }
      { 
        BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_QUERY_EXTENSIONAL_ASSERTION);
        BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, NULL);
        elaborateMetaInstance(prototype);
        return (((LogicObject*)(prototype)));
      }
    }
  }
}

TruthValue* unaryDescriptionSpecializesDescriptionP(Description* sub, Description* super) {
  if (oREVERSEPOLARITYpo.get()) {
    return (UNKNOWN_TRUTH_VALUE);
  }
  if (collectionImpliesCollectionP(sub, super)) {
    return (TRUE_TRUTH_VALUE);
  }
  { 
    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE)) {
      std::cout << std::endl << "Prototype Subsumption Test:" << std::endl << "   sub=" << sub << std::endl << "   super=" << super << std::endl;
    }
  }
  { TruthValue* result = UNKNOWN_TRUTH_VALUE;

    try {
      { 
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, getInferenceCache(oMODULEo.get(), KWD_QUERY_META));
        result = callAsk(createQueryIterator(super, stella::vector(1, getPrototype(sub))));
      }
    }
    catch (LogicException& _e) {
      LogicException* e = &_e;

      *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    }
    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE)) {
      std::cout << std::endl;
    }
    return (result);
  }
}

TruthValue* descriptionSpecializesDescriptionP(Description* sub, Description* super) {
  if (!(sub->arity() == super->arity())) {
    if (oREVERSEPOLARITYpo.get()) {
      return (TRUE_TRUTH_VALUE);
    }
    else {
      return (FALSE_TRUTH_VALUE);
    }
  }
  if (oREVERSEPOLARITYpo.get()) {
    return (UNKNOWN_TRUTH_VALUE);
  }
  if (collectionImpliesCollectionP(sub, super)) {
    return (TRUE_TRUTH_VALUE);
  }
  if (super->arity() == 1) {
    return (unaryDescriptionSpecializesDescriptionP(sub, super));
  }
  { 
    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE)) {
      std::cout << std::endl << "Subsumption Test:" << std::endl << "   sub=" << sub << std::endl << "   super=" << super << std::endl;
    }
  }
  { Vector* skolemsvector = newVector(sub->ioVariables->length());
    TruthValue* result = UNKNOWN_TRUTH_VALUE;

    pushMonotonicWorld();
    initializeInferenceWorld(((World*)(oCONTEXTo.get())));
    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = skolemsvector->length() - 1;

      for  (i, iter000, upperBound000; 
            iter000 <= upperBound000; 
            iter000 = iter000 + 1) {
        i = iter000;
        (skolemsvector->theArray)[i] = (createHypothesizedInstance("anonymous"));
      }
    }
    try {
      inheritDescription(skolemsvector, sub, false);
      result = callAsk(createQueryIterator(super, skolemsvector));
    }
    catch (LogicException& _e) {
      LogicException* e = &_e;

      *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    }
    popWorld();
    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_QUERY_GOAL_TREE)) {
      std::cout << std::endl;
    }
    return (result);
  }
}

TruthValue* vectorSatisfiesDescriptionP(Vector* vector, Description* description) {
  if (!(vector->length() == description->arity())) {
    if (oREVERSEPOLARITYpo.get()) {
      return (TRUE_TRUTH_VALUE);
    }
    else {
      return (FALSE_TRUTH_VALUE);
    }
  }
  if (oREVERSEPOLARITYpo.get()) {
    return (UNKNOWN_TRUTH_VALUE);
  }
  try {
    { boolean alwaysP000 = true;

      { Object* value = NULL;
        Vector* vector000 = vector;
        int index000 = 0;
        int length000 = vector000->length();

        for  (value, vector000, index000, length000; 
              index000 < length000; 
              index000 = index000 + 1) {
          value = (vector000->theArray)[index000];
          if (!((boolean)(value))) {
            alwaysP000 = false;
            break;
          }
        }
      }
      if (alwaysP000) {
        return (callAsk(createQueryIterator(description, vector)));
      }
    }
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
  }
  return (UNKNOWN_TRUTH_VALUE);
}

TruthValue* instanceSatisfiesDescriptionP(Object* instance, Description* description) {
  return (vectorSatisfiesDescriptionP(stella::vector(1, instance), description));
}

Description* coerceToDescription(Object* self, Object* original) {
  if (!((boolean)(original))) {
    original = self;
  }
  if (!((boolean)(self))) {
    std::cout << "Can't find a description for the object " << "`" << original << "'" << "." << std::endl;
    return (NULL);
  }
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_DESCRIPTION)) {
      { Object* self000 = self;
        Description* self = ((Description*)(self000));

        return (self);
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_STELLA_RELATION)) {
      { Object* self001 = self;
        Relation* self = ((Relation*)(self001));

        return (getDescription(self));
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* self002 = self;
        Surrogate* self = ((Surrogate*)(self002));

        return (coerceToDescription(self->surrogateValue, original));
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* self003 = self;
        Symbol* self = ((Symbol*)(self003));

        return (coerceToDescription(lookupSurrogateInModule(self->symbolName, ((Module*)(self->homeContext)), false), original));
      }
    }
    else if (subtypeOfKeywordP(testValue000)) {
      { Object* self004 = self;
        Keyword* self = ((Keyword*)(self004));

        return (coerceToDescription(lookupSurrogate(self->symbolName), original));
      }
    }
    else if (subtypeOfStringP(testValue000)) {
      { Object* self005 = self;
        StringWrapper* self = ((StringWrapper*)(self005));

        return (coerceToDescription(lookupSurrogate(self->wrapperValue), original));
      }
    }
    else {
      return (coerceToDescription(NULL, original));
    }
  }
}

TruthValue* specializesP(Object* subobject, Object* superobject) {
  // Try to prove if the description associated with `subObject'
  // specializes the description for `superObject' and return the result truth
  // value of the query.
  { Description* subdescription = coerceToDescription(subobject, NULL);
    Description* superdescription = coerceToDescription(superobject, NULL);

    finalizeObjects();
    { 
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, getInferenceCache(oMODULEo.get(), KWD_QUERY_META));
      if (((boolean)(subdescription)) &&
          ((boolean)(superdescription))) {
        return (descriptionSpecializesDescriptionP(subdescription, superdescription));
      }
    }
    return (UNKNOWN_TRUTH_VALUE);
  }
}

LogicObject* coerceToInstance(Object* self, Object* original) {
  // Return the logic instance referred to by 'self'.
  if (!((boolean)(original))) {
    original = self;
  }
  if (!((boolean)(self))) {
    std::cout << "Can't find a logic object " << "`" << original << "'" << "." << std::endl;
    return (NULL);
  }
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        return (self);
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_STELLA_RELATION)) {
      { Object* self001 = self;
        Relation* self = ((Relation*)(self001));

        return (getDescription(self));
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* self002 = self;
        Surrogate* self = ((Surrogate*)(self002));

        { Object* value = self->surrogateValue;
          ObjectStore* store = NULL;

          if (!((boolean)(value))) {
            store = homeObjectStore(self);
            if (((boolean)(store))) {
              value = store->fetchInstance(self);
            }
          }
          return (coerceToInstance(value, original));
        }
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* self003 = self;
        Symbol* self = ((Symbol*)(self003));

        return (coerceToInstance(symbolToSurrogate(self), original));
      }
    }
    else if (subtypeOfKeywordP(testValue000)) {
      { Object* self004 = self;
        Keyword* self = ((Keyword*)(self004));

        return (coerceToInstance(lookupSurrogate(self->symbolName), original));
      }
    }
    else if (subtypeOfStringP(testValue000)) {
      { Object* self005 = self;
        StringWrapper* self = ((StringWrapper*)(self005));

        return (coerceToInstance(lookupSurrogate(self->wrapperValue), original));
      }
    }
    else {
      return (coerceToInstance(NULL, original));
    }
  }
}

Object* coerceToInstanceOrLiteral(Object* self, Object* original) {
  // Return the logic instance referred to by `self', or `self' if it is a
  // literal (e.g., string or number) that can't be coerced.
  if (!((boolean)(original))) {
    if (((boolean)(self))) {
      original = self;
    }
    else {
      return (NULL);
    }
  }
  if (!((boolean)(self))) {
    if (wrapperP(original)) {
      return (original);
    }
    else {
      std::cout << "Can't find a logic object " << "`" << original << "'" << "." << std::endl;
      return (NULL);
    }
  }
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_QUERY_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        return (self);
      }
    }
    else if (subtypeOfP(testValue000, SGT_QUERY_STELLA_RELATION)) {
      { Object* self001 = self;
        Relation* self = ((Relation*)(self001));

        return (getDescription(self));
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* self002 = self;
        Surrogate* self = ((Surrogate*)(self002));

        return (coerceToInstanceOrLiteral(self->surrogateValue, original));
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* self003 = self;
        Symbol* self = ((Symbol*)(self003));

        return (coerceToInstanceOrLiteral(symbolToSurrogate(self), original));
      }
    }
    else if (subtypeOfKeywordP(testValue000)) {
      { Object* self004 = self;
        Keyword* self = ((Keyword*)(self004));

        return (coerceToInstanceOrLiteral(lookupSurrogate(self->symbolName), original));
      }
    }
    else if (subtypeOfStringP(testValue000)) {
      { Object* self005 = self;
        StringWrapper* self = ((StringWrapper*)(self005));

        return (coerceToInstanceOrLiteral(lookupSurrogate(self->wrapperValue), original));
      }
    }
    else {
      return (coerceToInstanceOrLiteral(NULL, original));
    }
  }
}

Vector* coerceToVector(Object* self) {
  // Return a vector containing the elements in `self'.
  // Coerce each element of `self' to be a logic object or literal.
  { Vector* vector = NULL;

    { Surrogate* testValue000 = safePrimaryType(self);

      if (subtypeOfP(testValue000, SGT_QUERY_STELLA_VECTOR)) {
        { Object* self000 = self;
          Vector* self = ((Vector*)(self000));

          vector = self;
          { Object* m = NULL;
            Vector* vector000 = self;
            int index000 = 0;
            int length000 = vector000->length();
            int i = NULL_INTEGER;
            int iter000 = 0;

            for  (m, vector000, index000, length000, i, iter000; 
                  index000 < length000; 
                  index000 = index000 + 1,
                  iter000 = iter000 + 1) {
              m = (vector000->theArray)[index000];
              i = iter000;
              (vector->theArray)[i] = (coerceToInstanceOrLiteral(m, NULL));
            }
          }
        }
      }
      else if (subtypeOfP(testValue000, SGT_QUERY_STELLA_LIST)) {
        { Object* self001 = self;
          List* self = ((List*)(self001));

          vector = newVector(self->length());
          { Object* m = NULL;
            Cons* iter001 = self->theConsList;
            int i = NULL_INTEGER;
            int iter002 = 0;

            for  (m, iter001, i, iter002; 
                  !(iter001 == NIL); 
                  iter001 = iter001->rest,
                  iter002 = iter002 + 1) {
              m = iter001->value;
              i = iter002;
              (vector->theArray)[i] = (coerceToInstanceOrLiteral(m, NULL));
            }
          }
        }
      }
      else if (testValue000 == SGT_QUERY_STELLA_CONS) {
        { Object* self002 = self;
          Cons* self = ((Cons*)(self002));

          vector = newVector(self->length());
          { Object* m = NULL;
            Cons* iter003 = self;
            int i = NULL_INTEGER;
            int iter004 = 0;

            for  (m, iter003, i, iter004; 
                  !(iter003 == NIL); 
                  iter003 = iter003->rest,
                  iter004 = iter004 + 1) {
              m = iter003->value;
              i = iter004;
              (vector->theArray)[i] = (coerceToInstanceOrLiteral(m, NULL));
            }
          }
        }
      }
      else {
        std::cout << "Don't know how to coerce " << "`" << self << "'" << " of type " << "`" << self->primaryType() << "'" << std::endl << "   into a vector." << std::endl;
      }
    }
    return (vector);
  }
}

TruthValue* satisfiesP(Object* instanceortuple, Object* relationref) {
  // Try to prove whether `instanceOrTuple' satisfies the
  // definition of the relation `relationRef' and return the result truth value
  // of the query.  `instanceOrTuple' can be a single object, the name or surrogate
  // of an object, or a collection (a list or vector) of objects.  `relationRef'
  // can be a relation, description, surrogate or relation name.
  { Description* description = coerceToDescription(relationref, NULL);

    if (((boolean)(description))) {
      finalizeObjects();
      { 
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, getQueryContext());
        BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
        if (isaP(instanceortuple, SGT_QUERY_STELLA_COLLECTION) ||
            consP(instanceortuple)) {
          { Vector* vector = coerceToVector(instanceortuple);

            if (((boolean)(vector))) {
              return (vectorSatisfiesDescriptionP(vector, description));
            }
          }
        }
        else {
          { LogicObject* instance = coerceToInstance(instanceortuple, NULL);

            if (((boolean)(instance))) {
              return (instanceSatisfiesDescriptionP(instance, description));
            }
          }
        }
      }
    }
    return (UNKNOWN_TRUTH_VALUE);
  }
}

boolean applyKappaP(Description* description, Vector* vector) {
  // Apply (inherit) the description 'description'
  // to members of the vector 'vector'.  Return TRUE if no clash was detected.
  // Constraint propagation happens only if it is enabled prior to calling
  // 'apply-kappa?'.
  try {
    inheritUnnamedDescription(vector, description, false);
  }
  catch (Clash& _e) {
    Clash* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e) << std::endl;
    return (false);
  }
  return (true);
}

Cons* updatePropositionsFromQuery(QueryIterator* query, Description* description, Module* module, Keyword* updatemode) {
  if (query->queryIsTrueFalseP()) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
        *(stream000->nativeStream) << "ERROR: " << "Can't yet assert/retract the result of a true/false query" << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_QUERY_ERROR);
      }
      throw *newPropositionError(stream000->theStringReader());
    }
  }
  { Description* querydescription = query->queryDescription();
    boolean partialP = query->queryIsPartialP();
    QuerySolutionTable* solutions = query->solutions;
    KeyValueList* mapping = newKeyValueList();
    boolean dontcheckduplicatesP = false;
    Proposition* proposition = NULL;
    Cons* propositions = NIL;
    int tenthousands = 0;
    boolean terminatelineP = false;

    if (((boolean)(description))) {
      if ((!(description->arity() == querydescription->arity())) &&
          ((!variableArityP(description)) ||
           (querydescription->arity() < description->ioVariables->length()))) {
        { OutputStringStream* stream001 = newOutputStringStream();

          { 
            BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
            *(stream001->nativeStream) << "ERROR: " << "Arity mismatch between query proposition and " << "`" << description << "'" << "." << std::endl;
            helpSignalPropositionError(stream001, KWD_QUERY_ERROR);
          }
          throw *newPropositionError(stream001->theStringReader());
        }
      }
    }
    else {
      description = querydescription;
    }
    if (!((boolean)(module))) {
      module = oMODULEo.get();
    }
    proposition = description->proposition;
    if (variableArityP(description) &&
        (querydescription->arity() > description->ioVariables->length())) {
      if (!((proposition->kind == KWD_QUERY_FUNCTION) ||
          (proposition->kind == KWD_QUERY_PREDICATE))) {
        { OutputStringStream* stream002 = newOutputStringStream();

          { 
            BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
            *(stream002->nativeStream) << "ERROR: " << "Illegal variable arity description." << "." << std::endl;
            helpSignalPropositionError(stream002, KWD_QUERY_ERROR);
          }
          throw *newPropositionError(stream002->theStringReader());
        }
      }
      proposition = shallowCopyProposition(proposition);
      proposition->arguments = querydescription->ioVariables->copy();
      description = querydescription;
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, module);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
      dontcheckduplicatesP = namedDescriptionP(description) &&
          getDescriptionExtension(((NamedDescription*)(description)), false)->emptyP();
      { QuerySolution* solution = NULL;
        DictionaryIterator* iter000 = ((DictionaryIterator*)(solutions->allocateIterator()));
        int i = NULL_INTEGER;
        int iter001 = 0;

        for  (solution, iter000, i, iter001; 
              iter000->nextP(); 
              iter001 = iter001 + 1) {
          solution = ((QuerySolution*)(iter000->value));
          i = iter001;
          mapping->clear();
          if (mod(i, 10000) == 9999) {
            if (((boolean)(oTRACED_KEYWORDSo)) &&
                oTRACED_KEYWORDSo->membP(KWD_QUERY_UPDATE_FROM_QUERY)) {
              std::cout << (tenthousands = tenthousands + 1);
              flushOutput(STANDARD_OUTPUT);
            }
            flushOutput(STANDARD_OUTPUT);
          }
          else if (mod(i, 1000) == 999) {
            if (((boolean)(oTRACED_KEYWORDSo)) &&
                oTRACED_KEYWORDSo->membP(KWD_QUERY_UPDATE_FROM_QUERY)) {
              std::cout << ".";
              flushOutput(STANDARD_OUTPUT);
            }
            flushOutput(STANDARD_OUTPUT);
            terminatelineP = true;
          }
          { PatternVariable* var = NULL;
            Vector* vector000 = description->ioVariables;
            int index000 = 0;
            int length000 = vector000->length();
            Object* binding = NULL;
            Vector* vector001 = solution->bindings;
            int index001 = 0;
            int length001 = vector001->length();

            for  (var, vector000, index000, length000, binding, vector001, index001, length001; 
                  (index000 < length000) &&
                      (index001 < length001); 
                  index000 = index000 + 1,
                  index001 = index001 + 1) {
              var = ((PatternVariable*)((vector000->theArray)[index000]));
              binding = (vector001->theArray)[index001];
              mapping->insertAt(var, binding);
            }
          }
          { Proposition* prop = NULL;
            Cons* iter002 = inheritAsTopLevelProposition(proposition, mapping);

            for (prop, iter002; !(iter002 == NIL); iter002 = iter002->rest) {
              prop = ((Proposition*)(iter002->value));
              setDynamicSlotValue(prop->dynamicSlots, SYM_QUERY_LOGIC_DESCRIPTIVEp, (false ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
              prop = recursivelyFastenDownPropositions(prop, dontcheckduplicatesP);
              { Keyword* thisupdatemode = updatemode;
                TruthValue* truthvalue = solution->truthValue;
                boolean equivalenceP = prop->kind == KWD_QUERY_EQUIVALENT;

                if ((truthvalue == FALSE_TRUTH_VALUE) ||
                    (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
                  thisupdatemode = invertUpdateMode(thisupdatemode);
                }
                if ((truthvalue == DEFAULT_TRUE_TRUTH_VALUE) ||
                    (truthvalue == DEFAULT_FALSE_TRUTH_VALUE)) {
                  thisupdatemode = defaultifyUpdateMode(thisupdatemode);
                }
                if (equivalenceP) {
                  updateEquivalenceProposition(prop, thisupdatemode);
                }
                else {
                  updatePropositionTruthValue(prop, thisupdatemode);
                }
                if (partialP) {
                  setDynamicSlotValue(prop->dynamicSlots, SYM_QUERY_LOGIC_WEIGHT, wrapFloat(solution->matchScore), NULL_FLOAT_WRAPPER);
                }
                propositions = cons(prop, propositions);
              }
            }
          }
        }
      }
    }
    if (terminatelineP) {
      if (((boolean)(oTRACED_KEYWORDSo)) &&
          oTRACED_KEYWORDSo->membP(KWD_QUERY_UPDATE_FROM_QUERY)) {
        std::cout << std::endl;
      }
    }
    return (propositions->reverse());
  }
}

QueryIterator* getQueryIteratorFromCommand(Cons* query) {
  { Object* queryiterator = evaluateLogicCommand(query, true);

    if ((!isaP(queryiterator, SGT_QUERY_LOGIC_QUERY_ITERATOR)) &&
        (symbolP(query->value) &&
         stringEqualP(stringSubsequence(((Symbol*)(query->value))->symbolName, 0, 3), "ASK"))) {
      queryiterator = oMOST_RECENT_QUERYo;
    }
    if (!isaP(queryiterator, SGT_QUERY_LOGIC_QUERY_ITERATOR)) {
      { OutputStringStream* stream000 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
          *(stream000->nativeStream) << "ERROR: " << "Couldn't generate a query iterator result from " << "`" << query << "'" << "." << std::endl;
          helpSignalPropositionError(stream000, KWD_QUERY_ERROR);
        }
        throw *newPropositionError(stream000->theStringReader());
      }
    }
    return (((QueryIterator*)(queryiterator)));
  }
}

Cons* assertFromQuery(Cons* query, Cons* options) {
  // Evaluate `query', instantiate the query proposition for each generated
  // solution and assert the resulting propositions.  The accepted syntax
  // is as follows:
  // 	 
  //  (assert-from-query <query-command>
  //                     [:relation <relation-name>]
  //                     [:pattern <description-term>]
  //                     [:module <module-name>])
  // 	
  // <query-command> has to be a strict or partial retrieval command. If a
  // :relation option is supplied, <relation-name> is used as the relation
  // of the resulting propositions.  In this case the bindings of each
  // solution will become arguments to the specified relation in the order
  // of `query's output variables (the arities have to match).  The
  // :pattern option is a generalization of this mechanism that specifies
  // an arbitrary proposition pattern to be instantiated by the query's
  // solution.  In this case <description-term> has to be a SETOFALL or
  // KAPPA expression whose IO-variables will be bound in sequence to the
  // bindings of a query solution to generate the resulting proposition.
  // Finally, if a :module option is specified, the assertions will be
  // generated in that module.  Note that for this to work the relations
  // referenced in the query proposition or pattern have to be visible in
  // the module.  Also, instances will not be copied to the target module,
  // therefore, the resulting propositions might reference external
  // out-of-module objects in case they are not visible there.
  // Here are some examples:
  // 	 
  //  (assert-from-query (retrieve all (foo ?x ?y)))
  //  (assert-from-query (retrieve all (?y ?x)
  //                              (exists ?z
  //                                (and (foo ?x ?z)
  //                                     (foo ?z ?y))))
  //                     :relation bar :module other)
  //  (assert-from-query
  //    (retrieve all (and (relation ?x) (symmetric ?x)))
  //    :pattern (kappa (?pred)
  //               (forall (?x ?y)
  //                 (=> (holds ?pred ?x ?y)
  //                     (holds ?pred ?y ?x))))))
  // 	
  // 
  try {
    { PropertyList* theoptions = parseLogicCommandOptions(options, listO(7, KWD_QUERY_MODULE, SGT_QUERY_STELLA_MODULE, KWD_QUERY_RELATION, SGT_QUERY_LOGIC_NAMED_DESCRIPTION, KWD_QUERY_PATTERN, SGT_QUERY_STELLA_CONS, NIL), true, false);
      QueryIterator* queryiterator = getQueryIteratorFromCommand(query);
      Description* pattern = NULL;

      if (((boolean)(theoptions->lookup(KWD_QUERY_PATTERN)))) {
        pattern = ((Description*)(conceiveTerm(theoptions->lookup(KWD_QUERY_PATTERN))));
      }
      return (updatePropositionsFromQuery(queryiterator, (((boolean)(pattern)) ? pattern : ((Description*)(theoptions->lookup(KWD_QUERY_RELATION)))), ((Module*)(theoptions->lookup(KWD_QUERY_MODULE))), KWD_QUERY_ASSERT_TRUE));
    }
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
  }
  return (NULL);
}

Cons* assertFromQueryEvaluatorWrapper(Cons* arguments) {
  return (assertFromQuery(((Cons*)(arguments->value)), arguments->rest));
}

Cons* retractFromQuery(Cons* query, Cons* options) {
  // Evaluate `query' which has to be a strict or partial retrieval
  // command, instantiate the query proposition for each generated solution
  // and retract the resulting propositions.  See `assert-from-query' for
  // available command options.
  try {
    { PropertyList* theoptions = parseLogicCommandOptions(options, listO(7, KWD_QUERY_MODULE, SGT_QUERY_STELLA_MODULE, KWD_QUERY_RELATION, SGT_QUERY_LOGIC_NAMED_DESCRIPTION, KWD_QUERY_PATTERN, SGT_QUERY_STELLA_CONS, NIL), true, false);
      QueryIterator* queryiterator = getQueryIteratorFromCommand(query);
      Description* pattern = NULL;

      if (((boolean)(theoptions->lookup(KWD_QUERY_PATTERN)))) {
        pattern = ((Description*)(conceiveTerm(theoptions->lookup(KWD_QUERY_PATTERN))));
      }
      return (updatePropositionsFromQuery(queryiterator, (((boolean)(pattern)) ? pattern : ((Description*)(theoptions->lookup(KWD_QUERY_RELATION)))), ((Module*)(theoptions->lookup(KWD_QUERY_MODULE))), KWD_QUERY_RETRACT_TRUE));
    }
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
  }
  return (NULL);
}

Cons* retractFromQueryEvaluatorWrapper(Cons* arguments) {
  return (retractFromQuery(((Cons*)(arguments->value)), arguments->rest));
}

char* displaySettings() {
  std::cout << std::endl << "*LAZY-SATELLITE-RULES?*" << " =  " << oLAZY_SATELLITE_RULESpo << std::endl << "*CACHE-SUCCEEDED-GOALS?*" << " =  " << oCACHE_SUCCEEDED_GOALSpo << std::endl << "*CACHE-FAILED-GOALS?*" << " =  " << oCACHE_FAILED_GOALSpo << std::endl << "*CACHE-GOAL-QUANTUM*" << " =  " << oCACHE_GOAL_QUANTUMo << std::endl << "*CACHE-INFERABLE-SUBCOLLECTIONS?*" << " =  " << oCACHE_INFERABLE_SUBCOLLECTIONSpo << std::endl << "*INFERENCELEVEL*" << " =  " << oINFERENCELEVELo.get() << std::endl << "*MAXIMUM-BACKTRACKING-DEPTH*" << " =  " << oMAXIMUM_BACKTRACKING_DEPTHo << std::endl << "*TYPE-CHECK-STRATEGY*" << " =  " << oTYPE_CHECK_STRATEGYo.get() << std::endl << "*DUPLICATE-SUBGOAL-STRATEGY*" << " =  " << oDUPLICATE_SUBGOAL_STRATEGYo << std::endl << "*DUPLICATE-GOAL-SEARCH-DEPTH*" << " =  " << oDUPLICATE_GOAL_SEARCH_DEPTHo << std::endl << "*DUPLICATE-RULE-SEARCH-DEPTH*" << " =  " << oDUPLICATE_RULE_SEARCH_DEPTHo << std::endl << "*GLOBALLY-CLOSED-COLLECTIONS?*" << " =  " << oGLOBALLY_CLOSED_COLLECTIONSpo << std::endl << "*DEFAULT-MAXIMUM-DEPTH*" << " =  " << oDEFAULT_MAXIMUM_DEPTHo << std::endl << "*INITIAL-BACKTRACKING-DEPTH*" << " =  " << oINITIAL_BACKTRACKING_DEPTHo << std::endl << "*ITERATIVE-DEEPENING-MODE?*" << " =  " << oITERATIVE_DEEPENING_MODEpo << std::endl << "*DUPLICATEINSTANCESCACHECROSSOVERPOINT*" << " =  " << oDUPLICATEINSTANCESCACHECROSSOVERPOINTo << std::endl << "*CLASSIFY-FROM-NON-INFERABLE-PARENTS-ONLY?*" << " =  " << oCLASSIFY_FROM_NON_INFERABLE_PARENTS_ONLYpo.get() << std::endl << std::endl;
  return ("");
}

void helpStartupQuery1() {
  {
    SGT_QUERY_LOGIC_INFERENCE_LEVEL = ((Surrogate*)(internRigidSymbolWrtModule("INFERENCE-LEVEL", NULL, 1)));
    SYM_QUERY_STELLA_KEYWORD = ((Symbol*)(internRigidSymbolWrtModule("KEYWORD", getStellaModule("/STELLA", true), 0)));
    SGT_QUERY_LOGIC_NORMAL_INFERENCE_LEVEL = ((Surrogate*)(internRigidSymbolWrtModule("NORMAL-INFERENCE-LEVEL", NULL, 1)));
    SGT_QUERY_LOGIC_BACKTRACKING_INFERENCE_LEVEL = ((Surrogate*)(internRigidSymbolWrtModule("BACKTRACKING-INFERENCE-LEVEL", NULL, 1)));
    SGT_QUERY_LOGIC_SUBSUMPTION_INFERENCE_LEVEL = ((Surrogate*)(internRigidSymbolWrtModule("SUBSUMPTION-INFERENCE-LEVEL", NULL, 1)));
    SGT_QUERY_LOGIC_SHALLOW_INFERENCE_LEVEL = ((Surrogate*)(internRigidSymbolWrtModule("SHALLOW-INFERENCE-LEVEL", NULL, 1)));
    SGT_QUERY_LOGIC_ASSERTION_INFERENCE_LEVEL = ((Surrogate*)(internRigidSymbolWrtModule("ASSERTION-INFERENCE-LEVEL", NULL, 1)));
    SGT_QUERY_LOGIC_REFUTATION_INFERENCE_LEVEL = ((Surrogate*)(internRigidSymbolWrtModule("REFUTATION-INFERENCE-LEVEL", NULL, 1)));
    KWD_QUERY_NORMAL = ((Keyword*)(internRigidSymbolWrtModule("NORMAL", NULL, 2)));
    KWD_QUERY_BACKTRACKING = ((Keyword*)(internRigidSymbolWrtModule("BACKTRACKING", NULL, 2)));
    KWD_QUERY_SUBSUMPTION = ((Keyword*)(internRigidSymbolWrtModule("SUBSUMPTION", NULL, 2)));
    KWD_QUERY_SHALLOW = ((Keyword*)(internRigidSymbolWrtModule("SHALLOW", NULL, 2)));
    KWD_QUERY_ASSERTION = ((Keyword*)(internRigidSymbolWrtModule("ASSERTION", NULL, 2)));
    KWD_QUERY_REFUTATION = ((Keyword*)(internRigidSymbolWrtModule("REFUTATION", NULL, 2)));
    SYM_QUERY_LOGIC_INFERENCE_LEVEL = ((Symbol*)(internRigidSymbolWrtModule("INFERENCE-LEVEL", NULL, 0)));
    KWD_QUERY_LOOKUP = ((Keyword*)(internRigidSymbolWrtModule("LOOKUP", NULL, 2)));
    KWD_QUERY_DUPLICATE_GOALS = ((Keyword*)(internRigidSymbolWrtModule("DUPLICATE-GOALS", NULL, 2)));
    KWD_QUERY_TRACE_SUBGOALS = ((Keyword*)(internRigidSymbolWrtModule("TRACE-SUBGOALS", NULL, 2)));
    KWD_QUERY_PROPAGATE = ((Keyword*)(internRigidSymbolWrtModule("PROPAGATE", NULL, 2)));
    KWD_QUERY_STRATEGIES = ((Keyword*)(internRigidSymbolWrtModule("STRATEGIES", NULL, 2)));
    SYM_QUERY_LOGIC_COST_ESTIMATE = ((Symbol*)(internRigidSymbolWrtModule("COST-ESTIMATE", NULL, 0)));
    SGT_QUERY_LOGIC_QUERY_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("QUERY-ITERATOR", NULL, 1)));
    SYM_QUERY_LOGIC_RESIDUE_GOALS = ((Symbol*)(internRigidSymbolWrtModule("RESIDUE-GOALS", NULL, 0)));
    SYM_QUERY_LOGIC_BEST_GOAL_SEQUENCE = ((Symbol*)(internRigidSymbolWrtModule("BEST-GOAL-SEQUENCE", NULL, 0)));
    SYM_QUERY_STELLA_BADp = ((Symbol*)(internRigidSymbolWrtModule("BAD?", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_EXTERNAL_VARIABLES = ((Symbol*)(internRigidSymbolWrtModule("EXTERNAL-VARIABLES", NULL, 0)));
    SYM_QUERY_LOGIC_EXHAUSTEDp = ((Symbol*)(internRigidSymbolWrtModule("EXHAUSTED?", NULL, 0)));
    SYM_QUERY_STELLA_OPTIONS = ((Symbol*)(internRigidSymbolWrtModule("OPTIONS", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_SOLUTIONS = ((Symbol*)(internRigidSymbolWrtModule("SOLUTIONS", NULL, 0)));
    SYM_QUERY_LOGIC_QUERY_CONTEXT = ((Symbol*)(internRigidSymbolWrtModule("QUERY-CONTEXT", NULL, 0)));
    SYM_QUERY_LOGIC_BASE_CONTROL_FRAME = ((Symbol*)(internRigidSymbolWrtModule("BASE-CONTROL-FRAME", NULL, 0)));
    SYM_QUERY_LOGIC_CURRENT_CONTROL_FRAME = ((Symbol*)(internRigidSymbolWrtModule("CURRENT-CONTROL-FRAME", NULL, 0)));
    SYM_QUERY_LOGIC_CURRENT_PATTERN_RECORD = ((Symbol*)(internRigidSymbolWrtModule("CURRENT-PATTERN-RECORD", NULL, 0)));
    SYM_QUERY_LOGIC_CURRENT_PARALLEL_THREAD = ((Symbol*)(internRigidSymbolWrtModule("CURRENT-PARALLEL-THREAD", NULL, 0)));
    SYM_QUERY_LOGIC_CONTROL_FRAME_PRIORITY_QUEUE = ((Symbol*)(internRigidSymbolWrtModule("CONTROL-FRAME-PRIORITY-QUEUE", NULL, 0)));
    SYM_QUERY_LOGIC_AUGMENTED_GOAL_CACHEp = ((Symbol*)(internRigidSymbolWrtModule("AUGMENTED-GOAL-CACHE?", NULL, 0)));
    SYM_QUERY_LOGIC_ACTIVE_GOAL_CACHES = ((Symbol*)(internRigidSymbolWrtModule("ACTIVE-GOAL-CACHES", NULL, 0)));
    SYM_QUERY_LOGIC_TRIGGERED_DEPTH_CUTOFFp = ((Symbol*)(internRigidSymbolWrtModule("TRIGGERED-DEPTH-CUTOFF?", NULL, 0)));
    SYM_QUERY_LOGIC_FAILED_TO_FIND_DUPLICATE_SUBGOALp = ((Symbol*)(internRigidSymbolWrtModule("FAILED-TO-FIND-DUPLICATE-SUBGOAL?", NULL, 0)));
    SYM_QUERY_LOGIC_FOUND_AT_LEAST_ONE_SOLUTIONp = ((Symbol*)(internRigidSymbolWrtModule("FOUND-AT-LEAST-ONE-SOLUTION?", NULL, 0)));
    SYM_QUERY_LOGIC_TIMESTAMP = ((Symbol*)(internRigidSymbolWrtModule("TIMESTAMP", NULL, 0)));
    SYM_QUERY_LOGIC_PARTIAL_MATCH_STRATEGY = ((Symbol*)(internRigidSymbolWrtModule("PARTIAL-MATCH-STRATEGY", NULL, 0)));
    SYM_QUERY_LOGIC_CURRENT_DEPTH_CUTOFF = ((Symbol*)(internRigidSymbolWrtModule("CURRENT-DEPTH-CUTOFF", NULL, 0)));
    SYM_QUERY_LOGIC_MAXIMUM_DEPTH = ((Symbol*)(internRigidSymbolWrtModule("MAXIMUM-DEPTH", NULL, 0)));
    SYM_QUERY_LOGIC_ALLOTTED_TIME = ((Symbol*)(internRigidSymbolWrtModule("ALLOTTED-TIME", NULL, 0)));
    SYM_QUERY_LOGIC_ALLOTTED_CLOCK_TICKS = ((Symbol*)(internRigidSymbolWrtModule("ALLOTTED-CLOCK-TICKS", NULL, 0)));
    SYM_QUERY_LOGIC_CURRENT_CLOCK_TICKS = ((Symbol*)(internRigidSymbolWrtModule("CURRENT-CLOCK-TICKS", NULL, 0)));
    SYM_QUERY_LOGIC_TIMEOUTp = ((Symbol*)(internRigidSymbolWrtModule("TIMEOUT?", NULL, 0)));
    SYM_QUERY_LOGIC_NEGATED_QUERY = ((Symbol*)(internRigidSymbolWrtModule("NEGATED-QUERY", NULL, 0)));
    SYM_QUERY_LOGIC_LATEST_PARTIAL_SCORE = ((Symbol*)(internRigidSymbolWrtModule("LATEST-PARTIAL-SCORE", NULL, 0)));
    SYM_QUERY_LOGIC_AUXILIARY_QUERY = ((Symbol*)(internRigidSymbolWrtModule("AUXILIARY-QUERY", NULL, 0)));
    SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE = ((Symbol*)(internRigidSymbolWrtModule("LATEST-POSITIVE-SCORE", NULL, 0)));
    SYM_QUERY_STELLA_DELETED_OBJECTp = ((Symbol*)(internRigidSymbolWrtModule("DELETED-OBJECT?", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_GOAL_BINDINGS = ((Symbol*)(internRigidSymbolWrtModule("GOAL-BINDINGS", NULL, 0)));
    SGT_QUERY_LOGIC_CONTROL_FRAME = ((Surrogate*)(internRigidSymbolWrtModule("CONTROL-FRAME", NULL, 1)));
    SYM_QUERY_STELLA_STATE = ((Symbol*)(internRigidSymbolWrtModule("STATE", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_PROPOSITION = ((Symbol*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 0)));
    SYM_QUERY_LOGIC_TRUTH_VALUE = ((Symbol*)(internRigidSymbolWrtModule("TRUTH-VALUE", NULL, 0)));
    SYM_QUERY_LOGIC_REVERSE_POLARITYp = ((Symbol*)(internRigidSymbolWrtModule("REVERSE-POLARITY?", NULL, 0)));
    SYM_QUERY_LOGIC_STARTING_CLOCK_TICKS = ((Symbol*)(internRigidSymbolWrtModule("STARTING-CLOCK-TICKS", NULL, 0)));
  }
}

void helpStartupQuery2() {
  {
    SYM_QUERY_LOGIC_UP = ((Symbol*)(internRigidSymbolWrtModule("UP", NULL, 0)));
    SYM_QUERY_LOGIC_DOWN = ((Symbol*)(internRigidSymbolWrtModule("DOWN", NULL, 0)));
    SYM_QUERY_STELLA_RESULT = ((Symbol*)(internRigidSymbolWrtModule("RESULT", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_ARGUMENT_CURSOR = ((Symbol*)(internRigidSymbolWrtModule("ARGUMENT-CURSOR", NULL, 0)));
    SYM_QUERY_LOGIC_PATTERN_RECORD = ((Symbol*)(internRigidSymbolWrtModule("PATTERN-RECORD", NULL, 0)));
    SYM_QUERY_LOGIC_INHERITED_PATTERN_RECORD = ((Symbol*)(internRigidSymbolWrtModule("INHERITED-PATTERN-RECORD", NULL, 0)));
    SYM_QUERY_LOGIC_CHOICE_POINT_UNBINDING_OFFSET = ((Symbol*)(internRigidSymbolWrtModule("CHOICE-POINT-UNBINDING-OFFSET", NULL, 0)));
    SYM_QUERY_LOGIC_CURRENT_STRATEGY = ((Symbol*)(internRigidSymbolWrtModule("CURRENT-STRATEGY", NULL, 0)));
    SYM_QUERY_LOGIC_NEXT_STRATEGIES = ((Symbol*)(internRigidSymbolWrtModule("NEXT-STRATEGIES", NULL, 0)));
    SYM_QUERY_LOGIC_PARTIAL_MATCH_FRAME = ((Symbol*)(internRigidSymbolWrtModule("PARTIAL-MATCH-FRAME", NULL, 0)));
    SYM_QUERY_LOGIC_JUSTIFICATIONS = ((Symbol*)(internRigidSymbolWrtModule("JUSTIFICATIONS", NULL, 0)));
    SYM_QUERY_LOGIC_CACHED_GOAL_RESULTp = ((Symbol*)(internRigidSymbolWrtModule("CACHED-GOAL-RESULT?", NULL, 0)));
    SYM_QUERY_LOGIC_DONT_CACHE_GOAL_FAILUREp = ((Symbol*)(internRigidSymbolWrtModule("DONT-CACHE-GOAL-FAILURE?", NULL, 0)));
    SGT_QUERY_LOGIC_PARALLEL_THREAD = ((Surrogate*)(internRigidSymbolWrtModule("PARALLEL-THREAD", NULL, 1)));
    SYM_QUERY_LOGIC_TOP_CONTROL_FRAME = ((Symbol*)(internRigidSymbolWrtModule("TOP-CONTROL-FRAME", NULL, 0)));
    SYM_QUERY_LOGIC_HYPOTHETICAL_WORLD = ((Symbol*)(internRigidSymbolWrtModule("HYPOTHETICAL-WORLD", NULL, 0)));
    SYM_QUERY_LOGIC_VARIABLE_BINDINGS = ((Symbol*)(internRigidSymbolWrtModule("VARIABLE-BINDINGS", NULL, 0)));
    SYM_QUERY_LOGIC_UNBINDING_STACK = ((Symbol*)(internRigidSymbolWrtModule("UNBINDING-STACK", NULL, 0)));
    SYM_QUERY_LOGIC_TOP_UNBINDING_STACK_OFFSET = ((Symbol*)(internRigidSymbolWrtModule("TOP-UNBINDING-STACK-OFFSET", NULL, 0)));
    SYM_QUERY_LOGIC_PRIORITY = ((Symbol*)(internRigidSymbolWrtModule("PRIORITY", NULL, 0)));
    SYM_QUERY_LOGIC_STATUS = ((Symbol*)(internRigidSymbolWrtModule("STATUS", NULL, 0)));
    SGT_QUERY_LOGIC_PARALLEL_CONTROL_FRAME = ((Surrogate*)(internRigidSymbolWrtModule("PARALLEL-CONTROL-FRAME", NULL, 1)));
    SYM_QUERY_LOGIC_CHILD_THREADS = ((Symbol*)(internRigidSymbolWrtModule("CHILD-THREADS", NULL, 0)));
    SYM_QUERY_LOGIC_UNBOUND_VARIABLESp = ((Symbol*)(internRigidSymbolWrtModule("UNBOUND-VARIABLES?", NULL, 0)));
    SYM_QUERY_LOGIC_CURRENT_CHILD_THREAD = ((Symbol*)(internRigidSymbolWrtModule("CURRENT-CHILD-THREAD", NULL, 0)));
    SYM_QUERY_LOGIC_SAVED_PARENT_CONTEXT = ((Symbol*)(internRigidSymbolWrtModule("SAVED-PARENT-CONTEXT", NULL, 0)));
    SYM_QUERY_LOGIC_SAVED_PARENT_PARALLEL_THREAD = ((Symbol*)(internRigidSymbolWrtModule("SAVED-PARENT-PARALLEL-THREAD", NULL, 0)));
    SGT_QUERY_LOGIC_CONTROL_FRAME_PRIORITY_QUEUE = ((Surrogate*)(internRigidSymbolWrtModule("CONTROL-FRAME-PRIORITY-QUEUE", NULL, 1)));
    SYM_QUERY_LOGIC_QUEUE = ((Symbol*)(internRigidSymbolWrtModule("QUEUE", NULL, 0)));
    KWD_QUERY_UPCLASSIFY = ((Keyword*)(internRigidSymbolWrtModule("UPCLASSIFY", NULL, 2)));
    KWD_QUERY_DOWNCLASSIFY = ((Keyword*)(internRigidSymbolWrtModule("DOWNCLASSIFY", NULL, 2)));
    KWD_QUERY_PARTIAL_MATCH = ((Keyword*)(internRigidSymbolWrtModule("PARTIAL-MATCH", NULL, 2)));
    SGT_QUERY_LOGIC_PROOF_ADJUNCT = ((Surrogate*)(internRigidSymbolWrtModule("PROOF-ADJUNCT", NULL, 1)));
    SGT_QUERY_LOGIC_PATTERN_RECORD = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-RECORD", NULL, 1)));
    SYM_QUERY_LOGIC_CONTROL_FRAME = ((Symbol*)(internRigidSymbolWrtModule("CONTROL-FRAME", NULL, 0)));
    SYM_QUERY_LOGIC_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 0)));
    SYM_QUERY_LOGIC_EXTERNAL_ARGUMENTS = ((Symbol*)(internRigidSymbolWrtModule("EXTERNAL-ARGUMENTS", NULL, 0)));
    SYM_QUERY_STELLA_BOOLEAN_VECTOR = ((Symbol*)(internRigidSymbolWrtModule("BOOLEAN-VECTOR", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_OPTIMAL_PATTERN = ((Symbol*)(internRigidSymbolWrtModule("OPTIMAL-PATTERN", NULL, 0)));
    SYM_QUERY_LOGIC_COLLECTION_LIST = ((Symbol*)(internRigidSymbolWrtModule("COLLECTION-LIST", NULL, 0)));
    SGT_QUERY_LOGIC_BOOLEAN_VECTOR_INDEX_NODE = ((Surrogate*)(internRigidSymbolWrtModule("BOOLEAN-VECTOR-INDEX-NODE", NULL, 1)));
    SYM_QUERY_LOGIC_TRUE_LINK = ((Symbol*)(internRigidSymbolWrtModule("TRUE-LINK", NULL, 0)));
    SYM_QUERY_LOGIC_FALSE_LINK = ((Symbol*)(internRigidSymbolWrtModule("FALSE-LINK", NULL, 0)));
    SYM_QUERY_LOGIC_THE_VECTOR = ((Symbol*)(internRigidSymbolWrtModule("THE-VECTOR", NULL, 0)));
    SGT_QUERY_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", NULL, 1)));
    KWD_QUERY_PATTERN = ((Keyword*)(internRigidSymbolWrtModule("PATTERN", NULL, 2)));
    KWD_QUERY_CONTAINED_BY = ((Keyword*)(internRigidSymbolWrtModule("CONTAINED-BY", NULL, 2)));
    KWD_QUERY_PARENT = ((Keyword*)(internRigidSymbolWrtModule("PARENT", NULL, 2)));
    SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR = ((Symbol*)(internRigidSymbolWrtModule("CACHED-BINDINGS-ITERATOR", NULL, 0)));
    KWD_QUERY_POPPED = ((Keyword*)(internRigidSymbolWrtModule("POPPED", NULL, 2)));
    KWD_QUERY_LOCAL = ((Keyword*)(internRigidSymbolWrtModule("LOCAL", NULL, 2)));
    KWD_QUERY_QUERY_STACKS = ((Keyword*)(internRigidSymbolWrtModule("QUERY-STACKS", NULL, 2)));
    SGT_QUERY_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 1)));
    SGT_QUERY_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
    SGT_QUERY_PL_KERNEL_KB_HOLDS = ((Surrogate*)(internRigidSymbolWrtModule("HOLDS", getStellaModule("/PL-KERNEL-KB", true), 1)));
    KWD_QUERY_NONE = ((Keyword*)(internRigidSymbolWrtModule("NONE", NULL, 2)));
    KWD_QUERY_SHALLOW_DISJOINT = ((Keyword*)(internRigidSymbolWrtModule("SHALLOW-DISJOINT", NULL, 2)));
    KWD_QUERY_DISJOINT = ((Keyword*)(internRigidSymbolWrtModule("DISJOINT", NULL, 2)));
    KWD_QUERY_ISA = ((Keyword*)(internRigidSymbolWrtModule("ISA", NULL, 2)));
    SGT_QUERY_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", NULL, 1)));
  }
}

void helpStartupQuery3() {
  {
    KWD_QUERY_PERFORMANCE_CLUES = ((Keyword*)(internRigidSymbolWrtModule("PERFORMANCE-CLUES", NULL, 2)));
    KWD_QUERY_WARNING = ((Keyword*)(internRigidSymbolWrtModule("WARNING", NULL, 2)));
    SYM_QUERY_STELLA_NULL = ((Symbol*)(internRigidSymbolWrtModule("NULL", getStellaModule("/STELLA", true), 0)));
    SGT_QUERY_STELLA_LIST = ((Surrogate*)(internRigidSymbolWrtModule("LIST", getStellaModule("/STELLA", true), 1)));
    SYM_QUERY_STELLA_SURROGATE_VALUE_INVERSE = ((Symbol*)(internRigidSymbolWrtModule("SURROGATE-VALUE-INVERSE", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_MASTER_PROPOSITION = ((Symbol*)(internRigidSymbolWrtModule("MASTER-PROPOSITION", NULL, 0)));
    KWD_QUERY_FLAT = ((Keyword*)(internRigidSymbolWrtModule("FLAT", NULL, 2)));
    KWD_QUERY_REALISTIC = ((Keyword*)(internRigidSymbolWrtModule("REALISTIC", NULL, 2)));
    KWD_QUERY_DOWN = ((Keyword*)(internRigidSymbolWrtModule("DOWN", NULL, 2)));
    KWD_QUERY_ITERATIVE_FORALL = ((Keyword*)(internRigidSymbolWrtModule("ITERATIVE-FORALL", NULL, 2)));
    KWD_QUERY_STATE_MACHINE = ((Keyword*)(internRigidSymbolWrtModule("STATE-MACHINE", NULL, 2)));
    KWD_QUERY_PARALLEL_STRATEGIES = ((Keyword*)(internRigidSymbolWrtModule("PARALLEL-STRATEGIES", NULL, 2)));
    KWD_QUERY_STRATEGY = ((Keyword*)(internRigidSymbolWrtModule("STRATEGY", NULL, 2)));
    KWD_QUERY_SPECIALIST = ((Keyword*)(internRigidSymbolWrtModule("SPECIALIST", NULL, 2)));
    KWD_QUERY_ATOMIC_GOAL = ((Keyword*)(internRigidSymbolWrtModule("ATOMIC-GOAL", NULL, 2)));
    SYM_QUERY_LOGIC_ANTECEDENTS_RULE = ((Symbol*)(internRigidSymbolWrtModule("ANTECEDENTS-RULE", NULL, 0)));
    KWD_QUERY_UP_TRUE = ((Keyword*)(internRigidSymbolWrtModule("UP-TRUE", NULL, 2)));
    KWD_QUERY_UP_FAIL = ((Keyword*)(internRigidSymbolWrtModule("UP-FAIL", NULL, 2)));
    KWD_QUERY_AND = ((Keyword*)(internRigidSymbolWrtModule("AND", NULL, 2)));
    KWD_QUERY_GOAL_TREE = ((Keyword*)(internRigidSymbolWrtModule("GOAL-TREE", NULL, 2)));
    KWD_QUERY_OR = ((Keyword*)(internRigidSymbolWrtModule("OR", NULL, 2)));
    KWD_QUERY_NOT = ((Keyword*)(internRigidSymbolWrtModule("NOT", NULL, 2)));
    KWD_QUERY_FULL_SUBQUERY = ((Keyword*)(internRigidSymbolWrtModule("FULL-SUBQUERY", NULL, 2)));
    KWD_QUERY_ANTECEDENTS = ((Keyword*)(internRigidSymbolWrtModule("ANTECEDENTS", NULL, 2)));
    SYM_QUERY_STELLA_ITERATOR = ((Symbol*)(internRigidSymbolWrtModule("ITERATOR", getStellaModule("/STELLA", true), 0)));
    KWD_QUERY_FAILURE = ((Keyword*)(internRigidSymbolWrtModule("FAILURE", NULL, 2)));
    KWD_QUERY_FINAL_SUCCESS = ((Keyword*)(internRigidSymbolWrtModule("FINAL-SUCCESS", NULL, 2)));
    SGT_QUERY_LOGIC_NN_PARTIAL_MATCH = ((Surrogate*)(internRigidSymbolWrtModule("NN-PARTIAL-MATCH", NULL, 1)));
    SYM_QUERY_LOGIC_MATCH_SCORE = ((Symbol*)(internRigidSymbolWrtModule("MATCH-SCORE", NULL, 0)));
    SYM_QUERY_LOGIC_SUPPORT = ((Symbol*)(internRigidSymbolWrtModule("SUPPORT", NULL, 0)));
    SYM_QUERY_LOGIC_BACK = ((Symbol*)(internRigidSymbolWrtModule("BACK", NULL, 0)));
    SYM_QUERY_LOGIC_JUSTIFICATION = ((Symbol*)(internRigidSymbolWrtModule("JUSTIFICATION", NULL, 0)));
    SYM_QUERY_LOGIC_GOAL_CACHE = ((Symbol*)(internRigidSymbolWrtModule("GOAL-CACHE", NULL, 0)));
    SYM_QUERY_LOGIC_DEBUG_FRAME_ID_INTERNAL = ((Symbol*)(internRigidSymbolWrtModule("DEBUG-FRAME-ID-INTERNAL", NULL, 0)));
    KWD_QUERY_MOVE_DOWN = ((Keyword*)(internRigidSymbolWrtModule("MOVE-DOWN", NULL, 2)));
    KWD_QUERY_CONTINUING_SUCCESS = ((Keyword*)(internRigidSymbolWrtModule("CONTINUING-SUCCESS", NULL, 2)));
    KWD_QUERY_MOVE_IN_PLACE = ((Keyword*)(internRigidSymbolWrtModule("MOVE-IN-PLACE", NULL, 2)));
    KWD_QUERY_TIMEOUT = ((Keyword*)(internRigidSymbolWrtModule("TIMEOUT", NULL, 2)));
    KWD_QUERY_FUNCTION = ((Keyword*)(internRigidSymbolWrtModule("FUNCTION", NULL, 2)));
    KWD_QUERY_PREDICATE = ((Keyword*)(internRigidSymbolWrtModule("PREDICATE", NULL, 2)));
    KWD_QUERY_EQUIVALENT = ((Keyword*)(internRigidSymbolWrtModule("EQUIVALENT", NULL, 2)));
    KWD_QUERY_IMPLIES = ((Keyword*)(internRigidSymbolWrtModule("IMPLIES", NULL, 2)));
    KWD_QUERY_SCAN_CACHED_BINDINGS = ((Keyword*)(internRigidSymbolWrtModule("SCAN-CACHED-BINDINGS", NULL, 2)));
    KWD_QUERY_FORALL = ((Keyword*)(internRigidSymbolWrtModule("FORALL", NULL, 2)));
    KWD_QUERY_EXISTS = ((Keyword*)(internRigidSymbolWrtModule("EXISTS", NULL, 2)));
    KWD_QUERY_CONSTANT = ((Keyword*)(internRigidSymbolWrtModule("CONSTANT", NULL, 2)));
    KWD_QUERY_FAIL = ((Keyword*)(internRigidSymbolWrtModule("FAIL", NULL, 2)));
    KWD_QUERY_CLUSTERED_CONJUNCTION = ((Keyword*)(internRigidSymbolWrtModule("CLUSTERED-CONJUNCTION", NULL, 2)));
    SYM_QUERY_STELLA_ARGUMENTS = ((Symbol*)(internRigidSymbolWrtModule("ARGUMENTS", getStellaModule("/STELLA", true), 0)));
    KWD_QUERY_DISJUNCTIVE_IMPLICATION_INTRODUCTION = ((Keyword*)(internRigidSymbolWrtModule("DISJUNCTIVE-IMPLICATION-INTRODUCTION", NULL, 2)));
    SYM_QUERY_LOGIC_FAIL = ((Symbol*)(internRigidSymbolWrtModule("FAIL", NULL, 0)));
    KWD_QUERY_DUPLICATE_GOALS_WITH_CACHING = ((Keyword*)(internRigidSymbolWrtModule("DUPLICATE-GOALS-WITH-CACHING", NULL, 2)));
    KWD_QUERY_MANUFACTURE_SKOLEM = ((Keyword*)(internRigidSymbolWrtModule("MANUFACTURE-SKOLEM", NULL, 2)));
    SYM_QUERY_LOGIC_IO_VARIABLES = ((Symbol*)(internRigidSymbolWrtModule("IO-VARIABLES", NULL, 0)));
    SGT_QUERY_LOGIC_NAMED_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("NAMED-DESCRIPTION", NULL, 1)));
    KWD_QUERY_DESCRIPTION = ((Keyword*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 2)));
    SYM_QUERY_LOGIC_CACHED_SINGLE_VALUEDp = ((Symbol*)(internRigidSymbolWrtModule("CACHED-SINGLE-VALUED?", NULL, 0)));
    KWD_QUERY_FAILED_OVERLAY = ((Keyword*)(internRigidSymbolWrtModule("FAILED-OVERLAY", NULL, 2)));
    SGT_QUERY_PL_KERNEL_KB_DISJOINT = ((Surrogate*)(internRigidSymbolWrtModule("DISJOINT", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SYM_QUERY_LOGIC_pD1 = ((Symbol*)(internRigidSymbolWrtModule("?D1", NULL, 0)));
  }
}

void helpStartupQuery4() {
  {
    SYM_QUERY_LOGIC_pD2 = ((Symbol*)(internRigidSymbolWrtModule("?D2", NULL, 0)));
    SYM_QUERY_LOGIC_DISJOINT = ((Symbol*)(internRigidSymbolWrtModule("DISJOINT", NULL, 0)));
    SYM_QUERY_LOGIC_F_DISJOINT_TERMSp_QUERY_000 = ((Symbol*)(internRigidSymbolWrtModule("F-DISJOINT-TERMS?-QUERY-000", NULL, 0)));
    SYM_QUERY_STELLA_OR = ((Symbol*)(internRigidSymbolWrtModule("OR", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_STELLA_AND = ((Symbol*)(internRigidSymbolWrtModule("AND", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_PL_KERNEL_KB_CLASS = ((Symbol*)(internRigidSymbolWrtModule("CLASS", getStellaModule("/PL-KERNEL-KB", true), 0)));
    SYM_QUERY_LOGIC_REFUTATION_DISJOINT = ((Symbol*)(internRigidSymbolWrtModule("REFUTATION-DISJOINT", NULL, 0)));
    SYM_QUERY_LOGIC_F_EXPENSIVE_DISJOINT_TERMSp_QUERY_000 = ((Symbol*)(internRigidSymbolWrtModule("F-EXPENSIVE-DISJOINT-TERMS?-QUERY-000", NULL, 0)));
    SGT_QUERY_PL_KERNEL_KB_COLLECTIONOF = ((Surrogate*)(internRigidSymbolWrtModule("COLLECTIONOF", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_QUERY_STELLA_COLLECTION = ((Surrogate*)(internRigidSymbolWrtModule("COLLECTION", getStellaModule("/STELLA", true), 1)));
    SGT_QUERY_LOGIC_SKOLEM = ((Surrogate*)(internRigidSymbolWrtModule("SKOLEM", NULL, 1)));
    SGT_QUERY_PL_KERNEL_KB_MEMBER_OF = ((Surrogate*)(internRigidSymbolWrtModule("MEMBER-OF", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_QUERY_LOGIC_DESCRIPTION_EXTENSION_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION-EXTENSION-ITERATOR", NULL, 1)));
    SYM_QUERY_LOGIC_ROOT_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("ROOT-DESCRIPTION", NULL, 0)));
    SYM_QUERY_LOGIC_SUBCOLLECTIONS = ((Symbol*)(internRigidSymbolWrtModule("SUBCOLLECTIONS", NULL, 0)));
    SYM_QUERY_LOGIC_EXTENSION_ITERATOR = ((Symbol*)(internRigidSymbolWrtModule("EXTENSION-ITERATOR", NULL, 0)));
    SYM_QUERY_LOGIC_REFERENCE_PROPOSITION = ((Symbol*)(internRigidSymbolWrtModule("REFERENCE-PROPOSITION", NULL, 0)));
    SYM_QUERY_LOGIC_ALREADY_GENERATED_LIST = ((Symbol*)(internRigidSymbolWrtModule("ALREADY-GENERATED-LIST", NULL, 0)));
    SYM_QUERY_LOGIC_ALREADY_GENERATED_TABLE = ((Symbol*)(internRigidSymbolWrtModule("ALREADY-GENERATED-TABLE", NULL, 0)));
    SYM_QUERY_LOGIC_REMOVING_DUPLICATESp = ((Symbol*)(internRigidSymbolWrtModule("REMOVING-DUPLICATES?", NULL, 0)));
    KWD_QUERY_GOAL_CACHES = ((Keyword*)(internRigidSymbolWrtModule("GOAL-CACHES", NULL, 2)));
    KWD_QUERY_DEPTH_VIOLATION = ((Keyword*)(internRigidSymbolWrtModule("DEPTH-VIOLATION", NULL, 2)));
    KWD_QUERY_DEPTH_CUTOFF = ((Keyword*)(internRigidSymbolWrtModule("DEPTH-CUTOFF", NULL, 2)));
    KWD_QUERY_TECHNICAL = ((Keyword*)(internRigidSymbolWrtModule("TECHNICAL", NULL, 2)));
    KWD_QUERY_LAY = ((Keyword*)(internRigidSymbolWrtModule("LAY", NULL, 2)));
    SGT_QUERY_LOGIC_QUERY_SOLUTION_TABLE = ((Surrogate*)(internRigidSymbolWrtModule("QUERY-SOLUTION-TABLE", NULL, 1)));
    SYM_QUERY_STELLA_THE_MAP = ((Symbol*)(internRigidSymbolWrtModule("THE-MAP", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_QUERY = ((Symbol*)(internRigidSymbolWrtModule("QUERY", NULL, 0)));
    SYM_QUERY_STELLA_FIRST = ((Symbol*)(internRigidSymbolWrtModule("FIRST", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_STELLA_LAST = ((Symbol*)(internRigidSymbolWrtModule("LAST", getStellaModule("/STELLA", true), 0)));
    SGT_QUERY_LOGIC_QUERY_SOLUTION = ((Surrogate*)(internRigidSymbolWrtModule("QUERY-SOLUTION", NULL, 1)));
    SYM_QUERY_LOGIC_BINDINGS = ((Symbol*)(internRigidSymbolWrtModule("BINDINGS", NULL, 0)));
    SYM_QUERY_LOGIC_BEST_JUSTIFICATION = ((Symbol*)(internRigidSymbolWrtModule("BEST-JUSTIFICATION", NULL, 0)));
    SYM_QUERY_LOGIC_ALL_JUSTIFICATIONS = ((Symbol*)(internRigidSymbolWrtModule("ALL-JUSTIFICATIONS", NULL, 0)));
    SYM_QUERY_STELLA_NEXT = ((Symbol*)(internRigidSymbolWrtModule("NEXT", getStellaModule("/STELLA", true), 0)));
    SGT_QUERY_LOGIC_QUERY_SOLUTION_TABLE_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("QUERY-SOLUTION-TABLE-ITERATOR", NULL, 1)));
    SYM_QUERY_STELLA_THE_TABLE = ((Symbol*)(internRigidSymbolWrtModule("THE-TABLE", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_STELLA_CURSOR = ((Symbol*)(internRigidSymbolWrtModule("CURSOR", getStellaModule("/STELLA", true), 0)));
    KWD_QUERY_TRACE_SOLUTIONS = ((Keyword*)(internRigidSymbolWrtModule("TRACE-SOLUTIONS", NULL, 2)));
    SYM_QUERY_LOGIC_ATOMIC_SINGLETONSp = ((Symbol*)(internRigidSymbolWrtModule("ATOMIC-SINGLETONS?", NULL, 0)));
    KWD_QUERY_EXECUTE_QUERY = ((Keyword*)(internRigidSymbolWrtModule("EXECUTE-QUERY", NULL, 2)));
    KWD_QUERY_DONT_OPTIMIZEp = ((Keyword*)(internRigidSymbolWrtModule("DONT-OPTIMIZE?", NULL, 2)));
    SYM_QUERY_LOGIC_DONT_OPTIMIZEp = ((Symbol*)(internRigidSymbolWrtModule("DONT-OPTIMIZE?", NULL, 0)));
    SYM_QUERY_LOGIC_INITIAL_BINDINGS = ((Symbol*)(internRigidSymbolWrtModule("INITIAL-BINDINGS", NULL, 0)));
    KWD_QUERY_ITERATIVE_DEEPENINGp = ((Keyword*)(internRigidSymbolWrtModule("ITERATIVE-DEEPENING?", NULL, 2)));
    SYM_QUERY_LOGIC_ITERATIVE_DEEPENINGp = ((Symbol*)(internRigidSymbolWrtModule("ITERATIVE-DEEPENING?", NULL, 0)));
    KWD_QUERY_MATCH_MODE = ((Keyword*)(internRigidSymbolWrtModule("MATCH-MODE", NULL, 2)));
    KWD_QUERY_STRICT = ((Keyword*)(internRigidSymbolWrtModule("STRICT", NULL, 2)));
    KWD_QUERY_DEFERRED_OPTIONS = ((Keyword*)(internRigidSymbolWrtModule("DEFERRED-OPTIONS", NULL, 2)));
    KWD_QUERY_ERROR = ((Keyword*)(internRigidSymbolWrtModule("ERROR", NULL, 2)));
    SYM_QUERY_STELLA_TRUE = ((Symbol*)(internRigidSymbolWrtModule("TRUE", getStellaModule("/STELLA", true), 0)));
    SYM_QUERY_LOGIC_KAPPA = ((Symbol*)(internRigidSymbolWrtModule("KAPPA", NULL, 0)));
    SYM_QUERY_STELLA_EXISTS = ((Symbol*)(internRigidSymbolWrtModule("EXISTS", getStellaModule("/STELLA", true), 0)));
    KWD_QUERY_HOW_MANY = ((Keyword*)(internRigidSymbolWrtModule("HOW-MANY", NULL, 2)));
    KWD_QUERY_SORT_BY = ((Keyword*)(internRigidSymbolWrtModule("SORT-BY", NULL, 2)));
    KWD_QUERY_SCORE = ((Keyword*)(internRigidSymbolWrtModule("SCORE", NULL, 2)));
    KWD_QUERY_MOVEOUT = ((Keyword*)(internRigidSymbolWrtModule("MOVEOUT", NULL, 2)));
    KWD_QUERY_MAXIMUM_DEPTH = ((Keyword*)(internRigidSymbolWrtModule("MAXIMUM-DEPTH", NULL, 2)));
    KWD_QUERY_INFERENCE_LEVEL = ((Keyword*)(internRigidSymbolWrtModule("INFERENCE-LEVEL", NULL, 2)));
    SGT_QUERY_STELLA_GENERALIZED_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("GENERALIZED-SYMBOL", getStellaModule("/STELLA", true), 1)));
  }
}

void helpStartupQuery5() {
  {
    KWD_QUERY_THREE_VALUEDp = ((Keyword*)(internRigidSymbolWrtModule("THREE-VALUED?", NULL, 2)));
    KWD_QUERY_SINGLETONSp = ((Keyword*)(internRigidSymbolWrtModule("SINGLETONS?", NULL, 2)));
    KWD_QUERY_MINIMUM_SCORE = ((Keyword*)(internRigidSymbolWrtModule("MINIMUM-SCORE", NULL, 2)));
    KWD_QUERY_MAXIMIZE_SCOREp = ((Keyword*)(internRigidSymbolWrtModule("MAXIMIZE-SCORE?", NULL, 2)));
    KWD_QUERY_MAXIMUM_UNKNOWNS = ((Keyword*)(internRigidSymbolWrtModule("MAXIMUM-UNKNOWNS", NULL, 2)));
    SGT_QUERY_STELLA_PROPERTY_LIST = ((Surrogate*)(internRigidSymbolWrtModule("PROPERTY-LIST", getStellaModule("/STELLA", true), 1)));
    SGT_QUERY_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", getStellaModule("/STELLA", true), 1)));
    KWD_QUERY_DYNAMIC = ((Keyword*)(internRigidSymbolWrtModule("DYNAMIC", NULL, 2)));
    KWD_QUERY_DYNAMIC_WITH_CLUSTERING = ((Keyword*)(internRigidSymbolWrtModule("DYNAMIC-WITH-CLUSTERING", NULL, 2)));
    SGT_QUERY_PL_KERNEL_KB_CONCEPT_PROTOTYPE = ((Surrogate*)(internRigidSymbolWrtModule("CONCEPT-PROTOTYPE", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SYM_QUERY_LOGIC_pC = ((Symbol*)(internRigidSymbolWrtModule("?C", NULL, 0)));
    SYM_QUERY_LOGIC_pP = ((Symbol*)(internRigidSymbolWrtModule("?P", NULL, 0)));
    SYM_QUERY_PL_KERNEL_KB_CONCEPT_PROTOTYPE = ((Symbol*)(internRigidSymbolWrtModule("CONCEPT-PROTOTYPE", getStellaModule("/PL-KERNEL-KB", true), 0)));
    SYM_QUERY_LOGIC_F_GET_PROTOTYPE_QUERY_000 = ((Symbol*)(internRigidSymbolWrtModule("F-GET-PROTOTYPE-QUERY-000", NULL, 0)));
    KWD_QUERY_EXTENSIONAL_ASSERTION = ((Keyword*)(internRigidSymbolWrtModule("EXTENSIONAL-ASSERTION", NULL, 2)));
    KWD_QUERY_META = ((Keyword*)(internRigidSymbolWrtModule("META", NULL, 2)));
    SGT_QUERY_STELLA_RELATION = ((Surrogate*)(internRigidSymbolWrtModule("RELATION", getStellaModule("/STELLA", true), 1)));
    SGT_QUERY_STELLA_VECTOR = ((Surrogate*)(internRigidSymbolWrtModule("VECTOR", getStellaModule("/STELLA", true), 1)));
    KWD_QUERY_UPDATE_FROM_QUERY = ((Keyword*)(internRigidSymbolWrtModule("UPDATE-FROM-QUERY", NULL, 2)));
    SYM_QUERY_LOGIC_DESCRIPTIVEp = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTIVE?", NULL, 0)));
    SYM_QUERY_LOGIC_WEIGHT = ((Symbol*)(internRigidSymbolWrtModule("WEIGHT", NULL, 0)));
    KWD_QUERY_MODULE = ((Keyword*)(internRigidSymbolWrtModule("MODULE", NULL, 2)));
    SGT_QUERY_STELLA_MODULE = ((Surrogate*)(internRigidSymbolWrtModule("MODULE", getStellaModule("/STELLA", true), 1)));
    KWD_QUERY_RELATION = ((Keyword*)(internRigidSymbolWrtModule("RELATION", NULL, 2)));
    KWD_QUERY_ASSERT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("ASSERT-TRUE", NULL, 2)));
    KWD_QUERY_RETRACT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("RETRACT-TRUE", NULL, 2)));
    SYM_QUERY_LOGIC_STARTUP_QUERY = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-QUERY", NULL, 0)));
    SYM_QUERY_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
  }
}

void helpStartupQuery6() {
  {
    { NormalInferenceLevel* self029 = newNormalInferenceLevel();

      self029->keyword = KWD_QUERY_NORMAL;
      NORMAL_INFERENCE = self029;
    }
    { BacktrackingInferenceLevel* self030 = newBacktrackingInferenceLevel();

      self030->keyword = KWD_QUERY_BACKTRACKING;
      BACKTRACKING_INFERENCE = self030;
    }
    { SubsumptionInferenceLevel* self031 = newSubsumptionInferenceLevel();

      self031->keyword = KWD_QUERY_SUBSUMPTION;
      SUBSUMPTION_INFERENCE = self031;
    }
    { ShallowInferenceLevel* self032 = newShallowInferenceLevel();

      self032->keyword = KWD_QUERY_SHALLOW;
      SHALLOW_INFERENCE = self032;
    }
    { AssertionInferenceLevel* self033 = newAssertionInferenceLevel();

      self033->keyword = KWD_QUERY_ASSERTION;
      ASSERTION_INFERENCE = self033;
    }
    { RefutationInferenceLevel* self034 = newRefutationInferenceLevel();

      self034->keyword = KWD_QUERY_REFUTATION;
      REFUTATION_INFERENCE = self034;
    }
    oINFERENCELEVELo.set(NORMAL_INFERENCE);
    oMAXIMUM_BACKTRACKING_DEPTHo = oDEFAULT_MAXIMUM_DEPTHo;
    oTYPE_CHECK_STRATEGYo.set(KWD_QUERY_LOOKUP);
    oDUPLICATE_SUBGOAL_STRATEGYo = KWD_QUERY_DUPLICATE_GOALS;
    { PropertyList* self035 = newPropertyList();

      self035->thePlist = listO(3, KWD_QUERY_UPCLASSIFY, wrapCharacter('u'), listO(3, KWD_QUERY_DOWNCLASSIFY, wrapCharacter('d'), listO(3, KWD_QUERY_PROPAGATE, wrapCharacter('f'), listO(3, KWD_QUERY_PARTIAL_MATCH, wrapCharacter('p'), NIL))));
      oTHINKING_DOT_TABLEo = self035;
    }
    { BooleanVectorIndexNode* self036 = newBooleanVectorIndexNode();

      self036->theVector = newBooleanVector(0);
      oBOOLEAN_VECTOR_INDEXo = self036;
    }
    oQUERY_CACHEo = newHashTable();
  }
}

void helpStartupQuery7() {
  {
    { Class* clasS = defineClassFromStringifiedSource("INFERENCE-LEVEL", "(DEFCLASS INFERENCE-LEVEL (STANDARD-OBJECT) :SLOTS ((KEYWORD :TYPE KEYWORD)) :DOCUMENTATION \"This class hierarchy is used to choose the\nlevel of inference applied when dispatching queries (canned\nor ad hoc).\")");

      clasS->classConstructorCode = ((cpp_function_code)(&newInferenceLevel));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessInferenceLevelSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("NORMAL-INFERENCE-LEVEL", "(DEFCLASS NORMAL-INFERENCE-LEVEL (INFERENCE-LEVEL) :DOCUMENTATION \"The normal inference level employs all proof strategies\nexcept disjunctive implication introduction and refutation.\")");

      clasS->classConstructorCode = ((cpp_function_code)(&newNormalInferenceLevel));
    }
    { Class* clasS = defineClassFromStringifiedSource("BACKTRACKING-INFERENCE-LEVEL", "(DEFCLASS BACKTRACKING-INFERENCE-LEVEL (NORMAL-INFERENCE-LEVEL) :DOCUMENTATION \"Specifies subsumption level inference plus backtracking.\")");

      clasS->classConstructorCode = ((cpp_function_code)(&newBacktrackingInferenceLevel));
    }
    { Class* clasS = defineClassFromStringifiedSource("SUBSUMPTION-INFERENCE-LEVEL", "(DEFCLASS SUBSUMPTION-INFERENCE-LEVEL (BACKTRACKING-INFERENCE-LEVEL) :DOCUMENTATION \"Specifies lookup augmented with cached\nsubsumption links and equality reasoning.\")");

      clasS->classConstructorCode = ((cpp_function_code)(&newSubsumptionInferenceLevel));
    }
    { Class* clasS = defineClassFromStringifiedSource("SHALLOW-INFERENCE-LEVEL", "(DEFCLASS SHALLOW-INFERENCE-LEVEL (SUBSUMPTION-INFERENCE-LEVEL) :DOCUMENTATION \"Specifies lookup of assertions plus simple frame computations.\")");

      clasS->classConstructorCode = ((cpp_function_code)(&newShallowInferenceLevel));
    }
    { Class* clasS = defineClassFromStringifiedSource("ASSERTION-INFERENCE-LEVEL", "(DEFCLASS ASSERTION-INFERENCE-LEVEL (SUBSUMPTION-INFERENCE-LEVEL) :DOCUMENTATION \"Specifies lookup of assertions only.\")");

      clasS->classConstructorCode = ((cpp_function_code)(&newAssertionInferenceLevel));
    }
    { Class* clasS = defineClassFromStringifiedSource("REFUTATION-INFERENCE-LEVEL", "(DEFCLASS REFUTATION-INFERENCE-LEVEL (NORMAL-INFERENCE-LEVEL) :DOCUMENTATION \"Normal inference augmented by refutation proof strategy.\")");

      clasS->classConstructorCode = ((cpp_function_code)(&newRefutationInferenceLevel));
    }
    defineStellaTypeFromStringifiedSource("(DEFTYPE COST-ESTIMATE FLOAT \"Type used by the query optimizer to compute estimates of the cost of\nexecuting a query.\")");
    { Class* clasS = defineClassFromStringifiedSource("QUERY-ITERATOR", "(DEFCLASS QUERY-ITERATOR (ITERATOR DYNAMIC-SLOTS-MIXIN) :PUBLIC? TRUE :DOCUMENTATION \"A query iterator points to a query environment\nrepresenting the initial or intermediate state of a query.  The iterator's\n'value' is a vector representing a satisfying set bindings of the query's\noutput variables.  Each call to the iterator writes a new set of bindings\ninto the vector.\" :PARAMETERS ((ANY-VALUE :TYPE QUERY-SOLUTION)) :PUBLIC-SLOTS ((EXTERNAL-VARIABLES :TYPE VARIABLES-VECTOR) (INITIAL-BINDINGS :TYPE ARGUMENTS-VECTOR :ALLOCATION :DYNAMIC :DOCUMENTATION \"Supports cached queries; conceivably, this could be static.\") (EXHAUSTED? :TYPE BOOLEAN) (AUXILIARY-QUERY :TYPE QUERY-ITERATOR :ALLOCATION :DYNAMIC) (NEGATED-QUERY :RENAMES AUXILIARY-QUERY) (OPTIONS :TYPE PROPERTY-LIST :INITIALLY (NEW PROPERTY-LIST)) (SOLUTIONS :TYPE QUERY-SOLUTION-TABLE :INITIALLY (NEW QUERY-SOLUTION-TABLE) :DOCUMENTATION \"Each element holds a solution record with a\nvector of bindings of the free external variables of the query plus " "all\nthe appropriate truth-value and justification support.\") (ATOMIC-SINGLETONS? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DOCUMENTATION \"If TRUE, then singleton result tuples are\nconsified (and printed) as atoms instead of singleton lists.\") (QUERY-CONTEXT :TYPE CONTEXT) (BASE-CONTROL-FRAME :TYPE CONTROL-FRAME) (CURRENT-CONTROL-FRAME :TYPE CONTROL-FRAME) (CURRENT-PATTERN-RECORD :TYPE PATTERN-RECORD) (CURRENT-PARALLEL-THREAD :TYPE PARALLEL-THREAD) (CONTROL-FRAME-PRIORITY-QUEUE :TYPE CONTROL-FRAME-PRIORITY-QUEUE) (AUGMENTED-GOAL-CACHE? :TYPE BOOLEAN) (ACTIVE-GOAL-CACHES :TYPE (LIST OF GOAL-CACHE) :ALLOCATION :EMBEDDED) (TRIGGERED-DEPTH-CUTOFF? :TYPE BOOLEAN) (FAILED-TO-FIND-DUPLICATE-SUBGOAL? :TYPE BOOLEAN) (FOUND-AT-LEAST-ONE-SOLUTION? :TYPE BOOLEAN) (TIMESTAMP :TYPE TIMESTAMP) (PARTIAL-MATCH-STRATEGY :TYPE PARTIAL-MATCH-FRAME) (LATEST-POSITIVE-SCORE :TYPE PARTIAL-MATCH-SCORE :ALLOCATION :DYNAMIC) (LATEST-PARTIAL-SCORE :TYPE PARTIAL-MATCH-SCORE :RENAMES LATEST-POSITIVE-SCORE) (OPTIMIZER-GOAL-RECORDS :TYPE (EX" "TENSIBLE-VECTOR OF GOAL-RECORD) :ALLOCATION :DYNAMIC) (RESIDUE-GOALS :TYPE (LIST OF PROPOSITION) :ALLOCATION :DYNAMIC) (BEST-GOAL-SEQUENCE :TYPE (LIST OF PROPOSITION) :ALLOCATION :DYNAMIC) (BEST-COST :TYPE COST-ESTIMATE :ALLOCATION :DYNAMIC) (INFERENCE-LEVEL :TYPE INFERENCE-LEVEL) (ITERATIVE-DEEPENING? :TYPE BOOLEAN :ALLOCATION :DYNAMIC) (CURRENT-DEPTH-CUTOFF :TYPE INTEGER) (MAXIMUM-DEPTH :TYPE INTEGER) (ALLOTTED-TIME :TYPE FLOAT :DOCUMENTATION \"If defined, timeout after that many seconds.\") (ALLOTTED-CLOCK-TICKS :TYPE INTEGER :DOCUMENTATION \"If defined, timeout after that many :DOWN moves.\") (CURRENT-CLOCK-TICKS :TYPE INTEGER :INITIALLY 0) (TIMEOUT? :TYPE BOOLEAN :DOCUMENTATION \"Set to TRUE if query times out.\")) :PRINT-FORM (PRINT-QUERY-ITERATOR SELF STREAM))");

      clasS->classConstructorCode = ((cpp_function_code)(&newQueryIterator));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessQueryIteratorSlotValue));
    }
    defineStellaTypeFromStringifiedSource("(DEFTYPE GOAL-BINDINGS (CONS OF OBJECT))");
    { Class* clasS = defineClassFromStringifiedSource("CONTROL-FRAME", "(DEFCLASS CONTROL-FRAME (STANDARD-OBJECT DYNAMIC-SLOTS-MIXIN) :PUBLIC? TRUE :PUBLIC-SLOTS ((STATE :TYPE KEYWORD) (PROPOSITION :TYPE PROPOSITION) (DESCRIPTION :TYPE DESCRIPTION :ALLOCATION :DYNAMIC) (TRUTH-VALUE :TYPE TRUTH-VALUE) (REVERSE-POLARITY? :TYPE BOOLEAN) (STARTING-CLOCK-TICKS :TYPE INTEGER :DOCUMENTATION \"Clock ticks at last :DOWN move.\") (ALLOTTED-CLOCK-TICKS :TYPE INTEGER :DOCUMENTATION \"Total clock ticks allotted to prove this goal.\") (UP :TYPE CONTROL-FRAME) (DOWN :TYPE CONTROL-FRAME) (BACK :TYPE CONTROL-FRAME :ALLOCATION :DYNAMIC) (RESULT :TYPE CONTROL-FRAME) (ARGUMENTS :TYPE (VECTOR OF CONTROL-FRAME) :ALLOCATION :DYNAMIC) (ARGUMENT-CURSOR :TYPE INTEGER :INITIALLY 0) (PATTERN-RECORD :TYPE PATTERN-RECORD) (INHERITED-PATTERN-RECORD :TYPE PATTERN-RECORD) (CHOICE-POINT-UNBINDING-OFFSET :TYPE INTEGER) (CURRENT-STRATEGY :TYPE KEYWORD) (NEXT-STRATEGIES :TYPE (CONS OF KEYWORD) :INITIALLY NIL) (ITERATOR :TYPE ITERATOR :ALLOCATION :DYNAMIC) (ANTECEDENTS-RULE :TYPE PROPOSITION :ALLOCATION :DYNAMIC) (P" "ROOF-ADJUNCT :TYPE PROOF-ADJUNCT :ALLOCATION :DYNAMIC) (PARTIAL-MATCH-FRAME :TYPE PARTIAL-MATCH-FRAME) (JUSTIFICATIONS :TYPE LIST :ALLOCATION :EMBEDDED) (JUSTIFICATION :TYPE JUSTIFICATION :ALLOCATION :DYNAMIC) (CACHED-SINGLE-VALUED? :TYPE BOOLEAN :ALLOCATION :DYNAMIC) (GOAL-BINDINGS :TYPE GOAL-BINDINGS) (CACHED-GOAL-RESULT? :TYPE BOOLEAN) (DONT-CACHE-GOAL-FAILURE? :TYPE BOOLEAN) (GOAL-CACHE :TYPE GOAL-CACHE :ALLOCATION :DYNAMIC) (CACHED-BINDINGS-ITERATOR :TYPE (ITERATOR OF GOAL-BINDINGS) :ALLOCATION :DYNAMIC)) :PUBLIC-METHODS ((HOLDS-BY-DEFAULT? ((SELF CONTROL-FRAME)) :TYPE BOOLEAN :GLOBALLY-INLINE? TRUE (RETURN (DEFAULT-TRUTH-VALUE? (TRUTH-VALUE SELF))))) :PRINT-FORM (PRINT-CONTROL-FRAME SELF STREAM))");

      clasS->classConstructorCode = ((cpp_function_code)(&newControlFrame));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessControlFrameSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("PARALLEL-THREAD", "(DEFCLASS PARALLEL-THREAD (STANDARD-OBJECT) :SLOTS ((TOP-CONTROL-FRAME :TYPE CONTROL-FRAME) (HYPOTHETICAL-WORLD :TYPE WORLD) (VARIABLE-BINDINGS :TYPE (VECTOR OF OBJECT)) (UNBINDING-STACK :TYPE INTEGER-VECTOR) (TOP-UNBINDING-STACK-OFFSET :TYPE INTEGER) (PRIORITY :TYPE INTEGER) (STATUS :TYPE KEYWORD)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newParallelThread));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessParallelThreadSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("PARALLEL-CONTROL-FRAME", "(DEFCLASS PARALLEL-CONTROL-FRAME (CONTROL-FRAME) :SLOTS ((CHILD-THREADS :TYPE (LIST OF PARALLEL-THREAD) :ALLOCATION :EMBEDDED) (UNBOUND-VARIABLES? :TYPE BOOLEAN) (CURRENT-CHILD-THREAD :TYPE PARALLEL-THREAD) (SAVED-PARENT-CONTEXT :TYPE CONTEXT) (SAVED-PARENT-PARALLEL-THREAD :TYPE PARALLEL-THREAD)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newParallelControlFrame));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessParallelControlFrameSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("CONTROL-FRAME-PRIORITY-QUEUE", "(DEFCLASS CONTROL-FRAME-PRIORITY-QUEUE (STANDARD-OBJECT) :SLOTS ((QUEUE :TYPE (LIST OF PARALLEL-CONTROL-FRAME))))");

      clasS->classConstructorCode = ((cpp_function_code)(&newControlFramePriorityQueue));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessControlFramePriorityQueueSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("PROOF-ADJUNCT", "(DEFCLASS PROOF-ADJUNCT (STANDARD-OBJECT) :DOCUMENTATION \"Subclasses of 'PROOF-ADJUNCT' provide for specialized\nslots (specialized for a particular strategy) to hold a record of\nan ongoing proof thread.\")");

      clasS->classConstructorCode = ((cpp_function_code)(&newProofAdjunct));
    }
    { Class* clasS = defineClassFromStringifiedSource("PATTERN-RECORD", "(DEFCLASS PATTERN-RECORD (STANDARD-OBJECT) :DOCUMENTATION \"A pattern record records bookkeeping data used during\nthe processing of a description.\" :SLOTS ((CONTROL-FRAME :TYPE CONTROL-FRAME) (VARIABLE-BINDINGS :TYPE (VECTOR OF OBJECT)) (UNBINDING-STACK :TYPE INTEGER-VECTOR) (TOP-UNBINDING-STACK-OFFSET :TYPE INTEGER) (DESCRIPTION :TYPE DESCRIPTION) (EXTERNAL-ARGUMENTS :TYPE ARGUMENTS-VECTOR) (BOOLEAN-VECTOR :TYPE BOOLEAN-VECTOR) (OPTIMAL-PATTERN :TYPE DESCRIPTION) (COLLECTION-LIST :TYPE LIST)) :TERMINATOR TERMINATE-PATTERN-RECORD?)");

      clasS->classConstructorCode = ((cpp_function_code)(&newPatternRecord));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessPatternRecordSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("BOOLEAN-VECTOR-INDEX-NODE", "(DEFCLASS BOOLEAN-VECTOR-INDEX-NODE (STANDARD-OBJECT) :SLOTS ((TRUE-LINK :TYPE BOOLEAN-VECTOR-INDEX-NODE) (FALSE-LINK :TYPE BOOLEAN-VECTOR-INDEX-NODE) (THE-VECTOR :TYPE BOOLEAN-VECTOR)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newBooleanVectorIndexNode));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessBooleanVectorIndexNodeSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("DESCRIPTION-EXTENSION-ITERATOR", "(DEFCLASS DESCRIPTION-EXTENSION-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterates over the extension of a description and\nits subdescriptions, returning those propositions that are currently true.\" :PARAMETERS ((ANY-VALUE :TYPE PROPOSITION)) :SLOTS ((ROOT-DESCRIPTION :TYPE NAMED-DESCRIPTION) (SUBCOLLECTIONS :TYPE (CONS OF CONS) :INITIALLY NULL) (EXTENSION-ITERATOR :TYPE (ITERATOR OF PROPOSITION)) (REFERENCE-PROPOSITION :TYPE PROPOSITION) (ALREADY-GENERATED-LIST :TYPE LIST :INITIALLY (NEW LIST)) (ALREADY-GENERATED-TABLE :TYPE HASH-TABLE) (REMOVING-DUPLICATES? :TYPE BOOLEAN) (TRUTH-VALUE :TYPE TRUTH-VALUE)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newDescriptionExtensionIterator));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessDescriptionExtensionIteratorSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("QUERY-SOLUTION-TABLE", "(DEFCLASS QUERY-SOLUTION-TABLE (DICTIONARY) :DOCUMENTATION \"Special key/value map for query solutions indexed by output\nvariable binding vectors that also preserves the order of solution generation.\" :PARAMETERS ((ANY-KEY :TYPE ARGUMENTS-VECTOR) (ANY-VALUE :TYPE QUERY-SOLUTION)) :SLOTS ((THE-MAP :TYPE (KEY-VALUE-MAP OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF))) :INITIALLY (NEW KEY-VALUE-MAP :EQUAL-TEST? TRUE)) (QUERY :TYPE QUERY-ITERATOR) (FIRST :TYPE QUERY-SOLUTION) (LAST :TYPE QUERY-SOLUTION)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newQuerySolutionTable));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessQuerySolutionTableSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("QUERY-SOLUTION", "(DEFCLASS QUERY-SOLUTION (STANDARD-OBJECT) :SLOTS ((BINDINGS :TYPE ARGUMENTS-VECTOR) (TRUTH-VALUE :TYPE TRUTH-VALUE) (MATCH-SCORE :TYPE PARTIAL-MATCH-SCORE) (JUSTIFICATION :TYPE JUSTIFICATION) (BEST-JUSTIFICATION :TYPE JUSTIFICATION :RENAMES JUSTIFICATION) (ALL-JUSTIFICATIONS :TYPE (LIST OF JUSTIFICATION) :DOCUMENTATION \"All recorded justifications for\nthis solution in case we have multiple ones from a partial match operation.\") (NEXT :TYPE QUERY-SOLUTION)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newQuerySolution));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessQuerySolutionSlotValue));
    }
    { Class* clasS = defineClassFromStringifiedSource("QUERY-SOLUTION-TABLE-ITERATOR", "(DEFCLASS QUERY-SOLUTION-TABLE-ITERATOR (DICTIONARY-ITERATOR) :SLOTS ((THE-TABLE :TYPE QUERY-SOLUTION-TABLE) (CURSOR :TYPE QUERY-SOLUTION)))");

      clasS->classConstructorCode = ((cpp_function_code)(&newQuerySolutionTableIterator));
      clasS->classSlotAccessorCode = ((cpp_function_code)(&accessQuerySolutionTableIteratorSlotValue));
    }
  }
}

void helpStartupQuery8() {
  {
    defineExternalSlotFromStringifiedSource("(DEFSLOT MODULE INFERENCE-LEVEL :TYPE INFERENCE-LEVEL :DOCUMENTATION \"The default inference level used for inferences in a module.\" :ALLOCATION :DYNAMIC)");
    defineFunctionObject("CURRENT-INFERENCE-LEVEL", "(DEFUN (CURRENT-INFERENCE-LEVEL NORMAL-INFERENCE-LEVEL) () :DOCUMENTATION \"Return the current inference level that is active in the\ncurrent query, the current module, or, otherwise, globally.\" :PUBLIC? TRUE :COMMAND? TRUE)", ((cpp_function_code)(&currentInferenceLevel)), NULL);
    defineFunctionObject("GET-INFERENCE-LEVEL", "(DEFUN (GET-INFERENCE-LEVEL INFERENCE-LEVEL) ((LEVELKEYWORD KEYWORD)))", ((cpp_function_code)(&getInferenceLevel)), NULL);
    defineFunctionObject("SET-INFERENCE-LEVEL", "(DEFUN (SET-INFERENCE-LEVEL KEYWORD) ((LEVEL NAME) (MODULE NAME)) :DOCUMENTATION \"Set the inference level of `module' to the level specified\nby 'levelKeyword'.  If `module' is NULL, set the level globally.\" :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE)", ((cpp_function_code)(&setInferenceLevel)), NULL);
    defineFunctionObject("CALL-SET-INFERENCE-LEVEL", "(DEFUN (CALL-SET-INFERENCE-LEVEL KEYWORD) ((LEVELKEYWORD KEYWORD) (MODULE MODULE)) :DOCUMENTATION \"Set the inference level of `module' to the level specified\nby 'levelKeyword'.  If `module' is NULL and we are inside a query, set the\nlevel of the current query iterator.  Otherwise, set the level globally.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callSetInferenceLevel)), NULL);
    defineFunctionObject("USING-DEFAULT-KNOWLEDGE?", "(DEFUN (USING-DEFAULT-KNOWLEDGE? BOOLEAN) () :GLOBALLY-INLINE? TRUE (RETURN (NOT *DONTUSEDEFAULTKNOWLEDGE?*)))", ((cpp_function_code)(&usingDefaultKnowledgeP)), NULL);
    defineFunctionObject("TRACE-SUBGOALS", "(DEFUN TRACE-SUBGOALS ())", ((cpp_function_code)(&traceSubgoals)), NULL);
    defineFunctionObject("UNTRACE-SUBGOALS", "(DEFUN UNTRACE-SUBGOALS ())", ((cpp_function_code)(&untraceSubgoals)), NULL);
    defineFunctionObject("TRACE-RULES", "(DEFUN TRACE-RULES ())", ((cpp_function_code)(&traceRules)), NULL);
    defineFunctionObject("UNTRACE-RULES", "(DEFUN UNTRACE-RULES ())", ((cpp_function_code)(&untraceRules)), NULL);
    defineFunctionObject("TOGGLE-TRACE-SUBGOALS", "(DEFUN (TOGGLE-TRACE-SUBGOALS STRING) ())", ((cpp_function_code)(&toggleTraceSubgoals)), NULL);
    defineFunctionObject("TOGGLE-TRACE-RULES", "(DEFUN (TOGGLE-TRACE-RULES STRING) ())", ((cpp_function_code)(&toggleTraceRules)), NULL);
    defineFunctionObject("EMIT-THINKING-DOT", "(DEFUN EMIT-THINKING-DOT ((KINDOFTHINKING KEYWORD)))", ((cpp_function_code)(&emitThinkingDot)), NULL);
    defineFunctionObject("CREATE-BOOLEAN-VECTOR-INDEX-NODE", "(DEFUN (CREATE-BOOLEAN-VECTOR-INDEX-NODE BOOLEAN-VECTOR-INDEX-NODE) ((PARENTNODE BOOLEAN-VECTOR-INDEX-NODE) (LASTVALUE BOOLEAN)))", ((cpp_function_code)(&createBooleanVectorIndexNode)), NULL);
    defineFunctionObject("ARGUMENTS-VECTOR-TO-BOOLEAN-VECTOR", "(DEFUN (ARGUMENTS-VECTOR-TO-BOOLEAN-VECTOR BOOLEAN-VECTOR) ((ARGUMENTSVECTOR ARGUMENTS-VECTOR)))", ((cpp_function_code)(&argumentsVectorToBooleanVector)), NULL);
    defineFunctionObject("ZERO-ONE-LIST-TO-BOOLEAN-VECTOR", "(DEFUN (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR BOOLEAN-VECTOR) ((ZEROONELIST (LIST OF INTEGER-WRAPPER))))", ((cpp_function_code)(&zeroOneListToBooleanVector)), NULL);
    defineFunctionObject("POP-CONTROL-FRAME", "(DEFUN POP-CONTROL-FRAME ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&popControlFrame)), NULL);
    defineFunctionObject("POP-FRAMES-UP-TO", "(DEFUN POP-FRAMES-UP-TO ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&popFramesUpTo)), NULL);
    defineFunctionObject("POP-DOWN-FRAME", "(DEFUN POP-DOWN-FRAME ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&popDownFrame)), NULL);
    defineFunctionObject("ACTIVATE-PATTERN-RECORD", "(DEFUN ACTIVATE-PATTERN-RECORD ((PATTERNRECORD PATTERN-RECORD) (VARIABLECOUNT INTEGER)))", ((cpp_function_code)(&activatePatternRecord)), NULL);
    defineFunctionObject("RESET-CURRENT-PATTERN-RECORD", "(DEFUN RESET-CURRENT-PATTERN-RECORD ((FRAME CONTROL-FRAME) (LOCALORPARENT KEYWORD)))", ((cpp_function_code)(&resetCurrentPatternRecord)), NULL);
    defineFunctionObject("PRINT-ENVIRONMENT-STACKS", "(DEFUN PRINT-ENVIRONMENT-STACKS ())", ((cpp_function_code)(&printEnvironmentStacks)), NULL);
    defineFunctionObject("SET-PATTERN-VARIABLE-BINDING", "(DEFUN SET-PATTERN-VARIABLE-BINDING ((VARIABLE PATTERN-VARIABLE) (VALUE OBJECT)))", ((cpp_function_code)(&setPatternVariableBinding)), NULL);
    defineFunctionObject("CHANGE-PATTERN-VARIABLE-BINDING", "(DEFUN CHANGE-PATTERN-VARIABLE-BINDING ((VARIABLE PATTERN-VARIABLE) (NEWVALUE OBJECT)))", ((cpp_function_code)(&changePatternVariableBinding)), NULL);
    defineFunctionObject("UNBIND-VARIABLES-BEGINNING-AT", "(DEFUN UNBIND-VARIABLES-BEGINNING-AT ((PATTERNRECORD PATTERN-RECORD) (UBSTACKOFFSET INTEGER)))", ((cpp_function_code)(&unbindVariablesBeginningAt)), NULL);
    defineFunctionObject("CREATE-CHOICE-POINT", "(DEFUN CREATE-CHOICE-POINT ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&createChoicePoint)), NULL);
    defineFunctionObject("UNWIND-TO-CHOICE-POINT", "(DEFUN UNWIND-TO-CHOICE-POINT ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&unwindToChoicePoint)), NULL);
    defineFunctionObject("NEW-BINDINGS-SINCE-LAST-CHOICE-POINT?", "(DEFUN (NEW-BINDINGS-SINCE-LAST-CHOICE-POINT? BOOLEAN) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&newBindingsSinceLastChoicePointP)), NULL);
    defineFunctionObject("BOUND-TO", "(DEFUN (BOUND-TO OBJECT) ((SELF PATTERN-VARIABLE)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH (VARIABLE-BINDINGS (CURRENT-PATTERN-RECORD *QUERYITERATOR*)) (BOUND-TO-OFFSET SELF))))", ((cpp_function_code)(&boundTo)), NULL);
    defineFunctionObject("SAFE-BOUND-TO", "(DEFUN (SAFE-BOUND-TO OBJECT) ((SELF PATTERN-VARIABLE)))", ((cpp_function_code)(&safeBoundTo)), NULL);
    defineFunctionObject("BOUND-TO-IN-FRAME", "(DEFUN (BOUND-TO-IN-FRAME OBJECT) ((SELF PATTERN-VARIABLE) (FRAME CONTROL-FRAME)))", ((cpp_function_code)(&boundToInFrame)), NULL);
    defineFunctionObject("BOUND-TO-IN-RECORD", "(DEFUN (BOUND-TO-IN-RECORD OBJECT) ((SELF PATTERN-VARIABLE) (RECORD PATTERN-RECORD)) :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (NTH (VARIABLE-BINDINGS RECORD) (BOUND-TO-OFFSET SELF))))", ((cpp_function_code)(&boundToInRecord)), NULL);
    defineFunctionObject("CONTAINS-OPERATOR?", "(DEFUN (CONTAINS-OPERATOR? BOOLEAN) ((PROPOSITION PROPOSITION) (OPERATOR SURROGATE)) :PUBLIC? TRUE)", ((cpp_function_code)(&containsOperatorP)), NULL);
    defineFunctionObject("ARGUMENT-BOUND-TO", "(DEFUN (ARGUMENT-BOUND-TO OBJECT) ((SELF OBJECT)) :PUBLIC? TRUE)", ((cpp_function_code)(&argumentBoundTo)), NULL);
    defineFunctionObject("HELP-UNIFY-ATTRIBUTES?", "(DEFUN (HELP-UNIFY-ATTRIBUTES? BOOLEAN) ((VALUE1 OBJECT) (VALUE2 OBJECT)))", ((cpp_function_code)(&helpUnifyAttributesP)), NULL);
    defineFunctionObject("FAILS-UNIFICATION-TYPE-CHECK?", "(DEFUN (FAILS-UNIFICATION-TYPE-CHECK? BOOLEAN) ((V1 PATTERN-VARIABLE) (I2 OBJECT)))", ((cpp_function_code)(&failsUnificationTypeCheckP)), NULL);
    defineFunctionObject("FAILS-ANTECEDENT-TYPE-CHECK?", "(DEFUN (FAILS-ANTECEDENT-TYPE-CHECK? BOOLEAN) ((V1 PATTERN-VARIABLE) (I2 OBJECT)))", ((cpp_function_code)(&failsAntecedentTypeCheckP)), NULL);
    defineFunctionObject("HELP-BIND-VARIABLE-TO-VALUE?", "(DEFUN (HELP-BIND-VARIABLE-TO-VALUE? BOOLEAN) ((VARIABLE PATTERN-VARIABLE) (VALUE OBJECT)))", ((cpp_function_code)(&helpBindVariableToValueP)), NULL);
    defineFunctionObject("BIND-VARIABLE-TO-VALUE?", "(DEFUN (BIND-VARIABLE-TO-VALUE? BOOLEAN) ((VARIABLE PATTERN-VARIABLE) (VALUE OBJECT) (AUTOCLEANUP? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&bindVariableToValueP)), NULL);
    defineFunctionObject("BIND-ARGUMENT-TO-VALUE?", "(DEFUN (BIND-ARGUMENT-TO-VALUE? BOOLEAN) ((ARGUMENT OBJECT) (VALUE OBJECT) (AUTOCLEANUP? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&bindArgumentToValueP)), NULL);
    defineFunctionObject("BIND-VECTOR-OF-ARGUMENTS-TO-VALUES?", "(DEFUN (BIND-VECTOR-OF-ARGUMENTS-TO-VALUES? BOOLEAN) ((ARGUMENTS ARGUMENTS-VECTOR) (VALUES CONS)))", ((cpp_function_code)(&bindVectorOfArgumentsToValuesP)), NULL);
    defineFunctionObject("PRINT-CONTROL-FRAME-STACK", "(DEFUN PRINT-CONTROL-FRAME-STACK ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&printControlFrameStack)), NULL);
    defineFunctionObject("PCS", "(DEFUN PCS ())", ((cpp_function_code)(&pcs)), NULL);
    defineFunctionObject("VARIABLE-FROM-UNBINDING-OFFSET", "(DEFUN (VARIABLE-FROM-UNBINDING-OFFSET PATTERN-VARIABLE) ((DESCRIPTION DESCRIPTION) (UBOFFSET INTEGER)))", ((cpp_function_code)(&variableFromUnbindingOffset)), NULL);
    defineFunctionObject("PRINT-ONE-VARIABLE-BINDING", "(DEFUN PRINT-ONE-VARIABLE-BINDING ((VARIABLE PATTERN-VARIABLE)))", ((cpp_function_code)(&printOneVariableBinding)), NULL);
    defineFunctionObject("PRINT-VARIABLE-BINDINGS", "(DEFUN PRINT-VARIABLE-BINDINGS ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&printVariableBindings)), NULL);
    defineFunctionObject("PRINT-RULE-IN-GOAL-TREE", "(DEFUN PRINT-RULE-IN-GOAL-TREE ((FRAME CONTROL-FRAME) (IMPLIESPROP PROPOSITION) (DEPTH INTEGER)))", ((cpp_function_code)(&printRuleInGoalTree)), NULL);
    defineFunctionObject("PRINT-GOAL-IN-GOAL-TREE", "(DEFUN PRINT-GOAL-IN-GOAL-TREE ((FRAME CONTROL-FRAME) (DEPTH INTEGER)))", ((cpp_function_code)(&printGoalInGoalTree)), NULL);
    defineFunctionObject("COMPUTE-FRAME-DEPTH", "(DEFUN (COMPUTE-FRAME-DEPTH INTEGER) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&computeFrameDepth)), NULL);
    defineFunctionObject("PRINT-VERTICAL-BARS", "(DEFUN PRINT-VERTICAL-BARS ((DEPTH INTEGER)))", ((cpp_function_code)(&printVerticalBars)), NULL);
    defineFunctionObject("UNWIND-TO-CHOICE-POINTS-BELOW-FRAME", "(DEFUN UNWIND-TO-CHOICE-POINTS-BELOW-FRAME ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&unwindToChoicePointsBelowFrame)), NULL);
    defineFunctionObject("TRACE-GOAL-TREE", "(DEFUN TRACE-GOAL-TREE ((FRAME CONTROL-FRAME) (DEPTH INTEGER) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&traceGoalTree)), NULL);
    defineFunctionObject("OLD-INTERPRET-AND-SCORES", "(DEFUN (OLD-INTERPRET-AND-SCORES KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&oldInterpretAndScores)), NULL);
    defineMethodObject("(DEFMETHOD (CONTINUE-PARTIAL-AND-PROOF KEYWORD) ((SELF CONTROL-FRAME) (FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_method_code)(&ControlFrame::continuePartialAndProof)), ((cpp_method_code)(NULL)));
    defineFunctionObject("INTERPRET-ITERATIVE-FORALL-SCORES", "(DEFUN (INTERPRET-ITERATIVE-FORALL-SCORES KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&interpretIterativeForallScores)), NULL);
    defineFunctionObject("OLD-INTERPRET-OR-SCORES", "(DEFUN (OLD-INTERPRET-OR-SCORES KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&oldInterpretOrScores)), NULL);
    defineMethodObject("(DEFMETHOD (CONTINUE-PARTIAL-OR-PROOF KEYWORD) ((SELF CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_method_code)(&ControlFrame::continuePartialOrProof)), ((cpp_method_code)(NULL)));
    defineFunctionObject("OLD-INTERPRET-FAIL-SCORE", "(DEFUN (OLD-INTERPRET-FAIL-SCORE KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&oldInterpretFailScore)), NULL);
    defineMethodObject("(DEFMETHOD (CONTINUE-PARTIAL-NOT-PROOF KEYWORD) ((SELF CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_method_code)(&ControlFrame::continuePartialNotProof)), ((cpp_method_code)(NULL)));
    defineFunctionObject("OLD-INTERPRET-GOAL-SCORES", "(DEFUN (OLD-INTERPRET-GOAL-SCORES KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&oldInterpretGoalScores)), NULL);
  }
}

void helpStartupQuery9() {
  {
    defineFunctionObject("ATTACH-SUPPORT", "(DEFUN ATTACH-SUPPORT ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&attachSupport)), NULL);
    defineMethodObject("(DEFMETHOD (CONTINUE-PARTIAL-STRATEGIES-PROOFS KEYWORD) ((SELF CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_method_code)(&ControlFrame::continuePartialStrategiesProofs)), ((cpp_method_code)(NULL)));
    defineFunctionObject("OPERATIVE-PATTERN-RECORD", "(DEFUN (OPERATIVE-PATTERN-RECORD PATTERN-RECORD) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&operativePatternRecord)), NULL);
    defineFunctionObject("CREATE-DOWN-FRAME", "(DEFUN (CREATE-DOWN-FRAME CONTROL-FRAME) ((UPFRAME CONTROL-FRAME) (DOWNPROPOSITION PROPOSITION)))", ((cpp_function_code)(&createDownFrame)), NULL);
    defineFunctionObject("SET-FRAME-TRUTH-VALUE", "(DEFUN (SET-FRAME-TRUTH-VALUE TRUTH-VALUE) ((FRAME CONTROL-FRAME) (TRUTHVALUE TRUTH-VALUE)))", ((cpp_function_code)(&setFrameTruthValue)), NULL);
    defineFunctionObject("PROPAGATE-FRAME-TRUTH-VALUE", "(DEFUN (PROPAGATE-FRAME-TRUTH-VALUE TRUTH-VALUE) ((SOURCE CONTROL-FRAME) (TARGET CONTROL-FRAME)))", ((cpp_function_code)(&propagateFrameTruthValue)), NULL);
    defineExternalSlotFromStringifiedSource("(DEFSLOT CONTROL-FRAME DEBUG-FRAME-ID-INTERNAL :TYPE INTEGER :ALLOCATION :DYNAMIC)");
    defineFunctionObject("DEBUG-FRAME-ID", "(DEFUN (DEBUG-FRAME-ID INTEGER) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&debugFrameId)), NULL);
    defineFunctionObject("COPY-FRAME-STATE", "(DEFUN COPY-FRAME-STATE ((FROMFRAME CONTROL-FRAME) (TOFRAME CONTROL-FRAME)))", ((cpp_function_code)(&copyFrameState)), NULL);
    defineFunctionObject("PARALLELIZE-CONTROL-FRAME", "(DEFUN (PARALLELIZE-CONTROL-FRAME PARALLEL-CONTROL-FRAME) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&parallelizeControlFrame)), NULL);
    defineFunctionObject("ENTER-PARALLEL-THREAD", "(DEFUN ENTER-PARALLEL-THREAD ((PFRAME PARALLEL-CONTROL-FRAME) (CHILDTHREAD PARALLEL-THREAD)))", ((cpp_function_code)(&enterParallelThread)), NULL);
    defineFunctionObject("EXIT-PARALLEL-THREAD", "(DEFUN EXIT-PARALLEL-THREAD ((PFRAME PARALLEL-CONTROL-FRAME)))", ((cpp_function_code)(&exitParallelThread)), NULL);
    defineFunctionObject("ENTER-HYPOTHETICAL-WORLD", "(DEFUN (ENTER-HYPOTHETICAL-WORLD WORLD) ((PFRAME PARALLEL-CONTROL-FRAME)))", ((cpp_function_code)(&enterHypotheticalWorld)), NULL);
    defineFunctionObject("PARTIAL-MATCH-MODE?", "(DEFUN (PARTIAL-MATCH-MODE? BOOLEAN) () :GLOBALLY-INLINE? TRUE (RETURN (AND (DEFINED? *QUERYITERATOR*) (DEFINED? (PARTIAL-MATCH-STRATEGY *QUERYITERATOR*)))))", ((cpp_function_code)(&partialMatchModeP)), NULL);
    defineFunctionObject("EXECUTE-BACKWARD-CHAINING-PROOF?", "(DEFUN (EXECUTE-BACKWARD-CHAINING-PROOF? BOOLEAN) ((QUERY QUERY-ITERATOR)))", ((cpp_function_code)(&executeBackwardChainingProofP)), NULL);
    defineFunctionObject("EVALUATE-NEXT-MOVE", "(DEFUN (EVALUATE-NEXT-MOVE KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD) (CLOCKTICKS INTEGER)))", ((cpp_function_code)(&evaluateNextMove)), NULL);
    defineMethodObject("(DEFMETHOD (CLUSTERED-CONJUNCTION? BOOLEAN) ((SELF PROPOSITION)))", ((cpp_method_code)(&Proposition::clusteredConjunctionP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("CONTINUE-AND-PROOF", "(DEFUN (CONTINUE-AND-PROOF KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&continueAndProof)), NULL);
    defineFunctionObject("CONTINUE-OR-PROOF", "(DEFUN (CONTINUE-OR-PROOF KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&continueOrProof)), NULL);
    defineFunctionObject("CONTINUE-NOT-PROOF", "(DEFUN (CONTINUE-NOT-PROOF KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&continueNotProof)), NULL);
    defineFunctionObject("OVERLAY-WITH-FAIL-FRAME", "(DEFUN (OVERLAY-WITH-FAIL-FRAME KEYWORD) ((FRAME CONTROL-FRAME) (PROPOSITION PROPOSITION)))", ((cpp_function_code)(&overlayWithFailFrame)), NULL);
    defineFunctionObject("OVERLAY-WITH-STRATEGY-FRAME", "(DEFUN (OVERLAY-WITH-STRATEGY-FRAME KEYWORD) ((FRAME CONTROL-FRAME) (STRATEGY KEYWORD)))", ((cpp_function_code)(&overlayWithStrategyFrame)), NULL);
    defineFunctionObject("CHECK-FOR-DUPLICATE-GOAL?", "(DEFUN (CHECK-FOR-DUPLICATE-GOAL? BOOLEAN) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&checkForDuplicateGoalP)), NULL);
    defineFunctionObject("INITIATE-ATOMIC-GOAL-PROOFS", "(DEFUN (INITIATE-ATOMIC-GOAL-PROOFS KEYWORD) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&initiateAtomicGoalProofs)), NULL);
    defineFunctionObject("ALL-ARGUMENTS-BOUND?", "(DEFUN (ALL-ARGUMENTS-BOUND? BOOLEAN) ((GOAL PROPOSITION)))", ((cpp_function_code)(&allArgumentsBoundP)), NULL);
    defineFunctionObject("ALL-KEY-ARGUMENTS-BOUND?", "(DEFUN (ALL-KEY-ARGUMENTS-BOUND? BOOLEAN) ((GOAL PROPOSITION)))", ((cpp_function_code)(&allKeyArgumentsBoundP)), NULL);
    defineFunctionObject("CREATE-PATTERN-RECORD", "(DEFUN (CREATE-PATTERN-RECORD PATTERN-RECORD) ((FRAME CONTROL-FRAME) (DESCRIPTION DESCRIPTION) (EXTERNALARGUMENTS ARGUMENTS-VECTOR)))", ((cpp_function_code)(&createPatternRecord)), NULL);
    defineFunctionObject("TERMINATE-PATTERN-RECORD?", "(DEFUN (TERMINATE-PATTERN-RECORD? BOOLEAN) ((SELF PATTERN-RECORD)))", ((cpp_function_code)(&terminatePatternRecordP)), NULL);
    defineFunctionObject("COPY-PATTERN-ARGUMENTS", "(DEFUN (COPY-PATTERN-ARGUMENTS ARGUMENTS-VECTOR) ((ARGUMENTS OBJECT-VECTOR) (DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&copyPatternArguments)), NULL);
    defineFunctionObject("COMPUTE-EXTERNAL-BINDINGS", "(DEFUN (COMPUTE-EXTERNAL-BINDINGS CONS) ((EXTERNALARGUMENTS ARGUMENTS-VECTOR)))", ((cpp_function_code)(&computeExternalBindings)), NULL);
    defineFunctionObject("INSTANTIATE-EXTERNAL-BINDINGS", "(DEFUN (INSTANTIATE-EXTERNAL-BINDINGS OBJECT) ((SELF OBJECT)))", ((cpp_function_code)(&instantiateExternalBindings)), NULL);
    defineFunctionObject("INSTANTIATE-EXTERNAL-VARIABLES", "(DEFUN (INSTANTIATE-EXTERNAL-VARIABLES DESCRIPTION) ((SELF DESCRIPTION) (BINDINGS ENTITY-MAPPING)))", ((cpp_function_code)(&instantiateExternalVariables)), NULL);
    defineFunctionObject("CHECK-FOR-SINGLE-VALUED-GOAL?", "(DEFUN (CHECK-FOR-SINGLE-VALUED-GOAL? BOOLEAN) ((PATTERN DESCRIPTION) (IOBINDINGS CONS)))", ((cpp_function_code)(&checkForSingleValuedGoalP)), NULL);
    defineFunctionObject("OVERLAY-WITH-PATTERN-FRAME?", "(DEFUN (OVERLAY-WITH-PATTERN-FRAME? BOOLEAN) ((FRAME CONTROL-FRAME) (DESCRIPTION DESCRIPTION) (IOARGUMENTS ARGUMENTS-VECTOR)))", ((cpp_function_code)(&overlayWithPatternFrameP)), NULL);
    defineFunctionObject("TRANSFER-PATTERN-QUERY-BINDINGS?", "(DEFUN (TRANSFER-PATTERN-QUERY-BINDINGS? BOOLEAN) ((FRAME CONTROL-FRAME) (FUTUREBINDINGS? BOOLEAN)))", ((cpp_function_code)(&transferPatternQueryBindingsP)), NULL);
    defineFunctionObject("COLLECT-PATTERN-QUERY-BINDINGS", "(DEFUN COLLECT-PATTERN-QUERY-BINDINGS ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&collectPatternQueryBindings)), NULL);
    defineFunctionObject("GET-RULE-OF-ANTECEDENT-FRAME", "(DEFUN (GET-RULE-OF-ANTECEDENT-FRAME PROPOSITION) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&getRuleOfAntecedentFrame)), NULL);
    defineFunctionObject("CONTINUE-PATTERN-PROOF", "(DEFUN (CONTINUE-PATTERN-PROOF KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&continuePatternProof)), NULL);
    defineFunctionObject("DISJOINT-CLASSES?", "(DEFUN (DISJOINT-CLASSES? BOOLEAN) ((DESC1 NAMED-DESCRIPTION) (DESC2 NAMED-DESCRIPTION)) :PUBLIC? TRUE)", ((cpp_function_code)(&disjointClassesP)), NULL);
    defineFunctionObject("DISJOINT-TERMS?", "(DEFUN (DISJOINT-TERMS? BOOLEAN) ((D1 DESCRIPTION) (D2 DESCRIPTION)) :DOCUMENTATION \"Return TRUE if 'd1' and 'd2' belong to disjoint partitions.\" :PUBLIC? TRUE)", ((cpp_function_code)(&disjointTermsP)), NULL);
    defineFunctionObject("EXPENSIVE-DISJOINT-TERMS?", "(DEFUN (EXPENSIVE-DISJOINT-TERMS? BOOLEAN) ((D1 DESCRIPTION) (D2 DESCRIPTION)) :PUBLIC? TRUE)", ((cpp_function_code)(&expensiveDisjointTermsP)), NULL);
    defineFunctionObject("COLLECTIONOF-PROPOSITION?", "(DEFUN (COLLECTIONOF-PROPOSITION? BOOLEAN) ((DEFININGPROPOSITION PROPOSITION)))", ((cpp_function_code)(&collectionofPropositionP)), NULL);
    defineFunctionObject("MEMBER-OF-COLLECTION?", "(DEFUN (MEMBER-OF-COLLECTION? BOOLEAN) ((MEMBER OBJECT) (COLLECTION OBJECT)))", ((cpp_function_code)(&memberOfCollectionP)), NULL);
    defineFunctionObject("ASSERTED-COLLECTION-MEMBERS", "(DEFUN (ASSERTED-COLLECTION-MEMBERS LIST) ((SELF OBJECT) (DIRECT? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&assertedCollectionMembers)), NULL);
    defineFunctionObject("ALL-TRUE-EXTENSION-MEMBERS", "(DEFUN (ALL-TRUE-EXTENSION-MEMBERS DESCRIPTION-EXTENSION-ITERATOR) ((SELF NAMED-DESCRIPTION) (SPECIALIZE? BOOLEAN)))", ((cpp_function_code)(&allTrueExtensionMembers)), NULL);
    defineFunctionObject("ALL-MATCHING-EXTENSION-MEMBERS", "(DEFUN (ALL-MATCHING-EXTENSION-MEMBERS (ITERATOR OF PROPOSITION)) ((SELF PROPOSITION) (SPECIALIZE? BOOLEAN)))", ((cpp_function_code)(&allMatchingExtensionMembers)), NULL);
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF DESCRIPTION-EXTENSION-ITERATOR)))", ((cpp_method_code)(&DescriptionExtensionIterator::nextP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("HELP-FIND-DUPLICATED-GOAL", "(DEFUN (HELP-FIND-DUPLICATED-GOAL CONTROL-FRAME CONTROL-FRAME INTEGER) ((GOALFRAME CONTROL-FRAME)))", ((cpp_function_code)(&helpFindDuplicatedGoal)), NULL);
    defineFunctionObject("FIND-DUPLICATED-GOAL", "(DEFUN (FIND-DUPLICATED-GOAL CONTROL-FRAME CONTROL-FRAME INTEGER) ((FRAME CONTROL-FRAME)))", ((cpp_function_code)(&findDuplicatedGoal)), NULL);
    defineFunctionObject("HANDLE-DEPTH-VIOLATION", "(DEFUN (HANDLE-DEPTH-VIOLATION CONTROL-FRAME INTEGER) ((FRAME CONTROL-FRAME) (DEPTH INTEGER)))", ((cpp_function_code)(&handleDepthViolation)), NULL);
    defineFunctionObject("HANDLE-TIMEOUT", "(DEFUN (HANDLE-TIMEOUT CONTROL-FRAME INTEGER) ((FRAME CONTROL-FRAME) (DEPTH INTEGER)))", ((cpp_function_code)(&handleTimeout)), NULL);
    defineMethodObject("(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF QUERY-SOLUTION-TABLE) (KEY (LIKE (ANY-KEY SELF)))) :DOCUMENTATION \"Lookup the solution identified by `key' in `self' and\nreturn its value, or NULL if no such solution exists.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::lookup)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD INSERT-AT ((SELF QUERY-SOLUTION-TABLE) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Insert `value' identified by `key' into `self'.  If a solution\nwith that key already exists, destructively modify it with the slot values of\n`value'.  This is necessary to preserve the order of solutions in `self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::insertAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DELETED? BOOLEAN) ((SELF QUERY-SOLUTION)))", ((cpp_method_code)(&QuerySolution::deletedP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DELETED?-SETTER BOOLEAN) ((SELF QUERY-SOLUTION) (VALUE BOOLEAN)))", ((cpp_method_code)(&QuerySolution::deletedPSetter)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD REMOVE-AT ((SELF QUERY-SOLUTION-TABLE) (KEY (LIKE (ANY-KEY SELF)))) :DOCUMENTATION \"Remove the solution identified by `key' from `self'.\nTo preserve the solution ordering chain, the solution is marked as deleted\nand will be completely removed upon the next iteration through `self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::removeAt)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (POP (LIKE (ANY-VALUE SELF))) ((SELF QUERY-SOLUTION-TABLE)) :DOCUMENTATION \"Remove and return the first solution of `self' or NULL\nif the table is empty.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::pop)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LENGTH INTEGER) ((SELF QUERY-SOLUTION-TABLE)) :DOCUMENTATION \"Return the number of entries in `self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::length)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (EMPTY? BOOLEAN) ((SELF QUERY-SOLUTION-TABLE)) :DOCUMENTATION \"Return TRUE if `self' has zero entries.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::emptyP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF QUERY-SOLUTION-TABLE)) :DOCUMENTATION \"Return TRUE if `self' has at least 1 entry.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::nonEmptyP)), ((cpp_method_code)(NULL)));
  }
}

void helpStartupQuery10() {
  {
    defineMethodObject("(DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ((SELF QUERY-SOLUTION-TABLE) (POSITION INTEGER)) :DOCUMENTATION \"Return the nth solution in `self', or NULL if it is empty.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::nth)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD CLEAR ((SELF QUERY-SOLUTION-TABLE)))", ((cpp_method_code)(&QuerySolutionTable::clear)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (CONSIFY CONS) ((SELF QUERY-SOLUTION-TABLE)) :DOCUMENTATION \"Collect all solutions of `self' into a cons list and return the result.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::consify)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (SORT (LIKE SELF)) ((SELF QUERY-SOLUTION-TABLE) (PREDICATE FUNCTION-CODE)) :DOCUMENTATION \"Perform a stable, destructive sort of `self' according to\n`predicate', and return the result.  If `predicate' has a '<' semantics, the\nresult will be in ascending order.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QuerySolutionTable::sort)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (ALLOCATE-ITERATOR DICTIONARY-ITERATOR) ((SELF QUERY-SOLUTION-TABLE)))", ((cpp_method_code)(&QuerySolutionTable::allocateIterator)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF QUERY-SOLUTION-TABLE-ITERATOR)))", ((cpp_method_code)(&QuerySolutionTableIterator::nextP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("PRINT-CONTROL-FRAME", "(DEFUN PRINT-CONTROL-FRAME ((SELF CONTROL-FRAME) (STREAM NATIVE-OUTPUT-STREAM)))", ((cpp_function_code)(&printControlFrame)), NULL);
    defineFunctionObject("PRINT-GOAL-STACK", "(DEFUN PRINT-GOAL-STACK ((FRAME CONTROL-FRAME) (VERBOSE? BOOLEAN)) :DOCUMENTATION \"Print stack of goals.  Assumes that query has been interrupted\nwith a full stack of control frames.\")", ((cpp_function_code)(&printGoalStack)), NULL);
    defineFunctionObject("PGS", "(DEFUN PGS ())", ((cpp_function_code)(&pgs)), NULL);
    defineFunctionObject("VPGS", "(DEFUN VPGS ())", ((cpp_function_code)(&vpgs)), NULL);
    defineFunctionObject("PRINT-QUERY-ITERATOR", "(DEFUN PRINT-QUERY-ITERATOR ((SELF QUERY-ITERATOR) (STREAM NATIVE-OUTPUT-STREAM)))", ((cpp_function_code)(&printQueryIterator)), NULL);
    defineFunctionObject("PRINT-QUERY-ITERATOR-ORNATELY", "(DEFUN PRINT-QUERY-ITERATOR-ORNATELY ((SELF QUERY-ITERATOR) (STREAM NATIVE-OUTPUT-STREAM)))", ((cpp_function_code)(&printQueryIteratorOrnately)), NULL);
    defineFunctionObject("PRINT-QUERY-ITERATOR-SOLUTION-ORNATELY", "(DEFUN PRINT-QUERY-ITERATOR-SOLUTION-ORNATELY ((SELF QUERY-ITERATOR) (SOLUTION QUERY-SOLUTION) (SOLUTIONNUMBER INTEGER) (STREAM NATIVE-OUTPUT-STREAM)))", ((cpp_function_code)(&printQueryIteratorSolutionOrnately)), NULL);
    defineFunctionObject("TRACE-SOLUTION", "(DEFUN TRACE-SOLUTION ((SELF QUERY-ITERATOR) (SOLUTION QUERY-SOLUTION) (SOLUTIONNUMBER INTEGER)))", ((cpp_function_code)(&traceSolution)), NULL);
    defineFunctionObject("PRINT-QUERY-ITERATOR-READABLY", "(DEFUN PRINT-QUERY-ITERATOR-READABLY ((SELF QUERY-ITERATOR) (STREAM NATIVE-OUTPUT-STREAM)))", ((cpp_function_code)(&printQueryIteratorReadably)), NULL);
    defineFunctionObject("ALLOCATE-QUERY-ITERATOR", "(DEFUN (ALLOCATE-QUERY-ITERATOR QUERY-ITERATOR) ())", ((cpp_function_code)(&allocateQueryIterator)), NULL);
    defineMethodObject("(DEFMETHOD FREE ((SELF QUERY-ITERATOR)))", ((cpp_method_code)(&QueryIterator::free)), ((cpp_method_code)(NULL)));
    defineFunctionObject("FREE-QUERY-ITERATOR", "(DEFUN FREE-QUERY-ITERATOR ((SELF QUERY-ITERATOR)))", ((cpp_function_code)(&freeQueryIterator)), NULL);
    defineFunctionObject("ALLOCATE-COLLECTION-VARIABLES", "(DEFUN (ALLOCATE-COLLECTION-VARIABLES VARIABLES-VECTOR) ((FRAME CONTROL-FRAME) (DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&allocateCollectionVariables)), NULL);
    defineFunctionObject("CREATE-QUERY-ITERATOR", "(DEFUN (CREATE-QUERY-ITERATOR QUERY-ITERATOR) ((DESCRIPTION DESCRIPTION) (OUTSIDEBINDINGS VECTOR)))", ((cpp_function_code)(&createQueryIterator)), NULL);
    defineFunctionObject("INITIALIZE-QUERY-ITERATOR", "(DEFUN (INITIALIZE-QUERY-ITERATOR QUERY-ITERATOR) ((QUERYITERATOR QUERY-ITERATOR) (DESCRIPTION DESCRIPTION) (OUTSIDEBINDINGS VECTOR)))", ((cpp_function_code)(&initializeQueryIterator)), NULL);
    defineMethodObject("(DEFMETHOD (QUERY-PROPOSITION PROPOSITION) ((SELF QUERY-ITERATOR)))", ((cpp_method_code)(&QueryIterator::queryProposition)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (QUERY-DESCRIPTION DESCRIPTION) ((SELF QUERY-ITERATOR)))", ((cpp_method_code)(&QueryIterator::queryDescription)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (QUERY-IS-TRUE-FALSE? BOOLEAN) ((SELF QUERY-ITERATOR)))", ((cpp_method_code)(&QueryIterator::queryIsTrueFalseP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (QUERY-IS-PARTIAL? BOOLEAN) ((SELF QUERY-ITERATOR)))", ((cpp_method_code)(&QueryIterator::queryIsPartialP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (QUERY-SUCCEEDED? BOOLEAN) ((SELF QUERY-ITERATOR)))", ((cpp_method_code)(&QueryIterator::querySucceededP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF QUERY-ITERATOR)))", ((cpp_method_code)(&QueryIterator::nextP)), ((cpp_method_code)(NULL)));
    defineFunctionObject("TRY-TO-DEFEAT-LAST-ANSWER?", "(DEFUN (TRY-TO-DEFEAT-LAST-ANSWER? BOOLEAN) ((SELF QUERY-ITERATOR)))", ((cpp_function_code)(&tryToDefeatLastAnswerP)), NULL);
    defineMethodObject("(DEFMETHOD RESET ((SELF QUERY-ITERATOR)))", ((cpp_method_code)(&QueryIterator::reset)), ((cpp_method_code)(NULL)));
    defineFunctionObject("STANDARDIZE-QUERY-TREE", "(DEFUN (STANDARDIZE-QUERY-TREE CONS) ((IOVARIABLES OBJECT) (QUERYBODY OBJECT) (EXTERNALVARIABLES CONS)))", ((cpp_function_code)(&standardizeQueryTree)), NULL);
    defineFunctionObject("MAKE-QUERY", "(DEFUN (MAKE-QUERY QUERY-ITERATOR) ((IOVARIABLES OBJECT) (QUERYTREE OBJECT) (EXTERNALBINDINGS CONS) (OPTIONS OBJECT)))", ((cpp_function_code)(&makeQuery)), NULL);
    defineFunctionObject("PARSE-QUERY-AND-OPTIONS", "(DEFUN (PARSE-QUERY-AND-OPTIONS OBJECT OBJECT PROPERTY-LIST) ((|QUERY&OPTIONS| CONS)))", ((cpp_function_code)(&parseQueryAndOptions)), NULL);
    defineFunctionObject("PROCESS-QUERY-OPTIONS", "(DEFUN PROCESS-QUERY-OPTIONS ((QUERY QUERY-ITERATOR) (OPTIONS OBJECT)))", ((cpp_function_code)(&processQueryOptions)), NULL);
    defineFunctionObject("LOOKUP-QUERY-OPTION", "(DEFUN (LOOKUP-QUERY-OPTION OBJECT) ((QUERYOROPTIONS OBJECT) (KEY KEYWORD)))", ((cpp_function_code)(&lookupQueryOption)), NULL);
    defineFunctionObject("TEST-QUERY-OPTION?", "(DEFUN (TEST-QUERY-OPTION? BOOLEAN) ((QUERYOROPTIONS OBJECT) (KEY KEYWORD)))", ((cpp_function_code)(&testQueryOptionP)), NULL);
    defineFunctionObject("LOOKUP-DEFERRED-QUERY-OPTION", "(DEFUN (LOOKUP-DEFERRED-QUERY-OPTION OBJECT) ((QUERYOROPTIONS OBJECT) (KEY KEYWORD) (COERCETOTYPE TYPE)))", ((cpp_function_code)(&lookupDeferredQueryOption)), NULL);
    defineFunctionObject("LOOKUP-HOW-MANY-SOLUTIONS", "(DEFUN (LOOKUP-HOW-MANY-SOLUTIONS INTEGER) ((QUERYOROPTIONS OBJECT)))", ((cpp_function_code)(&lookupHowManySolutions)), NULL);
    defineFunctionObject("RUN-YES-OR-NO-QUERY?", "(DEFUN (RUN-YES-OR-NO-QUERY? THREE-VALUED-BOOLEAN) ((QUERY QUERY-ITERATOR)))", ((cpp_function_code)(&runYesOrNoQueryP)), NULL);
    defineFunctionObject("COERCE-TO-TREE", "(DEFUN (COERCE-TO-TREE OBJECT) ((SELF OBJECT)))", ((cpp_function_code)(&coerceToTree)), NULL);
    defineFunctionObject("COERCE-TO-STRING", "(DEFUN (COERCE-TO-STRING STRING) ((SELF OBJECT)))", ((cpp_function_code)(&coerceToString)), NULL);
    defineFunctionObject("CREATE-ASK-QUERY", "(DEFUN (CREATE-ASK-QUERY QUERY-ITERATOR) ((QUERY OBJECT)))", ((cpp_function_code)(&createAskQuery)), NULL);
    defineFunctionObject("CALL-ASK", "(DEFUN (CALL-ASK TRUTH-VALUE) ((QUERY OBJECT)) :DOCUMENTATION \"Callable version of `ask' (which see).  Accepts queries\nspecified by a query iterator, or specified as a CONS-list of arguments as they\nwould be supplied to `ask'.  Raises LOGIC-EXCEPTIONs in case of illegal\nqueries and logical expressions.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callAsk)), NULL);
    defineFunctionObject("ASK", "(DEFUN (ASK TRUTH-VALUE) (|&REST| (|PROPOSITION&OPTIONS| PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Perform inference to determine whether the proposition specified in\n`proposition&options' is true.  Return the truth-value found.  `ask'\nwill spend most of its effort to determine whether the proposition\nis true and only a little effort via shallow inference strategies to\ndetermine whether it is false.  To find out whether a proposition is\nfalse with full inference effort `ask' its negation.\n\nKIF example: `(ask (happy Fred))' will return TRUE if Fred was indeed\nfound to be happy.  Note, that for this query to run, the logic\nconstant `Fred' and the relation `happy' must already be defined (see\n`assert').  Use `(set/unset-feature goal-trace)' to en/disable goal\ntracing of the inference engine.\n\nThe `ask' command supports the following options: `:TIMEOUT' is an\ninteger or floating point time limit, specified in seconds.  For\nexample, the command `(ask (ner" "vous Fred) :timeout 2.0)' will cease\ninference after two seconds if a proof has not been found by then.\nIf the `:DONT-OPTIMIZE?' is given as TRUE, it tells PowerLoom to\nnot optimize the order of clauses in the query before evaluating it.\nThis is useful for cases where a specific evaluation order of the\nclauses is required (or the optimizer doesn't do the right thing).\nIf `:THREE-VALUED?' is given as TRUE, PowerLoom will try to prove\nthe negation of the query with full effort in case the given query\nreturned UNKNOWN.  By default, PowerLoom uses full effort to prove\nthe query as stated and only a little opportunistic effort to see\nwhether it is actually false.\")", ((cpp_function_code)(&ask)), ((cpp_function_code)(&askEvaluatorWrapper)));
    defineFunctionObject("RETRIEVE-BINDINGS", "(DEFUN (RETRIEVE-BINDINGS QUERY-ITERATOR) ((QUERY OBJECT) (NOFBINDINGS INTEGER)))", ((cpp_function_code)(&retrieveBindings)), NULL);
    defineFunctionObject("CREATE-RETRIEVE-QUERY", "(DEFUN (CREATE-RETRIEVE-QUERY QUERY-ITERATOR) ((QUERY OBJECT)))", ((cpp_function_code)(&createRetrieveQuery)), NULL);
    defineFunctionObject("CALL-RETRIEVE", "(DEFUN (CALL-RETRIEVE QUERY-ITERATOR) ((QUERY OBJECT)) :DOCUMENTATION \"Callable version of `retrieve' (which see).  Accepts queries\nspecified by a query iterator, or specified as a CONS-list of arguments as they\nwould be supplied to `retrieve'.  Raises LOGIC-EXCEPTIONs in case of illegal\nqueries and logical expressions.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callRetrieve)), NULL);
    defineFunctionObject("RETRIEVE", "(DEFUN (RETRIEVE QUERY-ITERATOR) (|&REST| (QUERY PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Retrieve elements of a relation (tuples) that satisfy a proposition.\nThe accepted syntax is:\n	 \n  (retrieve [<integer> | all]\n            [[{<vardecl> | (<vardecl>+)}]\n            <proposition>])\n	\nThe variables and proposition are similar to an `exists' sentence or\n`kappa' term without the explicit quantifier.  If variables are declared,\nthey must match the free variables referenced by <proposition>.  Otherwise,\nthe free variables referenced in <proposition> will be used as the query\nvariables.  If <proposition> is omitted, the most recently asked query\nwill be continued.\n\nA solution is a set of bindings for the listed variables for which\n<proposition> is true.  The optional first argument controls how many\nsolutions should be generated before control is returned.  The keyword\n`all' indicates that all solutions should be generated.  By default,\n`retrieve' r" "eturns after it has found one new solution or if it cannot\nfind any more solutions.\n\n`retrieve' returns an iterator which saves all the necessary state of\na query and stores all generated solutions.  When used interactively,\nthe returned iterator will print out with the set of solutions collected\nso far.  Calling `retrieve' without any arguments (or only with the first\nargument) will generate one (or more) solutions to the most recently\nasked query.\n\nKIF examples:\n	 \n  (retrieve (happy ?x))\n	\nwill try to find one happy entity and store it in the returned \nquery iterator.\n	 \n  (retrieve 10 (happy ?x))\n	\nwill try to find 10 happy entities.\n	 \n  (retrieve 10)\n	\nwill try to find the next 10 happy entities..\n	 \n  (retrieve all (happy ?x))\n	\nwill find all happy entities.\n	 \n  (retrieve all (?x Person) (happy ?x))\n	\nwill to find all happy people.  Here we used the optional retrieve variable\nsyntax to restrict the acceptable solutions.  The above is equivalent to\nthe following query:" "\n	 \n  (retrieve all (and (Person ?x) (happy ?x)))\n	\nSimilarly,\n	 \n  (retrieve all (?x Person))\n  (retrieve all (Person ?x))\n  (retrieve all ?x (Person ?x))\n	\nwill find all people.  Note that in the first case we only specify a query\nvariable and its type but omit the logic sentence which defaults to TRUE.  This\nsomewhat impoverished looking query can be paraphrased as \\\"retrieve all ?x of\ntype Person such that TRUE.\\\"\n	 \n  (retrieve ?x (or (happy ?x) (parent-of Fred ?x)))\n	\nwill try to find a person that is happy or has Fred as a parent.\n	 \n  (retrieve (?y ?x) (parent-of ?x ?y))\n	\nwill try to find the one pair of parent/child and return it in the order\nof child/parent.\n	 \n  (retrieve all (?x Person)\n            (exists (?y Person) (parent-of ?x ?y)))\n	\nwill generate the set of all parents.  Note, that for these queries to run,\nthe class `Person', the relations `happy' and `parent-of', and the logic\nconstant `Fred' must already be defined (see `assert').\n\nUse `(set/unset-fea" "ture trace-subgoals)' to en/disable goal tracing of the\ninference engine.\")", ((cpp_function_code)(&retrieve)), ((cpp_function_code)(&retrieveEvaluatorWrapper)));
    defineMethodObject("(DEFMETHOD (CONSIFY-CURRENT-SOLUTIONS CONS) ((SELF QUERY-ITERATOR)) :DOCUMENTATION \"Collect the current solutions of `self' into a cons list\nof result tuples.  If `:SINGLETONS? TRUE', collect a list of atoms rather than a\nlist of lists for tuples of arity=1.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QueryIterator::consifyCurrentSolutions)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (CONSIFY CONS) ((SELF QUERY-ITERATOR)) :DOCUMENTATION \"Generate all solutions for the query self, and collect them into a cons list\nof result tuples.  If `:SINGLETONS? TRUE', collect a list of atoms rather than a\nlist of lists for tuples of arity=1.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QueryIterator::consify)), ((cpp_method_code)(NULL)));
    defineFunctionObject("CONSIFY-QUERY", "(DEFUN (CONSIFY-QUERY CONS) ((SELF QUERY-ITERATOR)) :GLOBALLY-INLINE? TRUE (RETURN (CONSIFY SELF)))", ((cpp_function_code)(&consifyQuery)), NULL);
    defineMethodObject("(DEFMETHOD (LISTIFY LIST) ((SELF QUERY-ITERATOR)) :DOCUMENTATION \"Just like `QUERY-ITERATOR.consify' but return a LIST instead.\" :PUBLIC? TRUE)", ((cpp_method_code)(&QueryIterator::listify)), ((cpp_method_code)(NULL)));
    defineFunctionObject("FLUSH-INLINE-QUERY-CACHES", "(DEFUN FLUSH-INLINE-QUERY-CACHES ())", ((cpp_function_code)(&flushInlineQueryCaches)), NULL);
    defineFunctionObject("MAKE-CACHED-QUERY", "(DEFUN (MAKE-CACHED-QUERY QUERY-ITERATOR) ((VARIABLES CONS) (QUERYBODY CONS) (INPUTBINDINGS CONS) (OPTIONS OBJECT) (CACHEID SYMBOL)) :PUBLIC? TRUE)", ((cpp_function_code)(&makeCachedQuery)), NULL);
    defineFunctionObject("APPLY-CACHED-RETRIEVE", "(DEFUN (APPLY-CACHED-RETRIEVE CONS CONS) ((VARIABLES CONS) (QUERYBODY CONS) (INPUTBINDINGS CONS) (OPTIONS OBJECT) (CACHEID SYMBOL)) :PUBLIC? TRUE)", ((cpp_function_code)(&applyCachedRetrieve)), NULL);
    defineFunctionObject("APPLY-CACHED-ASK", "(DEFUN (APPLY-CACHED-ASK BOOLEAN TRUTH-VALUE) ((INPUTVARIABLES CONS) (QUERYBODY CONS) (INPUTBINDINGS CONS) (OPTIONS OBJECT) (CACHEID SYMBOL)) :PUBLIC? TRUE)", ((cpp_function_code)(&applyCachedAsk)), NULL);
    defineFunctionObject("GET-PROTOTYPE", "(DEFUN (GET-PROTOTYPE LOGIC-OBJECT) ((DESCRIPTION DESCRIPTION)) :PUBLIC? TRUE)", ((cpp_function_code)(&getPrototype)), NULL);
    defineFunctionObject("UNARY-DESCRIPTION-SPECIALIZES-DESCRIPTION?", "(DEFUN (UNARY-DESCRIPTION-SPECIALIZES-DESCRIPTION? TRUTH-VALUE) ((SUB DESCRIPTION) (SUPER DESCRIPTION)))", ((cpp_function_code)(&unaryDescriptionSpecializesDescriptionP)), NULL);
    defineFunctionObject("DESCRIPTION-SPECIALIZES-DESCRIPTION?", "(DEFUN (DESCRIPTION-SPECIALIZES-DESCRIPTION? TRUTH-VALUE) ((SUB DESCRIPTION) (SUPER DESCRIPTION)) :PUBLIC? TRUE)", ((cpp_function_code)(&descriptionSpecializesDescriptionP)), NULL);
    defineFunctionObject("VECTOR-SATISFIES-DESCRIPTION?", "(DEFUN (VECTOR-SATISFIES-DESCRIPTION? TRUTH-VALUE) ((VECTOR VECTOR) (DESCRIPTION DESCRIPTION)) :PUBLIC? TRUE)", ((cpp_function_code)(&vectorSatisfiesDescriptionP)), NULL);
    defineFunctionObject("INSTANCE-SATISFIES-DESCRIPTION?", "(DEFUN (INSTANCE-SATISFIES-DESCRIPTION? TRUTH-VALUE) ((INSTANCE OBJECT) (DESCRIPTION DESCRIPTION)) :PUBLIC? TRUE)", ((cpp_function_code)(&instanceSatisfiesDescriptionP)), NULL);
  }
}

void startupQuery() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupQuery1();
      helpStartupQuery2();
      helpStartupQuery3();
      helpStartupQuery4();
      helpStartupQuery5();
    }
    if (currentStartupTimePhaseP(4)) {
      helpStartupQuery6();
    }
    if (currentStartupTimePhaseP(5)) {
      helpStartupQuery7();
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupQuery8();
      helpStartupQuery9();
      helpStartupQuery10();
      defineFunctionObject("COERCE-TO-DESCRIPTION", "(DEFUN (COERCE-TO-DESCRIPTION DESCRIPTION) ((SELF OBJECT) (ORIGINAL OBJECT)))", ((cpp_function_code)(&coerceToDescription)), NULL);
      defineFunctionObject("SPECIALIZES?", "(DEFUN (SPECIALIZES? TRUTH-VALUE) ((SUBOBJECT OBJECT) (SUPEROBJECT OBJECT)) :DOCUMENTATION \"Try to prove if the description associated with `subObject'\nspecializes the description for `superObject' and return the result truth\nvalue of the query.\" :PUBLIC? TRUE)", ((cpp_function_code)(&specializesP)), NULL);
      defineFunctionObject("COERCE-TO-INSTANCE", "(DEFUN (COERCE-TO-INSTANCE LOGIC-OBJECT) ((SELF OBJECT) (ORIGINAL OBJECT)) :DOCUMENTATION \"Return the logic instance referred to by 'self'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&coerceToInstance)), NULL);
      defineFunctionObject("COERCE-TO-INSTANCE-OR-LITERAL", "(DEFUN (COERCE-TO-INSTANCE-OR-LITERAL OBJECT) ((SELF OBJECT) (ORIGINAL OBJECT)) :DOCUMENTATION \"Return the logic instance referred to by `self', or `self' if it is a\nliteral (e.g., string or number) that can't be coerced.\" :PUBLIC? TRUE)", ((cpp_function_code)(&coerceToInstanceOrLiteral)), NULL);
      defineFunctionObject("COERCE-TO-VECTOR", "(DEFUN (COERCE-TO-VECTOR VECTOR) ((SELF OBJECT)) :DOCUMENTATION \"Return a vector containing the elements in `self'.\nCoerce each element of `self' to be a logic object or literal.\" :PUBLIC? TRUE)", ((cpp_function_code)(&coerceToVector)), NULL);
      defineFunctionObject("SATISFIES?", "(DEFUN (SATISFIES? TRUTH-VALUE) ((INSTANCEORTUPLE OBJECT) (RELATIONREF OBJECT)) :DOCUMENTATION \"Try to prove whether `instanceOrTuple' satisfies the\ndefinition of the relation `relationRef' and return the result truth value\nof the query.  `instanceOrTuple' can be a single object, the name or surrogate\nof an object, or a collection (a list or vector) of objects.  `relationRef'\ncan be a relation, description, surrogate or relation name.\" :PUBLIC? TRUE)", ((cpp_function_code)(&satisfiesP)), NULL);
      defineFunctionObject("APPLY-KAPPA?", "(DEFUN (APPLY-KAPPA? BOOLEAN) ((DESCRIPTION DESCRIPTION) (VECTOR VECTOR)) :PUBLIC? TRUE :DOCUMENTATION \"Apply (inherit) the description 'description'\nto members of the vector 'vector'.  Return TRUE if no clash was detected.\nConstraint propagation happens only if it is enabled prior to calling\n'apply-kappa?'.\")", ((cpp_function_code)(&applyKappaP)), NULL);
      defineFunctionObject("UPDATE-PROPOSITIONS-FROM-QUERY", "(DEFUN (UPDATE-PROPOSITIONS-FROM-QUERY (CONS OF PROPOSITION)) ((QUERY QUERY-ITERATOR) (DESCRIPTION DESCRIPTION) (MODULE MODULE) (UPDATEMODE KEYWORD)))", ((cpp_function_code)(&updatePropositionsFromQuery)), NULL);
      defineFunctionObject("GET-QUERY-ITERATOR-FROM-COMMAND", "(DEFUN (GET-QUERY-ITERATOR-FROM-COMMAND QUERY-ITERATOR) ((QUERY CONS)))", ((cpp_function_code)(&getQueryIteratorFromCommand)), NULL);
      defineFunctionObject("ASSERT-FROM-QUERY", "(DEFUN (ASSERT-FROM-QUERY (CONS OF PROPOSITION)) ((QUERY CONS) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Evaluate `query', instantiate the query proposition for each generated\nsolution and assert the resulting propositions.  The accepted syntax\nis as follows:\n	 \n (assert-from-query <query-command>\n                    [:relation <relation-name>]\n                    [:pattern <description-term>]\n                    [:module <module-name>])\n	\n<query-command> has to be a strict or partial retrieval command. If a\n:relation option is supplied, <relation-name> is used as the relation\nof the resulting propositions.  In this case the bindings of each\nsolution will become arguments to the specified relation in the order\nof `query's output variables (the arities have to match).  The\n:pattern option is a generalization of this mechanism that specifies\nan arbitrary proposition pattern to be instantiated by the query's\nsolution.  In this case <description-term> has to be a SETOFALL or\nKAPPA expression wh" "ose IO-variables will be bound in sequence to the\nbindings of a query solution to generate the resulting proposition.\nFinally, if a :module option is specified, the assertions will be\ngenerated in that module.  Note that for this to work the relations\nreferenced in the query proposition or pattern have to be visible in\nthe module.  Also, instances will not be copied to the target module,\ntherefore, the resulting propositions might reference external\nout-of-module objects in case they are not visible there.\nHere are some examples:\n	 \n (assert-from-query (retrieve all (foo ?x ?y)))\n (assert-from-query (retrieve all (?y ?x)\n                             (exists ?z\n                               (and (foo ?x ?z)\n                                    (foo ?z ?y))))\n                    :relation bar :module other)\n (assert-from-query\n   (retrieve all (and (relation ?x) (symmetric ?x)))\n   :pattern (kappa (?pred)\n              (forall (?x ?y)\n                (=> (holds ?pred ?x ?y)\n               " "     (holds ?pred ?y ?x))))))\n	\n\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", ((cpp_function_code)(&assertFromQuery)), ((cpp_function_code)(&assertFromQueryEvaluatorWrapper)));
      defineFunctionObject("RETRACT-FROM-QUERY", "(DEFUN (RETRACT-FROM-QUERY (CONS OF PROPOSITION)) ((QUERY CONS) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Evaluate `query' which has to be a strict or partial retrieval\ncommand, instantiate the query proposition for each generated solution\nand retract the resulting propositions.  See `assert-from-query' for\navailable command options.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", ((cpp_function_code)(&retractFromQuery)), ((cpp_function_code)(&retractFromQueryEvaluatorWrapper)));
      defineFunctionObject("DISPLAY-SETTINGS", "(DEFUN (DISPLAY-SETTINGS STRING) ())", ((cpp_function_code)(&displaySettings)), NULL);
      defineFunctionObject("STARTUP-QUERY", "(DEFUN STARTUP-QUERY () :PUBLIC? TRUE)", ((cpp_function_code)(&startupQuery)), NULL);
      { MethodSlot* function = lookupFunction(SYM_QUERY_LOGIC_STARTUP_QUERY);

        setDynamicSlotValue(function->dynamicSlots, SYM_QUERY_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupQuery"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL NORMAL-INFERENCE NORMAL-INFERENCE-LEVEL (NEW NORMAL-INFERENCE-LEVEL :KEYWORD :NORMAL))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL BACKTRACKING-INFERENCE BACKTRACKING-INFERENCE-LEVEL (NEW BACKTRACKING-INFERENCE-LEVEL :KEYWORD :BACKTRACKING))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL SUBSUMPTION-INFERENCE SUBSUMPTION-INFERENCE-LEVEL (NEW SUBSUMPTION-INFERENCE-LEVEL :KEYWORD :SUBSUMPTION))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL SHALLOW-INFERENCE SHALLOW-INFERENCE-LEVEL (NEW SHALLOW-INFERENCE-LEVEL :KEYWORD :SHALLOW))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL ASSERTION-INFERENCE ASSERTION-INFERENCE-LEVEL (NEW ASSERTION-INFERENCE-LEVEL :KEYWORD :ASSERTION))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL REFUTATION-INFERENCE REFUTATION-INFERENCE-LEVEL (NEW REFUTATION-INFERENCE-LEVEL :KEYWORD :REFUTATION))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *INFERENCELEVEL* NORMAL-INFERENCE-LEVEL NORMAL-INFERENCE :DOCUMENTATION \"Specifies the level/depth of inference applied\nduring a query.  Possible values are:\n  :ASSERTION -- database lookup with no inheritance;\n  :SHALLOW -- includes database lookup, computed predicates and specialists;\n  :SUBSUMPTION -- shallow plus cached subsumption links and equality reasoning;\n  :BACKTRACKING -- all of the above plus backtracking over rules;\n  :NORMAL -- all of the above plus universal introduction;\n  :REFUTATION -- all of the above plus disjunctive implication introduction and refutation.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DONTUSEDEFAULTKNOWLEDGE?* BOOLEAN FALSE :DOCUMENTATION \"Controls whether queries use default knowledge or not.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *MAXIMUM-BACKTRACKING-DEPTH* INTEGER *DEFAULT-MAXIMUM-DEPTH* :DOCUMENTATION \"Value for the maximum depth allowable during\nbacktrack search.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *TYPE-CHECK-STRATEGY* KEYWORD :LOOKUP :DOCUMENTATION \"Determines whether there is a slow but thorough type test\nwhen variables are bound, a fast but very shallow one, or none.  Values\nare :NONE, :LOOKUP, :DISJOINT.  The default is :LOOKUP.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DUPLICATE-SUBGOAL-STRATEGY* KEYWORD :DUPLICATE-GOALS :DOCUMENTATION \"Determines what kind of duplicate subgoal test to use.  Choices\nare :DUPLICATE-RULES, :DUPLICATE-GOALS, and :DUPLICATE-GOALS-WITH-CACHING.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DUPLICATE-GOAL-SEARCH-DEPTH* INTEGER NULL :DOCUMENTATION \"Sets the maximum number of frames search looking for\na duplicate subgoal.  Default value is infinite.  Possibly this should\nbe replaced by a function that increases with depth of search.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DUPLICATE-RULE-SEARCH-DEPTH* INTEGER NULL :DOCUMENTATION \"Set limit on number of frames searched looking for\na duplicate rule.  Default value is infinite.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *GLOBALLY-CLOSED-COLLECTIONS?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, all collections are assumed to be closed.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *GENERATE-ALL-PROOFS?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, the backchainer follows all lines of proof\nfor each goal, rather than switching to a new goal once the first proof\nof a goal is achieved.  The partial matcher sets this variable to\nTRUE to force generation of proofs having possibly different\nweights.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *QUERYITERATOR* QUERY-ITERATOR NULL :DOCUMENTATION \"Points to the query iterator for the currently executing query.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DEFAULT-MAXIMUM-DEPTH* INTEGER 25 :DOCUMENTATION \"Possibly a good value for the maximum backtracking depth.\nMore testing is needed.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *INITIAL-BACKTRACKING-DEPTH* INTEGER 5 :DOCUMENTATION \"Value of the initial depth used during an interative\ndeepening search.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *ITERATIVE-DEEPENING-MODE?* BOOLEAN FALSE :DOCUMENTATION \"Default setting.  If TRUE, queries are evaluated\nusing iterative deepening from depth '*initial-backtracking-depth*'\nto depth '*maximum-backtracking-depth*'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *EMIT-THINKING-DOTS?* BOOLEAN TRUE :DOCUMENTATION \"When TRUE, various kinds of characters are\nemitted to STANDARD-OUTPUT while PowerLoom is 'thinking'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *THINKING-DOT-COUNTER* INTEGER 0 :DOCUMENTATION \"Used to determine when to generate linefeeds\nafter forty-or-so thinking dots.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *THINKING-DOT-TABLE* (PROPERTY-LIST OF KEYWORD CHARACTER-WRAPPER) (NEW PROPERTY-LIST :THE-PLIST (BQUOTE (:UPCLASSIFY |&| (WRAP-LITERAL #\\u) :DOWNCLASSIFY |&| (WRAP-LITERAL #\\d) :PROPAGATE |&| (WRAP-LITERAL #\\f) :PARTIAL-MATCH |&| (WRAP-LITERAL #\\p)))) :DOCUMENTATION \"Maps kind of thinking keywords to characters.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *BOOLEAN-VECTOR-INDEX* BOOLEAN-VECTOR-INDEX-NODE (NEW BOOLEAN-VECTOR-INDEX-NODE :THE-VECTOR (NEW BOOLEAN-VECTOR :ARRAY-SIZE 0)) :DOCUMENTATION \"Points to the head of a discrimination tree of containing\nall boolean vectors.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *PRINTINFRAME* CONTROL-FRAME NULL :DOCUMENTATION \"If set, controls diagnostic printing by making\nvariable bindings appear relative to the frame '*printInFrame*'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CONTROL-FRAME-ID-COUNTER* INTEGER -1 :DOCUMENTATION \"Generates unique IDs for control frames.  Used only for debugging.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *REVERSEPOLARITY?* BOOLEAN FALSE :PUBLIC? TRUE :DOCUMENTATION \"Signals atomic proposition provers that polarity is negative.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DUPLICATEINSTANCESCACHECROSSOVERPOINT* INTEGER 20 :DOCUMENTATION \"Point where a cache of generated instances in a \ndescription extension iterator is switched from a list to a hash table\")");
      defineExplanationPhrase(KWD_QUERY_DEPTH_CUTOFF, KWD_QUERY_TECHNICAL, "because of an inference depth cutoff", 0);
      defineExplanationPhrase(KWD_QUERY_DEPTH_CUTOFF, KWD_QUERY_LAY, "because the maximum inference search depth was exceeded", 0);
      defineExplanationPhrase(KWD_QUERY_TIMEOUT, KWD_QUERY_TECHNICAL, "because of an inference timeout", 0);
      defineExplanationPhrase(KWD_QUERY_TIMEOUT, KWD_QUERY_LAY, "because the allotted inference CPU time was exceeded", 0);
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *MOST-RECENT-QUERY* QUERY-ITERATOR NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *QUERY-CACHE* (HASH-TABLE OF SYMBOL QUERY-ITERATOR) (NEW HASH-TABLE) :DOCUMENTATION \"Caches in-line queries, so that they\ndon't have to be reparsed and reoptimized each time they\nare invoked.\")");
    }
  }
}

Surrogate* SGT_QUERY_LOGIC_INFERENCE_LEVEL = NULL;

Symbol* SYM_QUERY_STELLA_KEYWORD = NULL;

Surrogate* SGT_QUERY_LOGIC_NORMAL_INFERENCE_LEVEL = NULL;

Surrogate* SGT_QUERY_LOGIC_BACKTRACKING_INFERENCE_LEVEL = NULL;

Surrogate* SGT_QUERY_LOGIC_SUBSUMPTION_INFERENCE_LEVEL = NULL;

Surrogate* SGT_QUERY_LOGIC_SHALLOW_INFERENCE_LEVEL = NULL;

Surrogate* SGT_QUERY_LOGIC_ASSERTION_INFERENCE_LEVEL = NULL;

Surrogate* SGT_QUERY_LOGIC_REFUTATION_INFERENCE_LEVEL = NULL;

Keyword* KWD_QUERY_NORMAL = NULL;

Keyword* KWD_QUERY_BACKTRACKING = NULL;

Keyword* KWD_QUERY_SUBSUMPTION = NULL;

Keyword* KWD_QUERY_SHALLOW = NULL;

Keyword* KWD_QUERY_ASSERTION = NULL;

Keyword* KWD_QUERY_REFUTATION = NULL;

Symbol* SYM_QUERY_LOGIC_INFERENCE_LEVEL = NULL;

Keyword* KWD_QUERY_LOOKUP = NULL;

Keyword* KWD_QUERY_DUPLICATE_GOALS = NULL;

Keyword* KWD_QUERY_TRACE_SUBGOALS = NULL;

Keyword* KWD_QUERY_PROPAGATE = NULL;

Keyword* KWD_QUERY_STRATEGIES = NULL;

Symbol* SYM_QUERY_LOGIC_COST_ESTIMATE = NULL;

Surrogate* SGT_QUERY_LOGIC_QUERY_ITERATOR = NULL;

Symbol* SYM_QUERY_LOGIC_RESIDUE_GOALS = NULL;

Symbol* SYM_QUERY_LOGIC_BEST_GOAL_SEQUENCE = NULL;

Symbol* SYM_QUERY_STELLA_BADp = NULL;

Symbol* SYM_QUERY_LOGIC_EXTERNAL_VARIABLES = NULL;

Symbol* SYM_QUERY_LOGIC_EXHAUSTEDp = NULL;

Symbol* SYM_QUERY_STELLA_OPTIONS = NULL;

Symbol* SYM_QUERY_LOGIC_SOLUTIONS = NULL;

Symbol* SYM_QUERY_LOGIC_QUERY_CONTEXT = NULL;

Symbol* SYM_QUERY_LOGIC_BASE_CONTROL_FRAME = NULL;

Symbol* SYM_QUERY_LOGIC_CURRENT_CONTROL_FRAME = NULL;

Symbol* SYM_QUERY_LOGIC_CURRENT_PATTERN_RECORD = NULL;

Symbol* SYM_QUERY_LOGIC_CURRENT_PARALLEL_THREAD = NULL;

Symbol* SYM_QUERY_LOGIC_CONTROL_FRAME_PRIORITY_QUEUE = NULL;

Symbol* SYM_QUERY_LOGIC_AUGMENTED_GOAL_CACHEp = NULL;

Symbol* SYM_QUERY_LOGIC_ACTIVE_GOAL_CACHES = NULL;

Symbol* SYM_QUERY_LOGIC_TRIGGERED_DEPTH_CUTOFFp = NULL;

Symbol* SYM_QUERY_LOGIC_FAILED_TO_FIND_DUPLICATE_SUBGOALp = NULL;

Symbol* SYM_QUERY_LOGIC_FOUND_AT_LEAST_ONE_SOLUTIONp = NULL;

Symbol* SYM_QUERY_LOGIC_TIMESTAMP = NULL;

Symbol* SYM_QUERY_LOGIC_PARTIAL_MATCH_STRATEGY = NULL;

Symbol* SYM_QUERY_LOGIC_CURRENT_DEPTH_CUTOFF = NULL;

Symbol* SYM_QUERY_LOGIC_MAXIMUM_DEPTH = NULL;

Symbol* SYM_QUERY_LOGIC_ALLOTTED_TIME = NULL;

Symbol* SYM_QUERY_LOGIC_ALLOTTED_CLOCK_TICKS = NULL;

Symbol* SYM_QUERY_LOGIC_CURRENT_CLOCK_TICKS = NULL;

Symbol* SYM_QUERY_LOGIC_TIMEOUTp = NULL;

Symbol* SYM_QUERY_LOGIC_NEGATED_QUERY = NULL;

Symbol* SYM_QUERY_LOGIC_LATEST_PARTIAL_SCORE = NULL;

Symbol* SYM_QUERY_LOGIC_AUXILIARY_QUERY = NULL;

Symbol* SYM_QUERY_LOGIC_LATEST_POSITIVE_SCORE = NULL;

Symbol* SYM_QUERY_STELLA_DELETED_OBJECTp = NULL;

Symbol* SYM_QUERY_LOGIC_GOAL_BINDINGS = NULL;

Surrogate* SGT_QUERY_LOGIC_CONTROL_FRAME = NULL;

Symbol* SYM_QUERY_STELLA_STATE = NULL;

Symbol* SYM_QUERY_LOGIC_PROPOSITION = NULL;

Symbol* SYM_QUERY_LOGIC_TRUTH_VALUE = NULL;

Symbol* SYM_QUERY_LOGIC_REVERSE_POLARITYp = NULL;

Symbol* SYM_QUERY_LOGIC_STARTING_CLOCK_TICKS = NULL;

Symbol* SYM_QUERY_LOGIC_UP = NULL;

Symbol* SYM_QUERY_LOGIC_DOWN = NULL;

Symbol* SYM_QUERY_STELLA_RESULT = NULL;

Symbol* SYM_QUERY_LOGIC_ARGUMENT_CURSOR = NULL;

Symbol* SYM_QUERY_LOGIC_PATTERN_RECORD = NULL;

Symbol* SYM_QUERY_LOGIC_INHERITED_PATTERN_RECORD = NULL;

Symbol* SYM_QUERY_LOGIC_CHOICE_POINT_UNBINDING_OFFSET = NULL;

Symbol* SYM_QUERY_LOGIC_CURRENT_STRATEGY = NULL;

Symbol* SYM_QUERY_LOGIC_NEXT_STRATEGIES = NULL;

Symbol* SYM_QUERY_LOGIC_PARTIAL_MATCH_FRAME = NULL;

Symbol* SYM_QUERY_LOGIC_JUSTIFICATIONS = NULL;

Symbol* SYM_QUERY_LOGIC_CACHED_GOAL_RESULTp = NULL;

Symbol* SYM_QUERY_LOGIC_DONT_CACHE_GOAL_FAILUREp = NULL;

Surrogate* SGT_QUERY_LOGIC_PARALLEL_THREAD = NULL;

Symbol* SYM_QUERY_LOGIC_TOP_CONTROL_FRAME = NULL;

Symbol* SYM_QUERY_LOGIC_HYPOTHETICAL_WORLD = NULL;

Symbol* SYM_QUERY_LOGIC_VARIABLE_BINDINGS = NULL;

Symbol* SYM_QUERY_LOGIC_UNBINDING_STACK = NULL;

Symbol* SYM_QUERY_LOGIC_TOP_UNBINDING_STACK_OFFSET = NULL;

Symbol* SYM_QUERY_LOGIC_PRIORITY = NULL;

Symbol* SYM_QUERY_LOGIC_STATUS = NULL;

Surrogate* SGT_QUERY_LOGIC_PARALLEL_CONTROL_FRAME = NULL;

Symbol* SYM_QUERY_LOGIC_CHILD_THREADS = NULL;

Symbol* SYM_QUERY_LOGIC_UNBOUND_VARIABLESp = NULL;

Symbol* SYM_QUERY_LOGIC_CURRENT_CHILD_THREAD = NULL;

Symbol* SYM_QUERY_LOGIC_SAVED_PARENT_CONTEXT = NULL;

Symbol* SYM_QUERY_LOGIC_SAVED_PARENT_PARALLEL_THREAD = NULL;

Surrogate* SGT_QUERY_LOGIC_CONTROL_FRAME_PRIORITY_QUEUE = NULL;

Symbol* SYM_QUERY_LOGIC_QUEUE = NULL;

Keyword* KWD_QUERY_UPCLASSIFY = NULL;

Keyword* KWD_QUERY_DOWNCLASSIFY = NULL;

Keyword* KWD_QUERY_PARTIAL_MATCH = NULL;

Surrogate* SGT_QUERY_LOGIC_PROOF_ADJUNCT = NULL;

Surrogate* SGT_QUERY_LOGIC_PATTERN_RECORD = NULL;

Symbol* SYM_QUERY_LOGIC_CONTROL_FRAME = NULL;

Symbol* SYM_QUERY_LOGIC_DESCRIPTION = NULL;

Symbol* SYM_QUERY_LOGIC_EXTERNAL_ARGUMENTS = NULL;

Symbol* SYM_QUERY_STELLA_BOOLEAN_VECTOR = NULL;

Symbol* SYM_QUERY_LOGIC_OPTIMAL_PATTERN = NULL;

Symbol* SYM_QUERY_LOGIC_COLLECTION_LIST = NULL;

Surrogate* SGT_QUERY_LOGIC_BOOLEAN_VECTOR_INDEX_NODE = NULL;

Symbol* SYM_QUERY_LOGIC_TRUE_LINK = NULL;

Symbol* SYM_QUERY_LOGIC_FALSE_LINK = NULL;

Symbol* SYM_QUERY_LOGIC_THE_VECTOR = NULL;

Surrogate* SGT_QUERY_LOGIC_PATTERN_VARIABLE = NULL;

Keyword* KWD_QUERY_PATTERN = NULL;

Keyword* KWD_QUERY_CONTAINED_BY = NULL;

Keyword* KWD_QUERY_PARENT = NULL;

Symbol* SYM_QUERY_LOGIC_CACHED_BINDINGS_ITERATOR = NULL;

Keyword* KWD_QUERY_POPPED = NULL;

Keyword* KWD_QUERY_LOCAL = NULL;

Keyword* KWD_QUERY_QUERY_STACKS = NULL;

Surrogate* SGT_QUERY_LOGIC_PROPOSITION = NULL;

Surrogate* SGT_QUERY_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_QUERY_PL_KERNEL_KB_HOLDS = NULL;

Keyword* KWD_QUERY_NONE = NULL;

Keyword* KWD_QUERY_SHALLOW_DISJOINT = NULL;

Keyword* KWD_QUERY_DISJOINT = NULL;

Keyword* KWD_QUERY_ISA = NULL;

Surrogate* SGT_QUERY_LOGIC_LOGIC_OBJECT = NULL;

Keyword* KWD_QUERY_PERFORMANCE_CLUES = NULL;

Keyword* KWD_QUERY_WARNING = NULL;

Symbol* SYM_QUERY_STELLA_NULL = NULL;

Surrogate* SGT_QUERY_STELLA_LIST = NULL;

Symbol* SYM_QUERY_STELLA_SURROGATE_VALUE_INVERSE = NULL;

Symbol* SYM_QUERY_LOGIC_MASTER_PROPOSITION = NULL;

Keyword* KWD_QUERY_FLAT = NULL;

Keyword* KWD_QUERY_REALISTIC = NULL;

Keyword* KWD_QUERY_DOWN = NULL;

Keyword* KWD_QUERY_ITERATIVE_FORALL = NULL;

Keyword* KWD_QUERY_STATE_MACHINE = NULL;

Keyword* KWD_QUERY_PARALLEL_STRATEGIES = NULL;

Keyword* KWD_QUERY_STRATEGY = NULL;

Keyword* KWD_QUERY_SPECIALIST = NULL;

Keyword* KWD_QUERY_ATOMIC_GOAL = NULL;

Symbol* SYM_QUERY_LOGIC_ANTECEDENTS_RULE = NULL;

Keyword* KWD_QUERY_UP_TRUE = NULL;

Keyword* KWD_QUERY_UP_FAIL = NULL;

Keyword* KWD_QUERY_AND = NULL;

Keyword* KWD_QUERY_GOAL_TREE = NULL;

Keyword* KWD_QUERY_OR = NULL;

Keyword* KWD_QUERY_NOT = NULL;

Keyword* KWD_QUERY_FULL_SUBQUERY = NULL;

Keyword* KWD_QUERY_ANTECEDENTS = NULL;

Symbol* SYM_QUERY_STELLA_ITERATOR = NULL;

Keyword* KWD_QUERY_FAILURE = NULL;

Keyword* KWD_QUERY_FINAL_SUCCESS = NULL;

Surrogate* SGT_QUERY_LOGIC_NN_PARTIAL_MATCH = NULL;

Symbol* SYM_QUERY_LOGIC_MATCH_SCORE = NULL;

Symbol* SYM_QUERY_LOGIC_SUPPORT = NULL;

Symbol* SYM_QUERY_LOGIC_BACK = NULL;

Symbol* SYM_QUERY_LOGIC_JUSTIFICATION = NULL;

Symbol* SYM_QUERY_LOGIC_GOAL_CACHE = NULL;

Symbol* SYM_QUERY_LOGIC_DEBUG_FRAME_ID_INTERNAL = NULL;

Keyword* KWD_QUERY_MOVE_DOWN = NULL;

Keyword* KWD_QUERY_CONTINUING_SUCCESS = NULL;

Keyword* KWD_QUERY_MOVE_IN_PLACE = NULL;

Keyword* KWD_QUERY_TIMEOUT = NULL;

Keyword* KWD_QUERY_FUNCTION = NULL;

Keyword* KWD_QUERY_PREDICATE = NULL;

Keyword* KWD_QUERY_EQUIVALENT = NULL;

Keyword* KWD_QUERY_IMPLIES = NULL;

Keyword* KWD_QUERY_SCAN_CACHED_BINDINGS = NULL;

Keyword* KWD_QUERY_FORALL = NULL;

Keyword* KWD_QUERY_EXISTS = NULL;

Keyword* KWD_QUERY_CONSTANT = NULL;

Keyword* KWD_QUERY_FAIL = NULL;

Keyword* KWD_QUERY_CLUSTERED_CONJUNCTION = NULL;

Symbol* SYM_QUERY_STELLA_ARGUMENTS = NULL;

Keyword* KWD_QUERY_DISJUNCTIVE_IMPLICATION_INTRODUCTION = NULL;

Symbol* SYM_QUERY_LOGIC_FAIL = NULL;

Keyword* KWD_QUERY_DUPLICATE_GOALS_WITH_CACHING = NULL;

Keyword* KWD_QUERY_MANUFACTURE_SKOLEM = NULL;

Symbol* SYM_QUERY_LOGIC_IO_VARIABLES = NULL;

Surrogate* SGT_QUERY_LOGIC_NAMED_DESCRIPTION = NULL;

Keyword* KWD_QUERY_DESCRIPTION = NULL;

Symbol* SYM_QUERY_LOGIC_CACHED_SINGLE_VALUEDp = NULL;

Keyword* KWD_QUERY_FAILED_OVERLAY = NULL;

Surrogate* SGT_QUERY_PL_KERNEL_KB_DISJOINT = NULL;

Symbol* SYM_QUERY_LOGIC_pD1 = NULL;

Symbol* SYM_QUERY_LOGIC_pD2 = NULL;

Symbol* SYM_QUERY_LOGIC_DISJOINT = NULL;

Symbol* SYM_QUERY_LOGIC_F_DISJOINT_TERMSp_QUERY_000 = NULL;

Symbol* SYM_QUERY_STELLA_OR = NULL;

Symbol* SYM_QUERY_STELLA_AND = NULL;

Symbol* SYM_QUERY_PL_KERNEL_KB_CLASS = NULL;

Symbol* SYM_QUERY_LOGIC_REFUTATION_DISJOINT = NULL;

Symbol* SYM_QUERY_LOGIC_F_EXPENSIVE_DISJOINT_TERMSp_QUERY_000 = NULL;

Surrogate* SGT_QUERY_PL_KERNEL_KB_COLLECTIONOF = NULL;

Surrogate* SGT_QUERY_STELLA_COLLECTION = NULL;

Surrogate* SGT_QUERY_LOGIC_SKOLEM = NULL;

Surrogate* SGT_QUERY_PL_KERNEL_KB_MEMBER_OF = NULL;

Surrogate* SGT_QUERY_LOGIC_DESCRIPTION_EXTENSION_ITERATOR = NULL;

Symbol* SYM_QUERY_LOGIC_ROOT_DESCRIPTION = NULL;

Symbol* SYM_QUERY_LOGIC_SUBCOLLECTIONS = NULL;

Symbol* SYM_QUERY_LOGIC_EXTENSION_ITERATOR = NULL;

Symbol* SYM_QUERY_LOGIC_REFERENCE_PROPOSITION = NULL;

Symbol* SYM_QUERY_LOGIC_ALREADY_GENERATED_LIST = NULL;

Symbol* SYM_QUERY_LOGIC_ALREADY_GENERATED_TABLE = NULL;

Symbol* SYM_QUERY_LOGIC_REMOVING_DUPLICATESp = NULL;

Keyword* KWD_QUERY_GOAL_CACHES = NULL;

Keyword* KWD_QUERY_DEPTH_VIOLATION = NULL;

Keyword* KWD_QUERY_DEPTH_CUTOFF = NULL;

Keyword* KWD_QUERY_TECHNICAL = NULL;

Keyword* KWD_QUERY_LAY = NULL;

Surrogate* SGT_QUERY_LOGIC_QUERY_SOLUTION_TABLE = NULL;

Symbol* SYM_QUERY_STELLA_THE_MAP = NULL;

Symbol* SYM_QUERY_LOGIC_QUERY = NULL;

Symbol* SYM_QUERY_STELLA_FIRST = NULL;

Symbol* SYM_QUERY_STELLA_LAST = NULL;

Surrogate* SGT_QUERY_LOGIC_QUERY_SOLUTION = NULL;

Symbol* SYM_QUERY_LOGIC_BINDINGS = NULL;

Symbol* SYM_QUERY_LOGIC_BEST_JUSTIFICATION = NULL;

Symbol* SYM_QUERY_LOGIC_ALL_JUSTIFICATIONS = NULL;

Symbol* SYM_QUERY_STELLA_NEXT = NULL;

Surrogate* SGT_QUERY_LOGIC_QUERY_SOLUTION_TABLE_ITERATOR = NULL;

Symbol* SYM_QUERY_STELLA_THE_TABLE = NULL;

Symbol* SYM_QUERY_STELLA_CURSOR = NULL;

Keyword* KWD_QUERY_TRACE_SOLUTIONS = NULL;

Symbol* SYM_QUERY_LOGIC_ATOMIC_SINGLETONSp = NULL;

Keyword* KWD_QUERY_EXECUTE_QUERY = NULL;

Keyword* KWD_QUERY_DONT_OPTIMIZEp = NULL;

Symbol* SYM_QUERY_LOGIC_DONT_OPTIMIZEp = NULL;

Symbol* SYM_QUERY_LOGIC_INITIAL_BINDINGS = NULL;

Keyword* KWD_QUERY_ITERATIVE_DEEPENINGp = NULL;

Symbol* SYM_QUERY_LOGIC_ITERATIVE_DEEPENINGp = NULL;

Keyword* KWD_QUERY_MATCH_MODE = NULL;

Keyword* KWD_QUERY_STRICT = NULL;

Keyword* KWD_QUERY_DEFERRED_OPTIONS = NULL;

Keyword* KWD_QUERY_ERROR = NULL;

Symbol* SYM_QUERY_STELLA_TRUE = NULL;

Symbol* SYM_QUERY_LOGIC_KAPPA = NULL;

Symbol* SYM_QUERY_STELLA_EXISTS = NULL;

Keyword* KWD_QUERY_HOW_MANY = NULL;

Keyword* KWD_QUERY_SORT_BY = NULL;

Keyword* KWD_QUERY_SCORE = NULL;

Keyword* KWD_QUERY_MOVEOUT = NULL;

Keyword* KWD_QUERY_MAXIMUM_DEPTH = NULL;

Keyword* KWD_QUERY_INFERENCE_LEVEL = NULL;

Surrogate* SGT_QUERY_STELLA_GENERALIZED_SYMBOL = NULL;

Keyword* KWD_QUERY_THREE_VALUEDp = NULL;

Keyword* KWD_QUERY_SINGLETONSp = NULL;

Keyword* KWD_QUERY_MINIMUM_SCORE = NULL;

Keyword* KWD_QUERY_MAXIMIZE_SCOREp = NULL;

Keyword* KWD_QUERY_MAXIMUM_UNKNOWNS = NULL;

Surrogate* SGT_QUERY_STELLA_PROPERTY_LIST = NULL;

Surrogate* SGT_QUERY_STELLA_CONS = NULL;

Keyword* KWD_QUERY_DYNAMIC = NULL;

Keyword* KWD_QUERY_DYNAMIC_WITH_CLUSTERING = NULL;

Surrogate* SGT_QUERY_PL_KERNEL_KB_CONCEPT_PROTOTYPE = NULL;

Symbol* SYM_QUERY_LOGIC_pC = NULL;

Symbol* SYM_QUERY_LOGIC_pP = NULL;

Symbol* SYM_QUERY_PL_KERNEL_KB_CONCEPT_PROTOTYPE = NULL;

Symbol* SYM_QUERY_LOGIC_F_GET_PROTOTYPE_QUERY_000 = NULL;

Keyword* KWD_QUERY_EXTENSIONAL_ASSERTION = NULL;

Keyword* KWD_QUERY_META = NULL;

Surrogate* SGT_QUERY_STELLA_RELATION = NULL;

Surrogate* SGT_QUERY_STELLA_VECTOR = NULL;

Keyword* KWD_QUERY_UPDATE_FROM_QUERY = NULL;

Symbol* SYM_QUERY_LOGIC_DESCRIPTIVEp = NULL;

Symbol* SYM_QUERY_LOGIC_WEIGHT = NULL;

Keyword* KWD_QUERY_MODULE = NULL;

Surrogate* SGT_QUERY_STELLA_MODULE = NULL;

Keyword* KWD_QUERY_RELATION = NULL;

Keyword* KWD_QUERY_ASSERT_TRUE = NULL;

Keyword* KWD_QUERY_RETRACT_TRUE = NULL;

Symbol* SYM_QUERY_LOGIC_STARTUP_QUERY = NULL;

Symbol* SYM_QUERY_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
