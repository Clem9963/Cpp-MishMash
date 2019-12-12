#include "ZZ.hpp"
#include <iostream>
#include <queue>
#include <vector>

int main(int, char const **)
{
	std::vector<ZZ> zz;

	zz.push_back(ZZ("jean", "dupond", 12.5));
	zz.push_back(ZZ("michel", "tartanpion", 14.7));
	zz.push_back(ZZ("alice", "riviere", 9.5));
	zz.push_back(ZZ("julien", "duport", 5.5));
	zz.push_back(ZZ("elise", "martine", 19.1));

	std::priority_queue<ZZ> tri;

	for (std::vector<ZZ>::iterator it = zz.begin(); it != zz.end(); ++it)
		tri.push(*it);

	while (!tri.empty())
	{
		std::cout << tri.top() << " ";
		tri.pop();
	}
	std::cout << std::endl;
}
