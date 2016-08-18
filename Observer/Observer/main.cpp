#include <iostream>
#include <list>

/* 한 객체의 상태가 변하면 그와 연결되어 있는 모든 객체들의 상태도 갱신되게 하는 패턴 */

class Observer
{
public:
	virtual void Update() = 0;
};

class ConcreteObserver : public Observer
{
public:
	void Update() override { std::cout << "(" << this << ")->Update()" << std::endl; }
};

class Subject
{
	std::list<Observer*> m_List;
protected:
	void Notify()
	{
		for (auto & i : m_List)
			i->Update();
	}
public:
	void Attach(Observer* Observer_) { m_List.push_back(Observer_); }
	void Detach(Observer* Observer_) 
	{
		for (auto i = m_List.begin(); i != m_List.end(); i++)
		{
			if (*i == Observer_)
			{
				m_List.erase(i);
				break;
			}
		}
	}

	virtual void Change() = 0;
};

class ConcreteSubject : public Subject
{
public:
	void Change() override { Notify(); }
};

void main()
{
	Subject* l_pSubject(new ConcreteSubject);

	Observer* l_pObserver1(new ConcreteObserver);
	Observer* l_pObserver2(new ConcreteObserver);
	Observer* l_pObserver3(new ConcreteObserver);

	l_pSubject->Attach(l_pObserver1);
	l_pSubject->Attach(l_pObserver2);
	l_pSubject->Attach(l_pObserver3);

	l_pSubject->Change();
	
	l_pSubject->Detach(l_pObserver1);
	l_pSubject->Detach(l_pObserver2);
	l_pSubject->Detach(l_pObserver3);

	l_pSubject->Change();

	delete l_pSubject;
	delete l_pObserver1;
	delete l_pObserver2;
	delete l_pObserver3;

	l_pSubject = nullptr;
	l_pObserver1 = nullptr;
	l_pObserver2 = nullptr;
	l_pObserver3 = nullptr;
}