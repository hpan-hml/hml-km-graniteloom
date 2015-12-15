//  -*- Mode: C++ -*-

// timepoint-kb.cc

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

void startupTimepointKb() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/TIMEPOINT-SUPPORT", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_DAY_OF_WEEK = ((Symbol*)(internRigidSymbolWrtModule("DAY-OF-WEEK", getStellaModule("/TIMEPOINT-KB", true), 0)));
      KWD_TIMEPOINT_KB_AXIOMS = ((Keyword*)(internRigidSymbolWrtModule("AXIOMS", NULL, 2)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_OF = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-OF", getStellaModule("/TIMEPOINT-KB", true), 0)));
      KWD_TIMEPOINT_KB__g = ((Keyword*)(internRigidSymbolWrtModule("->", NULL, 2)));
      SYM_TIMEPOINT_KB_TIMEPOINT_SUPPORT_pTP = ((Symbol*)(internRigidSymbolWrtModule("?TP", NULL, 0)));
      KWD_TIMEPOINT_KB_DOCUMENTATION = ((Keyword*)(internRigidSymbolWrtModule("DOCUMENTATION", NULL, 2)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_DURATION_OF = ((Symbol*)(internRigidSymbolWrtModule("DURATION-OF", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIME_ = ((Symbol*)(internRigidSymbolWrtModule("TIME-", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEi = ((Symbol*)(internRigidSymbolWrtModule("TIME+", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_YEAR = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-YEAR", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_MONTH = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-MONTH", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DAY = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-DAY", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-DAY-OF-WEEK", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_HOUR = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-HOUR", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_MINUTE = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-MINUTE", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_SECOND = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-SECOND", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DATE = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-DATE", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_TIME = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-TIME", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_OFo = ((Symbol*)(internRigidSymbolWrtModule("TIMEPOINT-OF*", getStellaModule("/TIMEPOINT-KB", true), 0)));
      SYM_TIMEPOINT_KB_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_KB = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-TIMEPOINT-KB", NULL, 0)));
      SYM_TIMEPOINT_KB_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("STARTUP-TIMEPOINT-KB", "(DEFUN STARTUP-TIMEPOINT-KB () :PUBLIC? TRUE)", ((cpp_function_code)(&startupTimepointKb)), NULL);
      { MethodSlot* function = lookupFunction(SYM_TIMEPOINT_KB_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_KB);

        setDynamicSlotValue(function->dynamicSlots, SYM_TIMEPOINT_KB_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupTimepointKb"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("PL-KERNEL-KB", true));
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
        defconcept(consList(1, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT)))));
        defconcept(consList(4, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_DAY_OF_WEEK))), ((Cons*)(copyConsTree(NIL))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/SUNDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/SATURDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/FRIDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/THURSDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/WEDNESDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/TUESDAY) (/TIMEPOINT-KB/DAY-OF-WEEK /TIMEPOINT-KB/MONDAY) (CLOSED /TIMEPOINT-KB/DAY-OF-WEEK)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(8, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_OF))), ((Cons*)(copyConsTree(getQuotedTree("(((?X STRING)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB__g, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_SUPPORT_pTP))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("Connects a STRING representation of a timePoint to the actual\ninternal representation.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-OF) (RELATION-EVALUATOR /TIMEPOINT-KB/TIMEPOINT-OF TIMEPOINT-OF-EVALUATOR) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-OF TIMEPOINT-OF-SPECIALIST) (GOES-TRUE-DEMON /TIMEPOINT-KB/TIMEPOINT-OF TIMEPOINT-OF-EVALUATOR)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(8, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_DURATION_OF))), ((Cons*)(copyConsTree(getQuotedTree("(((?X STRING)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB__g, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_SUPPORT_pTP))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("Connects a STRING representation of a time duration to the actual\ninternal representation.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/DURATION-OF) (RELATION-EVALUATOR /TIMEPOINT-KB/DURATION-OF DURATION-OF-EVALUATOR) (RELATION-SPECIALIST /TIMEPOINT-KB/DURATION-OF DURATION-OF-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIME_))), ((Cons*)(copyConsTree(getQuotedTree("((?T1 ?T2 ?T3) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("Subtract ?t2 from ?t1.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIME-) (RELATION-EVALUATOR /TIMEPOINT-KB/TIME- TIME-MINUS-EVALUATOR) (RELATION-CONSTRAINT /TIMEPOINT-KB/TIME- TIME-MINUS-CONSTRAINT) (RELATION-SPECIALIST /TIMEPOINT-KB/TIME- CONSTRAINT-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEi))), ((Cons*)(copyConsTree(getQuotedTree("((?T1 ?T2 ?T3) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("Add ?t2 to ?t1.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIME+) (RELATION-EVALUATOR /TIMEPOINT-KB/TIME+ TIME-ADD-EVALUATOR) (RELATION-CONSTRAINT /TIMEPOINT-KB/TIME+ TIME-ADD-CONSTRAINT) (RELATION-SPECIALIST /TIMEPOINT-KB/TIME+ CONSTRAINT-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_YEAR))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE ?YEAR) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The year component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-YEAR) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-YEAR TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_MONTH))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE (?MONTH INTEGER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The month component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-MONTH) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-MONTH TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DAY))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE (?DAY INTEGER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The day component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-DAY) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-DAY TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE (?DOW /TIMEPOINT-KB/DAY-OF-WEEK)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The day-of-week component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-DAY-OF-WEEK) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-DAY-OF-WEEK TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_HOUR))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE (?HOUR INTEGER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The hour component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-HOUR) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-HOUR TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_MINUTE))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE (?MINUTE INTEGER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The minute component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-MINUTE) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-MINUTE TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_SECOND))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE (?SECOND NUMBER)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The second component of ?tp evaluated in time zone ?zone.\n\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-SECOND) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-SECOND TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DATE))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE (?DATE STRING)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The date component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-DATE) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-DATE TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_TIME))), ((Cons*)(copyConsTree(getQuotedTree("((?TP ?ZONE (?TIME STRING)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("The time component of ?tp evaluated in time zone ?zone.\nVariable ?zone is represented as a floating point offset from UTC in hours.\nAs an input value common strings are also recognized.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-TIME) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-TIME TIMEPOINT-ACCESSOR-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        deffunction(consList(6, ((Symbol*)(copyConsTree(SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_OFo))), ((Cons*)(copyConsTree(getQuotedTree("(((?YEAR INTEGER) (?MONTH INTEGER) (?DAY INTEGER) (?HOUR INTEGER) (?MINUTE INTEGER) (?SECOND NUMBER) ?ZONE ?TIMEPOINT) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))), KWD_TIMEPOINT_KB_DOCUMENTATION, ((StringWrapper*)(copyConsTree(wrapString("Maps time components into a timepoint or vice-versa.\nVariables ?year, ?month, ?day, ?hour and ?minute are integers.\nVariable ?second is a number, either integer or float.  Resolution is 0.001\nVariable ?zone is the time zone.  It is represented as a floating point offset\nfrom UTC in hours.  As an input value common strings are also recognized.\nVariable ?timepoint is the internal timepoint representation.")))), KWD_TIMEPOINT_KB_AXIOMS, ((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED /TIMEPOINT-KB/TIMEPOINT-OF*) (RELATION-EVALUATOR /TIMEPOINT-KB/TIMEPOINT-OF* TIMEPOINT-OF*-EVALUATOR) (RELATION-SPECIALIST /TIMEPOINT-KB/TIMEPOINT-OF* TIMEPOINT-OF*-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT"))))));
        asserT(((Cons*)(copyConsTree(getQuotedTree("((AND (COMPUTED-PROCEDURE TIMEPOINT-OF-EVALUATOR) (COMPUTED-PROCEDURE TIMEPOINT-OF*-EVALUATOR) (COMPUTED-PROCEDURE DURATION-OF-EVALUATOR) (COMPUTED-PROCEDURE TIME-GREATER-EVALUATOR) (COMPUTED-PROCEDURE TIME-LESS-EVALUATOR) (COMPUTED-PROCEDURE TIME-PLUS-EVALUATOR) (COMPUTED-PROCEDURE TIME-MINUS-EVALUATOR) (COMPUTED-PROCEDURE TIMEPOINT-OF-SPECIALIST) (COMPUTED-PROCEDURE TIMEPOINT-OF*-SPECIALIST) (COMPUTED-PROCEDURE DURATION-OF-SPECIALIST) (COMPUTED-PROCEDURE TIME-GREATER-SPECIALIST) (COMPUTED-PROCEDURE TIME-LESS-SPECIALIST) (COMPUTED-PROCEDURE TIME-PLUS-SPECIALIST) (COMPUTED-PROCEDURE TIME-MINUS-SPECIALIST)) \"/TIMEPOINT-SUPPORT\")", "/TIMEPOINT-SUPPORT")))));
        processDefinitions();
      }
    }
  }
}

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_DAY_OF_WEEK = NULL;

Keyword* KWD_TIMEPOINT_KB_AXIOMS = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_OF = NULL;

Keyword* KWD_TIMEPOINT_KB__g = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_SUPPORT_pTP = NULL;

Keyword* KWD_TIMEPOINT_KB_DOCUMENTATION = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_DURATION_OF = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIME_ = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEi = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_YEAR = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_MONTH = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DAY = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DAY_OF_WEEK = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_HOUR = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_MINUTE = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_SECOND = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_DATE = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_TIME = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_KB_TIMEPOINT_OFo = NULL;

Symbol* SYM_TIMEPOINT_KB_TIMEPOINT_SUPPORT_STARTUP_TIMEPOINT_KB = NULL;

Symbol* SYM_TIMEPOINT_KB_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace timepoint
