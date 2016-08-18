#include <iostream>

/* 객체 생성을 전담하는 인터페이스를 만들어 유연성과 확장성이 뛰어난 코드를 만들게 해주는 패턴 */

class Product
{
public:
	virtual void Function() = 0;
};

class ProductA : public Product
{
public:
	void Function() override { std::cout << "ProductA::Function()" << std::endl; }
};

class ProductB : public Product
{
public:
	void Function() override { std::cout << "ProductB::Function()" << std::endl; }
};

class Factory
{
public:
	Product* Create() { return CreateProduct(); }
protected:
	virtual Product* CreateProduct() = 0;
};

class FactoryA : public Factory
{
protected:
	Product* CreateProduct() override { return new ProductA; }
};

class FactoryB : public Factory
{
protected:
	Product* CreateProduct() override { return new ProductB; }
};

void main()
{
	FactoryA l_FactoryA;
	FactoryB l_FactoryB;
	Product *l_pProductA = l_FactoryA.Create(), *l_pProductB = l_FactoryB.Create();

	l_pProductA->Function();
	l_pProductB->Function();

	delete l_pProductA;
	delete l_pProductB;
	l_pProductA = nullptr;
	l_pProductB = nullptr;
}