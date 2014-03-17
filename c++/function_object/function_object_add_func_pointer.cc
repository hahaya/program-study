#include <iostream>

int add_func(int a, int b)
{
    return a + b;
}

//函数对象
class AddClass
{
public:
    int operator()(int a, int b) { return a + b; }
};

//函数指针
typedef int (*AddFunction)(int a, int b);

int main()
{
    //为了方便对比 将函数对象和函数指针声明了同名变量 
    //为了防止报错 故两个同名变量都有各自的作用域 每个的作用域在各自的{}中
    //通过后面的调用发现两者调用方式是一样的 都是通过add(1, 2)调用    
    {
        //函数对象的使用
        AddClass add;
        int sum = add(1, 2);
        std::cout << "Sum:" << sum << std::endl;
    }

    {
        //函数指针的使用
        AddFunction add = &add_func;
        int sum = add(2, 2);
        std::cout << "Sum:" << sum << std::endl;
    }

    return 0;
}
