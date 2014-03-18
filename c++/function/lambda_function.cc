#include <iostream>
#include <functional>    //std::function需要的头文件
#include <algorithm>    //std::for_each需要的头文件
#include <vector>

int main()
{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(3);

    //lambda产生的闭包类型能隐式转换成std::function
    std::function<void(int)> func = 
        [](int val){ std::cout << val + 2 << std::endl; };

    std::for_each(vecInt.begin(), vecInt.end(), func);

    return 0;
}
