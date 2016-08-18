#include <iostream>

/* ���丮 �޼��� ���ϰ� �����ϳ� ��ü�� ������ �����ϴ� ��� ����ϴ� ����
���� �ٸ� ��ü���� �ϳ��� ���丮�� ����, �����Ѵ� */

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

class FactoryAA : public FactoryA
{
protected:
	ProductA* CreateProduct() override { return new ProductAA; }
};
class FactoryAB : public FactoryA
{
protected:
	ProductA* CreateProduct() override { return new ProductAB; }
};
class FactoryBA : public FactoryB
{
protected:
	ProductB* CreateProduct() override { return new ProductBA; }
};
class FactoryBB : public FactoryB
{
protected:
	ProductB* CreateProduct() override { return new ProductBB; }
};

void main()
{
	FactoryAA l_FactoryAA;
	FactoryAB l_FactoryAB;
	FactoryBA l_FactoryBA;
	FactoryBB l_FactoryBB;

	ProductA *l_pProductAA(l_FactoryAA.Create()), *l_pProductAB(l_FactoryAB.Create());
	ProductB *l_pProductBA(l_FactoryBA.Create()), *l_pProductBB(l_FactoryBB.Create());

	l_pProductAA->Function();
	l_pProductAB->Function();
	l_pProductBA->Function();
	l_pProductBB->Function();
}