#include <iostream>
#include <string>

class Monster
{
	std::string m_Name;
private:
	virtual void Attack() = 0;

	void Born()
	{
		std::cout << m_Name << "��(��) �����Ǿ���." << std::endl;
	}
	void Move()
	{
		std::cout << m_Name << "��(��) �̵��Ͽ���." << std::endl;
	}
	void Die()
	{
		std::cout << m_Name << "��(��) �׾���." << std::endl;
	}
public:
	Monster(std::string Name) : m_Name(Name) {}

	void Act()
	{
		Born();
		for (size_t i = 0; i < 3; i++)
		{
			Move();
			Attack();
		}
		Die();
	}
};

class Dragon : public Monster
{
public:
	Dragon() : Monster("�巡��") {}

	void Attack() override
	{
		std::cout << "�巡����(��) ���� �վ���." << std::endl;
	}
};

class Devil : public Monster
{
public:
	Devil() : Monster("�Ǹ�") {}

	void Attack() override
	{
		std::cout << "�Ǹ���(��) ��������." << std::endl;
	}
};

void main()
{
	Monster *Mob1(new Dragon), *Mob2(new Devil);

	Mob1->Act();
	Mob2->Act();
}