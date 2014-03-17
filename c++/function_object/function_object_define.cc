#include <iostream>

//普通函数
int add(int a, int b)
{
    return a + b;
}

//函数对象类
class FunctionObjectDefine
{
public:
    int operator()(int a, int b) { return a + b; };
};

int main()
{
    FunctionObjectDefine func;
    int total = add(1, 2);
    int sum = func(1, 2); //是不是和普通函数add(1, 2)调用方式一样
    std::cout << "Total:" << total << std::endl;
    std::cout << "Sum:" << sum << std::endl;
    return 0;
}
