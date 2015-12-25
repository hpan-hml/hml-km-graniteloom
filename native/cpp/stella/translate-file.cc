//  -*- Mode: C++ -*-

// translate-file.cc

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

// If `true', record object signatures into a persistent table.
boolean oRECORD_SIGNATURESpo = false;

// If `true', the walker will try to find previously recorded
// signatures for referenced but undefined functions, methods, etc.
boolean oWALK_WITH_RECORDED_SIGNATURESpo = false;

// If `true', `safe-lookup-slot' and `lookup-function' will
// try to retrieve a previously recorded signature if normal lookup fails.
DEFINE_STELLA_SPECIAL(oUSERECORDEDSIGNATURESpo, boolean , false);

DEFINE_STELLA_SPECIAL(oROOTSOURCEDIRECTORYo, char* , "PL:sources;");

DEFINE_STELLA_SPECIAL(oROOTNATIVEDIRECTORYo, char* , "PL:native;");

DEFINE_STELLA_SPECIAL(oROOTBINARYDIRECTORYo, char* , "PL:bin;");

// Points to the directory containing the SYSTEMS file.
DEFINE_STELLA_SPECIAL(oSYSTEMDEFINITIONSDIRECTORYo, char* , NULL);

char* rootSourceDirectory() {
  return (translateLogicalPathname(oROOTSOURCEDIRECTORYo));
}

char* rootNativeDirectory() {
  return (translateLogicalPathname(oROOTNATIVEDIRECTORYo));
}

char* rootBinaryDirectory() {
  return (translateLogicalPathname(oROOTBINARYDIRECTORYo));
}

char* systemDefinitionsDirectory() {
  if (oSYSTEMDEFINITIONSDIRECTORYo != NULL) {
    return (translateLogicalPathname(oSYSTEMDEFINITIONSDIRECTORYo));
  }
  else {
    return (stringConcatenate(rootSourceDirectory(), "systems", 0));
  }
}

// Points to the current system.
DEFINE_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition* , NULL);

// Points to a path from the root directory down
// to a local directory containing sources, natives, or binaries.
DEFINE_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char* , "");

boolean handleInModuleTree(Cons* tree, boolean seeninmoduleP, boolean erroroninmoduleP, boolean& _Return1) {
  { Object* operatoR = tree->value;
    Object* firstarg = NULL;

    if (subtypeOfSymbolP(safePrimaryType(operatoR))) {
      { Object* operator000 = operatoR;
        Symbol* operatoR = ((Symbol*)(operator000));

        { char* testValue000 = (oMODULEo->caseSensitiveP ? stringUpcase(operatoR->symbolName) : operatoR->symbolName);

          if (stringEqlP(testValue000, "IN-PACKAGE")) {
            _Return1 = seeninmoduleP;
            return (true);
          }
          else if (stringEqlP(testValue000, "IN-MODULE")) {
            if (seeninmoduleP &&
                erroroninmoduleP) {
              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                signalTranslationError();
                if (!(suppressWarningsP())) {
                  printErrorContext(">> ERROR: ", STANDARD_ERROR);
                  *(STANDARD_ERROR->nativeStream) << std::endl << " " << "Additional IN-MODULE declaration: " << "`" << deUglifyParseTree(tree) << "'" << "." << std::endl;
                }
              }
              _Return1 = seeninmoduleP;
              return (false);
            }
            firstarg = tree->rest->value;
            if (subtypeOfStringP(safePrimaryType(firstarg))) {
              { Object* firstarg000 = firstarg;
                StringWrapper* firstarg = ((StringWrapper*)(firstarg000));

                stringChangeModule(firstarg->wrapperValue);
                seeninmoduleP = true;
              }
            }
            else {
              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                signalTranslationWarning();
                if (!(suppressWarningsP())) {
                  printErrorContext(">> WARNING: ", STANDARD_WARNING);
                  *(STANDARD_WARNING->nativeStream) << std::endl << " " << "Ignoring illegal IN-MODULE declaration: " << "`" << deUglifyParseTree(tree) << "'" << "." << std::endl;
                }
              }
            }
            _Return1 = seeninmoduleP;
            return (false);
          }
          else if (stringEqlP(testValue000, "DEFMODULE") ||
              stringEqlP(testValue000, "VERBATIM")) {
          }
          else {
            if (!(seeninmoduleP)) {
              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, true);
                signalTranslationWarning();
                if (!(suppressWarningsP())) {
                  printErrorContext(">> WARNING: ", STANDARD_WARNING);
                  *(STANDARD_WARNING->nativeStream) << std::endl << " " << "Missing IN-MODULE declaration, translating " << "into module STELLA" << "." << std::endl;
                }
              }
              stringChangeModule("STELLA");
              seeninmoduleP = true;
            }
          }
        }
      }
    }
    else {
    }
    _Return1 = seeninmoduleP;
    return (false);
  }
}

void translateAndOutputUnitsToFile(char* file, char* targetlanguage) {
  oTRANSLATIONPHASEo = KWD_TRANSLATE_FILE_TRANSLATE;
  if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_JAVA) {
  }
  else {
    if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
      std::cout << "Translating " << "`" << file << "'" << " to " << "`" << targetlanguage << "'" << "..." << std::endl;
    }
    translateAllUnits();
  }
  outputAllUnitsToFile(file);
}

void operateOnFile(char* file, Keyword* operation) {
  { char* targetlanguage = oTRANSLATOROUTPUTLANGUAGEo->symbolName;
    Module* currentmodule = oMODULEo;
    Context* currentcontext = oCONTEXTo;
    boolean seeninmoduleP = false;
    boolean skipP = false;

    file = translateLogicalPathname(file);
    if (!((boolean)(operation))) {
      operation = KWD_TRANSLATE_FILE_TRANSLATE;
    }
    { 
      BIND_STELLA_SPECIAL(oTRANSLATIONPHASEo, Keyword*, NULL);
      BIND_STELLA_SPECIAL(oTRANSLATIONERRORSo, int, 0);
      BIND_STELLA_SPECIAL(oTRANSLATIONWARNINGSo, int, 0);
      BIND_STELLA_SPECIAL(oTRANSLATIONNOTESo, int, 0);
      BIND_STELLA_SPECIAL(oCURRENTFILEo, char*, fileBaseName(file));
      BIND_STELLA_SPECIAL(oMODULEo, Module*, currentmodule);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, currentcontext);
      if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_COMMON_LISP) {
        targetlanguage = "Common Lisp";
      }
      else if ((oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP) ||
          (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP_STANDALONE)) {
        targetlanguage = "C++";
      }
      else if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_IDL) {
        targetlanguage = "IDL";
      }
      else if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_JAVA) {
        targetlanguage = "Java";
      }
      else {
      }
      if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
        std::cout << "Processing " << "`" << file << "'" << ":" << std::endl;
        std::cout << "*** Pass 1, generating objects..." << std::endl;
      }
      { 
        BIND_STELLA_SPECIAL(oTRANSIENTOBJECTSpo, boolean, true);
        { Object* tree = NULL;
          SExpressionIterator* iter000 = sExpressions(newInputFileStream(file));

          for (tree, iter000; iter000->nextP(); ) {
            tree = iter000->value;
            { 
              BIND_STELLA_SPECIAL(oTRANSIENTOBJECTSpo, boolean, false);
              if (safePrimaryType(tree) == SGT_TRANSLATE_FILE_STELLA_CONS) {
                { Object* tree000 = tree;
                  Cons* tree = ((Cons*)(tree000));

                  skipP = handleInModuleTree(tree, seeninmoduleP, true, seeninmoduleP);
                  if (!(skipP)) {
                    { 
                      BIND_STELLA_SPECIAL(oTRANSLATIONPHASEo, Keyword*, KWD_TRANSLATE_FILE_DEFINE);
                      walkTopLevelTree(tree, true);
                    }
                  }
                }
              }
              else {
              }
            }
          }
        }
      }
      oTRANSLATIONUNITSo->reverse();
      if (!(operation == KWD_TRANSLATE_FILE_DEFINE)) {
        if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
          std::cout << "*** Pass 2, finalizing objects..." << std::endl;
        }
        oTRANSLATIONPHASEo = KWD_TRANSLATE_FILE_FINALIZE;
        finalizeClassesAndSlots();
        if (!(operation == KWD_TRANSLATE_FILE_FINALIZE)) {
          if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
            std::cout << "*** Pass 3, walking objects..." << std::endl;
          }
          oTRANSLATIONPHASEo = KWD_TRANSLATE_FILE_WALK;
          if (!(useHardcodedSymbolsP() ||
              (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_JAVA))) {
            clearSymbolRegistry();
          }
          { 
            BIND_STELLA_SPECIAL(oUSERECORDEDSIGNATURESpo, boolean, oWALK_WITH_RECORDED_SIGNATURESpo);
            walkAllPhaseOneUnits();
          }
          if (!(operation == KWD_TRANSLATE_FILE_WALK)) {
            translateAndOutputUnitsToFile(file, targetlanguage);
          }
          if (oRECORD_SIGNATURESpo) {
            std::cout << "Recording object signatures..." << std::endl;
            recordSignaturesOfAllUnits(file);
          }
        }
      }
      summarizeTranslationErrors();
    }
  }
}

void cleanUpTranslationUnitsSpecial() {
  { TranslationUnit* unit = NULL;
    Cons* iter000 = oTRANSLATIONUNITSo->theConsList;

    for (unit, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
      unit = ((TranslationUnit*)(iter000->value));
      unit->free();
    }
  }
  oTRANSLATIONUNITSo->clear();
  sweepTransients();
}

void translateFile(char* file, Keyword* outputlanguage, boolean aspartofsystemP) {
  { Keyword* mode = KWD_TRANSLATE_FILE_TRANSLATE;

    { 
      BIND_STELLA_SPECIAL(oJAVA_INDENT_CHARSo, int, 0);
      BIND_STELLA_SPECIAL(oIDL_INDENT_CHARSo, int, 0);
      BIND_STELLA_SPECIAL(oCPP_INDENT_CHARSo, int, 0);
      if (outputlanguage == KWD_TRANSLATE_FILE_JAVA) {
        if (aspartofsystemP) {
          mode = KWD_TRANSLATE_FILE_WALK;
        }
      }
      else {
      }
      if (aspartofsystemP) {
        operateOnFile(file, mode);
      }
      else {
        { 
          BIND_STELLA_SPECIAL(oTRANSLATOROUTPUTLANGUAGEo, Keyword*, oTRANSLATOROUTPUTLANGUAGEo);
          BIND_STELLA_SPECIAL(oTRANSLATIONUNITSo, List*, newList());
          setTranslatorOutputLanguage(outputlanguage);
          operateOnFile(file, mode);
          if (outputlanguage == KWD_TRANSLATE_FILE_CPP_STANDALONE) {
          }
          else {
            cleanUpTranslationUnitsSpecial();
          }
        }
      }
    }
  }
}

