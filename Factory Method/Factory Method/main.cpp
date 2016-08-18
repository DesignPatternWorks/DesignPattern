#include <iostream>

/* ��ü ������ �����ϴ� �������̽��� ����� �������� Ȯ�强�� �پ �ڵ带 ����� ���ִ� ���� */

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