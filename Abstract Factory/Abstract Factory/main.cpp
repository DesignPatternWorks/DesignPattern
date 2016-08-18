#include <iostream>

/* 팩토리 메서드 패턴과 유사하나 객체의 집합을 생성하는 경우 사용하는 패턴
서로 다른 객체들을 하나의 팩토리가 생성, 관리한다 */

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