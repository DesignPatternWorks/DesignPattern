#include <iostream>

/* 어떤 객체들이 다른 객체들을 포함하는 것을 필요로 할 때 사용하는 패턴
주로 게임에서 유닛과 무기의 관계에서 사용되는 것 같다 */

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