
#include "muduo/net/TcpServer.h"
#include "muduo/net/EventLoop.h"

class Server
{
public:
	Server(muduo::net::EventLoop* loop, const muduo::net::InetAddress& listenAddr );
	void Start();
	void OnConnection( const muduo::net::TcpConnectionPtr& conn );
	void OnMessage( const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buf, muduo::Timestamp time);
private:
	muduo::net::EventLoop *_loop;
	muduo::net::TcpServer _server;
};
