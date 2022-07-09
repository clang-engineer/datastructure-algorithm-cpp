#include <iostream>
#include <forward_list>
#include <vector>

int main() {
    std::vector<std::string> vec = {
        "Kim", "Lee", "Park", "Hong", 
        "Choi", "Ki", "Ko", "Lim", "Hwang"
    };

    auto it = vec.begin();
    std::cout << "vec begin: " << *it << std::endl;

    it+=8;
    std::cout << "iter + 8: " << *it << std::endl;
    
    advance(it, -3);
    std::cout << "advance(it, -3): " << *it << std::endl;

    std::cout << std::endl;

    std::forward_list<std::string> fwd(vec.begin(), vec.end());

    auto it1 = fwd.begin();
    std::cout << "vec begin: " << *it1 << std::endl;

    advance(it1, 5);
    std::cout << "advance(it1, 5): " << *it1 << std::endl;
    
    advance(it1, -3);
    std::cout << "advance(it1, -3): " << *it1 << std::endl;
}
