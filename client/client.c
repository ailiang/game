#include "client.h"
#include "muduo/base/Logging.h"
#include <functional>

Client::Client(muduo::net::EventLoop* loop, const muduo::net::InetAddress& listenAddr ): _loop(loop), _client(loop, listenAddr, "Client")
{
	_client.setConnectionCallback( std::bind(&Client::OnConnection, this, std::placeholders::_1) );
	_client.setMessageCallback( std::bind(&Client::OnMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) );
}

void Client::Connection()
{
	_client.connect();
}

void Client::OnConnection( const muduo::net::TcpConnectionPtr& conn )
{
	LOG_INFO << "conn" ;
	if( !conn->connected() )
	{
		_loop->quit();
	}
}

void Client::OnMessage( const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp time)
{
	LOG_INFO << "msg"; 
}
