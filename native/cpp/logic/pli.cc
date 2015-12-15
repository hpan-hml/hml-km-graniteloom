//  -*- Mode: C++ -*-

// pli.cc

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

namespace pli {
  using namespace stella;
  using namespace logic;

boolean oPOWERLOOM_INITIALIZEDpo = false;

void initialize() {
  // Initialize the PowerLoom logic system.  This function
  // needs to be called by all applications before using PowerLoom.  If it
  // is called more than once, every call after the first one is a no-op.
  // Should be synchronized on process lock oBOOTSTRAP_LOCKo
  {
    if (!oPOWERLOOM_INITIALIZEDpo) {
      startupLogicSystem();
    }
  }
}

void resetPowerloom() {
  // Reset PowerLoom to its initial state.
  // CAUTION: This will destroy all loaded knowledge bases and might break other
  // loaded STELLA systems if they do reference PowerLoom symbols in their code.
  // Should be synchronized on process lock oPOWERLOOM_LOCKo
  {
    logic::resetPowerloom();
  }
}

void clearCaches() {
  // Clear all query and memoization caches.
  // Should be synchronized on process lock oPOWERLOOM_LOCKo
  {
    logic::clearCaches();
  }
}

Environment* newEnvironment() {
  { Environment* self = NULL;

    self = new Environment();
    self->level = NULL;
    return (self);
  }
}

Surrogate* Environment::primaryType() {
  { Environment* self = this;

    return (SGT_PLI_PLI_ENVIRONMENT);
  }
}

Object* accessEnvironmentSlotValue(Environment* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_PLI_LOGIC_LEVEL) {
    if (setvalueP) {
      self->level = ((StringWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapString(self->level);
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

void Environment::printObject(std::ostream* stream) {
  { Environment* self = this;

    *(stream) << "|ENV|" << self->level;
  }
}

Environment* ASSERTION_ENV = NULL;

Environment* TAXONOMIC_ENV = NULL;

Environment* INFERENCE_ENV = NULL;

PlIterator* newPlIterator() {
  { PlIterator* self = NULL;

    self = new PlIterator();
    self->firstIterationP = true;
    self->value = NULL;
    self->cursor = NULL;
    return (self);
  }
}

Surrogate* PlIterator::primaryType() {
  { PlIterator* self = this;

    return (SGT_PLI_PLI_PL_ITERATOR);
  }
}

Object* accessPlIteratorSlotValue(PlIterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_PLI_STELLA_CURSOR) {
    if (setvalueP) {
      self->cursor = ((Cons*)(value));
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

boolean PlIterator::nextP() {
  // Advance the PL-Iterator `self' and return `true' if more
  // elements are available, `false' otherwise.
  { PlIterator* self = this;

    { Cons* cursor = self->cursor;

      if (cursor == NIL) {
        self->value = NULL;
        return (false);
      }
      self->value = cursor->value;
      self->cursor = cursor->rest;
      return (true);
    }
  }
}

boolean PlIterator::emptyP() {
  // Return TRUE if the iterator `self' has no more elements.
  { PlIterator* self = this;

    return (self->cursor == NIL);
  }
}

int PlIterator::length() {
  // Number of items remaining in `self'.  Non destructive.
  { PlIterator* self = this;

    return (self->cursor->length());
  }
}

// Iterator that generates no values.
PlIterator* EMPTY_PL_ITERATOR = NULL;

PlIterator* consToPlIterator(Cons* self) {
  // Convert a Stella cons list into an API iterator.
  if (self == NIL) {
    return (EMPTY_PL_ITERATOR);
  }
  else {
    { PlIterator* self000 = newPlIterator();

      self000->cursor = self;
      { PlIterator* value000 = self000;

        return (value000);
      }
    }
  }
}

PlIterator* listToPlIterator(List* self) {
  // Convert a Stella list into an API iterator.
  if (self->emptyP()) {
    return (EMPTY_PL_ITERATOR);
  }
  else {
    return (consToPlIterator(self->theConsList));
  }
}

PlIterator* iteratorToPlIterator(Iterator* self) {
  // Convert an arbitrary Stella iterator into an API iterator.
  return (consToPlIterator(self->consify()));
}

List* PlIterator::listify() {
  // Convert `self' into a Stella LIST.
  { PlIterator* self = this;

    { List* self000 = newList();

      { Cons* value001 = NIL;

        { Object* x = NULL;
          PlIterator* iter000 = self;
          Cons* collect000 = NULL;

          for  (x, iter000, collect000; 
                iter000->nextP(); ) {
            x = iter000->value;
            if (!((boolean)(collect000))) {
              {
                collect000 = cons(x, NIL);
                if (value001 == NIL) {
                  value001 = collect000;
                }
                else {
                  addConsToEndOfConsList(value001, collect000);
                }
              }
            }
            else {
              {
                collect000->rest = cons(x, NIL);
                collect000 = collect000->rest;
              }
            }
          }
        }
        self000->theConsList = value001;
      }
      { List* value000 = self000;

        return (value000);
      }
    }
  }
}

Cons* PlIterator::consify() {
  // Convert `self' into a Stella CONS.
  { PlIterator* self = this;

    { Cons* value000 = NIL;

      { Object* x = NULL;
        PlIterator* iter000 = self;
        Cons* collect000 = NULL;

        for  (x, iter000, collect000; 
              iter000->nextP(); ) {
          x = iter000->value;
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(x, NIL);
              if (value000 == NIL) {
                value000 = collect000;
              }
              else {
                addConsToEndOfConsList(value000, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(x, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      { Cons* value001 = value000;

        return (value001);
      }
    }
  }
}

Object* safelyGetObject(char* name, Module* module, Environment* environment) {
  if (name == NULL) {
    return (NULL);
  }
  { Object* object = getObject(name, module, environment);

    if (!((boolean)(object))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Can't find an object named " << "`" << name << "'";
        throw *newNoSuchObjectException(stream000->theStringReader());
      }
    }
    else {
      return (object);
    }
  }
}

Object* safelyGetConcept(char* name, Module* module, Environment* environment) {
  if (name == NULL) {
    return (NULL);
  }
  { LogicObject* object = getConcept(name, module, environment);

    if (!((boolean)(object))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Can't find a concept named " << "`" << name << "'";
        throw *newNoSuchObjectException(stream000->theStringReader());
      }
    }
    else {
      return (object);
    }
  }
}

Object* safelyGetRelation(char* name, Module* module, Environment* environment) {
  if (name == NULL) {
    return (NULL);
  }
  { LogicObject* object = getRelation(name, module, environment);

    if (!((boolean)(object))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Can't find a relation named " << "`" << name << "'";
        throw *newNoSuchObjectException(stream000->theStringReader());
      }
    }
    else {
      return (object);
    }
  }
}

Context* safelyGetModule(char* name, Environment* environment) {
  environment = environment;
  if ((name == NULL) ||
      stringEqlP(name, "")) {
    return (oMODULEo.get());
  }
  return (getStellaModule(name, true));
}

Object* safelyGetObjectOrNull(char* name, Module* module, Environment* environment) {
  if ((!((boolean)(module))) ||
      ((name == NULL) ||
       (stringEqlP(name, "") ||
        stringEqualP(name, "null")))) {
    return (NULL);
  }
  try {
    return (getObject(name, module, environment));
  }
  catch (NoSuchObjectException ) {
    return (NULL);
  }
}

Cons* sequenceToConsList(Object* sequence) {
  { Surrogate* testValue000 = safePrimaryType(sequence);

    if (testValue000 == SGT_PLI_STELLA_CONS) {
      { Object* sequence000 = sequence;
        Cons* sequence = ((Cons*)(sequence000));

        return (sequence);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_LIST)) {
      { Object* sequence001 = sequence;
        List* sequence = ((List*)(sequence001));

        return (sequence->theConsList);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_VECTOR)) {
      { Object* sequence002 = sequence;
        Vector* sequence = ((Vector*)(sequence002));

        { Cons* result = NIL;

          { int i = NULL_INTEGER;
            int iter000 = 0;
            int upperBound000 = sequence->length();
            Cons* collect000 = NULL;

            for  (i, iter000, upperBound000, collect000; 
                  iter000 <= upperBound000; 
                  iter000 = iter000 + 1) {
              i = iter000;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons((sequence->theArray)[i], NIL);
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
                  collect000->rest = cons((sequence->theArray)[i], NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
          return (result);
        }
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Don't know how to convert object of type " << "`" << sequence->primaryType() << "'" << " into a cons list.";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Cons* explodeStringList(char* stringlist, Module* module) {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, module);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    { Cons* expression = ((Cons*)(readSExpressionFromString(stringlist)));
      Object* term = NULL;
      Cons* result = NIL;

      { Object* ref = NULL;
        Cons* iter000 = expression;
        Cons* collect000 = NULL;

        for  (ref, iter000, collect000; 
              !(iter000 == NIL); 
              iter000 = iter000->rest) {
          ref = iter000->value;
          term = ((ref == SYM_PLI_STELLA_NULL) ? NULL : evaluateTerm(ref));
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(term, NIL);
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
              collect000->rest = cons(term, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      return (result);
    }
  }
}

boolean legalOperatorP(Symbol* operatoR) {
  return (oKIF_SENTENCE_OPERATORSo->memberP(operatoR) ||
      (oKIF_TERM_OPERATORSo->memberP(operatoR) ||
       getQuotedTree("((<=>> <<=> <<=>> <~> <~>> <<~> <<~>> ABOUT <<= =>> <~ ~> <<~ ~>>) \"/PLI\")", "/PLI")->memberP(operatoR)));
}

Keyword* getKeyword(char* name) {
  // Returns the Stella KEYWORD `name' if it exists.  Case sensitive.
  return (lookupKeyword(name));
}

Symbol* getSymbol(char* name, Module* module, Environment* environment) {
  // Returns the Stella SYMBOL `name' visible in `module' if it
  // exists.  `name' is ALWAYS treated case sensitively.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (lookupSymbol(name));
      }
    }
  }
}

Symbol* getOperator(char* name) {
  // Returns the logical operator object (a Stella SYMBOL) for `name'.
  // If no such operator exists then a `no-such-object' exception is thrown.
  if (!(allUpperCaseStringP(name))) {
    name = stringUpcase(name);
  }
  { Symbol* operatoR = lookupSymbolInModule(name, oLOGIC_MODULEo, false);

    if (((boolean)(operatoR)) &&
        legalOperatorP(operatoR)) {
      return (operatoR);
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "No operator named " << "`" << name << "'";
        throw *newNoSuchObjectException(stream000->theStringReader());
      }
    }
  }
}

Object* getObject(char* name, Module* module, Environment* environment) {
  // Look for an object named `name' that is local to
  // or visible from the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (getInstance(internStellaName(name)));
      }
    }
  }
}

Object* sGetObject(char* name, char* moduleName, Environment* environment) {
  // Look for an object named `name' that is local to
  // or visible from the module `module-name'.  A module name of `null' or the
  // empty string refers to the current module.  If no module can be found
  // with the name `module-name', then a Stella `no-such-context-exception' is thrown.
  return (getObject(name, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

LogicObject* getConcept(char* name, Module* module, Environment* environment) {
  // Return a class/concept named `name' that is local to
  // or visible from the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (getClass(internStellaName(name)));
      }
    }
  }
}

LogicObject* sGetConcept(char* name, char* moduleName, Environment* environment) {
  // Return a class/concept named `name' that is local to
  // or visible from the module `module-name'.  A module name of `null' or the
  // empty string refers to the current module.  If no module can be found
  // with the name `module-name', then a Stella `no-such-context-exception' is thrown.
  return (getConcept(name, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

LogicObject* getRelation(char* name, Module* module, Environment* environment) {
  // Return a concept or relation named `name' that is local to
  // or visible from the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (logic::getRelation(internStellaName(name)));
      }
    }
  }
}

LogicObject* sGetRelation(char* name, char* moduleName, Environment* environment) {
  // Return a concept or relation named `name' that is local to
  // or visible from the module `module-name'.  A module name of `null' or the
  // empty string refers to the current module.  If no module can be found
  // with the name `module-name', then a Stella `no-such-context-exception' is thrown.
  return (getRelation(name, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

char* getNameInModule(Object* obj, Module* module, Environment* environment) {
  // Return the name, qualified as necessary, so that `obj' can be found from
  // `module'.  If there is no name for the object return `null'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { Surrogate* testValue000 = safePrimaryType(obj);

          if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
            { Object* obj000 = obj;
              Skolem* obj = ((Skolem*)(obj000));

              return (NULL);
            }
          }
          else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
            { Object* obj001 = obj;
              LogicObject* obj = ((LogicObject*)(obj001));

              return (stringify(objectName(obj)));
            }
          }
          else if (subtypeOfP(testValue000, SGT_PLI_STELLA_GENERALIZED_SYMBOL)) {
            { Object* obj002 = obj;
              GeneralizedSymbol* obj = ((GeneralizedSymbol*)(obj002));

              return (stringify(obj));
            }
          }
          else if (subtypeOfP(testValue000, SGT_PLI_STELLA_MODULE)) {
            { Object* obj003 = obj;
              Module* obj = ((Module*)(obj003));

              return (obj->moduleFullName);
            }
          }
          else if (subtypeOfP(testValue000, SGT_PLI_STELLA_CONTEXT)) {
            { Object* obj004 = obj;
              Context* obj = ((Context*)(obj004));

              return (obj->contextName());
            }
          }
          else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_COMPUTED_PROCEDURE)) {
            { Object* obj005 = obj;
              ComputedProcedure* obj = ((ComputedProcedure*)(obj005));

              return (stringify(obj->surrogateValueInverse));
            }
          }
          else {
            return (NULL);
          }
        }
      }
    }
  }
}

char* getName(Object* obj) {
  // Return the fully qualified name of `obj', if it has one.  Otherwise return `null'.
  return (getNameInModule(obj, oROOT_MODULEo, NULL));
}

char* getShortName(Object* obj) {
  // Return the short name of `obj', if it has one.  Otherwise return `null'.
  { Surrogate* testValue000 = safePrimaryType(obj);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
      { Object* obj000 = obj;
        Skolem* obj = ((Skolem*)(obj000));

        return (NULL);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
      { Object* obj001 = obj;
        LogicObject* obj = ((LogicObject*)(obj001));

        return (objectNameString(obj));
      }
    }
    else if (subtypeOfKeywordP(testValue000)) {
      { Object* obj002 = obj;
        Keyword* obj = ((Keyword*)(obj002));

        return (stringConcatenate(":", obj->symbolName, 0));
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_GENERALIZED_SYMBOL)) {
      { Object* obj003 = obj;
        GeneralizedSymbol* obj = ((GeneralizedSymbol*)(obj003));

        return (obj->symbolName);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_CONTEXT)) {
      { Object* obj004 = obj;
        Context* obj = ((Context*)(obj004));

        return (obj->contextName());
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_COMPUTED_PROCEDURE)) {
      { Object* obj005 = obj;
        ComputedProcedure* obj = ((ComputedProcedure*)(obj005));

        return (obj->surrogateValueInverse->symbolName);
      }
    }
    else {
      return (NULL);
    }
  }
}

char* objectToString(Object* self) {
  // Return a printed representation of the term `self' as a string.
  if (!((boolean)(self))) {
    return (NULL);
  }
  else {
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
      { Surrogate* testValue000 = safePrimaryType(self);

        if (subtypeOfStringP(testValue000)) {
          { Object* self000 = self;
            StringWrapper* self = ((StringWrapper*)(self000));

            return (self->wrapperValue);
          }
        }
        else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
          { Object* self001 = self;
            Skolem* self = ((Skolem*)(self001));

            { Object* value = valueOf(self);

              if (value == self) {
                return (stringify(self));
              }
              else {
                return (objectToString(value));
              }
            }
          }
        }
        else if (subtypeOfP(testValue000, SGT_PLI_PLI_PL_ITERATOR)) {
          { Object* self002 = self;
            PlIterator* self = ((PlIterator*)(self002));

            return (stringify(self->consify()));
          }
        }
        else {
          return (stringify(self));
        }
      }
    }
  }
}

int objectToInteger(Object* self) {
  // Coerce `self' to an integer, or throw a Stella Exception if the coersion is not feasible.
  // Floating point values will be coerced by rounding.
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
      { Object* self000 = self;
        Skolem* self = ((Skolem*)(self000));

        { Object* value = valueOf(self);

          if (value == self) {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "Can't coerce " << "`" << self << "'" << " to an integer.";
              throw *newStellaException(stream000->theStringReader());
            }
          }
          else {
            return (objectToInteger(value));
          }
        }
      }
    }
    else if (subtypeOfIntegerP(testValue000)) {
      { Object* self001 = self;
        IntegerWrapper* self = ((IntegerWrapper*)(self001));

        return (self->wrapperValue);
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { Object* self002 = self;
        FloatWrapper* self = ((FloatWrapper*)(self002));

        return (stella::round(self->wrapperValue));
      }
    }
    else {
      { OutputStringStream* stream001 = newOutputStringStream();

        *(stream001->nativeStream) << "Can't coerce " << "`" << self << "'" << " to an integer.";
        throw *newStellaException(stream001->theStringReader());
      }
    }
  }
}

double objectToFloat(Object* self) {
  // Coerce `self' to a float, or throw a Stella Exception if the coersion is not feasible.
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
      { Object* self000 = self;
        Skolem* self = ((Skolem*)(self000));

        { Object* value = valueOf(self);

          if (value == self) {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "Can't coerce " << "`" << self << "'" << " to a float.";
              throw *newStellaException(stream000->theStringReader());
            }
          }
          else {
            return (objectToFloat(value));
          }
        }
      }
    }
    else if (subtypeOfIntegerP(testValue000)) {
      { Object* self001 = self;
        IntegerWrapper* self = ((IntegerWrapper*)(self001));

        return (self->numberWrapperToFloat());
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { Object* self002 = self;
        FloatWrapper* self = ((FloatWrapper*)(self002));

        return (self->wrapperValue);
      }
    }
    else {
      { OutputStringStream* stream001 = newOutputStringStream();

        *(stream001->nativeStream) << "Can't coerce " << "`" << self << "'" << " to a float.";
        throw *newStellaException(stream001->theStringReader());
      }
    }
  }
}

char* objectToParsableString(Object* self) {
  // Return a string representing a printed
  // representation of the object `self'.  Like `object-to-string', but puts
  // escaped double quotes around strings.
  if (subtypeOfStringP(safePrimaryType(self))) {
    { Object* self000 = self;
      StringWrapper* self = ((StringWrapper*)(self000));

      return (stringConcatenate("\"", self->wrapperValue, 1, "\""));
    }
  }
  else {
    return (objectToString(self));
  }
}

NamedDescription* oLITERAL_CONCEPTo = NULL;

NamedDescription* oSTRING_CONCEPTo = NULL;

NamedDescription* oINTEGER_CONCEPTo = NULL;

NamedDescription* oFLOAT_CONCEPTo = NULL;

Object* stringToObject(char* string, LogicObject* type, Module* module, Environment* environment) {
  // Evaluate `string' with respect to `module' and `environment'
  // and return the corresponding logical term.  `type' is a concept used to assist the
  // correct interpretation of `string'.
  // 
  // Currently `type' only has an effect on the interpretation of literal types.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { Object* obj = readSExpressionFromString(string);

          if (subtypeOfP(safePrimaryType(obj), SGT_PLI_STELLA_LITERAL_WRAPPER)) {
            { Object* obj000 = obj;
              LiteralWrapper* obj = ((LiteralWrapper*)(obj000));

              if (!((boolean)(type))) {
                return (obj);
              }
              { Surrogate* testValue000 = safePrimaryType(obj);

                if (subtypeOfStringP(testValue000)) {
                  { LiteralWrapper* obj001 = obj;
                    StringWrapper* obj = ((StringWrapper*)(obj001));

                    if (subrelationOfP(((NamedDescription*)(type)), oSTRING_CONCEPTo)) {
                      return (obj);
                    }
                    else {
                      { OutputStringStream* stream000 = newOutputStringStream();

                        *(stream000->nativeStream) << "String argument found, but " << "`" << type << "'" << " is not a subconcept of " << "`" << oSTRING_CONCEPTo << "'";
                        throw *newParsingError(stream000->theStringReader());
                      }
                    }
                  }
                }
                else if (subtypeOfIntegerP(testValue000)) {
                  { LiteralWrapper* obj002 = obj;
                    IntegerWrapper* obj = ((IntegerWrapper*)(obj002));

                    if (subrelationOfP(((NamedDescription*)(type)), oINTEGER_CONCEPTo)) {
                      return (obj);
                    }
                    else if (subrelationOfP(((NamedDescription*)(type)), oFLOAT_CONCEPTo)) {
                      return (wrapFloat(((double)(obj->wrapperValue))));
                    }
                    else {
                      return (getObject(string, module, environment));
                    }
                  }
                }
                else if (subtypeOfFloatP(testValue000)) {
                  { LiteralWrapper* obj003 = obj;
                    FloatWrapper* obj = ((FloatWrapper*)(obj003));

                    if (subrelationOfP(((NamedDescription*)(type)), oFLOAT_CONCEPTo)) {
                      return (obj);
                    }
                    else {
                      return (getObject(string, module, environment));
                    }
                  }
                }
                else {
                  { OutputStringStream* stream001 = newOutputStringStream();

                    *(stream001->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
                    throw *newStellaException(stream001->theStringReader());
                  }
                }
              }
            }
          }
          else {
            if (!((boolean)(type))) {
              return (getObject(string, module, environment));
            }
            else if (subrelationOfP(((NamedDescription*)(type)), oSTRING_CONCEPTo)) {
              return (wrapString(string));
            }
            else if (subrelationOfP(((NamedDescription*)(type)), oLITERAL_CONCEPTo)) {
              { OutputStringStream* stream002 = newOutputStringStream();

                *(stream002->nativeStream) << "`" << string << "'" << " is a non-literal, but " << "`" << type << "'" << " is a subconcept of " << "`" << oLITERAL_CONCEPTo << "'";
                throw *newParsingError(stream002->theStringReader());
              }
            }
            else {
              return (getObject(string, module, environment));
            }
          }
        }
      }
    }
  }
}

