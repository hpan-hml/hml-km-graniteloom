//  -*- Mode: C++ -*-

// java-translate-file.cc

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
| Portions created by the Initial Developer are Copyright (C) 1996-2010      |
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

// Holds the current Stella class being output in Java
DEFINE_STELLA_SPECIAL(oCURRENT_JAVA_OUTPUT_CLASSo, Class* , NULL);

void clt() {
  stringChangeModule("STELLA");
  setTranslatorOutputLanguage(KWD_JAVA_TRANSLATE_FILE_COMMON_LISP);
}

void jt() {
  stringChangeModule("STELLA");
  setTranslatorOutputLanguage(KWD_JAVA_TRANSLATE_FILE_JAVA);
}

void jptrans(Object* statement) {
  // Translate `statement' to C++ and print the result.
  { 
    BIND_STELLA_SPECIAL(oTRANSLATOROUTPUTLANGUAGEo, Keyword*, oTRANSLATOROUTPUTLANGUAGEo.get());
    BIND_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream*, STANDARD_OUTPUT);
    setTranslatorOutputLanguage(KWD_JAVA_TRANSLATE_FILE_JAVA);
    incrementallyTranslate(statement);
  }
}

char* stringJavaMakeCodeOutputFileName(char* barefile, boolean donttruncateP) {
  if (donttruncateP) {
    { 
      BIND_STELLA_SPECIAL(oDONTTRUNCATEFILENAMESpo, boolean, true);
      return (makeFileNameFromRelativePath(wrapString(barefile), KWD_JAVA_TRANSLATE_FILE_JAVA));
    }
  }
  else {
    return (makeFileNameFromRelativePath(wrapString(barefile), KWD_JAVA_TRANSLATE_FILE_JAVA));
  }
}

char* Class::javaMakeCodeOutputFileName(boolean donttruncateP) {
  { Class* source = this;

    { StringWrapper* barefile = javaTranslateClassNamestring(wrapString(className(source)));

      return (stringJavaMakeCodeOutputFileName(barefile->wrapperValue, donttruncateP));
    }
  }
}

char* javaMakeGlobalOutputFileName(Module* module, boolean donttruncateP) {
  return (stringJavaMakeCodeOutputFileName(javaYieldFlotsamClassName(module), donttruncateP));
}

void javaOutputFlotsamUnitsToFile(HashTable* globalsht, HashTable* functionht, Cons* codemodulelist) {
  { Cons* functions = NIL;
    Cons* globals = NIL;
    char* filename = NULL;
    Cons* flotsamFiles = NIL;

    { Module* module = NULL;
      Cons* iter000 = codemodulelist;

      for (module, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        module = ((Module*)(iter000->value));
        { 
          BIND_STELLA_SPECIAL(oMODULEo, Module*, module);
          BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
          filename = javaMakeGlobalOutputFileName(module, false);
          if (flotsamFiles->memberP(wrapString(filename))) {
            *(STANDARD_WARNING->nativeStream) << "Warning: " << "Overwriting Flotsam file " << "`" << filename << "'" << ".  This is surely bad." << std::endl;
          }
          flotsamFiles = cons(wrapString(filename), flotsamFiles);
          globals = ((Cons*)(globalsht->lookup(module)));
          if (!(((boolean)(globals)))) {
            globals = NIL;
          }
          functions = ((Cons*)(functionht->lookup(module)));
          if (!(((boolean)(functions)))) {
            functions = NIL;
          }
          javaOutputFlotsamUnitsToFileForModule(filename, module, NULL, globals, functions);
        }
      }
    }
  }
}

