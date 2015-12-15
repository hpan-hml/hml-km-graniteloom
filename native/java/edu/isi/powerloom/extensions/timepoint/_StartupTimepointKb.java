//  -*- Mode: Java -*-
//
// _StartupTimepointKb.java

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

public class _StartupTimepointKb {
  public static void startupTimepointKb() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/TIMEPOINT-SUPPORT", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_DAY_OF_WEEK = ((Symbol)(Stella.internRigidSymbolWrtModule("DAY-OF-WEEK", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_OF = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-OF", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_SUPPORT_pTP = ((Symbol)(Stella.internRigidSymbolWrtModule("?TP", null, 0)));
          Timepoint.SYM_TIMEPOINT_KB_DURATION_OF = ((Symbol)(Stella.internRigidSymbolWrtModule("DURATION-OF", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIME_ = ((Symbol)(Stella.internRigidSymbolWrtModule("TIME-", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEi = ((Symbol)(Stella.internRigidSymbolWrtModule("TIME+", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_YEAR = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-YEAR", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_MONTH = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-MONTH", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_DAY = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-DAY", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-DAY-OF-WEEK", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_HOUR = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-HOUR", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_MINUTE = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-MINUTE", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_SECOND = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-SECOND", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_DATE = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-DATE", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_TIME = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-TIME", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_OF$ = ((Symbol)(Stella.internRigidSymbolWrtModule("TIMEPOINT-OF*", Stella.getStellaModule("/TIMEPOINT-KB", true), 0)));
          Timepoint.SYM_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_KB = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-TIMEPOINT-KB", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("STARTUP-TIMEPOINT-KB", "(DEFUN STARTUP-TIMEPOINT-KB () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.extensions.timepoint._StartupTimepointKb", "startupTimepointKb", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Timepoint.SYM_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_KB);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, edu.isi.powerloom.extensions.Extensions.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupTimepointKb"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          { Object old$Module$001 = Stella.$MODULE$.get();
            Object old$Context$001 = Stella.$CONTEXT$.get();

            try {
              Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("PL-KERNEL-KB", true));
              Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
              Logic.defconcept(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT))), Stella.NIL));
              Logic.defconcept(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_DAY_OF_WEEK))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.NIL))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/SUNDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/SATURDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/FRIDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/THURSDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/WEDNESDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/TUESDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/MONDAY) (CLOSED /TIMEPOINT-KB/DAY-OF-WEEK)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_OF))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("(((?X STRING)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD__g, Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_SUPPORT_pTP))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Connects a STRING representation of a timePoint to the actual\ninternal representation.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-OF) (RELATION-EVALUATOR /TIMEPOINT-KB/TIMEPOINT-OF TIMEPOINT-OF-EVALUATOR) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-OF TIMEPOINT-OF-SPECIALIST) (GOES-TRUE-DEMON /TIMEPOINT-KB/TIMEPOINT-OF TIMEPOINT-OF-EVALUATOR)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_DURATION_OF))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("(((?X STRING)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD__g, Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_SUPPORT_pTP))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Connects a STRING representation of a time duration to the actual\ninternal representation.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/DURATION-OF) (RELATION-EVALUATOR /TIMEPOINT-KB/DURATION-OF DURATION-OF-EVALUATOR) (RELATION-SPECIALIST /TIMEPOINT-KB/DURATION-OF DURATION-OF-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIME_))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?T1 ?T2 ?T3) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Subtract ?t2 from ?t1.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIME-) (RELATION-EVALUATOR /TIMEPOINT-KB/TIME- TIME-MINUS-EVALUATOR) (RELATION-CONSTRAINT /TIMEPOINT-KB/TIME- TIME-MINUS-CONSTRAINT) (RELATION-SPECIALIST /TIMEPOINT-KB/TIME- CONSTRAINT-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEi))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?T1 ?T2 ?T3) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Add ?t2 to ?t1.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIME+) (RELATION-EVALUATOR /TIMEPOINT-KB/TIME+ TIME-ADD-EVALUATOR) (RELATION-CONSTRAINT /TIMEPOINT-KB/TIME+ TIME-ADD-CONSTRAINT) (RELATION-SPECIALIST /TIMEPOINT-KB/TIME+ CONSTRAINT-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_YEAR))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE ?YEAR) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The year component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-YEAR) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-YEAR TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_MONTH))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE (?MONTH INTEGER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The month component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-MONTH) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-MONTH TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_DAY))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE (?DAY INTEGER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The day component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-DAY) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-DAY TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE (?DOW /TIMEPOINT-KB/DAY-OF-WEEK)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The day-of-week component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-DAY-OF-WEEK) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-DAY-OF-WEEK TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_HOUR))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE (?HOUR INTEGER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The hour component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-HOUR) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-HOUR TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_MINUTE))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE (?MINUTE INTEGER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The minute component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-MINUTE) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-MINUTE TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_SECOND))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE (?SECOND NUMBER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The second component of ?tp evaluated in time zone ?zone.\n\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-SECOND) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-SECOND TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_DATE))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE (?DATE STRING)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The date component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-DATE) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-DATE TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_TIME))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?TP ?ZONE (?TIME STRING)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("The time component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-TIME) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-TIME TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Timepoint.SYM_TIMEPOINT_KB_TIMEPOINT_OF$))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("(((?YEAR INTEGER) (?MONTH INTEGER) (?DAY INTEGER) (?HOUR INTEGER) (?MINUTE INTEGER) (?SECOND NUMBER) ?ZONE ?TIMEPOINT) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Maps time components into a timepoint or vice-versa.\nVariables ?year, ?month, ?day, ?hour and ?minute are integers.\nVariable ?second is a number, either integer or float.  Resolution is 0.001\nVariable ?zone is the time zone.  It is represented as a floating point offset\nfrom UTC in hours.  As an input value common strings are also recognized.\nVariable ?timepoint is the internal timepoint representation.")))), Stella_Object.cons(edu.isi.powerloom.extensions.units.Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-OF*) (RELATION-EVALUATOR /TIMEPOINT-KB/TIMEPOINT-OF* TIMEPOINT-OF*-EVALUATOR) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-OF* TIMEPOINT-OF*-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), Stella.NIL)))))));
              Logic.renamed_Assert(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED-PROCEDURE TIMEPOINT-OF-EVALUATOR) (COMPUTED-PROCEDURE TIMEPOINT-OF*-EVALUATOR) (COMPUTED-PROCEDURE DURATION-OF-EVALUATOR) (COMPUTED-PROCEDURE TIME-GREATER-EVALUATOR) (COMPUTED-PROCEDURE TIME-LESS-EVALUATOR) (COMPUTED-PROCEDURE TIME-PLUS-EVALUATOR) (COMPUTED-PROCEDURE TIME-MINUS-EVALUATOR) (COMPUTED-PROCEDURE TIMEPOINT-OF-SPECIALIST) (COMPUTED-PROCEDURE TIMEPOINT-OF*-SPECIALIST) (COMPUTED-PROCEDURE DURATION-OF-SPECIALIST) (COMPUTED-PROCEDURE TIME-GREATER-SPECIALIST) (COMPUTED-PROCEDURE TIME-LESS-SPECIALIST) (COMPUTED-PROCEDURE TIME-PLUS-SPECIALIST) (COMPUTED-PROCEDURE TIME-MINUS-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))));
              Logic.processDefinitions();

            } finally {
              Stella.$CONTEXT$.set(old$Context$001);
              Stella.$MODULE$.set(old$Module$001);
            }
          }
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
