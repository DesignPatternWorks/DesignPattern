#include <iostream>

class Prototype
{
public:
	virtual Prototype* Clone() = 0;
};

class Concrete1 : public Prototype
{
public:
	Concrete1() = default;
	Concrete1(Concrete1 &) = default;
	Concrete1(Concrete1 &&) = default;

	Prototype* Clone() override { return new Concrete1(*this); }
};

class Concrete2 : public Prototype
{
public:
	Concrete2() = default;
	Concrete2(Concrete2 &) = default;
	Concrete2(Concrete2 &&) = default;

	Prototype* Clone() override { return new Concrete2(*this); }
};

void main()
{
	Prototype *Original1(new Concrete1), *Original2(new Concrete2), 
		*Clone1(nullptr), *Clone2(nullptr);

	Clone1 = Original1->Clone();
	Clone2 = Original2->Clone();

	delete Original1;
	delete Original2;
	delete Clone1;
	delete Clone2;
}