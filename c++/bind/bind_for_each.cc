#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

//普通函数
int print_add(int value, int num)
{
    std::cout << value + num << std::endl;
}

int main()
{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(3);

    
    std::cout << "---------使用auto对象保存std::bind返回的对象------------" << std::endl;
    auto func = std::bind(print_add, std::placeholders::_1, 222);
    std::for_each(vecInt.begin(), vecInt.end(), func); 

    std::cout << "---------直接将std::bind返回的对象用在std::for_each中------" << std::endl;
    std::for_each(vecInt.begin(),
                vecInt.end(),
                std::bind(print_add, std::placeholders::_1, 222));

    return 0;

}

