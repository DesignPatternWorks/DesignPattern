#include <iostream>

class Element;
class Visitor;

class ElementA;
class ElementB;
class VisitorA;
class VisitorB;

class Element
{
public:
	virtual void Function(Visitor*) = 0;
};

class Visitor
{
public:
	virtual void Visit(ElementA*) = 0;
	virtual void Visit(ElementB*) = 0;
};

class ElementA : public Element
{
public:
	void Function(Visitor* pVisitor) override
	{
		pVisitor->Visit(this);
	}
};

class ElementB : public Element
{
public:
	void Function(Visitor* pVisitor) override
	{
		pVisitor->Visit(this);
	}
};

class VisitorA : public Visitor
{
public:
	void Visit(ElementA*) override
	{
		std::cout << "ElementA->Function(VisitorA)" << std::endl;
	}
	void Visit(ElementB*) override
	{
		std::cout << "ElementB->Function(VisitorA)" << std::endl;
	}
};

class VisitorB : public Visitor
{
public:
	void Visit(ElementA*) override
	{
		std::cout << "ElementA->Function(VisitorB)" << std::endl;
	}
	void Visit(ElementB*) override
	{
		std::cout << "ElementB->Function(VisitorB)" << std::endl;
	}
};

void main()
{
	Element *l_pElementA(new ElementA), *l_pElementB(new ElementB);
	Visitor *l_pVisitorA(new VisitorA), *l_pVisitorB(new VisitorB);

	l_pElementA->Function(l_pVisitorA);
	l_pElementA->Function(l_pVisitorB);
	l_pElementB->Function(l_pVisitorA);
	l_pElementB->Function(l_pVisitorB);

	delete l_pElementA;
	delete l_pElementB;
	delete l_pVisitorA;
	delete l_pVisitorB;
	l_pElementA = nullptr;
	l_pElementB = nullptr;
	l_pVisitorA = nullptr;
	l_pVisitorB = nullptr;
}