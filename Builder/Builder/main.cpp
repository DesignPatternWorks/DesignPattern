#include <iostream>

class Product
{
public:
	void Function() { std::cout << "Product::Function()" << std::endl; }
};

class Builder
{
public:
	virtual void Build() = 0;
	virtual Product* GetResult() = 0;
};

class ConcreteBuilder : public Builder
{
	Product* m_Product;
public:
	~ConcreteBuilder() { if (m_Product != nullptr) delete m_Product; }

	void Build() override { m_Product = new Product; }
	Product* GetResult() override { return m_Product; }
};

class Director
{
	Builder* m_Builder;
public:
	Director(Builder* Builder_) : m_Builder(Builder_) {}
	~Director() { if (m_Builder != nullptr) delete m_Builder; }

	Product* Construct() 
	{
		m_Builder->Build();
		return m_Builder->GetResult();
	}
};

void main()
{
	Director* D(new Director(new ConcreteBuilder));
	Product* P(D->Construct());

	P->Function();

	delete D;
	delete P;
}