#ifndef CPP3_A_H_
#define CPP3_A_H_

class B;

class A
{
	int i_;

public:
	A(int i);
	void send(B& b) const;
	void exec(int i);
};

#endif
