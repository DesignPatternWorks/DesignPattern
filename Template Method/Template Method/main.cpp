#include <iostream>
#include <string>

class Monster
{
	std::string m_Name;
private:
	virtual void Attack() = 0;

	void Born()
	{
		std::cout << m_Name << "이(가) 생성되었다." << std::endl;
	}
	void Move()
	{
		std::cout << m_Name << "이(가) 이동하였다." << std::endl;
	}
	void Die()
	{
		std::cout << m_Name << "이(가) 죽었다." << std::endl;
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
	Dragon() : Monster("드래곤") {}

	void Attack() override
	{
		std::cout << "드래곤이(가) 불을 뿜었다." << std::endl;
	}
};

class Devil : public Monster
{
public:
	Devil() : Monster("악마") {}

	void Attack() override
	{
		std::cout << "악마이(가) 할퀴었다." << std::endl;
	}
};

void main()
{
	Monster *Mob1(new Dragon), *Mob2(new Devil);

	Mob1->Act();
	Mob2->Act();
}