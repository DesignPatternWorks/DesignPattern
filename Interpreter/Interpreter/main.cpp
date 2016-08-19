#include <iostream>
#include <string>
#include <list>

/* 문법 규칙을 클래스화 하여, 언어를 해석하는 패턴 */

class Context
{
	std::string m_Data;
public:
	Context(std::string Data) : m_Data(Data) {}

	std::string GetData() const { return m_Data; }
};

class Expression
{
public:
	virtual void Interpret(Context* pContext) = 0;
};

class TerminalExpression : public Expression
{
public:
	void Interpret(Context* pContext) override { std::cout << "TerminalExpression : " << pContext->GetData() << std::endl; }
};
class NonterminalExpression : public Expression
{
public:
	void Interpret(Context* pContext) override { std::cout << "NonterminalExpression : " << pContext->GetData() << std::endl; }
};

void main()
{
	Context l_Context("Data");

	std::list<Expression*> l_List;
	l_List.push_back(new TerminalExpression);
	l_List.push_back(new NonterminalExpression);

	for each (Expression* pExpression in l_List)
	{
		pExpression->Interpret(&l_Context);
		delete pExpression;
		pExpression = nullptr;
	}
	l_List.clear();
}