//  -*- Mode: Java -*-
//
// _StartupSystems.java

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
| Portions created by the Initial Developer are Copyright (C) 1996-2006      |
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

package edu.isi.stella;

import edu.isi.stella.javalib.*;

public class _StartupSystems {
  static void helpStartupSystems1() {
    {
      Stella.SYM_STELLA_IN_MODULE = ((Symbol)(Stella.internRigidSymbolWrtModule("IN-MODULE", null, 0)));
      Stella.SYM_STELLA_DEFSYSTEM = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFSYSTEM", null, 0)));
      Stella.KWD_FILES = ((Keyword)(Stella.internRigidSymbolWrtModule("FILES", null, 2)));
      Stella.KWD_REQUIRED_SYSTEMS = ((Keyword)(Stella.internRigidSymbolWrtModule("REQUIRED-SYSTEMS", null, 2)));
      Stella.KWD_LISP_ONLY_FILES = ((Keyword)(Stella.internRigidSymbolWrtModule("LISP-ONLY-FILES", null, 2)));
      Stella.KWD_CPP_ONLY_FILES = ((Keyword)(Stella.internRigidSymbolWrtModule("CPP-ONLY-FILES", null, 2)));
      Stella.KWD_JAVA_ONLY_FILES = ((Keyword)(Stella.internRigidSymbolWrtModule("JAVA-ONLY-FILES", null, 2)));
      Stella.KWD_PREPROCESSED_FILES = ((Keyword)(Stella.internRigidSymbolWrtModule("PREPROCESSED-FILES", null, 2)));
      Stella.KWD_CARDINAL_MODULE = ((Keyword)(Stella.internRigidSymbolWrtModule("CARDINAL-MODULE", null, 2)));
      Stella.KWD_ROOT_SOURCE_DIRECTORY = ((Keyword)(Stella.internRigidSymbolWrtModule("ROOT-SOURCE-DIRECTORY", null, 2)));
      Stella.KWD_ROOT_NATIVE_DIRECTORY = ((Keyword)(Stella.internRigidSymbolWrtModule("ROOT-NATIVE-DIRECTORY", null, 2)));
      Stella.KWD_ROOT_BINARY_DIRECTORY = ((Keyword)(Stella.internRigidSymbolWrtModule("ROOT-BINARY-DIRECTORY", null, 2)));
      Stella.KWD_BANNER = ((Keyword)(Stella.internRigidSymbolWrtModule("BANNER", null, 2)));
      Stella.KWD_COPYRIGHT_HEADER = ((Keyword)(Stella.internRigidSymbolWrtModule("COPYRIGHT-HEADER", null, 2)));
      Stella.KWD_PRODUCTION_SETTINGS = ((Keyword)(Stella.internRigidSymbolWrtModule("PRODUCTION-SETTINGS", null, 2)));
      Stella.KWD_DEVELOPMENT_SETTINGS = ((Keyword)(Stella.internRigidSymbolWrtModule("DEVELOPMENT-SETTINGS", null, 2)));
      Stella.KWD_FINALIZATION_FUNCTION = ((Keyword)(Stella.internRigidSymbolWrtModule("FINALIZATION-FUNCTION", null, 2)));
      Stella.KWD_FORCE_RECOMPILATIONp = ((Keyword)(Stella.internRigidSymbolWrtModule("FORCE-RECOMPILATION?", null, 2)));
      Stella.KWD_LOAD_SYSTEMp = ((Keyword)(Stella.internRigidSymbolWrtModule("LOAD-SYSTEM?", null, 2)));
      Stella.KWD_STARTUPp = ((Keyword)(Stella.internRigidSymbolWrtModule("STARTUP?", null, 2)));
      Stella.SYM_STELLA_SYSTEM_STARTED_UPp = ((Symbol)(Stella.internRigidSymbolWrtModule("SYSTEM-STARTED-UP?", null, 0)));
      Stella.KWD_EARLY_INITS = ((Keyword)(Stella.internRigidSymbolWrtModule("EARLY-INITS", null, 2)));
      Stella.SYM_STELLA_STARTUP = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP", null, 0)));
      Stella.SYM_STELLA_PHASE = ((Symbol)(Stella.internRigidSymbolWrtModule("PHASE", null, 0)));
      Stella.SYM_STELLA_PHASE_TO_INTEGER = ((Symbol)(Stella.internRigidSymbolWrtModule("PHASE-TO-INTEGER", null, 0)));
      Stella.KWD_SET = ((Keyword)(Stella.internRigidSymbolWrtModule("SET", null, 2)));
      Stella.KWD_ADD = ((Keyword)(Stella.internRigidSymbolWrtModule("ADD", null, 2)));
      Stella.SYM_STELLA_CONFIGURATION_TABLE = ((Symbol)(Stella.internRigidSymbolWrtModule("CONFIGURATION-TABLE", null, 0)));
      Stella.SYM_STELLA_STARTUP_SYSTEMS = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-SYSTEMS", null, 0)));
    }
  }

