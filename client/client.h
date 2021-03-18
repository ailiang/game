
#include "muduo/net/TcpClient.h"
#include "muduo/net/EventLoop.h"

class Client
{
public:
	Client(muduo::net::EventLoop* loop, const muduo::net::InetAddress& listenAddr );
	void Connection();
	void OnConnection( const muduo::net::TcpConnectionPtr& conn );
	void OnMessage( const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp time);
private:
	muduo::net::EventLoop *_loop;
	muduo::net::TcpClient _client;
};
