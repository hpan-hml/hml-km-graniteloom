//  -*- Mode: Java -*-
//
// DateTimeLogicWrapper.java

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

public class DateTimeLogicWrapper extends QuantityLogicWrapper {
  public static DateTimeLogicWrapper newDateTimeLogicWrapper(DateTimeObject wrapperValue) {
    { DateTimeLogicWrapper self = null;

      self = new DateTimeLogicWrapper();
      self.wrapperValue = wrapperValue;
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = null;
      self.functionTerm = null;
      return (self);
    }
  }

  public static Stella_Object helpExtractDateTimeComponent(DateTimeLogicWrapper timepoint, double timeZone, GeneralizedSymbol predicate) {
    { CalendarDate date = ((CalendarDate)(((DateTimeObject)(timepoint.wrapperValue))));

      if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_YEAR) {
        { int year = Stella.NULL_INTEGER;
          int month = Stella.NULL_INTEGER;
          int day = Stella.NULL_INTEGER;
          Keyword dow = null;

          { Object [] caller_MV_returnarray = new Object[3];

            year = date.getCalendarDate(timeZone, caller_MV_returnarray);
            month = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
            day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
            dow = ((Keyword)(caller_MV_returnarray[2]));
          }
          {
            month = month;
            day = day;
            dow = dow;
          }
          return (IntegerWrapper.wrapInteger(year));
        }
      }
      else if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_MONTH) {
        { int year = Stella.NULL_INTEGER;
          int month = Stella.NULL_INTEGER;
          int day = Stella.NULL_INTEGER;
          Keyword dow = null;

          { Object [] caller_MV_returnarray = new Object[3];

            year = date.getCalendarDate(timeZone, caller_MV_returnarray);
            month = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
            day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
            dow = ((Keyword)(caller_MV_returnarray[2]));
          }
          {
            year = year;
            day = day;
            dow = dow;
          }
          return (IntegerWrapper.wrapInteger(month));
        }
      }
      else if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_DAY) {
        { int year = Stella.NULL_INTEGER;
          int month = Stella.NULL_INTEGER;
          int day = Stella.NULL_INTEGER;
          Keyword dow = null;

          { Object [] caller_MV_returnarray = new Object[3];

            year = date.getCalendarDate(timeZone, caller_MV_returnarray);
            month = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
            day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
            dow = ((Keyword)(caller_MV_returnarray[2]));
          }
          {
            year = year;
            month = month;
            dow = dow;
          }
          return (IntegerWrapper.wrapInteger(day));
        }
      }
      else if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK) {
        { int year = Stella.NULL_INTEGER;
          int month = Stella.NULL_INTEGER;
          int day = Stella.NULL_INTEGER;
          Keyword dow = null;

          { Object [] caller_MV_returnarray = new Object[3];

            year = date.getCalendarDate(timeZone, caller_MV_returnarray);
            month = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
            day = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
            dow = ((Keyword)(caller_MV_returnarray[2]));
          }
          {
            year = year;
            month = month;
            day = day;
          }
          return (Timepoint.dowKeywordToInstance(dow));
        }
      }
      else if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_HOUR) {
        { int hour = Stella.NULL_INTEGER;
          int minute = Stella.NULL_INTEGER;
          int second = Stella.NULL_INTEGER;
          int millisecond = Stella.NULL_INTEGER;

          { Object [] caller_MV_returnarray = new Object[3];

            hour = date.getTime(timeZone, caller_MV_returnarray);
            minute = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
            second = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
            millisecond = ((int)(((IntegerWrapper)(caller_MV_returnarray[2])).wrapperValue));
          }
          {
            minute = minute;
            second = second;
            millisecond = millisecond;
          }
          return (IntegerWrapper.wrapInteger(hour));
        }
      }
      else if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_MINUTE) {
        { int hour = Stella.NULL_INTEGER;
          int minute = Stella.NULL_INTEGER;
          int second = Stella.NULL_INTEGER;
          int millisecond = Stella.NULL_INTEGER;

          { Object [] caller_MV_returnarray = new Object[3];

            hour = date.getTime(timeZone, caller_MV_returnarray);
            minute = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
            second = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
            millisecond = ((int)(((IntegerWrapper)(caller_MV_returnarray[2])).wrapperValue));
          }
          {
            hour = hour;
            second = second;
            millisecond = millisecond;
          }
          return (IntegerWrapper.wrapInteger(minute));
        }
      }
      else if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_SECOND) {
        { int hour = Stella.NULL_INTEGER;
          int minute = Stella.NULL_INTEGER;
          int second = Stella.NULL_INTEGER;
          int millisecond = Stella.NULL_INTEGER;

          { Object [] caller_MV_returnarray = new Object[3];

            hour = date.getTime(timeZone, caller_MV_returnarray);
            minute = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
            second = ((int)(((IntegerWrapper)(caller_MV_returnarray[1])).wrapperValue));
            millisecond = ((int)(((IntegerWrapper)(caller_MV_returnarray[2])).wrapperValue));
          }
          {
            hour = hour;
            minute = minute;
          }
          if (millisecond == 0) {
            return (IntegerWrapper.wrapInteger(second));
          }
          else {
            return (FloatWrapper.wrapFloat(((double)(second)) + (millisecond * 0.001)));
          }
        }
      }
      else if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_DATE) {
        return (StringWrapper.wrapString(date.calendarDateToDateString(timeZone, false)));
      }
      else if (predicate == Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_TIME) {
        return (StringWrapper.wrapString(date.calendarDateToTimeString(timeZone, true, true, true)));
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + predicate + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public boolean objectEqlP(Stella_Object x) {
    { DateTimeLogicWrapper self = this;

      try {
        return (Stella_Object.isaP(x, edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER) &&
            ((DateTimeObject)(self.wrapperValue)).objectEqlP(((DateTimeObject)(((DateTimeLogicWrapper)(x)).wrapperValue))));
      } catch (StellaException e000) {
        return (false);
      }
    }
  }

  public int hashCode_() {
    { DateTimeLogicWrapper self = this;

      if (((DateTimeObject)(self.wrapperValue)) != null) {
        return (((DateTimeObject)(self.wrapperValue)).hashCode_());
      }
      else {
        return (0);
      }
    }
  }

  public Stella_Object generateSpecializedTerm() {
    { DateTimeLogicWrapper self = this;

      { Cons term = self.functionTerm;
        DateTimeObject datetime = ((DateTimeObject)(self.wrapperValue));

        if (term != null) {
          return (term);
        }
        else if (datetime != null) {
          { Surrogate testValue000 = Stella_Object.safePrimaryType(datetime);

            if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_STELLA_CALENDAR_DATE)) {
              { CalendarDate datetime000 = ((CalendarDate)(datetime));

                term = Stella_Object.cons(Logic.generateTerm(Timepoint.SGT_TIMEPOINT_KB_TIMEPOINT_OF), Stella_Object.cons(StringWrapper.wrapString(datetime000.calendarDateToString(0.0, false, true)), Stella.NIL));
              }
            }
            else if (Surrogate.subtypeOfP(testValue000, edu.isi.powerloom.extensions.units.Units.SGT_STELLA_TIME_DURATION)) {
              { TimeDuration datetime000 = ((TimeDuration)(datetime));

                term = Stella_Object.cons(Logic.generateTerm(Timepoint.SGT_TIMEPOINT_KB_DURATION_OF), Stella_Object.cons(StringWrapper.wrapString(datetime000.timeDurationToString()), Stella.NIL));
              }
            }
            else {
              { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
              }
            }
          }
          self.functionTerm = term;
          return (term);
        }
        else {
          throw ((TermGenerationException)(TermGenerationException.newTermGenerationException(self, "Date Time Number Wrapper doesn't have a value.").fillInStackTrace()));
        }
      }
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { DateTimeLogicWrapper self = this;

      if (((Boolean)(Stella.$PRINTREADABLYp$.get())).booleanValue()) {
        stream.print(((DateTimeObject)(self.wrapperValue)));
      }
      else {
        stream.print("|tw|" + ((DateTimeObject)(self.wrapperValue)));
      }
    }
  }

  public static Stella_Object accessDateTimeLogicWrapperSlotValue(DateTimeLogicWrapper self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == edu.isi.powerloom.extensions.units.Units.SYM_STELLA_WRAPPER_VALUE) {
      if (setvalueP) {
        self.wrapperValue = ((DateTimeObject)(value));
      }
      else {
        value = ((DateTimeObject)(self.wrapperValue));
      }
    }
    else {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, slotname, value, null);
      }
      else {
        value = self.dynamicSlots.lookup(slotname);
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { DateTimeLogicWrapper self = this;

      return (edu.isi.powerloom.extensions.units.Units.SGT_TIMEPOINT_SUPPORT_DATE_TIME_LOGIC_WRAPPER);
    }
  }

}

