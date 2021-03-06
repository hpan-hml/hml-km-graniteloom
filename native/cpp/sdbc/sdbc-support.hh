//  -*- Mode: C++ -*-

/*--------------------------- BEGIN LICENSE BLOCK ---------------------------+
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
+---------------------------- END LICENSE BLOCK ----------------------------*/

// Version: sdbc-support.hh,v 1.7 2010/10/11 22:35:15 hans Exp

// Header file for sdbc-support.cc


#include <sql.h>
#include <sqlext.h>
#include <iostream>

namespace sdbc {
  using namespace stella;

  class NativeConnection : public gc {
    // A native C++ object which holds ODBC connection variables.
  public:
    SQLHENV* henv;
    SQLHDBC* hdbc;
    SQLHSTMT* hstmt;
    int connected;    // 1 if connected, 0 otherwise.
  };

  class NativeResultSet : public gc {
    // A native C++ object which holds enough state to simulate a result set
  public:
    SQLHENV* henv;
    SQLHDBC* hdbc;
    SQLHSTMT* hstmt;
    Cons* types;
    short numCols;
    int done;
  };

  NativeConnection* getConnection(char* connectionString);

  void nativeDisconnect(sdbc::NativeConnection* nativeConnection);

  Object* executeSQL(sdbc::NativeConnection* nativeConnection, char* sqlRequest, Cons* types);

  NativeResultSet* getNativeResultSet(NativeConnection* nativeConnection, char* sqlRequest, Cons* types);

  Cons* fetchRow(NativeResultSet* resultSet);

  void setAutocommitFlag(NativeConnection* nativeConnection, boolean flag);

  void doCommit(NativeConnection* nativeConnection);

  void doRollback(NativeConnection* nativeConnection);

  void doPrepareStatement(NativeConnection* nativeConnection, char* sql);

  Object* doExecutePreparedStatement(NativeConnection* nativeConnection);

  void doBindParameter(NativeConnection* nativeConnection, int position, Surrogate* typespec, Object* value);

  Wrapper* doGetServerInfo(NativeConnection* nativeConnection, char* property);

  void initializeSymbols();

} // end namespace sdbc
