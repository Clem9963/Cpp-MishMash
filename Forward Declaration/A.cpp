#include "A.hpp"
#include "B.hpp"

A::A(int i)
	:i_(i)
{}

void A::send(B& b) const
{
	b.exec(i_);
}

void A::exec(int i)
{
	i_ += i;
}
