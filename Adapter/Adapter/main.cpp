#include <iostream>

/* 서로 다른 인터페이스를 하나로 통일시켜주는 패턴 */

class Adaptee
{
public:
	void Function() { std::cout << "Adaptee::Function()" << std::endl; }
};

class Adapter
{
public:
	virtual void Function() = 0;
};

class AdapterA : public Adapter
{
	Adaptee m_Adaptee;
public:
	void Function() override 
	{
		m_Adaptee.Function();
		std::cout << "AdapterA::Function()" << std::endl << std::endl;
	}
};
class AdapterB : public Adapter, public Adaptee
{
public:
	void Function() override 
	{
		Adaptee::Function();
		std::cout << "AdapterB::Function()" << std::endl << std::endl;
	}
};

void main()
{
	AdapterA l_AdapterA;
	AdapterB l_AdapterB;

	l_AdapterA.Function();
	l_AdapterB.Function();
}