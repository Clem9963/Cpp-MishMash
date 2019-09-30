#ifndef CPP3_B_H_
#define CPP3_B_H_

class A;

class B
{
	int j_;

public:
	B(int j);
	void send(A& a) const;
	void exec(int j);
};

#endif
