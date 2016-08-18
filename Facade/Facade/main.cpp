#include <iostream>

/* 하나의 인터페이스를 통해 다른 서브시스템들을 사용하도록 만든 패턴 */

class SubclassA
{
public:
	virtual void Function() = 0;
};
class SubclassB
{
public:
	virtual void Function() = 0;
};

class SubclassAA : public SubclassA
{
public:
	void Function() override { std::cout << "SubclassAA::Function()" << std::endl; }
};
class SubclassAB : public SubclassA
{
public:
	void Function() override { std::cout << "SubclassAB::Function()" << std::endl; }
};
class SubclassBA : public SubclassB
{
public:
	void Function() override { std::cout << "SubclassBA::Function()" << std::endl; }
};
class SubclassBB : public SubclassB
{
public:
	void Function() override { std::cout << "SubclassBB::Function()" << std::endl; }
};

class Facade
{
	SubclassA* m_pSubclassA;
	SubclassB* m_pSubclassB;
public:
	Facade(SubclassA* pSubclassA, SubclassB* pSubclassB) :
		m_pSubclassA(pSubclassA), m_pSubclassB(pSubclassB) {}
	~Facade()
	{
		if (m_pSubclassA != nullptr)
		{
			delete m_pSubclassA;
			m_pSubclassA = nullptr;
		}
		if (m_pSubclassB != nullptr)
		{
			delete m_pSubclassB;
			m_pSubclassB = nullptr;
		}
	}

	void Function()
	{
		m_pSubclassA->Function();
		m_pSubclassB->Function();
	}
};

void main()
{
	Facade l_FacadeA(new SubclassAA, new SubclassBA);
	Facade l_FacadeB(new SubclassAB, new SubclassBB);

	l_FacadeA.Function();
	l_FacadeB.Function();
}