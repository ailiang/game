#include <stdlib.h>
#include <iostream>
#include "db.h"

using namespace std;

void MdbConnPool::InitPool( int size )
{
	driver = get_driver_instance();
	for( int i = 0; i < size; ++i )
	{
		auto con = driver->connect("tcp://127.0.0.1:3306", "cal", "123");
		con->setSchema( "test" );
		conns.push_back(con);
	}
}

sql::Connection* MdbConnPool::GetConnection()
{
	if( conns.empty() ) return nullptr;
	auto con = conns.front();
	conns.pop_front();
	return con;
}

void MdbConnPool::Releseconnection( sql::Connection* con )
{
	if( !con ) return ;
	conns.push_back( con );
}

int Mdb::CreateTable(const std::string& table)
{
	auto conn = MdbConnPool::GetInstance().GetConnection();
	if( conn == nullptr ) return -1;
	std::unique_ptr<sql::Statement> stmt( conn->createStatement() );
	if( !stmt ) return -2;

	std::string sql( "DROP TABLE IF EXISTS " );
	sql += table ;
	stmt->execute( sql );
	sql = string(" CREATE TABLE ") + table + string("(id INT)");
	stmt->execute( sql );
	return 0;
}

Mdb::Mdb()
{
	MdbConnPool::GetInstance().InitPool( 5 );
}

void test()
{
	cout << endl;
	cout << "Let's have MySQL count from 10 to 1..." << endl;

	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "123");
		/* Connect to the MySQL test database */
		con->setSchema("test");

		stmt = con->createStatement();
		stmt->execute("DROP TABLE IF EXISTS test");
		stmt->execute("CREATE TABLE test(id INT)");
		delete stmt;

		/* '?' is the supported placeholder syntax */
		pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
		for (int i = 1; i <= 10; i++) {
			pstmt->setInt(1, i);
			pstmt->executeUpdate();
		}
		delete pstmt;

		/* Select in ascending order */
		pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
		res = pstmt->executeQuery();

		/* Fetch in reverse = descending order! */
		res->afterLast();
		while (res->previous())
			cout << "\t... MySQL counts: " << res->getInt("id") << endl;
		delete res;

		delete pstmt;
		delete con;

	} catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << 
			" )" << endl;
	}

	cout << endl;

}


