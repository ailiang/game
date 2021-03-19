#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <list>

class MdbConnPool
{
public:
	static MdbConnPool& GetInstance() 
	{
		static MdbConnPool _inst;
		return _inst;
	}
	void InitPool( int size );
	sql::Connection* GetConnection();
	void Releseconnection( sql::Connection* con );
private:
	sql::Driver *driver;
	std::list<sql::Connection*> conns;
};

class Mdb
{
public:
	Mdb();
	int CreateTable(const std::string& table);
	bool Update();
	bool del();
	void find();
private:
};
