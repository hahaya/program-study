/*
 *  给async_wait添加额外的参数
 *
 */

#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

void print(const boost::system::error_code&, 
        boost::asio::deadline_timer *t, int *count)
{
    if (*count < 10)
    {
        std::cout << "count:" << *count << std::endl;
        ++(*count);
        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));
    }
}

int main()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(1));
    int count = 0;
    timer.async_wait(boost::bind(print, boost::asio::placeholders::error, &timer, &count));
    io.run();
    return 0;
}
