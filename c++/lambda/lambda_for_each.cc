#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(3);

    std::for_each(vecInt.begin(), 
                  vecInt.end(), 
                  [](int x){ std::cout << x + 2 << std::endl; });
}
