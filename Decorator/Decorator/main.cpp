#include <iostream>

/* 동적으로 객체에 추가적인 기능을 가진 객체들을 붙여줄 수 있게 하는 패턴 */

class Component
{
public:
	virtual void Function() = 0;
};

class ConcreteComponent : public Component
{
public:
	void Function() override { std::cout << "ConcreteComponent::Function()" << std::endl << std::endl; }
};

class Decorator : public Component
{
	Component* m_pComponent;
public:
	Decorator(Component* pComponent) : m_pComponent(pComponent) {}
	~Decorator()
	{
		if (m_pComponent != nullptr)
		{
			delete m_pComponent;
			m_pComponent = nullptr;
		}
	}

	void Function() override
	{
		if (m_pComponent != nullptr)
			m_pComponent->Function();
	}
};

class DecoratorA : public Decorator
{
public:
	DecoratorA(Component* pComponent) : Decorator(pComponent) {}
	void Function()
	{
		std::cout << "DeoratorA::Function()" << std::endl;
		Decorator::Function();
	}
};

class DecoratorB : public Decorator
{
public:
	DecoratorB(Component* pComponent) : Decorator(pComponent) {}
	void Function()
	{
		std::cout << "DeoratorB::Function()" << std::endl;
		Decorator::Function();
	}
};

void main()
{
	Component* l_pComponent(new DecoratorA(new DecoratorB(new ConcreteComponent)));
	l_pComponent->Function();

	delete l_pComponent;
	l_pComponent = nullptr;
}