//  -*- Mode: C++ -*-

// translate-file.hh

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



namespace stella {

// Global declarations:
extern boolean oRECORD_SIGNATURESpo;
extern boolean oWALK_WITH_RECORDED_SIGNATURESpo;
extern DECLARE_STELLA_SPECIAL(oUSERECORDEDSIGNATURESpo, boolean );
extern DECLARE_STELLA_SPECIAL(oROOTSOURCEDIRECTORYo, char* );
extern DECLARE_STELLA_SPECIAL(oROOTNATIVEDIRECTORYo, char* );
extern DECLARE_STELLA_SPECIAL(oROOTBINARYDIRECTORYo, char* );
extern DECLARE_STELLA_SPECIAL(oSYSTEMDEFINITIONSDIRECTORYo, char* );
extern DECLARE_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition* );
extern DECLARE_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char* );
extern Keyword* oOSo;
extern char TYPE_SEPARATOR;
extern char LOGICAL_DIRECTORY_SEPARATOR;
extern char LOGICAL_HOST_SEPARATOR;
extern StringHashTable* oLOGICAL_HOST_TABLEo;
extern Cons* oTYPE_TO_FILE_EXTENSION_TABLEo;
extern char* oLISP_SPLITTER_PATHo;
extern char* oJAVA_SPLITTER_PATHo;
extern char* oCPP_SPLITTER_PATHo;
extern DECLARE_STELLA_SPECIAL(oDONTTRUNCATEFILENAMESpo, boolean );

// Function signatures:
char* rootSourceDirectory();
char* rootNativeDirectory();
char* rootBinaryDirectory();
char* systemDefinitionsDirectory();
boolean handleInModuleTree(Cons* tree, boolean seeninmoduleP, boolean erroroninmoduleP, boolean& _Return1);
void translateAndOutputUnitsToFile(char* file, char* targetlanguage);
void operateOnFile(char* file, Keyword* operation);
void cleanUpTranslationUnitsSpecial();
void translateFile(char* file, Keyword* outputlanguage, boolean aspartofsystemP);
void outputAllUnitsToFile(char* sourcefile);
void recordSignaturesOfAllUnits(char* sourcefile);
boolean translateWithCopyrightHeaderP();
void outputCopyrightHeader(OutputStream* stream);
void outputFileHeader(OutputStream* stream, char* file);
Keyword* operatingSystem();
char directorySeparator();
char* directorySeparatorString();
char directorySeparatorForFile(char* file);
char* fileNameDirectory(char* file);
char* directoryFileName(char* directory);
char* fileNameAsDirectory(char* file);
char* directoryParentDirectory(char* directory, int level);
char* fileNameWithoutDirectory(char* file);
char* fileNameWithoutExtension(char* file);
char* fileExtension(char* file);
char* fileBaseName(char* file);
void defineLogicalHostProperty(char* host, Keyword* property, Object* value);
Object* lookupLogicalHostProperty(char* host, Keyword* property);
boolean logicalHostP(char* host);
boolean logicalPathnameP(char* pathname);
boolean absolutePathnameP(char* pathname);
char* getLogicalHostName(char* pathname);
char* logicalPathnameWithoutHost(char* pathname);
char* translateLogicalPathname(char* pathname);
char* unlogicalizePathname(char* pathname);
char* mergeFileNames(char* basefile, char* defaults);
char* computeCommonLispFileExtension(Keyword* type);
char* defaultCommonLispFileExtension(Keyword* type);
char* selectFileExtension(Keyword* type);
Keyword* classifyFileExtension(char* file);
char* selectRootDirectory(Keyword* type);
char* selectSplitterPath(Keyword* type);
char* makeFileNameFromRelativePath(Object* filepath, Keyword* type);
char* rootDirectoryPrefix(char* file);
char* makeFileName(char* filepath, Keyword* type, boolean relativeP);
char* relativizeFileName(char* file, char* rootpath);
char* helpImplodePathname(char* filename);
char* implodePathname(Object* filepath);
char* maybeTruncateFilename(char* barefilename);
Keyword* languageToFileType(Keyword* language);
char* rerootFileName(char* file, char* fromroot, char* toroot);
BooleanWrapper* fileYoungerThanP(char* file1, char* file2);
boolean stellaNeedToTranslateP(Object* file, Keyword* language);
boolean stellaNeedToCompileP(Object* file);
boolean systemNeedsTranslationP(char* systemname, Keyword* language);
Module* computeFileUnitsModule(List* fileunits);
List* concatenateSystemUnits(KeyValueList* systemunits);
boolean translateSystem(char* systemname, Cons* languageAoptions);
BooleanWrapper* translateSystemEvaluatorWrapper(Cons* arguments);
boolean helpTranslateSystem(Cons* files, boolean twopassP, boolean forcetranslationP);
void transferNativeSystemFiles(Keyword* outputLanguage);
void transferDataFiles(Keyword* outputLanguage);
void transferFiles(Cons* files, Keyword* outputLanguage);
void helpStartupTranslateFile1();
void helpStartupTranslateFile2();
void startupTranslateFile();

