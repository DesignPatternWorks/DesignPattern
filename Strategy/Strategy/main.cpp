#include <iostream>
#include <memory>

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
	std::shared_ptr<Strategy> m_Strategy;
public:
	void SetStrategy(Strategy* Strategy_) { m_Strategy.reset(Strategy_); }
	void Function()
	{
		if (m_Strategy != nullptr)
			m_Strategy->Function();
	}
};

void main()
{
	Structure structure;
	
	structure.SetStrategy(new StrategyA);
	structure.Function();

	structure.SetStrategy(new StrategyB);
	structure.Function();
}