Cons* helpGetTrueExtensionMembers(NamedDescription* relation, boolean specializeP) {
  { Cons* value000 = NIL;

    { Object* p = NULL;
      Iterator* iter000 = allExtensionMembers(relation);
      Cons* collect000 = NULL;

      for  (p, iter000, collect000; 
            iter000->nextP(); ) {
        p = iter000->value;
        if ((!((Proposition*)(p))->deletedP()) &&
            ((oREVERSEPOLARITYpo.get() ? falseP(((Proposition*)(p))) : (trueP(((Proposition*)(p))) ||
            functionWithDefinedValueP(((Proposition*)(p))))))) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(p, NIL);
              if (value000 == NIL) {
                value000 = collect000;
              }
              else {
                addConsToEndOfConsList(value000, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(p, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    { Cons* result = value000;

      if (specializeP) {
        { LogicObject* sub = NULL;
          Iterator* iter001 = allSubcollections(relation);

          for (sub, iter001; iter001->nextP(); ) {
            sub = ((LogicObject*)(iter001->value));
            if (isaP(sub, SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
              { Object* p = NULL;
                Iterator* iter002 = allExtensionMembers(((NamedDescription*)(sub)));

                for (p, iter002; iter002->nextP(); ) {
                  p = iter002->value;
                  if ((!((Proposition*)(p))->deletedP()) &&
                      ((oREVERSEPOLARITYpo.get() ? falseP(((Proposition*)(p))) : (trueP(((Proposition*)(p))) ||
                      functionWithDefinedValueP(((Proposition*)(p))))))) {
                    result = cons(p, result);
                  }
                }
              }
            }
          }
        }
        return (result->removeDuplicates());
      }
      return (result);
    }
  }
}

Cons* helpGetPropositions(LogicObject* relation, Cons* arguments, int limit, Module* module, Environment* environment) {
  if (!((boolean)(relation))) {
    return (NIL);
  }
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { boolean specializeP = !(environment == ASSERTION_ENV);

          { Object* value000 = NULL;

            { Object* arg = NULL;
              Cons* iter000 = arguments;

              for (arg, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
                arg = iter000->value;
                if (((boolean)(arg)) &&
                    isaP(arg, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
                  value000 = arg;
                  break;
                }
              }
            }
            { Object* argumentwithbacklinks = value000;
              Iterator* iterator = (((boolean)(argumentwithbacklinks)) ? ((Iterator*)(allTrueDependentPropositions(argumentwithbacklinks, relation->surrogateValueInverse, specializeP))) : helpGetTrueExtensionMembers(((NamedDescription*)(relation)), specializeP)->allocateIterator());
              Cons* results = NIL;

              { Proposition* p = NULL;
                Iterator* iter001 = iterator;

                for (p, iter001; iter001->nextP(); ) {
                  p = ((Proposition*)(iter001->value));
                  { boolean testValue000 = false;

                    { boolean alwaysP000 = true;

                      { Object* inputarg = NULL;
                        Cons* iter002 = arguments;
                        Object* arg2 = NULL;
                        Vector* vector000 = p->arguments;
                        int index000 = 0;
                        int length000 = vector000->length();

                        for  (inputarg, iter002, arg2, vector000, index000, length000; 
                              (!(iter002 == NIL)) &&
                                  (index000 < length000); 
                              iter002 = iter002->rest,
                              index000 = index000 + 1) {
                          inputarg = iter002->value;
                          arg2 = (vector000->theArray)[index000];
                          if (!((!((boolean)(inputarg))) ||
                              eqlP(inputarg, valueOf(arg2)))) {
                            alwaysP000 = false;
                            break;
                          }
                        }
                      }
                      testValue000 = alwaysP000;
                    }
                    if (testValue000) {
                      testValue000 = arguments->length() == p->arguments->length();
                    }
                    if (testValue000) {
                      results = cons(p, results);
                      limit = limit - 1;
                      if (limit == 0) {
                        break;
                      }
                    }
                  }
                }
              }
              return (results);
            }
          }
        }
      }
    }
  }
}

Proposition* getProposition(Object* relationAndArguments, Module* module, Environment* environment) {
  // Return a proposition matching `relation-and-arguments' that
  // has been asserted (or inferred by forward chaining).  `relation-and-arguments'
  // is a sequence containing objects and nulls.  The first argument must be the
  // name of a relation.  A null value acts like a wild card.  If more than one 
  // proposition matches the input criteria, the selection among satisficing
  // propositions is arbitrary.  This procedure is normally applied to single-valued
  // relations or functions.
  { Cons* list = sequenceToConsList(relationAndArguments);
    Object* relation = list->value;
    Cons* arguments = list->rest;

    return (((Proposition*)(helpGetPropositions(((LogicObject*)(relation)), arguments, 1, module, environment)->value)));
  }
}

Proposition* sGetProposition(char* relationAndArguments, char* moduleName, Environment* environment) {
  // Return a proposition matching `relation-and-arguments' that
  // has been asserted (or inferred by forward chaining).  `relation-and-arguments'
  // is a string that begins with a left parenthesis, followed by a relation name, 
  // one or more argument identifiers, and terminated by a right parenthesis.  Each
  // argument identifier can be the name of a logical constant, a literal
  // reference (e.g., a number), the null identifier, or a variable (an identifier that begins
  // with a question mark). Each occurrence of a null or a variable acts like a wild card.
  // If more than one proposition matches the input criteria, the selection among
  // satisficing propositions is arbitrary.  This procedure is normally applied to
  // single-valued relations or functions.
  // 
  // A module name of `null' or the
  // empty string refers to the current module.  If no module can be found
  // with the name `module-name', then a Stella `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Cons* elements = explodeStringList(relationAndArguments, ((Module*)(module)));
    Object* relation = elements->value;
    Cons* arguments = elements->rest;

    return (((Proposition*)(helpGetPropositions(((LogicObject*)(relation)), arguments, 1, ((Module*)(module)), environment)->value)));
  }
}

PlIterator* getPropositions(Object* relationAndArguments, Module* module, Environment* environment) {
  // Return propositions matching `relation-and-arguments' that
  // have been asserted (or inferred by forward chaining).  `relation-and-arguments'
  // is a sequence containing objects and nulls.  The first argument must be the
  // name of a relation.  A null value acts like a wild card.
  { Cons* list = sequenceToConsList(relationAndArguments);
    Object* relation = list->value;
    Cons* arguments = list->rest;

    return (consToPlIterator(helpGetPropositions(((LogicObject*)(relation)), arguments, 0, module, environment)));
  }
}

PlIterator* sGetPropositions(char* relationAndArguments, char* moduleName, Environment* environment) {
  // Return propositions matching `relation-and-arguments' that
  // have been asserted (or inferred by forward chaining).  `relation-and-arguments'
  // is a string that begins with a left parenthesis, followed by a relation name, 
  // one or more argument identifiers, and terminated by a right parenthesis.  Each
  // argument identifier can be the name of a logical constant, a literal 
  // reference (e.g., a number), the null identifier, or a variable (an identifier that begins
  // with a question mark). Each occurrence of a null or a variable acts like a wild card.
  // 
  // A module name of `null' or the
  // empty string refers to the current module.  If no module can be found
  // with the name `module-name', then a Stella `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Cons* elements = explodeStringList(relationAndArguments, ((Module*)(module)));
    Object* relation = elements->value;
    Cons* arguments = elements->rest;

    return (consToPlIterator(helpGetPropositions(((LogicObject*)(relation)), arguments, 0, ((Module*)(module)), environment)));
  }
}

Proposition* getBinaryProposition(LogicObject* relation, Object* arg1, Object* arg2, Module* module, Environment* environment) {
  // Return a proposition such that (`relation' `arg1' `arg2')
  // is true.  The `relation' argument must be bound to a relation.  One or both
  // of the `arg1' and `arg2' arguments may be set to NULL, which is interpreted
  // as a wildcard. If more than one proposition matches the input criteria,
  // the selection is arbitrary.  This procedure is normally applied to single-valued
  // relations or functions.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { LogicObject* argumentwithbacklinks = NULL;

          if (((boolean)(arg1)) &&
              isaP(arg1, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
            argumentwithbacklinks = ((LogicObject*)(arg1));
          }
          else if (((boolean)(arg2)) &&
              isaP(arg2, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
            argumentwithbacklinks = ((LogicObject*)(arg2));
          }
          if (((boolean)(argumentwithbacklinks))) {
            { Proposition* p = NULL;
              Iterator* iter000 = allTrueDependentPropositions(argumentwithbacklinks, relation->surrogateValueInverse, false);

              for (p, iter000; iter000->nextP(); ) {
                p = ((Proposition*)(iter000->value));
                if (((!((boolean)(arg1))) ||
                    eqlP(arg1, valueOf((p->arguments->theArray)[0]))) &&
                    ((!((boolean)(arg2))) ||
                     eqlP(arg2, valueOf((p->arguments->theArray)[1])))) {
                  return (p);
                }
              }
            }
          }
          else {
            return (((Proposition*)(helpGetPropositions(relation, consList(2, arg1, arg2), 1, module, environment)->value)));
          }
          return (NULL);
        }
      }
    }
  }
}

PlIterator* getBinaryPropositions(LogicObject* relation, Object* arg1, Object* arg2, Module* module, Environment* environment) {
  // Return propositions such that (`relation' `arg1' `arg2')
  // is true.  The `relation' argument
  // must be bound to a relation.  One or both of the `arg1' and `arg2' arguments
  // may be set to NULL, which is interpreted as a wildcard.
  return (consToPlIterator(helpGetPropositions(relation, consList(2, arg1, arg2), 0, module, environment)));
}

PlIterator* getInferredBinaryPropositionValues(LogicObject* relation, Object* arg, Module* module, Environment* environment) {
  // Return all values `v' such that (`relation' `arg' `v')
  // has been asserted or can be inferred.
  { Cons* dummy1;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (consToPlIterator(applyCachedRetrieve(listO(4, SYM_PLI_PLI_pR, SYM_PLI_PLI_pI, SYM_PLI_PLI_pV, NIL), listO(4, SYM_PLI_PLI_pR, SYM_PLI_PLI_pI, SYM_PLI_PLI_pV, NIL), consList(3, relation, arg, NULL), consList(0), SYM_PLI_PLI_F_GET_INFERRED_BINARY_PROPOSITION_VALUES_QUERY_000, dummy1)));
        }
      }
    }
  }
}

PlIterator* sGetInferredBinaryPropositionValues(char* relationName, char* argName, char* moduleName, Environment* environment) {
  // Return all values `v' such that (`relation-name' `arg-name' `v')
  // has been asserted or can be inferred.
  // 
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);
    Object* object = safelyGetObject(argName, ((Module*)(module)), environment);

    if (((boolean)(object)) &&
        ((boolean)(relation))) {
      return (getInferredBinaryPropositionValues(((LogicObject*)(relation)), object, ((Module*)(module)), environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

PlIterator* getPropositionsOf(LogicObject* object, Module* module, Environment* environment) {
  // Return all propositions that have `object' among their arguments,
  // and that are TRUE in the scope of the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (listToPlIterator(allFactsOfInstance(object, false, false)));
      }
    }
  }
}

PlIterator* sGetPropositionsOf(char* objectName, char* moduleName, Environment* environment) {
  // Return all propositions that have the object named `object-name' among
  // their arguments, and that are TRUE in the scope of the module `module-name'.
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* object = safelyGetObject(objectName, ((Module*)(module)), environment);

    if (((boolean)(object))) {
      return (getPropositionsOf(((LogicObject*)(object)), ((Module*)(module)), environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

PlIterator* getPropositionsInModule(Module* module, Environment* environment) {
  // Return propositions that have been conceived in
  // the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allPropositions(oMODULEo.get(), true)->consify()));
      }
    }
  }
}

boolean isTrueUnaryProposition(LogicObject* relation, Object* arg, Module* module, Environment* environment) {
  // Return TRUE if the proposition (`relation' `arg') has
  // been asserted (or inferred by forward chaining).
  return (((boolean)(helpGetPropositions(relation, consList(1, arg), 1, module, environment))));
}

boolean isTrueBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Environment* environment) {
  // Return TRUE if the proposition (`relation' `arg' `value') has
  // been asserted (or inferred by forward chaining).
  return (((boolean)(getBinaryProposition(relation, arg, value, module, environment))));
}

boolean isTrueProposition1(Object* relationAndArguments, Module* module, Environment* environment) {
  // Return TRUE if a proposition (`relation' `args') has
  // been asserted (or inferred by forward chaining).
  { Cons* list = sequenceToConsList(relationAndArguments);
    Object* relation = list->value;
    Cons* arguments = list->rest;

    return (((boolean)(helpGetPropositions(((LogicObject*)(relation)), arguments, 1, module, environment))));
  }
}

boolean isTrueProposition(Proposition* proposition, Module* module, Environment* environment) {
  // Return TRUE if `proposition' is  TRUE in the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return ((!proposition->deletedP()) &&
            ((oREVERSEPOLARITYpo.get() ? falseP(proposition) : (trueP(proposition) ||
            functionWithDefinedValueP(proposition)))));
      }
    }
  }
}

boolean sIsTrueProposition(char* relationAndArguments, char* moduleName, Environment* environment) {
  // Return TRUE if a proposition that prints as the string
  // `relation-and-arguments' is true in the module named `module-name'.
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  return (((boolean)(sGetProposition(relationAndArguments, moduleName, environment))));
}

boolean isSubrelation(LogicObject* sub, LogicObject* super, Module* module, Environment* environment) {
  // Return TRUE if `sub' is a subconcept/subrelation of `super'.
  if ((!((boolean)(sub))) ||
      (!((boolean)(super)))) {
    return (false);
  }
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (trueTruthValueP(descriptionSpecializesDescriptionP(((Description*)(sub)), ((Description*)(super)))));
      }
    }
  }
}

PlIterator* getProperSubrelations(LogicObject* relation, Module* module, Environment* environment) {
  // Return relations that specialize `relation'.
  // Non-reflexive.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allSubrelations(((NamedDescription*)(relation)), true)));
      }
    }
  }
}

PlIterator* getDirectSubrelations(LogicObject* relation, Module* module, Environment* environment) {
  // Return relations that directly specialize `relation'.
  // Non-reflexive.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allDirectSubrelations(((NamedDescription*)(relation)), true)));
      }
    }
  }
}

PlIterator* getProperSuperrelations(LogicObject* relation, Module* module, Environment* environment) {
  // Return relations that generalize `relation'.
  // Non-reflexive.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allSuperrelations(((NamedDescription*)(relation)), true)));
      }
    }
  }
}

PlIterator* getDirectSuperrelations(LogicObject* relation, Module* module, Environment* environment) {
  // Return relations that directly generalize `relation'.
  // Non-reflexive.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allDirectSuperrelations(((NamedDescription*)(relation)), true)));
      }
    }
  }
}

boolean isA(Object* object, LogicObject* concept, Module* module, Environment* environment) {
  // Return TRUE if `object' is a member of the concept `concept'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (testIsaP(object, concept->surrogateValueInverse));
      }
    }
  }
}

PlIterator* getConceptInstances(LogicObject* concept, Module* module, Environment* environment) {
  // Return instances of the concept `concept'.
  // Include instances of subconcepts of `concept'.  Depending on `concept',
  // the return values could be (wrapped) literals.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        if (((boolean)(environment)) &&
            stringEqlP(environment->level, "ASSERTION")) {
          return (listToPlIterator(assertedCollectionMembers(concept, false)->removeDeletedMembers()));
        }
        else {
          return (retrieve(listO(4, SYM_PLI_LOGIC_ALL, SYM_PLI_LOGIC_pX, cons(objectName(concept), cons(SYM_PLI_LOGIC_pX, NIL)), NIL), module, environment));
        }
      }
    }
  }
}

PlIterator* sGetConceptInstances(char* conceptName, char* moduleName, Environment* environment) {
  // Return instances of concept `concept-name'.
  // Include instances of subconcepts of `concept-name'.  Depending on `concept-name',
  // the return values could be (wrapped) literals.
  // 
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* concept = safelyGetConcept(conceptName, ((Module*)(module)), environment);

    if (((boolean)(concept))) {
      return (getConceptInstances(((LogicObject*)(concept)), ((Module*)(module)), environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

PlIterator* getDirectConceptInstances(LogicObject* concept, Module* module, Environment* environment) {
  // Return instances of concept `concept'.
  // Exclude instances of subconcepts of `concept'.  Depending on `concept',
  // the return values could be (wrapped) literals.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        if (((boolean)(environment)) &&
            stringEqlP(environment->level, "ASSERTION")) {
          return (listToPlIterator(assertedCollectionMembers(concept, true)->removeDeletedMembers()));
        }
        else {
          return (retrieve(listO(4, SYM_PLI_LOGIC_ALL, SYM_PLI_LOGIC_pX, listO(4, SYM_PLI_STELLA_AND, cons(objectName(concept), cons(SYM_PLI_LOGIC_pX, NIL)), listO(3, SYM_PLI_LOGIC_FAIL, listO(4, SYM_PLI_STELLA_EXISTS, cons(SYM_PLI_LOGIC_pY, NIL), listO(4, SYM_PLI_STELLA_AND, listO(3, SYM_PLI_PLI_PROPER_SUBRELATION, objectName(concept), cons(SYM_PLI_LOGIC_pY, NIL)), listO(3, SYM_PLI_LOGIC_pY, SYM_PLI_LOGIC_pX, NIL), NIL), NIL), NIL), NIL), NIL), module, environment));
        }
      }
    }
  }
}

PlIterator* sGetDirectConceptInstances(char* conceptName, char* moduleName, Environment* environment) {
  // Return instances of concept `concept-name'.
  // Exclude instances of subconcepts of `concept-name'.  Depending on `concept-name',
  // the return values could be (wrapped) literals.
  // 
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* concept = safelyGetConcept(conceptName, ((Module*)(module)), environment);

    if (((boolean)(concept))) {
      return (getDirectConceptInstances(((LogicObject*)(concept)), ((Module*)(module)), environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

PlIterator* getConceptInstancesMatchingValue(LogicObject* concept, LogicObject* relation, Object* value, Module* module, Environment* environment) {
  // Return members of concept `concept' that
  // have an attribute matching `value' for the binary relation `relation', i.e.,
  // `(relation <result> value)' holds.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { PlIterator* instances = getConceptInstances(concept, module, environment);
          Cons* answers = NIL;

          { Object* i = NULL;
            PlIterator* iter000 = instances;

            for (i, iter000; iter000->nextP(); ) {
              i = iter000->value;
              if (isTrueBinaryProposition(relation, i, value, module, environment)) {
                answers = cons(i, answers);
              }
            }
          }
          return (consToPlIterator(answers));
        }
      }
    }
  }
}

Object* getConceptInstanceMatchingValue(LogicObject* concept, LogicObject* relation, Object* value, Module* module, Environment* environment) {
  // Return a member of concept `concept' that
  // has an attribute matching `value' for the binary relation `relation', i.e.,
  // `(relation <result> value)' holds.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { PlIterator* instances = getConceptInstances(concept, module, environment);

          { Object* i = NULL;
            PlIterator* iter000 = instances;

            for (i, iter000; iter000->nextP(); ) {
              i = iter000->value;
              if (isTrueBinaryProposition(relation, i, value, module, environment)) {
                return (i);
              }
            }
          }
          return (NULL);
        }
      }
    }
  }
}

PlIterator* getTypes(LogicObject* object, Module* module, Environment* environment) {
  // Return all named concepts that `object' belongs to.
  { PlIterator* directtypes = getDirectTypes(object, module, environment);
    Cons* types = NIL;

    { LogicObject* d = NULL;
      PlIterator* iter000 = directtypes;

      for (d, iter000; iter000->nextP(); ) {
        d = ((LogicObject*)(iter000->value));
        if (!types->memberP(d)) {
          types = cons(d, types);
        }
        { LogicObject* c = NULL;
          Iterator* iter001 = allSupercollections(d);

          for (c, iter001; iter001->nextP(); ) {
            c = ((LogicObject*)(iter001->value));
            if (isaP(c, SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
              if (!types->memberP(c)) {
                types = cons(c, types);
              }
            }
          }
        }
      }
    }
    return (consToPlIterator(types));
  }
}

PlIterator* getDirectTypes(LogicObject* object, Module* module, Environment* environment) {
  // Return most specific concepts that `object' belongs to.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { Cons* derivabletypes = NIL;

          { Proposition* prop = NULL;
            Iterator* iter000 = allTrueDependentPropositions(object, NULL, false);

            for (prop, iter000; iter000->nextP(); ) {
              prop = ((Proposition*)(iter000->value));
              if (prop->kind == KWD_PLI_ISA) {
                derivabletypes = cons(getNthValue(prop, 0, module, environment), derivabletypes);
              }
            }
          }
          return (consToPlIterator(mostSpecificNamedDescriptions(derivabletypes)));
        }
      }
    }
  }
}

