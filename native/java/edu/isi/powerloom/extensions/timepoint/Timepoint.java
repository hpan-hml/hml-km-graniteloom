//  -*- Mode: Java -*-
//
// Timepoint.java

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

package edu.isi.powerloom.extensions.timepoint;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;
import edu.isi.stella.utilities.*;

public class Timepoint {
  /** Table for interning date-time logic wrappers
   */
  public static StellaHashTable $DATE_TIME_HASH_TABLE$ = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_OF = null;

  public static Surrogate SGT_TIMEPOINT_KB_DURATION_OF = null;

  public static Keyword KWD_MONDAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_MONDAY = null;

  public static Keyword KWD_TUESDAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_TUESDAY = null;

  public static Keyword KWD_WEDNESDAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_WEDNESDAY = null;

  public static Keyword KWD_THURSDAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_THURSDAY = null;

  public static Keyword KWD_FRIDAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_FRIDAY = null;

  public static Keyword KWD_SATURDAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_SATURDAY = null;

  public static Keyword KWD_SUNDAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_SUNDAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_YEAR = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_MONTH = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_DAY = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_HOUR = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_MINUTE = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_SECOND = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_DATE = null;

  public static Surrogate SGT_TIMEPOINT_KB_TIMEPOINT_TIME = null;

  public static Surrogate SGT_STELLA_STRING_WRAPPER = null;

  public static Symbol SYM_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_SUPPORT = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT = null;

  public static Symbol SYM_TIMEPOINT_KB_DAY_OF_WEEK = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_OF = null;

  public static Symbol SYM_TIMEPOINT_SUPPORT_pTP = null;

  public static Symbol SYM_TIMEPOINT_KB_DURATION_OF = null;

  public static Symbol SYM_TIMEPOINT_KB_TIME_ = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEi = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_YEAR = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_MONTH = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_DAY = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_HOUR = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_MINUTE = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_SECOND = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_DATE = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_TIME = null;

  public static Symbol SYM_TIMEPOINT_KB_TIMEPOINT_OF$ = null;

  public static Symbol SYM_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_KB = null;

  /** Return an interned LOGIC-WRAPPER for <code>value</code>.  This assures us
   * that all logic-wrapped DATE-TIME-OBJECTs are the same object.
   * @param value
   * @return DateTimeLogicWrapper
   */
  public static DateTimeLogicWrapper wrapDateTime(DateTimeObject value) {
    { DateTimeLogicWrapper wrapper = ((DateTimeLogicWrapper)(Timepoint.$DATE_TIME_HASH_TABLE$.lookup(value)));

      if (wrapper == null) {
        wrapper = DateTimeLogicWrapper.newDateTimeLogicWrapper(value);
        Timepoint.$DATE_TIME_HASH_TABLE$.insertAt(value, wrapper);
      }
      return (wrapper);
    }
  }

  public static DateTimeLogicWrapper helpGetCalendarTime(Stella_Object item) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(item);

      if (Surrogate.subtypeOfStringP(testValue000)) {
        { StringWrapper item000 = ((StringWrapper)(item));

          { CalendarDate value = CalendarDate.stringToCalendarDate(item000.wrapperValue);

            if (value != null) {
              return (Timepoint.wrapDateTime(value));
            }
            else {
              return (null);
            }
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
        { PatternVariable item000 = ((PatternVariable)(item));

          { Stella_Object value = PatternVariable.safeBoundTo(item000);

            if (value != null) {
              return (Timepoint.helpGetCalendarTime(value));
            }
            else {
              return (null);
            }
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
        { DateTimeLogicWrapper item000 = ((DateTimeLogicWrapper)(item));

          return (item000);
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
        { Skolem item000 = ((Skolem)(item));

          { Stella_Object value = ((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false)));

            { Surrogate testValue001 = Stella_Object.safePrimaryType(value);

              if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
                { DateTimeLogicWrapper value000 = ((DateTimeLogicWrapper)(value));

                  return (value000);
                }
              }
              else if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                { Skolem value000 = ((Skolem)(value));

                  if (Stella_Object.isaP(((Stella_Object)(Stella_Object.accessInContext(value000.variableValue, value000.homeContext, false))), edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                    return (null);
                  }
                  else {
                    return (Timepoint.helpGetCalendarTime(((Stella_Object)(Stella_Object.accessInContext(value000.variableValue, value000.homeContext, false)))));
                  }
                }
              }
              else {
                if (Stella_Object.isaP(((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false))), edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                  return (null);
                }
                else {
                  return (Timepoint.helpGetCalendarTime(((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false)))));
                }
              }
            }
          }
        }
      }
      else {
        return (null);
      }
    }
  }

  public static DateTimeLogicWrapper helpGetTimeDuration(Stella_Object item) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(item);

