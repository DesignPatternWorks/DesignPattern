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

template <typename T>
class Creator : public Factory
{
	Product* CreateProduct() override { return new T; }
};

void main()
{
	Creator<ProductA> CreatorA;
	Creator<ProductB> CreatorB;
	Product *PA = CreatorA.Create(), *PB = CreatorB.Create();

	PA->Function();
	PB->Function();
}