void outputAllUnitsToFile(char* sourcefile) {
  if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_COMMON_LISP) {
    clOutputAllUnitsToFile(sourcefile);
  }
  else if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_JAVA) {
    { 
      BIND_STELLA_SPECIAL(oJAVA_INDENT_CHARSo, int, 0);
      javaOutputAllUnitsToFile();
    }
  }
  else if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_IDL) {
    { 
      BIND_STELLA_SPECIAL(oIDL_INDENT_CHARSo, int, 0);
      idlOutputAllUnitsToFile(sourcefile);
    }
  }
  else if ((oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP) ||
      (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP_STANDALONE)) {
    { 
      BIND_STELLA_SPECIAL(oCPP_INDENT_CHARSo, int, 0);
      cppOutputAllUnitsToFile(sourcefile);
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << oTRANSLATOROUTPUTLANGUAGEo << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

void recordSignaturesOfAllUnits(char* sourcefile) {
  sourcefile = sourcefile;
}

boolean translateWithCopyrightHeaderP() {
  return (oCURRENT_STELLA_FEATURESo->membP(KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER));
}

void outputCopyrightHeader(OutputStream* stream) {
  if ((!translateWithCopyrightHeaderP()) ||
      ((!((boolean)(oCURRENTSYSTEMDEFINITIONo))) ||
       (oCURRENTSYSTEMDEFINITIONo->banner == NULL))) {
    return;
  }
  if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_COMMON_LISP) {
    *(stream->nativeStream) << "#|" << std::endl;
  }
  else if ((oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_JAVA) ||
      ((oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP) ||
       (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP_STANDALONE))) {
    *(stream->nativeStream) << "/*" << std::endl;
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << oTRANSLATOROUTPUTLANGUAGEo << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  { KeyValueList* substitutionList = newKeyValueList();
    InputStringStream* bstream = makeTokenizerStringStream(oCURRENTSYSTEMDEFINITIONo->banner);

    fillInDateSubstitution(substitutionList);
    substituteTemplateVariablesToStream(bstream, stream, substitutionList);
  }
  if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_COMMON_LISP) {
    *(stream->nativeStream) << "|#";
  }
  else if ((oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_JAVA) ||
      ((oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP) ||
       (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP_STANDALONE))) {
    *(stream->nativeStream) << "*/";
  }
  else {
    { OutputStringStream* stream001 = newOutputStringStream();

      *(stream001->nativeStream) << "`" << oTRANSLATOROUTPUTLANGUAGEo << "'" << " is not a valid case option";
      throw *newStellaException(stream001->theStringReader());
    }
  }
  *(stream->nativeStream) << std::endl << std::endl;
}

void outputFileHeader(OutputStream* stream, char* file) {
  if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_COMMON_LISP) {
    clOutputFileHeader(stream, file, true);
  }
  else if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_JAVA) {
    javaOutputFileHeader(stream, file);
  }
  else if (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_CPP) {
    cppOutputFileHeader(stream, file);
  }
  else {
    clOutputFileHeader(stream, file, false);
  }
}

// The operating system we are running on.  Currently,
// either :UNIX, :WINDOWS, or :MAC.  Note that on the Mac OS X, the
// OS can be either :UNIX or :MAC, depending on which file naming 
// conventions are being observed by the software.
Keyword* oOSo = NULL;

Keyword* operatingSystem() {
  if (probeFileP("C:\\AUTOEXEC.BAT") ||
      (probeFileP("C:\\IO.SYS") ||
       (probeFileP("C:\\BOOT.INI") ||
        startsWithP("", "win", 0)))) {
    return (KWD_TRANSLATE_FILE_WINDOWS);
  }
  else if (probeFileP("/usr") ||
      probeFileP("/etc")) {
    return (KWD_TRANSLATE_FILE_UNIX);
  }
  else {
    return (KWD_TRANSLATE_FILE_MAC);
  }
}