void javaOutputFlotsamUnitsToFileForModule(char* classoutputfile, Module* module, TranslationUnit* classunit, Cons* globals, Cons* functions) {
  { 
    BIND_STELLA_SPECIAL(oCURRENT_JAVA_OUTPUT_CLASSo, Class*, NULL);
    { Cons* translation = NIL;
      Class* clasS = NULL;
      Cons* classtranslation = NIL;

      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, module);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
        { OutputFileStream* classoutputstream = NULL;

          try {
            classoutputstream = openOutputFile(classoutputfile, 0);
            if (((boolean)(classunit))) {
              oCURRENT_JAVA_OUTPUT_CLASSo.set(((Class*)(classunit->theObject)));
              std::cout << "Translating " << "`" << clasS << "'" << "..." << std::endl;
              classtranslation = javaTranslateDefineNativeClass(oCURRENT_JAVA_OUTPUT_CLASSo.get())->rest;
            }
            { 
              BIND_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream*, classoutputstream);
              if (oTRANSLATIONVERBOSITYLEVELo.get() >= 1) {
                if (((boolean)(classunit))) {
                  std::cout << "    Writing " << "`" << classoutputfile << "'" << " ..." << std::endl;
                }
                else {
                  std::cout << "Writing " << "`" << classoutputfile << "'" << "..." << std::endl;
                }
              }
              javaOutputFileHeader(classoutputstream, javaMakeGlobalOutputFileName(module, true));
              if (((boolean)(classunit))) {
                javaOutputClassDeclaration(classtranslation);
              }
              else {
                *(oCURRENT_STREAMo.get()->nativeStream) << "public class " << javaYieldFlotsamClassName(module) << " ";
              }
              *(oCURRENT_STREAMo.get()->nativeStream) << "{" << std::endl;
              javaBumpIndent();
              if (((boolean)(classunit))) {
                javaOutputClassVariableDefinitions(((Cons*)(classtranslation->nth(6))));
              }
              { TranslationUnit* global = NULL;
                Cons* iter000 = globals;

                for (global, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
                  global = ((TranslationUnit*)(iter000->value));
                  translation = javaTranslateUnit(global);
                  javaOutputGlobalDefinition(translation->rest);
                  global->translation = NULL;
                  global->codeRegister = NULL;
                }
              }
              if (((boolean)(classunit))) {
                javaOutputClassConstructors(((Cons*)(classtranslation->nth(7))), javaYieldFlotsamClassName(module), ((boolean)(oCURRENT_JAVA_OUTPUT_CLASSo.get())) &&
                    exceptionClassP(oCURRENT_JAVA_OUTPUT_CLASSo.get()));
                { TranslationUnit* statement = NULL;
                  Cons* iter001 = ((Cons*)(classtranslation->nth(8)));

                  for (statement, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
                    statement = ((TranslationUnit*)(iter001->value));
                    javaOutputStatement(javaTranslateUnit(statement));
                    statement->translation = NULL;
                    statement->codeRegister = NULL;
                  }
                }
              }
              { TranslationUnit* function = NULL;
                Cons* iter002 = functions;

                for (function, iter002; !(iter002 == NIL); iter002 = iter002->rest) {
                  function = ((TranslationUnit*)(iter002->value));
                  javaOutputMethod(javaTranslateUnit(function)->rest);
                  function->translation = NULL;
                  function->codeRegister = NULL;
                }
              }
              javaUnbumpIndent();
              *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
            }
          }
catch (...) {
            if (((boolean)(classoutputstream))) {
              classoutputstream->free();
            }
            throw;
          }
          if (((boolean)(classoutputstream))) {
            classoutputstream->free();
          }
        }
      }
    }
  }
}

