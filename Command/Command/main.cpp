#include <iostream>

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
	void SetReceiver(Receiver* pReceiver) { m_pReceiver = pReceiver; }
	void Execute() override { m_pReceiver->Action(); }
};

class Invoker
{
	Command* m_pCommand;
public:
	void SetCommand(Command* pCommand) { m_pCommand = pCommand; }
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