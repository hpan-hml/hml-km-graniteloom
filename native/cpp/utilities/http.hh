//  -*- Mode: C++ -*-

// http.hh

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
| Portions created by the Initial Developer are Copyright (C) 2001-2006      |
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


namespace stella_utilities {
  using namespace stella;

// Class definitions:
class HttpException : public ReadException {
public:
  int errorCode;
public:
  HttpException(const std::string& msg) : ReadException(msg) {
}

};



// Function signatures:
HttpException* newHttpException(char* message);
char* handleHttpHeaderFirstLine(char* line, Dictionary* fields, int& _Return1, char*& _Return2);
void handleHttpHeaderOtherLine(char* line, Dictionary* fields);
char* decomposeInternetUrl(char* url, char*& _Return1, char*& _Return2, char*& _Return3, char*& _Return4, char*& _Return5, char*& _Return6);
int readHttpHeader(InputStream* stream, Dictionary* fields, char*& _Return1, char*& _Return2);
void writeHttpRequest(OutputStream* stream, char* method, char* host, char* urlPath, Dictionary* headers, char* content);
void writePostRequest(OutputStream* stream, char* host, char* urlPath, Dictionary* headers, char* content);
char* postData(char* host, int port, char* urlPath, Dictionary* headers, char* content);
char* getWebPage(char* host, int port, char* urlPath, Dictionary* returnHeaders);
char* buildFullUrlHierarchicalPart(char* path, char* query, char* fragment);
char* urlPathToFilename(char* path);
InputStream* openUrlStream(char* url);
Object* withInputUrl(Cons* binding, Cons* body);
void startupHttp();

// Auxiliary global declarations:
extern Keyword* KWD_HTTP_MAC;
extern Symbol* SYM_HTTP_STELLA_LET;
extern Symbol* SYM_HTTP_STELLA_INPUT_STREAM;
extern Symbol* SYM_HTTP_STELLA_NULL;
extern Symbol* SYM_HTTP_STELLA_UNWIND_PROTECT;
extern Symbol* SYM_HTTP_STELLA_PROGN;
extern Symbol* SYM_HTTP_STELLA_SETQ;
extern Symbol* SYM_HTTP_UTILITIES_OPEN_URL_STREAM;
extern Symbol* SYM_HTTP_STELLA_WHEN;
extern Symbol* SYM_HTTP_STELLA_DEFINEDp;
extern Symbol* SYM_HTTP_STELLA_FREE;
extern Symbol* SYM_HTTP_UTILITIES_STARTUP_HTTP;
extern Symbol* SYM_HTTP_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella_utilities
