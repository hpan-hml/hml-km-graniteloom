//  -*- Mode: C++ -*-

// http.cc

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

#include "utilities/utilities-system.hh"

namespace stella_utilities {
  using namespace stella;

HttpException* newHttpException(char* message) {
  { HttpException* self = NULL;

    self = new HttpException(message);
    self->errorCode = NULL_INTEGER;
    return (self);
  }
}

char* handleHttpHeaderFirstLine(char* line, Dictionary* fields, int& _Return1, char*& _Return2) {
  // Handles the first line of an http header.  
  // Returns version, response code, response message.  The first
  // line is inserted into `fields' fields with the empty string key ""
  // This is a low-level utility routine that can be used to build custom
  // message parsing code.
  { int space1 = stringPosition(line, ' ', 0);
    int space2 = ((space1 == NULL_INTEGER) ? NULL_INTEGER : stringPosition(line, ' ', space1 + 1));

    if (space2 == NULL_INTEGER) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Malformed header line: " << "`" << line << "'";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    fields->insertAt(wrapString(""), wrapString(line));
    { char* _Return0 = stringSubsequence(line, 0, space1);

      _Return1 = stringToInteger(stringSubsequence(line, space1 + 1, space2));
      _Return2 = stringSubsequence(line, space2 + 1, NULL_INTEGER);
      return (_Return0);
    }
  }
}

void handleHttpHeaderOtherLine(char* line, Dictionary* fields) {
  // Handles header lines other than the first one.
  // Each such line is inserted into `fields' as keyword value pairs.
  // This is a low-level utility routine that can be used to build custom
  // message parsing code.
  { int colonPosition = stringPosition(line, ':', 0);

    if (colonPosition == NULL_INTEGER) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Bad header seen: " << "`" << line << "'";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    else {
      fields->insertAt(wrapString(stringSubsequence(line, 0, colonPosition)), wrapString(stringSubsequence(line, colonPosition + 2, NULL_INTEGER)));
    }
  }
}

char* decomposeInternetUrl(char* url, char*& _Return1, char*& _Return2, char*& _Return3, char*& _Return4, char*& _Return5, char*& _Return6) {
  // Takes an internet style URL and returns the components of
  // that URL as specified below.  Missing elements return the empty string "".
  //   PROTOCOL USERNAME:PASSWORD DOMAIN PORT PATH QUERY FRAGMENT
  // 
  //   o Protocol.  The access protocol.
  // 
  //        Those schemes which refer to internet protocols mostly have a
  //        common syntax for the rest of the object name. This starts with a
  //        double slash '//' to indicate its presence, and continues until
  //        the following slash '/':
  // 
  //   o An optional user name, if required (as it is with a few FTP servers).
  //     The password, if present, follows the user name, separated from it by a colon;
  //     the user name and optional password are followed by a commercial at sign '@'. 
  //   o The internet domain name of the host
  //   o The port number, if it is not the default number for the protocol,
  //     is given in decimal notation after a colon.
  //   o Path The path is a hierarchical representation of a particular path. It may 
  //     define details of how the client should communicate with the server, including
  //     information to be passed transparently to the server without any processing by
  //     the client.
  //     The path is interpreted in a manner dependent on the scheme being used.
  //     Generally, the reserved slash '/' character (ASCII 2F hex) denotes a level in a
  //     hierarchical structure, the higher level part to the left of the slash.
  //   o Query is the part of the hierarchical information following a '?' character.
  //   o Fragment is the part of the hierarchical information following a '#' character.
  // 
  // References:  http://www.gbiv.com/protocols/uri/rfc/rfc3986.html
  // 
  { int fieldStart = 0;
    int fieldEnd = stringSearch(url, makeString(1, ':'), 0);
    char* protocol = "";
    char* userInformation = "";
    char* domainName = "";
    char* portNumber = "";
    char* path = "";
    char* query = "";
    char* fragment = "";

    if (fieldEnd != NULL_INTEGER) {
      protocol = stringSubsequence(url, 0, fieldEnd);
      if (fieldEnd == stringSearch(url, "://", fieldEnd)) {
        fieldEnd = fieldEnd + 3;
      }
      else {
        fieldEnd = fieldEnd + 1;
      }
      fieldStart = fieldEnd;
      fieldEnd = stringPosition(url, '/', fieldStart);
      domainName = stringSubsequence(url, fieldStart, fieldEnd);
      fieldStart = fieldEnd;
    }
    fieldEnd = stringPosition(url, '?', fieldStart);
    if (fieldEnd != NULL_INTEGER) {
      {
        path = stringSubsequence(url, fieldStart, fieldEnd);
        fieldStart = fieldEnd + 1;
        fieldEnd = stringPosition(url, '#', fieldStart);
        if (fieldEnd != NULL_INTEGER) {
          {
            query = stringSubsequence(url, fieldStart, fieldEnd);
            fieldStart = fieldEnd + 1;
            fragment = stringSubsequence(url, fieldStart, NULL_INTEGER);
          }
        }
        else {
          query = stringSubsequence(url, fieldStart, NULL_INTEGER);
        }
      }
    }
    else {
      {
        fieldEnd = stringPosition(url, '#', fieldStart);
        if (fieldEnd != NULL_INTEGER) {
          {
            path = stringSubsequence(url, fieldStart, fieldEnd);
            fieldStart = fieldEnd + 1;
            fragment = stringSubsequence(url, fieldStart, NULL_INTEGER);
          }
        }
        else {
          path = stringSubsequence(url, fieldStart, NULL_INTEGER);
        }
      }
    }
    fieldEnd = stringPosition(domainName, '@', 0);
    if (fieldEnd != NULL_INTEGER) {
      userInformation = stringSubsequence(domainName, 0, fieldEnd);
      domainName = stringSubsequence(domainName, fieldEnd + 1, NULL_INTEGER);
    }
    fieldStart = stringPosition(domainName, ':', 0);
    if (fieldStart != NULL_INTEGER) {
      portNumber = stringSubsequence(domainName, fieldStart + 1, NULL_INTEGER);
      domainName = stringSubsequence(domainName, 0, fieldStart);
    }
    _Return1 = userInformation;
    _Return2 = domainName;
    _Return3 = portNumber;
    _Return4 = path;
    _Return5 = query;
    _Return6 = fragment;
    return (protocol);
  }
}

int readHttpHeader(InputStream* stream, Dictionary* fields, char*& _Return1, char*& _Return2) {
  // Reads the HTTP header from `stream', parses the header fields
  // and stores the results in `fields'.  The first line of the response will be
  // stored in `fields' with the empty string "" as the key.  Other values will
  // have the header name as the key.  The first return value is the response code
  // of the HTTP request.  A response of 200 indicates success.  Other common
  // responses are 404 (page not found).  The second return value is the message
  // associated with the code.  The third return value is the version information.
  // If the stream ends before a valid header is read, then `null' is returned for
  // all values.
  { char* buffer = makeRawMutableString(1024);
    boolean firstLineP = true;
    int responseCode = NULL_INTEGER;
    char* responseMessage = NULL;
    char* versionString = NULL;
    char ch = NULL_CHARACTER;
    int index = 0;
    boolean eofP = false;
    boolean returnP = false;

    ch = readCharacter(stream, eofP);
    while (!eofP) {
      switch (ch) {
        case '\r': 
          if (returnP) {
            {
              break;
            }
          }
          else {
            returnP = true;
          }
        break;
        case '\n': 
          if (!(returnP)) {
          }
          if (index == 0) {
            break;
          }
          else if (firstLineP) {
            versionString = handleHttpHeaderFirstLine(mutableStringSubsequence(buffer, 0, index), fields, responseCode, responseMessage);
            firstLineP = false;
          }
          else {
            handleHttpHeaderOtherLine(mutableStringSubsequence(buffer, 0, index), fields);
          }
          returnP = false;
          index = 0;
        break;
        default:
          if (returnP) {
            if (index == 0) {
              break;
            }
            else if (firstLineP) {
              versionString = handleHttpHeaderFirstLine(mutableStringSubsequence(buffer, 0, index), fields, responseCode, responseMessage);
              firstLineP = false;
            }
            else {
              handleHttpHeaderOtherLine(mutableStringSubsequence(buffer, 0, index), fields);
            }
          }
          buffer[index] = ch;
          index = index + 1;
          returnP = false;
        break;
      }
      ch = readCharacter(stream, eofP);
    }
    _Return1 = responseMessage;
    _Return2 = versionString;
    return (responseCode);
  }
}

void writeHttpRequest(OutputStream* stream, char* method, char* host, char* urlPath, Dictionary* headers, char* content) {
  // Send `content' as an HTTP 1.0 request on `stream' using `method'.
  // The request is sent to `url-path' at `host'.  The `stream' must be a TCP-stream
  // that is connected to `host' at the appropriate port.
  *(stream->nativeStream) << method << " " << urlPath << " HTTP/1.0" << "\r" << "\n";
  if (host != NULL) {
    if (!((boolean)(headers))) {
      headers = newPropertyList();
    }
    headers->insertAt(wrapString("Host"), wrapString(host));
  }
  if (content != NULL) {
    if (!((boolean)(headers))) {
      headers = newPropertyList();
    }
    headers->insertAt(wrapString("Content-Length"), wrapString(integerToString(strlen(content))));
  }
  if (((boolean)(headers))) {
    { Object* key = NULL;
      Object* value = NULL;
      DictionaryIterator* iter000 = ((DictionaryIterator*)(headers->allocateIterator()));

      for  (key, value, iter000; 
            iter000->nextP(); ) {
        key = iter000->key;
        value = iter000->value;
        *(stream->nativeStream) << unwrapString(((StringWrapper*)(key))) << ": " << unwrapString(((StringWrapper*)(value))) << "\r" << "\n";
      }
    }
  }
  *(stream->nativeStream) << "\r" << "\n";
  if (content != NULL) {
    *(stream->nativeStream) << content;
  }
  flushOutput(stream);
}

void writePostRequest(OutputStream* stream, char* host, char* urlPath, Dictionary* headers, char* content) {
  writeHttpRequest(stream, "POST", host, urlPath, headers, content);
}

char* postData(char* host, int port, char* urlPath, Dictionary* headers, char* content) {
  // Posts `content' as data to `url-path' on `host' and `port'.
  // The port value for standard http servers is 80.  Returns the body of the
  // reply message as a string, if successful.  Otherwise an HTTP-EXCEPTION is
  // signaled.
  { KeyValueList* returnHeaders = newKeyValueList();

    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, false);
      { InputStream* in = NULL;
        OutputStream* out = NULL;

        try {
          in = openNetworkStream(host, port, out);
          writePostRequest(out, host, urlPath, headers, content);
          { int returnCode = NULL_INTEGER;
            char* returnMessage = NULL;
            char* version = NULL;

            returnCode = readHttpHeader(in, returnHeaders, returnMessage, version);
            version = version;
            if (returnCode == 200) {
              return (in->streamToString());
            }
            else {
              { HttpException* self001 = newHttpException(returnMessage);

                self001->errorCode = returnCode;
                { HttpException* ex = self001;

                  std::cout << "code = " << returnCode << "    message = " << returnMessage << "    version = " << version;
                  throw *ex;
                }
              }
            }
          }
        }
catch (...) {
          if (((boolean)(in))) {
            in->free();
          }
          if (((boolean)(out))) {
            out->free();
          }
          throw;
        }
        if (((boolean)(in))) {
          in->free();
        }
        if (((boolean)(out))) {
          out->free();
        }
      }
    }
  }
}

char* getWebPage(char* host, int port, char* urlPath, Dictionary* returnHeaders) {
  // Gets the webpage describe by path `url-path' on `host' and `port'.
  // The port value for standard http servers is 80.  If successful, 
  // returns the body of the web message as a string.  The headers
  // from the reply message will be set in `return-headers' if not
  // `null'.  If an error occurs an HTTP-EXCEPTION is signaled.
  if (!((boolean)(returnHeaders))) {
    returnHeaders = newKeyValueList();
  }
  { 
    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, false);
    { InputStream* in = NULL;
      OutputStream* out = NULL;

      try {
        in = openNetworkStream(host, port, out);
        writeHttpRequest(out, "GET", host, urlPath, NULL, NULL);
        { int returnCode = NULL_INTEGER;
          char* returnMessage = NULL;
          char* version = NULL;

          returnCode = readHttpHeader(in, returnHeaders, returnMessage, version);
          version = version;
          if (returnCode == 200) {
            return (in->streamToString());
          }
          else {
            { HttpException* self001 = newHttpException(returnMessage);

              self001->errorCode = returnCode;
              { HttpException* ex = self001;

                std::cout << "code = " << returnCode << "    message = " << returnMessage << "    version = " << version;
                throw *ex;
              }
            }
          }
        }
      }
catch (...) {
        if (((boolean)(in))) {
          in->free();
        }
        if (((boolean)(out))) {
          out->free();
        }
        throw;
      }
      if (((boolean)(in))) {
        in->free();
      }
      if (((boolean)(out))) {
        out->free();
      }
    }
  }
}

