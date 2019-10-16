#include <iostream>

class M
{
  public:
	M()
	{
		std::cout << "M::M()" << std::endl;
	}
	~M()
	{
		std::cout << "M::~M()" << std::endl;
	}
	M(const M &)
	{
		std::cout << "M::M(const M&)" << std::endl;
	}
	M operator=(const M &other)
	{
		std::cout << "M::=" << std::endl;
		return M(other);
	}
};

class A
{
  private:
	M attr_;

  public:
	A()
	{
		std::cout << "A::A()" << std::endl;
	}
	~A()
	{
		std::cout << "A::~A()" << std::endl;
	}
	A(const A &)
	{
		std::cout << "A::A(const A&)" << std::endl;
	}
	A operator=(const A &other)
	{
		std::cout << "A::=" << std::endl;
		return A(other);
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
	F operator=(const F &other)
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
	A a2 = a1;

	return 0;
}