char directorySeparator() {
  { char separator = '?';

    if (((boolean)(oOSo))) {
      if (oOSo == KWD_TRANSLATE_FILE_UNIX) {
        separator = '/';
      }
      else if (oOSo == KWD_TRANSLATE_FILE_MAC) {
        separator = ':';
      }
      else if (oOSo == KWD_TRANSLATE_FILE_WINDOWS) {
        separator = '\\';
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << oOSo << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    return (separator);
  }
}

char* directorySeparatorString() {
  return (makeString(1, directorySeparator()));
}

char directorySeparatorForFile(char* file) {
  if (logicalPathnameP(file)) {
    return (LOGICAL_DIRECTORY_SEPARATOR);
  }
  else {
    return (directorySeparator());
  }
}

char TYPE_SEPARATOR = '.';

char* fileNameDirectory(char* file) {
  // Return the directory component of `file' including the final
  // directory separator or the empty string if `file' does not include a directory.
  // Note that for purposes of this function, a logical host is considered part of
  // the directory portion of `file'
  { int start = 0;
    int length = strlen(file);
    char separator = directorySeparatorForFile(file);

    if (logicalPathnameP(file)) {
      start = stringPosition(file, LOGICAL_HOST_SEPARATOR, 0) + 1;
    }
    while ((start < length) &&
        (stringPosition(file, separator, start) != NULL_INTEGER)) {
      start = stringPosition(file, separator, start) + 1;
    }
    return (stringSubsequence(file, 0, start));
  }
}

char* directoryFileName(char* directory) {
  // Return `directory' as a file name, i.e., without a terminating
  // directory separator.
  { char separator = directorySeparatorForFile(directory);
    int last = strlen(directory) - 1;

    if ((last >= 0) &&
        (directory[last] == separator)) {
      return (stringSubsequence(directory, 0, last));
    }
    else {
      return (directory);
    }
  }
}

char* fileNameAsDirectory(char* file) {
  // Return `file' interpreted as a directory, i.e., with a
  // terminating directory separator.  If `file' is the empty string simply
  // return the empty string, i.e., interpret it as the current directory instead
  // of the root directory.
  { char separator = directorySeparatorForFile(file);
    int last = strlen(file) - 1;

    if ((last < 0) ||
        (file[last] == separator)) {
      return (file);
    }
    else {
      return (stringConcatenate(file, makeString(1, separator), 0));
    }
  }
}

char* directoryParentDirectory(char* directory, int level) {
  // Return the `level'-th parent directory component of `directory'
  // including the final directory separator, or the empty string if `directory' does
  // not have that many parents.
  { int i = NULL_INTEGER;
    int iter000 = 1;
    int upperBound000 = level;
    boolean unboundedP000 = upperBound000 == NULL_INTEGER;

    for  (i, iter000, upperBound000, unboundedP000; 
          unboundedP000 ||
              (iter000 <= upperBound000); 
          iter000 = iter000 + 1) {
      i = iter000;
      i = i;
      directory = fileNameDirectory(directoryFileName(directory));
    }
  }
  return (directory);
}

char* fileNameWithoutDevice(char* file) {
  // Return the file name portion of `file' by removing any
  // physical device components.  This is just like `logical-pathname-without-host'
  // but only looks for one-character device strings as used in Windows.
  { char separator = ':';

    if ((strlen(file) >= 2) &&
        ((file[1] == separator) &&
         (oCHARACTER_TYPE_TABLEo[(int)(unsigned char) (file[0])] == KWD_TRANSLATE_FILE_LETTER))) {
      return (stringSubsequence(file, 2, NULL_INTEGER));
    }
    else {
      return (file);
    }
  }
}

char* fileNameWithoutDirectory(char* file) {
  // Return the file name portion of `file' by removing any
  // directory and logical host components.
  { int start = 0;
    char separator = directorySeparatorForFile(file);

    if (separator == LOGICAL_HOST_SEPARATOR) {
      file = logicalPathnameWithoutHost(file);
    }
    else {
      file = fileNameWithoutDevice(file);
    }
    while (stringPosition(file, separator, start) != NULL_INTEGER) {
      start = stringPosition(file, separator, start) + 1;
    }
    return (stringSubsequence(file, start, NULL_INTEGER));
  }
}

char* fileNameWithoutExtension(char* file) {
  // Remove `file's extension (or type) if there is any and
  // return the result.
  { int start = 0;
    int end = NULL_INTEGER;

    while (stringPosition(file, TYPE_SEPARATOR, start) != NULL_INTEGER) {
      end = stringPosition(file, TYPE_SEPARATOR, start);
      start = end + 1;
    }
    return (stringSubsequence(file, 0, end));
  }
}

char* fileExtension(char* file) {
  // Return `file's extension (or type) if it has any including
  // the separator character.
  { int start = 0;
    int end = NULL_INTEGER;

    while (stringPosition(file, TYPE_SEPARATOR, start) != NULL_INTEGER) {
      end = stringPosition(file, TYPE_SEPARATOR, start);
      start = end + 1;
    }
    if (end == NULL_INTEGER) {
      return (NULL);
    }
    else if (stringPosition(file, directorySeparatorForFile(file), end) != NULL_INTEGER) {
      return (NULL);
    }
    else {
      return (stringSubsequence(file, end, NULL_INTEGER));
    }
  }
}

char* fileBaseName(char* file) {
  // Remove `file's directory (including logical host) and
  // extension components and return the result.
  return (fileNameWithoutExtension(fileNameWithoutDirectory(file)));
}

char LOGICAL_DIRECTORY_SEPARATOR = ';';

char LOGICAL_HOST_SEPARATOR = ':';

StringHashTable* oLOGICAL_HOST_TABLEo = NULL;

void defineLogicalHostProperty(char* host, Keyword* property, Object* value) {
  // Define `property' with `value' for the logical host `host'.
  // As a side-effect, this also defines `host' as a logical host (both
  // `property' and `value' can be supplied as NULL).  If :ROOT-DIRECTORY
  // is specified, all pathnames with `host' are assumed to be relative to
  // that directory (even if they are absolute) and will be rerooted upon
  // translation.  :ROOT-DIRECTORY can be a logical or physical pathname.
  // If :LISP-TRANSLATIONS is specified, those will be used verbatimely as
  // the value of `(CL:logical-pathname-translations host)' if we are
  // running in Lisp, which allows us to depend on the native
  // `CL:translate-logical-pathname' for more complex translation operations.
  host = stringUpcase(host);
  { KeyValueList* properties = ((KeyValueList*)(oLOGICAL_HOST_TABLEo->lookup(host)));

    if (!((boolean)(properties))) {
      properties = newKeyValueList();
      oLOGICAL_HOST_TABLEo->insertAt(host, properties);
    }
    if (((boolean)(property))) {
      if (property == KWD_TRANSLATE_FILE_ROOT_DIRECTORY) {
        properties->insertAt(property, NULL);
        if (((boolean)(value))) {
          properties->insertAt(property, wrapString(translateLogicalPathname(fileNameAsDirectory(((StringWrapper*)(value))->wrapperValue))));
        }
      }
      else if (property == KWD_TRANSLATE_FILE_LISP_TRANSLATIONS) {
        properties->insertAt(property, value);
      }
      else {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal host property: " << "`" << property << "'" << std::endl;
      }
    }
  }
}

Object* lookupLogicalHostProperty(char* host, Keyword* property) {
  host = stringUpcase(host);
  { KeyValueList* properties = ((KeyValueList*)(oLOGICAL_HOST_TABLEo->lookup(host)));

    if (!((boolean)(properties))) {
      return (NULL);
    }
    else {
      return (properties->lookup(property));
    }
  }
}

boolean logicalHostP(char* host) {
  return (((boolean)(((KeyValueList*)(oLOGICAL_HOST_TABLEo->lookup(stringUpcase(host)))))));
}

boolean logicalPathnameP(char* pathname) {
  { char* host = getLogicalHostName(pathname);

    return ((host != NULL) &&
        logicalHostP(host));
  }
}

boolean absolutePathnameP(char* pathname) {
  { char separator = directorySeparator();

    if (logicalPathnameP(pathname)) {
      separator = LOGICAL_DIRECTORY_SEPARATOR;
      pathname = logicalPathnameWithoutHost(pathname);
    }
    else {
      pathname = fileNameWithoutDevice(pathname);
    }
    return ((strlen(pathname) > 0) &&
        (pathname[0] == separator));
  }
}

char* getLogicalHostName(char* pathname) {
  { int separatorpos = stringPosition(pathname, LOGICAL_HOST_SEPARATOR, 0);

    if ((separatorpos != NULL_INTEGER) &&
        (separatorpos >= 1)) {
      return (stringSubsequence(pathname, 0, separatorpos));
    }
    else {
      return (NULL);
    }
  }
}

char* logicalPathnameWithoutHost(char* pathname) {
  { char* hostname = getLogicalHostName(pathname);

    if (hostname == NULL) {
      return (pathname);
    }
    else {
      return (stringSubsequence(pathname, strlen(hostname) + 1, NULL_INTEGER));
    }
  }
}

char* translateLogicalPathname(char* pathname) {
  if (!(logicalPathnameP(pathname))) {
    return (pathname);
  }
  { char* host = getLogicalHostName(pathname);
    char* translatedpathname = pathname;

    translatedpathname = stringSubstitute(logicalPathnameWithoutHost(pathname), directorySeparator(), LOGICAL_DIRECTORY_SEPARATOR);
    { StringWrapper* rootdirectory = ((StringWrapper*)(lookupLogicalHostProperty(host, KWD_TRANSLATE_FILE_ROOT_DIRECTORY)));

      if (((boolean)(rootdirectory))) {
        if (absolutePathnameP(translatedpathname)) {
          translatedpathname = stringSubsequence(translatedpathname, 1, NULL_INTEGER);
        }
        translatedpathname = stringConcatenate(rootdirectory->wrapperValue, translatedpathname, 0);
      }
    }
    return (translatedpathname);
  }
}

char* unlogicalizePathname(char* pathname) {
  return (translateLogicalPathname(pathname));
}

char* mergeFileNames(char* basefile, char* defaults) {
  // Parse `baseFile', supply any missing components from
  // `defaults' if supplied and return the result.
  { char baseseparator = directorySeparatorForFile(basefile);
    char* basehost = getLogicalHostName(basefile);
    char* basedirectory = logicalPathnameWithoutHost(fileNameDirectory(basefile));
    char* basename = fileBaseName(basefile);
    char* baseextension = fileExtension(basefile);
    char defaultsseparator = directorySeparatorForFile(defaults);
    boolean mergedP = false;
    OutputStringStream* result = NULL;

    if ((!(baseseparator == defaultsseparator)) &&
        (stringMemberP(basefile, baseseparator) &&
         stringMemberP(defaults, defaultsseparator))) {
      throw *newStellaException("merge-file-names: base file and defaults use different syntax");
    }
    if (basehost == NULL) {
      basehost = getLogicalHostName(defaults);
      mergedP = mergedP ||
          (basehost != NULL);
    }
    if (stringEqlP(basedirectory, "")) {
      basedirectory = logicalPathnameWithoutHost(fileNameDirectory(defaults));
      mergedP = mergedP ||
          (!stringEqlP(basedirectory, ""));
    }
    if (basename == NULL) {
      basename = fileBaseName(defaults);
      mergedP = mergedP ||
          (basename != NULL);
    }
    if (baseextension == NULL) {
      baseextension = fileExtension(defaults);
      mergedP = mergedP ||
          (baseextension != NULL);
    }
    if (!mergedP) {
      return (basefile);
    }
    result = newOutputStringStream();
    if (basehost != NULL) {
      *(result->nativeStream) << basehost << LOGICAL_HOST_SEPARATOR;
    }
    *(result->nativeStream) << basedirectory;
    if (basename != NULL) {
      *(result->nativeStream) << basename;
    }
    if (baseextension != NULL) {
      *(result->nativeStream) << baseextension;
    }
    return (result->theStringReader());
  }
}

// Used by `select-file-extension'.
Cons* oTYPE_TO_FILE_EXTENSION_TABLEo = NULL;

char* computeCommonLispFileExtension(Keyword* type) {
  if (!(runningAsLispP())) {
    throw *newStellaException("Shouldn't call COMPUTE-COMMON-LISP-FILE-EXTENSION unless running in Lisp");
  }
  { char* suffix = NULL;

    if (type == KWD_TRANSLATE_FILE_LISP_BINARY) {
      suffix = NULL;
      if (oCURRENT_STELLA_FEATURESo->membP(KWD_TRANSLATE_FILE_USE_COMMON_LISP_STRUCTS)) {
        suffix = stringConcatenate("s", suffix, 0);
      }
      else if (oCURRENT_STELLA_FEATURESo->membP(KWD_TRANSLATE_FILE_USE_COMMON_LISP_VECTOR_STRUCTS)) {
        suffix = stringConcatenate("vs", suffix, 0);
      }
      else {
      }
    }
    else if (type == KWD_TRANSLATE_FILE_LISP) {
      if (oCURRENT_STELLA_FEATURESo->membP(KWD_TRANSLATE_FILE_USE_COMMON_LISP_STRUCTS)) {
        suffix = ".slisp";
      }
      else if (oCURRENT_STELLA_FEATURESo->membP(KWD_TRANSLATE_FILE_USE_COMMON_LISP_VECTOR_STRUCTS)) {
        suffix = ".vslisp";
      }
      else {
        suffix = ".lisp";
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << type << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    return (stringConcatenate(".", suffix, 0));
  }
}

char* defaultCommonLispFileExtension(Keyword* type) {
  if (type == KWD_TRANSLATE_FILE_LISP) {
    if (oOSo == KWD_TRANSLATE_FILE_WINDOWS) {
      return (".lsp");
    }
    else {
      return (".lisp");
    }
  }
  else if (type == KWD_TRANSLATE_FILE_LISP_BINARY) {
    if (oOSo == KWD_TRANSLATE_FILE_MAC) {
      return (".cfsl");
    }
    else if (oOSo == KWD_TRANSLATE_FILE_WINDOWS) {
      return (".fas");
    }
    else {
      return (".fasl");
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << type << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

char* selectFileExtension(Keyword* type) {
  { char* extension = NULL;

    { Cons* entry = NULL;
      Cons* iter000 = oTYPE_TO_FILE_EXTENSION_TABLEo;

      for (entry, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        entry = ((Cons*)(iter000->value));
        if (entry->value == type) {
          extension = ((StringWrapper*)(entry->rest->value))->wrapperValue;
        }
      }
    }
    if (type == KWD_TRANSLATE_FILE_DIRECTORY) {
      return (directorySeparatorString());
    }
    else if ((type == KWD_TRANSLATE_FILE_LISP) ||
        (type == KWD_TRANSLATE_FILE_LISP_BINARY)) {
      if (runningAsLispP()) {
        return (computeCommonLispFileExtension(type));
      }
      else {
        return (defaultCommonLispFileExtension(type));
      }
    }
    else {
    }
    return (extension);
  }
}

Keyword* classifyFileExtension(char* file) {
  { char* extension = fileExtension(file);

    if (extension == NULL) {
      return (KWD_TRANSLATE_FILE_NONE);
    }
    { Cons* entry = NULL;
      Cons* iter000 = oTYPE_TO_FILE_EXTENSION_TABLEo;

      for (entry, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        entry = ((Cons*)(iter000->value));
        if (eqlToStringP(entry->rest->value, extension)) {
          return (((Keyword*)(entry->value)));
        }
      }
    }
    if (runningAsLispP()) {
      if (stringEqlP(computeCommonLispFileExtension(KWD_TRANSLATE_FILE_LISP), extension)) {
        return (KWD_TRANSLATE_FILE_LISP);
      }
      if (stringEqlP(computeCommonLispFileExtension(KWD_TRANSLATE_FILE_LISP_BINARY), extension)) {
        return (KWD_TRANSLATE_FILE_LISP_BINARY);
      }
    }
    if (stringEqlP(defaultCommonLispFileExtension(KWD_TRANSLATE_FILE_LISP), extension)) {
      return (KWD_TRANSLATE_FILE_LISP);
    }
    if (stringEqlP(defaultCommonLispFileExtension(KWD_TRANSLATE_FILE_LISP_BINARY), extension)) {
      return (KWD_TRANSLATE_FILE_LISP_BINARY);
    }
    return (KWD_TRANSLATE_FILE_OTHER);
  }
}

char* selectRootDirectory(Keyword* type) {
  { char* root = NULL;

    if ((type == KWD_TRANSLATE_FILE_STELLA) ||
        (type == KWD_TRANSLATE_FILE_KB)) {
      root = rootSourceDirectory();
    }
    else if ((type == KWD_TRANSLATE_FILE_LISP_BINARY) ||
        (type == KWD_TRANSLATE_FILE_DIRECTORY)) {
      root = rootBinaryDirectory();
    }
    else {
      root = rootNativeDirectory();
    }
    return (root);
  }
}

char* oLISP_SPLITTER_PATHo = "lisp";

char* oJAVA_SPLITTER_PATHo = "java";

char* oCPP_SPLITTER_PATHo = "cpp";

char* selectSplitterPath(Keyword* type) {
  { char* splitterpath = "";

    if ((type == KWD_TRANSLATE_FILE_LISP) ||
        (type == KWD_TRANSLATE_FILE_COMMON_LISP)) {
      splitterpath = oLISP_SPLITTER_PATHo;
    }
    else if (type == KWD_TRANSLATE_FILE_JAVA) {
      splitterpath = oJAVA_SPLITTER_PATHo;
    }
    else if ((type == KWD_TRANSLATE_FILE_CPP) ||
        ((type == KWD_TRANSLATE_FILE_CPP_HEADER) ||
         ((type == KWD_TRANSLATE_FILE_CPP_CODE) ||
          ((type == KWD_TRANSLATE_FILE_C_HEADER) ||
           (type == KWD_TRANSLATE_FILE_C_CODE))))) {
      splitterpath = oCPP_SPLITTER_PATHo;
    }
    else if ((type == KWD_TRANSLATE_FILE_NONE) ||
        (type == KWD_TRANSLATE_FILE_OTHER)) {
      return (selectSplitterPath(oTRANSLATOROUTPUTLANGUAGEo));
    }
    else {
    }
    if (!stringEqlP(splitterpath, "")) {
      splitterpath = stringConcatenate(splitterpath, directorySeparatorString(), 0);
    }
    return (splitterpath);
  }
}

char* makeFileNameFromRelativePath(Object* filepath, Keyword* type) {
  return (makeFileName(implodePathname(filepath), type, true));
}

char* rootDirectoryPrefix(char* file) {
  { char* extension = fileExtension(file);

    if (stringEqlP(extension, ".ste")) {
      return (rootSourceDirectory());
    }
    else if (stringEqlP(extension, ".lisp") ||
        (stringEqlP(extension, ".java") ||
         (stringEqlP(extension, ".cc") ||
          stringEqlP(extension, ".hh")))) {
      return (rootNativeDirectory());
    }
    else {
      return (rootNativeDirectory());
    }
  }
}

char* makeFileName(char* filepath, Keyword* type, boolean relativeP) {
  { char* extension = selectFileExtension(type);
    char* rootpath = "";
    char* splitterpath = "";
    char* subdirectory = "";

    if (relativeP) {
      rootpath = selectRootDirectory(type);
      splitterpath = selectSplitterPath(type);
      if (!(type == KWD_TRANSLATE_FILE_OTHER)) {
        filepath = fileNameWithoutExtension(filepath);
      }
      if ((type == KWD_TRANSLATE_FILE_JAVA) ||
          (((type == KWD_TRANSLATE_FILE_OTHER) ||
          (type == KWD_TRANSLATE_FILE_NONE)) &&
           (oTRANSLATOROUTPUTLANGUAGEo == KWD_TRANSLATE_FILE_JAVA))) {
        subdirectory = javaPackagePrefix(oMODULEo, directorySeparatorString());
      }
      else {
        if (!stringEqlP(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, "")) {
          subdirectory = stringConcatenate(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, directorySeparatorString(), 0);
        }
      }
    }
    else {
      { char* rootprefix = rootDirectoryPrefix(filepath);

        if (!(type == KWD_TRANSLATE_FILE_OTHER)) {
          filepath = fileNameWithoutExtension(filepath);
        }
        if (!getQuotedTree("((:STELLA :KB) \"/STELLA\")", "/STELLA")->memberP(type)) {
          { char* relativepath = relativizeFileName(filepath, rootprefix);

            if (!stringEqlP(filepath, relativepath)) {
              rootpath = selectRootDirectory(type);
              splitterpath = selectSplitterPath(type);
              filepath = relativepath;
            }
          }
        }
      }
    }
    return (stringConcatenate(rootpath, splitterpath, 3, subdirectory, filepath, extension));
  }
}

char* relativizeFileName(char* file, char* rootpath) {
  { boolean absoluteP = stringSearch(file, rootpath, 0) == 0;

    if (absoluteP) {
      return (stringSubsequence(file, strlen(rootpath), NULL_INTEGER));
    }
    else {
      return (file);
    }
  }
}

char* helpImplodePathname(char* filename) {
  { char* extension = fileExtension(filename);

    if (extension == NULL) {
      return (maybeTruncateFilename(filename));
    }
    else {
      return (stringConcatenate(maybeTruncateFilename(fileBaseName(filename)), extension, 0));
    }
  }
}

char* implodePathname(Object* filepath) {
  { char* file = NULL;

    if (safePrimaryType(filepath) == SGT_TRANSLATE_FILE_STELLA_CONS) {
      { Object* filepath000 = filepath;
        Cons* filepath = ((Cons*)(filepath000));

        { int pathLength = filepath->length();

          file = "";
          { StringWrapper* name = NULL;
            Cons* iter000 = ((Cons*)(filepath));
            int n = NULL_INTEGER;
            int iter001 = 1;
            int upperBound000 = pathLength;
            boolean unboundedP000 = upperBound000 == NULL_INTEGER;

            for  (name, iter000, n, iter001, upperBound000, unboundedP000; 
                  (!(iter000 == NIL)) &&
                      (unboundedP000 ||
                       (iter001 <= upperBound000)); 
                  iter000 = iter000->rest,
                  iter001 = iter001 + 1) {
              name = ((StringWrapper*)(iter000->value));
              n = iter001;
              if (n == pathLength) {
                file = stringConcatenate(file, helpImplodePathname(name->wrapperValue), 0);
              }
              else {
                file = stringConcatenate(file, name->wrapperValue, 1, directorySeparatorString());
              }
            }
          }
        }
      }
    }
    else {
      file = helpImplodePathname(((StringWrapper*)(filepath))->wrapperValue);
    }
    return (file);
  }
}

// When TRUE, overrides normal truncation of file names.
DEFINE_STELLA_SPECIAL(oDONTTRUNCATEFILENAMESpo, boolean , false);

char* maybeTruncateFilename(char* barefilename) {
  if (oDONTTRUNCATEFILENAMESpo) {
    return (barefilename);
  }
  { int maximumlength = 999;

    if (oOSo == KWD_TRANSLATE_FILE_MAC) {
      maximumlength = 31 - 5;
    }
    else {
    }
    if (strlen(barefilename) > maximumlength) {
      { char* originalfilename = barefilename;

        barefilename = stringSubsequence(barefilename, 0, maximumlength - 1);
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Truncating name of file." << std::endl << "   Original: " << "`" << originalfilename << "'" << "    Truncated: " << "`" << barefilename << "'" << std::endl << std::endl;
      }
    }
    return (barefilename);
  }
}

Keyword* languageToFileType(Keyword* language) {
  if (language == KWD_TRANSLATE_FILE_COMMON_LISP) {
    return (KWD_TRANSLATE_FILE_LISP);
  }
  else if (language == KWD_TRANSLATE_FILE_CPP) {
    return (KWD_TRANSLATE_FILE_CPP_CODE);
  }
  else {
    return (language);
  }
}

char* rerootFileName(char* file, char* fromroot, char* toroot) {
  { boolean absoluteP = stringSearch(file, fromroot, 0) == 0;

    if (absoluteP) {
      if (stringEqlP(fromroot, toroot)) {
        return (file);
      }
      else {
        return (stringConcatenate(toroot, stringSubsequence(file, strlen(fromroot), NULL_INTEGER), 0));
      }
    }
    else {
      return (stringConcatenate(toroot, file, 0));
    }
  }
}

BooleanWrapper* fileYoungerThanP(char* file1, char* file2) {
  if ((!probeFileP(file1)) ||
      (!probeFileP(file2))) {
    return (NULL);
  }
  else {
    { CalendarDate* file1Date = fileWriteDate(file1);
      CalendarDate* file2Date = fileWriteDate(file2);

      if ((!((boolean)(file1Date))) ||
          (!((boolean)(file2Date)))) {
        return (NULL);
      }
      else {
        return ((file1Date->greaterEqualP(file2Date) ? TRUE_WRAPPER : FALSE_WRAPPER));
      }
    }
  }
}

boolean stellaNeedToTranslateP(Object* file, Keyword* language) {
  if (language == KWD_TRANSLATE_FILE_JAVA) {
    return (true);
  }
  { char* sourcefile = makeFileName(((StringWrapper*)(file))->wrapperValue, KWD_TRANSLATE_FILE_STELLA, true);
    char* translatedfile = makeFileName(((StringWrapper*)(file))->wrapperValue, languageToFileType(language), true);

    return (probeFileP(sourcefile) &&
        (!(fileYoungerThanP(translatedfile, sourcefile) == TRUE_WRAPPER)));
  }
}

boolean stellaNeedToCompileP(Object* file) {
  { char* sourcefile = makeFileName(((StringWrapper*)(file))->wrapperValue, KWD_TRANSLATE_FILE_LISP, true);
    char* compiledfile = makeFileName(((StringWrapper*)(file))->wrapperValue, KWD_TRANSLATE_FILE_LISP_BINARY, true);

    return (!(fileYoungerThanP(compiledfile, sourcefile) == TRUE_WRAPPER));
  }
}

boolean systemNeedsTranslationP(char* systemname, Keyword* language) {
  { 
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition(systemname));
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo)) ? oCURRENTSYSTEMDEFINITIONo->directory : NULL));
    if (((boolean)(oCURRENTSYSTEMDEFINITIONo))) {
      {
        { boolean foundP000 = false;

          { StringWrapper* file = NULL;
            Cons* iter000 = systemDefinitionSourceFiles(oCURRENTSYSTEMDEFINITIONo);

            for (file, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
              file = ((StringWrapper*)(iter000->value));
              if (stellaNeedToTranslateP(file, language)) {
                foundP000 = true;
                break;
              }
            }
          }
          if (foundP000) {
            return (true);
          }
        }
        { char* startupFile = systemStartupFileName(NULL);

          if (!(probeFileP(makeFileName(startupFile, KWD_TRANSLATE_FILE_STELLA, true)))) {
            return (true);
          }
          return (stellaNeedToTranslateP(wrapString(startupFile), language));
        }
      }
    }
    else {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "`" << systemname << "'" << std::endl << std::endl;
    }
  }
  return (false);
}

Module* computeFileUnitsModule(List* fileunits) {
  { TranslationUnit* unit = NULL;
    Cons* iter000 = fileunits->theConsList;

    for (unit, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
      unit = ((TranslationUnit*)(iter000->value));
      if (((boolean)(unit->tuHomeModule))) {
        return (unit->tuHomeModule);
      }
    }
  }
  return (oMODULEo);
}

List* concatenateSystemUnits(KeyValueList* systemunits) {
  { Cons* head = cons(NULL, NIL);
    Cons* cursor = head;

    { StringWrapper* file = NULL;
      List* units = NULL;
      KvCons* iter000 = systemunits->theKvList;

      for  (file, units, iter000; 
            ((boolean)(iter000)); 
            iter000 = iter000->rest) {
        file = ((StringWrapper*)(iter000->key));
        units = ((List*)(iter000->value));
        file = file;
        if (units->nonEmptyP()) {
          cursor->concatenate(units->theConsList, 0);
          cursor = units->theConsList;
        }
      }
    }
    { List* self000 = newList();

      self000->theConsList = head->rest;
      { List* value000 = self000;

        return (value000);
      }
    }
  }
}

boolean translateSystem(char* systemname, Cons* languageAoptions) {
  // Translate all of the STELLA source files in system `systemName' into
  // `language' (the optional first argument).  The following keyword/value
  // `options' are recognized:
  // 
  // `:language': can be used as an alternative to the optional language argument.
  // If not specified, the language of the running implementation is assumed.
  // 
  // `:two-pass?' (default false): if true, all files will be scanned twice, once
  // to load the signatures of objects defined in them, and once to actually
  // translate the definitions.
  // 
  // `:force-translation?' (default false): if true, files will be translated
  // whether or not their translations are up-to-date.
  // 
  // `:development-settings?' (default false): if true translation will favor
  // safe, readable and debuggable code over efficiency (according to the value
  // of `:development-settings' on the system definition).  If false, efficiency
  // will be favored instead (according to the value of `:production-settings'
  // on the system definition).
  // 
  // `:production-settings?' (default true): inverse to `:development-settings?'.
  { Cons* options = languageAoptions;
    Keyword* language = (getQuotedTree("((:COMMON-LISP :CPP :JAVA) \"/STELLA\")", "/STELLA")->memberP(options->value) ? ((Keyword*)(options->value)) : runningInLanguage());
    PropertyList* plist = vetOptions(((options->value == language) ? options->rest : options), getQuotedTree("((:TWO-PASS? :FORCE-TRANSLATION? :PRODUCTION-SETTINGS? :DEVELOPMENT-SETTINGS? :LANGUAGE :ACTION) \"/STELLA\")", "/STELLA"));
    boolean twopassP = false;
    boolean forcetranslationP = false;
    boolean productionmodeP = true;

    language = ((Keyword*)(plist->lookupWithDefault(KWD_TRANSLATE_FILE_LANGUAGE, language)));
    plist->insertAt(KWD_TRANSLATE_FILE_LANGUAGE, language);
    plist->insertAt(KWD_TRANSLATE_FILE_ACTION, plist->lookupWithDefault(KWD_TRANSLATE_FILE_ACTION, KWD_TRANSLATE_FILE_TRANSLATE_SYSTEM));
    { Object* key = NULL;
      Object* value = NULL;
      Cons* iter000 = plist->thePlist;

      for  (key, value, iter000; 
            !(iter000 == NIL); 
            iter000 = iter000->rest->rest) {
        key = iter000->value;
        value = iter000->rest->value;
        { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(key));

          if (testValue000 == KWD_TRANSLATE_FILE_TWO_PASSp) {
            twopassP = eqlP(value, TRUE_WRAPPER);
          }
          else if (testValue000 == KWD_TRANSLATE_FILE_FORCE_TRANSLATIONp) {
            forcetranslationP = eqlP(value, TRUE_WRAPPER);
          }
          else if (testValue000 == KWD_TRANSLATE_FILE_PRODUCTION_SETTINGSp) {
            productionmodeP = eqlP(value, TRUE_WRAPPER);
          }
          else if (testValue000 == KWD_TRANSLATE_FILE_DEVELOPMENT_SETTINGSp) {
            productionmodeP = !eqlP(value, TRUE_WRAPPER);
          }
          else {
          }
        }
      }
    }
    { 
      BIND_STELLA_SPECIAL(oTRANSLATOROUTPUTLANGUAGEo, Keyword*, oTRANSLATOROUTPUTLANGUAGEo);
      BIND_STELLA_SPECIAL(oTRANSLATIONPHASEo, Keyword*, NULL);
      BIND_STELLA_SPECIAL(oSAFETYo, int, oSAFETYo);
      BIND_STELLA_SPECIAL(oRECYCLING_ENABLEDpo, boolean, !(language == KWD_TRANSLATE_FILE_JAVA));
      BIND_STELLA_SPECIAL(oCURRENT_STELLA_FEATURESo, List*, oCURRENT_STELLA_FEATURESo->copy());
      BIND_STELLA_SPECIAL(oCURRENT_SYSTEM_ACTIONo, PropertyList*, plist->copy());
      if (!systemLoadedOrStartedUpP(systemname)) {
        twopassP = true;
      }
      oGENSYM_COUNTERo = -1;
      setStellaFeature(consList(3, KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER, KWD_TRANSLATE_FILE_WARN_ABOUT_MISSING_METHODS, KWD_TRANSLATE_FILE_WARN_ABOUT_UNDEFINED_METHODS));
      unsetStellaFeature(consList(1, KWD_TRANSLATE_FILE_USE_HARDCODED_SYMBOLS));
      setTranslatorOutputLanguage(language);
      { 
        BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition(systemname));
        BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo)) ? oCURRENTSYSTEMDEFINITIONo->directory : NULL));
        if (((boolean)(oCURRENTSYSTEMDEFINITIONo))) {
          {
            computeOptimizationLevels(oCURRENTSYSTEMDEFINITIONo, productionmodeP);
            { Cons* files = filesPlusSystemStartup(systemDefinitionSourceFiles(oCURRENTSYSTEMDEFINITIONo));
              boolean translatedsomethingP = false;

              if (forcetranslationP ||
                  systemNeedsTranslationP(systemname, language)) {
                createSystemStartupFile(oCURRENTSYSTEMDEFINITIONo);
                translatedsomethingP = helpTranslateSystem(files, twopassP, forcetranslationP);
              }
              transferNativeSystemFiles(language);
              transferDataFiles(language);
              return (translatedsomethingP);
            }
          }
        }
        else {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "`" << systemname << "'" << std::endl << std::endl;
        }
      }
      return (false);
    }
  }
}

