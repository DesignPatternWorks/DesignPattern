#include <iostream>
#include <list>

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
	Subject* Subject_(new ConcreteSubject);

	Observer* Observer1(new ConcreteObserver);
	Observer* Observer2(new ConcreteObserver);
	Observer* Observer3(new ConcreteObserver);

	Subject_->Attach(Observer1);
	Subject_->Attach(Observer2);
	Subject_->Attach(Observer3);

	Subject_->Change();

	Subject_->Detach(Observer1);
	Subject_->Detach(Observer2);
	Subject_->Detach(Observer3);

	Subject_->Change();

	delete Subject_;
	delete Observer1;
	delete Observer2;
	delete Observer3;

	Subject_ = nullptr;
	Observer1 = nullptr;
	Observer2 = nullptr;
	Observer3 = nullptr;
}