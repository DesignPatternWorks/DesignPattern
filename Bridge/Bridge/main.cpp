#include <iostream>

/* � ��ü���� �ٸ� ��ü���� �����ϴ� ���� �ʿ�� �� �� ����ϴ� ����
�ַ� ���ӿ��� ���ְ� ������ ���迡�� ���Ǵ� �� ���� */

class Weapon
{
public:
	virtual void Function() = 0;
};

class WeaponA : public Weapon
{
public:
	void Function() override { std::cout << "WeaponA::Function()" << std::endl << std::endl; }
};

class WeaponB : public Weapon
{
public:
	void Function() override { std::cout << "WeaponB::Function()" << std::endl << std::endl; }
};

class Unit
{
public:
	virtual void Function() = 0;
};

class UnitA : public Unit
{
	Weapon* m_pImpl;
public:
	UnitA(Weapon* pImpl) : m_pImpl(pImpl) {}

	void SetWeapon(Weapon* pImpl) { m_pImpl = pImpl; }
	void Function() override 
	{ 
		std::cout << "UnitA::Function()" << std::endl;
		m_pImpl->Function(); 
	}
};
class UnitB : public Unit
{
	Weapon* m_pImpl;
public:
	UnitB(Weapon* pImpl) : m_pImpl(pImpl) {}

	void SetWeapon(Weapon* pImpl) { m_pImpl = pImpl; }
	void Function() override 
	{
		std::cout << "UnitB::Function()" << std::endl;
		m_pImpl->Function(); 
	}
};

void main()
{
	WeaponA l_WeaponA;
	WeaponB l_WeaponB;

	UnitA l_UnitA(&l_WeaponA);
	UnitB l_UnitB(&l_WeaponB);

	l_UnitA.Function();
	l_UnitB.Function();

	l_UnitA.SetWeapon(&l_WeaponB);
	l_UnitB.SetWeapon(&l_WeaponA);

	l_UnitA.Function();
	l_UnitB.Function();
}