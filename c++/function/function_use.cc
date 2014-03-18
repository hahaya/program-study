#include <iostream>
#include <functional>

//类
class PrintNum
{
public:
    PrintNum(int num) : num_(num) { }
    void print_add(int val) const
    { std::cout << num_ + val << std::endl; }

private:
    int num_;
};

//普通函数
void print_num(int val)
{ std::cout << val << std::endl; }

int main()
{
    //保存返回值为void、一个int参数的普通函数并调用
    std::function<void(int)> fun_display = print_num;
    fun_display(2);

    //保存成员函数并调用 成员函数中有一隐藏的this指针
    std::function<void(const PrintNum&, int)> func_class = &PrintNum::print_add;
    PrintNum printNum(2);
    func_class(printNum, 2);

    //保存lambda表达式并调用
    std::function<void(void)> func_lambda = 
        []{ std::cout << "hello std::function" << std::endl; };
    func_lambda();

    //保存std::bind绑定表达式并调用
    std::function<void()> func_bind = std::bind(print_num, 22);
    func_bind();

    return 0;
}
