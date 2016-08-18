#include <iostream>

/* 동적으로 알고리즘을 교체할 수 있도록 만들어진 패턴 */

class Strategy
{
public:
	virtual void Function() = 0;
};

class StrategyA : public Strategy
{
public:
	void Function() override
	{
		std::cout << "StrategyA::Function()" << std::endl;
	}
};

class StrategyB : public Strategy
{
public:
	void Function() override
	{
		std::cout << "StrategyB::Function()" << std::endl;
	}
};

class Structure
{
	Strategy* m_pStrategy;
public:
	Structure() : m_pStrategy(nullptr) {}
	~Structure()
	{
		if (m_pStrategy != nullptr)
		{
			delete m_pStrategy;
			m_pStrategy = nullptr;
		}
	}

	void SetStrategy(Strategy* pStrategy) { m_pStrategy = pStrategy; }
	void Function()
	{
		if (m_pStrategy != nullptr)
			m_pStrategy->Function();
	}
};

void main()
{
	Structure l_Structure;
	
	l_Structure.SetStrategy(new StrategyA);
	l_Structure.Function();

	l_Structure.SetStrategy(new StrategyB);
	l_Structure.Function();
}