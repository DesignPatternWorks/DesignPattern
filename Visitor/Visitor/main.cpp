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
	void Function(Visitor* Visitor_) override
	{
		Visitor_->Visit(this);
	}
};

class ElementB : public Element
{
public:
	void Function(Visitor* Visitor_) override
	{
		Visitor_->Visit(this);
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
	Element *EA(new ElementA), *EB(new ElementB);
	VisitorA *VA(new VisitorA);
	VisitorB *VB(new VisitorB);

	EA->Function(VA);
	EA->Function(VB);
	EB->Function(VA);
	EB->Function(VB);
}