char* buildFullUrlHierarchicalPart(char* path, char* query, char* fragment) {
  if (stringEqlP(query, "")) {
    if (stringEqlP(fragment, "")) {
      return (path);
    }
    else {
      return (stringConcatenate(path, "#", 1, fragment));
    }
  }
  else {
    if (stringEqlP(fragment, "")) {
      return (stringConcatenate(path, "?", 1, query));
    }
    else {
      return (stringConcatenate(path, "?", 3, query, "#", fragment));
    }
  }
}

char* urlPathToFilename(char* path) {
  { char separator = directorySeparator();

    if (separator == '/') {
      return (unescapeUrlString(path));
    }
    else {
      {
        path = unescapeUrlString(stringSubstitute(path, separator, '/'));
        if ((operatingSystem() == KWD_HTTP_MAC) &&
            (path[0] == separator)) {
          path = stringSubsequence(path, 1, NULL_INTEGER);
        }
        return (path);
      }
    }
  }
}

InputStream* openUrlStream(char* url) {
  // Opens an input stream to `url'.
  // Currently only http: with no user name or password and file: urls on the local
  // host with absolute pathnames are supported.
  { char* protocol = NULL;
    char* userInfo = NULL;
    char* host = NULL;
    char* port = NULL;
    char* path = NULL;
    char* query = NULL;
    char* fragment = NULL;

    protocol = decomposeInternetUrl(url, userInfo, host, port, path, query, fragment);
    if (stringEqlP(protocol, "http")) {
      if (!stringEqlP(userInfo, "")) {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "Only URL without user information are supported: " << "`" << url << "'";
          throw *newBadArgumentException(stream000->theStringReader());
        }
      }
      else {
        { InputStream* in = NULL;
          OutputStream* out = NULL;
          KeyValueList* returnHeaders = newKeyValueList();

          in = openNetworkStream(host, ((!stringEqlP(port, "")) ? stringToInteger(port) : 80), out);
          writeHttpRequest(out, "GET", host, buildFullUrlHierarchicalPart(path, query, fragment), NULL, NULL);
          { int returnCode = NULL_INTEGER;
            char* returnMessage = NULL;
            char* version = NULL;

            returnCode = readHttpHeader(in, returnHeaders, returnMessage, version);
            version = version;
            if (returnCode == 200) {
              return (in);
            }
            else {
              { HttpException* self003 = newHttpException(returnMessage);

                self003->errorCode = returnCode;
                { HttpException* ex = self003;

                  std::cout << "code = " << returnCode << "    message = " << returnMessage << "    version = " << version;
                  if (((boolean)(in))) {
                    in->free();
                  }
                  if (((boolean)(out))) {
                    out->free();
                  }
                  throw *ex;
                }
              }
            }
          }
        }
      }
    }
    else if (stringEqlP(protocol, "file")) {
      if (!stringEqlP(userInfo, "")) {
        { OutputStringStream* stream001 = newOutputStringStream();

          *(stream001->nativeStream) << "Only URL without user information are supported: " << "`" << url << "'";
          throw *newBadArgumentException(stream001->theStringReader());
        }
      }
      else if (stringEqlP(host, "") ||
          stringEqlP(host, "localhost")) {
        return (newInputFileStream(urlPathToFilename(path)));
      }
      else {
        { OutputStringStream* stream002 = newOutputStringStream();

          *(stream002->nativeStream) << "Only file URLs on the local host are supported: " << "`" << url << "'";
          throw *newBadArgumentException(stream002->theStringReader());
        }
      }
    }
    else {
      { OutputStringStream* stream003 = newOutputStringStream();

        *(stream003->nativeStream) << "Only http and file URLs are supported: " << "`" << url << "'";
        throw *newBadArgumentException(stream003->theStringReader());
      }
    }
  }
}

