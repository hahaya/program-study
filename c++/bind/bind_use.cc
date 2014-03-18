#include <iostream>
#include <functional>

//带有引用参数的普通函数
void display(int first, int &second)
{
    std::cout << "first: " << first << " second:" << second << std::endl;
}

//普通函数
int get_number(int number)
{
    return number;
}

class Test
{
public:
    Test(int num) : num_(num)
    { }

    //静态成员函数
    static void say_hello()
    { std::cout << "hello"  << std::endl; }

    //成员函数
    void print_add(int value)
    { std::cout << "add:" << value + num_ << std::endl; }

public:
    int num_;
};

int main()
{
    //绑定普通函数
    //使用auto接收std::bind的返回值
    std::cout << "绑定普通函数" << std::endl;
    auto bind_comm_func = std::bind(get_number, std::placeholders::_1);
    std::cout << bind_comm_func(2) << std::endl;
    //使用std::function接收std::bind的返回值
    std::function<int(int)> bind_comm_func_1 = std::bind(get_number, std::placeholders::_1);
    std::cout << bind_comm_func_1(22) << std::endl;
    std::cout << "绑定普通函数" << std::endl;


    //绑定带有引用参数的普通函数
    std::cout << "绑定带有引用参数的普通函数" << std::endl;
    int value = 22222;
    //auto
    auto bind_ref_func = std::bind(display, std::placeholders::_1, std::ref(value));
    bind_ref_func(1111);
    //std::bind
    std::function<void(int)> bind_ref_func_1 = std::bind(display, std::placeholders::_1, std::ref(value));
    bind_ref_func_1(22222);
    std::cout << "绑定带有引用参数的普通函数" << std::endl;

    
    //绑定静态成员函数
    std::cout << "绑定静态成员函数" << std::endl;
    //auto
    auto bind_static_member_func = std::bind(&Test::say_hello);
    bind_static_member_func();
    //std::function
    std::function<void(void)> bind_static_member_func_1 = std::bind(&Test::say_hello);
    bind_static_member_func();
    std::cout << "绑定静态成员函数" << std::endl;

    //绑定成员函数 需要多传递一个函数对象 故先需要创建函数对象
    std::cout << "绑定成员函数" << std::endl;
    //auto
    Test test(2);
    auto bind_member_func = std::bind(&Test::print_add, test, std::placeholders::_1);
    bind_member_func(2);
    //std::function
    std::function<void(int)> bind_member_func_1 = std::bind(&Test::print_add, test, std::placeholders::_1);
    bind_member_func_1(3);
    std::cout << "绑定成员函数" << std::endl;

    //绑定public成员变量
    std::cout << "绑定public成员变量" << std::endl;
    //auto
    auto bind_member_data = std::bind(&Test::num_, std::placeholders::_1);
    std::cout << bind_member_data(test) << std::endl;
    //int a = bind_member_data(test);
    //std::cout << "a" <<  a << std::endl;
    //std::function
    std::function<int(Test)> bind_member_data_1 = std::bind(&Test::num_, std::placeholders::_1);
    std::cout << bind_member_data_1(test) << std::endl;
    std::cout << "绑定public成员变量" << std::endl;
    
    return 0;
}
