class Prototype
{
public:
	virtual Prototype* Clone() = 0;
};

class ConcreteA : public Prototype
{
public:
	ConcreteA() = default;
	ConcreteA(ConcreteA &) = default;
	ConcreteA(ConcreteA &&) = default;

	Prototype* Clone() override { return new ConcreteA(*this); }
};

class ConcreteB : public Prototype
{
public:
	ConcreteB() = default;
	ConcreteB(ConcreteB &) = default;
	ConcreteB(ConcreteB &&) = default;

	Prototype* Clone() override { return new ConcreteB(*this); }
};

void main()
{
	Prototype *l_pOriginalA(new ConcreteA), *l_pOriginalB(new ConcreteB);
	Prototype *l_pCloneA(l_pOriginalA->Clone()), *l_pCloneB(l_pOriginalB->Clone());

	delete l_pOriginalA;
	delete l_pOriginalB;
	delete l_pCloneA;
	delete l_pCloneB;
	l_pOriginalA = nullptr;
	l_pOriginalB = nullptr;
	l_pCloneA = nullptr;
	l_pCloneB = nullptr;
}