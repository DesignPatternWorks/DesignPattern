#include <iostream>
#include <list>

/* 객체들을 하나의 인터페이스로 다룰 수 있게 하는 패턴 */

class Component
{
public:
	virtual void Function() = 0;
};

class LeafA : public Component
{
public:
	void Function() override { std::cout << "LeafA::Function()" << std::endl; }
};

class LeafB : public Component
{
public:
	void Function() override { std::cout << "LeafB::Function()" << std::endl; }
};

class Composite
{
	std::list<Component*> m_List;
public:
	void Add(Component* pComponent) { m_List.push_back(pComponent); }
	void Remove(Component* pComponent) { m_List.remove(pComponent); }
	void Function()
	{
		for (auto i : m_List)
			i->Function();
	}
	Component* GetChild(int n)
	{
		int cnt(0);
		for (auto i : m_List)
		{
			if (n == cnt)
				return i;
			cnt++;
		}
		return nullptr;
	}
};

void main()
{
	LeafA l_LeafA;
	LeafB l_LeafB;
	Composite l_Composite;

	l_Composite.Add(&l_LeafA);
	l_Composite.Add(&l_LeafB);
	l_Composite.Function();

	l_Composite.GetChild(0)->Function();
	l_Composite.GetChild(1)->Function();

	l_Composite.Remove(&l_LeafA);
	l_Composite.Remove(&l_LeafB);
	l_Composite.Function();
}