BooleanWrapper* translateSystemEvaluatorWrapper(Cons* arguments) {
  return ((translateSystem(((StringWrapper*)(arguments->value))->wrapperValue, arguments->rest) ? TRUE_WRAPPER : FALSE_WRAPPER));
}

boolean helpTranslateSystem(Cons* files, boolean twopassP, boolean forcetranslationP) {
  { 
    BIND_STELLA_SPECIAL(oTRANSLATIONUNITSo, List*, newList());
    { Keyword* outputlanguage = oTRANSLATOROUTPUTLANGUAGEo;
      char* filename = NULL;
      boolean translatedfileP = false;
      KeyValueList* walkedunits = newKeyValueList();

      clearSymbolRegistry();
      if (twopassP) {
        { StringWrapper* file = NULL;
          Cons* iter000 = files;

          for (file, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
            file = ((StringWrapper*)(iter000->value));
            if (forcetranslationP ||
                (stellaNeedToTranslateP(file, outputlanguage) ||
                 (!oCURRENTSYSTEMDEFINITIONo->loadedP))) {
              filename = makeFileName(file->wrapperValue, KWD_TRANSLATE_FILE_STELLA, true);
              if (!(probeFileP(filename))) {
                std::cout << "Warning: File " << "`" << filename << "'" << " does not exist." << std::endl;
                continue;
              }
              operateOnFile(filename, KWD_TRANSLATE_FILE_DEFINE);
              cleanUpTranslationUnitsSpecial();
              translatedfileP = true;
            }
          }
        }
        if (translatedfileP) {
          if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
            std::cout << "*** Pass 2, finalizing objects..." << std::endl;
          }
          finalizeClassesAndSlots();
        }
      }
      { StringWrapper* file = NULL;
        Cons* iter001 = files;

        for (file, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
          file = ((StringWrapper*)(iter001->value));
          if (forcetranslationP ||
              stellaNeedToTranslateP(file, outputlanguage)) {
            filename = makeFileName(file->wrapperValue, KWD_TRANSLATE_FILE_STELLA, true);
            if (!(probeFileP(filename))) {
              std::cout << "Warning: File " << "`" << filename << "'" << " does not exist." << std::endl;
              continue;
            }
            operateOnFile(filename, KWD_TRANSLATE_FILE_WALK);
            walkedunits->insertAt(wrapString(filename), oTRANSLATIONUNITSo);
            oTRANSLATIONUNITSo = newList();
          }
        }
      }
      walkedunits->reverse();
      if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
        std::cout << "    ==============================" << std::endl;
      }
      if (outputlanguage == KWD_TRANSLATE_FILE_COMMON_LISP) {
        clTranslateWalkedSystemUnits(walkedunits);
      }
      else if (outputlanguage == KWD_TRANSLATE_FILE_CPP) {
        cppTranslateWalkedSystemUnits(walkedunits);
      }
      else if (outputlanguage == KWD_TRANSLATE_FILE_JAVA) {
        javaTranslateWalkedSystemUnits(walkedunits);
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << outputlanguage << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
      clearSymbolRegistry();
      return (translatedfileP);
    }
  }
}

