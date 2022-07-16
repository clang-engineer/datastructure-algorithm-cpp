#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>


void transoform_test(std::vector<int> S)
{
    std::vector<int> Tr;
    std::cout << "[Map Test]" << std::endl;
    std::cout << "Input Array, S: " << std::endl;
    for (auto i : S)
        std::cout << i << " ";
    std::cout << std::endl;

    std::transform(S.begin(), S.end(), std::back_inserter(Tr),
            [](int x) {return std::pow(x, 2.0);});

    std::cout << "std::transform(), Tr: ";
    for (auto i : Tr)
	std::cout << i << " ";
    std::cout << std::endl;

    std::for_each(S.begin(), S.end(),
	    [](int& x) { x = std::pow(x, 2.0);});

    std::cout << "std::for_each(), S: ";
    for (auto i : S)
	std::cout << i << " ";
    std::cout << std::endl;
}

void reduce_test(std::vector<int> S)
{
    std::cout << std::endl << "[Reduce Test]" << std::endl;
    std::cout << "Input Array, S: " << std::endl;
    for (auto i : S)
	std::cout << i << " ";
    std::cout << std::endl;

    auto ans = std::accumulate(S.begin(), S.end(), 0, 
	    [](int acc, int x) {return acc + x;});
    std::cout << "std::accumulate(), ans: " << ans << std::endl;
}

int main()
{
    std::vector<int> S {1, 10, 4, 7, 3, 5, 6, 9, 8, 2};

    transoform_test(S);
    reduce_test(S);
    return 0;
}
