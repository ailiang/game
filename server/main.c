#include <iostream>
#include "server.h"
#include "db.h"
#include "cpp_redis/cpp_redis"
#include "cpp_redis/misc/macro.hpp"

int main()
{
	//init db
	Mdb db;
	db.CreateTable("test1");
	db.CreateTable("test2");

	//redis
	cpp_redis::client re_client;
	re_client.connect("127.0.0.1", 6379, [](const std::string& host, std::size_t port, cpp_redis::connect_state status  ){
			if( status ==  cpp_redis::connect_state::dropped )
			{
			std::cout << " redis connect droped \n";
			}
			});
	re_client.set("name", "cal");
	re_client.sync_commit();

	muduo::net::EventLoop loop;
	muduo::net::InetAddress addr(9999);
	Server serv( &loop, addr );
	serv.Start();
	loop.loop();
	std::cout << "hello my game\n";
}
