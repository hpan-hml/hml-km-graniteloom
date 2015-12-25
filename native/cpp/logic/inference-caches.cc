//  -*- Mode: C++ -*-

// inference-caches.cc

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
 | Portions created by the Initial Developer are Copyright (C) 1997-2014      |
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

boolean worldStateP(Context* self) {
  if (subtypeOfP(safePrimaryType(self), SGT_INFERENCE_CACHES_STELLA_WORLD)) {
    { Context* self000 = self;
      World* self = ((World*)(self000));

      return ((!((boolean)(((Context*)(dynamicSlotValue(self->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_INFERENCE_CACHE_OF, NULL)))))) &&
          (!((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_MONOTONICp, FALSE_WRAPPER)))->wrapperValue));
    }
  }
  else {
    return (true);
  }
}

Context* getWorldState(Context* self) {
  return ((worldStateP(self) ? self : ((World*)(self))->baseModule));
}

World* lookupInferenceCache(Context* context, Keyword* kind) {
  { Context* cacheworld = NULL;

    if (kind == KWD_INFERENCE_CACHES_JUST_IN_TIME) {
      cacheworld = ((World*)(dynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE, NULL)));
    }
    else if (kind == KWD_INFERENCE_CACHES_META) {
      cacheworld = ((World*)(dynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE, NULL)));
    }
    else if (kind == KWD_INFERENCE_CACHES_TMS) {
      cacheworld = ((World*)(dynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE, NULL)));
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << kind << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    return (((World*)(cacheworld)));
  }
}

void initializeInferenceWorld(World* world) {
}

World* createInferenceCache(Context* context, Keyword* kind) {
  { World* world = createWorld((getQuotedTree("((:JUST-IN-TIME :TMS) \"/LOGIC\")", "/LOGIC")->memberP(kind) ? getInferenceCache(context, KWD_INFERENCE_CACHES_META) : context), NULL);

    if (kind == KWD_INFERENCE_CACHES_JUST_IN_TIME) {
      setDynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE, world, NULL);
    }
    else if (kind == KWD_INFERENCE_CACHES_META) {
      setDynamicSlotValue(world->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_MONOTONICp, TRUE_WRAPPER, FALSE_WRAPPER);
      setDynamicSlotValue(world->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp, ((!allPropositions(context->baseModule, true)->nextP()) ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
      setDynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE, world, NULL);
    }
    else if (kind == KWD_INFERENCE_CACHES_TMS) {
      setDynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE, world, NULL);
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << kind << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    setDynamicSlotValue(world->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_INFERENCE_CACHE_OF, context, NULL);
    initializeInferenceWorld(world);
    return (world);
  }
}

World* getInferenceCache(Context* context, Keyword* kind) {
  if (!worldStateP(context)) {
    return (((World*)(context)));
  }
  { World* world = lookupInferenceCache(context, kind);

    if (((boolean)(world))) {
      return (world);
    }
    processCheckTypesAgenda();
    world = createInferenceCache(context, kind);
    if (kind == KWD_INFERENCE_CACHES_JUST_IN_TIME) {
    }
    else if ((kind == KWD_INFERENCE_CACHES_META) ||
        (kind == KWD_INFERENCE_CACHES_TMS)) {
      { Module* parentmodule = NULL;
        Cons* iter000 = context->baseModule->parentModules->theConsList;

        for (parentmodule, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
          parentmodule = ((Module*)(iter000->value));
          inheritCachedInferences(lookupInferenceCache(parentmodule, kind), world);
        }
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << kind << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    return (world);
  }
}

void destroyInferenceCache(Context* context, Keyword* kind) {
  { World* cache = NULL;

    if (kind == KWD_INFERENCE_CACHES_JUST_IN_TIME) {
      cache = ((World*)(dynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE, NULL)));
      setDynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE, NULL, NULL);
    }
    else if (kind == KWD_INFERENCE_CACHES_META) {
      cache = ((World*)(dynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE, NULL)));
      setDynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE, NULL, NULL);
    }
    else if (kind == KWD_INFERENCE_CACHES_TMS) {
      cache = ((World*)(dynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE, NULL)));
      setDynamicSlotValue(context->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE, NULL, NULL);
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << kind << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    if (((boolean)(cache)) &&
        (!cache->deletedP())) {
      destroyWorld(cache);
    }
  }
}

