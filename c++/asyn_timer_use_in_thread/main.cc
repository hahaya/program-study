/**
 *  在多线程中使用async_wait
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

class printer
{
public:
    //io_service不是线程安全的 要保证线程安全性需要使用strand
    //io_service复制构造函数不可用 故此处应该传递引用
    printer(boost::asio::io_service &io) 
        : strand_(io),
          timer1_(io, boost::posix_time::seconds(1)),
          timer2_(io, boost::posix_time::seconds(1)),
          count_(0)
    { 
        timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, 
                        this, boost::asio::placeholders::error)));
        timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, 
                        this, boost::asio::placeholders::error)));
    }

private:
    void print1(const boost::system::error_code&)
    {
        if (count_ < 20)
        {
            std::cout << "Timer1:" << count_ << std::endl;
            timer1_.expires_at(timer1_.expires_at() + boost::posix_time::seconds(1));
            ++count_;
            timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, 
                            this, boost::asio::placeholders::error)));
        }
    }

    void print2(const boost::system::error_code&)
    {
        if (count_ < 20)
        {
            std::cout << "Timer2:" << count_ << std::endl;
            timer2_.expires_at(timer2_.expires_at() + boost::posix_time::seconds(1));
            ++count_;
            timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, 
                            this, boost::asio::placeholders::error)));
        }
    }
private:
    boost::asio::strand strand_;
    boost::asio::deadline_timer timer1_;
    boost::asio::deadline_timer timer2_;
    int count_;
};

int main()
{
    boost::asio::io_service io;
    printer p(io);
    boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
    io.run();
    t.join();
    return 0;
}
