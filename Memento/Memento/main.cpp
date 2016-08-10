#include <iostream>
#include <string>
#include <stack>

class Memento
{
	std::string m_strState;
public:
	Memento(std::string State) : m_strState(State) {}

	std::string GetState() const { return m_strState; }
};

class Originator
{
	std::string m_strState;
public:
	void SetState(std::string State)
	{
		m_strState = State;
		std::cout << "Originator::SetState(" << m_strState << ")" << std::endl;
	}
	void SetMemento(Memento* Memento_)
	{
		if (Memento_ != nullptr)
		{
			m_strState = Memento_->GetState();
			delete Memento_;
			Memento_ = nullptr;
			std::cout << "Originator::SetMemento(" << m_strState << ")" << std::endl;
		}
	}
	Memento* CreateMemento()
	{
		std::cout << "Originator::CreateMemento(" << m_strState << ")" << std::endl;
		return new Memento(m_strState);
	}
};

class Caretaker
{
	std::stack<Memento*> m_Stack;
public:
	void PushMemento(Memento* pMemento) { m_Stack.push(pMemento); }
	Memento* PopMemento() 
	{
		Memento* pMemento = m_Stack.top();
		m_Stack.pop();
		return pMemento;
	}
};

void main()
{
	Caretaker l_Caretaker;
	Originator* l_pOriginator(new Originator);

	l_pOriginator->SetState("State1");
	l_Caretaker.PushMemento(l_pOriginator->CreateMemento());

	l_pOriginator->SetState("State2");
	l_Caretaker.PushMemento(l_pOriginator->CreateMemento());

	l_pOriginator->SetMemento(l_Caretaker.PopMemento());
	l_pOriginator->SetMemento(l_Caretaker.PopMemento());

	delete l_pOriginator;
	l_pOriginator = nullptr;
}