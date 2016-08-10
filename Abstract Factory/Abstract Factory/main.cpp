#include <iostream>

class ProductA
{
public:
	virtual void Function() = 0;
};

class ProductB
{
public:
	virtual void Function() = 0;
};

class ProductAA : public ProductA
{
public:
	void Function() override
	{
		std::cout << "ProductAA::Function()" << std::endl;
	}
};

class ProductAB : public ProductA
{
public:
	void Function() override
	{
		std::cout << "ProductAB::Function()" << std::endl;
	}
};

class ProductBA : public ProductB
{
public:
	void Function() override
	{
		std::cout << "ProductBA::Function()" << std::endl;
	}
};

class ProductBB : public ProductB
{
public:
	void Function() override
	{
		std::cout << "ProductBB::Function()" << std::endl;
	}
};

class FactoryA
{
protected:
	virtual ProductA* CreateProduct() = 0;
public:
	ProductA* Create() { return CreateProduct(); }
};

class FactoryB
{
protected:
	virtual ProductB* CreateProduct() = 0;
public:
	ProductB* Create() { return CreateProduct(); }
};

class CreatorAA : public FactoryA
{
protected:
	ProductA* CreateProduct() override { return new ProductAA; }
};

class CreatorAB : public FactoryA
{
protected:
	ProductA* CreateProduct() override { return new ProductAB; }
};

class CreatorBA : public FactoryB
{
protected:
	ProductB* CreateProduct() override { return new ProductBA; }
};

class CreatorBB : public FactoryB
{
protected:
	ProductB* CreateProduct() override { return new ProductBB; }
};

void main()
{
	CreatorAA l_CreatorAA;
	CreatorAB l_CreatorAB;
	CreatorBA l_CreatorBA;
	CreatorBB l_CreatorBB;

	ProductA *l_pProductAA(l_CreatorAA.Create()), *l_pProductAB(l_CreatorAB.Create());
	ProductB *l_pProductBA(l_CreatorBA.Create()), *l_pProductBB(l_CreatorBB.Create());

	l_pProductAA->Function();
	l_pProductAB->Function();
	l_pProductBA->Function();
	l_pProductBB->Function();
}