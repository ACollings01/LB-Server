#include <windows.h>
#include <stdio.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>

struct DBCredentials
{
	const char* dsnName;
	const char* userID;
	const char* password;
	char* retVal[256];
	unsigned int cbData;
};

// Following this tutorial for now while I figure this stuff out https://www.dreamincode.net/forums/topic/21309-cpp-with-odbc-open-database-connectivity/

int main()
{
	DBCredentials LBDB;

	LBDB.dsnName = "LBServer";
	LBDB.userID = "TeamAqua";
	LBDB.password = "1sjjmmddghgensjj12m44mm6b7bvv954nddi87cjd7";

	SQLHANDLE hdlEnv, hdlConn, hdlStmt, hdlDbc;
	SQLINTEGER output_nts;

	char statement[] = "SELECT * from LeaderBoard";

	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hdlEnv);
	SQLSetEnvAttr(hdlEnv, SQL_ATTR_OUTPUT_NTS, (SQLPOINTER)output_nts, 0);
	SQLAllocHandle(SQL_HANDLE_DBC, hdlEnv, &hdlConn);
	SQLConnect(hdlConn, (SQLCHAR*)LBDB.dsnName, SQL_NTS, (SQLCHAR*)LBDB.userID, SQL_NTS, (SQLCHAR*)LBDB.password, SQL_NTS);
	SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc, &hdlStmt);
	SQLExecDirect(hdlStmt, (SQLCHAR*)statement, SQL_NTS);
}