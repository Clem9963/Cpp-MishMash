#include "B.hpp"
#include "A.hpp"

B::B(int j)
	:j_(j)
{}

void B::send(A& a) const
{
	a.exec(j_);
}

void B::exec(int j)
{
	j_ += j;
}