// Auxiliary global declarations:
extern Keyword* KWD_TRANSLATE_FILE_TRANSLATE;
extern Keyword* KWD_TRANSLATE_FILE_JAVA;
extern Keyword* KWD_TRANSLATE_FILE_COMMON_LISP;
extern Keyword* KWD_TRANSLATE_FILE_CPP;
extern Keyword* KWD_TRANSLATE_FILE_CPP_STANDALONE;
extern Keyword* KWD_TRANSLATE_FILE_IDL;
extern Surrogate* SGT_TRANSLATE_FILE_STELLA_CONS;
extern Keyword* KWD_TRANSLATE_FILE_DEFINE;
extern Keyword* KWD_TRANSLATE_FILE_FINALIZE;
extern Keyword* KWD_TRANSLATE_FILE_WALK;
extern Keyword* KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER;
extern Keyword* KWD_TRANSLATE_FILE_WINDOWS;
extern Keyword* KWD_TRANSLATE_FILE_UNIX;
extern Keyword* KWD_TRANSLATE_FILE_MAC;
extern Keyword* KWD_TRANSLATE_FILE_ROOT_DIRECTORY;
extern Keyword* KWD_TRANSLATE_FILE_LISP_TRANSLATIONS;
extern Keyword* KWD_TRANSLATE_FILE_STELLA;
extern Keyword* KWD_TRANSLATE_FILE_KB;
extern Keyword* KWD_TRANSLATE_FILE_CPP_CODE;
extern Keyword* KWD_TRANSLATE_FILE_CPP_HEADER;
extern Keyword* KWD_TRANSLATE_FILE_C_CODE;
extern Keyword* KWD_TRANSLATE_FILE_C_HEADER;
extern Keyword* KWD_TRANSLATE_FILE_OTHER;
extern Keyword* KWD_TRANSLATE_FILE_NONE;
extern Keyword* KWD_TRANSLATE_FILE_LISP_BINARY;
extern Keyword* KWD_TRANSLATE_FILE_USE_COMMON_LISP_STRUCTS;
extern Keyword* KWD_TRANSLATE_FILE_USE_COMMON_LISP_VECTOR_STRUCTS;
extern Keyword* KWD_TRANSLATE_FILE_LISP;
extern Keyword* KWD_TRANSLATE_FILE_DIRECTORY;
extern Symbol* SYM_TRANSLATE_FILE_STELLA_SYSTEM_UNITS_ALIST;
extern Keyword* KWD_TRANSLATE_FILE_LANGUAGE;
extern Keyword* KWD_TRANSLATE_FILE_ACTION;
extern Keyword* KWD_TRANSLATE_FILE_TRANSLATE_SYSTEM;
extern Keyword* KWD_TRANSLATE_FILE_TWO_PASSp;
extern Keyword* KWD_TRANSLATE_FILE_FORCE_TRANSLATIONp;
extern Keyword* KWD_TRANSLATE_FILE_PRODUCTION_SETTINGSp;
extern Keyword* KWD_TRANSLATE_FILE_DEVELOPMENT_SETTINGSp;
extern Keyword* KWD_TRANSLATE_FILE_WARN_ABOUT_MISSING_METHODS;
extern Keyword* KWD_TRANSLATE_FILE_WARN_ABOUT_UNDEFINED_METHODS;
extern Keyword* KWD_TRANSLATE_FILE_USE_HARDCODED_SYMBOLS;
extern Symbol* SYM_TRANSLATE_FILE_STELLA_STARTUP_TRANSLATE_FILE;
extern Symbol* SYM_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
