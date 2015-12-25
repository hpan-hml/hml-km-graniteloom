//  -*- Mode: C++ -*-

// name-utility.hh

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




namespace stella {

// Function signatures:
char* makeMatchingName(char* original, int options, ...);
Cons* decomposeNamestring(char* namestring, int options, ...);
char* composeNamestring(Cons* nameComponents, int options, ...);
char* makeMatchingNameFull(char* originalname, Keyword* breakoncap, Keyword* breakonnumber, char* breakonseparators, char* removeprefix, char* removesuffix, char* addprefix, char* addsuffix, Keyword* outputcase, char* outputseparator);
Cons* decomposeNamestringFull(char* namestring, Keyword* breakOnCap, Keyword* breakOnNumber, char* breakOnSeparators);
boolean suffixMatchesP(char* teststring, char* suffix);
boolean ordinalNumberStringP(char* teststring);
boolean heuristicAcronymP(char* itemstring);
char* composeNamestringFull(Cons* strings, char* prefix, char* suffix, Keyword* outputcase, char* outputseparator, StringHashTable* translationtable, boolean useacronymheuristicsP);
void startupNameUtility();

// Auxiliary global declarations:
extern Keyword* KWD_NAME_UTILITY_CLEVER;
extern Keyword* KWD_NAME_UTILITY_TITLECASE;
extern Keyword* KWD_NAME_UTILITY_BREAK_ON_CAP;
extern Keyword* KWD_NAME_UTILITY_NO;
extern Keyword* KWD_NAME_UTILITY_BREAK_ON_NUMBER;
extern Keyword* KWD_NAME_UTILITY_BREAK_ON_SEPARATORS;
extern Keyword* KWD_NAME_UTILITY_REMOVE_PREFIX;
extern Keyword* KWD_NAME_UTILITY_REMOVE_SUFFIX;
extern Keyword* KWD_NAME_UTILITY_ADD_PREFIX;
extern Keyword* KWD_NAME_UTILITY_ADD_SUFFIX;
extern Keyword* KWD_NAME_UTILITY_CASE;
extern Keyword* KWD_NAME_UTILITY_SEPARATOR;
extern Keyword* KWD_NAME_UTILITY_PREFIX;
extern Keyword* KWD_NAME_UTILITY_SUFFIX;
extern Keyword* KWD_NAME_UTILITY_TRANSLATION_TABLE;
extern Keyword* KWD_NAME_UTILITY_USE_ACRONYM_HEURISTICSp;
extern Keyword* KWD_NAME_UTILITY_DIGIT;
extern Keyword* KWD_NAME_UTILITY_PRESERVE;
extern Keyword* KWD_NAME_UTILITY_ALLCAPS;
extern Keyword* KWD_NAME_UTILITY_UPCASE;
extern Keyword* KWD_NAME_UTILITY_DOWNCASE;
extern Keyword* KWD_NAME_UTILITY_CAPITALIZE;
extern Keyword* KWD_NAME_UTILITY_TITLECASEX;
extern Symbol* SYM_NAME_UTILITY_STELLA_STARTUP_NAME_UTILITY;
extern Symbol* SYM_NAME_UTILITY_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
