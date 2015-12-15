//  -*- Mode: C++ -*-

// timepoint-support.cc

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

#include "logic/extensions/powerloom-extensions-system.hh"

namespace timepoint {
  using namespace stella_utilities;
  using namespace stella;
  using namespace logic;

// Table for interning date-time logic wrappers
StellaHashTable* oDATE_TIME_HASH_TABLEo = NULL;

DateTimeLogicWrapper* newDateTimeLogicWrapper(DateTimeObject* wrapperValue) {
  { DateTimeLogicWrapper* self = NULL;

    self = new DateTimeLogicWrapper();
    self->wrapperValue = wrapperValue;
    self->dynamicSlots = newKeyValueList();
    self->surrogateValueInverse = NULL;
    self->functionTerm = NULL;
    return (self);
  }
}

Surrogate* DateTimeLogicWrapper::primaryType() {
  { DateTimeLogicWrapper* self = this;

    return (SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER);
  }
}

Object* accessDateTimeLogicWrapperSlotValue(DateTimeLogicWrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_TIMEPOINT_SUPPORT_STELLA_WRAPPER_VALUE) {
    if (setvalueP) {
      self->wrapperValue = ((DateTimeObject*)(value));
    }
    else {
      value = ((DateTimeObject*)(self->wrapperValue));
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

void DateTimeLogicWrapper::printObject(std::ostream* stream) {
  { DateTimeLogicWrapper* self = this;

    if (oPRINTREADABLYpo.get()) {
      *(stream) << ((DateTimeObject*)(self->wrapperValue));
    }
    else {
      *(stream) << "|tw|" << ((DateTimeObject*)(self->wrapperValue));
    }
  }
}

Object* DateTimeLogicWrapper::generateSpecializedTerm() {
  { DateTimeLogicWrapper* self = this;

    { Cons* term = self->functionTerm;
      DateTimeObject* datetime = ((DateTimeObject*)(self->wrapperValue));

      if (((boolean)(term))) {
        return (term);
      }
      else if (((boolean)(datetime))) {
        { Surrogate* testValue000 = safePrimaryType(datetime);

          if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_STELLA_CALENDAR_DATE)) {
            { DateTimeObject* datetime000 = datetime;
              CalendarDate* datetime = ((CalendarDate*)(datetime000));

              term = cons(generateTerm(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_OF), cons(wrapString(datetime->calendarDateToString(0.0, false, true)), NIL));
            }
          }
          else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_STELLA_TIME_DURATION)) {
            { DateTimeObject* datetime001 = datetime;
              TimeDuration* datetime = ((TimeDuration*)(datetime001));

              term = cons(generateTerm(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_DURATION_OF), cons(wrapString(datetime->timeDurationToString()), NIL));
            }
          }
          else {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
              throw *newStellaException(stream000->theStringReader());
            }
          }
        }
        self->functionTerm = term;
        return (term);
      }
      else {
        throw *newTermGenerationException(self, "Date Time Number Wrapper doesn't have a value.");
      }
    }
  }
}

int DateTimeLogicWrapper::hashCode() {
  { DateTimeLogicWrapper* self = this;

    if (((boolean)(((DateTimeObject*)(self->wrapperValue))))) {
      return (((DateTimeObject*)(self->wrapperValue))->hashCode());
    }
    else {
      return (0);
    }
  }
}

boolean DateTimeLogicWrapper::objectEqlP(Object* x) {
  { DateTimeLogicWrapper* self = this;

    try {
      return (isaP(x, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER) &&
          ((DateTimeObject*)(self->wrapperValue))->objectEqlP(((DateTimeObject*)(((DateTimeLogicWrapper*)(x))->wrapperValue))));
    }
    catch (StellaException ) {
      return (false);
    }
  }
}

DateTimeLogicWrapper* wrapDateTime(DateTimeObject* value) {
  // Return an interned LOGIC-WRAPPER for `value'.  This assures us
  // that all logic-wrapped DATE-TIME-OBJECTs are the same object.
  { DateTimeLogicWrapper* wrapper = ((DateTimeLogicWrapper*)(oDATE_TIME_HASH_TABLEo->lookup(value)));

    if (!((boolean)(wrapper))) {
      wrapper = newDateTimeLogicWrapper(value);
      oDATE_TIME_HASH_TABLEo->insertAt(value, wrapper);
    }
    return (wrapper);
  }
}

