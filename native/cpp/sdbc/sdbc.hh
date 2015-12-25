//  -*- Mode: C++ -*-

// sdbc.hh

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

// Header files and macros:
#include "sdbc/sdbc-support.hh"

namespace sdbc {
  using namespace stella;

// Class definitions:
class Connection : public StandardObject {
public:
  sdbc::NativeConnection* nativeConnection;
  char* connectionString;
  char* protocol;
  // Indicates to what kind of DBMS we are connected.
  Keyword* dbmsName;
  // Prepared statement associated with this connection.
  PreparedStatement* statement;
  // State of connection's auto-commit feature.
  boolean autoCommitP;
  // Time at which connection was created.
  CalendarDate* creationTime;
  // Time at which connection was last accessed.
  CalendarDate* lastAccessTime;
  // Time at or after which connection should be renewed.
  CalendarDate* renewalTime;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
};

class PreparedStatement : public StandardObject {
public:
  Connection* connection;
  NativePreparedStatement* statement;
  char* sql;
  // Stores parameters bound so far to support connection renewal.
  KeyValueList* parameters;
public:
  virtual Surrogate* primaryType();
};

class NativePreparedStatement : public gc {
};

class DatabaseException : public StellaException {
public:
  DatabaseException(const std::string& msg) : StellaException(msg) {
}

};

class ResultSetIterator : public Iterator {
// Iterator class for a table returned by a SQL query.
public:
  NativeResultSet* resultSet;
  Cons* types;
public:
  virtual Surrogate* primaryType();
  virtual boolean nextP();
};

class TableInfo : public StandardObject {
public:
  char* database;
  char* schema;
  char* name;
  char* type;
  char* remarks;
  List* columns;
public:
  virtual Surrogate* primaryType();
};

class ColumnInfo : public StandardObject {
public:
  char* database;
  char* schema;
  char* tableName;
  char* name;
  // SQL type from java.sql.Types.
  int dataType;
  // Data source dependent type name, for a UDT the type name is fully qualified.
  char* dataTypeName;
  // Column size. For char or date types this is the maximum number of characters,
  // for numeric or decimal types this is precision.
  int columnSize;
  // Not used.
  int bufferLength;
  // The number of fractional digits.
  int decimalDigits;
  // Radix (typically either 10 or 2).
  int radix;
  // TRUE means definitely allows NULL values, FALSE means might not allow
  // NULL values, NULL means nullability unknown.
  BooleanWrapper* nullableP;
  // TRUE means might allow NULL values, FALSE means definitely does not
  // allow NULL values, NULL means nullability unknown.
  BooleanWrapper* isNullableP;
  // Comment describing column (may be null).
  char* documentation;
  char* defaultValue;
  // Not used.
  int sqlDataType;
  // Not used.
  int sqlDatetimeSub;
  // For char types the maximum number of bytes in the column.
  int charOctetLength;
  // Index of column in table (starting at 1).
  int ordinalPosition;
public:
  virtual Surrogate* primaryType();
};


// Global declarations:
extern int oDB_CONNECTION_RENEWAL_INTERVALo;
extern DECLARE_STELLA_SPECIAL(oSQL_COMMAND_TEMPLATESo, KeyValueMap* );
extern char* oSQL_CMD_TEMPLATE_VARIABLE_PREFIXo;

// Function signatures:
Connection* newConnection();
Object* accessConnectionSlotValue(Connection* self, Symbol* slotname, Object* value, boolean setvalueP);
PreparedStatement* newPreparedStatement();
Object* accessPreparedStatementSlotValue(PreparedStatement* self, Symbol* slotname, Object* value, boolean setvalueP);
DatabaseException* newDatabaseException(char* message);
ResultSetIterator* newResultSetIterator();
Object* accessResultSetIteratorSlotValue(ResultSetIterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Connection* connect(Cons* keysAndValues);
Connection* connectEvaluatorWrapper(Cons* arguments);
Connection* callConnect(Cons* keysAndValues);
int ODbConnectionRenewalIntervalOSetter(int value);
int getMaxConnectionLifetime(Connection* con);
void maybeRenewConnection(Connection* con);
boolean jdbcConnectionStringP(char* string);
char* makeJdbcConnectionString(PropertyList* options);
boolean odbcConnectionStringP(char* string);
char* makeOdbcConnectionString(PropertyList* options);
sdbc::NativeConnection* clNativeOdbcConnect(char* connectionstring, char*& _Return1);
sdbc::NativeConnection* clNativeClsqlConnect(PropertyList* options, char* serverType, char*& _Return1);
void disconnect(Connection* connection);
void clNativeDisconnect(sdbc::NativeConnection* nativeConnection);
void clNativeOdbcDisconnect(sdbc::NativeConnection* nativeconnection);
void clNativeClsqlDisconnect(sdbc::NativeConnection* nativeConnection);
boolean sqlQueryP(char* sqlExpression);
Object* stellifyWithNilToNull(Object* self);
Object* clTranslateSqlParameterTypeSpecifier(Object* stellatype);
Object* clTranslateSqlTypeSpecifier(Object* stellatype);
Cons* clTranslateSqlTypeSpecifiers(Cons* stellatypes);
Object* executeSql(Connection* connection, Object* sql, Cons* options);
Object* executeSqlEvaluatorWrapper(Cons* arguments);
Object* clExecuteSql(sdbc::NativeConnection* connection, char* sql, Cons* types);
Object* clDoExecutePreparedStatement(sdbc::NativeConnection* connection, PreparedStatement* sql);
ResultSetIterator* getResultSet(Connection* connection, char* sql, int options, ...);
NativeResultSet* clGetNativeResultSet(sdbc::NativeConnection* connection, char* sql, Cons* types);
char* sqlEscapeString(char* value, char quotechar);
char sqlQuoteCharacter(Keyword* dbmsName, Keyword* lexicaltype);
void printValueList(OutputStream* stream, Cons* values, char quotechar);
void insertRow(Connection* connection, char* table, Cons* columns, Cons* values);
void insertRowEvaluatorWrapper(Cons* arguments);
void insertRows(Connection* connection, char* table, Cons* columns, Cons* rows);
void insertRowsEvaluatorWrapper(Cons* arguments);
Cons* coerceUncoercedValuesInTable(Cons* table, Cons* types);
Cons* coerceUncoercedColumnValues(Cons* row, Cons* types);
Object* convertStringToTypedObject(char* valuestring, GeneralizedSymbol* typespec);
PreparedStatement* prepareStatement(Connection* connection, char* sql);
PreparedStatement* prepareStatementEvaluatorWrapper(Cons* arguments);
void bindParameter(PreparedStatement* statement, int position, Surrogate* typespec, Object* value);
void bindParameterEvaluatorWrapper(Cons* arguments);
void clDoBindParameter(PreparedStatement* statement, int position, Surrogate* typespec, Object* value);
void setAutoCommit(Connection* connection, boolean flag);
void setAutoCommitEvaluatorWrapper(Cons* arguments);
void commit(Connection* connection);
void rollback(Connection* connection);
TableInfo* newTableInfo();
Object* accessTableInfoSlotValue(TableInfo* self, Symbol* slotname, Object* value, boolean setvalueP);
ColumnInfo* newColumnInfo();
Object* accessColumnInfoSlotValue(ColumnInfo* self, Symbol* slotname, Object* value, boolean setvalueP);
Cons* getTables(Connection* connection, char* catalogName, char* schemaName, char* tableName, char* tableType);
Cons* getTablesEvaluatorWrapper(Cons* arguments);
Cons* getColumns(Connection* connection, char* catalogname, char* schemaname, char* tablename, char* columnname);
Cons* getColumnsEvaluatorWrapper(Cons* arguments);
Wrapper* getServerInfo(Connection* connection, char* property);
Wrapper* getServerInfoEvaluatorWrapper(Cons* arguments);
char* guessDbmsName(Connection* connection);
Keyword* getDbmsName(Connection* connection);
void printTable(Object* table);
char* calendarDateToSqlString(CalendarDate* date);
void loadSqlCmdTemplates(char* file);
void insertSqlCommandTemplate(PropertyList* templatE);
PropertyList* lookupSqlCmdTemplate(Object* commandname, Object* datasource);
char* instantiateSqlCmd(Object* cmdname, Object* datasource, int varsAvalues, ...);
char* instantiateSqlCmdTemplate(char* templatE, KeyValueList* variables);
char* readSqlCmdTemplateVariable(char* templatE, int start, int end, int& _Return1);
char* instantiateSqlCmdTemplateVariable(char* templatevariable, KeyValueList* variables);
char* parseSqlCmdTemplateVariableRangeAndDefault(char* templatevariable, char* variablename, int start, int& _Return1, int& _Return2, char*& _Return3);
void testPreparedStatement();
void testTransactions();
void testResultSet();
void testRetrieveAll();
void helpStartupSdbc1();
void helpStartupSdbc2();
void helpStartupSdbc3();
void helpStartupSdbc4();
void startupSdbc();

// Auxiliary global declarations:
extern Keyword* KWD_SDBC_LOG_LEVELS;
extern Keyword* KWD_SDBC_LEVEL;
extern Keyword* KWD_SDBC_NONE;
extern Keyword* KWD_SDBC_MAX_WIDTH;
extern Surrogate* SGT_SDBC_SDBC_CONNECTION;
extern Symbol* SYM_SDBC_SDBC_CONNECTION_STRING;
extern Symbol* SYM_SDBC_SDBC_PROTOCOL;
extern Symbol* SYM_SDBC_SDBC_DBMS_NAME;
extern Symbol* SYM_SDBC_SDBC_STATEMENT;
extern Symbol* SYM_SDBC_SDBC_AUTO_COMMITp;
extern Symbol* SYM_SDBC_SDBC_CREATION_TIME;
extern Symbol* SYM_SDBC_SDBC_LAST_ACCESS_TIME;
extern Symbol* SYM_SDBC_SDBC_RENEWAL_TIME;
extern Surrogate* SGT_SDBC_SDBC_PREPARED_STATEMENT;
extern Symbol* SYM_SDBC_SDBC_CONNECTION;
extern Symbol* SYM_SDBC_SDBC_SQL;
extern Symbol* SYM_SDBC_STELLA_PARAMETERS;
extern Symbol* SYM_SDBC_SDBC_RDBMS_ROW;
extern Surrogate* SGT_SDBC_SDBC_RESULT_SET_ITERATOR;
extern Symbol* SYM_SDBC_SDBC_TYPES;
extern Keyword* KWD_SDBC_PROTOCOL;
extern Keyword* KWD_SDBC_SERVER_TYPE;
extern Keyword* KWD_SDBC_LOW;
extern Keyword* KWD_SDBC_CONNECTION_STRING;
extern Keyword* KWD_SDBC_HOST;
extern Keyword* KWD_SDBC_PORT;
extern Keyword* KWD_SDBC_DB_NAME;
extern Keyword* KWD_SDBC_DSN;
extern Keyword* KWD_SDBC_USER;
extern Keyword* KWD_SDBC_PASSWORD;
extern Keyword* KWD_SDBC_WHITE_SPACE;
extern Keyword* KWD_SDBC_LETTER;
extern Symbol* SYM_SDBC_STELLA_NULL;
extern Surrogate* SGT_SDBC_STELLA_CALENDAR_DATE;
extern Surrogate* SGT_SDBC_STELLA_STRING;
extern Surrogate* SGT_SDBC_STELLA_INTEGER;
extern Surrogate* SGT_SDBC_STELLA_LONG_INTEGER;
extern Surrogate* SGT_SDBC_STELLA_DOUBLE_FLOAT;
extern Keyword* KWD_SDBC_TYPES;
extern Keyword* KWD_SDBC_HIGH;
extern Keyword* KWD_SDBC_STRING_CONSTANT;
extern Keyword* KWD_SDBC_IDENTIFIER;
extern Keyword* KWD_SDBC_MYSQL;
extern Keyword* KWD_SDBC_NULL;
extern Symbol* SYM_SDBC_STELLA_DEFAULT;
extern Keyword* KWD_SDBC_DEFAULT;
extern Keyword* KWD_SDBC_ORACLE;
extern Surrogate* SGT_SDBC_STELLA_WRAPPER;
extern Surrogate* SGT_SDBC_SDBC_TABLE_INFO;
extern Symbol* SYM_SDBC_SDBC_DATABASE;
extern Symbol* SYM_SDBC_SDBC_CATALOG;
extern Symbol* SYM_SDBC_SDBC_SCHEMA;
extern Symbol* SYM_SDBC_STELLA_NAME;
extern Symbol* SYM_SDBC_STELLA_TYPE;
extern Symbol* SYM_SDBC_SDBC_REMARKS;
extern Symbol* SYM_SDBC_SDBC_COLUMNS;
extern Surrogate* SGT_SDBC_SDBC_COLUMN_INFO;
extern Symbol* SYM_SDBC_STELLA_TABLE_NAME;
extern Symbol* SYM_SDBC_SDBC_DATA_TYPE;
extern Symbol* SYM_SDBC_SDBC_DATA_TYPE_NAME;
extern Symbol* SYM_SDBC_SDBC_COLUMN_SIZE;
extern Symbol* SYM_SDBC_SDBC_BUFFER_LENGTH;
extern Symbol* SYM_SDBC_SDBC_DECIMAL_DIGITS;
extern Symbol* SYM_SDBC_SDBC_RADIX;
extern Symbol* SYM_SDBC_SDBC_NULLABLEp;
extern Symbol* SYM_SDBC_SDBC_IS_NULLABLEp;
extern Symbol* SYM_SDBC_STELLA_DOCUMENTATION;
extern Symbol* SYM_SDBC_STELLA_DEFAULT_VALUE;
extern Symbol* SYM_SDBC_SDBC_SQL_DATA_TYPE;
extern Symbol* SYM_SDBC_SDBC_SQL_DATETIME_SUB;
extern Symbol* SYM_SDBC_SDBC_CHAR_OCTET_LENGTH;
extern Symbol* SYM_SDBC_SDBC_ORDINAL_POSITION;
extern Keyword* KWD_SDBC_COMMAND;
extern Keyword* KWD_SDBC_DATA_SOURCE;
extern Keyword* KWD_SDBC_SQL;
extern Keyword* KWD_SDBC_OTHERWISE;
extern Surrogate* SGT_SDBC_STELLA_CONS;
extern Keyword* KWD_SDBC_DIGIT;
extern Keyword* KWD_SDBC_CONNECTIONSTRING;
extern Symbol* SYM_SDBC_SDBC_STARTUP_SDBC;
extern Symbol* SYM_SDBC_STELLA_METHOD_STARTUP_CLASSNAME;

// Function signatures:
int main();

} // end of namespace sdbc
