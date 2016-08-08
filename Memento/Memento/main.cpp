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
	void PushMemento(Memento* Memento_) { m_Stack.push(Memento_); }
	Memento* PopMemento() 
	{
		Memento* Memento_ = m_Stack.top();
		m_Stack.pop();
		return Memento_;
	}
};

void main()
{
	Caretaker Caretaker_;
	Originator* Originator_(new Originator);

	Originator_->SetState("State1");
	Caretaker_.PushMemento(Originator_->CreateMemento());

	Originator_->SetState("State2");
	Caretaker_.PushMemento(Originator_->CreateMemento());

	Originator_->SetMemento(Caretaker_.PopMemento());
	Originator_->SetMemento(Caretaker_.PopMemento());

	delete Originator_;
	Originator_ = nullptr;
}