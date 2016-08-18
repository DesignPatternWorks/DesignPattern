#include <iostream>
#include <map>

/* 여러 객체들에 대한 관리를 한 인터페이스에서 하게 만든 패턴 */

class Object
{
public:
	virtual void Function() = 0;
};
class ObjectA : public Object
{
public:
	void Function() override { std::cout << "ObjectA::Function()" << std::endl; }
};
class ObjectB : public Object
{
public:
	void Function() override { std::cout << "ObjectB::Function()" << std::endl; }
};
class ObjectC : public Object
{
public:
	void Function() override { std::cout << "ObjectC::Function()" << std::endl; }
};

class Factory
{
	static Factory* instance;

	std::map<int, Object*> m_Map;
private:
	Factory() = default;
	Factory(Factory &) = delete;
	Factory(Factory &&) = delete;
	Factory & operator=(Factory &) = delete;
	Factory & operator=(Factory &&) = delete;
public:
	~Factory()
	{
		for (auto i : m_Map)
		{
			if (i.second != nullptr)
			{
				delete i.second;
				i.second = nullptr;
			}
		}
	}
	static Factory& Instance() { return *(InstancePtr()); }
	static Factory* InstancePtr()
	{
		if (instance == nullptr)
			instance = new Factory;
		return instance;
	}

	template <typename T>
	void CreateObject(int key) 
	{
		if (m_Map.find(key) == m_Map.end())
			m_Map[key] = new T;
	}
	Object* GetObject(int key) { return m_Map[key]; }
};
Factory* Factory::instance(nullptr);

void main()
{
	Factory::Instance().CreateObject<ObjectA>(1);
	Factory::Instance().CreateObject<ObjectB>(2);
	Factory::Instance().CreateObject<ObjectC>(3);

	Object* l_pObjectA(Factory::Instance().GetObject(1));
	Object* l_pObjectB(Factory::Instance().GetObject(2));
	Object* l_pObjectC(Factory::Instance().GetObject(3));

	l_pObjectA->Function();
	l_pObjectB->Function();
	l_pObjectC->Function();
}