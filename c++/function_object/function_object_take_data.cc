#include <iostream>
#include <vector>
#include <algorithm>

class Add
{
public:
    Add(int num) : num_(num) 
    { } 

    void operator()(int value) 
    { std::cout << value + num_ << std::endl; }

private:
    int num_;
};

int main()
{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(3);

    Add add(2);
    //std::for_each的第3个对象为函数对象
    std::for_each(vecInt.begin(), vecInt.end(), add);
}