void transferNativeSystemFiles(Keyword* outputLanguage) {
  { Cons* nativeFiles = NULL;

    if (outputLanguage == KWD_TRANSLATE_FILE_COMMON_LISP) {
      nativeFiles = oCURRENTSYSTEMDEFINITIONo->lispOnlyFiles;
    }
    else if (outputLanguage == KWD_TRANSLATE_FILE_JAVA) {
      nativeFiles = oCURRENTSYSTEMDEFINITIONo->javaOnlyFiles;
    }
    else if (outputLanguage == KWD_TRANSLATE_FILE_CPP) {
      nativeFiles = oCURRENTSYSTEMDEFINITIONo->cppOnlyFiles;
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << outputLanguage << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    if (((boolean)(nativeFiles))) {
      nativeFiles = nativeFiles->difference(systemDefinitionSourceFiles(oCURRENTSYSTEMDEFINITIONo));
      transferFiles(nativeFiles, outputLanguage);
    }
  }
}

void transferDataFiles(Keyword* outputLanguage) {
  { Cons* dataFiles = oCURRENTSYSTEMDEFINITIONo->dataFiles;

    if (((boolean)(dataFiles))) {
      transferFiles(dataFiles, outputLanguage);
    }
  }
}

void transferFiles(Cons* files, Keyword* outputLanguage) {
  if (stringEqlP(rootSourceDirectory(), rootNativeDirectory())) {
    return;
  }
  { char* flotsamfilename = "";
    char* systemSubDirectory = (stringEqlP(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, "") ? (char*)"" : stringConcatenate(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, directorySeparatorString(), 0));

    if (outputLanguage == KWD_TRANSLATE_FILE_JAVA) {
      flotsamfilename = javaYieldFlotsamClassName(getCardinalModule(oCURRENTSYSTEMDEFINITIONo));
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, getCardinalModule(oCURRENTSYSTEMDEFINITIONo));
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo);
      { StringWrapper* f = NULL;
        Cons* iter000 = files;

        for (f, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
          f = ((StringWrapper*)(iter000->value));
          { char* filename = f->wrapperValue;
            Keyword* type = classifyFileExtension(filename);
            char* relativefilename = relativizeFileName(filename, rootSourceDirectory());
            char* fromfilename = NULL;
            char* tofilename = NULL;

            if (type == KWD_TRANSLATE_FILE_JAVA) {
              if (stringEqlP(fileBaseName(filename), flotsamfilename)) {
                *(STANDARD_WARNING->nativeStream) << "Warning: " << "Native Java filename " << "`" << flotsamfilename << "'" << std::endl << " conflicts with the Java catchall class' filename" << std::endl;
              }
            }
            else {
            }
            fromfilename = stringConcatenate(rootSourceDirectory(), systemSubDirectory, 1, filename);
            tofilename = makeFileName(relativefilename, type, true);
            if (!(fileYoungerThanP(tofilename, fromfilename) == TRUE_WRAPPER)) {
              if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
                std::cout << "Copying " << "`" << fromfilename << "'" << std::endl << " to " << "`" << tofilename << "'" << " ..." << std::endl;
              }
              copyFile(fromfilename, tofilename);
            }
          }
        }
      }
    }
  }
}