  public static void startupSystems() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.$STELLA_MODULE$);
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupSystems.helpStartupSystems1();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Stella.$SYSTEMDEFINITIONS$ = List.newList();
          Stella.$SYSTEM_CONFIGURATION_TABLE$ = KeyValueList.newKeyValueList();
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          Stella.defineStellaTypeFromStringifiedSource("(DEFTYPE CONFIGURATION-TABLE (KEY-VALUE-LIST OF STRING-WRAPPER OBJECT))");
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("EVALUATE-COMMAND", "(DEFUN (EVALUATE-COMMAND OBJECT) ((COMMAND OBJECT) (FINALIZE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Stella_Object", "evaluateCommand", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("LOAD-FILE", "(DEFUN LOAD-FILE ((FILE STRING)) :DOCUMENTATION \"Read STELLA commands from `file' and evaluate them.\nThe file should begin with an `in-module' declaration that specifies\nthe module within which all remaining commands are to be evaluated\nThe remaining commands are evaluated one-by-one, applying the function\n`evaluate' to each of them.\" :COMMAND? TRUE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "loadFile", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), Native.find_java_method("edu.isi.stella.Cons", "loadFileEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("MAKE-SYSTEM-DEFINITION-FILE-NAME", "(DEFUN (MAKE-SYSTEM-DEFINITION-FILE-NAME FILE-NAME) ((NAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "makeSystemDefinitionFileName", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("PARSE-LIST-OF-FILE-PATHS", "(DEFUN (PARSE-LIST-OF-FILE-PATHS (CONS OF STRING-WRAPPER)) ((FILES CONS)))", Native.find_java_method("edu.isi.stella.Cons", "parseListOfFilePaths", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("DEFINE-SYSTEM", "(DEFUN (DEFINE-SYSTEM SYSTEM-DEFINITION) ((NAME OBJECT) (OPTIONS CONS)))", Native.find_java_method("edu.isi.stella.Stella_Object", "defineSystem", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("DEFSYSTEM", "(DEFUN (DEFSYSTEM SYSTEM-DEFINITION) ((NAME SYMBOL) |&REST| (OPTIONS OBJECT)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE :DOCUMENTATION \"Define a system of files that collectively define\na Stella application.\n   Required options are:\n   :directory -- the relative path from the respective source/native/binary root directory\n                 to the directory containing the system files.  Can be a string or a list\n                 of strings (do not include directory separators).\n   :files -- a list of files in the system, containing strings and lists\n             of strings; the latter defines exploded paths to files\n             in subdirectories.\n   Optional options are:\n   :required-systems -- a list of systems (strings) that should be loaded\n                        prior to loading this system.\n   :cardinal-module -- the name (a string) of the principal module for this\n                       system.\n   :copyright-header -- string with a header for inclusion into all translated\n                        files produced by Stella.\n   :lisp-only-files  -- Like the :files keyword, but these are only included\n   :cpp-only-files      in the translation for the specific language, namely\n   :java-only-files     Common Lisp, C++ or Java\")", Native.find_java_method("edu.isi.stella.Symbol", "defsystem", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Cons")}), Native.find_java_method("edu.isi.stella.Cons", "defsystemEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("GET-SYSTEM-DEFINITION", "(DEFUN (GET-SYSTEM-DEFINITION SYSTEM-DEFINITION) ((NAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "getSystemDefinition", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("GET-CARDINAL-MODULE", "(DEFUN (GET-CARDINAL-MODULE MODULE) ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "getCardinalModule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("HELP-GET-SYSTEM-FILES", "(DEFUN HELP-GET-SYSTEM-FILES ((FILENAME FILE-NAME) (COLLECTION LIST) (PROBEFILE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Stella", "helpGetSystemFiles", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.List"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GET-SYSTEM-FILES", "(DEFUN (GET-SYSTEM-FILES (LIST OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION) (TYPE KEYWORD) (PROBEFILES? BOOLEAN)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "getSystemFiles", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition"), Native.find_java_class("edu.isi.stella.Keyword"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("CLEAN-SYSTEM", "(DEFUN CLEAN-SYSTEM ((SYSTEMNAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "cleanSystem", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("COMPUTE-OPTIMIZATION-LEVELS", "(DEFUN COMPUTE-OPTIMIZATION-LEVELS ((SYSTEM SYSTEM-DEFINITION) (PRODUCTIONMODE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "computeOptimizationLevels", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("LISP-KEYWORD-TO-STELLA-KEYWORD", "(DEFUN (LISP-KEYWORD-TO-STELLA-KEYWORD KEYWORD) ((KEY KEYWORD)))", Native.find_java_method("edu.isi.stella.Keyword", "lispKeywordToStellaKeyword", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("VET-OPTIONS", "(DEFUN (VET-OPTIONS PROPERTY-LIST) ((PLIST OBJECT) (LEGALOPTIONS (CONS OF KEYWORD))))", Native.find_java_method("edu.isi.stella.Stella_Object", "vetOptions", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("MAKE-SYSTEM", "(DEFUN (MAKE-SYSTEM BOOLEAN) ((SYSTEMNAME STRING) (LANGUAGE KEYWORD) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Translate all out-of-date files of system `systemName'\ninto `language' and then compile and load them (the latter is only possible\nfor Lisp right now).  The following keyword/value `options' are recognized:\n\n`:two-pass?': if true, all files will be scanned twice, once to\nload the signatures of objects defined in them, and once to actually\ntranslate the definitions.  Otherwise, the translator will make one pass in\nthe case that the system is already loaded (and is being remade), and two\npasses otherwise.\n\n`:development-settings?' (default false): if true translation will favor\nsafe, readable and debuggable code over efficiency (according to the value\nof `:development-settings' on the system definition).  If false, efficiency\nwill be favored instead (according to the value of `:production-settings'\non the system definition).\n\n`:production-settings?' (default true): inverse to `:development-settings?'.\n\n`:force-translation?' (default false): if true, files will be translated\nwhether or not their translations are up-to-date.\n\n`:force-recompilation?' (default false): if true, translated files will be\nrecompiled whether or not their compilations are up-to-date (only supported\nin Lisp right now).\n\n`:load-system?' (default true): if true, compiled files will be loaded into\nthe current STELLA image (only supported in Lisp right now).\n\n`:startup?' (default true): if true, the system startup function will\nbe called once all files have been loaded.\" :PUBLIC? TRUE :COMMAND? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "makeSystem", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("edu.isi.stella.Cons")}), Native.find_java_method("edu.isi.stella.Cons", "makeSystemEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("RUN-SYSTEM-FINALIZATION", "(DEFUN RUN-SYSTEM-FINALIZATION ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "runSystemFinalization", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("SYSTEM-DEFINITION-SOURCE-FILES", "(DEFUN (SYSTEM-DEFINITION-SOURCE-FILES (CONS OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "systemDefinitionSourceFiles", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("FILES-PLUS-SYSTEM-STARTUP", "(DEFUN (FILES-PLUS-SYSTEM-STARTUP (CONS OF STRING-WRAPPER)) ((FILES (CONS OF STRING-WRAPPER))))", Native.find_java_method("edu.isi.stella.Cons", "filesPlusSystemStartup", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("SYSTEM-DEFINITION-NATIVE-FILES", "(DEFUN (SYSTEM-DEFINITION-NATIVE-FILES (CONS OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "systemDefinitionNativeFiles", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("SYSTEM-LOADED?", "(DEFUN (SYSTEM-LOADED? BOOLEAN) ((NAME STRING)) :DOCUMENTATION \"Return `true' if system `name' has been loaded.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "systemLoadedP", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("CLEAR-SYSTEM", "(DEFUN CLEAR-SYSTEM ((NAME STRING)) :DOCUMENTATION \"Clears out the system definition named `name'.  If\n`name' is `null', then clear out all system definitions.  This function\nis useful when changes have been made to the system definition, and one\nwants to have it reloaded from the standard location in the file system.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "clearSystem", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("LOAD-PREPROCESSED-FILES", "(DEFUN LOAD-PREPROCESSED-FILES ((SYSTEMNAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "loadPreprocessedFiles", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("LOAD-SYSTEM", "(DEFUN (LOAD-SYSTEM BOOLEAN) ((SYSTEMNAME STRING) (LANGUAGE KEYWORD) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Natively `language'-compile out-of-date translated files of system\n`systemName' and then load them into the running system (this is only\nsupported/possible for Lisp at the moment).  Return true if at least one\nfile was compiled. The following keyword/value `options' are recognized:\n\n`:force-recompilation?' (default false): if true, files will be compiled\nwhether or not their compilations are up-to-date.\n\n`:startup?' (default true): if true, the system startup function will\nbe called once all files have been loaded.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "loadSystem", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("COMPILE-AND-LOAD-FILES", "(DEFUN (COMPILE-AND-LOAD-FILES BOOLEAN) ((FILES (CONS OF STRING-WRAPPER)) (LANGUAGE KEYWORD) (FORCERECOMPILATION? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Cons", "compileAndLoadFiles", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Keyword"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("RUN-SYSTEM-STARTUP-FUNCTION", "(DEFUN RUN-SYSTEM-STARTUP-FUNCTION ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "runSystemStartupFunction", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineMethodObject("(DEFMETHOD (SYSTEM-STARTUP-FUNCTION-NAME STRING) ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "systemStartupFunctionName", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (SYSTEM-STARTUP-FUNCTION-NAME STRING) ((SYSTEMNAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "string_systemStartupFunctionName", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("SYSTEM-STARTUP-FUNCTION-SYMBOL", "(DEFUN (SYSTEM-STARTUP-FUNCTION-SYMBOL SYMBOL) ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "systemStartupFunctionSymbol", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("STARTUP-NAME-FROM-FILE", "(DEFUN (STARTUP-NAME-FROM-FILE SYMBOL) ((FILE FILE-NAME)))", Native.find_java_method("edu.isi.stella.Stella", "startupNameFromFile", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("STARTUP-NAMES-FROM-FILES", "(DEFUN (STARTUP-NAMES-FROM-FILES (CONS OF SYMBOL)) ((FILES (CONS OF STRING-WRAPPER))))", Native.find_java_method("edu.isi.stella.Cons", "startupNamesFromFiles", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("SYSTEM-STARTUP-FILE-NAME", "(DEFUN (SYSTEM-STARTUP-FILE-NAME STRING) ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "systemStartupFileName", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("SYSTEM-STARTUP-FILE?", "(DEFUN (SYSTEM-STARTUP-FILE? BOOLEAN) ((FILE FILE-NAME)))", Native.find_java_method("edu.isi.stella.Stella", "systemStartupFileP", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("SYSTEM-STARTED-UP?", "(DEFUN (SYSTEM-STARTED-UP? BOOLEAN) ((SYSTEMNAME STRING) (SYSTEMMODULENAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "systemStartedUpP", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("YIELD-STARTUP-REQUIRED-SYSTEMS", "(DEFUN (YIELD-STARTUP-REQUIRED-SYSTEMS CONS) ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "yieldStartupRequiredSystems", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE", "(DEFUN (COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE (CONS OF CONS)) ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "collectStartupFormsFromSystemFile", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("CREATE-SYSTEM-STARTUP-FILE", "(DEFUN CREATE-SYSTEM-STARTUP-FILE ((SYSTEM SYSTEM-DEFINITION)))", Native.find_java_method("edu.isi.stella.SystemDefinition", "createSystemStartupFile", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.SystemDefinition")}), null);
          Stella.defineFunctionObject("HELP-ALL-REQUIRED-SYSTEMS", "(DEFUN (HELP-ALL-REQUIRED-SYSTEMS (LIST OF STRING-WRAPPER)) ((SYSTEM-NAME STRING) (FOUND (LIST OF STRING-WRAPPER))))", Native.find_java_method("edu.isi.stella.Stella", "helpAllRequiredSystems", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject("ALL-REQUIRED-SYSTEMS", "(DEFUN (ALL-REQUIRED-SYSTEMS (CONS OF STRING-WRAPPER)) ((SYSTEM-NAME STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Returns a CONS of all of the systems required by `system-name'\")", Native.find_java_method("edu.isi.stella.Stella", "allRequiredSystems", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("MAKE-STELLA", "(DEFUN MAKE-STELLA ((FORCERECOMPILATION? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Stella", "makeStella", new java.lang.Class [] {java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("PARSE-CONFIGURATION-FILE-LINE", "(DEFUN (PARSE-CONFIGURATION-FILE-LINE STRING-WRAPPER WRAPPER KEYWORD) ((LINE STRING)))", Native.find_java_method("edu.isi.stella.Stella", "parseConfigurationFileLine", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("LOAD-CONFIGURATION-FILE", "(DEFUN (LOAD-CONFIGURATION-FILE CONFIGURATION-TABLE) ((FILE FILE-NAME)) :DOCUMENTATION \"Read a configuration `file' and return its content as a configuration table.\nAlso enter each property read into the global system configuration table.\nAssumes Java-style property file syntax.  Each property name is represented\nas a wrapped string and each value as a wrapped string/integer/float or boolean.\" :PUBLIC? TRUE :CONSTRUCTOR? TRUE)", Native.find_java_method("edu.isi.stella.KeyValueList", "loadConfigurationFile", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("SAVE-CONFIGURATION-VALUE", "(DEFUN SAVE-CONFIGURATION-VALUE ((STREAM OUTPUT-STREAM) (VALUE OBJECT)) :DOCUMENTATION \"Save `value' to `stream' as a properly formatted configuration\nvalue.\")", Native.find_java_method("edu.isi.stella.OutputStream", "saveConfigurationValue", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputStream"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("SAVE-CONFIGURATION-FILE", "(DEFUN SAVE-CONFIGURATION-FILE ((TABLE CONFIGURATION-TABLE) (FILE FILE-NAME) (TITLE STRING)) :DOCUMENTATION \"Save `table' as a configuration file.  Uses a Java-style property file syntax.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.KeyValueList", "saveConfigurationFile", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.KeyValueList"), Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("LOOKUP-CONFIGURATION-PROPERTY", "(DEFUN (LOOKUP-CONFIGURATION-PROPERTY OBJECT) ((PROPERTY STRING) (DEFAULTVALUE WRAPPER) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Lookup `property' in `configuration' and return its value.\nUse the global system configuration table if `configuration' is NULL.  Return\n`defaultValue' if `property' is not defined.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupConfigurationProperty", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Wrapper"), Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("LOOKUP-CONFIGURATION-PROPERTY-VALUES", "(DEFUN (LOOKUP-CONFIGURATION-PROPERTY-VALUES CONS) ((PROPERTY STRING) (DEFAULTVALUE OBJECT) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Lookup `property' in `configuration', assume it is a multi-valued\nproperty and return its value(s) as a list.  Use the global system configuration table\nif `configuration' is NULL.  Return `defaultValue' if `property' is not defined or\nNIL is no default value is specified.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupConfigurationPropertyValues", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("SET-CONFIGURATION-PROPERTY", "(DEFUN (SET-CONFIGURATION-PROPERTY OBJECT) ((PROPERTY STRING) (VALUE OBJECT) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Set `property' in `configuration' to `value' and return it.\nUse the global system configuration table if `configuration' is NULL.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "setConfigurationProperty", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("ADD-CONFIGURATION-PROPERTY", "(DEFUN (ADD-CONFIGURATION-PROPERTY OBJECT) ((PROPERTY STRING) (VALUE OBJECT) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Add `value' to `property' in `configuration' and return it.\nIf a previous value exists add `value' to the end (listify the old value\nif it is not yet a list).  Otherwise, create a new list containing `value'.\nUse the global system configuration table if `configuration' is NULL.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "addConfigurationProperty", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("CLEAR-CONFIGURATION-PROPERTY", "(DEFUN (CLEAR-CONFIGURATION-PROPERTY OBJECT) ((PROPERTY STRING) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Remove `property' in `configuration' and return the previous\nvalue.\nUse the global system configuration table if `configuration' is NULL.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "clearConfigurationProperty", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("REMOVE-CONFIGURATION-PROPERTY", "(DEFUN (REMOVE-CONFIGURATION-PROPERTY OBJECT) ((PROPERTY STRING) (VALUE OBJECT) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Remove `value' from `property' in `configuration' and return it.\nUse the global system configuration table if `configuration' is NULL.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "removeConfigurationProperty", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("CONFIGURE-STELLA", "(DEFUN CONFIGURE-STELLA ((FILE FILE-NAME)) :DOCUMENTATION \"Perform STELLA run-time configuration.  If supplied, load the\nconfiguration file `file' first which should be supplied with a physical pathname.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "configureStella", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("STARTUP-SYSTEMS", "(DEFUN STARTUP-SYSTEMS () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella._StartupSystems", "startupSystems", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Stella.SYM_STELLA_STARTUP_SYSTEMS);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Stella.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupSystems"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SYSTEMDEFINITIONS* (LIST OF SYSTEM-DEFINITION) (NEW LIST) :DOCUMENTATION \"A list of all defined systems.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SYSTEM-CONFIGURATION-TABLE* CONFIGURATION-TABLE (NEW CONFIGURATION-TABLE))");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
