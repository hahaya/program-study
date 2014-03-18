#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    //eg1 直接输出hello lambda. 
    //尾部的()使该lambda表达式可立即执行
    //前面的lambda表达式产生一个匿名对象 结合后面的()相当与一个无參的函数调用
    []{ std::cout << "hello lambda." << std::endl; }();

    //eg2 该lambda表达式接收一个const std::string&类型的参数
    //返回一个std::string类型的值 结果保存在lambda_return变量中
    //尾部的("hahaya")表示传入一个"hahaya"参数使lambda表达式立即执行
    std::string lambda_return = [](const std::string &str)->std::string{
            return "hello " + str; }("hahaya");
    std::cout << lambda_return << std::endl;

    //eg3 该lambda表达式接收一个const std::string&类型的参数
    //lambda表示式的返回值通过return语句推导
    //lambda表达式产生一个匿名对象 保存在func对象中
    auto func = [](const std::string &str){ return "hello " + str; };
    std::cout << func("ToSmile") << std::endl;
    std::cout << func("C++") << std::endl;

    //eg4 按传值的方式捕获外部变量 
    //需要加上mutable关键字 否则不能在lambda表达式中修改total的值
    //由于是传值方式  所以在lambda表达式外部total的值并没有改变 但是在lambda表达式内部改变了
    int total = 0;
    [total](int num)mutable{ total += num; std::cout << total << std::endl; }(2);
    std::cout << "capture by value:" << total << std::endl;

    //eg5 按传引用的方式捕获外部变量
    //不需要加上mutable关键字
    //由于是传引用方式 所以在lambda表达式内部和外部都在total的值改变了
    [&total](int num){ total += num; std::cout << total << std::endl; }(2);
    std::cout << "capture by reference:" << total << std::endl;

    //eg6 lambda和stl的配合使用
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(3);
    std::for_each(vecInt.begin(), vecInt.end(), [](int val){std::cout << val + 2 << std::endl;});

    std::cout << std::endl;
    std::vector<int> secInt;
    secInt.push_back(7);
    secInt.push_back(8);

    //eg7 lambda和stl的配合使用 先保存匿名对象后调用
    auto add_func = [](int val){std::cout << val + 2 << std::endl; };
    std::for_each(secInt.begin(), secInt.end(), add_func);


    return 0;
}