void helpStartupTranslateFile1() {
  {
    KWD_TRANSLATE_FILE_TRANSLATE = ((Keyword*)(internRigidSymbolWrtModule("TRANSLATE", NULL, 2)));
    KWD_TRANSLATE_FILE_JAVA = ((Keyword*)(internRigidSymbolWrtModule("JAVA", NULL, 2)));
    KWD_TRANSLATE_FILE_COMMON_LISP = ((Keyword*)(internRigidSymbolWrtModule("COMMON-LISP", NULL, 2)));
    KWD_TRANSLATE_FILE_CPP = ((Keyword*)(internRigidSymbolWrtModule("CPP", NULL, 2)));
    KWD_TRANSLATE_FILE_CPP_STANDALONE = ((Keyword*)(internRigidSymbolWrtModule("CPP-STANDALONE", NULL, 2)));
    KWD_TRANSLATE_FILE_IDL = ((Keyword*)(internRigidSymbolWrtModule("IDL", NULL, 2)));
    SGT_TRANSLATE_FILE_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", NULL, 1)));
    KWD_TRANSLATE_FILE_DEFINE = ((Keyword*)(internRigidSymbolWrtModule("DEFINE", NULL, 2)));
    KWD_TRANSLATE_FILE_FINALIZE = ((Keyword*)(internRigidSymbolWrtModule("FINALIZE", NULL, 2)));
    KWD_TRANSLATE_FILE_WALK = ((Keyword*)(internRigidSymbolWrtModule("WALK", NULL, 2)));
    KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER = ((Keyword*)(internRigidSymbolWrtModule("TRANSLATE-WITH-COPYRIGHT-HEADER", NULL, 2)));
    KWD_TRANSLATE_FILE_WINDOWS = ((Keyword*)(internRigidSymbolWrtModule("WINDOWS", NULL, 2)));
    KWD_TRANSLATE_FILE_UNIX = ((Keyword*)(internRigidSymbolWrtModule("UNIX", NULL, 2)));
    KWD_TRANSLATE_FILE_MAC = ((Keyword*)(internRigidSymbolWrtModule("MAC", NULL, 2)));
    KWD_TRANSLATE_FILE_LETTER = ((Keyword*)(internRigidSymbolWrtModule("LETTER", NULL, 2)));
    KWD_TRANSLATE_FILE_ROOT_DIRECTORY = ((Keyword*)(internRigidSymbolWrtModule("ROOT-DIRECTORY", NULL, 2)));
    KWD_TRANSLATE_FILE_LISP_TRANSLATIONS = ((Keyword*)(internRigidSymbolWrtModule("LISP-TRANSLATIONS", NULL, 2)));
    KWD_TRANSLATE_FILE_STELLA = ((Keyword*)(internRigidSymbolWrtModule("STELLA", NULL, 2)));
    KWD_TRANSLATE_FILE_KB = ((Keyword*)(internRigidSymbolWrtModule("KB", NULL, 2)));
    KWD_TRANSLATE_FILE_CPP_CODE = ((Keyword*)(internRigidSymbolWrtModule("CPP-CODE", NULL, 2)));
    KWD_TRANSLATE_FILE_CPP_HEADER = ((Keyword*)(internRigidSymbolWrtModule("CPP-HEADER", NULL, 2)));
    KWD_TRANSLATE_FILE_C_CODE = ((Keyword*)(internRigidSymbolWrtModule("C-CODE", NULL, 2)));
    KWD_TRANSLATE_FILE_C_HEADER = ((Keyword*)(internRigidSymbolWrtModule("C-HEADER", NULL, 2)));
    KWD_TRANSLATE_FILE_OTHER = ((Keyword*)(internRigidSymbolWrtModule("OTHER", NULL, 2)));
    KWD_TRANSLATE_FILE_NONE = ((Keyword*)(internRigidSymbolWrtModule("NONE", NULL, 2)));
    KWD_TRANSLATE_FILE_LISP_BINARY = ((Keyword*)(internRigidSymbolWrtModule("LISP-BINARY", NULL, 2)));
    KWD_TRANSLATE_FILE_USE_COMMON_LISP_STRUCTS = ((Keyword*)(internRigidSymbolWrtModule("USE-COMMON-LISP-STRUCTS", NULL, 2)));
    KWD_TRANSLATE_FILE_USE_COMMON_LISP_VECTOR_STRUCTS = ((Keyword*)(internRigidSymbolWrtModule("USE-COMMON-LISP-VECTOR-STRUCTS", NULL, 2)));
    KWD_TRANSLATE_FILE_LISP = ((Keyword*)(internRigidSymbolWrtModule("LISP", NULL, 2)));
    KWD_TRANSLATE_FILE_DIRECTORY = ((Keyword*)(internRigidSymbolWrtModule("DIRECTORY", NULL, 2)));
    SYM_TRANSLATE_FILE_STELLA_SYSTEM_UNITS_ALIST = ((Symbol*)(internRigidSymbolWrtModule("SYSTEM-UNITS-ALIST", NULL, 0)));
    KWD_TRANSLATE_FILE_LANGUAGE = ((Keyword*)(internRigidSymbolWrtModule("LANGUAGE", NULL, 2)));
    KWD_TRANSLATE_FILE_ACTION = ((Keyword*)(internRigidSymbolWrtModule("ACTION", NULL, 2)));
    KWD_TRANSLATE_FILE_TRANSLATE_SYSTEM = ((Keyword*)(internRigidSymbolWrtModule("TRANSLATE-SYSTEM", NULL, 2)));
    KWD_TRANSLATE_FILE_TWO_PASSp = ((Keyword*)(internRigidSymbolWrtModule("TWO-PASS?", NULL, 2)));
    KWD_TRANSLATE_FILE_FORCE_TRANSLATIONp = ((Keyword*)(internRigidSymbolWrtModule("FORCE-TRANSLATION?", NULL, 2)));
    KWD_TRANSLATE_FILE_PRODUCTION_SETTINGSp = ((Keyword*)(internRigidSymbolWrtModule("PRODUCTION-SETTINGS?", NULL, 2)));
    KWD_TRANSLATE_FILE_DEVELOPMENT_SETTINGSp = ((Keyword*)(internRigidSymbolWrtModule("DEVELOPMENT-SETTINGS?", NULL, 2)));
    KWD_TRANSLATE_FILE_WARN_ABOUT_MISSING_METHODS = ((Keyword*)(internRigidSymbolWrtModule("WARN-ABOUT-MISSING-METHODS", NULL, 2)));
    KWD_TRANSLATE_FILE_WARN_ABOUT_UNDEFINED_METHODS = ((Keyword*)(internRigidSymbolWrtModule("WARN-ABOUT-UNDEFINED-METHODS", NULL, 2)));
    KWD_TRANSLATE_FILE_USE_HARDCODED_SYMBOLS = ((Keyword*)(internRigidSymbolWrtModule("USE-HARDCODED-SYMBOLS", NULL, 2)));
    SYM_TRANSLATE_FILE_STELLA_STARTUP_TRANSLATE_FILE = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-TRANSLATE-FILE", NULL, 0)));
    SYM_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
  }
}