void javaOutputFileHeader(OutputStream* stream, char* filename) {
  *(stream->nativeStream) << "//  -*- Mode: Java -*-" << std::endl << "//" << std::endl;
  if (filename != NULL) {
    *(stream->nativeStream) << "// " << fileNameWithoutDirectory(filename) << std::endl << std::endl;
  }
  { char* packageName = javaPackagePrefix(oMODULEo.get(), ".");
    Cons* importedPackages = NIL;
    char* name = NULL;

    outputCopyrightHeader(stream);
    if (!((packageName == NULL) ||
        stringEqlP(packageName, ""))) {
      packageName = stringSubsequence(packageName, 0, strlen(packageName) - 1);
      *(stream->nativeStream) << "package " << packageName << ";" << std::endl << std::endl;
    }
    if (oMODULEo.get() == oSTELLA_MODULEo) {
      *(stream->nativeStream) << "import " << javaStellaPackage() << ".javalib.*;" << std::endl;
    }
    else {
      {
        if ((!((boolean)(stringGetStellaClass("NATIVE", false)))) &&
            (!inheritedClassNameConflictsP("NATIVE"))) {
          *(stream->nativeStream) << "import " << javaStellaPackage() << ".javalib.Native;" << std::endl;
        }
        if ((!((boolean)(stringGetStellaClass("STELLA-SPECIAL-VARIABLE", false)))) &&
            (!inheritedClassNameConflictsP("STELLA-SPECIAL-VARIABLE"))) {
          *(stream->nativeStream) << "import " << javaStellaPackage() << ".javalib.StellaSpecialVariable;" << std::endl;
        }
      }
    }
    if (oCURRENT_STELLA_FEATURESo.get()->membP(KWD_JAVA_TRANSLATE_FILE_MINIMIZE_JAVA_PREFIXES)) {
      { Module* module = NULL;
        Cons* iter000 = oMODULEo.get()->uses->theConsList;

        for (module, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
          module = ((Module*)(iter000->value));
          name = javaPackagePrefix(module, ".");
          if (!(stringEqlP(name, packageName) ||
              importedPackages->memberP(wrapString(name)))) {
            *(stream->nativeStream) << "import " << name << "*;" << std::endl;
            importedPackages = cons(wrapString(name), importedPackages);
          }
        }
      }
      { Context* module = NULL;
        Cons* iter001 = oMODULEo.get()->allSuperContexts;

        for (module, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
          module = ((Context*)(iter001->value));
          name = javaPackagePrefix(((Module*)(module)), ".");
          if (!(stringEqlP(name, packageName) ||
              importedPackages->memberP(wrapString(name)))) {
            *(stream->nativeStream) << "import " << name << "*;" << std::endl;
            importedPackages = cons(wrapString(name), importedPackages);
          }
        }
      }
    }
    *(stream->nativeStream) << std::endl;
  }
}

void javaOutputClassToFile(Class* clasS) {
  { 
    BIND_STELLA_SPECIAL(oCURRENT_JAVA_OUTPUT_CLASSo, Class*, clasS);
    { 
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, clasS->homeModule());
      BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
      { char* classoutputfile = clasS->javaMakeCodeOutputFileName(false);
        Cons* translation = NIL;

        { OutputFileStream* classoutputstream = NULL;

          try {
            classoutputstream = openOutputFile(classoutputfile, 0);
            { 
              BIND_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream*, classoutputstream);
              std::cout << "Translating " << "`" << clasS << "'" << "..." << std::endl;
              translation = javaTranslateDefineNativeClass(clasS);
              if (oTRANSLATIONVERBOSITYLEVELo.get() >= 1) {
                std::cout << "    Writing " << "`" << classoutputfile << "'" << "..." << std::endl;
              }
              javaOutputFileHeader(classoutputstream, clasS->javaMakeCodeOutputFileName(true));
              javaOutputClass(translation->rest, exceptionClassP(clasS));
            }
          }
catch (...) {
            if (((boolean)(classoutputstream))) {
              classoutputstream->free();
            }
            throw;
          }
          if (((boolean)(classoutputstream))) {
            classoutputstream->free();
          }
        }
      }
    }
  }
}

void javaOutputClassUnitToFile(TranslationUnit* classunit) {
  javaOutputClassToFile(((Class*)(classunit->theObject)));
}

boolean javaFlotsamFunctionP(MethodSlot* method) {
  return ((!((BooleanWrapper*)(dynamicSlotValue(method->dynamicSlots, SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_CONSTRUCTORp, FALSE_WRAPPER)))->wrapperValue) &&
      ((!((BooleanWrapper*)(dynamicSlotValue(method->dynamicSlots, SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_NATIVEp, FALSE_WRAPPER)))->wrapperValue) &&
       ((!method->methodStartupFunctionP()) &&
        (zeroArgumentFunctionP(method) ||
         (javaMethodObjectDefinedOnNativeTypeP(method) ||
          javaFunctionInDifferentModuleP(method))))));
}

