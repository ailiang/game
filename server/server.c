#include "server.h"
#include "muduo/base/Logging.h"
#include <functional>

Server::Server(muduo::net::EventLoop* loop, const muduo::net::InetAddress& listenAddr ): _loop(loop), _server(loop, listenAddr, "Server")
{
	_server.setConnectionCallback( std::bind(&Server::OnConnection, this, std::placeholders::_1) );
	_server.setMessageCallback( std::bind(&Server::OnMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) );
}

void Server::Start()
{
	_server.start();
}

void Server::OnConnection( const muduo::net::TcpConnectionPtr& conn )
{
	LOG_INFO << "conn" ;

}

void Server::OnMessage( const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp time)
{
	LOG_INFO << "msg"; 
}