void helpStartupTranslateFile2() {
  {
    defineFunctionObject("ROOT-SOURCE-DIRECTORY", "(DEFUN (ROOT-SOURCE-DIRECTORY FILE-NAME) ())", ((cpp_function_code)(&rootSourceDirectory)), NULL);
    defineFunctionObject("ROOT-NATIVE-DIRECTORY", "(DEFUN (ROOT-NATIVE-DIRECTORY FILE-NAME) ())", ((cpp_function_code)(&rootNativeDirectory)), NULL);
    defineFunctionObject("ROOT-BINARY-DIRECTORY", "(DEFUN (ROOT-BINARY-DIRECTORY FILE-NAME) ())", ((cpp_function_code)(&rootBinaryDirectory)), NULL);
    defineFunctionObject("SYSTEM-DEFINITIONS-DIRECTORY", "(DEFUN (SYSTEM-DEFINITIONS-DIRECTORY FILE-NAME) ())", ((cpp_function_code)(&systemDefinitionsDirectory)), NULL);
    defineFunctionObject("HANDLE-IN-MODULE-TREE", "(DEFUN (HANDLE-IN-MODULE-TREE BOOLEAN BOOLEAN) ((TREE CONS) (SEENINMODULE? BOOLEAN) (ERRORONINMODULE? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&handleInModuleTree)), NULL);
    defineFunctionObject("TRANSLATE-AND-OUTPUT-UNITS-TO-FILE", "(DEFUN TRANSLATE-AND-OUTPUT-UNITS-TO-FILE ((FILE FILE-NAME) (TARGETLANGUAGE STRING)))", ((cpp_function_code)(&translateAndOutputUnitsToFile)), NULL);
    defineFunctionObject("OPERATE-ON-FILE", "(DEFUN OPERATE-ON-FILE ((FILE FILE-NAME) (OPERATION KEYWORD)))", ((cpp_function_code)(&operateOnFile)), NULL);
    defineFunctionObject("CLEAN-UP-TRANSLATION-UNITS-SPECIAL", "(DEFUN CLEAN-UP-TRANSLATION-UNITS-SPECIAL ())", ((cpp_function_code)(&cleanUpTranslationUnitsSpecial)), NULL);
    defineFunctionObject("TRANSLATE-FILE", "(DEFUN TRANSLATE-FILE ((FILE FILE-NAME) (OUTPUTLANGUAGE KEYWORD) (ASPARTOFSYSTEM? BOOLEAN)))", ((cpp_function_code)(&translateFile)), NULL);
    defineFunctionObject("OUTPUT-ALL-UNITS-TO-FILE", "(DEFUN OUTPUT-ALL-UNITS-TO-FILE ((SOURCEFILE FILE-NAME)))", ((cpp_function_code)(&outputAllUnitsToFile)), NULL);
    defineFunctionObject("RECORD-SIGNATURES-OF-ALL-UNITS", "(DEFUN RECORD-SIGNATURES-OF-ALL-UNITS ((SOURCEFILE FILE-NAME)))", ((cpp_function_code)(&recordSignaturesOfAllUnits)), NULL);
    defineFunctionObject("TRANSLATE-WITH-COPYRIGHT-HEADER?", "(DEFUN (TRANSLATE-WITH-COPYRIGHT-HEADER? BOOLEAN) ())", ((cpp_function_code)(&translateWithCopyrightHeaderP)), NULL);
    defineFunctionObject("OUTPUT-COPYRIGHT-HEADER", "(DEFUN OUTPUT-COPYRIGHT-HEADER ((STREAM OUTPUT-STREAM)))", ((cpp_function_code)(&outputCopyrightHeader)), NULL);
    defineFunctionObject("OUTPUT-FILE-HEADER", "(DEFUN OUTPUT-FILE-HEADER ((STREAM OUTPUT-STREAM) (FILE FILE-NAME)))", ((cpp_function_code)(&outputFileHeader)), NULL);
    defineFunctionObject("OPERATING-SYSTEM", "(DEFUN (OPERATING-SYSTEM KEYWORD) ())", ((cpp_function_code)(&operatingSystem)), NULL);
    defineFunctionObject("DIRECTORY-SEPARATOR", "(DEFUN (DIRECTORY-SEPARATOR CHARACTER) ())", ((cpp_function_code)(&directorySeparator)), NULL);
    defineFunctionObject("DIRECTORY-SEPARATOR-STRING", "(DEFUN (DIRECTORY-SEPARATOR-STRING STRING) ())", ((cpp_function_code)(&directorySeparatorString)), NULL);
    defineFunctionObject("DIRECTORY-SEPARATOR-FOR-FILE", "(DEFUN (DIRECTORY-SEPARATOR-FOR-FILE CHARACTER) ((FILE FILE-NAME)))", ((cpp_function_code)(&directorySeparatorForFile)), NULL);
    defineFunctionObject("FILE-NAME-DIRECTORY", "(DEFUN (FILE-NAME-DIRECTORY FILE-NAME) ((FILE FILE-NAME)) :DOCUMENTATION \"Return the directory component of `file' including the final\ndirectory separator or the empty string if `file' does not include a directory.\nNote that for purposes of this function, a logical host is considered part of\nthe directory portion of `file'\" :PUBLIC? TRUE)", ((cpp_function_code)(&fileNameDirectory)), NULL);
    defineFunctionObject("DIRECTORY-FILE-NAME", "(DEFUN (DIRECTORY-FILE-NAME FILE-NAME) ((DIRECTORY FILE-NAME)) :DOCUMENTATION \"Return `directory' as a file name, i.e., without a terminating\ndirectory separator.\" :PUBLIC? TRUE)", ((cpp_function_code)(&directoryFileName)), NULL);
    defineFunctionObject("FILE-NAME-AS-DIRECTORY", "(DEFUN (FILE-NAME-AS-DIRECTORY FILE-NAME) ((FILE FILE-NAME)) :DOCUMENTATION \"Return `file' interpreted as a directory, i.e., with a\nterminating directory separator.  If `file' is the empty string simply\nreturn the empty string, i.e., interpret it as the current directory instead\nof the root directory.\" :PUBLIC? TRUE)", ((cpp_function_code)(&fileNameAsDirectory)), NULL);
    defineFunctionObject("DIRECTORY-PARENT-DIRECTORY", "(DEFUN (DIRECTORY-PARENT-DIRECTORY FILE-NAME) ((DIRECTORY FILE-NAME) (LEVEL INTEGER)) :DOCUMENTATION \"Return the `level'-th parent directory component of `directory'\nincluding the final directory separator, or the empty string if `directory' does\nnot have that many parents.\" :PUBLIC? TRUE)", ((cpp_function_code)(&directoryParentDirectory)), NULL);
    defineFunctionObject("FILE-NAME-WITHOUT-DEVICE", "(DEFUN (FILE-NAME-WITHOUT-DEVICE FILE-NAME) ((FILE FILE-NAME)) :DOCUMENTATION \"Return the file name portion of `file' by removing any\nphysical device components.  This is just like `logical-pathname-without-host'\nbut only looks for one-character device strings as used in Windows.\" :PUBLIC? TRUE)", ((cpp_function_code)(&fileNameWithoutDevice)), NULL);
    defineFunctionObject("FILE-NAME-WITHOUT-DIRECTORY", "(DEFUN (FILE-NAME-WITHOUT-DIRECTORY FILE-NAME) ((FILE FILE-NAME)) :DOCUMENTATION \"Return the file name portion of `file' by removing any\ndirectory and logical host components.\" :PUBLIC? TRUE)", ((cpp_function_code)(&fileNameWithoutDirectory)), NULL);
    defineFunctionObject("FILE-NAME-WITHOUT-EXTENSION", "(DEFUN (FILE-NAME-WITHOUT-EXTENSION FILE-NAME) ((FILE FILE-NAME)) :DOCUMENTATION \"Remove `file's extension (or type) if there is any and\nreturn the result.\" :PUBLIC? TRUE)", ((cpp_function_code)(&fileNameWithoutExtension)), NULL);
    defineFunctionObject("FILE-EXTENSION", "(DEFUN (FILE-EXTENSION STRING) ((FILE FILE-NAME)) :DOCUMENTATION \"Return `file's extension (or type) if it has any including\nthe separator character.\" :PUBLIC? TRUE)", ((cpp_function_code)(&fileExtension)), NULL);
    defineFunctionObject("FILE-BASE-NAME", "(DEFUN (FILE-BASE-NAME FILE-NAME) ((FILE FILE-NAME)) :DOCUMENTATION \"Remove `file's directory (including logical host) and\nextension components and return the result.\" :PUBLIC? TRUE)", ((cpp_function_code)(&fileBaseName)), NULL);
    defineFunctionObject("DEFINE-LOGICAL-HOST-PROPERTY", "(DEFUN DEFINE-LOGICAL-HOST-PROPERTY ((HOST STRING) (PROPERTY KEYWORD) (VALUE OBJECT)) :DOCUMENTATION \"Define `property' with `value' for the logical host `host'.\nAs a side-effect, this also defines `host' as a logical host (both\n`property' and `value' can be supplied as NULL).  If :ROOT-DIRECTORY\nis specified, all pathnames with `host' are assumed to be relative to\nthat directory (even if they are absolute) and will be rerooted upon\ntranslation.  :ROOT-DIRECTORY can be a logical or physical pathname.\nIf :LISP-TRANSLATIONS is specified, those will be used verbatimely as\nthe value of `(CL:logical-pathname-translations host)' if we are\nrunning in Lisp, which allows us to depend on the native\n`CL:translate-logical-pathname' for more complex translation operations.\" :PUBLIC? TRUE)", ((cpp_function_code)(&defineLogicalHostProperty)), NULL);
    defineFunctionObject("LOOKUP-LOGICAL-HOST-PROPERTY", "(DEFUN (LOOKUP-LOGICAL-HOST-PROPERTY OBJECT) ((HOST STRING) (PROPERTY KEYWORD)))", ((cpp_function_code)(&lookupLogicalHostProperty)), NULL);
    defineFunctionObject("LOGICAL-HOST?", "(DEFUN (LOGICAL-HOST? BOOLEAN) ((HOST STRING)))", ((cpp_function_code)(&logicalHostP)), NULL);
    defineFunctionObject("LOGICAL-PATHNAME?", "(DEFUN (LOGICAL-PATHNAME? BOOLEAN) ((PATHNAME STRING)))", ((cpp_function_code)(&logicalPathnameP)), NULL);
    defineFunctionObject("ABSOLUTE-PATHNAME?", "(DEFUN (ABSOLUTE-PATHNAME? BOOLEAN) ((PATHNAME STRING)))", ((cpp_function_code)(&absolutePathnameP)), NULL);
    defineFunctionObject("GET-LOGICAL-HOST-NAME", "(DEFUN (GET-LOGICAL-HOST-NAME STRING) ((PATHNAME STRING)))", ((cpp_function_code)(&getLogicalHostName)), NULL);
    defineFunctionObject("LOGICAL-PATHNAME-WITHOUT-HOST", "(DEFUN (LOGICAL-PATHNAME-WITHOUT-HOST STRING) ((PATHNAME STRING)))", ((cpp_function_code)(&logicalPathnameWithoutHost)), NULL);
    defineFunctionObject("TRANSLATE-LOGICAL-PATHNAME", "(DEFUN (TRANSLATE-LOGICAL-PATHNAME STRING) ((PATHNAME STRING)))", ((cpp_function_code)(&translateLogicalPathname)), NULL);
    defineFunctionObject("UNLOGICALIZE-PATHNAME", "(DEFUN (UNLOGICALIZE-PATHNAME STRING) ((PATHNAME STRING)) :GLOBALLY-INLINE? TRUE (RETURN (TRANSLATE-LOGICAL-PATHNAME PATHNAME)))", ((cpp_function_code)(&unlogicalizePathname)), NULL);
    defineFunctionObject("MERGE-FILE-NAMES", "(DEFUN (MERGE-FILE-NAMES FILE-NAME) ((BASEFILE FILE-NAME) (DEFAULTS FILE-NAME)) :DOCUMENTATION \"Parse `baseFile', supply any missing components from\n`defaults' if supplied and return the result.\" :PUBLIC? TRUE)", ((cpp_function_code)(&mergeFileNames)), NULL);
    defineFunctionObject("COMPUTE-COMMON-LISP-FILE-EXTENSION", "(DEFUN (COMPUTE-COMMON-LISP-FILE-EXTENSION STRING) ((TYPE KEYWORD)))", ((cpp_function_code)(&computeCommonLispFileExtension)), NULL);
    defineFunctionObject("DEFAULT-COMMON-LISP-FILE-EXTENSION", "(DEFUN (DEFAULT-COMMON-LISP-FILE-EXTENSION STRING) ((TYPE KEYWORD)))", ((cpp_function_code)(&defaultCommonLispFileExtension)), NULL);
    defineFunctionObject("SELECT-FILE-EXTENSION", "(DEFUN (SELECT-FILE-EXTENSION STRING) ((TYPE KEYWORD)))", ((cpp_function_code)(&selectFileExtension)), NULL);
    defineFunctionObject("CLASSIFY-FILE-EXTENSION", "(DEFUN (CLASSIFY-FILE-EXTENSION KEYWORD) ((FILE FILE-NAME)))", ((cpp_function_code)(&classifyFileExtension)), NULL);
    defineFunctionObject("SELECT-ROOT-DIRECTORY", "(DEFUN (SELECT-ROOT-DIRECTORY STRING) ((TYPE KEYWORD)))", ((cpp_function_code)(&selectRootDirectory)), NULL);
    defineFunctionObject("SELECT-SPLITTER-PATH", "(DEFUN (SELECT-SPLITTER-PATH STRING) ((TYPE KEYWORD)))", ((cpp_function_code)(&selectSplitterPath)), NULL);
    defineFunctionObject("MAKE-FILE-NAME-FROM-RELATIVE-PATH", "(DEFUN (MAKE-FILE-NAME-FROM-RELATIVE-PATH FILE-NAME) ((FILEPATH OBJECT) (TYPE KEYWORD)))", ((cpp_function_code)(&makeFileNameFromRelativePath)), NULL);
    defineFunctionObject("ROOT-DIRECTORY-PREFIX", "(DEFUN (ROOT-DIRECTORY-PREFIX FILE-NAME) ((FILE FILE-NAME)))", ((cpp_function_code)(&rootDirectoryPrefix)), NULL);
    defineFunctionObject("MAKE-FILE-NAME", "(DEFUN (MAKE-FILE-NAME FILE-NAME) ((FILEPATH STRING) (TYPE KEYWORD) (RELATIVE? BOOLEAN)))", ((cpp_function_code)(&makeFileName)), NULL);
    defineFunctionObject("RELATIVIZE-FILE-NAME", "(DEFUN (RELATIVIZE-FILE-NAME FILE-NAME) ((FILE FILE-NAME) (ROOTPATH FILE-NAME)))", ((cpp_function_code)(&relativizeFileName)), NULL);
    defineFunctionObject("HELP-IMPLODE-PATHNAME", "(DEFUN (HELP-IMPLODE-PATHNAME FILE-NAME) ((FILENAME FILE-NAME)))", ((cpp_function_code)(&helpImplodePathname)), NULL);
    defineFunctionObject("IMPLODE-PATHNAME", "(DEFUN (IMPLODE-PATHNAME FILE-NAME) ((FILEPATH OBJECT)))", ((cpp_function_code)(&implodePathname)), NULL);
    defineFunctionObject("MAYBE-TRUNCATE-FILENAME", "(DEFUN (MAYBE-TRUNCATE-FILENAME FILE-NAME) ((BAREFILENAME FILE-NAME)))", ((cpp_function_code)(&maybeTruncateFilename)), NULL);
    defineFunctionObject("LANGUAGE-TO-FILE-TYPE", "(DEFUN (LANGUAGE-TO-FILE-TYPE KEYWORD) ((LANGUAGE KEYWORD)))", ((cpp_function_code)(&languageToFileType)), NULL);
    defineFunctionObject("REROOT-FILE-NAME", "(DEFUN (REROOT-FILE-NAME FILE-NAME) ((FILE FILE-NAME) (FROMROOT FILE-NAME) (TOROOT FILE-NAME)))", ((cpp_function_code)(&rerootFileName)), NULL);
    defineFunctionObject("FILE-YOUNGER-THAN?", "(DEFUN (FILE-YOUNGER-THAN? THREE-VALUED-BOOLEAN) ((FILE1 STRING) (FILE2 STRING)))", ((cpp_function_code)(&fileYoungerThanP)), NULL);
    defineFunctionObject("STELLA-NEED-TO-TRANSLATE?", "(DEFUN (STELLA-NEED-TO-TRANSLATE? BOOLEAN) ((FILE OBJECT) (LANGUAGE KEYWORD)))", ((cpp_function_code)(&stellaNeedToTranslateP)), NULL);
    defineFunctionObject("STELLA-NEED-TO-COMPILE?", "(DEFUN (STELLA-NEED-TO-COMPILE? BOOLEAN) ((FILE OBJECT)))", ((cpp_function_code)(&stellaNeedToCompileP)), NULL);
    defineFunctionObject("SYSTEM-NEEDS-TRANSLATION?", "(DEFUN (SYSTEM-NEEDS-TRANSLATION? BOOLEAN) ((SYSTEMNAME STRING) (LANGUAGE KEYWORD)))", ((cpp_function_code)(&systemNeedsTranslationP)), NULL);
    defineFunctionObject("COMPUTE-FILE-UNITS-MODULE", "(DEFUN (COMPUTE-FILE-UNITS-MODULE MODULE) ((FILEUNITS (LIST OF TRANSLATION-UNIT))))", ((cpp_function_code)(&computeFileUnitsModule)), NULL);
    defineFunctionObject("CONCATENATE-SYSTEM-UNITS", "(DEFUN (CONCATENATE-SYSTEM-UNITS (LIST OF TRANSLATION-UNIT)) ((SYSTEMUNITS SYSTEM-UNITS-ALIST)))", ((cpp_function_code)(&concatenateSystemUnits)), NULL);
    defineFunctionObject("TRANSLATE-SYSTEM", "(DEFUN (TRANSLATE-SYSTEM BOOLEAN) ((SYSTEMNAME STRING) |&REST| (|LANGUAGE&OPTIONS| OBJECT)) :DOCUMENTATION \"Translate all of the STELLA source files in system `systemName' into\n`language' (the optional first argument).  The following keyword/value\n`options' are recognized:\n\n`:language': can be used as an alternative to the optional language argument.\nIf not specified, the language of the running implementation is assumed.\n\n`:two-pass?' (default false): if true, all files will be scanned twice, once\nto load the signatures of objects defined in them, and once to actually\ntranslate the definitions.\n\n`:force-translation?' (default false): if true, files will be translated\nwhether or not their translations are up-to-date.\n\n`:development-settings?' (default false): if true translation will favor\nsafe, readable and debuggable code over efficiency (according to the value\nof `:development-settings' on the system definition).  If false, efficiency\nwill be favored instead (according to the value of `:" "production-settings'\non the system definition).\n\n`:production-settings?' (default true): inverse to `:development-settings?'.\" :PUBLIC? TRUE :COMMAND? TRUE)", ((cpp_function_code)(&translateSystem)), ((cpp_function_code)(&translateSystemEvaluatorWrapper)));
    defineFunctionObject("HELP-TRANSLATE-SYSTEM", "(DEFUN (HELP-TRANSLATE-SYSTEM BOOLEAN) ((FILES (CONS OF STRING-WRAPPER)) (TWOPASS? BOOLEAN) (FORCETRANSLATION? BOOLEAN)))", ((cpp_function_code)(&helpTranslateSystem)), NULL);
  }
}

void startupTranslateFile() {
  if (currentStartupTimePhaseP(0)) {
    oLOGICAL_HOST_TABLEo = newStringHashTable();
    defineLogicalHostProperty("PL", NULL, NULL);
  }
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo);
    if (currentStartupTimePhaseP(2)) {
      helpStartupTranslateFile1();
    }
    if (currentStartupTimePhaseP(4)) {
      oSYSTEMDEFINITIONSDIRECTORYo = NULL;
      oOSo = operatingSystem();
      oTYPE_TO_FILE_EXTENSION_TABLEo = listO(12, listO(3, KWD_TRANSLATE_FILE_STELLA, wrapString(".ste"), NIL), listO(3, KWD_TRANSLATE_FILE_KB, wrapString(".kb"), NIL), listO(3, KWD_TRANSLATE_FILE_CPP, wrapString(".cc"), NIL), listO(3, KWD_TRANSLATE_FILE_CPP_CODE, wrapString(".cc"), NIL), listO(3, KWD_TRANSLATE_FILE_CPP_HEADER, wrapString(".hh"), NIL), listO(3, KWD_TRANSLATE_FILE_C_CODE, wrapString(".c"), NIL), listO(3, KWD_TRANSLATE_FILE_C_HEADER, wrapString(".h"), NIL), listO(3, KWD_TRANSLATE_FILE_JAVA, wrapString(".java"), NIL), listO(3, KWD_TRANSLATE_FILE_IDL, wrapString(".idl"), NIL), listO(3, KWD_TRANSLATE_FILE_OTHER, wrapString(""), NIL), listO(3, KWD_TRANSLATE_FILE_NONE, wrapString(""), NIL), NIL);
    }
    if (currentStartupTimePhaseP(5)) {
      defineStellaTypeFromStringifiedSource("(DEFTYPE SYSTEM-UNITS-ALIST (KEY-VALUE-LIST OF STRING-WRAPPER (LIST OF TRANSLATION-UNIT)))");
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupTranslateFile2();
      defineFunctionObject("TRANSFER-NATIVE-SYSTEM-FILES", "(DEFUN TRANSFER-NATIVE-SYSTEM-FILES ((OUTPUT-LANGUAGE KEYWORD)))", ((cpp_function_code)(&transferNativeSystemFiles)), NULL);
      defineFunctionObject("TRANSFER-DATA-FILES", "(DEFUN TRANSFER-DATA-FILES ((OUTPUT-LANGUAGE KEYWORD)))", ((cpp_function_code)(&transferDataFiles)), NULL);
      defineFunctionObject("TRANSFER-FILES", "(DEFUN TRANSFER-FILES ((FILES (CONS OF STRING-WRAPPER)) (OUTPUT-LANGUAGE KEYWORD)))", ((cpp_function_code)(&transferFiles)), NULL);
      defineFunctionObject("STARTUP-TRANSLATE-FILE", "(DEFUN STARTUP-TRANSLATE-FILE () :PUBLIC? TRUE)", ((cpp_function_code)(&startupTranslateFile)), NULL);
      { MethodSlot* function = lookupFunction(SYM_TRANSLATE_FILE_STELLA_STARTUP_TRANSLATE_FILE);

        setDynamicSlotValue(function->dynamicSlots, SYM_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupTranslateFile"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      inModule(((StringWrapper*)(copyConsTree(wrapString("STELLA")))));
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *RECORD-SIGNATURES?* BOOLEAN FALSE :DOCUMENTATION \"If `true', record object signatures into a persistent table.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *WALK-WITH-RECORDED-SIGNATURES?* BOOLEAN FALSE :DOCUMENTATION \"If `true', the walker will try to find previously recorded\nsignatures for referenced but undefined functions, methods, etc.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *USERECORDEDSIGNATURES?* BOOLEAN FALSE :DOCUMENTATION \"If `true', `safe-lookup-slot' and `lookup-function' will\ntry to retrieve a previously recorded signature if normal lookup fails.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *ROOTSOURCEDIRECTORY* STRING \"PL:sources;\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *ROOTNATIVEDIRECTORY* STRING \"PL:native;\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *ROOTBINARYDIRECTORY* STRING \"PL:bin;\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *SYSTEMDEFINITIONSDIRECTORY* STRING NULL :DOCUMENTATION \"Points to the directory containing the SYSTEMS file.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CURRENTSYSTEMDEFINITION* SYSTEM-DEFINITION NULL :DOCUMENTATION \"Points to the current system.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CURRENTSYSTEMDEFINITIONSUBDIRECTORY* STRING \"\" :DOCUMENTATION \"Points to a path from the root directory down\nto a local directory containing sources, natives, or binaries.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *OS* KEYWORD (OPERATING-SYSTEM) :DOCUMENTATION \"The operating system we are running on.  Currently,\neither :UNIX, :WINDOWS, or :MAC.  Note that on the Mac OS X, the\nOS can be either :UNIX or :MAC, depending on which file naming \nconventions are being observed by the software.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT TYPE-SEPARATOR CHARACTER #\\.)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT LOGICAL-DIRECTORY-SEPARATOR CHARACTER #\\;)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT LOGICAL-HOST-SEPARATOR CHARACTER #\\:)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LOGICAL-HOST-TABLE* (STRING-HASH-TABLE OF STRING KEY-VALUE-LIST) NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *TYPE-TO-FILE-EXTENSION-TABLE* (CONS OF CONS) (BQUOTE ((:STELLA \".ste\") (:KB \".kb\") (:CPP \".cc\") (:CPP-CODE \".cc\") (:CPP-HEADER \".hh\") (:C-CODE \".c\") (:C-HEADER \".h\") (:JAVA \".java\") (:IDL \".idl\") (:OTHER \"\") (:NONE \"\"))) :DOCUMENTATION \"Used by `select-file-extension'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LISP-SPLITTER-PATH* STRING \"lisp\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *JAVA-SPLITTER-PATH* STRING \"java\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CPP-SPLITTER-PATH* STRING \"cpp\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DONTTRUNCATEFILENAMES?* BOOLEAN FALSE :DOCUMENTATION \"When TRUE, overrides normal truncation of file names.\")");
    }
  }
}