PlIterator* getRelationExtension(LogicObject* relation, Module* module, Environment* environment) {
  // Return propositions that satisfy `relation'.
  // Include propositions that satisfy subrelations of `relation'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(helpGetTrueExtensionMembers(((NamedDescription*)(relation)), !(environment == ASSERTION_ENV))));
      }
    }
  }
}

PlIterator* sGetRelationExtension(char* relationName, Module* module, Environment* environment) {
  // Return propositions that satisfy the relation named
  // `relation-name'.  Include propositions that satisfy subrelations of the relation.
  { Object* relation = safelyGetRelation(relationName, module, environment);

    if (((boolean)(relation))) {
      return (getRelationExtension(((LogicObject*)(relation)), module, environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

Module* getModule(char* name, Environment* environment) {
  // Return a module named `name'.
  environment = environment;
  return (getStellaModule(name, false));
}

Module* getCurrentModule(Environment* environment) {
  // Return the currently set module
  environment = environment;
  return (oMODULEo.get());
}

Module* getHomeModule(LogicObject* object) {
  // Return the module in which `object' was created.
  return (object->homeModule());
}

PlIterator* getModules(boolean kbModulesOnlyP) {
  // Return all modules currently loaded into PowerLoom.  If `kb-modules-only?'
  // is `true', then Stella modules that are used only for program code are
  // not included in the list.
  return (consToPlIterator(listModules(kbModulesOnlyP)));
}

Module* createModule(char* name, Module* parent, boolean caseSensitiveP) {
  // Creates a new module `name' as a child of `parent'.  The flag
  // `case-sensitive?' controls whether names read in this module will be
  // case sensitive or not.
  { char* fullName = (((boolean)(parent)) ? stringConcatenate(parent->moduleFullName, "/", 1, name) : name);
    Symbol* caseSensitiveSymbol = (caseSensitiveP ? SYM_PLI_STELLA_TRUE : SYM_PLI_STELLA_FALSE);

    return (defineModule(fullName, listO(3, KWD_PLI_CASE_SENSITIVEp, caseSensitiveSymbol, NIL)));
  }
}

Module* sCreateModule(char* name, char* parentName, boolean caseSensitiveP, Environment* environment) {
  // Creates a new module `name' as a child of `parent-name'.  The flag
  // `case-sensitive?' controls whether names read in this module will be
  // case sensitive or not.
  return (createModule(name, ((Module*)(safelyGetModule(parentName, environment))), caseSensitiveP));
}

Module* changeModule(Module* module) {
  // Set the current module to `module' and return it.
  // If `module' is `null', then no switch is performed and the current
  // module is returned.
  if (!((boolean)(module))) {
    return (oMODULEo.get());
  }
  return (module->changeModule());
}

Module* sChangeModule(char* name, Environment* environment) {
  // Set the current module to the module named `name'.
  // The return value is the module named `name' unless `name' is null or
  // the empty string.  In that case, the current module is returned.
  // If no module named `name' exists, a Stella `no-such-context-exception'
  // is thrown.
  return (changeModule(((Module*)(safelyGetModule(name, environment)))));
}

Module* clearModule(Module* module) {
  // Destroy the contents of the module `module' as well as
  // the contents of all of its children, recursively.
  callClearModule(consList(1, module));
  return (module);
}

Module* sClearModule(char* name, Environment* environment) {
  // Destroy the contents of the module named `name', as
  // well as the contents of all of its children, recursively.  If no module
  // named `name' exists, a Stella `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(name, environment);

    callClearModule(consList(1, module));
    return (((Module*)(module)));
  }
}

PlIterator* getChildModules(Module* module) {
  // Return the modules that are immediate children of `module'.
  { Cons* directsubmodules = NIL;

    { Context* child = NULL;
      Cons* iter000 = module->childContexts->theConsList;
      Cons* collect000 = NULL;

      for  (child, iter000, collect000; 
            !(iter000 == NIL); 
            iter000 = iter000->rest) {
        child = ((Context*)(iter000->value));
        if (isaP(child, SGT_PLI_STELLA_MODULE)) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(child, NIL);
              if (directsubmodules == NIL) {
                directsubmodules = collect000;
              }
              else {
                addConsToEndOfConsList(directsubmodules, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(child, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    return (consToPlIterator(directsubmodules));
  }
}

PlIterator* sGetChildModules(char* name, Environment* environment) {
  // Return the modules that are immediate children of module `name'.
  // If no module named `name' exists, a Stella `no-such-context-exception'
  // is thrown.
  return (getChildModules(((Module*)(safelyGetModule(name, environment)))));
}

PlIterator* getParentModules(Module* module) {
  // Return the modules that are immediate parents of `module'.
  return (listToPlIterator(module->parentModules));
}

PlIterator* sGetParentModules(char* name, Environment* environment) {
  // Return the modules that are immediate parents of module `name'.
  // If no module named `name' exists, a Stella `no-such-context-exception'
  // is thrown.
  return (getParentModules(((Module*)(safelyGetModule(name, environment)))));
}

char* generateUniqueName(char* prefix, Module* module, Environment* environment) {
  // Generates a name based on `prefix' with a number appended that
  // is not currently in use in `module.'  In a non-case-sensitive module, the returned
  // name will be all upper case (This latter feature may change!)
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        if (!(oMODULEo.get()->caseSensitiveP ||
            allUpperCaseStringP(prefix))) {
          prefix = stringUpcase(prefix);
        }
        return (yieldUniqueGensymName(prefix, oMODULEo.get()));
      }
    }
  }
}

Keyword* createKeyword(char* name) {
  // Returns the Stella keyword `name', creating it if
  // necessary.  `name' is treated case-sensitively.  This should
  // generally not be necessary to do.
  return (((Keyword*)(internRigidSymbolWrtModule(name, oMODULEo.get(), KEYWORD_SYM))));
}

Symbol* createSymbol(char* name, Module* module, Environment* environment) {
  // Returns the Stella symbol `name' visible in `module',
  // creating it if necessary.  `name' is ALWAYS treated case-sensitively,
  // even if `module' is case insensitive. This should generally not be
  // necessary to do.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (internSymbolInModule(name, oMODULEo.get(), false));
      }
    }
  }
}

LogicObject* createObject(char* name, LogicObject* concept, Module* module, Environment* environment) {
  // Create an object named `name' of type `concept' in the designated
  // module.  Both `name' and `concept' can be `null'.  If `name' is `null' then an
  // object will be created with a new, non-conflicting name based on the name of
  // `concept', or system-generated if no concept is specified.  If `concept' is
  // `null', then the object will be of type THING.  It is an error to create an
  // object with the same name as an existing object.
  // 
  // Note that the string can be a qualified name, in which case the object
  // will be created in the module specified, but with a name as determined
  // by the qualified name.  Vertical bars in the name string are interpreted
  // as Stella escape characters.
  // 
  // Note that because names in modules that are not case-sensitive are
  // canonicalized, the name of the returned object may not match `name'
  // exactly.
  // 
  // Return the object.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { LogicObject* object = NULL;
          Symbol* nameSymbol = NULL;
          Surrogate* objectSurrogate = NULL;

          if (name != NULL) {
            nameSymbol = ((Symbol*)(internStellaName(name)));
          }
          else if (((boolean)(concept))) {
            nameSymbol = internSymbol(getShortName(concept));
            nameSymbol = internSymbolInModule(generateUniqueName(nameSymbol->symbolName, ((Module*)(nameSymbol->homeContext)), NULL), ((Module*)(nameSymbol->homeContext)), true);
          }
          else {
            nameSymbol = internSymbolInModule(generateUniqueName("I", NULL, NULL), oMODULEo.get(), true);
          }
          objectSurrogate = lookupSurrogateInModule(nameSymbol->symbolName, ((Module*)(nameSymbol->homeContext)), false);
          if (!((boolean)(objectSurrogate))) {
            objectSurrogate = internSurrogateInModule(nameSymbol->symbolName, ((Module*)(nameSymbol->homeContext)), false);
          }
          object = ((LogicObject*)(helpCreateLogicInstance(objectSurrogate, NULL)));
          if (((boolean)(concept))) {
            if (((boolean)(assertUnaryProposition(concept, object, module, environment)))) {
              return (object);
            }
            else {
              return (NULL);
            }
          }
          return (object);
        }
      }
    }
  }
}

LogicObject* sCreateObject(char* name, char* conceptName, char* moduleName, Environment* environment) {
  // Create an object named `name' of type `concept-name' in the designated
  // module.  Both `name' and `concept-name' can be null strings.  If `name' is a null string
  // then an object will be created with a new, non-conflicting name based on `concept-name', or
  // system-generated if no concept nameis specified.  If `concept-name' is the null string, then
  // the object will be of type THING.
  // 
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  // 
  // Note that because names in modules that are not case-sensitive are canonicalized,
  // the name of the returned object may not match `name' exactly.
  // 
  // Return the object.
  { Context* module = safelyGetModule(moduleName, environment);

    return (createObject(name, ((LogicObject*)(safelyGetConcept(conceptName, ((Module*)(module)), environment))), ((Module*)(module)), environment));
  }
}

LogicObject* createConcept(char* name, LogicObject* parent, Module* module, Environment* environment) {
  // Create a concept named `name' in the designated `module', with the
  // designated `parent' superconcept (which can be left undefined).  Additional
  // superconcepts can be added via assertions of the `subset-of' relation.  Note
  // that a specified `parent' concept needs to be created separately.
  // 
  // Note that because names in modules that are not case-sensitive are canonicalized,
  // the name of the returned object may not match `name' exactly.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (callDefconcept(cons(internStellaName(name), ((((boolean)(parent)) ? listO(3, KWD_PLI_SUBSET_OF, objectName(parent), NIL) : NIL))->concatenate(NIL, 0))));
      }
    }
  }
}

LogicObject* sCreateConcept(char* name, char* parentName, char* moduleName, Environment* environment) {
  // Create a concept named `name' in the designated module, with
  // with the concept named `parent-name' as superconcept (which can be left
  // undefined).  Additional superconcepts can be added via assertions of the
  // `subset-of' relation.  Note that a specified parent concept needs to be
  // created separately.
  // 
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  // 
  // Note that because names in modules that are not case-sensitive are canonicalized,
  // the name of the returned object may not match `name' exactly.
  { Context* module = safelyGetModule(moduleName, environment);

    return (createConcept(name, ((LogicObject*)(safelyGetConcept(parentName, ((Module*)(module)), environment))), ((Module*)(module)), environment));
  }
}

LogicObject* createRelation(char* name, int arity, Module* module, Environment* environment) {
  // Create a relation named `name' with arity `arity' in the
  // designated module.  Domain and range information can be added via assertions
  // of `nth-domain' (or `domain' and `range') relations.
  // 
  // Note that because names in modules that are not case-sensitive are canonicalized,
  // the name of the returned object may not match `name' exactly.
  if (!(arity > 0)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
        *(stream000->nativeStream) << "PARSING ERROR: " << "Relations must have arity of at least 1" << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_PLI_ERROR);
      }
      throw *newParsingError(stream000->theStringReader());
    }
  }
  { Cons* args = NIL;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { int i = NULL_INTEGER;
            int iter000 = 0;
            int upperBound000 = arity - 1;
            Cons* collect000 = NULL;

            for  (i, iter000, upperBound000, collect000; 
                  iter000 <= upperBound000; 
                  iter000 = iter000 + 1) {
              i = iter000;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(yieldSystemDefinedParameterName(i, oMODULEo.get()), NIL);
                  if (args == NIL) {
                    args = collect000;
                  }
                  else {
                    addConsToEndOfConsList(args, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(yieldSystemDefinedParameterName(i, oMODULEo.get()), NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
          return (callDefrelation(cons(internStellaName(name), cons(args, NIL))));
        }
      }
    }
  }
}

LogicObject* sCreateRelation(char* name, int arity, char* moduleName, Environment* environment) {
  // Create a relation named `name' with arity `arity' in the
  // designated module.  Domain and range information can be added via assertions
  // of `nth-domain' (or `domain' and `range') relations.
  // 
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  // 
  // Note that because names in modules that are not case-sensitive are canonicalized,
  // the name of the returned object may not match `name' exactly.
  return (createRelation(name, arity, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

LogicObject* createFunction(char* name, int arity, Module* module, Environment* environment) {
  // Create a function named `name' with arity `arity'  in the designated 
  // `module'.  Domain and range information can be added via assertions of
  // `nth-domain' (or `domain' and `range') relations.
  // 
  // Note that because names in modules that are not case-sensitive are canonicalized,
  // the name of the returned object may not match `name' exactly.
  if (!(arity > 0)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
        *(stream000->nativeStream) << "PARSING ERROR: " << "Functions must have arity of at least 1" << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_PLI_ERROR);
      }
      throw *newParsingError(stream000->theStringReader());
    }
  }
  { Cons* args = NIL;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { int i = NULL_INTEGER;
            int iter000 = 0;
            int upperBound000 = arity - 1;
            Cons* collect000 = NULL;

            for  (i, iter000, upperBound000, collect000; 
                  iter000 <= upperBound000; 
                  iter000 = iter000 + 1) {
              i = iter000;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(yieldSystemDefinedParameterName(i, oMODULEo.get()), NIL);
                  if (args == NIL) {
                    args = collect000;
                  }
                  else {
                    addConsToEndOfConsList(args, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(yieldSystemDefinedParameterName(i, oMODULEo.get()), NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
          return (callDeffunction(cons(internStellaName(name), cons(args, NIL))));
        }
      }
    }
  }
}

LogicObject* sCreateFunction(char* name, int arity, char* moduleName, Environment* environment) {
  // Create a function named `name' with arity `arity' in the designated 
  // module.  Domain and range information can be added via assertions of
  // `domain', `nth-domain' and `range' relations.
  // 
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  // 
  // Note that because names in modules that are not case-sensitive are canonicalized,
  // the name of the returned object may not match `name' exactly.
  return (createFunction(name, arity, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

void registerSpecialistFunction(char* name, cpp_function_code functionReference, Module* module, Environment* environment) {
  // Register `name' as a function name in `module' which will invoke the
  // native code procedure described by `function-reference.'  The `name'
  // is a fully-qualified name which will be interpreted by the normal
  // rules for reading names in PowerLoom.  The function must conform
  // to the signature for specialist functions.
  // 
  // The exact form of `function-reference' depends on the underlying
  // programming language.  The following type mappings are used:
  //           C++:  
  //   Common Lisp:  FUNCTION   (result of #' or (FUNCTION ...))
  //          Java:  java.lang.reflect.Method
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        logic::registerSpecialistFunction(name, functionReference);
      }
    }
  }
}

void sRegisterSpecialistFunction(char* name, char* nativeName, char* moduleName, Environment* environment) {
  // Register `name' as a function name in the module named `module-name'.
  // This function will the native code named `native-name'.  The `name'
  // is a fully-qualified name which will be interpreted by the normal
  // rules for reading names in PowerLoom.  The `native-name' will be
  // processed in a manner that depends on the underlying programming
  // language.  The following type mappings are used:
  //           C++:  Not available.  Error signaled.
  //   Common Lisp:  The native-name is read by READ-FROM-STRING and then
  //                 the SYMBOL-FUNCTION is taken.
  //          Java:  A fully package-qualified name is required.  It is
  //                 looked up using the Reflection tools.
  // The function found must conform to the signature for specialist functions.
  { Module* mdl000 = ((Module*)(safelyGetModule(moduleName, environment)));
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        registerSpecialistFunctionName(name, nativeName);
      }
    }
  }
}

LogicObject* createEnumeratedList(Cons* members, Module* module, Environment* environment) {
  // Create a logical term that denotes a list containing `members' in
  // `module' using `environment'.  Useful for passing lists as arguments
  // to parameterized queries.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { List* self000 = newList();

          self000->theConsList = members;
          { Skolem* value000 = createLogicalList(self000);

            return (value000);
          }
        }
      }
    }
  }
}

LogicObject* createEnumeratedSet(Cons* members, Module* module, Environment* environment) {
  // Create a logical term that denotes the enumerated set containing `members'
  // in `module' using `environment'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { List* self000 = newList();

          self000->theConsList = members;
          { Skolem* value000 = logic::createEnumeratedSet(self000);

            return (value000);
          }
        }
      }
    }
  }
}

void destroyObject(LogicObject* object) {
  // Delete the object `object', retracting all facts attached to it.
  // Should be synchronized on process lock oPOWERLOOM_LOCKo
  {
    destroyInstance(object);
  }
}

void sDestroyObject(char* objectName, char* moduleName, Environment* environment) {
  // Delete the object named `object-name', retracting all facts
  // attached to it.
  // 
  // A module name of `null' or the empty string refers to the current module. 
  // If no module can be found with the name `module-name', then a Stella 
  // `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* object = safelyGetObject(objectName, ((Module*)(module)), environment);

    if (((boolean)(object))) {
      destroyObject(((LogicObject*)(object)));
    }
  }
}

Proposition* assertUnaryProposition(LogicObject* relation, Object* arg, Module* module, Environment* environment) {
  // Assert that the proposition (`relation' `arg') is TRUE in `module'.  Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        if (classP(relation)) {
          return (assertIsaProposition(arg, relation->surrogateValueInverse));
        }
        else {
          return (assertProperty(((LogicObject*)(arg)), relation->surrogateValueInverse));
        }
      }
    }
  }
}

Proposition* assertBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Environment* environment) {
  // Assert that the proposition (`relation' `arg' `value') is TRUE
  // in `module'.  Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (assertBinaryValue(relation->surrogateValueInverse, arg, value));
      }
    }
  }
}

Proposition* assertNaryProposition(Object* relationAndArguments, Module* module, Environment* environment) {
  // Assert that the proposition represented by the list ` relation-and-arguments' satisfies
  // the relation `relation'.
  { Cons* list = sequenceToConsList(relationAndArguments);
    NamedDescription* relation = ((NamedDescription*)(list->value));
    Surrogate* relationsurrogate = relation->surrogateValueInverse;
    Cons* arguments = list->rest;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (assertTuple(relationsurrogate, arguments));
        }
      }
    }
  }
}

Proposition* retractUnaryProposition(LogicObject* relation, Object* arg, Module* module, Environment* environment) {
  // Retract that the proposition (`relation' `arg') is TRUE in `module'.  Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        if (classP(relation)) {
          return (retractIsaProposition(arg, relation->surrogateValueInverse));
        }
        else {
          return (retractProperty(((LogicObject*)(arg)), relation->surrogateValueInverse));
        }
      }
    }
  }
}

Proposition* retractBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Environment* environment) {
  // Retract that the proposition (`relation' `arg' `value') is TRUE
  // in `module'.  Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (retractBinaryValue(relation->surrogateValueInverse, arg, value));
      }
    }
  }
}

Proposition* retractNaryProposition(Object* relationAndArguments, Module* module, Environment* environment) {
  // Retract the proposition that `arguments' satisfies
  // the relation `relation'.
  { Cons* list = sequenceToConsList(relationAndArguments);
    NamedDescription* relation = ((NamedDescription*)(list->value));
    Surrogate* relationsurrogate = relation->surrogateValueInverse;
    Cons* arguments = list->rest;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (updateTuple(relationsurrogate, arguments, KWD_PLI_RETRACT_TRUE));
        }
      }
    }
  }
}

Proposition* assertProposition(Proposition* proposition, Module* module, Environment* environment) {
  // Assert that the proposition `proposition' is true in `module'.
  // Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        helpUpdateTopLevelProposition(proposition, KWD_PLI_ASSERT_TRUE);
        return (proposition);
      }
    }
  }
}

PlIterator* sAssertProposition(char* sentence, char* moduleName, Environment* environment) {
  // Assert that the logical sentence `sentence' is true in the module
  // named `module-name'.  A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  // 
  // Return an iterator of the propositions resulting from sentence.
  { Context* module = safelyGetModule(moduleName, environment);
    PlIterator* propositions = NULL;
    PlIterator* returnValue = NULL;

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          propositions = sConceive(sentence, moduleName, environment);
          returnValue = consToPlIterator(propositions->cursor);
          { Proposition* proposition = NULL;
            PlIterator* iter000 = propositions;

            for (proposition, iter000; iter000->nextP(); ) {
              proposition = ((Proposition*)(iter000->value));
              helpUpdateTopLevelProposition(proposition, KWD_PLI_ASSERT_TRUE);
            }
          }
          return (returnValue);
        }
      }
    }
  }
}

Proposition* retractProposition(Proposition* proposition, Module* module, Environment* environment) {
  // Retract the truth of the proposition `proposition' in `module'.
  // Return the retracted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        helpUpdateTopLevelProposition(proposition, KWD_PLI_RETRACT_TRUE);
        return (proposition);
      }
    }
  }
}

PlIterator* sRetractProposition(char* sentence, char* moduleName, Environment* environment) {
  // Retract the truth of the logical sentence `sentence' in the module named
  // `module-name'.  A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  // 
  // Return an iterator of the retracted propositions resulting from sentence.
  { Context* module = safelyGetModule(moduleName, environment);
    PlIterator* propositions = NULL;
    PlIterator* returnValue = NULL;

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          propositions = sConceive(sentence, moduleName, environment);
          returnValue = consToPlIterator(propositions->cursor);
          { Proposition* proposition = NULL;
            PlIterator* iter000 = propositions;

            for (proposition, iter000; iter000->nextP(); ) {
              proposition = ((Proposition*)(iter000->value));
              helpUpdateTopLevelProposition(proposition, KWD_PLI_RETRACT_TRUE);
            }
          }
          return (returnValue);
        }
      }
    }
  }
}

