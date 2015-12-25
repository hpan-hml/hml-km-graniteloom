//  -*- Mode: C++ -*-

// startup.cc

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
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 1996-2014      |
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
+---------------------------- END LICENSE BLOCK -----------------------------+
*/

#include "stella/stella-system.hh"

namespace stella {

int oSTELLA_MAJOR_VERSION_NUMBERo = 3;

int oSTELLA_MINOR_VERSION_NUMBERo = 5;

char* oSTELLA_RELEASE_STATEo = "";

int oSTELLA_PATCH_LEVELo = 29;

char* oSTELLA_VERSION_STRINGo = NULL;

char* stellaVersionString() {
  // Return a string identifying the current version of STELLA.
  return (stringConcatenate("STELLA ", integerToString(((long long int)(oSTELLA_MAJOR_VERSION_NUMBERo))), 5, ".", integerToString(((long long int)(oSTELLA_MINOR_VERSION_NUMBERo))), ".", integerToString(((long long int)(oSTELLA_PATCH_LEVELo))), oSTELLA_RELEASE_STATEo));
}

char* stellaInformation() {
  // Returns information about the current Stella implementation.
  // Useful when reporting problems.
  return (stringConcatenate(oSTELLA_VERSION_STRINGo, " [", 3, runningInLanguage()->symbolName, "]", runningSystemInformation()));
}

StringWrapper* stellaInformationEvaluatorWrapper(Cons* arguments) {
  arguments = arguments;
  { char* result = stellaInformation();

    if (result != NULL) {
      return (wrapString(result));
    }
    else {
      return (NULL);
    }
  }
}

// List of phases that can be legally used as an optional
// phase argument to a `startup-time-progn' form.  The corresponding code
// will be executed during the execution of a startup-time-code function only
// if the position of the keyword in the list corresponds to the current value of
// `*STARTUP-TIME-PHASE*', or if phasing of startup-time code is disabled.
List* oSTARTUP_TIME_PHASESo = NULL;

// The current phase during 'phased startup'.
// The value has to correspond to the position of one of the keywords
// in `*STARTUP-TIME-PHASES*'.  999 means no phasing at all.
int oSTARTUP_TIME_PHASEo = 999;

boolean currentStartupTimePhaseP(int phase) {
  return ((oSTARTUP_TIME_PHASEo == 999) ||
      (phase == oSTARTUP_TIME_PHASEo));
}

int encodeStartupTimePhase(Keyword* phase) {
  { int startuptimephaseasnumber = 0;

    if (!(oSTARTUP_TIME_PHASESo->memberP(phase))) {
      phase = KWD_STARTUP_FINAL;
    }
    { Keyword* ph = NULL;
      Cons* iter000 = oSTARTUP_TIME_PHASESo->theConsList;

      for (ph, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        ph = ((Keyword*)(iter000->value));
        if (ph == phase) {
          return (startuptimephaseasnumber);
        }
        else {
          startuptimephaseasnumber = startuptimephaseasnumber + 1;
        }
      }
    }
    throw *newStellaException("`encode-startup-time-phase' should never get this far!");
  }
}

void startupKernel(boolean verboseP) {
  { int phase = NULL_INTEGER;
    int iter000 = 0;
    int upperBound000 = 9;

    for  (phase, iter000, upperBound000; 
          iter000 <= upperBound000; 
          iter000 = iter000 + 1) {
      phase = iter000;
      oSTARTUP_TIME_PHASEo = phase;
      if (verboseP) {
        if (phase == 0) {
        }
        else if (phase == 2) {
          std::cout << "Running kernel startup code..." << std::endl;
          std::cout << "Initializing symbol tables..." << std::endl;
        }
        else if (phase == 3) {
          std::cout << "Initializing quoted constants..." << std::endl;
        }
        else if (phase == 4) {
          std::cout << "Initializing global variables..." << std::endl;
        }
        else if (phase == 5) {
          std::cout << "Creating class objects..." << std::endl;
        }
        else if (phase == 6) {
          std::cout << "Finalizing classes..." << std::endl;
        }
        else if (phase == 7) {
          std::cout << "Creating method objects..." << std::endl;
        }
        else if (phase == 8) {
          std::cout << "Finalizing methods..." << std::endl;
        }
        else if (phase == 9) {
          std::cout << "Running non-phased startup code..." << std::endl;
        }
      }
      if (phase == 6) {
        finalizeClasses();
        oCLASS_HIERARCHY_BOOTEDpo = true;
        continue;
      }
      if (phase == 8) {
        finalizeSlots();
        cleanupUnfinalizedClasses();
        continue;
      }
      startupStartup();
      startupCppPrimal();
      startupPrimal();
      startupTypePredicates();
      startupConses();
      startupHierarchy();
      startupTaxonomies();
      startupLists();
      startupCollections();
      startupIterators();
      startupLiterals();
      startupSymbols();
      startupClasses();
      startupMethods();
      startupDefclass();
      startupStellaIn();
      startupForeach();
      startupWalk();
      startupDynamicSlots();
      startupDynamicLiteralSlots();
      startupSystems();
      startupClTranslate();
      startupMacros();
      startupMemoize();
      startupStreams();
      startupDescribe();
      startupDemons();
      startupMoreDemons();
      startupNameUtility();
      startupModules();
      startupContexts();
      startupRead();
      startupXml();
      startupDateTime();
      startupDateTimeParser();
    }
  }
}

void startupCppTranslator() {
  startupCppTranslate();
  startupCppClassOut();
  startupCppOutput();
  startupCppTranslateFile();
}

void startupJavaTranslator() {
  startupJavaTranslate();
  startupJavaClassOut();
  startupJavaOutput();
  startupJavaTranslateFile();
}

void startupIdlTranslator() {
  startupIdlTranslate();
  startupIdlClassOut();
  startupIdlOutput();
  startupIdlTranslateFile();
}

void startup(boolean verboseP) {
  startupKernel(verboseP);
  if (verboseP) {
    std::cout << "Starting up translators..." << std::endl;
  }
  { int phase = NULL_INTEGER;
    int iter000 = 0;
    int upperBound000 = 9;

    for  (phase, iter000, upperBound000; 
          iter000 <= upperBound000; 
          iter000 = iter000 + 1) {
      phase = iter000;
      oSTARTUP_TIME_PHASEo = phase;
      startupTranslateFile();
      startupClTranslateFile();
      startupCppTranslator();
      startupJavaTranslator();
      startupIdlTranslator();
      startupTools();
    }
  }
  oSTARTUP_TIME_PHASEo = 999;
  sweepTransients();
}

void interpretCommandLineArguments(int count, char** arguments) {
  // Old name for `process-command-line-arguments' (which see).
  processCommandLineArguments(count, arguments, KWD_STARTUP_WARN);
}

Cons* consifyCommandLineArguments(int count, char** arguments) {
  // Convert `count' command line `arguments' into a CONS list.
  { Cons* result = NIL;

    { int i = NULL_INTEGER;
      int iter000 = 1;
      int upperBound000 = count - 1;
      Cons* collect000 = NULL;

      for  (i, iter000, upperBound000, collect000; 
            iter000 <= upperBound000; 
            iter000 = iter000 + 1) {
        i = iter000;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(wrapString(arguments[i]), NIL);
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
            collect000->rest = cons(wrapString(arguments[i]), NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    return (result);
  }
}

int main(int count, char** arguments) {
  { boolean testingP = count == 1;

    startup(testingP);
    startupStellaSystem();
    std::cout << "Welcome to " << stellaVersionString() << std::endl;
    interpretCommandLineArguments(count, arguments);
    if (testingP) {
      std::cout << "Bye!" << std::endl;
    }
  }
  return (1);
}

void startupStartup() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo);
    if (currentStartupTimePhaseP(2)) {
      KWD_STARTUP_EARLY_INITS = ((Keyword*)(internRigidSymbolWrtModule("EARLY-INITS", NULL, 2)));
      KWD_STARTUP_MODULES = ((Keyword*)(internRigidSymbolWrtModule("MODULES", NULL, 2)));
      KWD_STARTUP_SYMBOLS = ((Keyword*)(internRigidSymbolWrtModule("SYMBOLS", NULL, 2)));
      KWD_STARTUP_QUOTED_CONSTANTS = ((Keyword*)(internRigidSymbolWrtModule("QUOTED-CONSTANTS", NULL, 2)));
      KWD_STARTUP_GLOBALS = ((Keyword*)(internRigidSymbolWrtModule("GLOBALS", NULL, 2)));
      KWD_STARTUP_CLASSES = ((Keyword*)(internRigidSymbolWrtModule("CLASSES", NULL, 2)));
      KWD_STARTUP_FINALIZE_CLASSES = ((Keyword*)(internRigidSymbolWrtModule("FINALIZE-CLASSES", NULL, 2)));
      KWD_STARTUP_METHODS = ((Keyword*)(internRigidSymbolWrtModule("METHODS", NULL, 2)));
      KWD_STARTUP_FINALIZE_METHODS = ((Keyword*)(internRigidSymbolWrtModule("FINALIZE-METHODS", NULL, 2)));
      KWD_STARTUP_FINAL = ((Keyword*)(internRigidSymbolWrtModule("FINAL", NULL, 2)));
      KWD_STARTUP_WARN = ((Keyword*)(internRigidSymbolWrtModule("WARN", NULL, 2)));
      KWD_STARTUP_DOCUMENTATION = ((Keyword*)(internRigidSymbolWrtModule("DOCUMENTATION", NULL, 2)));
      SYM_STARTUP_STELLA_STARTUP_STARTUP = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-STARTUP", NULL, 0)));
      SYM_STARTUP_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
    }
    if (currentStartupTimePhaseP(4)) {
      oSTELLA_VERSION_STRINGo = stellaVersionString();
      oSTARTUP_TIME_PHASESo = ((List*)(list(10, KWD_STARTUP_EARLY_INITS, KWD_STARTUP_MODULES, KWD_STARTUP_SYMBOLS, KWD_STARTUP_QUOTED_CONSTANTS, KWD_STARTUP_GLOBALS, KWD_STARTUP_CLASSES, KWD_STARTUP_FINALIZE_CLASSES, KWD_STARTUP_METHODS, KWD_STARTUP_FINALIZE_METHODS, KWD_STARTUP_FINAL)));
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("STELLA-VERSION-STRING", "(DEFUN (STELLA-VERSION-STRING STRING) () :DOCUMENTATION \"Return a string identifying the current version of STELLA.\" :PUBLIC? TRUE)", ((cpp_function_code)(&stellaVersionString)), NULL);
      defineFunctionObject("STELLA-INFORMATION", "(DEFUN (STELLA-INFORMATION STRING) () :DOCUMENTATION \"Returns information about the current Stella implementation.\nUseful when reporting problems.\" :PUBLIC? TRUE :COMMAND? TRUE)", ((cpp_function_code)(&stellaInformation)), ((cpp_function_code)(&stellaInformationEvaluatorWrapper)));
      defineFunctionObject("CURRENT-STARTUP-TIME-PHASE?", "(DEFUN (CURRENT-STARTUP-TIME-PHASE? BOOLEAN) ((PHASE INTEGER)) :PUBLIC? TRUE)", ((cpp_function_code)(&currentStartupTimePhaseP)), NULL);
      defineFunctionObject("ENCODE-STARTUP-TIME-PHASE", "(DEFUN (ENCODE-STARTUP-TIME-PHASE INTEGER) ((PHASE KEYWORD)))", ((cpp_function_code)(&encodeStartupTimePhase)), NULL);
      defineFunctionObject("STARTUP-KERNEL", "(DEFUN STARTUP-KERNEL ((VERBOSE? BOOLEAN)))", ((cpp_function_code)(&startupKernel)), NULL);
      defineFunctionObject("STARTUP-CPP-TRANSLATOR", "(DEFUN STARTUP-CPP-TRANSLATOR ())", ((cpp_function_code)(&startupCppTranslator)), NULL);
      defineFunctionObject("STARTUP-JAVA-TRANSLATOR", "(DEFUN STARTUP-JAVA-TRANSLATOR ())", ((cpp_function_code)(&startupJavaTranslator)), NULL);
      defineFunctionObject("STARTUP-IDL-TRANSLATOR", "(DEFUN STARTUP-IDL-TRANSLATOR ())", ((cpp_function_code)(&startupIdlTranslator)), NULL);
      defineFunctionObject("STARTUP", "(DEFUN STARTUP ((VERBOSE? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&startup)), NULL);
      defineFunctionObject("INTERPRET-COMMAND-LINE-ARGUMENTS", "(DEFUN INTERPRET-COMMAND-LINE-ARGUMENTS ((COUNT INTEGER) (ARGUMENTS (ARRAY () OF STRING))) :DOCUMENTATION \"Old name for `process-command-line-arguments' (which see).\" :PUBLIC? TRUE)", ((cpp_function_code)(&interpretCommandLineArguments)), NULL);
      defineFunctionObject("CONSIFY-COMMAND-LINE-ARGUMENTS", "(DEFUN (CONSIFY-COMMAND-LINE-ARGUMENTS (CONS OF STRING-WRAPPER)) ((COUNT INTEGER) (ARGUMENTS (ARRAY () OF STRING))) :DOCUMENTATION \"Convert `count' command line `arguments' into a CONS list.\" :PUBLIC? TRUE)", ((cpp_function_code)(&consifyCommandLineArguments)), NULL);
      defineFunctionObject("MAIN", "(DEFUN (MAIN INTEGER) ((COUNT INTEGER) (ARGUMENTS (ARRAY () OF STRING))) :PUBLIC? TRUE)", NULL, NULL);
      defineFunctionObject("STARTUP-STARTUP", "(DEFUN STARTUP-STARTUP () :PUBLIC? TRUE)", ((cpp_function_code)(&startupStartup)), NULL);
      { MethodSlot* function = lookupFunction(SYM_STARTUP_STELLA_STARTUP_STARTUP);

        setDynamicSlotValue(function->dynamicSlots, SYM_STARTUP_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupStartup"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      inModule(((StringWrapper*)(copyConsTree(wrapString("/STELLA")))));
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-MAJOR-VERSION-NUMBER* INTEGER 3 :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-MINOR-VERSION-NUMBER* INTEGER 5 :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-RELEASE-STATE* STRING \"\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-PATCH-LEVEL* INTEGER 29 :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-VERSION-STRING* STRING (STELLA-VERSION-STRING) :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STARTUP-TIME-PHASES* (LIST OF KEYWORD) (CAST (LIST :EARLY-INITS :MODULES :SYMBOLS :QUOTED-CONSTANTS :GLOBALS :CLASSES :FINALIZE-CLASSES :METHODS :FINALIZE-METHODS :FINAL) (LIST OF KEYWORD)) :DOCUMENTATION \"List of phases that can be legally used as an optional\nphase argument to a `startup-time-progn' form.  The corresponding code\nwill be executed during the execution of a startup-time-code function only\nif the position of the keyword in the list corresponds to the current value of\n`*STARTUP-TIME-PHASE*', or if phasing of startup-time code is disabled.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STARTUP-TIME-PHASE* INTEGER 999 :PUBLIC? TRUE :DOCUMENTATION \"The current phase during 'phased startup'.\nThe value has to correspond to the position of one of the keywords\nin `*STARTUP-TIME-PHASES*'.  999 means no phasing at all.\")");
    }
  }
}

Keyword* KWD_STARTUP_EARLY_INITS = NULL;

Keyword* KWD_STARTUP_MODULES = NULL;

Keyword* KWD_STARTUP_SYMBOLS = NULL;

Keyword* KWD_STARTUP_QUOTED_CONSTANTS = NULL;

Keyword* KWD_STARTUP_GLOBALS = NULL;

Keyword* KWD_STARTUP_CLASSES = NULL;

Keyword* KWD_STARTUP_FINALIZE_CLASSES = NULL;

Keyword* KWD_STARTUP_METHODS = NULL;

Keyword* KWD_STARTUP_FINALIZE_METHODS = NULL;

Keyword* KWD_STARTUP_FINAL = NULL;

Keyword* KWD_STARTUP_WARN = NULL;

Keyword* KWD_STARTUP_DOCUMENTATION = NULL;

Symbol* SYM_STARTUP_STELLA_STARTUP_STARTUP = NULL;

Symbol* SYM_STARTUP_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella


