#include <iostream>

/* 객체와 메소드를 분리하여 캡슐화하는 목적으로 사용하는 패턴 */

class Receiver
{
public:
	void Action() { std::cout << "Receiver::Action()" << std::endl; }
};

class Command
{
public:
	virtual void Execute() = 0;
};

class ConcreteCommand : public Command
{
	Receiver* m_pReceiver;
public:
	ConcreteCommand() : m_pReceiver(nullptr) {}
	void SetReceiver(Receiver* pReceiver) 
	{
		if (m_pReceiver != nullptr)
		{
			delete m_pReceiver;
			m_pReceiver = nullptr;
		}
		m_pReceiver = pReceiver;
	}
	void Execute() override { m_pReceiver->Action(); }
};

class Invoker
{
	Command* m_pCommand;
public:
	Invoker() : m_pCommand(nullptr) {}
	void SetCommand(Command* pCommand) 
	{
		if (m_pCommand != nullptr)
		{
			delete m_pCommand;
			m_pCommand = nullptr;
		}
		m_pCommand = pCommand;
	}
	void Execute() { m_pCommand->Execute(); }
};

void main()
{
	Invoker l_Invoker;
	Receiver l_Receiver;
	ConcreteCommand l_Command;

	l_Command.SetReceiver(&l_Receiver);
	l_Invoker.SetCommand(&l_Command);
	l_Invoker.Execute();
}