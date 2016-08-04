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

template <typename T>
class Factory
{
public:
	T* Create() { return CreateProduct(); }
protected:
	virtual T* CreateProduct() = 0;
};

template <typename T1, typename T2>
class Creator : public Factory<T1>
{
protected:
	T1* CreateProduct() { return new T2; }
};

void main()
{
	Creator<ProductA, ProductAA> CreatorAA;
	Creator<ProductA, ProductAB> CreatorAB;
	Creator<ProductB, ProductBA> CreatorBA;
	Creator<ProductB, ProductBB> CreatorBB;

	ProductA *PAA(CreatorAA.Create()), *PAB(CreatorAB.Create());
	ProductB *PBA(CreatorBA.Create()), *PBB(CreatorBB.Create());

	PAA->Function();
	PAB->Function();
	PBA->Function();
	PBB->Function();
}