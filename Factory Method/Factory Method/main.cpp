#include <iostream>

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

class CreatorA : public Factory
{
protected:
	Product* CreateProduct() override { return new ProductA; }
};

class CreatorB : public Factory
{
protected:
	Product* CreateProduct() override { return new ProductB; }
};

void main()
{
	CreatorA l_CreatorA;
	CreatorB l_CreatorB;
	Product *l_pProductA = l_CreatorA.Create(), *l_pProductB = l_CreatorB.Create();

	l_pProductA->Function();
	l_pProductB->Function();

	delete l_pProductA;
	delete l_pProductB;
	l_pProductA = nullptr;
	l_pProductB = nullptr;
}