void javaOutputStartupUnitsToFile(StringHashTable* startupht, Cons* keylist) {
  { char* classoutputfile = NULL;
    Cons* startupfunctions = NULL;

    { 
      BIND_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream*, NULL);
      { StringWrapper* classname = NULL;
        Cons* iter000 = keylist;

        for (classname, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
          classname = ((StringWrapper*)(iter000->value));
          startupfunctions = ((Cons*)(startupht->lookup(classname->wrapperValue)));
          if (((boolean)(startupfunctions)) &&
              (!(!((boolean)(startupfunctions))))) {
            { 
              BIND_STELLA_SPECIAL(oMODULEo, Module*, ((TranslationUnit*)(startupfunctions->value))->homeModule());
              BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
              classoutputfile = stringJavaMakeCodeOutputFileName(classname->wrapperValue, false);
              { OutputFileStream* classoutputstream = NULL;

                try {
                  classoutputstream = openOutputFile(classoutputfile, 0);
                  oCURRENT_STREAMo.set(classoutputstream);
                  if (oTRANSLATIONVERBOSITYLEVELo.get() >= 1) {
                    std::cout << "Writing " << "`" << classoutputfile << "'" << "..." << std::endl;
                  }
                  javaOutputFileHeader(classoutputstream, stringJavaMakeCodeOutputFileName(classname->wrapperValue, true));
                  *(oCURRENT_STREAMo.get()->nativeStream) << "public class " << classname->wrapperValue << " {" << std::endl;
                  javaBumpIndent();
                  { TranslationUnit* function = NULL;
                    Cons* iter001 = startupfunctions;

                    for (function, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
                      function = ((TranslationUnit*)(iter001->value));
                      javaOutputMethod(javaTranslateUnit(function)->rest);
                      function->translation = NULL;
                      function->codeRegister = NULL;
                    }
                  }
                  javaUnbumpIndent();
                  *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
                }
catch (...) {
                  if (((boolean)(classoutputstream))) {
                    classoutputstream->free();
                  }
                  throw;
                }
                if (((boolean)(classoutputstream))) {
                  classoutputstream->free();
                }
              }
            }
          }
        }
      }
    }
  }
}

void javaPushIntoHashTable(HashTable* ht, Object* key, Object* object) {
  { Cons* value = ((Cons*)(ht->lookup(key)));

    if (((boolean)(value))) {
      ht->insertAt(key, cons(object, value));
    }
    else {
      ht->insertAt(key, cons(object, NIL));
    }
  }
}

void javaPushIntoStringHashTable(StringHashTable* ht, char* key, Object* object) {
  { Cons* value = ((Cons*)(ht->lookup(key)));

    if (((boolean)(value))) {
      ht->insertAt(key, cons(object, value));
    }
    else {
      ht->insertAt(key, cons(object, NIL));
    }
  }
}

boolean javaClassUnitDefinesFlotsamClassP(TranslationUnit* classunit) {
  { Class* clasS = ((Class*)(classunit->theObject));
    Module* module = classunit->homeModule();

    return (stringEqlP(javaTranslateClassNamestring(wrapString(internSymbolInModule(clasS->classType->symbolName, ((Module*)(clasS->classType->homeContext)), false)->symbolName))->wrapperValue, javaYieldFlotsamClassName(module)));
  }
}

