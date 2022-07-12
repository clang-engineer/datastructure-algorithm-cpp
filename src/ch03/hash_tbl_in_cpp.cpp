#include <iostream>
#include <unordered_map>
#include <unordered_set>

void print(const std::unordered_set<int>& container)
{
    for (const auto& element : container)
        std::cout << element << " ";
    std::cout << std::endl;
}

void print(const std::unordered_map<int, int>& container)
{
    for (const auto& element : container)
        std::cout << element.first << " : " << element.second << ", ";

    std::cout << std::endl; 
}

void find(const std::unordered_set<int>& container, const int element)
{
    if (container.find(element) == container.end())
        std::cout << element << " search -> failed" << std::endl;
    else
        std::cout << element << " search -> succeed" << std::endl;
}

void find(const std::unordered_map<int,int>& container, const int element)
{
    auto it = container.find(element);

    if (it == container.end())
        std::cout << element << " search -> failed" << std::endl;
    else
        std::cout << element << " search -> succeed" << std::endl;
}

int main()
{
    std::cout << "*** std::unordered_set example ***" << std::endl;
    std::unordered_set<int> set1 = {1, 2, 3, 4, 5};

    std::cout << "set1 init value >> "; print(set1);

    set1.insert(2);
    std::cout << "2 inserted >> "; print(set1);

    set1.insert(10);
    set1.insert(300);
    std::cout << "10, 300 inserted >> "; print(set1);

    find(set1, 4);
    find(set1, 100);

    set1.erase(2);
    std::cout << "2 removed >> "; print(set1);

    find(set1, 2);


    std::cout << "*** std::unordered_map example ***" << std::endl;
    std::unordered_map<int, int> squareMap;

    squareMap.insert({2, 4});
    squareMap[3] = 9;
    std::cout << "insert square of 2, 3 >> "; print(squareMap);

    squareMap[20] = 400;
    squareMap[30] = 900;
    std::cout << "insert square of 20, 30 >> "; print(squareMap);

    find(squareMap, 10);
    find(squareMap, 20);
    std::cout << "squareMap[3] = " << squareMap[3] << std::endl;
    std::cout << "squareMap[100] = " << squareMap[100] << std::endl;
    print(squareMap);
}
