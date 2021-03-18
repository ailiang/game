#include <iostream>
#include "server.h"

int main()
{
	muduo::net::EventLoop loop;
	muduo::net::InetAddress addr(9999);
	Server serv( &loop, addr );
	serv.Start();
	loop.loop();
	std::cout << "hello my game\n";
}