      if (Surrogate.subtypeOfStringP(testValue000)) {
        { StringWrapper item000 = ((StringWrapper)(item));

          { TimeDuration value = TimeDuration.stringToTimeDuration(item000.wrapperValue);

            if (value != null) {
              return (Timepoint.wrapDateTime(value));
            }
            else {
              return (null);
            }
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
        { PatternVariable item000 = ((PatternVariable)(item));

          { Stella_Object value = PatternVariable.safeBoundTo(item000);

            if (value != null) {
              return (Timepoint.helpGetTimeDuration(value));
            }
            else {
              return (null);
            }
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
        { DateTimeLogicWrapper item000 = ((DateTimeLogicWrapper)(item));

          return (item000);
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_UNIT_SUPPORT_DIM_NUMBER_LOGIC_WRAPPER)) {
        { edu.isi.powerloom.extensions.units.DimNumberLogicWrapper item000 = ((edu.isi.powerloom.extensions.units.DimNumberLogicWrapper)(item));

          try {
            return (Timepoint.wrapDateTime(DimNumber.dimToTimeDuration(((DimNumber)(item000.wrapperValue)))));
          } catch (IncompatibleUnitsException e000) {
            return (null);
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
        { Skolem item000 = ((Skolem)(item));

          { Stella_Object value = ((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false)));

            { Surrogate testValue001 = Stella_Object.safePrimaryType(value);

              if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
                { DateTimeLogicWrapper value000 = ((DateTimeLogicWrapper)(value));

                  return (value000);
                }
              }
              else if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                { Skolem value000 = ((Skolem)(value));

                  if (Stella_Object.isaP(((Stella_Object)(Stella_Object.accessInContext(value000.variableValue, value000.homeContext, false))), edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                    return (null);
                  }
                  else {
                    return (Timepoint.helpGetTimeDuration(((Stella_Object)(Stella_Object.accessInContext(value000.variableValue, value000.homeContext, false)))));
                  }
                }
              }
              else {
                if (Stella_Object.isaP(((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false))), edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                  return (null);
                }
                else {
                  return (Timepoint.helpGetTimeDuration(((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false)))));
                }
              }
            }
          }
        }
      }
      else {
        return (null);
      }
    }
  }

  public static DateTimeLogicWrapper helpGetTimeObject(Stella_Object item) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(item);

      if (Surrogate.subtypeOfStringP(testValue000)) {
        { StringWrapper item000 = ((StringWrapper)(item));

          { DateTimeObject value = CalendarDate.stringToCalendarDate(item000.wrapperValue);

            if (value == null) {
              value = TimeDuration.stringToTimeDuration(item000.wrapperValue);
            }
            if (value != null) {
              return (Timepoint.wrapDateTime(value));
            }
            else {
              return (null);
            }
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
        { PatternVariable item000 = ((PatternVariable)(item));

          { Stella_Object value = PatternVariable.safeBoundTo(item000);

            if (value != null) {
              return (Timepoint.helpGetTimeObject(value));
            }
            else {
              return (null);
            }
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
        { DateTimeLogicWrapper item000 = ((DateTimeLogicWrapper)(item));

          return (item000);
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_UNIT_SUPPORT_DIM_NUMBER_LOGIC_WRAPPER)) {
        { edu.isi.powerloom.extensions.units.DimNumberLogicWrapper item000 = ((edu.isi.powerloom.extensions.units.DimNumberLogicWrapper)(item));

          try {
            return (Timepoint.wrapDateTime(DimNumber.dimToTimeDuration(((DimNumber)(item000.wrapperValue)))));
          } catch (IncompatibleUnitsException e000) {
            return (null);
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
        { Skolem item000 = ((Skolem)(item));

          { Stella_Object value = ((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false)));

            { Surrogate testValue001 = Stella_Object.safePrimaryType(value);

              if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
                { DateTimeLogicWrapper value000 = ((DateTimeLogicWrapper)(value));

                  return (value000);
                }
              }
              else if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                { Skolem value000 = ((Skolem)(value));

                  if (Stella_Object.isaP(((Stella_Object)(Stella_Object.accessInContext(value000.variableValue, value000.homeContext, false))), edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                    return (null);
                  }
                  else {
                    return (Timepoint.helpGetTimeObject(((Stella_Object)(Stella_Object.accessInContext(value000.variableValue, value000.homeContext, false)))));
                  }
                }
              }
              else {
                if (Stella_Object.isaP(((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false))), edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                  return (null);
                }
                else {
                  return (Timepoint.helpGetTimeObject(((Stella_Object)(Stella_Object.accessInContext(item000.variableValue, item000.homeContext, false)))));
                }
              }
            }
          }
        }
      }
      else {
        return (null);
      }
    }
  }

  public static int helpGetInteger(Stella_Object obj) {
    if (obj == null) {
      return (Stella.NULL_INTEGER);
    }
    else {
      { Surrogate testValue000 = Stella_Object.safePrimaryType(obj);

        if (Surrogate.subtypeOfFloatP(testValue000)) {
          { FloatWrapper obj000 = ((FloatWrapper)(obj));

            if (Stella.integerValuedP(obj000.wrapperValue)) {
              return (Native.floor(obj000.wrapperValue));
            }
            else {
              return (Stella.NULL_INTEGER);
            }
          }
        }
        else if (Surrogate.subtypeOfIntegerP(testValue000)) {
          { IntegerWrapper obj000 = ((IntegerWrapper)(obj));

            return (obj000.wrapperValue);
          }
        }
        else {
          return (Stella.NULL_INTEGER);
        }
      }
    }
  }

  public static double helpGetFloat(Stella_Object obj) {
    if (obj == null) {
      return (Stella.NULL_FLOAT);
    }
    else {
      { Surrogate testValue000 = Stella_Object.safePrimaryType(obj);

        if (Surrogate.subtypeOfFloatP(testValue000)) {
          { FloatWrapper obj000 = ((FloatWrapper)(obj));

            return (obj000.wrapperValue);
          }
        }
        else if (Surrogate.subtypeOfIntegerP(testValue000)) {
          { IntegerWrapper obj000 = ((IntegerWrapper)(obj));

            return (((double)(obj000.wrapperValue)));
          }
        }
        else {
          return (Stella.NULL_FLOAT);
        }
      }
    }
  }

  public static double helpGetTimezone(Stella_Object obj) {
    if (obj == null) {
      return (Stella.NULL_FLOAT);
    }
    else {
      { Surrogate testValue000 = Stella_Object.safePrimaryType(obj);

        if (Surrogate.subtypeOfFloatP(testValue000)) {
          { FloatWrapper obj000 = ((FloatWrapper)(obj));

            return (obj000.wrapperValue);
          }
        }
        else if (Surrogate.subtypeOfIntegerP(testValue000)) {
          { IntegerWrapper obj000 = ((IntegerWrapper)(obj));

            return (((double)(obj000.wrapperValue)));
          }
        }
        else if (Surrogate.subtypeOfStringP(testValue000)) {
          { StringWrapper obj000 = ((StringWrapper)(obj));

            { FloatWrapper decodedZone = Stella_Object.zone(StringWrapper.wrapString(Native.stringDowncase(obj000.wrapperValue)));

              if (decodedZone != null) {
                return (decodedZone.wrapperValue);
              }
              else {
                return (Stella.NULL_FLOAT);
              }
            }
          }
        }
        else {
          return (Stella.NULL_FLOAT);
        }
      }
    }
  }

  public static boolean canBindAllP(Cons plObjects, Cons values) {
    { Stella_Object obj = null;
      Cons iter000 = plObjects;
      Stella_Object value = null;
      Cons iter001 = values;

      for (;(!(iter000 == Stella.NIL)) &&
                (!(iter001 == Stella.NIL)); iter000 = iter000.rest, iter001 = iter001.rest) {
        obj = iter000.value;
        value = iter001.value;
        { Surrogate testValue000 = Stella_Object.safePrimaryType(obj);

          if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
            { PatternVariable obj000 = ((PatternVariable)(obj));

              if (!(PatternVariable.bindVariableToValueP(obj000, value, true))) {
                return (false);
              }
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
            { Skolem obj000 = ((Skolem)(obj));

              { Skolem object000 = obj000;
                Stella_Object value000 = value;
                Stella_Object oldValue000 = object000.variableValue;
                Stella_Object newValue000 = Stella_Object.updateInContext(oldValue000, value000, object000.homeContext, false);

                if (!((oldValue000 != null) &&
                    (oldValue000.primaryType() == edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CS_VALUE))) {
                  object000.variableValue = newValue000;
                }
              }
            }
          }
          else {
            if (!(obj.objectEqlP(value))) {
              return (false);
            }
          }
        }
      }
    }
    return (true);
  }

  public static void timepointOfEvaluator(Proposition self) {
    { Stella_Object value1 = Logic.valueOf((self.arguments.theArray)[0]);
      Stella_Object value2 = Logic.valueOf((self.arguments.theArray)[1]);
      DateTimeLogicWrapper time1 = Timepoint.helpGetCalendarTime(value1);

      if (time1 != null) {
        { Surrogate testValue000 = Stella_Object.safePrimaryType(value2);

          if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
            { Skolem value2000 = ((Skolem)(value2));

              Skolem.bindSkolemToValue(value2000, time1, false);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
            { DateTimeLogicWrapper value2000 = ((DateTimeLogicWrapper)(value2));

              if (!(((DateTimeObject)(time1.wrapperValue)).objectEqlP(((DateTimeObject)(value2000.wrapperValue))))) {
                Logic.signalUnificationClash(time1, value2000);
              }
            }
          }
          else {
            Logic.signalUnificationClash(time1, value2);
          }
        }
      }
    }
  }

  public static Keyword timepointOfSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object value1 = Logic.valueOf((proposition.arguments.theArray)[0]);
      Stella_Object value2 = Logic.valueOf((proposition.arguments.theArray)[1]);
      DateTimeLogicWrapper theTime = Timepoint.helpGetCalendarTime(value1);

      lastmove = lastmove;
      if (theTime != null) {
        { Surrogate testValue000 = Stella_Object.safePrimaryType(value2);

          if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
            { PatternVariable value2000 = ((PatternVariable)(value2));

              return (Logic.selectProofResult(PatternVariable.bindVariableToValueP(value2000, theTime, true), false, true));
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
            { Skolem value2000 = ((Skolem)(value2));

              { Skolem object000 = value2000;
                Stella_Object value000 = theTime;
                Stella_Object oldValue000 = object000.variableValue;
                Stella_Object newValue000 = Stella_Object.updateInContext(oldValue000, value000, object000.homeContext, false);

                if (!((oldValue000 != null) &&
                    (oldValue000.primaryType() == edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CS_VALUE))) {
                  object000.variableValue = newValue000;
                }
              }
              return (edu.isi.powerloom.extensions.units.Units.KWD_FINAL_SUCCESS);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
            { DateTimeLogicWrapper value2000 = ((DateTimeLogicWrapper)(value2));

              return (Logic.selectProofResult(((DateTimeObject)(theTime.wrapperValue)).objectEqlP(((DateTimeObject)(value2000.wrapperValue))), false, true));
            }
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        }
      }
      else if (value2 != null) {
        theTime = Timepoint.helpGetCalendarTime(value2);
        if (theTime != null) {
          { Surrogate testValue001 = Stella_Object.safePrimaryType(value1);

            if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
              { PatternVariable value1000 = ((PatternVariable)(value1));

                return (Logic.selectProofResult(PatternVariable.bindVariableToValueP(value1000, StringWrapper.wrapString(((CalendarDate)(((DateTimeObject)(theTime.wrapperValue)))).calendarDateToString(0.0, false, true)), true), false, true));
              }
            }
            else if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
              { Skolem value1000 = ((Skolem)(value1));

                { Skolem object001 = value1000;
                  Stella_Object value001 = StringWrapper.wrapString(((CalendarDate)(((DateTimeObject)(theTime.wrapperValue)))).calendarDateToString(0.0, false, true));
                  Stella_Object oldValue001 = object001.variableValue;
                  Stella_Object newValue001 = Stella_Object.updateInContext(oldValue001, value001, object001.homeContext, false);

                  if (!((oldValue001 != null) &&
                      (oldValue001.primaryType() == edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CS_VALUE))) {
                    object001.variableValue = newValue001;
                  }
                }
                return (edu.isi.powerloom.extensions.units.Units.KWD_FINAL_SUCCESS);
              }
            }
            else {
              return (edu.isi.powerloom.extensions.units.Units.KWD_TERMINAL_FAILURE);
            }
          }
        }
        else {
          return (edu.isi.powerloom.extensions.units.Units.KWD_TERMINAL_FAILURE);
        }
      }
      else {
        return (edu.isi.powerloom.extensions.units.Units.KWD_FAILURE);
      }
    }
  }

  public static void timepointOf$Evaluator(Proposition self) {
    { Vector args = self.arguments;
      Stella_Object yyValue = Logic.valueOf((args.theArray)[0]);
      Stella_Object mmValue = Logic.valueOf((args.theArray)[1]);
      Stella_Object ddValue = Logic.valueOf((args.theArray)[2]);
      Stella_Object hrValue = Logic.valueOf((args.theArray)[3]);
      Stella_Object minValue = Logic.valueOf((args.theArray)[4]);
      Stella_Object secValue = Logic.valueOf((args.theArray)[5]);
      Stella_Object tzValue = Logic.valueOf((args.theArray)[6]);
      Stella_Object tpValue = Logic.valueOf((args.theArray)[7]);
      int year = Timepoint.helpGetInteger(yyValue);
      int month = Timepoint.helpGetInteger(mmValue);
      int day = Timepoint.helpGetInteger(ddValue);
      int hour = Timepoint.helpGetInteger(hrValue);
      int minute = Timepoint.helpGetInteger(minValue);
      double secondFloat = Timepoint.helpGetFloat(secValue);
      double zone = Timepoint.helpGetTimezone(tzValue);
      int second = 0;
      DateTimeLogicWrapper time1 = null;

      if ((year != Stella.NULL_INTEGER) &&
          ((month != Stella.NULL_INTEGER) &&
           ((day != Stella.NULL_INTEGER) &&
            ((hour != Stella.NULL_INTEGER) &&
             ((minute != Stella.NULL_INTEGER) &&
              ((secondFloat != Stella.NULL_FLOAT) &&
               (zone != Stella.NULL_FLOAT))))))) {
        second = Native.floor(secondFloat);
        time1 = Timepoint.wrapDateTime(CalendarDate.makeDateTime(year, month, day, hour, minute, second, Native.floor(1000 * (secondFloat - second)), zone));
        { Surrogate testValue000 = Stella_Object.safePrimaryType(tpValue);

          if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
            { Skolem tpValue000 = ((Skolem)(tpValue));

              Skolem.bindSkolemToValue(tpValue000, time1, false);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
            { DateTimeLogicWrapper tpValue000 = ((DateTimeLogicWrapper)(tpValue));

              if (!(((DateTimeObject)(time1.wrapperValue)).objectEqlP(((DateTimeObject)(tpValue000.wrapperValue))))) {
                Logic.signalUnificationClash(time1, tpValue000);
              }
            }
          }
          else {
            Logic.signalUnificationClash(time1, tpValue);
          }
        }
      }
    }
  }

  public static Keyword timepointOf$Specialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Vector args = proposition.arguments;
      Stella_Object yyValue = Logic.valueOf((args.theArray)[0]);
      Stella_Object mmValue = Logic.valueOf((args.theArray)[1]);
      Stella_Object ddValue = Logic.valueOf((args.theArray)[2]);
      Stella_Object hrValue = Logic.valueOf((args.theArray)[3]);
      Stella_Object minValue = Logic.valueOf((args.theArray)[4]);
      Stella_Object secValue = Logic.valueOf((args.theArray)[5]);
      Stella_Object tzValue = Logic.valueOf((args.theArray)[6]);
      Stella_Object tpValue = Logic.valueOf((args.theArray)[7]);
      int year = Timepoint.helpGetInteger(yyValue);
      int month = Timepoint.helpGetInteger(mmValue);
      int day = Timepoint.helpGetInteger(ddValue);
      int hour = Timepoint.helpGetInteger(hrValue);
      int minute = Timepoint.helpGetInteger(minValue);
      double secondFloat = Timepoint.helpGetFloat(secValue);
      int second = 0;
      double zone = Timepoint.helpGetTimezone(tzValue);
      DateTimeLogicWrapper theTime = null;
      CalendarDate calendarDate = null;

      lastmove = lastmove;
      if ((year != Stella.NULL_INTEGER) &&
          ((month != Stella.NULL_INTEGER) &&
           ((day != Stella.NULL_INTEGER) &&
            ((hour != Stella.NULL_INTEGER) &&
             ((minute != Stella.NULL_INTEGER) &&
              ((secondFloat != Stella.NULL_FLOAT) &&
               (zone != Stella.NULL_FLOAT))))))) {
        second = Native.floor(secondFloat);
        theTime = Timepoint.wrapDateTime(CalendarDate.makeDateTime(year, month, day, hour, minute, second, Native.floor(1000 * (secondFloat - second)), zone));
        { Surrogate testValue000 = Stella_Object.safePrimaryType(tpValue);

          if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
            { PatternVariable tpValue000 = ((PatternVariable)(tpValue));

              return (Logic.selectProofResult(PatternVariable.bindVariableToValueP(tpValue000, theTime, true), false, true));
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
            { Skolem tpValue000 = ((Skolem)(tpValue));

              { Skolem object000 = tpValue000;
                Stella_Object value000 = theTime;
                Stella_Object oldValue000 = object000.variableValue;
                Stella_Object newValue000 = Stella_Object.updateInContext(oldValue000, value000, object000.homeContext, false);

                if (!((oldValue000 != null) &&
                    (oldValue000.primaryType() == edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CS_VALUE))) {
                  object000.variableValue = newValue000;
                }
              }
              return (edu.isi.powerloom.extensions.units.Units.KWD_FINAL_SUCCESS);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
            { DateTimeLogicWrapper tpValue000 = ((DateTimeLogicWrapper)(tpValue));

              return (Logic.selectProofResult(((DateTimeObject)(theTime.wrapperValue)).objectEqlP(((DateTimeObject)(tpValue000.wrapperValue))), false, true));
            }
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        }
      }
      else if (tpValue != null) {
        theTime = Timepoint.helpGetCalendarTime(tpValue);
        calendarDate = ((CalendarDate)(((DateTimeObject)(theTime.wrapperValue))));
        if (zone == Stella.NULL_FLOAT) {
          zone = 0.0;
          { Surrogate testValue001 = Stella_Object.safePrimaryType(tzValue);

            if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
              { PatternVariable tzValue000 = ((PatternVariable)(tzValue));

                if (!(PatternVariable.bindVariableToValueP(tzValue000, FloatWrapper.wrapFloat(zone), true))) {
                  return (edu.isi.powerloom.extensions.units.Units.KWD_FAILURE);
                }
              }
            }
            else if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
              { Skolem tzValue000 = ((Skolem)(tzValue));

                { Skolem object001 = tzValue000;
                  Stella_Object value001 = FloatWrapper.wrapFloat(zone);
                  Stella_Object oldValue001 = object001.variableValue;
                  Stella_Object newValue001 = Stella_Object.updateInContext(oldValue001, value001, object001.homeContext, false);

                  if (!((oldValue001 != null) &&
                      (oldValue001.primaryType() == edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CS_VALUE))) {
                    object001.variableValue = newValue001;
                  }
                }
              }
            }
            else {
              return (edu.isi.powerloom.extensions.units.Units.KWD_FAILURE);
            }
          }
        }
        if (theTime != null) {
          { int yy = Stella.NULL_INTEGER;
            int mm = Stella.NULL_INTEGER;
            int dd = Stella.NULL_INTEGER;
            Keyword dow = null;

            { Object [] caller_MV_returnarray = new Object[3];

              yy = calendarDate.getCalendarDate(zone, caller_MV_returnarray);
              mm = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
              dd = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
              dow = ((Keyword)(caller_MV_returnarray[2]));
            }
            dow = dow;
            { int h = Stella.NULL_INTEGER;
              int m = Stella.NULL_INTEGER;
              int s = Stella.NULL_INTEGER;
              int milli = Stella.NULL_INTEGER;

              { Object [] caller_MV_returnarray = new Object[3];

                h = calendarDate.getTime(zone, caller_MV_returnarray);
                m = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
                s = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
                milli = ((int)(((IntegerWrapper)(caller_MV_returnarray[2])).wrapperValue));
              }
              return (Logic.selectProofResult(Timepoint.canBindAllP(Stella.consList(Stella_Object.cons(yyValue, Stella_Object.cons(mmValue, Stella_Object.cons(ddValue, Stella_Object.cons(hrValue, Stella_Object.cons(minValue, Stella_Object.cons(secValue, Stella.NIL))))))), Stella.consList(Stella_Object.cons(IntegerWrapper.wrapInteger(yy), Stella_Object.cons(IntegerWrapper.wrapInteger(mm), Stella_Object.cons(IntegerWrapper.wrapInteger(dd), Stella_Object.cons(IntegerWrapper.wrapInteger(h), Stella_Object.cons(IntegerWrapper.wrapInteger(m), Stella_Object.cons(FloatWrapper.wrapFloat(((double)(s + (milli * 0.001)))), Stella.NIL)))))))), false, true));
            }
          }
        }
        else {
          return (edu.isi.powerloom.extensions.units.Units.KWD_TERMINAL_FAILURE);
        }
      }
      else {
        return (edu.isi.powerloom.extensions.units.Units.KWD_FAILURE);
      }
    }
  }

  public static void durationOfEvaluator(Proposition self) {
    { Stella_Object value1 = Logic.valueOf((self.arguments.theArray)[0]);
      Stella_Object value2 = Logic.valueOf((self.arguments.theArray)[1]);
      DateTimeLogicWrapper time1 = Timepoint.helpGetCalendarTime(value1);

      if (time1 != null) {
        { Surrogate testValue000 = Stella_Object.safePrimaryType(value2);

          if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
            { Skolem value2000 = ((Skolem)(value2));

              Skolem.bindSkolemToValue(value2000, time1, false);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
            { DateTimeLogicWrapper value2000 = ((DateTimeLogicWrapper)(value2));

              if (!(((DateTimeObject)(time1.wrapperValue)).objectEqlP(((DateTimeObject)(value2000.wrapperValue))))) {
                Logic.signalUnificationClash(time1, value2000);
              }
            }
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        }
      }
    }
  }

  public static Keyword durationOfSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object value1 = Logic.valueOf((proposition.arguments.theArray)[0]);
      Stella_Object value2 = Logic.valueOf((proposition.arguments.theArray)[1]);
      DateTimeLogicWrapper theTime = Timepoint.helpGetTimeDuration(value1);

      lastmove = lastmove;
      if (theTime != null) {
        { Surrogate testValue000 = Stella_Object.safePrimaryType(value2);

          if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
            { PatternVariable value2000 = ((PatternVariable)(value2));

              return (Logic.selectProofResult(PatternVariable.bindVariableToValueP(value2000, theTime, true), false, true));
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
            { Skolem value2000 = ((Skolem)(value2));

              { Skolem object000 = value2000;
                Stella_Object value000 = theTime;
                Stella_Object oldValue000 = object000.variableValue;
                Stella_Object newValue000 = Stella_Object.updateInContext(oldValue000, value000, object000.homeContext, false);

                if (!((oldValue000 != null) &&
                    (oldValue000.primaryType() == edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CS_VALUE))) {
                  object000.variableValue = newValue000;
                }
              }
              return (edu.isi.powerloom.extensions.units.Units.KWD_FINAL_SUCCESS);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER)) {
            { DateTimeLogicWrapper value2000 = ((DateTimeLogicWrapper)(value2));

              return (Logic.selectProofResult(((DateTimeObject)(theTime.wrapperValue)).objectEqlP(((DateTimeObject)(value2000.wrapperValue))), false, true));
            }
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        }
      }
      else if (value2 != null) {
        theTime = Timepoint.helpGetTimeDuration(value2);
        if (theTime != null) {
          { Surrogate testValue001 = Stella_Object.safePrimaryType(value1);

            if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
              { PatternVariable value1000 = ((PatternVariable)(value1));

                return (Logic.selectProofResult(PatternVariable.bindVariableToValueP(value1000, StringWrapper.wrapString(((TimeDuration)(((DateTimeObject)(theTime.wrapperValue)))).timeDurationToString()), true), false, true));
              }
            }
            else if (Surrogate.subtypeOfP(testValue001, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
              { Skolem value1000 = ((Skolem)(value1));

                { Skolem object001 = value1000;
                  Stella_Object value001 = StringWrapper.wrapString(((TimeDuration)(((DateTimeObject)(theTime.wrapperValue)))).timeDurationToString());
                  Stella_Object oldValue001 = object001.variableValue;
                  Stella_Object newValue001 = Stella_Object.updateInContext(oldValue001, value001, object001.homeContext, false);

                  if (!((oldValue001 != null) &&
                      (oldValue001.primaryType() == edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CS_VALUE))) {
                    object001.variableValue = newValue001;
                  }
                }
                return (edu.isi.powerloom.extensions.units.Units.KWD_FINAL_SUCCESS);
              }
            }
            else {
              return (edu.isi.powerloom.extensions.units.Units.KWD_TERMINAL_FAILURE);
            }
          }
        }
        else {
          return (edu.isi.powerloom.extensions.units.Units.KWD_TERMINAL_FAILURE);
        }
      }
      else {
        return (edu.isi.powerloom.extensions.units.Units.KWD_FAILURE);
      }
    }
  }

  public static void timeMinusEvaluator(Proposition self) {
    { Stella_Object value1 = Logic.valueOf((self.arguments.theArray)[0]);
      Stella_Object value2 = Logic.valueOf((self.arguments.theArray)[1]);
      Stella_Object value3 = Logic.valueOf((self.arguments.theArray)[2]);
      DateTimeLogicWrapper time1 = Timepoint.helpGetTimeObject(value1);
      DateTimeLogicWrapper time2 = Timepoint.helpGetTimeObject(value2);
      DateTimeLogicWrapper time3 = Timepoint.helpGetTimeObject(value3);

      if ((time1 != null) &&
          ((time2 != null) &&
           (time3 != null))) {
        try {
          if (!(((DateTimeObject)(time3.wrapperValue)).objectEqlP(DateTimeObject.timeSubtract(((DateTimeObject)(time1.wrapperValue)), ((DateTimeObject)(time2.wrapperValue)))))) {
            Proposition.signalTruthValueClash(self);
          }
        } catch (StellaException e000) {
          Proposition.signalTruthValueClash(self);
        }
      }
    }
  }

  public static void timeAddEvaluator(Proposition self) {
    { Stella_Object value1 = Logic.valueOf((self.arguments.theArray)[0]);
      Stella_Object value2 = Logic.valueOf((self.arguments.theArray)[1]);
      Stella_Object value3 = Logic.valueOf((self.arguments.theArray)[2]);
      DateTimeLogicWrapper time1 = Timepoint.helpGetTimeObject(value1);
      DateTimeLogicWrapper time2 = Timepoint.helpGetTimeObject(value2);
      DateTimeLogicWrapper time3 = Timepoint.helpGetTimeObject(value3);

      if ((time1 != null) &&
          ((time2 != null) &&
           (time3 != null))) {
        try {
          if (!(((DateTimeObject)(time3.wrapperValue)).objectEqlP(DateTimeObject.timeAdd(((DateTimeObject)(time1.wrapperValue)), ((DateTimeObject)(time2.wrapperValue)))))) {
            Proposition.signalTruthValueClash(self);
          }
        } catch (StellaException e000) {
          Proposition.signalTruthValueClash(self);
        }
      }
    }
  }

  public static Stella_Object timeMinusConstraint(IntegerWrapper missingArgument, DateTimeLogicWrapper x1, DateTimeLogicWrapper x2, DateTimeLogicWrapper x3) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          value = (DateTimeObject.timeSubtract(((DateTimeObject)(x1.wrapperValue)), ((DateTimeObject)(x2.wrapperValue))).objectEqlP(((DateTimeObject)(x3.wrapperValue))) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
        break;
        case 0: 
          value = Timepoint.wrapDateTime(DateTimeObject.timeAdd(((DateTimeObject)(x2.wrapperValue)), ((DateTimeObject)(x3.wrapperValue))));
        break;
        case 1: 
          value = Timepoint.wrapDateTime(DateTimeObject.timeSubtract(((DateTimeObject)(x1.wrapperValue)), ((DateTimeObject)(x3.wrapperValue))));
        break;
        case 2: 
          value = Timepoint.wrapDateTime(DateTimeObject.timeSubtract(((DateTimeObject)(x1.wrapperValue)), ((DateTimeObject)(x2.wrapperValue))));
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static Stella_Object timeAddConstraint(IntegerWrapper missingArgument, DateTimeLogicWrapper x1, DateTimeLogicWrapper x2, DateTimeLogicWrapper x3) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          value = (DateTimeObject.timeAdd(((DateTimeObject)(x1.wrapperValue)), ((DateTimeObject)(x2.wrapperValue))).objectEqlP(((DateTimeObject)(x3.wrapperValue))) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
        break;
        case 0: 
          value = Timepoint.wrapDateTime(DateTimeObject.timeSubtract(((DateTimeObject)(x3.wrapperValue)), ((DateTimeObject)(x2.wrapperValue))));
        break;
        case 1: 
          value = Timepoint.wrapDateTime(DateTimeObject.timeSubtract(((DateTimeObject)(x3.wrapperValue)), ((DateTimeObject)(x1.wrapperValue))));
        break;
        case 2: 
          value = Timepoint.wrapDateTime(DateTimeObject.timeAdd(((DateTimeObject)(x1.wrapperValue)), ((DateTimeObject)(x2.wrapperValue))));
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static double helpGetTimeZone(Stella_Object timeZoneSpecifier) {
    if (timeZoneSpecifier == null) {
      return (Stella.NULL_FLOAT);
    }
    { Surrogate testValue000 = Stella_Object.safePrimaryType(timeZoneSpecifier);

      if (Surrogate.subtypeOfStringP(testValue000)) {
        { StringWrapper timeZoneSpecifier000 = ((StringWrapper)(timeZoneSpecifier));

          { FloatWrapper zone = ((FloatWrapper)(((StringHashTable)(Stella.$ZONE_STRINGS$.get())).lookup(Native.stringDowncase(timeZoneSpecifier000.wrapperValue))));

            if (zone == null) {
              return (Stella.NULL_FLOAT);
            }
            else {
              return (((FloatWrapper)(zone)).wrapperValue);
            }
          }
        }
      }
      else if (Surrogate.subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper timeZoneSpecifier000 = ((IntegerWrapper)(timeZoneSpecifier));

          return (((double)(timeZoneSpecifier000.wrapperValue)));
        }
      }
      else if (Surrogate.subtypeOfFloatP(testValue000)) {
        { FloatWrapper timeZoneSpecifier000 = ((FloatWrapper)(timeZoneSpecifier));

          return (timeZoneSpecifier000.wrapperValue);
        }
      }
      else {
        return (Stella.NULL_FLOAT);
      }
    }
  }

  public static LogicObject dowKeywordToInstance(Keyword dow) {
    if (dow == Timepoint.KWD_MONDAY) {
      return (((LogicObject)(Timepoint.SGT_TIMEPOINT_KB_MONDAY.surrogateValue)));
    }
    else if (dow == Timepoint.KWD_TUESDAY) {
      return (((LogicObject)(Timepoint.SGT_TIMEPOINT_KB_TUESDAY.surrogateValue)));
    }
    else if (dow == Timepoint.KWD_WEDNESDAY) {
      return (((LogicObject)(Timepoint.SGT_TIMEPOINT_KB_WEDNESDAY.surrogateValue)));
    }
    else if (dow == Timepoint.KWD_THURSDAY) {
      return (((LogicObject)(Timepoint.SGT_TIMEPOINT_KB_THURSDAY.surrogateValue)));
    }
    else if (dow == Timepoint.KWD_FRIDAY) {
      return (((LogicObject)(Timepoint.SGT_TIMEPOINT_KB_FRIDAY.surrogateValue)));
    }
    else if (dow == Timepoint.KWD_SATURDAY) {
      return (((LogicObject)(Timepoint.SGT_TIMEPOINT_KB_SATURDAY.surrogateValue)));
    }
    else if (dow == Timepoint.KWD_SUNDAY) {
      return (((LogicObject)(Timepoint.SGT_TIMEPOINT_KB_SUNDAY.surrogateValue)));
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + dow + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public static Keyword timepointAccessorSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      GeneralizedSymbol predicate = proposition.operator;
      Stella_Object timepointValue = Logic.valueOf((proposition.arguments.theArray)[0]);
      Stella_Object timeZoneValue = Logic.valueOf((proposition.arguments.theArray)[1]);
      Stella_Object result = Logic.valueOf((proposition.arguments.theArray)[2]);
      DateTimeLogicWrapper timepoint = Timepoint.helpGetTimeObject(timepointValue);
      double timeZone = Timepoint.helpGetTimeZone(timeZoneValue);

      lastmove = lastmove;
      try {
        if ((timepoint == null) ||
            (timeZone == Stella.NULL_FLOAT)) {
          return (edu.isi.powerloom.extensions.units.Units.KWD_FAILURE);
        }
        else if (result != null) {
          { Stella_Object theValue = DateTimeLogicWrapper.helpExtractDateTimeComponent(timepoint, timeZone, predicate);

            { Surrogate testValue000 = Stella_Object.safePrimaryType(result);

              if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_PATTERN_VARIABLE)) {
                { PatternVariable result000 = ((PatternVariable)(result));

                  return (Logic.selectProofResult(PatternVariable.bindVariableToValueP(result000, theValue, true), false, true));
                }
              }
              else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_LOGIC_SKOLEM)) {
                { Skolem result000 = ((Skolem)(result));

                  { Skolem object000 = result000;
                    Stella_Object value000 = theValue;
                    Stella_Object oldValue000 = object000.variableValue;
                    Stella_Object newValue000 = Stella_Object.updateInContext(oldValue000, value000, object000.homeContext, false);

                    if (!((oldValue000 != null) &&
                        (oldValue000.primaryType() == edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CS_VALUE))) {
                      object000.variableValue = newValue000;
                    }
                  }
                  return (edu.isi.powerloom.extensions.units.Units.KWD_FINAL_SUCCESS);
                }
              }
              else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_STELLA_NUMBER_WRAPPER)) {
                { NumberWrapper result000 = ((NumberWrapper)(result));

                  return (Logic.selectProofResult(theValue.objectEqlP(result000), false, true));
                }
              }
              else if (Surrogate.subtypeOfStringP(testValue000)) {
                { StringWrapper result000 = ((StringWrapper)(result));

                  if (Stella_Object.isaP(theValue, Timepoint.SGT_STELLA_STRING_WRAPPER)) {
                    return (Logic.selectProofResult(Stella.stringEqualP(((StringWrapper)(theValue)).wrapperValue, result000.wrapperValue), false, true));
                  }
                  else {
                    return (edu.isi.powerloom.extensions.units.Units.KWD_FAILURE);
                  }
                }
              }
              else {
                { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                  stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
                  throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
                }
              }
            }
          }
        }
        else {
          return (edu.isi.powerloom.extensions.units.Units.KWD_FAILURE);
        }
      } catch (StellaException e000) {
        ControlFrame.setFrameTruthValue(frame, Logic.UNKNOWN_TRUTH_VALUE);
        return (edu.isi.powerloom.extensions.units.Units.KWD_TERMINAL_FAILURE);
      }
    }
  }

}
