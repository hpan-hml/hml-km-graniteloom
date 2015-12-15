//  -*- Mode: C++ -*-

// primal.hh

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



namespace stella {

// Global declarations:
extern double PI;
extern int NULL_INTEGER;
extern short int NULL_SHORT_INTEGER;
extern long int NULL_LONG_INTEGER;
extern unsigned short int NULL_UNSIGNED_SHORT_INTEGER;
extern unsigned long int NULL_UNSIGNED_LONG_INTEGER;
extern double NULL_FLOAT;
extern float NULL_SINGLE_FLOAT;
extern double NULL_DOUBLE_FLOAT;
extern char NULL_CHARACTER;
extern char NULL_BYTE;
extern char NULL_OCTET;
extern double RECIPROCAL_NL10;
extern DECLARE_STELLA_SPECIAL(oTRANSIENTOBJECTSpo, boolean );
extern int* oHASH_BYTE_RANDOM_TABLEo;
extern int oINTEGER_MSB_MASKo;
extern int oINTEGER_UNSIGNED_BITS_MASKo;
extern Vector* oHASH_TABLE_SIZE_PRIME_STRINGSo;
extern Vector* oHASH_TABLE_SIZE_PRIMESo;
extern char* oBOOTSTRAP_LOCKo;

// Function signatures:
char* lispNullArraySymbolString(int rank);
boolean eqlP(Object* x, Object* y);
boolean equalP(Object* x, Object* y);
boolean zeroP(int x);
boolean plusP(int x);
boolean evenP(int x);
boolean oddP(int x);
int div(int x, int y);
int rem(int x, int y);
double frem(double x, double y);
int mod(int x, int modulus);
double stella::fmod(double x, double modulus);
int gcd(int x, int y);
boolean integerValuedP(double x);
Cons* floatToBase60(double x, boolean allIntegersP);
double base60ToFloat(Cons* l);
int stella::random(int n);
void seedRandomNumberGenerator();
double stella::sqrt(double n);
double stella::cos(double n);
double stella::sin(double n);
double stella::tan(double n);
double stella::acos(double n);
double stella::asin(double n);
double stella::atan(double n);
double stella::atan2(double x, double y);
double stella::log(double n);
double log10(double n);
double stella::exp(double n);
double expt(double x, double y);
int stella::min(int x, int y);
int stella::max(int x, int y);
int integerAbs(int x);
double floatAbs(double x);
int characterCode(char ch);
char codeCharacter(int code);
char characterDowncase(char ch);
char characterUpcase(char ch);
char characterCapitalize(char ch);
boolean stringEqlP(char* x, char* y);
boolean stringEqualP(char* x, char* y);
int stringCompare(char* x, char* y, boolean caseSensitiveP);
boolean stringEmptyP(char* x);
boolean stringNonEmptyP(char* x);
boolean stringL(char* x, char* y);
boolean stringLE(char* x, char* y);
boolean stringGE(char* x, char* y);
boolean stringG(char* x, char* y);
boolean stringLessP(char* x, char* y);
boolean stringLessEqualP(char* x, char* y);
boolean stringGreaterEqualP(char* x, char* y);
boolean stringGreaterP(char* x, char* y);
char* makeMutableString(int size, char initchar);
char* makeRawMutableString(int size);
char* stringConcatenate(char* string1, char* string2, int otherstrings, ...);
char* helpSubstituteCharacters(char* self, char* newChars, char* oldChars);
char* mutableStringSubstituteCharacters(char* self, char* newChars, char* oldChars);
char* stringSubstituteCharacters(char* self, char* newChars, char* oldChars);
char* replaceSubstrings(char* string, char* neW, char* old);
char* instantiateStringTemplate(char* templatE, int varsAvalues, ...);
int insertString(char* source, int start, int end, char* target, int targetIndex, Keyword* caseConversion);
char* characterToString(char c);
char* formatWithPadding(char* input, int length, char padchar, Keyword* align, boolean truncateP);
char* zeroPadInteger(int value, int size);
char* zeroPadString(char* input, int size);
char stringFirst(char* self);
char mutableStringFirst(char* self);
char mutableStringFirstSetter(char* self, char ch);
char stringSecond(char* self);
char mutableStringSecond(char* self);
char mutableStringSecondSetter(char* self, char ch);
char stringThird(char* self);
char mutableStringThird(char* self);
char mutableStringThirdSetter(char* self, char ch);
char stringFourth(char* self);
char mutableStringFourth(char* self);
char mutableStringFourthSetter(char* self, char ch);
char stringFifth(char* self);
char mutableStringFifth(char* self);
char mutableStringFifthSetter(char* self, char ch);
char stringNth(char* self, int position);
char mutableStringNth(char* self, int position);
char mutableStringNthSetter(char* self, char ch, int position);
int stringLength(char* self);
int mutableStringLength(char* self);
boolean startsWithP(char* string, char* prefix, int start);
int helpFindMatchingPrefixLength(char* string1, int start1, int end1, char* string2, int start2, int end2);
int findMatchingPrefixLength(char* string1, int start1, int end1, char* string2, int start2, int end2);
int findMismatch(char* string1, int start1, int end1, char* string2, int start2, int end2, int& _Return1);
int nonMatchingPositionHelper(char* source, int start, int end, char* match);
int nonMatchingPosition(char* source, int start, char* match);
int helpAdvancePastWhitespace(char* source, int start, int end);
int advancePastWhitespace(char* source, int start);
boolean eqlExceptInWhitespaceP(char* s1, char* s2);
Object* unstringify(char* string);
int hashmod(int code, int size);
int rotateHashCode(int arg);
int objectHashCode(Object* self);
int safeHashCode(Object* self);
int stringHashCode(char* self);
int integerHashCode(int self);
int floatHashCode(double self);
int characterHashCode(char self);
int safeEqualHashCode(Object* self);
int hashString(char* string, int seedcode);
int pickHashTableSizePrime(int minsize);
void resizeVector(Vector* self, int size);
Object* nativeVectorNth(Object** self, int position);
Object* nativeVectorNthSetter(Object** self, Object* value, int position);
void unmake(Object* self);
void copyFile(char* fromfile, char* tofile);
int lognot(int arg);
int logand(int arg1, int arg2);
int logor(int arg1, int arg2);
int logxor(int arg1, int arg2);
int shiftLeft(int arg, int count);
int shiftRight(int arg, int count);
int unsignedShiftRightBy1(int arg);
char* generateUuid(Keyword* uuidType);
char* generateRandomUuid();
Object* stellify(Object* self);
boolean stellaObjectP(Object* self);
boolean runningAsLispP();
Keyword* runningInLanguage();
char* runningSystemInformation();
void stella::sleep(double seconds);
char* exceptionMessage(std::exception* e);
void printExceptionContext(std::exception* e, OutputStream* stream);
char* makeProcessLock();
void helpStartupPrimal1();
void helpStartupPrimal2();
void helpStartupPrimal3();
void helpStartupPrimal4();
void helpStartupPrimal5();
void startupPrimal();

// Auxiliary global declarations:
extern Symbol* SYM_PRIMAL_STELLA_FLOOR;
extern Keyword* KWD_PRIMAL_CPP;
extern Keyword* KWD_PRIMAL_FUNCTION;
extern Symbol* SYM_PRIMAL_STELLA_ROUND;
extern Symbol* SYM_PRIMAL_STELLA_FMOD;
extern Symbol* SYM_PRIMAL_STELLA_RANDOM;
extern Symbol* SYM_PRIMAL_STELLA_SQRT;
extern Symbol* SYM_PRIMAL_STELLA_COS;
extern Symbol* SYM_PRIMAL_STELLA_SIN;
extern Symbol* SYM_PRIMAL_STELLA_TAN;
extern Symbol* SYM_PRIMAL_STELLA_ACOS;
extern Symbol* SYM_PRIMAL_STELLA_ASIN;
extern Symbol* SYM_PRIMAL_STELLA_ATAN;
extern Symbol* SYM_PRIMAL_STELLA_ATAN2;
extern Symbol* SYM_PRIMAL_STELLA_EXP;
extern Symbol* SYM_PRIMAL_STELLA_LOG;
extern Symbol* SYM_PRIMAL_STELLA_MIN;
extern Symbol* SYM_PRIMAL_STELLA_MAX;
extern Keyword* KWD_PRIMAL_UPCASE;
extern Keyword* KWD_PRIMAL_DOWNCASE;
extern Keyword* KWD_PRIMAL_CAPITALIZE;
extern Keyword* KWD_PRIMAL_PRESERVE;
extern Keyword* KWD_PRIMAL_LEFT;
extern Keyword* KWD_PRIMAL_RIGHT;
extern Keyword* KWD_PRIMAL_CENTER;
extern Keyword* KWD_PRIMAL_WHITE_SPACE;
extern Symbol* SYM_PRIMAL_STELLA_HASH_CODE;
extern Keyword* KWD_PRIMAL_JAVA;
extern Keyword* KWD_PRIMAL_TYPE_4;
extern Keyword* KWD_PRIMAL_RANDOM;
extern Symbol* SYM_PRIMAL_STELLA_SLEEP;
extern Symbol* SYM_PRIMAL_STELLA_STARTUP_PRIMAL;
extern Symbol* SYM_PRIMAL_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
