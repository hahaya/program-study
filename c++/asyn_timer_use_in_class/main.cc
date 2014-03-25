/*
 * 成员函数绑定到async_wait
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class print
{
public:
    //此处需要传递引用 因为io_service禁止拷贝
    print(boost::asio::io_service &io) : timer_(io, boost::posix_time::seconds(1)), count_(0)
    { timer_.async_wait(boost::bind(&print::printer, this, boost::asio::placeholders::error)); }

    ~print()
    { std::cout << "final count:" << count_ << std::endl; }

private:
    void printer(const boost::system::error_code&)
    { 
        if ( count_ < 10 )
        {
            std::cout << "count:" << count_ << std::endl;
            ++count_;
            timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
            timer_.async_wait(boost::bind(&print::printer, this, boost::asio::placeholders::error));
        }
    }

private:
    boost::asio::deadline_timer timer_;
    int count_;
};

int main()
{
    boost::asio::io_service io;
    print p(io);
    io.run();
    return 0;
}
