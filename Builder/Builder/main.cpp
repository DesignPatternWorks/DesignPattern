#include <iostream>
#include <string>

/* 복합 객체의 생성과 표현을 분리하여 동일한 생성 절차에서 다른 결과를 만들 수 있게하는 패턴 */

class Product
{
	std::string m_String;
public:
	Product(std::string String) : m_String(String) {}

	void Function() { std::cout << "Product" << m_String << "::Function()" << std::endl; }
};

class Builder
{
public:
	virtual void Build() = 0;
	virtual Product* GetResult() = 0;
};

class BuilderA : public Builder
{
	Product* m_pProduct;
public:
	BuilderA() : m_pProduct(nullptr) {}
	~BuilderA()
	{
		if (m_pProduct != nullptr)
		{
			delete m_pProduct;
			m_pProduct = nullptr;
		}
	}

	void Build() override { m_pProduct = new Product("A"); }
	Product* GetResult() override { return m_pProduct; }
};
class BuilderB : public Builder
{
	Product* m_pProduct;
public:
	BuilderB() : m_pProduct(nullptr) {}
	~BuilderB()
	{
		if (m_pProduct != nullptr)
		{
			delete m_pProduct;
			m_pProduct = nullptr;
		}
	}

	void Build() override { m_pProduct = new Product("B"); }
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
	Director* l_pDirectorA(new Director(new BuilderA));
	Director* l_pDirectorB(new Director(new BuilderB));

	Product* l_pProductA(l_pDirectorA->Construct());
	Product* l_pProductB(l_pDirectorB->Construct());

	l_pProductA->Function();
	l_pProductB->Function();

	delete l_pDirectorA;
	delete l_pDirectorB;
	delete l_pProductA;
	delete l_pProductB;
	l_pDirectorA = nullptr;
	l_pDirectorB = nullptr;
	l_pProductA = nullptr;
	l_pProductB = nullptr;
}