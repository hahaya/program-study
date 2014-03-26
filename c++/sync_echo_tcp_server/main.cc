/*
 * 同步Echo Tcp服务器
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

int main()
{
    using boost::asio::ip::tcp;
    
    boost::asio::io_service io;
    //服务端 等待连接 故用acceptor
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 2121));

    std::cout << "start server." << std::endl;

    //循环等待连接
    while(true)
    {
        tcp::socket socket(io);
        acceptor.accept(socket);
        boost::array<char, 128> buf;
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        if (boost::asio::error::eof == error)   //读取完成
            break;
        else if (error)
            throw boost::system::error_code(error);

        //客户端ip
        std::string client_ip = socket.remote_endpoint().address().to_v4().to_string();
        std::cout << "Recv Data From[" << client_ip << "]:" << buf.data() << std::endl;

        //将数据发送给客户端
        socket.write_some(boost::asio::buffer(buf));
    }

    return 0;
}
