#include <iostream>

/* �븮 ��ü���� ��û�� �ϸ� ������ �� ��û�� ó���ϴ� ��ü���� ��û�� ó���ϰ� ����� �˷��ְ� ���� ���� */

class Subject
{
public:
	virtual void Function() = 0;
};

class ConcreteSubject : public Subject
{
public:
	void Function() override { std::cout << "ConcreteSubject::Function()" << std::endl; }
};

class Proxy : public Subject
{
	ConcreteSubject* m_pSubject;
public:
	Proxy() : m_pSubject(nullptr) {}
	~Proxy()
	{
		if (m_pSubject)
		{
			delete m_pSubject;
			m_pSubject = nullptr;
		}
	}

	void Function() override
	{
		if (m_pSubject == nullptr)
			m_pSubject = new ConcreteSubject;
		m_pSubject->Function();
	}
};

void main()
{
	Subject* l_pProxy(new Proxy);
	l_pProxy->Function();

	delete l_pProxy;
	l_pProxy = nullptr;
}