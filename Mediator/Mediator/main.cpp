#include <iostream>
#include <string>
#include <typeinfo>
#include <list>

/* 여러 클래스 간의 로직을 캡슐화 하여 하나의 클래스에게 역할을 위임하는 패턴
복잡한 로직을 하나의 클래스가 담당하기에 복잡도가 떨어진다 */

class Colleague;
class Mediator
{
public:
	virtual void AddColleague(Colleague* pColleague) = 0;
	virtual void Mediate(std::string Message, Colleague* pSender) = 0;
};
class Colleague
{
protected:
	Mediator* m_pMediator;
public:
	Colleague(Mediator* pMediator) : m_pMediator(pMediator) { m_pMediator->AddColleague(this); }

	void SendMessage(std::string String)
	{
		m_pMediator->Mediate(String, this);
		std::cout << "Message : " << String << ", Send by : " << GetName() << std::endl;
	}
	void ReceiveMessages(std::string String)
	{
		std::cout << "Message : " << String << ", Recv by : " << GetName() << std::endl;
	}
	virtual std::string GetName() = 0;
};

class ConcreteMediator : public Mediator
{
	std::list<Colleague*> m_List;
public:
	void AddColleague(Colleague* pColleague)
	{
		m_List.push_back(pColleague);
	}
	void Mediate(std::string Message, Colleague* pSender)
	{
		for (auto Object : m_List)
		{
			if (Object != pSender)
				Object->ReceiveMessages(Message);
		}
	}
};

class ColleagueA : public Colleague
{
public:
	ColleagueA(Mediator* pMediator) : Colleague(pMediator) {}
	std::string GetName() { return typeid(this).name(); }
};
class ColleagueB : public Colleague
{
public:
	ColleagueB(Mediator* pMediator) : Colleague(pMediator) {}
	std::string GetName() { return typeid(this).name(); }
};

void main()
{
	ConcreteMediator l_Mediator;
	ColleagueA l_ColleagueA(&l_Mediator);
	ColleagueB l_ColleagueB(&l_Mediator);

	l_ColleagueA.SendMessage("First Message");
	l_ColleagueB.SendMessage("Second Message");
}