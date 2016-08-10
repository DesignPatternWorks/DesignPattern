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
	Product* m_pProduct;
public:
	ConcreteBuilder() : m_pProduct(nullptr) {}
	~ConcreteBuilder() 
	{
		if (m_pProduct != nullptr)
		{
			delete m_pProduct;
			m_pProduct = nullptr;
		}
	}

	void Build() override { m_pProduct = new Product; }
	Product* GetResult() override { return m_pProduct; }
};

class Director
{
	Builder* m_pBuilder;
public:
	Director(Builder* pBuilder) : m_pBuilder(pBuilder) {}
	~Director()
	{
		if (m_pBuilder != nullptr)
		{
			delete m_pBuilder;
			m_pBuilder = nullptr;
		}
	}

	Product* Construct() 
	{
		m_pBuilder->Build();
		return m_pBuilder->GetResult();
	}
};

void main()
{
	Director* l_pDirector(new Director(new ConcreteBuilder));
	Product* l_pProduct(l_pDirector->Construct());

	l_pProduct->Function();

	delete l_pDirector;
	delete l_pProduct;
	l_pDirector = nullptr;
	l_pProduct = nullptr;
}