void destroyAllInferenceCaches(Context* context, Keyword* kind) {
  destroyInferenceCache(context, kind);
  { Context* child = NULL;
    AllPurposeIterator* iter000 = allSubcontexts(oCONTEXTo, KWD_INFERENCE_CACHES_PREORDER);

    for (child, iter000; iter000->nextP(); ) {
      child = ((Context*)(iter000->value));
      if (worldStateP(child)) {
        destroyInferenceCache(child, kind);
      }
    }
  }
}

void unlinkInferenceCache(World* self) {
  if (((boolean)(((Context*)(dynamicSlotValue(self->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_INFERENCE_CACHE_OF, NULL)))))) {
    { Context* worldstate = ((Context*)(dynamicSlotValue(self->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_INFERENCE_CACHE_OF, NULL)));

      if (self == ((World*)(dynamicSlotValue(worldstate->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE, NULL)))) {
        setDynamicSlotValue(worldstate->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE, NULL, NULL);
      }
      else if (self == ((World*)(dynamicSlotValue(worldstate->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE, NULL)))) {
        setDynamicSlotValue(worldstate->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE, NULL, NULL);
      }
      else if (self == ((World*)(dynamicSlotValue(worldstate->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE, NULL)))) {
        setDynamicSlotValue(worldstate->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE, NULL, NULL);
      }
      setDynamicSlotValue(self->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_INFERENCE_CACHE_OF, NULL, NULL);
    }
  }
}

void destroyInferenceCaches(Context* context) {
  destroyInferenceCache(context, KWD_INFERENCE_CACHES_JUST_IN_TIME);
  destroyInferenceCache(context, KWD_INFERENCE_CACHES_META);
  destroyInferenceCache(context, KWD_INFERENCE_CACHES_TMS);
}

// Used to signal an assertion that doesn't
// blow away inference caches.
DEFINE_STELLA_SPECIAL(oINVISIBLEASSERTIONpo, boolean , false);

boolean metaPropositionP(Proposition* proposition) {
  if (!((boolean)(proposition))) {
    return (false);
  }
  { boolean pointstometaobjectP = false;

    { Object* arg = NULL;
      Vector* vector000 = proposition->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      for  (arg, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        { Surrogate* testValue000 = safePrimaryType(arg);

          if (subtypeOfP(testValue000, SGT_INFERENCE_CACHES_LOGIC_DESCRIPTION)) {
            { Object* arg000 = arg;
              Description* arg = ((Description*)(arg000));

              pointstometaobjectP = true;
            }
          }
          else if (subtypeOfP(testValue000, SGT_INFERENCE_CACHES_STELLA_LITERAL_WRAPPER)) {
            { Object* arg001 = arg;
              LiteralWrapper* arg = ((LiteralWrapper*)(arg001));

            }
          }
          else {
            return (false);
          }
        }
      }
    }
    return (pointstometaobjectP);
  }
}

