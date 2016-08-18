#include <iostream>

/* 한 객체에 대한 요청으로 그와 연결된 다른 클래스들에도 요청을 보내는 패턴 */

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