PlIterator* conceive(Object* sentence, Module* module, Environment* environment) {
  // Create one or more proposition objects from the sentence `sentence'
  // in the  module `module'.  Return an iterator of the propositions.
  // If any of the new propositions has the same structure as an already existing
  // proposition, an automatic check for duplicates will return the pre-existing
  // proposition.  Multiple propositions may be returned for a single sentence
  // because of normalization of equivalences, conjunctions, etc.
  // 
  // Signals a `Proposition-Error' if PowerLoom could not conceive `sentence'.
  if (!((boolean)(sentence))) {
    return (NULL);
  }
  else {
    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { Object* propositions = conceiveFormula(sentence);

            if (!((boolean)(propositions))) {
              { OutputStringStream* stream000 = newOutputStringStream();

                { 
                  BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                  *(stream000->nativeStream) << "ERROR: " << "Failed to conceive " << "`" << sentence << "'" << "." << std::endl;
                  helpSignalPropositionError(stream000, KWD_PLI_ERROR);
                }
                throw *newPropositionError(stream000->theStringReader());
              }
            }
            { Surrogate* testValue000 = safePrimaryType(propositions);

              if (subtypeOfP(testValue000, SGT_PLI_LOGIC_PROPOSITION)) {
                { Object* propositions000 = propositions;
                  Proposition* propositions = ((Proposition*)(propositions000));

                  return (consToPlIterator(cons(propositions, NIL)));
                }
              }
              else if (testValue000 == SGT_PLI_STELLA_CONS) {
                { Object* propositions001 = propositions;
                  Cons* propositions = ((Cons*)(propositions001));

                  return (consToPlIterator(propositions));
                }
              }
              else {
                { OutputStringStream* stream001 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                    *(stream001->nativeStream) << "ERROR: " << "Formula is not a sentence: " << "`" << sentence << "'" << "." << std::endl;
                    helpSignalPropositionError(stream001, KWD_PLI_ERROR);
                  }
                  throw *newPropositionError(stream001->theStringReader());
                }
              }
            }
          }
        }
      }
    }
  }
}

PlIterator* sConceive(char* sentence, char* moduleName, Environment* environment) {
  // Create one or more proposition objects from the sentence `sentence'
  // in the  module named `module-name'.  Return an iterator of the propositions.
  // If any of the new propositions has the same structure as an already existing
  // proposition, an automatic check for duplicates will return the pre-existing
  // proposition.  Multiple propositions may be returned for a single sentence
  // because of normalization of equivalences, conjunctions, etc.
  // 
  // A module name of `null' or the empty string refers to the current module.
  // If no module can be found with the name `module-name', then a Stella
  // `No-Such-Context-Exception' is thrown.
  // 
  // Signals a `Proposition-Error' if PowerLoom could not conceive `sentence'.
  { Context* module = safelyGetModule(moduleName, environment);

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (conceive(readSExpressionFromString(sentence), ((Module*)(module)), environment));
        }
      }
    }
  }
}

PlIterator* getRules(LogicObject* relation, Module* module, Environment* environment) {
  // Return rules attached to the concept/relation `relation'
  // in either antecedent or consequent position.
  if (!((boolean)(relation))) {
    return (EMPTY_PL_ITERATOR);
  }
  else {
    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (consToPlIterator(callGetRules(relation)));
        }
      }
    }
  }
}

PlIterator* sGetRules(char* relationName, char* moduleName, Environment* environment) {
  // Return rules attached to the concept/relation named
  // `relation-name' found in the module named `module-name'.
  // 
  // A module name of `null' or the empty string refers to the current module.
  // If no module can be found with the name `module-name', then a Stella
  // `No-Such-Context-Exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    return (getRules(((LogicObject*)(relation)), ((Module*)(module)), environment));
  }
}

void sPrintRules(char* name, OutputStream* stream, char* moduleName, Environment* environment) {
  // Print rules attached to the concept/relation named `name'.
  // 
  // A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  if (!((boolean)(stream))) {
    stream = STANDARD_OUTPUT;
  }
  { Proposition* rule = NULL;
    PlIterator* iter000 = sGetRules(name, moduleName, environment);

    for (rule, iter000; iter000->nextP(); ) {
      rule = ((Proposition*)(iter000->value));
      printLogicalForm(rule, stream);
      *(stream->nativeStream) << std::endl << std::endl;
    }
  }
}

void runForwardRules(Object* module, boolean forceP) {
  // Run forward inference rules in module `module'.
  // If `module' is NULL, the
  // current module will be used.  If forward inferencing is already up-to-date
  // in the designated module, no additional inferencing will occur, unless `force'
  // is set to TRUE, in which case all forward rules are run or rerun.
  // 
  // Calling `run-forward-rules' temporarily puts the module into a mode where
  // future assertional (monotonic) updates will trigger additional forward
  // inference.  Once a non-monotonic update is performed, i.e., a retraction
  // or clipping of relation value, all cached forward inferences will be discarded
  // and forward inferencing will be disabled until this function is
  // called again.
  if (!((boolean)(module))) {
    module = oMODULEo.get();
  }
  if (((boolean)(module))) {
    callRunForwardRules(((Module*)(module)), forceP);
  }
}

int getArity(LogicObject* relation) {
  // Return the arity of the relation `relation'.
  if (subtypeOfP(safePrimaryType(relation), SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
    { LogicObject* relation000 = relation;
      NamedDescription* relation = ((NamedDescription*)(relation000));

      return (relation->arity());
    }
  }
  else {
    return (0);
  }
}

int sGetArity(char* relationName, char* moduleName, Environment* environment) {
  // Return the arity of the relation named `relation-name'.
  // 
  //  A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    if (((boolean)(relation))) {
      return (getArity(((LogicObject*)(relation))));
    }
    else {
      return (NULL_INTEGER);
    }
  }
}

LogicObject* getDomain(LogicObject* relation) {
  // Return the type (a concept) for the first argument to the binary
  // relation `relation'.
  if (subtypeOfP(safePrimaryType(relation), SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
    { LogicObject* relation000 = relation;
      NamedDescription* relation = ((NamedDescription*)(relation000));

      return (getNthDomain(relation, 0));
    }
  }
  else {
    return (NULL);
  }
}

LogicObject* sGetDomain(char* relationName, char* moduleName, Environment* environment) {
  // Return the type (concept) for the first argument to the binary
  // relation `relation-name'.
  // 
  // A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    if (((boolean)(relation))) {
      return (getDomain(((LogicObject*)(relation))));
    }
    else {
      return (NULL);
    }
  }
}

LogicObject* getRange(LogicObject* relation) {
  // Return the type (a concept) for fillers of the binary relation
  // `relation'.
  if (subtypeOfP(safePrimaryType(relation), SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
    { LogicObject* relation000 = relation;
      NamedDescription* relation = ((NamedDescription*)(relation000));

      return (getNthDomain(relation, 1));
    }
  }
  else {
    return (NULL);
  }
}

LogicObject* sGetRange(char* relationName, char* moduleName, Environment* environment) {
  // Return the type (a concept) for fillers of the binary relation
  // `relation-name'.
  // 
  // A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    if (((boolean)(relation))) {
      return (getRange(((LogicObject*)(relation))));
    }
    else {
      return (NULL);
    }
  }
}

LogicObject* getNthDomain(LogicObject* relation, int n) {
  // Return the type (a concept) for the the nth argument of the
  // relation `relation'.  Counting starts at zero.
  if (classP(relation)) {
    return (((n == 0) ? relation : NULL));
  }
  else {
    if (subtypeOfP(safePrimaryType(relation), SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
      { LogicObject* relation000 = relation;
        NamedDescription* relation = ((NamedDescription*)(relation000));

        if ((n >= 0) &&
            (n < relation->ioVariableTypes->length())) {
          { Object* type = ((Surrogate*)(relation->ioVariableTypes->nth(n)))->surrogateValue;

            if (!((boolean)(type))) {
              return (NULL);
            }
            { Surrogate* testValue000 = safePrimaryType(type);

              if (subtypeOfClassP(testValue000)) {
                { Object* type000 = type;
                  Class* type = ((Class*)(type000));

                  return (((NamedDescription*)(dynamicSlotValue(type->dynamicSlots, SYM_PLI_LOGIC_DESCRIPTION, NULL))));
                }
              }
              else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
                { Object* type001 = type;
                  LogicObject* type = ((LogicObject*)(type001));

                  return (type);
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
        }
        else {
          return (NULL);
        }
      }
    }
    else {
      return (NULL);
    }
  }
}

LogicObject* sGetNthDomain(char* relationName, int n, char* moduleName, Environment* environment) {
  // Return the type (a concept) for the nth argument of the relation
  // named `relation-name'.  Counting starts at zero.
  // 
  // A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    if (((boolean)(relation))) {
      return (getNthDomain(((LogicObject*)(relation)), n));
    }
    else {
      return (NULL);
    }
  }
}

void load(char* filename, Environment* environment) {
  // Read logic commands from the file named `filename' and evaluate them.
  // The file should begin with an `in-module' declaration that specifies
  // the module within which all remaining commands are to be evaluated
  // The remaining commands are evaluated one-by-one, applying the function
  // `evaluate' to each of them.
  { Module* mdl000 = oMODULEo.get();
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        logic::load(filename, NIL);
      }
    }
  }
}

void loadStream(InputStream* stream, Environment* environment) {
  // Read logic commands from the STELLA stream `stream' and evaluate them.
  // The stream should begin with an `in-module' declaration that specifies
  // the module within which all remaining commands are to be evaluated
  // The remaining commands are evaluated one-by-one, applying the function
  // `evaluate' to each of them.
  { Module* mdl000 = oMODULEo.get();
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        logic::loadStream(stream);
      }
    }
  }
}

void loadNativeStream(std::istream* stream, Environment* environment) {
  // Read logic commands from the native input stream `stream' and evaluate them.
  // Assumes `stream' is a line-buffered stream which is a safe compromise but does
  // not generate the best efficiency for block-buffered streams such as files.
  // The stream should begin with an `in-module' declaration that specifies
  // the module within which all remaining commands are to be evaluated
  // The remaining commands are evaluated one-by-one, applying the function
  // `evaluate' to each of them.
  { Module* mdl000 = oMODULEo.get();
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { InputStream* self000 = newInputStream();

          self000->nativeStream = stream;
          logic::loadStream(self000);
        }
      }
    }
  }
}

void saveModule(Module* module, char* filename, char* ifexists, Environment* environment) {
  // Save the contents of the module `mod' into a file named `filename'.
  // If a file named `filename' already exists, then the action taken depends on the
  // value of `ifexists'.  Possible values are "ASK", "REPLACE", "WARN" and "ERROR":
  // 
  //   REPLACE => Means overwrite without warning.
  //   WARN    => Means overwrite with a warning.
  //   ERROR   => Means don't overwrite, signal an error instead.
  //   ASK     => Ask the user whether to overwrite or not.  If not overwritten, an 
  //              exception is thrown.
  { boolean existsP = probeFileP(filename);

    if ((!existsP) ||
        stringEqualP(ifexists, "REPLACE")) {
    }
    else if (stringEqualP(ifexists, "ASK")) {
      if (!(yesOrNoP(stringConcatenate("File `", filename, 1, "' already exists.  Overwrite it? (yes or no) ")))) {
        ensureFileDoesNotExist(filename, "save-module");
      }
    }
    else if (stringEqualP(ifexists, "WARN")) {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "File " << "`" << filename << "'" << " already exists, overwriting." << std::endl;
    }
    else if (stringEqualP(ifexists, "ERROR")) {
      ensureFileDoesNotExist(filename, "save-module");
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Unrecognized ifexists option " << "`" << ifexists << "'";
        throw *newBadArgumentException(stream000->theStringReader());
      }
    }
    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { OutputFileStream* stream = NULL;

            try {
              stream = openOutputFile(filename, 0);
              doSaveModule(oMODULEo.get(), stream);
            }
catch (...) {
              if (((boolean)(stream))) {
                stream->free();
              }
              throw;
            }
            if (((boolean)(stream))) {
              stream->free();
            }
          }
        }
      }
    }
  }
}

void sSaveModule(char* moduleName, char* filename, char* ifexists, Environment* environment) {
  // Save the contents of the module `module-name' into a file named `filename'.
  // If a file named `filename' already exists, then the action taken depends on the
  // value of `ifexists'.  Possible values are "ASK", "REPLACE", "WARN" and "ERROR":
  // 
  //   REPLACE => Means overwrite without warning.
  //   WARN    => Means overwrite with a warning.
  //   ERROR   => Means don't overwrite, signal an error instead.
  //   ASK     => Ask the user whether to overwrite or not.  If not overwritten, an
  //              exception is thrown.
  // 
  // A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  saveModule(((Module*)(safelyGetModule(moduleName, environment))), filename, ifexists, environment);
}

LogicObject* getPredicate(Proposition* prop) {
  // Return the concept or relation predicate for
  // the proposition `prop'.
  { LogicObject* relation = getDescription(((Surrogate*)(prop->operatoR)));

    if (!((boolean)(relation))) {
      relation = ((LogicObject*)(((Surrogate*)(prop->operatoR))->surrogateValue));
    }
    return (relation);
  }
}

int getColumnCount(Object* obj) {
  // Return the number of columns in `obj', which must
  // be of type proposition, cons, vector or PL-iterator.  For a proposition,
  // the number includes both the predidate and arguments. For the PL-iterator
  // case,the number of columns is for the current value of the iterator.
  // 
  // For non sequence objects, the column count is zero.
  if (!((boolean)(obj))) {
    return (0);
  }
  { Surrogate* testValue000 = safePrimaryType(obj);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_PROPOSITION)) {
      { Object* obj000 = obj;
        Proposition* obj = ((Proposition*)(obj000));

        return (obj->arguments->length() + 1);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_PLI_PL_ITERATOR)) {
      { Object* obj001 = obj;
        PlIterator* obj = ((PlIterator*)(obj001));

        return (getColumnCount(obj->value));
      }
    }
    else if (testValue000 == SGT_PLI_STELLA_CONS) {
      { Object* obj002 = obj;
        Cons* obj = ((Cons*)(obj002));

        return (obj->length());
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_VECTOR)) {
      { Object* obj003 = obj;
        Vector* obj = ((Vector*)(obj003));

        return (obj->length());
      }
    }
    else {
      return (1);
    }
  }
}

Object* getNthValue(Object* sequence, int n, Module* module, Environment* environment) {
  // Return the value in the `nth' column of `sequence'.
  // Counting starts at zero.  Unless `n' is zero, `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the number
  // of columns is for the current value of the iterator.
  // 
  // As a special case, a column number of zero will also return `sequence' itself
  // if it is not one of the types enumerated above.  This is done to allow the
  // use of `get-nth-value' on PL-iterators with only a single return variable.
  if ((n >= getColumnCount(sequence)) ||
      (n < 0)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "Column index " << "`" << n << "'" << " is out of range for " << "`" << sequence << "'";
      throw *newLogicException(stream000->theStringReader());
    }
  }
  { Surrogate* testValue000 = safePrimaryType(sequence);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_PROPOSITION)) {
      { Object* sequence000 = sequence;
        Proposition* sequence = ((Proposition*)(sequence000));

        if (n == 0) {
          return (getPredicate(sequence));
        }
        else {
          { Object* value = (sequence->arguments->theArray)[(n - 1)];

            if (subtypeOfP(safePrimaryType(value), SGT_PLI_LOGIC_SKOLEM)) {
              { Object* value000 = value;
                Skolem* value = ((Skolem*)(value000));

                { Module* mdl000 = module;
                  Context* cxt000 = mdl000;

                  if (!((boolean)(mdl000))) {
                    mdl000 = oMODULEo.get();
                    cxt000 = oCONTEXTo.get();
                  }
                  { 
                    BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
                    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
                    environment = environment;
                    // Should be synchronized on process lock oPOWERLOOM_LOCKo
                    {
                      return (valueOf(value));
                    }
                  }
                }
              }
            }
            else {
              return (value);
            }
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_PLI_PL_ITERATOR)) {
      { Object* sequence001 = sequence;
        PlIterator* sequence = ((PlIterator*)(sequence001));

        return (getNthValue(sequence->value, n, module, environment));
      }
    }
    else if (testValue000 == SGT_PLI_STELLA_CONS) {
      { Object* sequence002 = sequence;
        Cons* sequence = ((Cons*)(sequence002));

        return (sequence->nth(n));
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_VECTOR)) {
      { Object* sequence003 = sequence;
        Vector* sequence = ((Vector*)(sequence003));

        return ((sequence->theArray)[n]);
      }
    }
    else {
      return (sequence);
    }
  }
}

char* getNthString(Object* sequence, int n, Module* module, Environment* environment) {
  // Return a string representation of the value in the `nth' column of
  // `sequence'. Counting starts at zero.   Unless `n' is zero, `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the
  // the current value pointed to by the iterator is used.  This will always
  // succeed, even if the `nth' value is not a string object.  In that case, a
  // string reprensentation will be returned.
  // 
  // 
  // As a special case, a column number of zero will also return `sequence' itself
  // as a string if it is not one of the types enumerated above.  This is done to 
  // allow the use of `get-nth-string' on PL-iterators with only a single return variable.
  return (objectToString(getNthValue(sequence, n, module, environment)));
}

int getNthInteger(Object* sequence, int n, Module* module, Environment* environment) {
  // Return an integer representation of the value in the `nth' column of
  // `sequence'. Counting starts at zero.   Unless `n' is zero, `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the
  // the current value pointed to by the iterator is used.  If this is not
  // an integer value, then an exception will be thrown.
  // 
  // 
  // As a special case, a column number of zero will also return the integer
  // value of `sequence' itself if it is not one of the types enumerated
  // above.   This allows the use of `get-nth-integer' on PL-iterators with
  // only a single return variable.  If  `sequence' cannot be turned into an
  // integer, an exception will be thrown.
  return (objectToInteger(getNthValue(sequence, n, module, environment)));
}

double getNthFloat(Object* sequence, int n, Module* module, Environment* environment) {
  // Return the floating point value in the `nth' column of
  // `sequence'. Counting starts at zero.  `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the
  // the current value pointed to by the iterator is used.  If this is not
  // a floating point value, then an exception will be thrown.
  // 
  // 
  // As a special case, a column number of zero will also return the floating
  // point value of `sequence' itself if it is not one of the types enumerated
  // above.  This allows the use of `get-nth-float' on PL-iterators with only
  // a single return variable.    If  `sequence' cannot be turned into a floating
  // point value, an exception will be thrown.
  return (objectToFloat(getNthValue(sequence, n, module, environment)));
}

LogicObject* getNthLogicObject(Object* sequence, int n, Module* module, Environment* environment) {
  // Return a logic object representation of the value in the `nth' column
  // of `sequence'.  Counting starts at zero.   Unless `n' is zero, `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the
  // the current value pointed to by the iterator is used.  A zero column number
  // returns the proposition's relational predicate.  If the return value is
  // not a LOGIC-OBJECT, an exception is thrown.
  // 
  // As a special case, a column number of zero will also return `sequence' itself
  // if it is not one of the types enumerated above.  This is done to allow the
  // use of `get-nth-value' on PL-iterators with only a single return variable.
  // If `sequence' is not a LOGIC-OBJECT, an exception is thrown.
  { Object* value = getNthValue(sequence, n, module, environment);

    if (isaP(value, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
      return (((LogicObject*)(value)));
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Can't coerce " << "`" << value << "'" << " to a LOGIC-OBJECT.";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Cons* getEnumeratedCollectionMembers(Object* collection, Module* module, Environment* environment) {
  // Returns the members of an enumerated collection.  This works on all types
  // of collection, i.e., sets and lists
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { List* members = assertedCollectionMembers(collection, true);

          if (((boolean)(members))) {
            return (members->theConsList);
          }
          else {
            return (NULL);
          }
        }
      }
    }
  }
}

Object* evaluate(Object* command, Module* module, Environment* environment) {
  // Evaluate the command `command' within `module' and return
  // the result. Currently, only the evaluation of (possibly nested) commands and
  // global variables is supported.  Commands are simple to program in Common Lisp,
  // since they are built into the language, and relatively awkward in Java and C++.
  // Users of either of those languages are more likely to want to call `s-evaluate'.
  if (((boolean)(command))) {
    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (stella::evaluate(command));
        }
      }
    }
  }
  return (NULL);
}

Object* sEvaluate(char* command, char* moduleName, Environment* environment) {
  // Evaluate the command represented by the string `command' within `module' and
  // return the result.  Currently, only the evaluation of (possibly nested) commands and
  // global variables is supported.
  // 
  //  A module name of `null' or the empty string refers to the
  // current module.  If no module can be found with the name `module-name',
  // then a Stella `no-such-context-exception' is thrown.
  { Context* module = safelyGetModule(moduleName, environment);

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (evaluate(readSExpressionFromString(command), ((Module*)(module)), environment));
        }
      }
    }
  }
}

boolean isLogicObject(Object* obj) {
  // Test whether `obj' is of type LOGIC-OBJECT
  return (isaP(obj, SGT_PLI_LOGIC_LOGIC_OBJECT));
}

boolean isInteger(Object* obj) {
  // Test whether `obj' is of type INTEGER
  return (isaP(obj, SGT_PLI_STELLA_INTEGER_WRAPPER));
}

boolean isFloat(Object* obj) {
  // Test whether `obj' is of type FLOAT (double)
  return (isaP(obj, SGT_PLI_STELLA_FLOAT_WRAPPER));
}

boolean isNumber(Object* obj) {
  // Test whether `obj' is of type NUMBER.  This can
  // be either an integer or a floating point number.  One key characteristic
  // is that 'object-to-integer' and `object-to-float' will both work on it.
  return (isaP(obj, SGT_PLI_STELLA_NUMBER_WRAPPER));
}