void handleOutOfDateInferenceCache(Keyword* assertorretract, Proposition* proposition) {
  if (worldStateP(oCONTEXTo)) {
    if ((!((boolean)(lookupInferenceCache(oCONTEXTo, KWD_INFERENCE_CACHES_META)))) ||
        (((boolean)(oQUERYITERATORo)) ||
         (descriptionModeP() ||
          oINVISIBLEASSERTIONpo))) {
      return;
    }
    { NamedDescription* description = (((boolean)(proposition)) ? getDescription(((Surrogate*)(proposition->operatoR))) : ((NamedDescription*)(NULL)));

      if (((boolean)(description)) &&
          testPropertyP(description, SGT_INFERENCE_CACHES_PL_KERNEL_KB_HIDDEN_RELATION)) {
        return;
      }
    }
    if (metaPropositionP(proposition) &&
        ((assertorretract == KWD_INFERENCE_CACHES_RETRACT) &&
         (!((BooleanWrapper*)(dynamicSlotValue(lookupInferenceCache(oCONTEXTo, KWD_INFERENCE_CACHES_META)->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINEDp, FALSE_WRAPPER)))->wrapperValue))) {
      if (((boolean)(oTRACED_KEYWORDSo)) &&
          oTRACED_KEYWORDSo->membP(KWD_INFERENCE_CACHES_PERFORMANCE_CLUES)) {
        std::cout << "DELETING META CACHE" << std::endl;
      }
      destroyInferenceCache(oCONTEXTo, KWD_INFERENCE_CACHES_META);
    }
    else if (oJUST_IN_TIME_FORWARD_INFERENCEpo) {
      if (((boolean)(((World*)(dynamicSlotValue(oCONTEXTo->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE, NULL)))))) {
        if (((boolean)(oTRACED_KEYWORDSo)) &&
            oTRACED_KEYWORDSo->membP(KWD_INFERENCE_CACHES_PERFORMANCE_CLUES)) {
          std::cout << "DELETING JIT CACHE" << std::endl;
        }
        destroyAllInferenceCaches(oCONTEXTo, KWD_INFERENCE_CACHES_JUST_IN_TIME);
      }
    }
    else {
      { World* cache = lookupInferenceCache(oCONTEXTo, KWD_INFERENCE_CACHES_TMS);

        if (((boolean)(cache)) &&
            (!((BooleanWrapper*)(dynamicSlotValue(cache->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINEDp, FALSE_WRAPPER)))->wrapperValue)) {
          destroyInferenceCache(oCONTEXTo, KWD_INFERENCE_CACHES_TMS);
        }
      }
    }
    return;
  }
  { World* world = ((World*)(oCONTEXTo));

    if (((BooleanWrapper*)(dynamicSlotValue(world->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_MONOTONICp, FALSE_WRAPPER)))->wrapperValue &&
        (assertorretract == KWD_INFERENCE_CACHES_RETRACT)) {
      if (((boolean)(proposition))) {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Retraction of " << "`" << proposition << "'" << " occurred in world " << "`" << world << "'" << " which is marked monotonic." << std::endl;
      }
      else {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Retraction occurred in world " << "`" << world << "'" << " which is marked monotonic." << std::endl;
      }
    }
    if (!((BooleanWrapper*)(dynamicSlotValue(world->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINEDp, FALSE_WRAPPER)))->wrapperValue) {
      setDynamicSlotValue(world->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp, FALSE_WRAPPER, FALSE_WRAPPER);
    }
  }
}

World* bestInferenceCache(Context* context) {
  if (oJUST_IN_TIME_FORWARD_INFERENCEpo) {
    return (getInferenceCache(context, KWD_INFERENCE_CACHES_JUST_IN_TIME));
  }
  { World* cache = lookupInferenceCache(context, KWD_INFERENCE_CACHES_TMS);

    if (((boolean)(cache))) {
      return (cache);
    }
    else {
      return (lookupInferenceCache(context, KWD_INFERENCE_CACHES_META));
    }
  }
}

Context* getQueryContext() {
  if (!worldStateP(oCONTEXTo)) {
    return (oCONTEXTo);
  }
  { World* cache = bestInferenceCache(oCONTEXTo);

    return ((((boolean)(cache)) ? cache : oCONTEXTo));
  }
}

Context* getPropertyTestContext() {
  { World* constraintpropagationworld = lookupConstraintPropagationWorld(oCONTEXTo);

    if (!((boolean)(constraintpropagationworld))) {
      return (oCONTEXTo);
    }
    else {
      return (constraintpropagationworld);
    }
  }
}

Context* getInferableTestContext() {
  if (!worldStateP(oCONTEXTo)) {
    return (oCONTEXTo);
  }
  else {
    { World* temp000 = lookupInferenceCache(oCONTEXTo, KWD_INFERENCE_CACHES_META);

      { Context* value000 = (((boolean)(temp000)) ? temp000 : oCONTEXTo);

        return (value000);
      }
    }
  }
}

Context* getTopLevelUpdateContext() {
  return (getWorldState(oCONTEXTo));
}

World* lookupConstraintPropagationWorld(Context* self) {
  if (worldStateP(self)) {
    if (oJUST_IN_TIME_FORWARD_INFERENCEpo) {
      if (((boolean)(oQUERYITERATORo))) {
        return (getInferenceCache(self, KWD_INFERENCE_CACHES_JUST_IN_TIME));
      }
      else {
        return (lookupInferenceCache(self, KWD_INFERENCE_CACHES_JUST_IN_TIME));
      }
    }
    else {
      return (lookupInferenceCache(self, KWD_INFERENCE_CACHES_TMS));
    }
  }
  else {
    return (((World*)(self)));
  }
}

void inheritCachedInferences(World* fromworld, World* toworld) {
  toworld = toworld;
  if (!((boolean)(fromworld))) {
    return;
  }
}

void inheritTruthValueUpdate(Proposition* proposition, World* toworld) {
}

void inheritVariableValueUpdate(Skolem* skolem, World* toworld) {
}

void callPropagateConstraints(Context* context) {
  // Trigger constraint propagation over all propositions
  // in the module or world `context'.
  { Context* worldstate = getWorldState(context);
    World* propagationworld = getInferenceCache(worldstate, KWD_INFERENCE_CACHES_META);

    if (((BooleanWrapper*)(dynamicSlotValue(propagationworld->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp, FALSE_WRAPPER)))->wrapperValue) {
      return;
    }
    try {
      { Proposition* p = NULL;
        Iterator* iter000 = allPropositions(((Module*)(worldstate)), true);

        for (p, iter000; iter000->nextP(); ) {
          p = ((Proposition*)(iter000->value));
          reactToKbUpdate(propagationworld, p);
        }
      }
    }
    catch (Clash& _e) {
      Clash* e = &_e;

      *(STANDARD_ERROR->nativeStream) << exceptionMessage(e) << std::endl;
      *(STANDARD_ERROR->nativeStream) << "One or more facts need to be retracted to eliminate" << std::endl << "   the inconsistency." << std::endl;
    }
    setDynamicSlotValue(propagationworld->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp, TRUE_WRAPPER, FALSE_WRAPPER);
  }
}

void propagateConstraints(Cons* name) {
  // Trigger constraint propagation over all propositions of module `name'.
  // If no `name' is supplied, the current module will be used.  This also
  // enables incremental constraint propagation for future monotonic updates to
  // the module.  Once a non-monotonic update is performed, i.e., a retraction
  // or clipping of a function value, all cached inferences will be discarded
  // and constraint propagation will be turned off until this function is
  // called again.
  processCheckTypesAgenda();
  { Cons* optionalname = name;
    Module* module = NULL;

    if (((boolean)(optionalname->value))) {
      module = coerceToModule(optionalname->value, true);
    }
    if (((boolean)(module))) {
      callPropagateConstraints(module);
    }
    else {
      callPropagateConstraints(oCONTEXTo);
    }
  }
}

void propagateConstraintsEvaluatorWrapper(Cons* arguments) {
  propagateConstraints(arguments);
}

void repropagateConstraints(Cons* name) {
  // Force non-incremental constraint propagation over all propositions of
  // module `name'.  If no `name' is supplied, the current module will be used.
  // This also enables incremental constraint propagation for future monotonic
  // updates to the module similar to `propagate-constraints'.
  processCheckTypesAgenda();
  { Cons* optionalname = name;
    Module* context = coerceToModule(optionalname->value, true);

    if (!((boolean)(context))) {
      context = ((Module*)(oCONTEXTo));
    }
    destroyInferenceCaches(context);
    callPropagateConstraints(context);
  }
}

void repropagateConstraintsEvaluatorWrapper(Cons* arguments) {
  repropagateConstraints(arguments);
}

void callRunForwardRules(Module* module, boolean forceP) {
  // Run forward inference rules in module 'module'. If 'module'
  // is NULL, the current module will be used.  If forward inferencing is already
  // up-to-date in the designated module, no additional inferencing will occur,
  // unless 'force?' is set to TRUE, in which case all forward rules are run or rerun.
  finalizeObjects();
  processCheckTypesAgenda();
  if (forceP) {
    destroyInferenceCaches(module);
  }
  { Context* worldstate = getWorldState(module);
    World* propagationworld = getInferenceCache(worldstate, KWD_INFERENCE_CACHES_META);

    if (((BooleanWrapper*)(dynamicSlotValue(propagationworld->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp, FALSE_WRAPPER)))->wrapperValue) {
      return;
    }
    { Proposition* p = NULL;
      Iterator* iter000 = allPropositions(((Module*)(worldstate)), true);

      for (p, iter000; iter000->nextP(); ) {
        p = ((Proposition*)(iter000->value));
        reactToKbUpdate(propagationworld, p);
      }
    }
    setDynamicSlotValue(propagationworld->dynamicSlots, SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp, TRUE_WRAPPER, FALSE_WRAPPER);
  }
}

void runForwardRules(Cons* options) {
  // Run forward inference rules in the module defined by the :module option (which
  // defaults to the current module).  If forward inferencing is already up-to-date
  // in the designated module, no additional inferencing will occur, unless the :force?
  // option is specified as TRUE, in which case all forward rules are run or rerun.
  // For backwards compatibility, this command also supports the old <module> :force
  // arguments specified with a non-standard keyword notation.
  // 
  // Calling `run-forward-rules' temporarily puts the module into a mode where
  // future assertional (monotonic) updates will trigger additional forward
  // inference.  Once a non-monotonic update is performed, i.e., a retraction
  // or clipping of relation value, all cached forward inferences will be discarded
  // and forward inferencing will be disabled until this function is called again.
  { Cons* optionslist = options;
    PropertyList* theoptions = parseOptions((keywordP(optionslist->value) ? optionslist : consList(4, KWD_INFERENCE_CACHES_MODULE, optionslist->value, KWD_INFERENCE_CACHES_FORCEp, ((optionslist->rest->value == KWD_INFERENCE_CACHES_FORCE) ? TRUE_WRAPPER : FALSE_WRAPPER))), listO(5, KWD_INFERENCE_CACHES_MODULE, SGT_INFERENCE_CACHES_STELLA_MODULE, KWD_INFERENCE_CACHES_FORCEp, SGT_INFERENCE_CACHES_STELLA_BOOLEAN, NIL), true, false);
    Module* themodule = ((Module*)(theoptions->lookupWithDefault(KWD_INFERENCE_CACHES_MODULE, oMODULEo)));
    boolean forceP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(theoptions->lookupWithDefault(KWD_INFERENCE_CACHES_FORCEp, FALSE_WRAPPER))));

    try {
      callRunForwardRules(themodule, forceP);
    }
    catch (Clash& _e) {
      Clash* e = &_e;

      *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
      std::cout << "   One or more facts need to be retracted to eliminate" << " the inconsistency." << std::endl;
    }
  }
}

void runForwardRulesEvaluatorWrapper(Cons* arguments) {
  runForwardRules(arguments);
}

void startupInferenceCaches() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo);
    if (currentStartupTimePhaseP(2)) {
      SGT_INFERENCE_CACHES_STELLA_WORLD = ((Surrogate*)(internRigidSymbolWrtModule("WORLD", getStellaModule("/STELLA", true), 1)));
      SYM_INFERENCE_CACHES_LOGIC_INFERENCE_CACHE_OF = ((Symbol*)(internRigidSymbolWrtModule("INFERENCE-CACHE-OF", NULL, 0)));
      SYM_INFERENCE_CACHES_LOGIC_MONOTONICp = ((Symbol*)(internRigidSymbolWrtModule("MONOTONIC?", NULL, 0)));
      KWD_INFERENCE_CACHES_JUST_IN_TIME = ((Keyword*)(internRigidSymbolWrtModule("JUST-IN-TIME", NULL, 2)));
      SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE = ((Symbol*)(internRigidSymbolWrtModule("JUST-IN-TIME-INFERENCE-CACHE", NULL, 0)));
      KWD_INFERENCE_CACHES_META = ((Keyword*)(internRigidSymbolWrtModule("META", NULL, 2)));
      SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE = ((Symbol*)(internRigidSymbolWrtModule("META-INFERENCE-CACHE", NULL, 0)));
      KWD_INFERENCE_CACHES_TMS = ((Keyword*)(internRigidSymbolWrtModule("TMS", NULL, 2)));
      SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE = ((Symbol*)(internRigidSymbolWrtModule("TRUTH-MAINTAINED-INFERENCE-CACHE", NULL, 0)));
      SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp = ((Symbol*)(internRigidSymbolWrtModule("UP-TO-DATE-INFERENCES?", NULL, 0)));
      KWD_INFERENCE_CACHES_PREORDER = ((Keyword*)(internRigidSymbolWrtModule("PREORDER", NULL, 2)));
      SGT_INFERENCE_CACHES_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
      SGT_INFERENCE_CACHES_STELLA_LITERAL_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("LITERAL-WRAPPER", getStellaModule("/STELLA", true), 1)));
      SGT_INFERENCE_CACHES_PL_KERNEL_KB_HIDDEN_RELATION = ((Surrogate*)(internRigidSymbolWrtModule("HIDDEN-RELATION", getStellaModule("/PL-KERNEL-KB", true), 1)));
      KWD_INFERENCE_CACHES_RETRACT = ((Keyword*)(internRigidSymbolWrtModule("RETRACT", NULL, 2)));
      SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINEDp = ((Symbol*)(internRigidSymbolWrtModule("TRUTH-MAINTAINED?", NULL, 0)));
      KWD_INFERENCE_CACHES_PERFORMANCE_CLUES = ((Keyword*)(internRigidSymbolWrtModule("PERFORMANCE-CLUES", NULL, 2)));
      KWD_INFERENCE_CACHES_MODULE = ((Keyword*)(internRigidSymbolWrtModule("MODULE", NULL, 2)));
      KWD_INFERENCE_CACHES_FORCEp = ((Keyword*)(internRigidSymbolWrtModule("FORCE?", NULL, 2)));
      KWD_INFERENCE_CACHES_FORCE = ((Keyword*)(internRigidSymbolWrtModule("FORCE", NULL, 2)));
      SGT_INFERENCE_CACHES_STELLA_MODULE = ((Surrogate*)(internRigidSymbolWrtModule("MODULE", getStellaModule("/STELLA", true), 1)));
      SGT_INFERENCE_CACHES_STELLA_BOOLEAN = ((Surrogate*)(internRigidSymbolWrtModule("BOOLEAN", getStellaModule("/STELLA", true), 1)));
      SYM_INFERENCE_CACHES_LOGIC_STARTUP_INFERENCE_CACHES = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-INFERENCE-CACHES", NULL, 0)));
      SYM_INFERENCE_CACHES_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("WORLD-STATE?", "(DEFUN (WORLD-STATE? BOOLEAN) ((SELF CONTEXT)) :PUBLIC? TRUE)", ((cpp_function_code)(&worldStateP)), NULL);
      defineFunctionObject("GET-WORLD-STATE", "(DEFUN (GET-WORLD-STATE CONTEXT) ((SELF CONTEXT)) :PUBLIC? TRUE)", ((cpp_function_code)(&getWorldState)), NULL);
      defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT META-INFERENCE-CACHE :TYPE WORLD :ALLOCATION :DYNAMIC)");
      defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT TRUTH-MAINTAINED-INFERENCE-CACHE :TYPE WORLD :ALLOCATION :DYNAMIC)");
      defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT JUST-IN-TIME-INFERENCE-CACHE :TYPE WORLD :ALLOCATION :DYNAMIC)");
      defineExternalSlotFromStringifiedSource("(DEFSLOT WORLD INFERENCE-CACHE-OF :TYPE CONTEXT :PUBLIC? TRUE :ALLOCATION :DYNAMIC)");
      defineFunctionObject("LOOKUP-INFERENCE-CACHE", "(DEFUN (LOOKUP-INFERENCE-CACHE WORLD) ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", ((cpp_function_code)(&lookupInferenceCache)), NULL);
      defineFunctionObject("INITIALIZE-INFERENCE-WORLD", "(DEFUN INITIALIZE-INFERENCE-WORLD ((WORLD WORLD)))", ((cpp_function_code)(&initializeInferenceWorld)), NULL);
      defineFunctionObject("CREATE-INFERENCE-CACHE", "(DEFUN (CREATE-INFERENCE-CACHE WORLD) ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", ((cpp_function_code)(&createInferenceCache)), NULL);
      defineFunctionObject("GET-INFERENCE-CACHE", "(DEFUN (GET-INFERENCE-CACHE WORLD) ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", ((cpp_function_code)(&getInferenceCache)), NULL);
      defineFunctionObject("DESTROY-INFERENCE-CACHE", "(DEFUN DESTROY-INFERENCE-CACHE ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", ((cpp_function_code)(&destroyInferenceCache)), NULL);
      defineFunctionObject("DESTROY-ALL-INFERENCE-CACHES", "(DEFUN DESTROY-ALL-INFERENCE-CACHES ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", ((cpp_function_code)(&destroyAllInferenceCaches)), NULL);
      defineFunctionObject("UNLINK-INFERENCE-CACHE", "(DEFUN UNLINK-INFERENCE-CACHE ((SELF WORLD)))", ((cpp_function_code)(&unlinkInferenceCache)), NULL);
      defineFunctionObject("DESTROY-INFERENCE-CACHES", "(DEFUN DESTROY-INFERENCE-CACHES ((CONTEXT CONTEXT)) :PUBLIC? TRUE)", ((cpp_function_code)(&destroyInferenceCaches)), NULL);
      defineFunctionObject("META-PROPOSITION?", "(DEFUN (META-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)) :PUBLIC? TRUE)", ((cpp_function_code)(&metaPropositionP)), NULL);
      defineFunctionObject("HANDLE-OUT-OF-DATE-INFERENCE-CACHE", "(DEFUN HANDLE-OUT-OF-DATE-INFERENCE-CACHE ((ASSERTORRETRACT KEYWORD) (PROPOSITION PROPOSITION)))", ((cpp_function_code)(&handleOutOfDateInferenceCache)), NULL);
      defineFunctionObject("BEST-INFERENCE-CACHE", "(DEFUN (BEST-INFERENCE-CACHE WORLD) ((CONTEXT CONTEXT)))", ((cpp_function_code)(&bestInferenceCache)), NULL);
      defineFunctionObject("GET-QUERY-CONTEXT", "(DEFUN (GET-QUERY-CONTEXT CONTEXT) () :PUBLIC? TRUE)", ((cpp_function_code)(&getQueryContext)), NULL);
      defineFunctionObject("GET-PROPERTY-TEST-CONTEXT", "(DEFUN (GET-PROPERTY-TEST-CONTEXT CONTEXT) ())", ((cpp_function_code)(&getPropertyTestContext)), NULL);
      defineFunctionObject("GET-INFERABLE-TEST-CONTEXT", "(DEFUN (GET-INFERABLE-TEST-CONTEXT CONTEXT) ())", ((cpp_function_code)(&getInferableTestContext)), NULL);
      defineFunctionObject("GET-TOP-LEVEL-UPDATE-CONTEXT", "(DEFUN (GET-TOP-LEVEL-UPDATE-CONTEXT CONTEXT) ())", ((cpp_function_code)(&getTopLevelUpdateContext)), NULL);
      defineFunctionObject("LOOKUP-CONSTRAINT-PROPAGATION-WORLD", "(DEFUN (LOOKUP-CONSTRAINT-PROPAGATION-WORLD WORLD) ((SELF CONTEXT)))", ((cpp_function_code)(&lookupConstraintPropagationWorld)), NULL);
      defineFunctionObject("INHERIT-CACHED-INFERENCES", "(DEFUN INHERIT-CACHED-INFERENCES ((FROMWORLD WORLD) (TOWORLD WORLD)))", ((cpp_function_code)(&inheritCachedInferences)), NULL);
      defineFunctionObject("INHERIT-TRUTH-VALUE-UPDATE", "(DEFUN INHERIT-TRUTH-VALUE-UPDATE ((PROPOSITION PROPOSITION) (TOWORLD WORLD)))", ((cpp_function_code)(&inheritTruthValueUpdate)), NULL);
      defineFunctionObject("INHERIT-VARIABLE-VALUE-UPDATE", "(DEFUN INHERIT-VARIABLE-VALUE-UPDATE ((SKOLEM SKOLEM) (TOWORLD WORLD)))", ((cpp_function_code)(&inheritVariableValueUpdate)), NULL);
      defineFunctionObject("CALL-PROPAGATE-CONSTRAINTS", "(DEFUN CALL-PROPAGATE-CONSTRAINTS ((CONTEXT CONTEXT)) :DOCUMENTATION \"Trigger constraint propagation over all propositions\nin the module or world `context'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callPropagateConstraints)), NULL);
      defineFunctionObject("PROPAGATE-CONSTRAINTS", "(DEFUN PROPAGATE-CONSTRAINTS (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Trigger constraint propagation over all propositions of module `name'.\nIf no `name' is supplied, the current module will be used.  This also\nenables incremental constraint propagation for future monotonic updates to\nthe module.  Once a non-monotonic update is performed, i.e., a retraction\nor clipping of a function value, all cached inferences will be discarded\nand constraint propagation will be turned off until this function is\ncalled again.\")", ((cpp_function_code)(&propagateConstraints)), ((cpp_function_code)(&propagateConstraintsEvaluatorWrapper)));
      defineFunctionObject("REPROPAGATE-CONSTRAINTS", "(DEFUN REPROPAGATE-CONSTRAINTS (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Force non-incremental constraint propagation over all propositions of\nmodule `name'.  If no `name' is supplied, the current module will be used.\nThis also enables incremental constraint propagation for future monotonic\nupdates to the module similar to `propagate-constraints'.\")", ((cpp_function_code)(&repropagateConstraints)), ((cpp_function_code)(&repropagateConstraintsEvaluatorWrapper)));
      defineFunctionObject("CALL-RUN-FORWARD-RULES", "(DEFUN CALL-RUN-FORWARD-RULES ((MODULE MODULE) (FORCE? BOOLEAN)) :DOCUMENTATION \"Run forward inference rules in module 'module'. If 'module'\nis NULL, the current module will be used.  If forward inferencing is already\nup-to-date in the designated module, no additional inferencing will occur,\nunless 'force?' is set to TRUE, in which case all forward rules are run or rerun.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callRunForwardRules)), NULL);
      defineFunctionObject("RUN-FORWARD-RULES", "(DEFUN RUN-FORWARD-RULES (|&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Run forward inference rules in the module defined by the :module option (which\ndefaults to the current module).  If forward inferencing is already up-to-date\nin the designated module, no additional inferencing will occur, unless the :force?\noption is specified as TRUE, in which case all forward rules are run or rerun.\nFor backwards compatibility, this command also supports the old <module> :force\narguments specified with a non-standard keyword notation.\n\nCalling `run-forward-rules' temporarily puts the module into a mode where\nfuture assertional (monotonic) updates will trigger additional forward\ninference.  Once a non-monotonic update is performed, i.e., a retraction\nor clipping of relation value, all cached forward inferences will be discarded\nand forward inferencing will be disabled until this function is called again.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", ((cpp_function_code)(&runForwardRules)), ((cpp_function_code)(&runForwardRulesEvaluatorWrapper)));
      defineFunctionObject("STARTUP-INFERENCE-CACHES", "(DEFUN STARTUP-INFERENCE-CACHES () :PUBLIC? TRUE)", ((cpp_function_code)(&startupInferenceCaches)), NULL);
      { MethodSlot* function = lookupFunction(SYM_INFERENCE_CACHES_LOGIC_STARTUP_INFERENCE_CACHES);

        setDynamicSlotValue(function->dynamicSlots, SYM_INFERENCE_CACHES_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupInferenceCaches"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      inModule(((StringWrapper*)(copyConsTree(wrapString("LOGIC")))));
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *INVISIBLEASSERTION?* BOOLEAN FALSE :DOCUMENTATION \"Used to signal an assertion that doesn't\nblow away inference caches.\")");
    }
  }
}

