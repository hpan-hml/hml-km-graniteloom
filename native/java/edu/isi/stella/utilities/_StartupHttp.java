//  -*- Mode: Java -*-
//
// _StartupHttp.java

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

package edu.isi.stella.utilities;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

public class _StartupHttp {
  public static void startupHttp() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/UTILITIES", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Utilities.KWD_MAC = ((Keyword)(Stella.internRigidSymbolWrtModule("MAC", null, 2)));
          Utilities.SYM_STELLA_LET = ((Symbol)(Stella.internRigidSymbolWrtModule("LET", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_STELLA_INPUT_STREAM = ((Symbol)(Stella.internRigidSymbolWrtModule("INPUT-STREAM", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_STELLA_NULL = ((Symbol)(Stella.internRigidSymbolWrtModule("NULL", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_STELLA_UNWIND_PROTECT = ((Symbol)(Stella.internRigidSymbolWrtModule("UNWIND-PROTECT", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_STELLA_PROGN = ((Symbol)(Stella.internRigidSymbolWrtModule("PROGN", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_STELLA_SETQ = ((Symbol)(Stella.internRigidSymbolWrtModule("SETQ", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_UTILITIES_OPEN_URL_STREAM = ((Symbol)(Stella.internRigidSymbolWrtModule("OPEN-URL-STREAM", null, 0)));
          Utilities.SYM_STELLA_WHEN = ((Symbol)(Stella.internRigidSymbolWrtModule("WHEN", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_STELLA_DEFINEDp = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFINED?", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_STELLA_FREE = ((Symbol)(Stella.internRigidSymbolWrtModule("FREE", Stella.getStellaModule("/STELLA", true), 0)));
          Utilities.SYM_UTILITIES_STARTUP_HTTP = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-HTTP", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("HTTP-EXCEPTION", "(DEFCLASS HTTP-EXCEPTION (READ-EXCEPTION) :PUBLIC-SLOTS ((ERROR-CODE :TYPE INTEGER)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.stella.utilities.HttpException", "newHttpException", new java.lang.Class [] {Native.find_java_class("java.lang.String")});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("HANDLE-HTTP-HEADER-FIRST-LINE", "(DEFUN (HANDLE-HTTP-HEADER-FIRST-LINE STRING INTEGER STRING) ((LINE STRING) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Handles the first line of an http header.  \nReturns version, response code, response message.  The first\nline is inserted into `fields' fields with the empty string key \\\"\\\"\nThis is a low-level utility routine that can be used to build custom\nmessage parsing code.\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "handleHttpHeaderFirstLine", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Dictionary"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("HANDLE-HTTP-HEADER-OTHER-LINE", "(DEFUN HANDLE-HTTP-HEADER-OTHER-LINE ((LINE STRING) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Handles header lines other than the first one.\nEach such line is inserted into `fields' as keyword value pairs.\nThis is a low-level utility routine that can be used to build custom\nmessage parsing code.\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "handleHttpHeaderOtherLine", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Dictionary")}), null);
          Stella.defineFunctionObject("DECOMPOSE-INTERNET-URL", "(DEFUN (DECOMPOSE-INTERNET-URL STRING STRING STRING STRING STRING STRING STRING) ((URL STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Takes an internet style URL and returns the components of\nthat URL as specified below.  Missing elements return the empty string \\\"\\\".\n  PROTOCOL USERNAME:PASSWORD DOMAIN PORT PATH QUERY FRAGMENT\n\n  o Protocol.  The access protocol.\n\n       Those schemes which refer to internet protocols mostly have a\n       common syntax for the rest of the object name. This starts with a\n       double slash '//' to indicate its presence, and continues until\n       the following slash '/':\n\n  o An optional user name, if required (as it is with a few FTP servers).\n    The password, if present, follows the user name, separated from it by a colon;\n    the user name and optional password are followed by a commercial at sign '@'. \n  o The internet domain name of the host\n  o The port number, if it is not the default number for the protocol,\n    is given in decimal notation after a colon.\n  o Path The path is a hierarchical representation of a particular path. It may \n    define details of how the client should communicate with the server, including\n    information to be passed transparently to the server without any processing by\n    the client.\n    The path is interpreted in a manner dependent on the scheme being used.\n    Generally, the reserved slash '/' character (ASCII 2F hex) denotes a level in a\n    hierarchical structure, the higher level part to the left of the slash.\n  o Query is the part of the hierarchical information following a '?' character.\n  o Fragment is the part of the hierarchical information following a '#' character.\n\nReferences:  http://www.gbiv.com/protocols/uri/rfc/rfc3986.html\n\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "decomposeInternetUrl", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("READ-HTTP-HEADER", "(DEFUN (READ-HTTP-HEADER INTEGER STRING STRING) ((STREAM INPUT-STREAM) (FIELDS (DICTIONARY OF STRING-WRAPPER STRING-WRAPPER))) :PUBLIC? TRUE :DOCUMENTATION \"Reads the HTTP header from `stream', parses the header fields\nand stores the results in `fields'.  The first line of the response will be\nstored in `fields' with the empty string \\\"\\\" as the key.  Other values will\nhave the header name as the key.  The first return value is the response code\nof the HTTP request.  A response of 200 indicates success.  Other common\nresponses are 404 (page not found).  The second return value is the message\nassociated with the code.  The third return value is the version information.\nIf the stream ends before a valid header is read, then `null' is returned for\nall values.\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "readHttpHeader", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputStream"), Native.find_java_class("edu.isi.stella.Dictionary"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("WRITE-HTTP-REQUEST", "(DEFUN WRITE-HTTP-REQUEST ((STREAM OUTPUT-STREAM) (METHOD STRING) (HOST STRING) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Send `content' as an HTTP 1.0 request on `stream' using `method'.\nThe request is sent to `url-path' at `host'.  The `stream' must be a TCP-stream\nthat is connected to `host' at the appropriate port.\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "writeHttpRequest", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputStream"), Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Dictionary"), Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("WRITE-POST-REQUEST", "(DEFUN WRITE-POST-REQUEST ((STREAM OUTPUT-STREAM) (HOST STRING) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)))", Native.find_java_method("edu.isi.stella.utilities.Utilities", "writePostRequest", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputStream"), Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Dictionary"), Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("POST-DATA", "(DEFUN (POST-DATA STRING) ((HOST STRING) (PORT INTEGER) (URL-PATH STRING) (HEADERS DICTIONARY) (CONTENT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Posts `content' as data to `url-path' on `host' and `port'.\nThe port value for standard http servers is 80.  Returns the body of the\nreply message as a string, if successful.  Otherwise an HTTP-EXCEPTION is\nsignaled.\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "postData", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE, Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Dictionary"), Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("GET-WEB-PAGE", "(DEFUN (GET-WEB-PAGE STRING) ((HOST STRING) (PORT INTEGER) (URL-PATH STRING) (RETURN-HEADERS DICTIONARY)) :PUBLIC? TRUE :DOCUMENTATION \"Gets the webpage describe by path `url-path' on `host' and `port'.\nThe port value for standard http servers is 80.  If successful, \nreturns the body of the web message as a string.  The headers\nfrom the reply message will be set in `return-headers' if not\n`null'.  If an error occurs an HTTP-EXCEPTION is signaled.\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "getWebPage", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE, Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Dictionary")}), null);
          Stella.defineFunctionObject("BUILD-FULL-URL-HIERARCHICAL-PART", "(DEFUN (BUILD-FULL-URL-HIERARCHICAL-PART STRING) ((PATH STRING) (QUERY STRING) (FRAGMENT STRING)))", Native.find_java_method("edu.isi.stella.utilities.Utilities", "buildFullUrlHierarchicalPart", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("URL-PATH-TO-FILENAME", "(DEFUN (URL-PATH-TO-FILENAME STRING) ((PATH STRING)))", Native.find_java_method("edu.isi.stella.utilities.Utilities", "urlPathToFilename", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("OPEN-URL-STREAM", "(DEFUN (OPEN-URL-STREAM INPUT-STREAM) ((URL STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Opens an input stream to `url'.\nCurrently only http: with no user name or password and file: urls on the local\nhost with absolute pathnames are supported.\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "openUrlStream", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("WITH-INPUT-URL", "(DEFUN WITH-INPUT-URL ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a URL for\ninput and closes it afterwards.  The stream for reading is bound to the\nvariable provided in the macro form.\nSyntax is `(WITH-INPUT-URL (var url) body+)'.\")", Native.find_java_method("edu.isi.stella.utilities.Utilities", "withInputUrl", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("STARTUP-HTTP", "(DEFUN STARTUP-HTTP () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.utilities._StartupHttp", "startupHttp", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Utilities.SYM_UTILITIES_STARTUP_HTTP);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Utilities.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupHttp"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