void javaOutputAllUnitsToFile() {
  { StringWrapper* startupclassname = NULL;
    StringHashTable* startupht = newStringHashTable();
    Cons* startupclasslist = NIL;
    Cons* methods = NIL;
    HashTable* flotsamfunctionht = newHashTable();
    HashTable* globalsht = newHashTable();
    List* codemoduleslist = list(0);
    Cons* verbatimstatements = NIL;
    Cons* classes = NIL;
    Module* codeoutputmodule = NULL;

    oJAVA_STELLA_PACKAGE_MAPPINGo->insertAt(wrapString("STELLAROOT"), wrapString(javaStellaPackage()));
    oTRANSLATIONUNITSo.set(oTRANSLATIONUNITSo.get()->reverse());
    { TranslationUnit* unit = NULL;
      Cons* iter000 = oTRANSLATIONUNITSo.get()->theConsList;

      for (unit, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        unit = ((TranslationUnit*)(iter000->value));
        { Symbol* testValue000 = unit->category;

          if ((testValue000 == SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD) ||
              (testValue000 == SYM_JAVA_TRANSLATE_FILE_STELLA_MACRO)) {
            if (javaFlotsamFunctionP(((MethodSlot*)(unit->theObject)))) {
              codeoutputmodule = unit->theObject->homeModule();
              javaPushIntoHashTable(flotsamfunctionht, codeoutputmodule, unit);
              codemoduleslist->insertNew(codeoutputmodule);
            }
            else if (((MethodSlot*)(unit->theObject))->methodStartupFunctionP()) {
              startupclassname = javaTranslateClassNamestring(wrapString(((StringWrapper*)(dynamicSlotValue(((MethodSlot*)(unit->theObject))->dynamicSlots, SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME, NULL_STRING_WRAPPER)))->wrapperValue));
              javaPushIntoStringHashTable(startupht, startupclassname->wrapperValue, unit);
              if (!(startupclasslist->memberP(startupclassname))) {
                startupclasslist = cons(startupclassname, startupclasslist);
              }
            }
            else {
              methods = cons(unit, methods);
            }
          }
          else if (testValue000 == SYM_JAVA_TRANSLATE_FILE_STELLA_PRINT_METHOD) {
            methods = cons(unit, methods);
          }
          else if (testValue000 == SYM_JAVA_TRANSLATE_FILE_STELLA_TYPE) {
          }
          else if (testValue000 == SYM_JAVA_TRANSLATE_FILE_STELLA_VERBATIM) {
            verbatimstatements = cons(unit, verbatimstatements);
          }
          else if (testValue000 == SYM_JAVA_TRANSLATE_FILE_STELLA_CLASS) {
            classes = cons(unit, classes);
          }
          else if (testValue000 == SYM_JAVA_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE) {
            codeoutputmodule = unit->theObject->homeModule();
            javaPushIntoHashTable(globalsht, codeoutputmodule, unit);
            codemoduleslist->insertNew(codeoutputmodule);
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
    { TranslationUnit* classunit = NULL;
      Cons* iter001 = classes;

      for (classunit, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
        classunit = ((TranslationUnit*)(iter001->value));
        if (javaClassUnitDefinesFlotsamClassP(classunit)) {
          { Module* module = classunit->theObject->homeModule();
            Cons* globals = NIL;
            Cons* functions = NIL;

            { 
              BIND_STELLA_SPECIAL(oMODULEo, Module*, module);
              BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
              globals = ((Cons*)(globalsht->lookup(module)));
              if (!(((boolean)(globals)))) {
                globals = NIL;
              }
              functions = ((Cons*)(flotsamfunctionht->lookup(module)));
              if (!(((boolean)(functions)))) {
                functions = NIL;
              }
              javaOutputFlotsamUnitsToFileForModule(javaMakeGlobalOutputFileName(module, false), module, classunit, globals, functions);
              codemoduleslist->remove(module);
            }
          }
        }
        else {
          javaOutputClassUnitToFile(classunit);
        }
      }
    }
    javaOutputFlotsamUnitsToFile(globalsht, flotsamfunctionht, codemoduleslist->theConsList);
    javaOutputStartupUnitsToFile(startupht, startupclasslist);
  }
}

void javaInitializeFileTranslation() {
  oJAVA_INDENT_CHARSo.set(0);
}

void javaTranslateFile(char* filename) {
  translateFile(filename, KWD_JAVA_TRANSLATE_FILE_JAVA, false);
}

void javaTranslateFileAsPartOfSystem(char* filename) {
  translateFile(filename, KWD_JAVA_TRANSLATE_FILE_JAVA, true);
}

void javaTranslateWalkedSystemUnits(KeyValueList* systemunits) {
  { 
    BIND_STELLA_SPECIAL(oTRANSLATIONUNITSo, List*, concatenateSystemUnits(systemunits));
    if (oTRANSLATIONVERBOSITYLEVELo.get() >= 1) {
      std::cout << "Generating Java translations..." << std::endl;
    }
    javaOutputAllUnitsToFile();
    cleanUpTranslationUnitsSpecial();
  }
}

void javaTranslateSystem(char* systemname) {
  // Translate the system `systemName' to Java.
  translateSystem(systemname, consList(7, KWD_JAVA_TRANSLATE_FILE_JAVA, KWD_JAVA_TRANSLATE_FILE_TWO_PASSp, TRUE_WRAPPER, KWD_JAVA_TRANSLATE_FILE_FORCE_TRANSLATIONp, TRUE_WRAPPER, KWD_JAVA_TRANSLATE_FILE_PRODUCTION_SETTINGSp, TRUE_WRAPPER));
}

void startupJavaTranslateFile() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      KWD_JAVA_TRANSLATE_FILE_COMMON_LISP = ((Keyword*)(internRigidSymbolWrtModule("COMMON-LISP", NULL, 2)));
      KWD_JAVA_TRANSLATE_FILE_JAVA = ((Keyword*)(internRigidSymbolWrtModule("JAVA", NULL, 2)));
      KWD_JAVA_TRANSLATE_FILE_MINIMIZE_JAVA_PREFIXES = ((Keyword*)(internRigidSymbolWrtModule("MINIMIZE-JAVA-PREFIXES", NULL, 2)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_CONSTRUCTORp = ((Symbol*)(internRigidSymbolWrtModule("METHOD-CONSTRUCTOR?", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_NATIVEp = ((Symbol*)(internRigidSymbolWrtModule("METHOD-NATIVE?", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD = ((Symbol*)(internRigidSymbolWrtModule("METHOD", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_MACRO = ((Symbol*)(internRigidSymbolWrtModule("MACRO", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_PRINT_METHOD = ((Symbol*)(internRigidSymbolWrtModule("PRINT-METHOD", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_TYPE = ((Symbol*)(internRigidSymbolWrtModule("TYPE", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_VERBATIM = ((Symbol*)(internRigidSymbolWrtModule("VERBATIM", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_CLASS = ((Symbol*)(internRigidSymbolWrtModule("CLASS", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE = ((Symbol*)(internRigidSymbolWrtModule("GLOBAL-VARIABLE", NULL, 0)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
      KWD_JAVA_TRANSLATE_FILE_TWO_PASSp = ((Keyword*)(internRigidSymbolWrtModule("TWO-PASS?", NULL, 2)));
      KWD_JAVA_TRANSLATE_FILE_FORCE_TRANSLATIONp = ((Keyword*)(internRigidSymbolWrtModule("FORCE-TRANSLATION?", NULL, 2)));
      KWD_JAVA_TRANSLATE_FILE_PRODUCTION_SETTINGSp = ((Keyword*)(internRigidSymbolWrtModule("PRODUCTION-SETTINGS?", NULL, 2)));
      SYM_JAVA_TRANSLATE_FILE_STELLA_STARTUP_JAVA_TRANSLATE_FILE = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-JAVA-TRANSLATE-FILE", NULL, 0)));
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("CLT", "(DEFUN CLT ())", ((cpp_function_code)(&clt)), NULL);
      defineFunctionObject("JT", "(DEFUN JT ())", ((cpp_function_code)(&jt)), NULL);
      defineFunctionObject("JPTRANS", "(DEFUN JPTRANS ((STATEMENT OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Translate `statement' to C++ and print the result.\")", ((cpp_function_code)(&jptrans)), NULL);
      defineMethodObject("(DEFMETHOD (JAVA-MAKE-CODE-OUTPUT-FILE-NAME FILE-NAME) ((BAREFILE FILE-NAME) (DONTTRUNCATE? BOOLEAN)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (JAVA-MAKE-CODE-OUTPUT-FILE-NAME FILE-NAME) ((SOURCE CLASS) (DONTTRUNCATE? BOOLEAN)))", ((cpp_method_code)(&Class::javaMakeCodeOutputFileName)), ((cpp_method_code)(NULL)));
      defineFunctionObject("JAVA-MAKE-GLOBAL-OUTPUT-FILE-NAME", "(DEFUN (JAVA-MAKE-GLOBAL-OUTPUT-FILE-NAME FILE-NAME) ((MODULE MODULE) (DONTTRUNCATE? BOOLEAN)))", ((cpp_function_code)(&javaMakeGlobalOutputFileName)), NULL);
      defineFunctionObject("JAVA-OUTPUT-FLOTSAM-UNITS-TO-FILE", "(DEFUN JAVA-OUTPUT-FLOTSAM-UNITS-TO-FILE ((GLOBALSHT HASH-TABLE) (FUNCTIONHT HASH-TABLE) (CODEMODULELIST (CONS OF MODULE))))", ((cpp_function_code)(&javaOutputFlotsamUnitsToFile)), NULL);
      defineFunctionObject("JAVA-OUTPUT-FLOTSAM-UNITS-TO-FILE-FOR-MODULE", "(DEFUN JAVA-OUTPUT-FLOTSAM-UNITS-TO-FILE-FOR-MODULE ((CLASSOUTPUTFILE FILE-NAME) (MODULE MODULE) (CLASSUNIT TRANSLATION-UNIT) (GLOBALS (CONS OF TRANSLATION-UNIT)) (FUNCTIONS (CONS OF TRANSLATION-UNIT))))", ((cpp_function_code)(&javaOutputFlotsamUnitsToFileForModule)), NULL);
      defineFunctionObject("JAVA-OUTPUT-FILE-HEADER", "(DEFUN JAVA-OUTPUT-FILE-HEADER ((STREAM OUTPUT-STREAM) (FILENAME FILE-NAME)))", ((cpp_function_code)(&javaOutputFileHeader)), NULL);
      defineFunctionObject("JAVA-OUTPUT-CLASS-TO-FILE", "(DEFUN JAVA-OUTPUT-CLASS-TO-FILE ((CLASS CLASS)))", ((cpp_function_code)(&javaOutputClassToFile)), NULL);
      defineFunctionObject("JAVA-OUTPUT-CLASS-UNIT-TO-FILE", "(DEFUN JAVA-OUTPUT-CLASS-UNIT-TO-FILE ((CLASSUNIT TRANSLATION-UNIT)))", ((cpp_function_code)(&javaOutputClassUnitToFile)), NULL);
      defineFunctionObject("JAVA-FLOTSAM-FUNCTION?", "(DEFUN (JAVA-FLOTSAM-FUNCTION? BOOLEAN) ((METHOD METHOD-SLOT)))", ((cpp_function_code)(&javaFlotsamFunctionP)), NULL);
      defineFunctionObject("JAVA-OUTPUT-STARTUP-UNITS-TO-FILE", "(DEFUN JAVA-OUTPUT-STARTUP-UNITS-TO-FILE ((STARTUPHT STRING-HASH-TABLE) (KEYLIST (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&javaOutputStartupUnitsToFile)), NULL);
      defineFunctionObject("JAVA-PUSH-INTO-HASH-TABLE", "(DEFUN JAVA-PUSH-INTO-HASH-TABLE ((HT HASH-TABLE) (KEY OBJECT) (OBJECT OBJECT)))", ((cpp_function_code)(&javaPushIntoHashTable)), NULL);
      defineFunctionObject("JAVA-PUSH-INTO-STRING-HASH-TABLE", "(DEFUN JAVA-PUSH-INTO-STRING-HASH-TABLE ((HT STRING-HASH-TABLE) (KEY STRING) (OBJECT OBJECT)))", ((cpp_function_code)(&javaPushIntoStringHashTable)), NULL);
      defineFunctionObject("JAVA-CLASS-UNIT-DEFINES-FLOTSAM-CLASS?", "(DEFUN (JAVA-CLASS-UNIT-DEFINES-FLOTSAM-CLASS? BOOLEAN) ((CLASSUNIT TRANSLATION-UNIT)))", ((cpp_function_code)(&javaClassUnitDefinesFlotsamClassP)), NULL);
      defineFunctionObject("JAVA-OUTPUT-ALL-UNITS-TO-FILE", "(DEFUN JAVA-OUTPUT-ALL-UNITS-TO-FILE ())", ((cpp_function_code)(&javaOutputAllUnitsToFile)), NULL);
      defineFunctionObject("JAVA-INITIALIZE-FILE-TRANSLATION", "(DEFUN JAVA-INITIALIZE-FILE-TRANSLATION ())", ((cpp_function_code)(&javaInitializeFileTranslation)), NULL);
      defineFunctionObject("JAVA-TRANSLATE-FILE", "(DEFUN JAVA-TRANSLATE-FILE ((FILENAME FILE-NAME)) :PUBLIC? TRUE)", ((cpp_function_code)(&javaTranslateFile)), NULL);
      defineFunctionObject("JAVA-TRANSLATE-FILE-AS-PART-OF-SYSTEM", "(DEFUN JAVA-TRANSLATE-FILE-AS-PART-OF-SYSTEM ((FILENAME FILE-NAME)))", ((cpp_function_code)(&javaTranslateFileAsPartOfSystem)), NULL);
      defineFunctionObject("JAVA-TRANSLATE-WALKED-SYSTEM-UNITS", "(DEFUN JAVA-TRANSLATE-WALKED-SYSTEM-UNITS ((SYSTEMUNITS SYSTEM-UNITS-ALIST)))", ((cpp_function_code)(&javaTranslateWalkedSystemUnits)), NULL);
      defineFunctionObject("JAVA-TRANSLATE-SYSTEM", "(DEFUN JAVA-TRANSLATE-SYSTEM ((SYSTEMNAME STRING)) :DOCUMENTATION \"Translate the system `systemName' to Java.\" :PUBLIC? TRUE)", ((cpp_function_code)(&javaTranslateSystem)), NULL);
      defineFunctionObject("STARTUP-JAVA-TRANSLATE-FILE", "(DEFUN STARTUP-JAVA-TRANSLATE-FILE () :PUBLIC? TRUE)", ((cpp_function_code)(&startupJavaTranslateFile)), NULL);
      { MethodSlot* function = lookupFunction(SYM_JAVA_TRANSLATE_FILE_STELLA_STARTUP_JAVA_TRANSLATE_FILE);

        setDynamicSlotValue(function->dynamicSlots, SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupJavaTranslateFile"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      inModule(((StringWrapper*)(copyConsTree(wrapString("STELLA")))));
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CURRENT-JAVA-OUTPUT-CLASS* CLASS NULL :PUBLIC? FALSE :DOCUMENTATION \"Holds the current Stella class being output in Java\")");
    }
  }
}

Keyword* KWD_JAVA_TRANSLATE_FILE_COMMON_LISP = NULL;

Keyword* KWD_JAVA_TRANSLATE_FILE_JAVA = NULL;

Keyword* KWD_JAVA_TRANSLATE_FILE_MINIMIZE_JAVA_PREFIXES = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_CONSTRUCTORp = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_NATIVEp = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_MACRO = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_PRINT_METHOD = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_TYPE = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_VERBATIM = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_CLASS = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

Keyword* KWD_JAVA_TRANSLATE_FILE_TWO_PASSp = NULL;

Keyword* KWD_JAVA_TRANSLATE_FILE_FORCE_TRANSLATIONp = NULL;

Keyword* KWD_JAVA_TRANSLATE_FILE_PRODUCTION_SETTINGSp = NULL;

Symbol* SYM_JAVA_TRANSLATE_FILE_STELLA_STARTUP_JAVA_TRANSLATE_FILE = NULL;

} // end of namespace stella