Surrogate* SGT_INFERENCE_CACHES_STELLA_WORLD = NULL;

Symbol* SYM_INFERENCE_CACHES_LOGIC_INFERENCE_CACHE_OF = NULL;

Symbol* SYM_INFERENCE_CACHES_LOGIC_MONOTONICp = NULL;

Keyword* KWD_INFERENCE_CACHES_JUST_IN_TIME = NULL;

Symbol* SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE = NULL;

Keyword* KWD_INFERENCE_CACHES_META = NULL;

Symbol* SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE = NULL;

Keyword* KWD_INFERENCE_CACHES_TMS = NULL;

Symbol* SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE = NULL;

Symbol* SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp = NULL;

Keyword* KWD_INFERENCE_CACHES_PREORDER = NULL;

Surrogate* SGT_INFERENCE_CACHES_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_INFERENCE_CACHES_STELLA_LITERAL_WRAPPER = NULL;

Surrogate* SGT_INFERENCE_CACHES_PL_KERNEL_KB_HIDDEN_RELATION = NULL;

Keyword* KWD_INFERENCE_CACHES_RETRACT = NULL;

Symbol* SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINEDp = NULL;

Keyword* KWD_INFERENCE_CACHES_PERFORMANCE_CLUES = NULL;

Keyword* KWD_INFERENCE_CACHES_MODULE = NULL;

Keyword* KWD_INFERENCE_CACHES_FORCEp = NULL;

Keyword* KWD_INFERENCE_CACHES_FORCE = NULL;

Surrogate* SGT_INFERENCE_CACHES_STELLA_MODULE = NULL;

Surrogate* SGT_INFERENCE_CACHES_STELLA_BOOLEAN = NULL;

Symbol* SYM_INFERENCE_CACHES_LOGIC_STARTUP_INFERENCE_CACHES = NULL;

Symbol* SYM_INFERENCE_CACHES_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