boolean isString(Object* obj) {
  // Test whether `obj' is of type STRING
  return (isaP(obj, SGT_PLI_STELLA_STRING_WRAPPER));
}

boolean isEnumeratedCollection(Object* obj) {
  // Test whether `obj' is an enumerated collection.  This
  // subsumes both sets and lists.
  return (logicalCollectionP(obj));
}

boolean isEnumeratedSet(Object* obj) {
  // Test whether `obj' is an enumerated set.
  return (enumeratedSetP(obj));
}

boolean isEnumeratedList(Object* obj) {
  // Test whether `obj' is an enumerated list
  return (enumeratedListP(obj));
}

boolean isTrue(TruthValue* tv) {
  // Tests whether `tv' is a true truth value.  It can be true
  // either absolutely or by default.
  return ((tv == TRUE_TRUTH_VALUE) ||
      (tv == DEFAULT_TRUE_TRUTH_VALUE));
}

boolean isFalse(TruthValue* tv) {
  // Tests whether `tv' is a false truth value.  It can be false
  // either absolutely or by default.
  return ((tv == FALSE_TRUTH_VALUE) ||
      (tv == DEFAULT_FALSE_TRUTH_VALUE));
}

boolean isUnknown(TruthValue* tv) {
  // Tests whether `tv' is an unknown truth value.
  return ((tv == UNKNOWN_TRUTH_VALUE) ||
      (!((boolean)(tv))));
}

boolean isInconsistent(TruthValue* tv) {
  // Tests whether `tv' is an inconsistent truth value.
  return (tv == INCONSISTENT_TRUTH_VALUE);
}

boolean isStrict(TruthValue* tv) {
  // Tests whether `tv' is a strict (non-default) truth value.
  return ((tv == TRUE_TRUTH_VALUE) ||
      (tv == FALSE_TRUTH_VALUE));
}

boolean isDefault(TruthValue* tv) {
  // Tests whether `tv' is a default truth value.
  return ((tv == DEFAULT_TRUE_TRUTH_VALUE) ||
      (tv == DEFAULT_FALSE_TRUTH_VALUE));
}

TruthValue* ask(Cons* query, Module* module, Environment* environment) {
  // Returns a truth value for `query' in `module' and `environment'.
  // `query' has the same syntax as the PowerLoom `ask' command (which see)
  // but with the `ask' operator omitted.  For example, here are some legal
  // `query' arguments:
  // 	 
  //     ((happy Fred))
  //     ((happy Fred) :inference-level :assertion)
  //     ((happy Fred) :inference-level :assertion :timeout 1.0)
  // 	
  // As a convenience, a `query' argument whose first element is a symbol is
  // interpreted as a sentence that is queried without any options.  For example:
  // 	 
  //     (happy Fred)
  // 	
  // is a legal `query' argument.  Note that for a setence whose relation is a list
  // itself, e.g., `((FruitFn BananaTree) MyBanana)' this shortcut is not available,
  // that is, in that case an extra level of list nesting is always necessary.
  // The returned truth value represents the logical truth of the queried sentence
  // as determined by PowerLoom.  It can be be tested via the functions `is-true',
  // `is-false' and `is-unknown' (which see).
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        query = ((Cons*)(deobjectifyTree(query)));
        if (symbolP(query->value)) {
          query = cons(query, NIL);
        }
        return (callAsk(query));
      }
    }
  }
}

TruthValue* sAsk(char* query, char* moduleName, Environment* environment) {
  // Returns a truth value for `query' in module `module-name' and `environment'.
  // `query' has the same syntax as the PowerLoom `ask' command (which see) but
  // with the `ask' operator omitted.  Different from the PLI `ask' function, `s-ask'
  // does not expect a top-level pair of parentheses.  For example, here are some legal
  // `query' arguments:
  // 	 
  //     "(happy Fred)"
  //     "(happy Fred) :inference-level :assertion"
  //     "(happy Fred) :inference-level :assertion :timeout 1.0"
  // 	
  // Names in `query' will be interpreted relative to module `module-name'.
  // A null `module-name' or the empty string refers to the current module.
  // If no module can be found with the name `module-name', then a STELLA
  // `no-such-context-exception' is thrown.
  // The returned truth value represents the logical truth of the queried sentence
  // as determined by PowerLoom.  It can be be tested via the functions `is-true',
  // `is-false' and `is-unknown' (which see).
  { Cons* queryform = NIL;
    Context* module = safelyGetModule(moduleName, environment);

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { Object* sexp = NULL;
            SExpressionIterator* iter000 = sExpressions(newInputStringStream(query));
            Cons* collect000 = NULL;

            for  (sexp, iter000, collect000; 
                  iter000->nextP(); ) {
              sexp = iter000->value;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(sexp, NIL);
                  if (queryform == NIL) {
                    queryform = collect000;
                  }
                  else {
                    addConsToEndOfConsList(queryform, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(sexp, NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
        }
      }
    }
    return (ask(queryform, ((Module*)(safelyGetModule(moduleName, environment))), environment));
  }
}

PlIterator* retrieve(Cons* query, Module* module, Environment* environment) {
  // Returns an iterator of variable bindings that when substituted for the
  // open variables in `query' satisfy the query proposition.  The query is
  // run in `module' and relative to `environment'.  `query' has the same syntax
  // as the PowerLoom `retrieve' command (which see) but with the `retrieve'
  // operator omitted.    For example, here are some legal `query' arguments:
  // 	 
  //     ((happy ?x))
  //     (10 (happy ?x))
  //     (all (happy ?x))
  //     (all ?x (happy ?x))
  //     (10 (happy ?x) :inference-level :assertion)
  //     (10 (happy ?x) :inference-level :assertion :timeout 1.0)
  // 	
  // If there is only a single output variable (as in all the examples above)
  // each element generated by the returned iterator will be a binding for
  // that variable - unless, the output variable was declared with a surrounding
  // pair of parentheses.  For example:
  // 	 
  //     (all (?x) (happy ?x))
  // 	
  // In that case, the generated elements will be one-element lists.  If there
  // are multiple output variables, each element generated by the returned
  // iterator will be a list of variable bindings that can be accessed using
  // the various `get-nth-...' functions.  The list of output variables does
  // not need to be declared in which case they are taken to be the open variables
  // in the query proposition in the order in which they were encountered.  If
  // order does matter or should be different from its default, it can be forced
  // by declaring the set of output variables.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        query = ((Cons*)(deobjectifyTree(query)));
        return (consToPlIterator(callRetrieve(query)->consifyCurrentSolutions()));
      }
    }
  }
}