Object* withInputUrl(Cons* binding, Cons* body) {
  // Sets up an unwind-protected form which opens a URL for
  // input and closes it afterwards.  The stream for reading is bound to the
  // variable provided in the macro form.
  // Syntax is `(WITH-INPUT-URL (var url) body+)'.
  { Symbol* var = ((Symbol*)(binding->value));

    return (listO(4, SYM_HTTP_STELLA_LET, cons(cons(var, listO(3, SYM_HTTP_STELLA_INPUT_STREAM, SYM_HTTP_STELLA_NULL, NIL)), NIL), listO(4, SYM_HTTP_STELLA_UNWIND_PROTECT, listO(3, SYM_HTTP_STELLA_PROGN, listO(3, SYM_HTTP_STELLA_SETQ, var, cons(listO(3, SYM_HTTP_UTILITIES_OPEN_URL_STREAM, binding->rest->value, NIL), NIL)), body->concatenate(NIL, 0)), listO(4, SYM_HTTP_STELLA_WHEN, listO(3, SYM_HTTP_STELLA_DEFINEDp, var, NIL), listO(3, SYM_HTTP_STELLA_FREE, var, NIL), NIL), NIL), NIL));
  }
}

void startupHttp() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/UTILITIES", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      KWD_HTTP_MAC = ((Keyword*)(internRigidSymbolWrtModule("MAC", NULL, 2)));
      SYM_HTTP_STELLA_LET = ((Symbol*)(internRigidSymbolWrtModule("LET", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_STELLA_INPUT_STREAM = ((Symbol*)(internRigidSymbolWrtModule("INPUT-STREAM", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_STELLA_NULL = ((Symbol*)(internRigidSymbolWrtModule("NULL", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_STELLA_UNWIND_PROTECT = ((Symbol*)(internRigidSymbolWrtModule("UNWIND-PROTECT", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_STELLA_PROGN = ((Symbol*)(internRigidSymbolWrtModule("PROGN", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_STELLA_SETQ = ((Symbol*)(internRigidSymbolWrtModule("SETQ", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_UTILITIES_OPEN_URL_STREAM = ((Symbol*)(internRigidSymbolWrtModule("OPEN-URL-STREAM", NULL, 0)));
      SYM_HTTP_STELLA_WHEN = ((Symbol*)(internRigidSymbolWrtModule("WHEN", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_STELLA_DEFINEDp = ((Symbol*)(internRigidSymbolWrtModule("DEFINED?", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_STELLA_FREE = ((Symbol*)(internRigidSymbolWrtModule("FREE", getStellaModule("/STELLA", true), 0)));
      SYM_HTTP_UTILITIES_STARTUP_HTTP = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-HTTP", NULL, 0)));
      SYM_HTTP_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
    }
    if (currentStartupTimePhaseP(5)) {
      { Class* clasS = defineClassFromStringifiedSource("HTTP-EXCEPTION", "(DEFCLASS HTTP-EXCEPTION (READ-EXCEPTION) :PUBLIC-SLOTS ((ERROR-CODE :TYPE INTEGER)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newHttpException));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("HANDLE-HTTP-HEADER-FIRST-LINE", "(DEFUN (HANDLE-HTTP-HEADER-FIRST-LINE STRING INTEGER STRING) ((LINE STRING) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Handles the first line of an http header.  \nReturns version, response code, response message.  The first\nline is inserted into `fields' fields with the empty string key \\\"\\\"\nThis is a low-level utility routine that can be used to build custom\nmessage parsing code.\")", ((cpp_function_code)(&handleHttpHeaderFirstLine)), NULL);
      defineFunctionObject("HANDLE-HTTP-HEADER-OTHER-LINE", "(DEFUN HANDLE-HTTP-HEADER-OTHER-LINE ((LINE STRING) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Handles header lines other than the first one.\nEach such line is inserted into `fields' as keyword value pairs.\nThis is a low-level utility routine that can be used to build custom\nmessage parsing code.\")", ((cpp_function_code)(&handleHttpHeaderOtherLine)), NULL);
      defineFunctionObject("DECOMPOSE-INTERNET-URL", "(DEFUN (DECOMPOSE-INTERNET-URL STRING STRING STRING STRING STRING STRING STRING) ((URL STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Takes an internet style URL and returns the components of\nthat URL as specified below.  Missing elements return the empty string \\\"\\\".\n  PROTOCOL USERNAME:PASSWORD DOMAIN PORT PATH QUERY FRAGMENT\n\n  o Protocol.  The access protocol.\n\n       Those schemes which refer to internet protocols mostly have a\n       common syntax for the rest of the object name. This starts with a\n       double slash '//' to indicate its presence, and continues until\n       the following slash '/':\n\n  o An optional user name, if required (as it is with a few FTP servers).\n    The password, if present, follows the user name, separated from it by a colon;\n    the user name and optional password are followed by a commercial at sign '@'. \n  o The internet domain name of the host\n  o The port number, if it is not the default number for the protocol,\n    is given in decimal notation after a col" "on.\n  o Path The path is a hierarchical representation of a particular path. It may \n    define details of how the client should communicate with the server, including\n    information to be passed transparently to the server without any processing by\n    the client.\n    The path is interpreted in a manner dependent on the scheme being used.\n    Generally, the reserved slash '/' character (ASCII 2F hex) denotes a level in a\n    hierarchical structure, the higher level part to the left of the slash.\n  o Query is the part of the hierarchical information following a '?' character.\n  o Fragment is the part of the hierarchical information following a '#' character.\n\nReferences:  http://www.gbiv.com/protocols/uri/rfc/rfc3986.html\n\")", ((cpp_function_code)(&decomposeInternetUrl)), NULL);
      defineFunctionObject("READ-HTTP-HEADER", "(DEFUN (READ-HTTP-HEADER INTEGER STRING STRING) ((STREAM INPUT-STREAM) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Reads the HTTP header from `stream', parses the header fields\nand stores the results in `fields'.  The first line of the response will be\nstored in `fields' with the empty string \\\"\\\" as the key.  Other values will\nhave the header name as the key.  The first return value is the response code\nof the HTTP request.  A response of 200 indicates success.  Other common\nresponses are 404 (page not found).  The second return value is the message\nassociated with the code.  The third return value is the version information.\nIf the stream ends before a valid header is read, then `null' is returned for\nall values.\")", ((cpp_function_code)(&readHttpHeader)), NULL);
      defineFunctionObject("WRITE-HTTP-REQUEST", "(DEFUN WRITE-HTTP-REQUEST ((STREAM OUTPUT-STREAM) (METHOD STRING) (HOST STRING) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Send `content' as an HTTP 1.0 request on `stream' using `method'.\nThe request is sent to `url-path' at `host'.  The `stream' must be a TCP-stream\nthat is connected to `host' at the appropriate port.\")", ((cpp_function_code)(&writeHttpRequest)), NULL);
      defineFunctionObject("WRITE-POST-REQUEST", "(DEFUN WRITE-POST-REQUEST ((STREAM OUTPUT-STREAM) (HOST STRING) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)))", ((cpp_function_code)(&writePostRequest)), NULL);
      defineFunctionObject("POST-DATA", "(DEFUN (POST-DATA STRING) ((HOST STRING) (PORT INTEGER) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Posts `content' as data to `url-path' on `host' and `port'.\nThe port value for standard http servers is 80.  Returns the body of the\nreply message as a string, if successful.  Otherwise an HTTP-EXCEPTION is\nsignaled.\")", ((cpp_function_code)(&postData)), NULL);
      defineFunctionObject("GET-WEB-PAGE", "(DEFUN (GET-WEB-PAGE STRING) ((HOST STRING) (PORT INTEGER) (URL-PATH STRING) (RETURN-HEADERS DICTIONARY)) :PUBLIC? TRUE :DOCUMENTATION \"Gets the webpage describe by path `url-path' on `host' and `port'.\nThe port value for standard http servers is 80.  If successful, \nreturns the body of the web message as a string.  The headers\nfrom the reply message will be set in `return-headers' if not\n`null'.  If an error occurs an HTTP-EXCEPTION is signaled.\")", ((cpp_function_code)(&getWebPage)), NULL);
      defineFunctionObject("BUILD-FULL-URL-HIERARCHICAL-PART", "(DEFUN (BUILD-FULL-URL-HIERARCHICAL-PART STRING) ((PATH STRING) (QUERY STRING) (FRAGMENT STRING)))", ((cpp_function_code)(&buildFullUrlHierarchicalPart)), NULL);
      defineFunctionObject("URL-PATH-TO-FILENAME", "(DEFUN (URL-PATH-TO-FILENAME STRING) ((PATH STRING)))", ((cpp_function_code)(&urlPathToFilename)), NULL);
      defineFunctionObject("OPEN-URL-STREAM", "(DEFUN (OPEN-URL-STREAM INPUT-STREAM) ((URL STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Opens an input stream to `url'.\nCurrently only http: with no user name or password and file: urls on the local\nhost with absolute pathnames are supported.\")", ((cpp_function_code)(&openUrlStream)), NULL);
      defineFunctionObject("WITH-INPUT-URL", "(DEFUN WITH-INPUT-URL ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a URL for\ninput and closes it afterwards.  The stream for reading is bound to the\nvariable provided in the macro form.\nSyntax is `(WITH-INPUT-URL (var url) body+)'.\")", ((cpp_function_code)(&withInputUrl)), NULL);
      defineFunctionObject("STARTUP-HTTP", "(DEFUN STARTUP-HTTP () :PUBLIC? TRUE)", ((cpp_function_code)(&startupHttp)), NULL);
      { MethodSlot* function = lookupFunction(SYM_HTTP_UTILITIES_STARTUP_HTTP);

        setDynamicSlotValue(function->dynamicSlots, SYM_HTTP_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupHttp"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
  }
}

Keyword* KWD_HTTP_MAC = NULL;

Symbol* SYM_HTTP_STELLA_LET = NULL;

Symbol* SYM_HTTP_STELLA_INPUT_STREAM = NULL;

Symbol* SYM_HTTP_STELLA_NULL = NULL;

Symbol* SYM_HTTP_STELLA_UNWIND_PROTECT = NULL;

Symbol* SYM_HTTP_STELLA_PROGN = NULL;

Symbol* SYM_HTTP_STELLA_SETQ = NULL;

Symbol* SYM_HTTP_UTILITIES_OPEN_URL_STREAM = NULL;

Symbol* SYM_HTTP_STELLA_WHEN = NULL;

Symbol* SYM_HTTP_STELLA_DEFINEDp = NULL;

Symbol* SYM_HTTP_STELLA_FREE = NULL;

Symbol* SYM_HTTP_UTILITIES_STARTUP_HTTP = NULL;

Symbol* SYM_HTTP_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella_utilities