Keyword* KWD_TRANSLATE_FILE_TRANSLATE = NULL;

Keyword* KWD_TRANSLATE_FILE_JAVA = NULL;

Keyword* KWD_TRANSLATE_FILE_COMMON_LISP = NULL;

Keyword* KWD_TRANSLATE_FILE_CPP = NULL;

Keyword* KWD_TRANSLATE_FILE_CPP_STANDALONE = NULL;

Keyword* KWD_TRANSLATE_FILE_IDL = NULL;

Surrogate* SGT_TRANSLATE_FILE_STELLA_CONS = NULL;

Keyword* KWD_TRANSLATE_FILE_DEFINE = NULL;

Keyword* KWD_TRANSLATE_FILE_FINALIZE = NULL;

Keyword* KWD_TRANSLATE_FILE_WALK = NULL;

Keyword* KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER = NULL;

Keyword* KWD_TRANSLATE_FILE_WINDOWS = NULL;

Keyword* KWD_TRANSLATE_FILE_UNIX = NULL;

Keyword* KWD_TRANSLATE_FILE_MAC = NULL;

Keyword* KWD_TRANSLATE_FILE_LETTER = NULL;

Keyword* KWD_TRANSLATE_FILE_ROOT_DIRECTORY = NULL;

Keyword* KWD_TRANSLATE_FILE_LISP_TRANSLATIONS = NULL;

Keyword* KWD_TRANSLATE_FILE_STELLA = NULL;

Keyword* KWD_TRANSLATE_FILE_KB = NULL;

Keyword* KWD_TRANSLATE_FILE_CPP_CODE = NULL;

Keyword* KWD_TRANSLATE_FILE_CPP_HEADER = NULL;

Keyword* KWD_TRANSLATE_FILE_C_CODE = NULL;

Keyword* KWD_TRANSLATE_FILE_C_HEADER = NULL;

Keyword* KWD_TRANSLATE_FILE_OTHER = NULL;

Keyword* KWD_TRANSLATE_FILE_NONE = NULL;

Keyword* KWD_TRANSLATE_FILE_LISP_BINARY = NULL;

Keyword* KWD_TRANSLATE_FILE_USE_COMMON_LISP_STRUCTS = NULL;

Keyword* KWD_TRANSLATE_FILE_USE_COMMON_LISP_VECTOR_STRUCTS = NULL;

Keyword* KWD_TRANSLATE_FILE_LISP = NULL;

Keyword* KWD_TRANSLATE_FILE_DIRECTORY = NULL;

Symbol* SYM_TRANSLATE_FILE_STELLA_SYSTEM_UNITS_ALIST = NULL;

Keyword* KWD_TRANSLATE_FILE_LANGUAGE = NULL;

Keyword* KWD_TRANSLATE_FILE_ACTION = NULL;

Keyword* KWD_TRANSLATE_FILE_TRANSLATE_SYSTEM = NULL;

Keyword* KWD_TRANSLATE_FILE_TWO_PASSp = NULL;

Keyword* KWD_TRANSLATE_FILE_FORCE_TRANSLATIONp = NULL;

Keyword* KWD_TRANSLATE_FILE_PRODUCTION_SETTINGSp = NULL;

Keyword* KWD_TRANSLATE_FILE_DEVELOPMENT_SETTINGSp = NULL;

Keyword* KWD_TRANSLATE_FILE_WARN_ABOUT_MISSING_METHODS = NULL;

Keyword* KWD_TRANSLATE_FILE_WARN_ABOUT_UNDEFINED_METHODS = NULL;

Keyword* KWD_TRANSLATE_FILE_USE_HARDCODED_SYMBOLS = NULL;

Symbol* SYM_TRANSLATE_FILE_STELLA_STARTUP_TRANSLATE_FILE = NULL;

Symbol* SYM_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