PlIterator* sRetrieve(char* query, char* moduleName, Environment* environment) {
  // Returns an iterator of variable bindings that when substituted for the
  // open variables in `query' satisfy the query proposition.  The query is
  // run in `module' and relative to `environment'.  `query' has the same syntax
  // as the PowerLoom `retrieve' command (which see) but with the `retrieve'
  // operator omitted.  Different from the PLI `retrieve' function, `s-retrieve'
  // does not expect a top-level pair of parentheses.  For example, here are some
  // legal `query' arguments:
  // 	 
  //     "(happy ?x)"
  //     "10 (happy ?x)"
  //     "all (happy ?x)"
  //     "all ?x (happy ?x)"
  //     "10 (happy ?x) :inference-level :assertion"
  //     "10 (happy ?x) :inference-level :assertion :timeout 1.0"
  // 	
  // If there is only a single output variable (as in all the examples above)
  // each element generated by the returned iterator will be a binding for
  // that variable - unless, the output variable was declared with a surrounding
  // pair of parentheses.  For example:
  // 	 
  //     "all (?x) (happy ?x)"
  // 	
  // In that case, the generated elements will be one-element lists.  If there
  // are multiple output variables, each element generated by the returned
  // iterator will be a list of variable bindings that can be accessed using
  // the various `get-nth-...' functions.  The list of output variables does
  // not need to be declared in which case they are taken to be the open variables
  // in the query proposition in the order in which they were encountered.  If
  // order does matter or should be different from its default, it can be forced
  // by declaring the set of output variables.
  // 
  // Names in `query' will be interpreted relative to module `module-name'.
  // A null `module-name' or the empty string refers to the current module.
  // If no module can be found with the name `module-name', then a STELLA
  // `no-such-context-exception' is thrown.
  { Cons* queryform = NIL;
    Context* module = safelyGetModule(moduleName, environment);

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { Object* sexp = NULL;
            SExpressionIterator* iter000 = sExpressions(newInputStringStream(query));
            Cons* collect000 = NULL;

            for  (sexp, iter000, collect000; 
                  iter000->nextP(); ) {
              sexp = iter000->value;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(sexp, NIL);
                  if (queryform == NIL) {
                    queryform = collect000;
                  }
                  else {
                    addConsToEndOfConsList(queryform, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(sexp, NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
        }
      }
    }
    return (retrieve(queryform, ((Module*)(module)), environment));
  }
}

int main() {
  // Main PowerLoom entry point for your code in C++ and Java.
  std::cout << "Initializing STELLA..." << std::endl;
  startupStellaSystem();
  std::cout << "Initializing PowerLoom..." << std::endl;
  startupLogicSystem();
  stella::stringChangeModule("PL-USER");
  powerloom();
  return (1);
}

void helpStartupPli1() {
  {
    SGT_PLI_PLI_ENVIRONMENT = ((Surrogate*)(internRigidSymbolWrtModule("ENVIRONMENT", NULL, 1)));
    SYM_PLI_LOGIC_LEVEL = ((Symbol*)(internRigidSymbolWrtModule("LEVEL", getStellaModule("/LOGIC", true), 0)));
    SGT_PLI_PLI_PL_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("PL-ITERATOR", NULL, 1)));
    SYM_PLI_STELLA_CURSOR = ((Symbol*)(internRigidSymbolWrtModule("CURSOR", getStellaModule("/STELLA", true), 0)));
    SGT_PLI_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_STELLA_LIST = ((Surrogate*)(internRigidSymbolWrtModule("LIST", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_STELLA_VECTOR = ((Surrogate*)(internRigidSymbolWrtModule("VECTOR", getStellaModule("/STELLA", true), 1)));
    SYM_PLI_STELLA_NULL = ((Symbol*)(internRigidSymbolWrtModule("NULL", getStellaModule("/STELLA", true), 0)));
    SGT_PLI_LOGIC_SKOLEM = ((Surrogate*)(internRigidSymbolWrtModule("SKOLEM", getStellaModule("/LOGIC", true), 1)));
    SGT_PLI_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", getStellaModule("/LOGIC", true), 1)));
    SGT_PLI_STELLA_GENERALIZED_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("GENERALIZED-SYMBOL", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_STELLA_MODULE = ((Surrogate*)(internRigidSymbolWrtModule("MODULE", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_STELLA_CONTEXT = ((Surrogate*)(internRigidSymbolWrtModule("CONTEXT", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_LOGIC_COMPUTED_PROCEDURE = ((Surrogate*)(internRigidSymbolWrtModule("COMPUTED-PROCEDURE", getStellaModule("/LOGIC", true), 1)));
    SGT_PLI_STELLA_LITERAL_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("LITERAL-WRAPPER", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_LOGIC_NAMED_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("NAMED-DESCRIPTION", getStellaModule("/LOGIC", true), 1)));
    SYM_PLI_PLI_pR = ((Symbol*)(internRigidSymbolWrtModule("?R", NULL, 0)));
    SYM_PLI_PLI_pI = ((Symbol*)(internRigidSymbolWrtModule("?I", NULL, 0)));
    SYM_PLI_PLI_pV = ((Symbol*)(internRigidSymbolWrtModule("?V", NULL, 0)));
    SYM_PLI_PLI_F_GET_INFERRED_BINARY_PROPOSITION_VALUES_QUERY_000 = ((Symbol*)(internRigidSymbolWrtModule("F-GET-INFERRED-BINARY-PROPOSITION-VALUES-QUERY-000", NULL, 0)));
    SYM_PLI_LOGIC_ALL = ((Symbol*)(internRigidSymbolWrtModule("ALL", getStellaModule("/LOGIC", true), 0)));
    SYM_PLI_LOGIC_pX = ((Symbol*)(internRigidSymbolWrtModule("?X", getStellaModule("/LOGIC", true), 0)));
    SYM_PLI_STELLA_AND = ((Symbol*)(internRigidSymbolWrtModule("AND", getStellaModule("/STELLA", true), 0)));
    SYM_PLI_LOGIC_FAIL = ((Symbol*)(internRigidSymbolWrtModule("FAIL", getStellaModule("/LOGIC", true), 0)));
    SYM_PLI_STELLA_EXISTS = ((Symbol*)(internRigidSymbolWrtModule("EXISTS", getStellaModule("/STELLA", true), 0)));
    SYM_PLI_LOGIC_pY = ((Symbol*)(internRigidSymbolWrtModule("?Y", getStellaModule("/LOGIC", true), 0)));
    SYM_PLI_PLI_PROPER_SUBRELATION = ((Symbol*)(internRigidSymbolWrtModule("PROPER-SUBRELATION", NULL, 0)));
    KWD_PLI_ISA = ((Keyword*)(internRigidSymbolWrtModule("ISA", NULL, 2)));
    SYM_PLI_STELLA_TRUE = ((Symbol*)(internRigidSymbolWrtModule("TRUE", getStellaModule("/STELLA", true), 0)));
    SYM_PLI_STELLA_FALSE = ((Symbol*)(internRigidSymbolWrtModule("FALSE", getStellaModule("/STELLA", true), 0)));
    KWD_PLI_CASE_SENSITIVEp = ((Keyword*)(internRigidSymbolWrtModule("CASE-SENSITIVE?", NULL, 2)));
    KWD_PLI_SUBSET_OF = ((Keyword*)(internRigidSymbolWrtModule("SUBSET-OF", NULL, 2)));
    KWD_PLI_ERROR = ((Keyword*)(internRigidSymbolWrtModule("ERROR", NULL, 2)));
    KWD_PLI_RETRACT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("RETRACT-TRUE", NULL, 2)));
    KWD_PLI_ASSERT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("ASSERT-TRUE", NULL, 2)));
    SGT_PLI_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", getStellaModule("/LOGIC", true), 1)));
    SYM_PLI_LOGIC_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTION", getStellaModule("/LOGIC", true), 0)));
    SGT_PLI_STELLA_INTEGER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER-WRAPPER", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_STELLA_FLOAT_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("FLOAT-WRAPPER", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_STELLA_NUMBER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("NUMBER-WRAPPER", getStellaModule("/STELLA", true), 1)));
    SGT_PLI_STELLA_STRING_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("STRING-WRAPPER", getStellaModule("/STELLA", true), 1)));
    SYM_PLI_PLI_STARTUP_PLI = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-PLI", NULL, 0)));
    SYM_PLI_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
  }
}

void helpStartupPli2() {
  {
    defineFunctionObject("INITIALIZE", "(DEFUN INITIALIZE () :DOCUMENTATION \"Initialize the PowerLoom logic system.  This function\nneeds to be called by all applications before using PowerLoom.  If it\nis called more than once, every call after the first one is a no-op.\" :PUBLIC? TRUE)", ((cpp_function_code)(&initialize)), NULL);
    defineFunctionObject("RESET-POWERLOOM", "(DEFUN RESET-POWERLOOM () :DOCUMENTATION \"Reset PowerLoom to its initial state.\nCAUTION: This will destroy all loaded knowledge bases and might break other\nloaded STELLA systems if they do reference PowerLoom symbols in their code.\" :PUBLIC? TRUE)", ((cpp_function_code)(&resetPowerloom)), NULL);
    defineFunctionObject("CLEAR-CACHES", "(DEFUN CLEAR-CACHES () :DOCUMENTATION \"Clear all query and memoization caches.\" :PUBLIC? TRUE)", ((cpp_function_code)(&clearCaches)), NULL);
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF PL-ITERATOR)) :PUBLIC? TRUE :DOCUMENTATION \"Advance the PL-Iterator `self' and return `true' if more\nelements are available, `false' otherwise.\")", ((cpp_method_code)(&PlIterator::nextP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (EMPTY? BOOLEAN) ((SELF PL-ITERATOR)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the iterator `self' has no more elements.\")", ((cpp_method_code)(&PlIterator::emptyP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LENGTH INTEGER) ((SELF PL-ITERATOR)) :PUBLIC? TRUE :DOCUMENTATION \"Number of items remaining in `self'.  Non destructive.\")", ((cpp_method_code)(&PlIterator::length)), ((cpp_method_code)(NULL)));
    defineFunctionObject("CONS-TO-PL-ITERATOR", "(DEFUN (CONS-TO-PL-ITERATOR PL-ITERATOR) ((SELF CONS)) :PUBLIC? FALSE :DOCUMENTATION \"Convert a Stella cons list into an API iterator.\")", ((cpp_function_code)(&consToPlIterator)), NULL);
    defineFunctionObject("LIST-TO-PL-ITERATOR", "(DEFUN (LIST-TO-PL-ITERATOR PL-ITERATOR) ((SELF LIST)) :PUBLIC? FALSE :DOCUMENTATION \"Convert a Stella list into an API iterator.\")", ((cpp_function_code)(&listToPlIterator)), NULL);
    defineFunctionObject("ITERATOR-TO-PL-ITERATOR", "(DEFUN (ITERATOR-TO-PL-ITERATOR PL-ITERATOR) ((SELF ITERATOR)) :PUBLIC? FALSE :DOCUMENTATION \"Convert an arbitrary Stella iterator into an API iterator.\")", ((cpp_function_code)(&iteratorToPlIterator)), NULL);
    defineMethodObject("(DEFMETHOD (LISTIFY LIST) ((SELF PL-ITERATOR)) :PUBLIC? TRUE :DOCUMENTATION \"Convert `self' into a Stella LIST.\")", ((cpp_method_code)(&PlIterator::listify)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (CONSIFY CONS) ((SELF PL-ITERATOR)) :PUBLIC? TRUE :DOCUMENTATION \"Convert `self' into a Stella CONS.\")", ((cpp_method_code)(&PlIterator::consify)), ((cpp_method_code)(NULL)));
    defineFunctionObject("SAFELY-GET-OBJECT", "(DEFUN (SAFELY-GET-OBJECT OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? FALSE)", ((cpp_function_code)(&safelyGetObject)), NULL);
    defineFunctionObject("SAFELY-GET-CONCEPT", "(DEFUN (SAFELY-GET-CONCEPT OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? FALSE)", ((cpp_function_code)(&safelyGetConcept)), NULL);
    defineFunctionObject("SAFELY-GET-RELATION", "(DEFUN (SAFELY-GET-RELATION OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? FALSE)", ((cpp_function_code)(&safelyGetRelation)), NULL);
    defineFunctionObject("SAFELY-GET-MODULE", "(DEFUN (SAFELY-GET-MODULE CONTEXT) ((NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? FALSE)", ((cpp_function_code)(&safelyGetModule)), NULL);
    defineFunctionObject("SAFELY-GET-OBJECT-OR-NULL", "(DEFUN (SAFELY-GET-OBJECT-OR-NULL OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? FALSE)", ((cpp_function_code)(&safelyGetObjectOrNull)), NULL);
    defineFunctionObject("SEQUENCE-TO-CONS-LIST", "(DEFUN (SEQUENCE-TO-CONS-LIST CONS) ((SEQUENCE OBJECT)) :PUBLIC? FALSE)", ((cpp_function_code)(&sequenceToConsList)), NULL);
    defineFunctionObject("EXPLODE-STRING-LIST", "(DEFUN (EXPLODE-STRING-LIST CONS) ((STRINGLIST STRING) (MODULE MODULE)) :PUBLIC? FALSE)", ((cpp_function_code)(&explodeStringList)), NULL);
    defineFunctionObject("LEGAL-OPERATOR?", "(DEFUN (LEGAL-OPERATOR? BOOLEAN) ((OPERATOR SYMBOL)) :PUBLIC? FALSE)", ((cpp_function_code)(&legalOperatorP)), NULL);
    defineFunctionObject("GET-KEYWORD", "(DEFUN (GET-KEYWORD KEYWORD) ((NAME STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Returns the Stella KEYWORD `name' if it exists.  Case sensitive.\")", ((cpp_function_code)(&getKeyword)), NULL);
    defineFunctionObject("GET-SYMBOL", "(DEFUN (GET-SYMBOL SYMBOL) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Returns the Stella SYMBOL `name' visible in `module' if it\nexists.  `name' is ALWAYS treated case sensitively.\")", ((cpp_function_code)(&getSymbol)), NULL);
    defineFunctionObject("GET-OPERATOR", "(DEFUN (GET-OPERATOR SYMBOL) ((NAME STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Returns the logical operator object (a Stella SYMBOL) for `name'.\nIf no such operator exists then a `no-such-object' exception is thrown.\")", ((cpp_function_code)(&getOperator)), NULL);
    defineFunctionObject("GET-OBJECT", "(DEFUN (GET-OBJECT OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Look for an object named `name' that is local to\nor visible from the module `module'.\")", ((cpp_function_code)(&getObject)), NULL);
    defineFunctionObject("S-GET-OBJECT", "(DEFUN (S-GET-OBJECT OBJECT) ((NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Look for an object named `name' that is local to\nor visible from the module `module-name'.  A module name of `null' or the\nempty string refers to the current module.  If no module can be found\nwith the name `module-name', then a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetObject)), NULL);
    defineFunctionObject("GET-CONCEPT", "(DEFUN (GET-CONCEPT LOGIC-OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a class/concept named `name' that is local to\nor visible from the module `module'.\")", ((cpp_function_code)(&getConcept)), NULL);
    defineFunctionObject("S-GET-CONCEPT", "(DEFUN (S-GET-CONCEPT LOGIC-OBJECT) ((NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a class/concept named `name' that is local to\nor visible from the module `module-name'.  A module name of `null' or the\nempty string refers to the current module.  If no module can be found\nwith the name `module-name', then a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetConcept)), NULL);
    defineFunctionObject("GET-RELATION", "(DEFUN (GET-RELATION LOGIC-OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a concept or relation named `name' that is local to\nor visible from the module `module'.\")", ((cpp_function_code)(&getRelation)), NULL);
    defineFunctionObject("S-GET-RELATION", "(DEFUN (S-GET-RELATION LOGIC-OBJECT) ((NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a concept or relation named `name' that is local to\nor visible from the module `module-name'.  A module name of `null' or the\nempty string refers to the current module.  If no module can be found\nwith the name `module-name', then a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetRelation)), NULL);
    defineFunctionObject("GET-NAME-IN-MODULE", "(DEFUN (GET-NAME-IN-MODULE STRING) ((OBJ OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the name, qualified as necessary, so that `obj' can be found from\n`module'.  If there is no name for the object return `null'.\")", ((cpp_function_code)(&getNameInModule)), NULL);
    defineFunctionObject("GET-NAME", "(DEFUN (GET-NAME STRING) ((OBJ OBJECT)) :DOCUMENTATION \"Return the fully qualified name of `obj', if it has one.  Otherwise return `null'.\")", ((cpp_function_code)(&getName)), NULL);
    defineFunctionObject("GET-SHORT-NAME", "(DEFUN (GET-SHORT-NAME STRING) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the short name of `obj', if it has one.  Otherwise return `null'.\")", ((cpp_function_code)(&getShortName)), NULL);
    defineFunctionObject("OBJECT-TO-STRING", "(DEFUN (OBJECT-TO-STRING STRING) ((SELF OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a printed representation of the term `self' as a string.\")", ((cpp_function_code)(&objectToString)), NULL);
    defineFunctionObject("OBJECT-TO-INTEGER", "(DEFUN (OBJECT-TO-INTEGER INTEGER) ((SELF OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Coerce `self' to an integer, or throw a Stella Exception if the coersion is not feasible.\nFloating point values will be coerced by rounding.\")", ((cpp_function_code)(&objectToInteger)), NULL);
    defineFunctionObject("OBJECT-TO-FLOAT", "(DEFUN (OBJECT-TO-FLOAT FLOAT) ((SELF OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Coerce `self' to a float, or throw a Stella Exception if the coersion is not feasible.\")", ((cpp_function_code)(&objectToFloat)), NULL);
    defineFunctionObject("OBJECT-TO-PARSABLE-STRING", "(DEFUN (OBJECT-TO-PARSABLE-STRING STRING) ((SELF OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a string representing a printed\nrepresentation of the object `self'.  Like `object-to-string', but puts\nescaped double quotes around strings.\")", ((cpp_function_code)(&objectToParsableString)), NULL);
    defineFunctionObject("STRING-TO-OBJECT", "(DEFUN (STRING-TO-OBJECT OBJECT) ((STRING STRING) (TYPE LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Evaluate `string' with respect to `module' and `environment'\nand return the corresponding logical term.  `type' is a concept used to assist the\ncorrect interpretation of `string'.\n\nCurrently `type' only has an effect on the interpretation of literal types.\")", ((cpp_function_code)(&stringToObject)), NULL);
    defineFunctionObject("HELP-GET-TRUE-EXTENSION-MEMBERS", "(DEFUN (HELP-GET-TRUE-EXTENSION-MEMBERS (CONS OF PROPOSITION)) ((RELATION NAMED-DESCRIPTION) (SPECIALIZE? BOOLEAN)) :PUBLIC? FALSE)", ((cpp_function_code)(&helpGetTrueExtensionMembers)), NULL);
    defineFunctionObject("HELP-GET-PROPOSITIONS", "(DEFUN (HELP-GET-PROPOSITIONS (CONS OF PROPOSITION)) ((RELATION LOGIC-OBJECT) (ARGUMENTS CONS) (LIMIT INTEGER) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? FALSE)", ((cpp_function_code)(&helpGetPropositions)), NULL);
    defineFunctionObject("GET-PROPOSITION", "(DEFUN (GET-PROPOSITION PROPOSITION) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a proposition matching `relation-and-arguments' that\nhas been asserted (or inferred by forward chaining).  `relation-and-arguments'\nis a sequence containing objects and nulls.  The first argument must be the\nname of a relation.  A null value acts like a wild card.  If more than one \nproposition matches the input criteria, the selection among satisficing\npropositions is arbitrary.  This procedure is normally applied to single-valued\nrelations or functions.\")", ((cpp_function_code)(&getProposition)), NULL);
    defineFunctionObject("S-GET-PROPOSITION", "(DEFUN (S-GET-PROPOSITION PROPOSITION) ((RELATION-AND-ARGUMENTS STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a proposition matching `relation-and-arguments' that\nhas been asserted (or inferred by forward chaining).  `relation-and-arguments'\nis a string that begins with a left parenthesis, followed by a relation name, \none or more argument identifiers, and terminated by a right parenthesis.  Each\nargument identifier can be the name of a logical constant, a literal\nreference (e.g., a number), the null identifier, or a variable (an identifier that begins\nwith a question mark). Each occurrence of a null or a variable acts like a wild card.\nIf more than one proposition matches the input criteria, the selection among\nsatisficing propositions is arbitrary.  This procedure is normally applied to\nsingle-valued relations or functions.\n\nA module name of `null' or the\nempty string refers to the current module.  If no module can be found\nwith the name `module-" "name', then a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetProposition)), NULL);
    defineFunctionObject("GET-PROPOSITIONS", "(DEFUN (GET-PROPOSITIONS (PL-ITERATOR OF PROPOSITION)) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return propositions matching `relation-and-arguments' that\nhave been asserted (or inferred by forward chaining).  `relation-and-arguments'\nis a sequence containing objects and nulls.  The first argument must be the\nname of a relation.  A null value acts like a wild card.\")", ((cpp_function_code)(&getPropositions)), NULL);
    defineFunctionObject("S-GET-PROPOSITIONS", "(DEFUN (S-GET-PROPOSITIONS (PL-ITERATOR OF PROPOSITION)) ((RELATION-AND-ARGUMENTS STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return propositions matching `relation-and-arguments' that\nhave been asserted (or inferred by forward chaining).  `relation-and-arguments'\nis a string that begins with a left parenthesis, followed by a relation name, \none or more argument identifiers, and terminated by a right parenthesis.  Each\nargument identifier can be the name of a logical constant, a literal \nreference (e.g., a number), the null identifier, or a variable (an identifier that begins\nwith a question mark). Each occurrence of a null or a variable acts like a wild card.\n\nA module name of `null' or the\nempty string refers to the current module.  If no module can be found\nwith the name `module-name', then a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetPropositions)), NULL);
    defineFunctionObject("GET-BINARY-PROPOSITION", "(DEFUN (GET-BINARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG1 OBJECT) (ARG2 OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a proposition such that (`relation' `arg1' `arg2')\nis true.  The `relation' argument must be bound to a relation.  One or both\nof the `arg1' and `arg2' arguments may be set to NULL, which is interpreted\nas a wildcard. If more than one proposition matches the input criteria,\nthe selection is arbitrary.  This procedure is normally applied to single-valued\nrelations or functions.\")", ((cpp_function_code)(&getBinaryProposition)), NULL);
    defineFunctionObject("GET-BINARY-PROPOSITIONS", "(DEFUN (GET-BINARY-PROPOSITIONS (PL-ITERATOR OF PROPOSITION)) ((RELATION LOGIC-OBJECT) (ARG1 OBJECT) (ARG2 OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return propositions such that (`relation' `arg1' `arg2')\nis true.  The `relation' argument\nmust be bound to a relation.  One or both of the `arg1' and `arg2' arguments\nmay be set to NULL, which is interpreted as a wildcard.\")", ((cpp_function_code)(&getBinaryPropositions)), NULL);
    defineFunctionObject("GET-INFERRED-BINARY-PROPOSITION-VALUES", "(DEFUN (GET-INFERRED-BINARY-PROPOSITION-VALUES PL-ITERATOR) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return all values `v' such that (`relation' `arg' `v')\nhas been asserted or can be inferred.\")", ((cpp_function_code)(&getInferredBinaryPropositionValues)), NULL);
    defineFunctionObject("S-GET-INFERRED-BINARY-PROPOSITION-VALUES", "(DEFUN (S-GET-INFERRED-BINARY-PROPOSITION-VALUES PL-ITERATOR) ((RELATION-NAME STRING) (ARG-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return all values `v' such that (`relation-name' `arg-name' `v')\nhas been asserted or can be inferred.\n\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetInferredBinaryPropositionValues)), NULL);
    defineFunctionObject("GET-PROPOSITIONS-OF", "(DEFUN (GET-PROPOSITIONS-OF (PL-ITERATOR OF PROPOSITION)) ((OBJECT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return all propositions that have `object' among their arguments,\nand that are TRUE in the scope of the module `module'.\")", ((cpp_function_code)(&getPropositionsOf)), NULL);
    defineFunctionObject("S-GET-PROPOSITIONS-OF", "(DEFUN (S-GET-PROPOSITIONS-OF (PL-ITERATOR OF PROPOSITION)) ((OBJECT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return all propositions that have the object named `object-name' among\ntheir arguments, and that are TRUE in the scope of the module `module-name'.\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetPropositionsOf)), NULL);
    defineFunctionObject("GET-PROPOSITIONS-IN-MODULE", "(DEFUN (GET-PROPOSITIONS-IN-MODULE (PL-ITERATOR OF PROPOSITION)) ((MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return propositions that have been conceived in\nthe module `module'.\")", ((cpp_function_code)(&getPropositionsInModule)), NULL);
    defineFunctionObject("IS-TRUE-UNARY-PROPOSITION", "(DEFUN (IS-TRUE-UNARY-PROPOSITION BOOLEAN) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the proposition (`relation' `arg') has\nbeen asserted (or inferred by forward chaining).\")", ((cpp_function_code)(&isTrueUnaryProposition)), NULL);
    defineFunctionObject("IS-TRUE-BINARY-PROPOSITION", "(DEFUN (IS-TRUE-BINARY-PROPOSITION BOOLEAN) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the proposition (`relation' `arg' `value') has\nbeen asserted (or inferred by forward chaining).\")", ((cpp_function_code)(&isTrueBinaryProposition)), NULL);
    defineFunctionObject("IS-TRUE-PROPOSITION1", "(DEFUN (IS-TRUE-PROPOSITION1 BOOLEAN) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if a proposition (`relation' `args') has\nbeen asserted (or inferred by forward chaining).\")", ((cpp_function_code)(&isTrueProposition1)), NULL);
    defineFunctionObject("IS-TRUE-PROPOSITION", "(DEFUN (IS-TRUE-PROPOSITION BOOLEAN) ((PROPOSITION PROPOSITION) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if `proposition' is  TRUE in the module `module'.\")", ((cpp_function_code)(&isTrueProposition)), NULL);
    defineFunctionObject("S-IS-TRUE-PROPOSITION", "(DEFUN (S-IS-TRUE-PROPOSITION BOOLEAN) ((RELATION-AND-ARGUMENTS STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if a proposition that prints as the string\n`relation-and-arguments' is true in the module named `module-name'.\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sIsTrueProposition)), NULL);
    defineFunctionObject("IS-SUBRELATION", "(DEFUN (IS-SUBRELATION BOOLEAN) ((SUB LOGIC-OBJECT) (SUPER LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if `sub' is a subconcept/subrelation of `super'.\")", ((cpp_function_code)(&isSubrelation)), NULL);
    defineFunctionObject("GET-PROPER-SUBRELATIONS", "(DEFUN (GET-PROPER-SUBRELATIONS (PL-ITERATOR OF LOGIC-OBJECT)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return relations that specialize `relation'.\nNon-reflexive.\")", ((cpp_function_code)(&getProperSubrelations)), NULL);
    defineFunctionObject("GET-DIRECT-SUBRELATIONS", "(DEFUN (GET-DIRECT-SUBRELATIONS (PL-ITERATOR OF LOGIC-OBJECT)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return relations that directly specialize `relation'.\nNon-reflexive.\")", ((cpp_function_code)(&getDirectSubrelations)), NULL);
    defineFunctionObject("GET-PROPER-SUPERRELATIONS", "(DEFUN (GET-PROPER-SUPERRELATIONS (PL-ITERATOR OF LOGIC-OBJECT)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return relations that generalize `relation'.\nNon-reflexive.\")", ((cpp_function_code)(&getProperSuperrelations)), NULL);
    defineFunctionObject("GET-DIRECT-SUPERRELATIONS", "(DEFUN (GET-DIRECT-SUPERRELATIONS (PL-ITERATOR OF LOGIC-OBJECT)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return relations that directly generalize `relation'.\nNon-reflexive.\")", ((cpp_function_code)(&getDirectSuperrelations)), NULL);
    defineFunctionObject("IS-A", "(DEFUN (IS-A BOOLEAN) ((OBJECT OBJECT) (CONCEPT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if `object' is a member of the concept `concept'.\")", ((cpp_function_code)(&isA)), NULL);
  }
}

void helpStartupPli3() {
  {
    defineFunctionObject("GET-CONCEPT-INSTANCES", "(DEFUN (GET-CONCEPT-INSTANCES PL-ITERATOR) ((CONCEPT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return instances of the concept `concept'.\nInclude instances of subconcepts of `concept'.  Depending on `concept',\nthe return values could be (wrapped) literals.\")", ((cpp_function_code)(&getConceptInstances)), NULL);
    defineFunctionObject("S-GET-CONCEPT-INSTANCES", "(DEFUN (S-GET-CONCEPT-INSTANCES PL-ITERATOR) ((CONCEPT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return instances of concept `concept-name'.\nInclude instances of subconcepts of `concept-name'.  Depending on `concept-name',\nthe return values could be (wrapped) literals.\n\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetConceptInstances)), NULL);
    defineFunctionObject("GET-DIRECT-CONCEPT-INSTANCES", "(DEFUN (GET-DIRECT-CONCEPT-INSTANCES PL-ITERATOR) ((CONCEPT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return instances of concept `concept'.\nExclude instances of subconcepts of `concept'.  Depending on `concept',\nthe return values could be (wrapped) literals.\")", ((cpp_function_code)(&getDirectConceptInstances)), NULL);
    defineFunctionObject("S-GET-DIRECT-CONCEPT-INSTANCES", "(DEFUN (S-GET-DIRECT-CONCEPT-INSTANCES PL-ITERATOR) ((CONCEPT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return instances of concept `concept-name'.\nExclude instances of subconcepts of `concept-name'.  Depending on `concept-name',\nthe return values could be (wrapped) literals.\n\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetDirectConceptInstances)), NULL);
    defineFunctionObject("GET-CONCEPT-INSTANCES-MATCHING-VALUE", "(DEFUN (GET-CONCEPT-INSTANCES-MATCHING-VALUE PL-ITERATOR) ((CONCEPT LOGIC-OBJECT) (RELATION LOGIC-OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return members of concept `concept' that\nhave an attribute matching `value' for the binary relation `relation', i.e.,\n`(relation <result> value)' holds.\")", ((cpp_function_code)(&getConceptInstancesMatchingValue)), NULL);
    defineFunctionObject("GET-CONCEPT-INSTANCE-MATCHING-VALUE", "(DEFUN (GET-CONCEPT-INSTANCE-MATCHING-VALUE OBJECT) ((CONCEPT LOGIC-OBJECT) (RELATION LOGIC-OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a member of concept `concept' that\nhas an attribute matching `value' for the binary relation `relation', i.e.,\n`(relation <result> value)' holds.\")", ((cpp_function_code)(&getConceptInstanceMatchingValue)), NULL);
    defineFunctionObject("GET-TYPES", "(DEFUN (GET-TYPES (PL-ITERATOR OF LOGIC-OBJECT)) ((OBJECT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return all named concepts that `object' belongs to.\")", ((cpp_function_code)(&getTypes)), NULL);
    defineFunctionObject("GET-DIRECT-TYPES", "(DEFUN (GET-DIRECT-TYPES (PL-ITERATOR OF LOGIC-OBJECT)) ((OBJECT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return most specific concepts that `object' belongs to.\")", ((cpp_function_code)(&getDirectTypes)), NULL);
    defineFunctionObject("GET-RELATION-EXTENSION", "(DEFUN (GET-RELATION-EXTENSION (PL-ITERATOR OF PROPOSITION)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :DOCUMENTATION \"Return propositions that satisfy `relation'.\nInclude propositions that satisfy subrelations of `relation'.\")", ((cpp_function_code)(&getRelationExtension)), NULL);
    defineFunctionObject("S-GET-RELATION-EXTENSION", "(DEFUN (S-GET-RELATION-EXTENSION (PL-ITERATOR OF PROPOSITION)) ((RELATION-NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return propositions that satisfy the relation named\n`relation-name'.  Include propositions that satisfy subrelations of the relation.\")", ((cpp_function_code)(&sGetRelationExtension)), NULL);
    defineFunctionObject("GET-MODULE", "(DEFUN (GET-MODULE MODULE) ((NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a module named `name'.\")", ((cpp_function_code)(&getModule)), NULL);
    defineFunctionObject("GET-CURRENT-MODULE", "(DEFUN (GET-CURRENT-MODULE MODULE) ((ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the currently set module\")", ((cpp_function_code)(&getCurrentModule)), NULL);
    defineFunctionObject("GET-HOME-MODULE", "(DEFUN (GET-HOME-MODULE MODULE) ((OBJECT LOGIC-OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the module in which `object' was created.\")", ((cpp_function_code)(&getHomeModule)), NULL);
    defineFunctionObject("GET-MODULES", "(DEFUN (GET-MODULES (PL-ITERATOR OF MODULE)) ((KB-MODULES-ONLY? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Return all modules currently loaded into PowerLoom.  If `kb-modules-only?'\nis `true', then Stella modules that are used only for program code are\nnot included in the list.\")", ((cpp_function_code)(&getModules)), NULL);
    defineFunctionObject("CREATE-MODULE", "(DEFUN (CREATE-MODULE MODULE) ((NAME STRING) (PARENT MODULE) (CASE-SENSITIVE? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Creates a new module `name' as a child of `parent'.  The flag\n`case-sensitive?' controls whether names read in this module will be\ncase sensitive or not.\")", ((cpp_function_code)(&createModule)), NULL);
    defineFunctionObject("S-CREATE-MODULE", "(DEFUN (S-CREATE-MODULE MODULE) ((NAME STRING) (PARENT-NAME STRING) (CASE-SENSITIVE? BOOLEAN) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Creates a new module `name' as a child of `parent-name'.  The flag\n`case-sensitive?' controls whether names read in this module will be\ncase sensitive or not.\")", ((cpp_function_code)(&sCreateModule)), NULL);
    defineFunctionObject("CHANGE-MODULE", "(DEFUN (CHANGE-MODULE MODULE) ((MODULE MODULE)) :PUBLIC? TRUE :DOCUMENTATION \"Set the current module to `module' and return it.\nIf `module' is `null', then no switch is performed and the current\nmodule is returned.\")", ((cpp_function_code)(&changeModule)), NULL);
    defineFunctionObject("S-CHANGE-MODULE", "(DEFUN (S-CHANGE-MODULE MODULE) ((NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Set the current module to the module named `name'.\nThe return value is the module named `name' unless `name' is null or\nthe empty string.  In that case, the current module is returned.\nIf no module named `name' exists, a Stella `no-such-context-exception'\nis thrown.\")", ((cpp_function_code)(&sChangeModule)), NULL);
    defineFunctionObject("CLEAR-MODULE", "(DEFUN (CLEAR-MODULE MODULE) ((MODULE MODULE)) :PUBLIC? TRUE :DOCUMENTATION \"Destroy the contents of the module `module' as well as\nthe contents of all of its children, recursively.\")", ((cpp_function_code)(&clearModule)), NULL);
    defineFunctionObject("S-CLEAR-MODULE", "(DEFUN (S-CLEAR-MODULE MODULE) ((NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Destroy the contents of the module named `name', as\nwell as the contents of all of its children, recursively.  If no module\nnamed `name' exists, a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sClearModule)), NULL);
    defineFunctionObject("GET-CHILD-MODULES", "(DEFUN (GET-CHILD-MODULES (PL-ITERATOR OF MODULE)) ((MODULE MODULE)) :PUBLIC? TRUE :DOCUMENTATION \"Return the modules that are immediate children of `module'.\")", ((cpp_function_code)(&getChildModules)), NULL);
    defineFunctionObject("S-GET-CHILD-MODULES", "(DEFUN (S-GET-CHILD-MODULES (PL-ITERATOR OF MODULE)) ((NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the modules that are immediate children of module `name'.\nIf no module named `name' exists, a Stella `no-such-context-exception'\nis thrown.\")", ((cpp_function_code)(&sGetChildModules)), NULL);
    defineFunctionObject("GET-PARENT-MODULES", "(DEFUN (GET-PARENT-MODULES (PL-ITERATOR OF MODULE)) ((MODULE MODULE)) :PUBLIC? TRUE :DOCUMENTATION \"Return the modules that are immediate parents of `module'.\")", ((cpp_function_code)(&getParentModules)), NULL);
    defineFunctionObject("S-GET-PARENT-MODULES", "(DEFUN (S-GET-PARENT-MODULES (PL-ITERATOR OF MODULE)) ((NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the modules that are immediate parents of module `name'.\nIf no module named `name' exists, a Stella `no-such-context-exception'\nis thrown.\")", ((cpp_function_code)(&sGetParentModules)), NULL);
    defineFunctionObject("GENERATE-UNIQUE-NAME", "(DEFUN (GENERATE-UNIQUE-NAME STRING) ((PREFIX STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Generates a name based on `prefix' with a number appended that\nis not currently in use in `module.'  In a non-case-sensitive module, the returned\nname will be all upper case (This latter feature may change!)\")", ((cpp_function_code)(&generateUniqueName)), NULL);
    defineFunctionObject("CREATE-KEYWORD", "(DEFUN (CREATE-KEYWORD KEYWORD) ((NAME STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Returns the Stella keyword `name', creating it if\nnecessary.  `name' is treated case-sensitively.  This should\ngenerally not be necessary to do.\")", ((cpp_function_code)(&createKeyword)), NULL);
    defineFunctionObject("CREATE-SYMBOL", "(DEFUN (CREATE-SYMBOL SYMBOL) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Returns the Stella symbol `name' visible in `module',\ncreating it if necessary.  `name' is ALWAYS treated case-sensitively,\neven if `module' is case insensitive. This should generally not be\nnecessary to do.\")", ((cpp_function_code)(&createSymbol)), NULL);
    defineFunctionObject("CREATE-OBJECT", "(DEFUN (CREATE-OBJECT LOGIC-OBJECT) ((NAME STRING) (CONCEPT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create an object named `name' of type `concept' in the designated\nmodule.  Both `name' and `concept' can be `null'.  If `name' is `null' then an\nobject will be created with a new, non-conflicting name based on the name of\n`concept', or system-generated if no concept is specified.  If `concept' is\n`null', then the object will be of type THING.  It is an error to create an\nobject with the same name as an existing object.\n\nNote that the string can be a qualified name, in which case the object\nwill be created in the module specified, but with a name as determined\nby the qualified name.  Vertical bars in the name string are interpreted\nas Stella escape characters.\n\nNote that because names in modules that are not case-sensitive are\ncanonicalized, the name of the returned object may not match `name'\nexactly.\n\nReturn the object.\")", ((cpp_function_code)(&createObject)), NULL);
    defineFunctionObject("S-CREATE-OBJECT", "(DEFUN (S-CREATE-OBJECT LOGIC-OBJECT) ((NAME STRING) (CONCEPT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create an object named `name' of type `concept-name' in the designated\nmodule.  Both `name' and `concept-name' can be null strings.  If `name' is a null string\nthen an object will be created with a new, non-conflicting name based on `concept-name', or\nsystem-generated if no concept nameis specified.  If `concept-name' is the null string, then\nthe object will be of type THING.\n\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\n\nNote that because names in modules that are not case-sensitive are canonicalized,\nthe name of the returned object may not match `name' exactly.\n\nReturn the object.\")", ((cpp_function_code)(&sCreateObject)), NULL);
    defineFunctionObject("CREATE-CONCEPT", "(DEFUN (CREATE-CONCEPT LOGIC-OBJECT) ((NAME STRING) (PARENT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create a concept named `name' in the designated `module', with the\ndesignated `parent' superconcept (which can be left undefined).  Additional\nsuperconcepts can be added via assertions of the `subset-of' relation.  Note\nthat a specified `parent' concept needs to be created separately.\n\nNote that because names in modules that are not case-sensitive are canonicalized,\nthe name of the returned object may not match `name' exactly.\")", ((cpp_function_code)(&createConcept)), NULL);
    defineFunctionObject("S-CREATE-CONCEPT", "(DEFUN (S-CREATE-CONCEPT LOGIC-OBJECT) ((NAME STRING) (PARENT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create a concept named `name' in the designated module, with\nwith the concept named `parent-name' as superconcept (which can be left\nundefined).  Additional superconcepts can be added via assertions of the\n`subset-of' relation.  Note that a specified parent concept needs to be\ncreated separately.\n\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\n\nNote that because names in modules that are not case-sensitive are canonicalized,\nthe name of the returned object may not match `name' exactly.\")", ((cpp_function_code)(&sCreateConcept)), NULL);
    defineFunctionObject("CREATE-RELATION", "(DEFUN (CREATE-RELATION LOGIC-OBJECT) ((NAME STRING) (ARITY INTEGER) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create a relation named `name' with arity `arity' in the\ndesignated module.  Domain and range information can be added via assertions\nof `nth-domain' (or `domain' and `range') relations.\n\nNote that because names in modules that are not case-sensitive are canonicalized,\nthe name of the returned object may not match `name' exactly.\")", ((cpp_function_code)(&createRelation)), NULL);
    defineFunctionObject("S-CREATE-RELATION", "(DEFUN (S-CREATE-RELATION LOGIC-OBJECT) ((NAME STRING) (ARITY INTEGER) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create a relation named `name' with arity `arity' in the\ndesignated module.  Domain and range information can be added via assertions\nof `nth-domain' (or `domain' and `range') relations.\n\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\n\nNote that because names in modules that are not case-sensitive are canonicalized,\nthe name of the returned object may not match `name' exactly.\")", ((cpp_function_code)(&sCreateRelation)), NULL);
    defineFunctionObject("CREATE-FUNCTION", "(DEFUN (CREATE-FUNCTION LOGIC-OBJECT) ((NAME STRING) (ARITY INTEGER) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create a function named `name' with arity `arity'  in the designated \n`module'.  Domain and range information can be added via assertions of\n`nth-domain' (or `domain' and `range') relations.\n\nNote that because names in modules that are not case-sensitive are canonicalized,\nthe name of the returned object may not match `name' exactly.\")", ((cpp_function_code)(&createFunction)), NULL);
    defineFunctionObject("S-CREATE-FUNCTION", "(DEFUN (S-CREATE-FUNCTION LOGIC-OBJECT) ((NAME STRING) (ARITY INTEGER) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create a function named `name' with arity `arity' in the designated \nmodule.  Domain and range information can be added via assertions of\n`domain', `nth-domain' and `range' relations.\n\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\n\nNote that because names in modules that are not case-sensitive are canonicalized,\nthe name of the returned object may not match `name' exactly.\")", ((cpp_function_code)(&sCreateFunction)), NULL);
    defineFunctionObject("REGISTER-SPECIALIST-FUNCTION", "(DEFUN REGISTER-SPECIALIST-FUNCTION ((NAME STRING) (FUNCTION-REFERENCE FUNCTION-CODE) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Register `name' as a function name in `module' which will invoke the\nnative code procedure described by `function-reference.'  The `name'\nis a fully-qualified name which will be interpreted by the normal\nrules for reading names in PowerLoom.  The function must conform\nto the signature for specialist functions.\n\nThe exact form of `function-reference' depends on the underlying\nprogramming language.  The following type mappings are used:\n          C++:  \n  Common Lisp:  FUNCTION   (result of #' or (FUNCTION ...))\n         Java:  java.lang.reflect.Method\")", ((cpp_function_code)(&registerSpecialistFunction)), NULL);
    defineFunctionObject("S-REGISTER-SPECIALIST-FUNCTION", "(DEFUN S-REGISTER-SPECIALIST-FUNCTION ((NAME STRING) (NATIVE-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Register `name' as a function name in the module named `module-name'.\nThis function will the native code named `native-name'.  The `name'\nis a fully-qualified name which will be interpreted by the normal\nrules for reading names in PowerLoom.  The `native-name' will be\nprocessed in a manner that depends on the underlying programming\nlanguage.  The following type mappings are used:\n          C++:  Not available.  Error signaled.\n  Common Lisp:  The native-name is read by READ-FROM-STRING and then\n                the SYMBOL-FUNCTION is taken.\n         Java:  A fully package-qualified name is required.  It is\n                looked up using the Reflection tools.\nThe function found must conform to the signature for specialist functions.\")", ((cpp_function_code)(&sRegisterSpecialistFunction)), NULL);
    defineFunctionObject("CREATE-ENUMERATED-LIST", "(DEFUN (CREATE-ENUMERATED-LIST LOGIC-OBJECT) ((MEMBERS CONS) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create a logical term that denotes a list containing `members' in\n`module' using `environment'.  Useful for passing lists as arguments\nto parameterized queries.\")", ((cpp_function_code)(&createEnumeratedList)), NULL);
    defineFunctionObject("CREATE-ENUMERATED-SET", "(DEFUN (CREATE-ENUMERATED-SET LOGIC-OBJECT) ((MEMBERS CONS) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create a logical term that denotes the enumerated set containing `members'\nin `module' using `environment'.\")", ((cpp_function_code)(&createEnumeratedSet)), NULL);
    defineFunctionObject("DESTROY-OBJECT", "(DEFUN DESTROY-OBJECT ((OBJECT LOGIC-OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Delete the object `object', retracting all facts attached to it.\")", ((cpp_function_code)(&destroyObject)), NULL);
    defineFunctionObject("S-DESTROY-OBJECT", "(DEFUN S-DESTROY-OBJECT ((OBJECT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Delete the object named `object-name', retracting all facts\nattached to it.\n\nA module name of `null' or the empty string refers to the current module. \nIf no module can be found with the name `module-name', then a Stella \n`no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sDestroyObject)), NULL);
    defineFunctionObject("ASSERT-UNARY-PROPOSITION", "(DEFUN (ASSERT-UNARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Assert that the proposition (`relation' `arg') is TRUE in `module'.  Return the asserted proposition.\")", ((cpp_function_code)(&assertUnaryProposition)), NULL);
    defineFunctionObject("ASSERT-BINARY-PROPOSITION", "(DEFUN (ASSERT-BINARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Assert that the proposition (`relation' `arg' `value') is TRUE\nin `module'.  Return the asserted proposition.\")", ((cpp_function_code)(&assertBinaryProposition)), NULL);
    defineFunctionObject("ASSERT-NARY-PROPOSITION", "(DEFUN (ASSERT-NARY-PROPOSITION PROPOSITION) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Assert that the proposition represented by the list ` relation-and-arguments' satisfies\nthe relation `relation'.\")", ((cpp_function_code)(&assertNaryProposition)), NULL);
    defineFunctionObject("RETRACT-UNARY-PROPOSITION", "(DEFUN (RETRACT-UNARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Retract that the proposition (`relation' `arg') is TRUE in `module'.  Return the asserted proposition.\")", ((cpp_function_code)(&retractUnaryProposition)), NULL);
    defineFunctionObject("RETRACT-BINARY-PROPOSITION", "(DEFUN (RETRACT-BINARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Retract that the proposition (`relation' `arg' `value') is TRUE\nin `module'.  Return the asserted proposition.\")", ((cpp_function_code)(&retractBinaryProposition)), NULL);
    defineFunctionObject("RETRACT-NARY-PROPOSITION", "(DEFUN (RETRACT-NARY-PROPOSITION PROPOSITION) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Retract the proposition that `arguments' satisfies\nthe relation `relation'.\")", ((cpp_function_code)(&retractNaryProposition)), NULL);
    defineFunctionObject("ASSERT-PROPOSITION", "(DEFUN (ASSERT-PROPOSITION PROPOSITION) ((PROPOSITION PROPOSITION) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Assert that the proposition `proposition' is true in `module'.\nReturn the asserted proposition.\")", ((cpp_function_code)(&assertProposition)), NULL);
    defineFunctionObject("S-ASSERT-PROPOSITION", "(DEFUN (S-ASSERT-PROPOSITION (PL-ITERATOR OF PROPOSITION)) ((SENTENCE STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Assert that the logical sentence `sentence' is true in the module\nnamed `module-name'.  A module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\n\nReturn an iterator of the propositions resulting from sentence.\")", ((cpp_function_code)(&sAssertProposition)), NULL);
    defineFunctionObject("RETRACT-PROPOSITION", "(DEFUN (RETRACT-PROPOSITION PROPOSITION) ((PROPOSITION PROPOSITION) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Retract the truth of the proposition `proposition' in `module'.\nReturn the retracted proposition.\")", ((cpp_function_code)(&retractProposition)), NULL);
    defineFunctionObject("S-RETRACT-PROPOSITION", "(DEFUN (S-RETRACT-PROPOSITION (PL-ITERATOR OF PROPOSITION)) ((SENTENCE STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Retract the truth of the logical sentence `sentence' in the module named\n`module-name'.  A module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\n\nReturn an iterator of the retracted propositions resulting from sentence.\")", ((cpp_function_code)(&sRetractProposition)), NULL);
    defineFunctionObject("CONCEIVE", "(DEFUN (CONCEIVE (PL-ITERATOR OF PROPOSITION)) ((SENTENCE OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create one or more proposition objects from the sentence `sentence'\nin the  module `module'.  Return an iterator of the propositions.\nIf any of the new propositions has the same structure as an already existing\nproposition, an automatic check for duplicates will return the pre-existing\nproposition.  Multiple propositions may be returned for a single sentence\nbecause of normalization of equivalences, conjunctions, etc.\n\nSignals a `Proposition-Error' if PowerLoom could not conceive `sentence'.\")", ((cpp_function_code)(&conceive)), NULL);
    defineFunctionObject("S-CONCEIVE", "(DEFUN (S-CONCEIVE (PL-ITERATOR OF PROPOSITION)) ((SENTENCE STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Create one or more proposition objects from the sentence `sentence'\nin the  module named `module-name'.  Return an iterator of the propositions.\nIf any of the new propositions has the same structure as an already existing\nproposition, an automatic check for duplicates will return the pre-existing\nproposition.  Multiple propositions may be returned for a single sentence\nbecause of normalization of equivalences, conjunctions, etc.\n\nA module name of `null' or the empty string refers to the current module.\nIf no module can be found with the name `module-name', then a Stella\n`No-Such-Context-Exception' is thrown.\n\nSignals a `Proposition-Error' if PowerLoom could not conceive `sentence'.\")", ((cpp_function_code)(&sConceive)), NULL);
    defineFunctionObject("GET-RULES", "(DEFUN (GET-RULES (PL-ITERATOR OF PROPOSITION)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return rules attached to the concept/relation `relation'\nin either antecedent or consequent position.\")", ((cpp_function_code)(&getRules)), NULL);
    defineFunctionObject("S-GET-RULES", "(DEFUN (S-GET-RULES (PL-ITERATOR OF PROPOSITION)) ((RELATION-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return rules attached to the concept/relation named\n`relation-name' found in the module named `module-name'.\n\nA module name of `null' or the empty string refers to the current module.\nIf no module can be found with the name `module-name', then a Stella\n`No-Such-Context-Exception' is thrown.\")", ((cpp_function_code)(&sGetRules)), NULL);
    defineFunctionObject("S-PRINT-RULES", "(DEFUN S-PRINT-RULES ((NAME STRING) (STREAM OUTPUT-STREAM) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :DOCUMENTATION \"Print rules attached to the concept/relation named `name'.\n\nA module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sPrintRules)), NULL);
    defineFunctionObject("RUN-FORWARD-RULES", "(DEFUN RUN-FORWARD-RULES ((MODULE OBJECT) (FORCE? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Run forward inference rules in module `module'.\nIf `module' is NULL, the\ncurrent module will be used.  If forward inferencing is already up-to-date\nin the designated module, no additional inferencing will occur, unless `force'\nis set to TRUE, in which case all forward rules are run or rerun.\n\nCalling `run-forward-rules' temporarily puts the module into a mode where\nfuture assertional (monotonic) updates will trigger additional forward\ninference.  Once a non-monotonic update is performed, i.e., a retraction\nor clipping of relation value, all cached forward inferences will be discarded\nand forward inferencing will be disabled until this function is\ncalled again.\")", ((cpp_function_code)(&runForwardRules)), NULL);
    defineFunctionObject("GET-ARITY", "(DEFUN (GET-ARITY INTEGER) ((RELATION LOGIC-OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the arity of the relation `relation'.\")", ((cpp_function_code)(&getArity)), NULL);
    defineFunctionObject("S-GET-ARITY", "(DEFUN (S-GET-ARITY INTEGER) ((RELATION-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the arity of the relation named `relation-name'.\n\n A module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetArity)), NULL);
    defineFunctionObject("GET-DOMAIN", "(DEFUN (GET-DOMAIN LOGIC-OBJECT) ((RELATION LOGIC-OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the type (a concept) for the first argument to the binary\nrelation `relation'.\")", ((cpp_function_code)(&getDomain)), NULL);
  }
}

void helpStartupPli4() {
  {
    defineFunctionObject("S-GET-DOMAIN", "(DEFUN (S-GET-DOMAIN LOGIC-OBJECT) ((RELATION-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the type (concept) for the first argument to the binary\nrelation `relation-name'.\n\nA module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetDomain)), NULL);
    defineFunctionObject("GET-RANGE", "(DEFUN (GET-RANGE LOGIC-OBJECT) ((RELATION LOGIC-OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the type (a concept) for fillers of the binary relation\n`relation'.\")", ((cpp_function_code)(&getRange)), NULL);
    defineFunctionObject("S-GET-RANGE", "(DEFUN (S-GET-RANGE LOGIC-OBJECT) ((RELATION-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the type (a concept) for fillers of the binary relation\n`relation-name'.\n\nA module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetRange)), NULL);
    defineFunctionObject("GET-NTH-DOMAIN", "(DEFUN (GET-NTH-DOMAIN LOGIC-OBJECT) ((RELATION LOGIC-OBJECT) (N INTEGER)) :PUBLIC? TRUE :DOCUMENTATION \"Return the type (a concept) for the the nth argument of the\nrelation `relation'.  Counting starts at zero.\")", ((cpp_function_code)(&getNthDomain)), NULL);
    defineFunctionObject("S-GET-NTH-DOMAIN", "(DEFUN (S-GET-NTH-DOMAIN LOGIC-OBJECT) ((RELATION-NAME STRING) (N INTEGER) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the type (a concept) for the nth argument of the relation\nnamed `relation-name'.  Counting starts at zero.\n\nA module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sGetNthDomain)), NULL);
    defineFunctionObject("LOAD", "(DEFUN LOAD ((FILENAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Read logic commands from the file named `filename' and evaluate them.\nThe file should begin with an `in-module' declaration that specifies\nthe module within which all remaining commands are to be evaluated\nThe remaining commands are evaluated one-by-one, applying the function\n`evaluate' to each of them.\")", ((cpp_function_code)(&load)), NULL);
    defineFunctionObject("LOAD-STREAM", "(DEFUN LOAD-STREAM ((STREAM INPUT-STREAM) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Read logic commands from the STELLA stream `stream' and evaluate them.\nThe stream should begin with an `in-module' declaration that specifies\nthe module within which all remaining commands are to be evaluated\nThe remaining commands are evaluated one-by-one, applying the function\n`evaluate' to each of them.\")", ((cpp_function_code)(&loadStream)), NULL);
    defineFunctionObject("LOAD-NATIVE-STREAM", "(DEFUN LOAD-NATIVE-STREAM ((STREAM NATIVE-INPUT-STREAM) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Read logic commands from the native input stream `stream' and evaluate them.\nAssumes `stream' is a line-buffered stream which is a safe compromise but does\nnot generate the best efficiency for block-buffered streams such as files.\nThe stream should begin with an `in-module' declaration that specifies\nthe module within which all remaining commands are to be evaluated\nThe remaining commands are evaluated one-by-one, applying the function\n`evaluate' to each of them.\")", ((cpp_function_code)(&loadNativeStream)), NULL);
    defineFunctionObject("SAVE-MODULE", "(DEFUN SAVE-MODULE ((MODULE MODULE) (FILENAME STRING) (IFEXISTS STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Save the contents of the module `mod' into a file named `filename'.\nIf a file named `filename' already exists, then the action taken depends on the\nvalue of `ifexists'.  Possible values are \\\"ASK\\\", \\\"REPLACE\\\", \\\"WARN\\\" and \\\"ERROR\\\":\n\n  REPLACE => Means overwrite without warning.\n  WARN    => Means overwrite with a warning.\n  ERROR   => Means don't overwrite, signal an error instead.\n  ASK     => Ask the user whether to overwrite or not.  If not overwritten, an \n             exception is thrown.\")", ((cpp_function_code)(&saveModule)), NULL);
    defineFunctionObject("S-SAVE-MODULE", "(DEFUN S-SAVE-MODULE ((MODULE-NAME STRING) (FILENAME STRING) (IFEXISTS STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Save the contents of the module `module-name' into a file named `filename'.\nIf a file named `filename' already exists, then the action taken depends on the\nvalue of `ifexists'.  Possible values are \\\"ASK\\\", \\\"REPLACE\\\", \\\"WARN\\\" and \\\"ERROR\\\":\n\n  REPLACE => Means overwrite without warning.\n  WARN    => Means overwrite with a warning.\n  ERROR   => Means don't overwrite, signal an error instead.\n  ASK     => Ask the user whether to overwrite or not.  If not overwritten, an\n             exception is thrown.\n\nA module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sSaveModule)), NULL);
    defineFunctionObject("GET-PREDICATE", "(DEFUN (GET-PREDICATE LOGIC-OBJECT) ((PROP PROPOSITION)) :PUBLIC? TRUE :DOCUMENTATION \"Return the concept or relation predicate for\nthe proposition `prop'.\")", ((cpp_function_code)(&getPredicate)), NULL);
    defineFunctionObject("GET-COLUMN-COUNT", "(DEFUN (GET-COLUMN-COUNT INTEGER) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the number of columns in `obj', which must\nbe of type proposition, cons, vector or PL-iterator.  For a proposition,\nthe number includes both the predidate and arguments. For the PL-iterator\ncase,the number of columns is for the current value of the iterator.\n\nFor non sequence objects, the column count is zero.\")", ((cpp_function_code)(&getColumnCount)), NULL);
    defineFunctionObject("GET-NTH-VALUE", "(DEFUN (GET-NTH-VALUE OBJECT) ((SEQUENCE OBJECT) (N INTEGER) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the value in the `nth' column of `sequence'.\nCounting starts at zero.  Unless `n' is zero, `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the number\nof columns is for the current value of the iterator.\n\nAs a special case, a column number of zero will also return `sequence' itself\nif it is not one of the types enumerated above.  This is done to allow the\nuse of `get-nth-value' on PL-iterators with only a single return variable.\")", ((cpp_function_code)(&getNthValue)), NULL);
    defineFunctionObject("GET-NTH-STRING", "(DEFUN (GET-NTH-STRING STRING) ((SEQUENCE OBJECT) (N INTEGER) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a string representation of the value in the `nth' column of\n`sequence'. Counting starts at zero.   Unless `n' is zero, `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the\nthe current value pointed to by the iterator is used.  This will always\nsucceed, even if the `nth' value is not a string object.  In that case, a\nstring reprensentation will be returned.\n\n\nAs a special case, a column number of zero will also return `sequence' itself\nas a string if it is not one of the types enumerated above.  This is done to \nallow the use of `get-nth-string' on PL-iterators with only a single return variable.\")", ((cpp_function_code)(&getNthString)), NULL);
    defineFunctionObject("GET-NTH-INTEGER", "(DEFUN (GET-NTH-INTEGER INTEGER) ((SEQUENCE OBJECT) (N INTEGER) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return an integer representation of the value in the `nth' column of\n`sequence'. Counting starts at zero.   Unless `n' is zero, `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the\nthe current value pointed to by the iterator is used.  If this is not\nan integer value, then an exception will be thrown.\n\n\nAs a special case, a column number of zero will also return the integer\nvalue of `sequence' itself if it is not one of the types enumerated\nabove.   This allows the use of `get-nth-integer' on PL-iterators with\nonly a single return variable.  If  `sequence' cannot be turned into an\ninteger, an exception will be thrown.\")", ((cpp_function_code)(&getNthInteger)), NULL);
    defineFunctionObject("GET-NTH-FLOAT", "(DEFUN (GET-NTH-FLOAT FLOAT) ((SEQUENCE OBJECT) (N INTEGER) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return the floating point value in the `nth' column of\n`sequence'. Counting starts at zero.  `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the\nthe current value pointed to by the iterator is used.  If this is not\na floating point value, then an exception will be thrown.\n\n\nAs a special case, a column number of zero will also return the floating\npoint value of `sequence' itself if it is not one of the types enumerated\nabove.  This allows the use of `get-nth-float' on PL-iterators with only\na single return variable.    If  `sequence' cannot be turned into a floating\npoint value, an exception will be thrown.\")", ((cpp_function_code)(&getNthFloat)), NULL);
    defineFunctionObject("GET-NTH-LOGIC-OBJECT", "(DEFUN (GET-NTH-LOGIC-OBJECT LOGIC-OBJECT) ((SEQUENCE OBJECT) (N INTEGER) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Return a logic object representation of the value in the `nth' column\nof `sequence'.  Counting starts at zero.   Unless `n' is zero, `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the\nthe current value pointed to by the iterator is used.  A zero column number\nreturns the proposition's relational predicate.  If the return value is\nnot a LOGIC-OBJECT, an exception is thrown.\n\nAs a special case, a column number of zero will also return `sequence' itself\nif it is not one of the types enumerated above.  This is done to allow the\nuse of `get-nth-value' on PL-iterators with only a single return variable.\nIf `sequence' is not a LOGIC-OBJECT, an exception is thrown.\")", ((cpp_function_code)(&getNthLogicObject)), NULL);
    defineFunctionObject("GET-ENUMERATED-COLLECTION-MEMBERS", "(DEFUN (GET-ENUMERATED-COLLECTION-MEMBERS CONS) ((COLLECTION OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Returns the members of an enumerated collection.  This works on all types\nof collection, i.e., sets and lists\")", ((cpp_function_code)(&getEnumeratedCollectionMembers)), NULL);
    defineFunctionObject("EVALUATE", "(DEFUN (EVALUATE OBJECT) ((COMMAND OBJECT) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Evaluate the command `command' within `module' and return\nthe result. Currently, only the evaluation of (possibly nested) commands and\nglobal variables is supported.  Commands are simple to program in Common Lisp,\nsince they are built into the language, and relatively awkward in Java and C++.\nUsers of either of those languages are more likely to want to call `s-evaluate'.\")", ((cpp_function_code)(&evaluate)), NULL);
    defineFunctionObject("S-EVALUATE", "(DEFUN (S-EVALUATE OBJECT) ((COMMAND STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Evaluate the command represented by the string `command' within `module' and\nreturn the result.  Currently, only the evaluation of (possibly nested) commands and\nglobal variables is supported.\n\n A module name of `null' or the empty string refers to the\ncurrent module.  If no module can be found with the name `module-name',\nthen a Stella `no-such-context-exception' is thrown.\")", ((cpp_function_code)(&sEvaluate)), NULL);
    defineFunctionObject("IS-LOGIC-OBJECT", "(DEFUN (IS-LOGIC-OBJECT BOOLEAN) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Test whether `obj' is of type LOGIC-OBJECT\")", ((cpp_function_code)(&isLogicObject)), NULL);
    defineFunctionObject("IS-INTEGER", "(DEFUN (IS-INTEGER BOOLEAN) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Test whether `obj' is of type INTEGER\")", ((cpp_function_code)(&isInteger)), NULL);
    defineFunctionObject("IS-FLOAT", "(DEFUN (IS-FLOAT BOOLEAN) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Test whether `obj' is of type FLOAT (double)\")", ((cpp_function_code)(&isFloat)), NULL);
    defineFunctionObject("IS-NUMBER", "(DEFUN (IS-NUMBER BOOLEAN) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Test whether `obj' is of type NUMBER.  This can\nbe either an integer or a floating point number.  One key characteristic\nis that 'object-to-integer' and `object-to-float' will both work on it.\")", ((cpp_function_code)(&isNumber)), NULL);
    defineFunctionObject("IS-STRING", "(DEFUN (IS-STRING BOOLEAN) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Test whether `obj' is of type STRING\")", ((cpp_function_code)(&isString)), NULL);
    defineFunctionObject("IS-ENUMERATED-COLLECTION", "(DEFUN (IS-ENUMERATED-COLLECTION BOOLEAN) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Test whether `obj' is an enumerated collection.  This\nsubsumes both sets and lists.\")", ((cpp_function_code)(&isEnumeratedCollection)), NULL);
    defineFunctionObject("IS-ENUMERATED-SET", "(DEFUN (IS-ENUMERATED-SET BOOLEAN) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Test whether `obj' is an enumerated set.\")", ((cpp_function_code)(&isEnumeratedSet)), NULL);
    defineFunctionObject("IS-ENUMERATED-LIST", "(DEFUN (IS-ENUMERATED-LIST BOOLEAN) ((OBJ OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Test whether `obj' is an enumerated list\")", ((cpp_function_code)(&isEnumeratedList)), NULL);
    defineFunctionObject("IS-TRUE", "(DEFUN (IS-TRUE BOOLEAN) ((TV TRUTH-VALUE)) :PUBLIC? TRUE :DOCUMENTATION \"Tests whether `tv' is a true truth value.  It can be true\neither absolutely or by default.\")", ((cpp_function_code)(&isTrue)), NULL);
    defineFunctionObject("IS-FALSE", "(DEFUN (IS-FALSE BOOLEAN) ((TV TRUTH-VALUE)) :PUBLIC? TRUE :DOCUMENTATION \"Tests whether `tv' is a false truth value.  It can be false\neither absolutely or by default.\")", ((cpp_function_code)(&isFalse)), NULL);
    defineFunctionObject("IS-UNKNOWN", "(DEFUN (IS-UNKNOWN BOOLEAN) ((TV TRUTH-VALUE)) :PUBLIC? TRUE :DOCUMENTATION \"Tests whether `tv' is an unknown truth value.\")", ((cpp_function_code)(&isUnknown)), NULL);
    defineFunctionObject("IS-INCONSISTENT", "(DEFUN (IS-INCONSISTENT BOOLEAN) ((TV TRUTH-VALUE)) :PUBLIC? TRUE :DOCUMENTATION \"Tests whether `tv' is an inconsistent truth value.\")", ((cpp_function_code)(&isInconsistent)), NULL);
    defineFunctionObject("IS-STRICT", "(DEFUN (IS-STRICT BOOLEAN) ((TV TRUTH-VALUE)) :PUBLIC? TRUE :DOCUMENTATION \"Tests whether `tv' is a strict (non-default) truth value.\")", ((cpp_function_code)(&isStrict)), NULL);
    defineFunctionObject("IS-DEFAULT", "(DEFUN (IS-DEFAULT BOOLEAN) ((TV TRUTH-VALUE)) :PUBLIC? TRUE :DOCUMENTATION \"Tests whether `tv' is a default truth value.\")", ((cpp_function_code)(&isDefault)), NULL);
    defineFunctionObject("ASK", "(DEFUN (ASK TRUTH-VALUE) ((QUERY CONS) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :DOCUMENTATION \"Returns a truth value for `query' in `module' and `environment'.\n`query' has the same syntax as the PowerLoom `ask' command (which see)\nbut with the `ask' operator omitted.  For example, here are some legal\n`query' arguments:\n	 \n    ((happy Fred))\n    ((happy Fred) :inference-level :assertion)\n    ((happy Fred) :inference-level :assertion :timeout 1.0)\n	\nAs a convenience, a `query' argument whose first element is a symbol is\ninterpreted as a sentence that is queried without any options.  For example:\n	 \n    (happy Fred)\n	\nis a legal `query' argument.  Note that for a setence whose relation is a list\nitself, e.g., `((FruitFn BananaTree) MyBanana)' this shortcut is not available,\nthat is, in that case an extra level of list nesting is always necessary.\nThe returned truth value represents the logical truth of the queried sentence\nas determined by PowerLoom.  It can be be tested via the functions " "`is-true',\n`is-false' and `is-unknown' (which see).\" :PUBLIC? TRUE)", ((cpp_function_code)(&ask)), NULL);
    defineFunctionObject("S-ASK", "(DEFUN (S-ASK TRUTH-VALUE) ((QUERY STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :DOCUMENTATION \"Returns a truth value for `query' in module `module-name' and `environment'.\n`query' has the same syntax as the PowerLoom `ask' command (which see) but\nwith the `ask' operator omitted.  Different from the PLI `ask' function, `s-ask'\ndoes not expect a top-level pair of parentheses.  For example, here are some legal\n`query' arguments:\n	 \n    \\\"(happy Fred)\\\"\n    \\\"(happy Fred) :inference-level :assertion\\\"\n    \\\"(happy Fred) :inference-level :assertion :timeout 1.0\\\"\n	\nNames in `query' will be interpreted relative to module `module-name'.\nA null `module-name' or the empty string refers to the current module.\nIf no module can be found with the name `module-name', then a STELLA\n`no-such-context-exception' is thrown.\nThe returned truth value represents the logical truth of the queried sentence\nas determined by PowerLoom.  It can be be tested via the functions `is-true',\n`is-false" "' and `is-unknown' (which see).\" :PUBLIC? TRUE)", ((cpp_function_code)(&sAsk)), NULL);
    defineFunctionObject("RETRIEVE", "(DEFUN (RETRIEVE PL-ITERATOR) ((QUERY CONS) (MODULE MODULE) (ENVIRONMENT ENVIRONMENT)) :DOCUMENTATION \"Returns an iterator of variable bindings that when substituted for the\nopen variables in `query' satisfy the query proposition.  The query is\nrun in `module' and relative to `environment'.  `query' has the same syntax\nas the PowerLoom `retrieve' command (which see) but with the `retrieve'\noperator omitted.    For example, here are some legal `query' arguments:\n	 \n    ((happy ?x))\n    (10 (happy ?x))\n    (all (happy ?x))\n    (all ?x (happy ?x))\n    (10 (happy ?x) :inference-level :assertion)\n    (10 (happy ?x) :inference-level :assertion :timeout 1.0)\n	\nIf there is only a single output variable (as in all the examples above)\neach element generated by the returned iterator will be a binding for\nthat variable - unless, the output variable was declared with a surrounding\npair of parentheses.  For example:\n	 \n    (all (?x) (happy ?x))\n	\nIn that case, the generated elements will be one-elemen" "t lists.  If there\nare multiple output variables, each element generated by the returned\niterator will be a list of variable bindings that can be accessed using\nthe various `get-nth-...' functions.  The list of output variables does\nnot need to be declared in which case they are taken to be the open variables\nin the query proposition in the order in which they were encountered.  If\norder does matter or should be different from its default, it can be forced\nby declaring the set of output variables.\" :PUBLIC? TRUE)", ((cpp_function_code)(&retrieve)), NULL);
    defineFunctionObject("S-RETRIEVE", "(DEFUN (S-RETRIEVE PL-ITERATOR) ((QUERY STRING) (MODULE-NAME STRING) (ENVIRONMENT ENVIRONMENT)) :PUBLIC? TRUE :DOCUMENTATION \"Returns an iterator of variable bindings that when substituted for the\nopen variables in `query' satisfy the query proposition.  The query is\nrun in `module' and relative to `environment'.  `query' has the same syntax\nas the PowerLoom `retrieve' command (which see) but with the `retrieve'\noperator omitted.  Different from the PLI `retrieve' function, `s-retrieve'\ndoes not expect a top-level pair of parentheses.  For example, here are some\nlegal `query' arguments:\n	 \n    \\\"(happy ?x)\\\"\n    \\\"10 (happy ?x)\\\"\n    \\\"all (happy ?x)\\\"\n    \\\"all ?x (happy ?x)\\\"\n    \\\"10 (happy ?x) :inference-level :assertion\\\"\n    \\\"10 (happy ?x) :inference-level :assertion :timeout 1.0\\\"\n	\nIf there is only a single output variable (as in all the examples above)\neach element generated by the returned iterator will be a binding for\nthat variable - unless, the output v" "ariable was declared with a surrounding\npair of parentheses.  For example:\n	 \n    \\\"all (?x) (happy ?x)\\\"\n	\nIn that case, the generated elements will be one-element lists.  If there\nare multiple output variables, each element generated by the returned\niterator will be a list of variable bindings that can be accessed using\nthe various `get-nth-...' functions.  The list of output variables does\nnot need to be declared in which case they are taken to be the open variables\nin the query proposition in the order in which they were encountered.  If\norder does matter or should be different from its default, it can be forced\nby declaring the set of output variables.\n\nNames in `query' will be interpreted relative to module `module-name'.\nA null `module-name' or the empty string refers to the current module.\nIf no module can be found with the name `module-name', then a STELLA\n`no-such-context-exception' is thrown.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sRetrieve)), NULL);
    defineFunctionObject("MAIN", "(DEFUN (MAIN INTEGER) () :PUBLIC? TRUE :DOCUMENTATION \"Main PowerLoom entry point for your code in C++ and Java.\")", ((cpp_function_code)(&main)), NULL);
    defineFunctionObject("STARTUP-PLI", "(DEFUN STARTUP-PLI () :PUBLIC? TRUE)", ((cpp_function_code)(&startupPli)), NULL);
    { MethodSlot* function = lookupFunction(SYM_PLI_PLI_STARTUP_PLI);

      setDynamicSlotValue(function->dynamicSlots, SYM_PLI_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupPli"), NULL_STRING_WRAPPER);
    }
  }
}

void startupPli() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/PLI", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupPli1();
    }
    if (currentStartupTimePhaseP(4)) {
      { Environment* self058 = newEnvironment();

        self058->level = "ASSERTION";
        ASSERTION_ENV = self058;
      }
      { Environment* self059 = newEnvironment();

        self059->level = "TAXONOMIC";
        TAXONOMIC_ENV = self059;
      }
      { Environment* self060 = newEnvironment();

        self060->level = "INFERENCE";
        INFERENCE_ENV = self060;
      }
      { PlIterator* self061 = newPlIterator();

        self061->cursor = NIL;
        EMPTY_PL_ITERATOR = self061;
      }
    }
    if (currentStartupTimePhaseP(5)) {
      { Class* clasS = defineClassFromStringifiedSource("ENVIRONMENT", "(DEFCLASS ENVIRONMENT (STANDARD-OBJECT) :PUBLIC? TRUE :SLOTS ((LEVEL :TYPE STRING)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|ENV|\" (LEVEL SELF)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newEnvironment));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessEnvironmentSlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("PL-ITERATOR", "(DEFCLASS PL-ITERATOR (ITERATOR) :PUBLIC? TRUE :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((CURSOR :TYPE CONS)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newPlIterator));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessPlIteratorSlotValue));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupPli2();
      helpStartupPli3();
      helpStartupPli4();
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-INITIALIZED?* BOOLEAN FALSE)");
      oPOWERLOOM_INITIALIZEDpo = true;
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT ASSERTION-ENV ENVIRONMENT (NEW ENVIRONMENT :LEVEL \"ASSERTION\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT TAXONOMIC-ENV ENVIRONMENT (NEW ENVIRONMENT :LEVEL \"TAXONOMIC\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT INFERENCE-ENV ENVIRONMENT (NEW ENVIRONMENT :LEVEL \"INFERENCE\") :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL EMPTY-PL-ITERATOR PL-ITERATOR (NEW PL-ITERATOR :CURSOR NIL) :PUBLIC? FALSE :DOCUMENTATION \"Iterator that generates no values.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LITERAL-CONCEPT* NAMED-DESCRIPTION NULL :PUBLIC? FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STRING-CONCEPT* NAMED-DESCRIPTION NULL :PUBLIC? FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *INTEGER-CONCEPT* NAMED-DESCRIPTION NULL :PUBLIC? FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *FLOAT-CONCEPT* NAMED-DESCRIPTION NULL :PUBLIC? FALSE)");
      oLITERAL_CONCEPTo = ((NamedDescription*)(sGetConcept("LITERAL", "PL-USER", NULL)));
      oSTRING_CONCEPTo = ((NamedDescription*)(sGetConcept("STRING", "PL-USER", NULL)));
      oINTEGER_CONCEPTo = ((NamedDescription*)(sGetConcept("INTEGER", "PL-USER", NULL)));
      oFLOAT_CONCEPTo = ((NamedDescription*)(sGetConcept("FLOAT", "PL-USER", NULL)));
    }
  }
}

Surrogate* SGT_PLI_PLI_ENVIRONMENT = NULL;

Symbol* SYM_PLI_LOGIC_LEVEL = NULL;

Surrogate* SGT_PLI_PLI_PL_ITERATOR = NULL;

Symbol* SYM_PLI_STELLA_CURSOR = NULL;

Surrogate* SGT_PLI_STELLA_CONS = NULL;

Surrogate* SGT_PLI_STELLA_LIST = NULL;

Surrogate* SGT_PLI_STELLA_VECTOR = NULL;

Symbol* SYM_PLI_STELLA_NULL = NULL;

Surrogate* SGT_PLI_LOGIC_SKOLEM = NULL;

Surrogate* SGT_PLI_LOGIC_LOGIC_OBJECT = NULL;

Surrogate* SGT_PLI_STELLA_GENERALIZED_SYMBOL = NULL;

Surrogate* SGT_PLI_STELLA_MODULE = NULL;

Surrogate* SGT_PLI_STELLA_CONTEXT = NULL;

Surrogate* SGT_PLI_LOGIC_COMPUTED_PROCEDURE = NULL;

Surrogate* SGT_PLI_STELLA_LITERAL_WRAPPER = NULL;

Surrogate* SGT_PLI_LOGIC_NAMED_DESCRIPTION = NULL;

Symbol* SYM_PLI_PLI_pR = NULL;

Symbol* SYM_PLI_PLI_pI = NULL;

Symbol* SYM_PLI_PLI_pV = NULL;

Symbol* SYM_PLI_PLI_F_GET_INFERRED_BINARY_PROPOSITION_VALUES_QUERY_000 = NULL;

Symbol* SYM_PLI_LOGIC_ALL = NULL;

Symbol* SYM_PLI_LOGIC_pX = NULL;

Symbol* SYM_PLI_STELLA_AND = NULL;

Symbol* SYM_PLI_LOGIC_FAIL = NULL;

Symbol* SYM_PLI_STELLA_EXISTS = NULL;

Symbol* SYM_PLI_LOGIC_pY = NULL;

Symbol* SYM_PLI_PLI_PROPER_SUBRELATION = NULL;

Keyword* KWD_PLI_ISA = NULL;

Symbol* SYM_PLI_STELLA_TRUE = NULL;

Symbol* SYM_PLI_STELLA_FALSE = NULL;

Keyword* KWD_PLI_CASE_SENSITIVEp = NULL;

Keyword* KWD_PLI_SUBSET_OF = NULL;

Keyword* KWD_PLI_ERROR = NULL;

Keyword* KWD_PLI_RETRACT_TRUE = NULL;

Keyword* KWD_PLI_ASSERT_TRUE = NULL;

Surrogate* SGT_PLI_LOGIC_PROPOSITION = NULL;

Symbol* SYM_PLI_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_PLI_STELLA_INTEGER_WRAPPER = NULL;

Surrogate* SGT_PLI_STELLA_FLOAT_WRAPPER = NULL;

Surrogate* SGT_PLI_STELLA_NUMBER_WRAPPER = NULL;

Surrogate* SGT_PLI_STELLA_STRING_WRAPPER = NULL;

Symbol* SYM_PLI_PLI_STARTUP_PLI = NULL;

Symbol* SYM_PLI_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace pli


