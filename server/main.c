#include <iostream>
#include "server.h"
#include "db.h"

int main()
{
	//init db
	Mdb db;
	db.CreateTable("test1");
	db.CreateTable("test2");
	
	muduo::net::EventLoop loop;
	muduo::net::InetAddress addr(9999);
	Server serv( &loop, addr );
	serv.Start();
	loop.loop();
	std::cout << "hello my game\n";
}
