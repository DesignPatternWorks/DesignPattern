#include <iostream>

/* �� ��ü�� ���� ��û���� �׿� ����� �ٸ� Ŭ�����鿡�� ��û�� ������ ���� */

class Handler
{
	Handler* m_pHandler;
public:
	Handler(Handler* pHandler) : m_pHandler(pHandler) {}
	~Handler()
	{
		if (m_pHandler != nullptr)
		{
			delete m_pHandler;
			m_pHandler = nullptr;
		}
	}

	virtual void HandleRequest()
	{
		if (m_pHandler != nullptr)
			HandleRequest();
	}
};

class HandlerA : public Handler
{
public:
	HandlerA(Handler* pHandler) : Handler(pHandler) {}
	void HandleRequest() override
	{
		std::cout << "HandlerA::Function()" << std::endl;
		Handler::HandleRequest();
	}
};

class HandlerB : public Handler
{
public:
	HandlerB(Handler* pHandler) : Handler(pHandler) {}
	void HandleRequest() override
	{
		std::cout << "HandlerB::Function()" << std::endl;
		Handler::HandleRequest();
	}
};

class HandlerC : public Handler
{
public:
	HandlerC(Handler* pHandler) : Handler(pHandler) {}
	void HandleRequest() override
	{
		std::cout << "HandlerC::Function()" << std::endl;
		Handler::HandleRequest();
	}
};

void main()
{
	Handler* l_pHandler(new HandlerA(new HandlerB(new HandlerC(nullptr))));
	l_pHandler->HandleRequest();

	delete l_pHandler;
	l_pHandler = nullptr;
}