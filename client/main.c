#include <iostream>
#include "client.h"

int main()
{
	muduo::net::EventLoop loop;
	muduo::net::InetAddress addr("127.0.0.1", 9999);
	Client cli( &loop, addr );
	cli.Connection();
	loop.loop();
}
