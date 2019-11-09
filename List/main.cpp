#include "List.hpp"
#include <iostream>

int main(int, char const **)
{
	List<int> my_list = List<int>();

	int a = 1;
	int b = 2;
	int c = 3;

	my_list.push_back(a);
	my_list.push_back(b);
	my_list.push_back(c);
	// my_list.pop_back();
	// my_list.pop_front();

	std::cout << my_list << std::endl;

	List<int>::ItList it = my_list.begin();
	while (it != my_list.end())
	{
		*it = 4;
		++it;
	}

	std::cout << my_list << std::endl;

	return 0;
}
