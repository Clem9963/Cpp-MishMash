#include "A.hpp"
#include "B.hpp"

int main(int, const char **)
{
	A monA(2);
	B monB(4);

	monA.send(monB);
	monB.send(monA);

	return 0;
}