DateTimeLogicWrapper* helpGetCalendarTime(Object* item) {
  { Surrogate* testValue000 = safePrimaryType(item);

    if (subtypeOfStringP(testValue000)) {
      { Object* item000 = item;
        StringWrapper* item = ((StringWrapper*)(item000));

        { CalendarDate* value = stringToCalendarDate(item->wrapperValue);

          if (((boolean)(value))) {
            return (wrapDateTime(value));
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
      { Object* item001 = item;
        PatternVariable* item = ((PatternVariable*)(item001));

        { Object* value = safeBoundTo(item);

          if (((boolean)(value))) {
            return (helpGetCalendarTime(value));
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
      { Object* item002 = item;
        DateTimeLogicWrapper* item = ((DateTimeLogicWrapper*)(item002));

        return (item);
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
      { Object* item003 = item;
        Skolem* item = ((Skolem*)(item003));

        { Object* value = ((Object*)(accessInContext(item->variableValue, item->homeContext, false)));

          { Surrogate* testValue001 = safePrimaryType(value);

            if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
              { Object* value000 = value;
                DateTimeLogicWrapper* value = ((DateTimeLogicWrapper*)(value000));

                return (value);
              }
            }
            else if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
              { Object* value001 = value;
                Skolem* value = ((Skolem*)(value001));

                if (isaP(((Object*)(accessInContext(value->variableValue, value->homeContext, false))), SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
                  return (NULL);
                }
                else {
                  return (helpGetCalendarTime(((Object*)(accessInContext(value->variableValue, value->homeContext, false)))));
                }
              }
            }
            else {
              if (isaP(((Object*)(accessInContext(item->variableValue, item->homeContext, false))), SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
                return (NULL);
              }
              else {
                return (helpGetCalendarTime(((Object*)(accessInContext(item->variableValue, item->homeContext, false)))));
              }
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

DateTimeLogicWrapper* helpGetTimeDuration(Object* item) {
  { Surrogate* testValue000 = safePrimaryType(item);

    if (subtypeOfStringP(testValue000)) {
      { Object* item000 = item;
        StringWrapper* item = ((StringWrapper*)(item000));

        { TimeDuration* value = stringToTimeDuration(item->wrapperValue);

          if (((boolean)(value))) {
            return (wrapDateTime(value));
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
      { Object* item001 = item;
        PatternVariable* item = ((PatternVariable*)(item001));

        { Object* value = safeBoundTo(item);

          if (((boolean)(value))) {
            return (helpGetTimeDuration(value));
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
      { Object* item002 = item;
        DateTimeLogicWrapper* item = ((DateTimeLogicWrapper*)(item002));

        return (item);
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_UNIT_SUPPORT_DIM_NUMBER_LOGIC_WRAPPER)) {
      { Object* item003 = item;
        units::DimNumberLogicWrapper* item = ((units::DimNumberLogicWrapper*)(item003));

        try {
          return (wrapDateTime(dimToTimeDuration(((DimNumber*)(item->wrapperValue)))));
        }
        catch (IncompatibleUnitsException ) {
          return (NULL);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
      { Object* item004 = item;
        Skolem* item = ((Skolem*)(item004));

        { Object* value = ((Object*)(accessInContext(item->variableValue, item->homeContext, false)));

          { Surrogate* testValue001 = safePrimaryType(value);

            if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
              { Object* value000 = value;
                DateTimeLogicWrapper* value = ((DateTimeLogicWrapper*)(value000));

                return (value);
              }
            }
            else if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
              { Object* value001 = value;
                Skolem* value = ((Skolem*)(value001));

                if (isaP(((Object*)(accessInContext(value->variableValue, value->homeContext, false))), SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
                  return (NULL);
                }
                else {
                  return (helpGetTimeDuration(((Object*)(accessInContext(value->variableValue, value->homeContext, false)))));
                }
              }
            }
            else {
              if (isaP(((Object*)(accessInContext(item->variableValue, item->homeContext, false))), SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
                return (NULL);
              }
              else {
                return (helpGetTimeDuration(((Object*)(accessInContext(item->variableValue, item->homeContext, false)))));
              }
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

DateTimeLogicWrapper* helpGetTimeObject(Object* item) {
  { Surrogate* testValue000 = safePrimaryType(item);

    if (subtypeOfStringP(testValue000)) {
      { Object* item000 = item;
        StringWrapper* item = ((StringWrapper*)(item000));

        { DateTimeObject* value = stringToCalendarDate(item->wrapperValue);

          if (!((boolean)(value))) {
            value = stringToTimeDuration(item->wrapperValue);
          }
          if (((boolean)(value))) {
            return (wrapDateTime(value));
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
      { Object* item001 = item;
        PatternVariable* item = ((PatternVariable*)(item001));

        { Object* value = safeBoundTo(item);

          if (((boolean)(value))) {
            return (helpGetTimeObject(value));
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
      { Object* item002 = item;
        DateTimeLogicWrapper* item = ((DateTimeLogicWrapper*)(item002));

        return (item);
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_UNIT_SUPPORT_DIM_NUMBER_LOGIC_WRAPPER)) {
      { Object* item003 = item;
        units::DimNumberLogicWrapper* item = ((units::DimNumberLogicWrapper*)(item003));

        try {
          return (wrapDateTime(dimToTimeDuration(((DimNumber*)(item->wrapperValue)))));
        }
        catch (IncompatibleUnitsException ) {
          return (NULL);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
      { Object* item004 = item;
        Skolem* item = ((Skolem*)(item004));

        { Object* value = ((Object*)(accessInContext(item->variableValue, item->homeContext, false)));

          { Surrogate* testValue001 = safePrimaryType(value);

            if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
              { Object* value000 = value;
                DateTimeLogicWrapper* value = ((DateTimeLogicWrapper*)(value000));

                return (value);
              }
            }
            else if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
              { Object* value001 = value;
                Skolem* value = ((Skolem*)(value001));

                if (isaP(((Object*)(accessInContext(value->variableValue, value->homeContext, false))), SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
                  return (NULL);
                }
                else {
                  return (helpGetTimeObject(((Object*)(accessInContext(value->variableValue, value->homeContext, false)))));
                }
              }
            }
            else {
              if (isaP(((Object*)(accessInContext(item->variableValue, item->homeContext, false))), SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
                return (NULL);
              }
              else {
                return (helpGetTimeObject(((Object*)(accessInContext(item->variableValue, item->homeContext, false)))));
              }
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

int helpGetInteger(Object* obj) {
  if (!((boolean)(obj))) {
    return (NULL_INTEGER);
  }
  else {
    { Surrogate* testValue000 = safePrimaryType(obj);

      if (subtypeOfFloatP(testValue000)) {
        { Object* obj000 = obj;
          FloatWrapper* obj = ((FloatWrapper*)(obj000));

          if (integerValuedP(obj->wrapperValue)) {
            return (stella::floor(obj->wrapperValue));
          }
          else {
            return (NULL_INTEGER);
          }
        }
      }
      else if (subtypeOfIntegerP(testValue000)) {
        { Object* obj001 = obj;
          IntegerWrapper* obj = ((IntegerWrapper*)(obj001));

          return (obj->wrapperValue);
        }
      }
      else {
        return (NULL_INTEGER);
      }
    }
  }
}

double helpGetFloat(Object* obj) {
  if (!((boolean)(obj))) {
    return (NULL_FLOAT);
  }
  else {
    { Surrogate* testValue000 = safePrimaryType(obj);

      if (subtypeOfFloatP(testValue000)) {
        { Object* obj000 = obj;
          FloatWrapper* obj = ((FloatWrapper*)(obj000));

          return (obj->wrapperValue);
        }
      }
      else if (subtypeOfIntegerP(testValue000)) {
        { Object* obj001 = obj;
          IntegerWrapper* obj = ((IntegerWrapper*)(obj001));

          return (((double)(obj->wrapperValue)));
        }
      }
      else {
        return (NULL_FLOAT);
      }
    }
  }
}

double helpGetTimezone(Object* obj) {
  if (!((boolean)(obj))) {
    return (NULL_FLOAT);
  }
  else {
    { Surrogate* testValue000 = safePrimaryType(obj);

      if (subtypeOfFloatP(testValue000)) {
        { Object* obj000 = obj;
          FloatWrapper* obj = ((FloatWrapper*)(obj000));

          return (obj->wrapperValue);
        }
      }
      else if (subtypeOfIntegerP(testValue000)) {
        { Object* obj001 = obj;
          IntegerWrapper* obj = ((IntegerWrapper*)(obj001));

          return (((double)(obj->wrapperValue)));
        }
      }
      else if (subtypeOfStringP(testValue000)) {
        { Object* obj002 = obj;
          StringWrapper* obj = ((StringWrapper*)(obj002));

          { FloatWrapper* decodedZone = zone(wrapString(stringDowncase(obj->wrapperValue)));

            if (((boolean)(decodedZone))) {
              return (decodedZone->wrapperValue);
            }
            else {
              return (NULL_FLOAT);
            }
          }
        }
      }
      else {
        return (NULL_FLOAT);
      }
    }
  }
}

boolean canBindAllP(Cons* plObjects, Cons* values) {
  { Object* obj = NULL;
    Cons* iter000 = plObjects;
    Object* value = NULL;
    Cons* iter001 = values;

    for  (obj, iter000, value, iter001; 
          (!(iter000 == NIL)) &&
              (!(iter001 == NIL)); 
          iter000 = iter000->rest,
          iter001 = iter001->rest) {
      obj = iter000->value;
      value = iter001->value;
      { Surrogate* testValue000 = safePrimaryType(obj);

        if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
          { Object* obj000 = obj;
            PatternVariable* obj = ((PatternVariable*)(obj000));

            if (!(bindVariableToValueP(obj, value, true))) {
              return (false);
            }
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
          { Object* obj001 = obj;
            Skolem* obj = ((Skolem*)(obj001));

            { Skolem* object000 = obj;
              Object* value000 = value;
              Object* oldValue000 = object000->variableValue;
              Object* newValue000 = updateInContext(oldValue000, value000, object000->homeContext, false);

              if (!(((boolean)(oldValue000)) &&
                  (oldValue000->primaryType() == SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE))) {
                object000->variableValue = newValue000;
              }
            }
          }
        }
        else {
          if (!(obj->objectEqlP(value))) {
            return (false);
          }
        }
      }
    }
  }
  return (true);
}

void timepointOfEvaluator(Proposition* self) {
  { Object* value1 = valueOf((self->arguments->theArray)[0]);
    Object* value2 = valueOf((self->arguments->theArray)[1]);
    DateTimeLogicWrapper* time1 = helpGetCalendarTime(value1);

    if (((boolean)(time1))) {
      { Surrogate* testValue000 = safePrimaryType(value2);

        if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
          { Object* value2000 = value2;
            Skolem* value2 = ((Skolem*)(value2000));

            bindSkolemToValue(value2, time1, false);
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
          { Object* value2001 = value2;
            DateTimeLogicWrapper* value2 = ((DateTimeLogicWrapper*)(value2001));

            if (!(((DateTimeObject*)(time1->wrapperValue))->objectEqlP(((DateTimeObject*)(value2->wrapperValue))))) {
              signalUnificationClash(time1, value2);
            }
          }
        }
        else {
          signalUnificationClash(time1, value2);
        }
      }
    }
  }
}

Keyword* timepointOfSpecialist(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;
    Object* value1 = valueOf((proposition->arguments->theArray)[0]);
    Object* value2 = valueOf((proposition->arguments->theArray)[1]);
    DateTimeLogicWrapper* theTime = helpGetCalendarTime(value1);

    lastmove = lastmove;
    if (((boolean)(theTime))) {
      { Surrogate* testValue000 = safePrimaryType(value2);

        if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
          { Object* value2000 = value2;
            PatternVariable* value2 = ((PatternVariable*)(value2000));

            return (selectProofResult(bindVariableToValueP(value2, theTime, true), false, true));
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
          { Object* value2001 = value2;
            Skolem* value2 = ((Skolem*)(value2001));

            { Skolem* object000 = value2;
              Object* value000 = theTime;
              Object* oldValue000 = object000->variableValue;
              Object* newValue000 = updateInContext(oldValue000, value000, object000->homeContext, false);

              if (!(((boolean)(oldValue000)) &&
                  (oldValue000->primaryType() == SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE))) {
                object000->variableValue = newValue000;
              }
            }
            return (KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS);
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
          { Object* value2002 = value2;
            DateTimeLogicWrapper* value2 = ((DateTimeLogicWrapper*)(value2002));

            return (selectProofResult(((DateTimeObject*)(theTime->wrapperValue))->objectEqlP(((DateTimeObject*)(value2->wrapperValue))), false, true));
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
    else if (((boolean)(value2))) {
      theTime = helpGetCalendarTime(value2);
      if (((boolean)(theTime))) {
        { Surrogate* testValue001 = safePrimaryType(value1);

          if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
            { Object* value1000 = value1;
              PatternVariable* value1 = ((PatternVariable*)(value1000));

              return (selectProofResult(bindVariableToValueP(value1, wrapString(((CalendarDate*)(((DateTimeObject*)(theTime->wrapperValue))))->calendarDateToString(0.0, false, true)), true), false, true));
            }
          }
          else if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
            { Object* value1001 = value1;
              Skolem* value1 = ((Skolem*)(value1001));

              { Skolem* object001 = value1;
                Object* value001 = wrapString(((CalendarDate*)(((DateTimeObject*)(theTime->wrapperValue))))->calendarDateToString(0.0, false, true));
                Object* oldValue001 = object001->variableValue;
                Object* newValue001 = updateInContext(oldValue001, value001, object001->homeContext, false);

                if (!(((boolean)(oldValue001)) &&
                    (oldValue001->primaryType() == SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE))) {
                  object001->variableValue = newValue001;
                }
              }
              return (KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS);
            }
          }
          else {
            return (KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE);
          }
        }
      }
      else {
        return (KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE);
      }
    }
    else {
      return (KWD_TIMEPOINT_SUPPORT_FAILURE);
    }
  }
}

void timepointOfOEvaluator(Proposition* self) {
  { Vector* args = self->arguments;
    Object* yyValue = valueOf((args->theArray)[0]);
    Object* mmValue = valueOf((args->theArray)[1]);
    Object* ddValue = valueOf((args->theArray)[2]);
    Object* hrValue = valueOf((args->theArray)[3]);
    Object* minValue = valueOf((args->theArray)[4]);
    Object* secValue = valueOf((args->theArray)[5]);
    Object* tzValue = valueOf((args->theArray)[6]);
    Object* tpValue = valueOf((args->theArray)[7]);
    int year = helpGetInteger(yyValue);
    int month = helpGetInteger(mmValue);
    int day = helpGetInteger(ddValue);
    int hour = helpGetInteger(hrValue);
    int minute = helpGetInteger(minValue);
    double secondFloat = helpGetFloat(secValue);
    double zone = helpGetTimezone(tzValue);
    int second = 0;
    DateTimeLogicWrapper* time1 = NULL;

    if ((year != NULL_INTEGER) &&
        ((month != NULL_INTEGER) &&
         ((day != NULL_INTEGER) &&
          ((hour != NULL_INTEGER) &&
           ((minute != NULL_INTEGER) &&
            ((secondFloat != NULL_FLOAT) &&
             (zone != NULL_FLOAT))))))) {
      second = stella::floor(secondFloat);
      time1 = wrapDateTime(makeDateTime(year, month, day, hour, minute, second, stella::floor(1000 * (secondFloat - second)), zone));
      { Surrogate* testValue000 = safePrimaryType(tpValue);

        if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
          { Object* tpValue000 = tpValue;
            Skolem* tpValue = ((Skolem*)(tpValue000));

            bindSkolemToValue(tpValue, time1, false);
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
          { Object* tpValue001 = tpValue;
            DateTimeLogicWrapper* tpValue = ((DateTimeLogicWrapper*)(tpValue001));

            if (!(((DateTimeObject*)(time1->wrapperValue))->objectEqlP(((DateTimeObject*)(tpValue->wrapperValue))))) {
              signalUnificationClash(time1, tpValue);
            }
          }
        }
        else {
          signalUnificationClash(time1, tpValue);
        }
      }
    }
  }
}

Keyword* timepointOfOSpecialist(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;
    Vector* args = proposition->arguments;
    Object* yyValue = valueOf((args->theArray)[0]);
    Object* mmValue = valueOf((args->theArray)[1]);
    Object* ddValue = valueOf((args->theArray)[2]);
    Object* hrValue = valueOf((args->theArray)[3]);
    Object* minValue = valueOf((args->theArray)[4]);
    Object* secValue = valueOf((args->theArray)[5]);
    Object* tzValue = valueOf((args->theArray)[6]);
    Object* tpValue = valueOf((args->theArray)[7]);
    int year = helpGetInteger(yyValue);
    int month = helpGetInteger(mmValue);
    int day = helpGetInteger(ddValue);
    int hour = helpGetInteger(hrValue);
    int minute = helpGetInteger(minValue);
    double secondFloat = helpGetFloat(secValue);
    int second = 0;
    double zone = helpGetTimezone(tzValue);
    DateTimeLogicWrapper* theTime = NULL;
    CalendarDate* calendarDate = NULL;

    lastmove = lastmove;
    if ((year != NULL_INTEGER) &&
        ((month != NULL_INTEGER) &&
         ((day != NULL_INTEGER) &&
          ((hour != NULL_INTEGER) &&
           ((minute != NULL_INTEGER) &&
            ((secondFloat != NULL_FLOAT) &&
             (zone != NULL_FLOAT))))))) {
      second = stella::floor(secondFloat);
      theTime = wrapDateTime(makeDateTime(year, month, day, hour, minute, second, stella::floor(1000 * (secondFloat - second)), zone));
      { Surrogate* testValue000 = safePrimaryType(tpValue);

        if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
          { Object* tpValue000 = tpValue;
            PatternVariable* tpValue = ((PatternVariable*)(tpValue000));

            return (selectProofResult(bindVariableToValueP(tpValue, theTime, true), false, true));
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
          { Object* tpValue001 = tpValue;
            Skolem* tpValue = ((Skolem*)(tpValue001));

            { Skolem* object000 = tpValue;
              Object* value000 = theTime;
              Object* oldValue000 = object000->variableValue;
              Object* newValue000 = updateInContext(oldValue000, value000, object000->homeContext, false);

              if (!(((boolean)(oldValue000)) &&
                  (oldValue000->primaryType() == SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE))) {
                object000->variableValue = newValue000;
              }
            }
            return (KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS);
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
          { Object* tpValue002 = tpValue;
            DateTimeLogicWrapper* tpValue = ((DateTimeLogicWrapper*)(tpValue002));

            return (selectProofResult(((DateTimeObject*)(theTime->wrapperValue))->objectEqlP(((DateTimeObject*)(tpValue->wrapperValue))), false, true));
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
    else if (((boolean)(tpValue))) {
      theTime = helpGetCalendarTime(tpValue);
      calendarDate = ((CalendarDate*)(((DateTimeObject*)(theTime->wrapperValue))));
      if (zone == NULL_FLOAT) {
        zone = 0.0;
        { Surrogate* testValue001 = safePrimaryType(tzValue);

          if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
            { Object* tzValue000 = tzValue;
              PatternVariable* tzValue = ((PatternVariable*)(tzValue000));

              if (!(bindVariableToValueP(tzValue, wrapFloat(zone), true))) {
                return (KWD_TIMEPOINT_SUPPORT_FAILURE);
              }
            }
          }
          else if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
            { Object* tzValue001 = tzValue;
              Skolem* tzValue = ((Skolem*)(tzValue001));

              { Skolem* object001 = tzValue;
                Object* value001 = wrapFloat(zone);
                Object* oldValue001 = object001->variableValue;
                Object* newValue001 = updateInContext(oldValue001, value001, object001->homeContext, false);

                if (!(((boolean)(oldValue001)) &&
                    (oldValue001->primaryType() == SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE))) {
                  object001->variableValue = newValue001;
                }
              }
            }
          }
          else {
            return (KWD_TIMEPOINT_SUPPORT_FAILURE);
          }
        }
      }
      if (((boolean)(theTime))) {
        { int yy = NULL_INTEGER;
          int mm = NULL_INTEGER;
          int dd = NULL_INTEGER;
          Keyword* dow = NULL;

          yy = calendarDate->getCalendarDate(zone, mm, dd, dow);
          dow = dow;
          { int h = NULL_INTEGER;
            int m = NULL_INTEGER;
            int s = NULL_INTEGER;
            int milli = NULL_INTEGER;

            h = calendarDate->getTime(zone, m, s, milli);
            return (selectProofResult(canBindAllP(consList(6, yyValue, mmValue, ddValue, hrValue, minValue, secValue), consList(6, wrapInteger(yy), wrapInteger(mm), wrapInteger(dd), wrapInteger(h), wrapInteger(m), wrapFloat(((double)(s + (milli * 0.001)))))), false, true));
          }
        }
      }
      else {
        return (KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE);
      }
    }
    else {
      return (KWD_TIMEPOINT_SUPPORT_FAILURE);
    }
  }
}

void durationOfEvaluator(Proposition* self) {
  { Object* value1 = valueOf((self->arguments->theArray)[0]);
    Object* value2 = valueOf((self->arguments->theArray)[1]);
    DateTimeLogicWrapper* time1 = helpGetCalendarTime(value1);

    if (((boolean)(time1))) {
      { Surrogate* testValue000 = safePrimaryType(value2);

        if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
          { Object* value2000 = value2;
            Skolem* value2 = ((Skolem*)(value2000));

            bindSkolemToValue(value2, time1, false);
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
          { Object* value2001 = value2;
            DateTimeLogicWrapper* value2 = ((DateTimeLogicWrapper*)(value2001));

            if (!(((DateTimeObject*)(time1->wrapperValue))->objectEqlP(((DateTimeObject*)(value2->wrapperValue))))) {
              signalUnificationClash(time1, value2);
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
  }
}

Keyword* durationOfSpecialist(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;
    Object* value1 = valueOf((proposition->arguments->theArray)[0]);
    Object* value2 = valueOf((proposition->arguments->theArray)[1]);
    DateTimeLogicWrapper* theTime = helpGetTimeDuration(value1);

    lastmove = lastmove;
    if (((boolean)(theTime))) {
      { Surrogate* testValue000 = safePrimaryType(value2);

        if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
          { Object* value2000 = value2;
            PatternVariable* value2 = ((PatternVariable*)(value2000));

            return (selectProofResult(bindVariableToValueP(value2, theTime, true), false, true));
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
          { Object* value2001 = value2;
            Skolem* value2 = ((Skolem*)(value2001));

            { Skolem* object000 = value2;
              Object* value000 = theTime;
              Object* oldValue000 = object000->variableValue;
              Object* newValue000 = updateInContext(oldValue000, value000, object000->homeContext, false);

              if (!(((boolean)(oldValue000)) &&
                  (oldValue000->primaryType() == SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE))) {
                object000->variableValue = newValue000;
              }
            }
            return (KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS);
          }
        }
        else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
          { Object* value2002 = value2;
            DateTimeLogicWrapper* value2 = ((DateTimeLogicWrapper*)(value2002));

            return (selectProofResult(((DateTimeObject*)(theTime->wrapperValue))->objectEqlP(((DateTimeObject*)(value2->wrapperValue))), false, true));
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
    else if (((boolean)(value2))) {
      theTime = helpGetTimeDuration(value2);
      if (((boolean)(theTime))) {
        { Surrogate* testValue001 = safePrimaryType(value1);

          if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
            { Object* value1000 = value1;
              PatternVariable* value1 = ((PatternVariable*)(value1000));

              return (selectProofResult(bindVariableToValueP(value1, wrapString(((TimeDuration*)(((DateTimeObject*)(theTime->wrapperValue))))->timeDurationToString()), true), false, true));
            }
          }
          else if (subtypeOfP(testValue001, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
            { Object* value1001 = value1;
              Skolem* value1 = ((Skolem*)(value1001));

              { Skolem* object001 = value1;
                Object* value001 = wrapString(((TimeDuration*)(((DateTimeObject*)(theTime->wrapperValue))))->timeDurationToString());
                Object* oldValue001 = object001->variableValue;
                Object* newValue001 = updateInContext(oldValue001, value001, object001->homeContext, false);

                if (!(((boolean)(oldValue001)) &&
                    (oldValue001->primaryType() == SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE))) {
                  object001->variableValue = newValue001;
                }
              }
              return (KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS);
            }
          }
          else {
            return (KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE);
          }
        }
      }
      else {
        return (KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE);
      }
    }
    else {
      return (KWD_TIMEPOINT_SUPPORT_FAILURE);
    }
  }
}

void timeMinusEvaluator(Proposition* self) {
  { Object* value1 = valueOf((self->arguments->theArray)[0]);
    Object* value2 = valueOf((self->arguments->theArray)[1]);
    Object* value3 = valueOf((self->arguments->theArray)[2]);
    DateTimeLogicWrapper* time1 = helpGetTimeObject(value1);
    DateTimeLogicWrapper* time2 = helpGetTimeObject(value2);
    DateTimeLogicWrapper* time3 = helpGetTimeObject(value3);

    if (((boolean)(time1)) &&
        (((boolean)(time2)) &&
         ((boolean)(time3)))) {
      try {
        if (!(((DateTimeObject*)(time3->wrapperValue))->objectEqlP(timeSubtract(((DateTimeObject*)(time1->wrapperValue)), ((DateTimeObject*)(time2->wrapperValue)))))) {
          signalTruthValueClash(self);
        }
      }
      catch (StellaException ) {
        signalTruthValueClash(self);
      }
    }
  }
}

void timeAddEvaluator(Proposition* self) {
  { Object* value1 = valueOf((self->arguments->theArray)[0]);
    Object* value2 = valueOf((self->arguments->theArray)[1]);
    Object* value3 = valueOf((self->arguments->theArray)[2]);
    DateTimeLogicWrapper* time1 = helpGetTimeObject(value1);
    DateTimeLogicWrapper* time2 = helpGetTimeObject(value2);
    DateTimeLogicWrapper* time3 = helpGetTimeObject(value3);

    if (((boolean)(time1)) &&
        (((boolean)(time2)) &&
         ((boolean)(time3)))) {
      try {
        if (!(((DateTimeObject*)(time3->wrapperValue))->objectEqlP(timeAdd(((DateTimeObject*)(time1->wrapperValue)), ((DateTimeObject*)(time2->wrapperValue)))))) {
          signalTruthValueClash(self);
        }
      }
      catch (StellaException ) {
        signalTruthValueClash(self);
      }
    }
  }
}

Object* timeMinusConstraint(IntegerWrapper* missingArgument, DateTimeLogicWrapper* x1, DateTimeLogicWrapper* x2, DateTimeLogicWrapper* x3) {
  { Object* value = NULL;

    switch (missingArgument->wrapperValue) {
      case -1: 
        value = (timeSubtract(((DateTimeObject*)(x1->wrapperValue)), ((DateTimeObject*)(x2->wrapperValue)))->objectEqlP(((DateTimeObject*)(x3->wrapperValue))) ? TRUE_WRAPPER : FALSE_WRAPPER);
      break;
      case 0: 
        value = wrapDateTime(timeAdd(((DateTimeObject*)(x2->wrapperValue)), ((DateTimeObject*)(x3->wrapperValue))));
      break;
      case 1: 
        value = wrapDateTime(timeSubtract(((DateTimeObject*)(x1->wrapperValue)), ((DateTimeObject*)(x3->wrapperValue))));
      break;
      case 2: 
        value = wrapDateTime(timeSubtract(((DateTimeObject*)(x1->wrapperValue)), ((DateTimeObject*)(x2->wrapperValue))));
      break;
      default:
      break;
    }
    return (value);
  }
}

Object* timeAddConstraint(IntegerWrapper* missingArgument, DateTimeLogicWrapper* x1, DateTimeLogicWrapper* x2, DateTimeLogicWrapper* x3) {
  { Object* value = NULL;

    switch (missingArgument->wrapperValue) {
      case -1: 
        value = (timeAdd(((DateTimeObject*)(x1->wrapperValue)), ((DateTimeObject*)(x2->wrapperValue)))->objectEqlP(((DateTimeObject*)(x3->wrapperValue))) ? TRUE_WRAPPER : FALSE_WRAPPER);
      break;
      case 0: 
        value = wrapDateTime(timeSubtract(((DateTimeObject*)(x3->wrapperValue)), ((DateTimeObject*)(x2->wrapperValue))));
      break;
      case 1: 
        value = wrapDateTime(timeSubtract(((DateTimeObject*)(x3->wrapperValue)), ((DateTimeObject*)(x1->wrapperValue))));
      break;
      case 2: 
        value = wrapDateTime(timeAdd(((DateTimeObject*)(x1->wrapperValue)), ((DateTimeObject*)(x2->wrapperValue))));
      break;
      default:
      break;
    }
    return (value);
  }
}

double helpGetTimeZone(Object* timeZoneSpecifier) {
  if (!((boolean)(timeZoneSpecifier))) {
    return (NULL_FLOAT);
  }
  { Surrogate* testValue000 = safePrimaryType(timeZoneSpecifier);

    if (subtypeOfStringP(testValue000)) {
      { Object* timeZoneSpecifier000 = timeZoneSpecifier;
        StringWrapper* timeZoneSpecifier = ((StringWrapper*)(timeZoneSpecifier000));

        { FloatWrapper* zone = ((FloatWrapper*)(oZONE_STRINGSo.get()->lookup(stringDowncase(timeZoneSpecifier->wrapperValue))));

          if (!((boolean)(zone))) {
            return (NULL_FLOAT);
          }
          else {
            return (((FloatWrapper*)(zone))->wrapperValue);
          }
        }
      }
    }
    else if (subtypeOfIntegerP(testValue000)) {
      { Object* timeZoneSpecifier001 = timeZoneSpecifier;
        IntegerWrapper* timeZoneSpecifier = ((IntegerWrapper*)(timeZoneSpecifier001));

        return (((double)(timeZoneSpecifier->wrapperValue)));
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { Object* timeZoneSpecifier002 = timeZoneSpecifier;
        FloatWrapper* timeZoneSpecifier = ((FloatWrapper*)(timeZoneSpecifier002));

        return (timeZoneSpecifier->wrapperValue);
      }
    }
    else {
      return (NULL_FLOAT);
    }
  }
}

LogicObject* dowKeywordToInstance(Keyword* dow) {
  if (dow == KWD_TIMEPOINT_SUPPORT_MONDAY) {
    return (((LogicObject*)(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_MONDAY->surrogateValue)));
  }
  else if (dow == KWD_TIMEPOINT_SUPPORT_TUESDAY) {
    return (((LogicObject*)(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TUESDAY->surrogateValue)));
  }
  else if (dow == KWD_TIMEPOINT_SUPPORT_WEDNESDAY) {
    return (((LogicObject*)(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_WEDNESDAY->surrogateValue)));
  }
  else if (dow == KWD_TIMEPOINT_SUPPORT_THURSDAY) {
    return (((LogicObject*)(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_THURSDAY->surrogateValue)));
  }
  else if (dow == KWD_TIMEPOINT_SUPPORT_FRIDAY) {
    return (((LogicObject*)(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_FRIDAY->surrogateValue)));
  }
  else if (dow == KWD_TIMEPOINT_SUPPORT_SATURDAY) {
    return (((LogicObject*)(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_SATURDAY->surrogateValue)));
  }
  else if (dow == KWD_TIMEPOINT_SUPPORT_SUNDAY) {
    return (((LogicObject*)(SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_SUNDAY->surrogateValue)));
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << dow << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

Object* helpExtractDateTimeComponent(DateTimeLogicWrapper* timepoint, double timeZone, GeneralizedSymbol* predicate) {
  { CalendarDate* date = ((CalendarDate*)(((DateTimeObject*)(timepoint->wrapperValue))));

    if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_YEAR) {
      { int year = NULL_INTEGER;
        int month = NULL_INTEGER;
        int day = NULL_INTEGER;
        Keyword* dow = NULL;

        year = date->getCalendarDate(timeZone, month, day, dow);
        {
          month = month;
          day = day;
          dow = dow;
        }
        return (wrapInteger(year));
      }
    }
    else if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_MONTH) {
      { int year = NULL_INTEGER;
        int month = NULL_INTEGER;
        int day = NULL_INTEGER;
        Keyword* dow = NULL;

        year = date->getCalendarDate(timeZone, month, day, dow);
        {
          year = year;
          day = day;
          dow = dow;
        }
        return (wrapInteger(month));
      }
    }
    else if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DAY) {
      { int year = NULL_INTEGER;
        int month = NULL_INTEGER;
        int day = NULL_INTEGER;
        Keyword* dow = NULL;

        year = date->getCalendarDate(timeZone, month, day, dow);
        {
          year = year;
          month = month;
          dow = dow;
        }
        return (wrapInteger(day));
      }
    }
    else if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK) {
      { int year = NULL_INTEGER;
        int month = NULL_INTEGER;
        int day = NULL_INTEGER;
        Keyword* dow = NULL;

        year = date->getCalendarDate(timeZone, month, day, dow);
        {
          year = year;
          month = month;
          day = day;
        }
        return (dowKeywordToInstance(dow));
      }
    }
    else if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_HOUR) {
      { int hour = NULL_INTEGER;
        int minute = NULL_INTEGER;
        int second = NULL_INTEGER;
        int millisecond = NULL_INTEGER;

        hour = date->getTime(timeZone, minute, second, millisecond);
        {
          minute = minute;
          second = second;
          millisecond = millisecond;
        }
        return (wrapInteger(hour));
      }
    }
    else if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_MINUTE) {
      { int hour = NULL_INTEGER;
        int minute = NULL_INTEGER;
        int second = NULL_INTEGER;
        int millisecond = NULL_INTEGER;

        hour = date->getTime(timeZone, minute, second, millisecond);
        {
          hour = hour;
          second = second;
          millisecond = millisecond;
        }
        return (wrapInteger(minute));
      }
    }
    else if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_SECOND) {
      { int hour = NULL_INTEGER;
        int minute = NULL_INTEGER;
        int second = NULL_INTEGER;
        int millisecond = NULL_INTEGER;

        hour = date->getTime(timeZone, minute, second, millisecond);
        {
          hour = hour;
          minute = minute;
        }
        if (millisecond == 0) {
          return (wrapInteger(second));
        }
        else {
          return (wrapFloat(((double)(second)) + (millisecond * 0.001)));
        }
      }
    }
    else if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DATE) {
      return (wrapString(date->calendarDateToDateString(timeZone, false)));
    }
    else if (predicate == SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_TIME) {
      return (wrapString(date->calendarDateToTimeString(timeZone, true, true, true)));
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << predicate << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Keyword* timepointAccessorSpecialist(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;
    GeneralizedSymbol* predicate = proposition->operatoR;
    Object* timepointValue = valueOf((proposition->arguments->theArray)[0]);
    Object* timeZoneValue = valueOf((proposition->arguments->theArray)[1]);
    Object* result = valueOf((proposition->arguments->theArray)[2]);
    DateTimeLogicWrapper* timepoint = helpGetTimeObject(timepointValue);
    double timeZone = helpGetTimeZone(timeZoneValue);

    lastmove = lastmove;
    try {
      if ((!((boolean)(timepoint))) ||
          (timeZone == NULL_FLOAT)) {
        return (KWD_TIMEPOINT_SUPPORT_FAILURE);
      }
      else if (((boolean)(result))) {
        { Object* theValue = helpExtractDateTimeComponent(timepoint, timeZone, predicate);

          { Surrogate* testValue000 = safePrimaryType(result);

            if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
              { Object* result000 = result;
                PatternVariable* result = ((PatternVariable*)(result000));

                return (selectProofResult(bindVariableToValueP(result, theValue, true), false, true));
              }
            }
            else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM)) {
              { Object* result001 = result;
                Skolem* result = ((Skolem*)(result001));

                { Skolem* object000 = result;
                  Object* value000 = theValue;
                  Object* oldValue000 = object000->variableValue;
                  Object* newValue000 = updateInContext(oldValue000, value000, object000->homeContext, false);

                  if (!(((boolean)(oldValue000)) &&
                      (oldValue000->primaryType() == SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE))) {
                    object000->variableValue = newValue000;
                  }
                }
                return (KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS);
              }
            }
            else if (subtypeOfP(testValue000, SGT_TIMEPOINT_SUPPORT_STELLA_NUMBER_WRAPPER)) {
              { Object* result002 = result;
                NumberWrapper* result = ((NumberWrapper*)(result002));

                return (selectProofResult(theValue->objectEqlP(result), false, true));
              }
            }
            else if (subtypeOfStringP(testValue000)) {
              { Object* result003 = result;
                StringWrapper* result = ((StringWrapper*)(result003));

                if (isaP(theValue, SGT_TIMEPOINT_SUPPORT_STELLA_STRING_WRAPPER)) {
                  return (selectProofResult(stringEqualP(((StringWrapper*)(theValue))->wrapperValue, result->wrapperValue), false, true));
                }
                else {
                  return (KWD_TIMEPOINT_SUPPORT_FAILURE);
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
      }
      else {
        return (KWD_TIMEPOINT_SUPPORT_FAILURE);
      }
    }
    catch (StellaException ) {
      setFrameTruthValue(frame, UNKNOWN_TRUTH_VALUE);
      return (KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE);
    }
  }
}

void helpStartupTimepointSupport1() {
  {
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("DATE-TIME-LOGIC-WRAPPER", NULL, 1)));
    SYM_TIMEPOINT_SUPPORT_STELLA_WRAPPER_VALUE = ((Symbol*)(internRigidSymbolWrtModule("WRAPPER-VALUE", getStellaModule("/STELLA", true), 0)));
    SGT_TIMEPOINT_SUPPORT_STELLA_CALENDAR_DATE = ((Surrogate*)(internRigidSymbolWrtModule("CALENDAR-DATE", getStellaModule("/STELLA", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_OF = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-OF", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_STELLA_TIME_DURATION = ((Surrogate*)(internRigidSymbolWrtModule("TIME-DURATION", getStellaModule("/STELLA", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_DURATION_OF = ((Surrogate*)(internRigidSymbolWrtModule("DURATION-OF", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", getStellaModule("/LOGIC", true), 1)));
    SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM = ((Surrogate*)(internRigidSymbolWrtModule("SKOLEM", getStellaModule("/LOGIC", true), 1)));
    SGT_TIMEPOINT_SUPPORT_UNIT_SUPPORT_DIM_NUMBER_LOGIC_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("DIM-NUMBER-LOGIC-WRAPPER", getStellaModule("/UNIT-SUPPORT", true), 1)));
    SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE = ((Surrogate*)(internRigidSymbolWrtModule("CS-VALUE", getStellaModule("/STELLA", true), 1)));
    KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS = ((Keyword*)(internRigidSymbolWrtModule("FINAL-SUCCESS", NULL, 2)));
    KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE = ((Keyword*)(internRigidSymbolWrtModule("TERMINAL-FAILURE", NULL, 2)));
    KWD_TIMEPOINT_SUPPORT_FAILURE = ((Keyword*)(internRigidSymbolWrtModule("FAILURE", NULL, 2)));
    KWD_TIMEPOINT_SUPPORT_MONDAY = ((Keyword*)(internRigidSymbolWrtModule("MONDAY", NULL, 2)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_MONDAY = ((Surrogate*)(internRigidSymbolWrtModule("MONDAY", getStellaModule("/TIMEPOINT-KB", true), 1)));
    KWD_TIMEPOINT_SUPPORT_TUESDAY = ((Keyword*)(internRigidSymbolWrtModule("TUESDAY", NULL, 2)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TUESDAY = ((Surrogate*)(internRigidSymbolWrtModule("TUESDAY", getStellaModule("/TIMEPOINT-KB", true), 1)));
    KWD_TIMEPOINT_SUPPORT_WEDNESDAY = ((Keyword*)(internRigidSymbolWrtModule("WEDNESDAY", NULL, 2)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_WEDNESDAY = ((Surrogate*)(internRigidSymbolWrtModule("WEDNESDAY", getStellaModule("/TIMEPOINT-KB", true), 1)));
    KWD_TIMEPOINT_SUPPORT_THURSDAY = ((Keyword*)(internRigidSymbolWrtModule("THURSDAY", NULL, 2)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_THURSDAY = ((Surrogate*)(internRigidSymbolWrtModule("THURSDAY", getStellaModule("/TIMEPOINT-KB", true), 1)));
    KWD_TIMEPOINT_SUPPORT_FRIDAY = ((Keyword*)(internRigidSymbolWrtModule("FRIDAY", NULL, 2)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_FRIDAY = ((Surrogate*)(internRigidSymbolWrtModule("FRIDAY", getStellaModule("/TIMEPOINT-KB", true), 1)));
    KWD_TIMEPOINT_SUPPORT_SATURDAY = ((Keyword*)(internRigidSymbolWrtModule("SATURDAY", NULL, 2)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_SATURDAY = ((Surrogate*)(internRigidSymbolWrtModule("SATURDAY", getStellaModule("/TIMEPOINT-KB", true), 1)));
    KWD_TIMEPOINT_SUPPORT_SUNDAY = ((Keyword*)(internRigidSymbolWrtModule("SUNDAY", NULL, 2)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_SUNDAY = ((Surrogate*)(internRigidSymbolWrtModule("SUNDAY", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_YEAR = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-YEAR", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_MONTH = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-MONTH", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DAY = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-DAY", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-DAY-OF-WEEK", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_HOUR = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-HOUR", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_MINUTE = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-MINUTE", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_SECOND = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-SECOND", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DATE = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-DATE", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_TIME = ((Surrogate*)(internRigidSymbolWrtModule("TIMEPOINT-TIME", getStellaModule("/TIMEPOINT-KB", true), 1)));
    SGT_TIMEPOINT_SUPPORT_STELLA_NUMBER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("NUMBER-WRAPPER", getStellaModule("/STELLA", true), 1)));
    SGT_TIMEPOINT_SUPPORT_STELLA_STRING_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("STRING-WRAPPER", getStellaModule("/STELLA", true), 1)));
    SYM_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_SUPPORT = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-TIMEPOINT-SUPPORT", NULL, 0)));
    SYM_TIMEPOINT_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
  }
}

void startupTimepointSupport() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/TIMEPOINT-SUPPORT", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupTimepointSupport1();
    }
    if (currentStartupTimePhaseP(4)) {
      oDATE_TIME_HASH_TABLEo = newStellaHashTable();
    }
    if (currentStartupTimePhaseP(5)) {
      { Class* clasS = defineClassFromStringifiedSource("DATE-TIME-LOGIC-WRAPPER", "(DEFCLASS DATE-TIME-LOGIC-WRAPPER (QUANTITY-LOGIC-WRAPPER) :PUBLIC-SLOTS ((WRAPPER-VALUE :TYPE DATE-TIME-OBJECT :REQUIRED? TRUE)) :PRINT-FORM (IF *PRINTREADABLY?* (PRINT-NATIVE-STREAM STREAM (WRAPPER-VALUE SELF)) (PRINT-NATIVE-STREAM STREAM \"|tw|\" (WRAPPER-VALUE SELF))))");

        clasS->classConstructorCode = ((cpp_function_code)(&newDateTimeLogicWrapper));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessDateTimeLogicWrapperSlotValue));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineMethodObject("(DEFMETHOD (GENERATE-SPECIALIZED-TERM OBJECT) ((SELF DATE-TIME-LOGIC-WRAPPER)))", ((cpp_method_code)(&DateTimeLogicWrapper::generateSpecializedTerm)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (HASH-CODE INTEGER) ((SELF DATE-TIME-LOGIC-WRAPPER)))", ((cpp_method_code)(&DateTimeLogicWrapper::hashCode)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (OBJECT-EQL? BOOLEAN) ((SELF DATE-TIME-LOGIC-WRAPPER) (X OBJECT)))", ((cpp_method_code)(&DateTimeLogicWrapper::objectEqlP)), ((cpp_method_code)(NULL)));
      defineFunctionObject("WRAP-DATE-TIME", "(DEFUN (WRAP-DATE-TIME DATE-TIME-LOGIC-WRAPPER) ((VALUE DATE-TIME-OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return an interned LOGIC-WRAPPER for `value'.  This assures us\nthat all logic-wrapped DATE-TIME-OBJECTs are the same object.\")", ((cpp_function_code)(&wrapDateTime)), NULL);
      defineFunctionObject("HELP-GET-CALENDAR-TIME", "(DEFUN (HELP-GET-CALENDAR-TIME DATE-TIME-LOGIC-WRAPPER) ((ITEM OBJECT)))", ((cpp_function_code)(&helpGetCalendarTime)), NULL);
      defineFunctionObject("HELP-GET-TIME-DURATION", "(DEFUN (HELP-GET-TIME-DURATION DATE-TIME-LOGIC-WRAPPER) ((ITEM OBJECT)))", ((cpp_function_code)(&helpGetTimeDuration)), NULL);
      defineFunctionObject("HELP-GET-TIME-OBJECT", "(DEFUN (HELP-GET-TIME-OBJECT DATE-TIME-LOGIC-WRAPPER) ((ITEM OBJECT)))", ((cpp_function_code)(&helpGetTimeObject)), NULL);
      defineFunctionObject("HELP-GET-INTEGER", "(DEFUN (HELP-GET-INTEGER INTEGER) ((OBJ OBJECT)))", ((cpp_function_code)(&helpGetInteger)), NULL);
      defineFunctionObject("HELP-GET-FLOAT", "(DEFUN (HELP-GET-FLOAT FLOAT) ((OBJ OBJECT)))", ((cpp_function_code)(&helpGetFloat)), NULL);
      defineFunctionObject("HELP-GET-TIMEZONE", "(DEFUN (HELP-GET-TIMEZONE FLOAT) ((OBJ OBJECT)))", ((cpp_function_code)(&helpGetTimezone)), NULL);
      defineFunctionObject("CAN-BIND-ALL?", "(DEFUN (CAN-BIND-ALL? BOOLEAN) ((PL-OBJECTS CONS) (VALUES CONS)))", ((cpp_function_code)(&canBindAllP)), NULL);
      defineFunctionObject("TIMEPOINT-OF-EVALUATOR", "(DEFUN TIMEPOINT-OF-EVALUATOR ((SELF PROPOSITION)))", ((cpp_function_code)(&timepointOfEvaluator)), NULL);
      defineFunctionObject("TIMEPOINT-OF-SPECIALIST", "(DEFUN (TIMEPOINT-OF-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&timepointOfSpecialist)), NULL);
      defineFunctionObject("TIMEPOINT-OF*-EVALUATOR", "(DEFUN TIMEPOINT-OF*-EVALUATOR ((SELF PROPOSITION)))", ((cpp_function_code)(&timepointOfOEvaluator)), NULL);
      defineFunctionObject("TIMEPOINT-OF*-SPECIALIST", "(DEFUN (TIMEPOINT-OF*-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&timepointOfOSpecialist)), NULL);
      defineFunctionObject("DURATION-OF-EVALUATOR", "(DEFUN DURATION-OF-EVALUATOR ((SELF PROPOSITION)))", ((cpp_function_code)(&durationOfEvaluator)), NULL);
      defineFunctionObject("DURATION-OF-SPECIALIST", "(DEFUN (DURATION-OF-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&durationOfSpecialist)), NULL);
      defineFunctionObject("TIME-MINUS-EVALUATOR", "(DEFUN TIME-MINUS-EVALUATOR ((SELF PROPOSITION)))", ((cpp_function_code)(&timeMinusEvaluator)), NULL);
      defineFunctionObject("TIME-ADD-EVALUATOR", "(DEFUN TIME-ADD-EVALUATOR ((SELF PROPOSITION)))", ((cpp_function_code)(&timeAddEvaluator)), NULL);
      defineFunctionObject("TIME-MINUS-CONSTRAINT", "(DEFUN (TIME-MINUS-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 DATE-TIME-LOGIC-WRAPPER) (X2 DATE-TIME-LOGIC-WRAPPER) (X3 DATE-TIME-LOGIC-WRAPPER)))", ((cpp_function_code)(&timeMinusConstraint)), NULL);
      defineFunctionObject("TIME-ADD-CONSTRAINT", "(DEFUN (TIME-ADD-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 DATE-TIME-LOGIC-WRAPPER) (X2 DATE-TIME-LOGIC-WRAPPER) (X3 DATE-TIME-LOGIC-WRAPPER)))", ((cpp_function_code)(&timeAddConstraint)), NULL);
      defineFunctionObject("HELP-GET-TIME-ZONE", "(DEFUN (HELP-GET-TIME-ZONE FLOAT) ((TIME-ZONE-SPECIFIER OBJECT)))", ((cpp_function_code)(&helpGetTimeZone)), NULL);
      defineFunctionObject("DOW-KEYWORD-TO-INSTANCE", "(DEFUN (DOW-KEYWORD-TO-INSTANCE LOGIC-OBJECT) ((DOW KEYWORD)))", ((cpp_function_code)(&dowKeywordToInstance)), NULL);
      defineFunctionObject("HELP-EXTRACT-DATE-TIME-COMPONENT", "(DEFUN (HELP-EXTRACT-DATE-TIME-COMPONENT OBJECT) ((TIMEPOINT DATE-TIME-LOGIC-WRAPPER) (TIME-ZONE FLOAT) (PREDICATE GENERALIZED-SYMBOL)))", ((cpp_function_code)(&helpExtractDateTimeComponent)), NULL);
      defineFunctionObject("TIMEPOINT-ACCESSOR-SPECIALIST", "(DEFUN (TIMEPOINT-ACCESSOR-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&timepointAccessorSpecialist)), NULL);
      defineFunctionObject("STARTUP-TIMEPOINT-SUPPORT", "(DEFUN STARTUP-TIMEPOINT-SUPPORT () :PUBLIC? TRUE)", ((cpp_function_code)(&startupTimepointSupport)), NULL);
      { MethodSlot* function = lookupFunction(SYM_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_SUPPORT);

        setDynamicSlotValue(function->dynamicSlots, SYM_TIMEPOINT_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupTimepointSupport"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DATE-TIME-HASH-TABLE* (STELLA-HASH-TABLE OF DATE-TIME-OBJECT DATE-TIME-LOGIC-WRAPPER) (NEW STELLA-HASH-TABLE) :DOCUMENTATION \"Table for interning date-time logic wrappers\")");
    }
  }
}

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER = NULL;

Symbol* SYM_TIMEPOINT_SUPPORT_STELLA_WRAPPER_VALUE = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_CALENDAR_DATE = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_OF = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_TIME_DURATION = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_DURATION_OF = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_LOGIC_PATTERN_VARIABLE = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_LOGIC_SKOLEM = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_UNIT_SUPPORT_DIM_NUMBER_LOGIC_WRAPPER = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_CS_VALUE = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_FINAL_SUCCESS = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_TERMINAL_FAILURE = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_FAILURE = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_MONDAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_MONDAY = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_TUESDAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TUESDAY = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_WEDNESDAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_WEDNESDAY = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_THURSDAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_THURSDAY = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_FRIDAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_FRIDAY = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_SATURDAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_SATURDAY = NULL;

Keyword* KWD_TIMEPOINT_SUPPORT_SUNDAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_SUNDAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_YEAR = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_MONTH = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DAY = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_HOUR = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_MINUTE = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_SECOND = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_DATE = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_TIMEPOINT_KB_TIMEPOINT_TIME = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_NUMBER_WRAPPER = NULL;

Surrogate* SGT_TIMEPOINT_SUPPORT_STELLA_STRING_WRAPPER = NULL;

Symbol* SYM_TIMEPOINT_SUPPORT_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_SUPPORT = NULL;

Symbol* SYM_TIMEPOINT_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace timepoint
