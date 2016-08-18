#include <iostream>

/* 객체와 객체의 상태에 따른 행동을 변경할 수 있도록 캡슐화한 패턴 */

class State
{
public:
	virtual void Function() = 0;
};

class ConcreteStateA : public State
{
public:
	void Function() override { std::cout << "ConcreteStateA::Function()" << std::endl; }
};

class ConcreteStateB : public State
{
public:
	void Function() override { std::cout << "ConcreteStateB::Function()" << std::endl; }
};

class Context
{
	State* m_pState;
public:
	Context() : m_pState(nullptr) {}
	~Context()
	{
		if (m_pState != nullptr)
		{
			delete m_pState;
			m_pState = nullptr;
		}
	}

	void SetState(State* pState)
	{
		if (m_pState != nullptr)
		{
			delete m_pState;
			m_pState = nullptr;
		}
		m_pState = pState;
	}
	void Function() { m_pState->Function(); }
};

void main()
{
	Context* l_pContext(new Context);

	l_pContext->SetState(new ConcreteStateA);
	l_pContext->Function();
	
	l_pContext->SetState(new ConcreteStateB);
	l_pContext->Function();

	delete l_pContext;
	l_pContext = nullptr;
	
}