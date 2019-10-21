#include <iostream>

class M
{
  private:
	int _nb;

  public:
	M()
	{
		std::cout << "M::M()" << std::endl;
		_nb = 42;
	}
	~M()
	{
		std::cout << "M::~M()" << std::endl;
	}
	M(const M &other)
		: _nb(other._nb)
	{
		std::cout << "M::M(const M&)" << std::endl;
	}
	M &operator=(const M &other)
	{
		std::cout << "M::=" << std::endl;
		_nb = other._nb;
		return *this;
	}
};

class A
{
  private:
	M _attr;

  public:
	A()
	{
		std::cout << "A::A()" << std::endl;
	}
	~A()
	{
		std::cout << "A::~A()" << std::endl;
	}
	A(const A &other)
		: _attr(other._attr)
	{
		std::cout << "A::A(const A&)" << std::endl;
	}
	A &operator=(const A &other)
	{
		std::cout << "A::=" << std::endl;
		_attr = other._attr;
		return *this;
	}
};

class F : public M
{
  public:
	F()
	{
		std::cout << "F::F()" << std::endl;
	}
	~F()
	{
		std::cout << "F::~F()" << std::endl;
	}

	F(const F &f)
		: M(f)
	{
		std::cout << "F::F(const F&)" << std::endl;
	}
	F &operator=(const F &other)
	{
		std::cout << "F::=" << std::endl;
		M::operator=(other);
		return *this;
	}
};

int main(int, char **)
{
	/*
	F f1;
	F f2 = f1;

	f1 = f2;
	*/

	A a1;
	A a2;
	a2 = a1;

	return 0;
}