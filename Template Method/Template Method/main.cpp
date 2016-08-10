#include <iostream>
#include <string>

class AbstractClass
{
protected:
	void Function1() { std::cout << "AbstractClass::Function1()" << std::endl; }
	virtual void Function2() = 0;
	virtual void Function3() = 0;
public:
	void Function()
	{
		Function1();
		Function2();
		Function3();
	}
};

class ConcreteClassA : public AbstractClass
{
protected:
	void Function2() override { std::cout << "ConcreteClassA::Function2()" << std::endl; }
	void Function3() override { std::cout << "ConcreteClassA::Function3()" << std::endl; }
};

class ConcreteClassB : public AbstractClass
{
protected:
	void Function2() override { std::cout << "ConcreteClassB::Function2()" << std::endl; }
	void Function3() override { std::cout << "ConcreteClassB::Function3()" << std::endl; }
};

void main()
{
	AbstractClass *l_pClassA(new ConcreteClassA), *l_pClassB(new ConcreteClassB);

	l_pClassA->Function();
	l_pClassB->Function();

	delete l_pClassA;
	delete l_pClassB;
	l_pClassA = nullptr;
	l_pClassB = nullptr;
}