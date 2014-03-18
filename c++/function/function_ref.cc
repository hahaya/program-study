#include <iostream>
#include <functional> //std::function需要的头文件
#include <algorithm>
#include <vector>

int main()
{
    //std::reference_wrapper封装int内置类型
    int number = 1;
    std::reference_wrapper<int> rw(number);
    std::cout << "Number:" << rw.get() << std::endl;

    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(3);

    //std::ref只能用于左值 最下面一行代码直接使用std::ref引用lambda表达式目前是编译不过的
    //所以先用auto func对象保存lambda表达式返回的闭包对象 再std::for_each再对func进行引用
    auto func = [](int val){std::cout << val + 2 << std::endl;};
    std::for_each(vecInt.begin(), vecInt.end(), std::ref(func));
    //std::for_each(vecInt.begin(), vecInt.end(),
            //std::ref( [](int val){std::cout << val + 2 << std::endl;} ));
}
