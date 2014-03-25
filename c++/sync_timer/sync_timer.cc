/*
 * note：   同步定时器的使用
 * useage:  mkdir build
 *          cd build
 *          cmake ..
 *          make
 */
#include <iostream>
#include <boost/asio.hpp>

int main()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));
    timer.wait();
    std::cout << "hello asio." << std::endl;
    return 0;
}

