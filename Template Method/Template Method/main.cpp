#include <iostream>
#include <string>

/* 상위 클래스에서 흐름을 제어하고 하위 클래스에서 구체화하는 패턴
하위 클래스들의 공통적인 내용은 상위 클래스에 정의하고 클래스별로 상세한 내용을 하위 클래스에서 구현한다 */

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
	void Function3() override { std::cout << "ConcreteClassA::Function3()" << std::endl << std::endl; }
};

class ConcreteClassB : public AbstractClass
{
protected:
	void Function2() override { std::cout << "ConcreteClassB::Function2()" << std::endl; }
	void Function3() override { std::cout << "ConcreteClassB::Function3()" << std::endl << std::endl; }
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