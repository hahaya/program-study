/*
 *  异步Echo TCP服务端
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/array.hpp>

class TcpConnection : public boost::enable_shared_from_this<TcpConnection>
{
public:
    static boost::shared_ptr<TcpConnection> create(boost::asio::io_service &io)
    { return boost::shared_ptr<TcpConnection>(new TcpConnection(io)); }

    void start()
    {
        socket_.async_read_some(boost::asio::buffer(message_),
                boost::bind(&TcpConnection::handle_read, shared_from_this(),boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }

    boost::asio::ip::tcp::socket& socket()
    { return socket_; }

private:
    TcpConnection(boost::asio::io_service &io) : socket_(io)
    { }

    void handle_read(const boost::system::error_code&, size_t)
    {
        std::string client_ip = socket_.remote_endpoint().address().to_v4().to_string();
        std::cout << "Recv Data From[" << client_ip << "]:" << message_.data() << std::endl;
    }

private:
    boost::asio::ip::tcp::socket socket_;
    boost::array<char, 128> message_;
};

class TcpServer
{
public:
    TcpServer(boost::asio::io_service &io) 
        : acceptor_(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 2121))
    { this->start();  }

private:
    void start()
    {
        boost::shared_ptr<TcpConnection> new_connection = 
            TcpConnection::create(acceptor_.get_io_service());

        acceptor_.async_accept(new_connection->socket(),
                boost::bind(&TcpServer::handle_accept, this, new_connection, boost::asio::placeholders::error));
    }

    void handle_accept(boost::shared_ptr<TcpConnection> new_connection, const boost::system::error_code &error)
    {
        if (!error)
            new_connection->start();

        this->start();
    }
private:
    boost::asio::ip::tcp::acceptor acceptor_;
};

int main()
{
    boost::asio::io_service io;
    TcpServer server(io);
    io.run();

    return 0;
}
