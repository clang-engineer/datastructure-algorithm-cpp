#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

template <typename T>
auto compute_waiting_times(std::vector<T>& service_times)
{
    std::vector<T> W(service_times.size());
    W[0] = 0;

    for (auto i = 1; i < service_times.size(); i++)
	W[i] = W[i - 1] + service_times[i - 1];

    return W;
}

template <typename T>
void print_vector(std::vector<T>& V)
{  
    for (auto& i : V)
    {
	std::cout.width(2);
	std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void compute_and_print_waiting_times(std::vector<T>& service_times)
{
    auto waiting_times = compute_waiting_times<int>(service_times);

    std::cout << "- service time list: ";
    print_vector<T>(service_times);

    std::cout << "- wainting itme list: ";
    print_vector<T>(waiting_times);

    auto ave_waiting_times = std::accumulate(waiting_times.begin(), waiting_times.end(), 0.0) / waiting_times.size();
    std::cout << "- avg waiting times: " << ave_waiting_times << std::endl;
}

int main()
{
    std::vector<int> service_times {8, 1, 2, 4, 9, 2, 3, 5};

    std::cout << "[service times & waiting times before sorting]" << std::endl;
    compute_and_print_waiting_times(service_times);
    std::cout << std::endl;

    std::cout << "[service times & waiting times after sorting]" << std::endl;
    std::sort(service_times.begin(), service_times.end());
    compute_and_print_waiting_times(service_times);
    std::cout << std::endl;
    return 0;
}

