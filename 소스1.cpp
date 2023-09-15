#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <ranges>
#include <algorithm>
using namespace std;

template <typename... Args>
int sum(Args... args)
{
	return (args + ...);
}

int main()
{
	cout << sum(1, 2, 3,4,5,6,7,8,9,10);
}