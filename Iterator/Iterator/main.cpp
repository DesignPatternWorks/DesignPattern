#include <iostream>
#include <string>

/* 컨테이너(벡터, 연결 리스트 등)의 내부에 대한 이해 없이 탐색할 수 있도록 해주는 패턴 */

class Element
{
public:
	std::string m_Data;

	Element(std::string Data) : m_Data(Data) {}
};

class Aggregate
{
protected:
	int m_TotalCnt;
public:
	friend class Iterator;

	virtual void AddNext(Element* pNewElement, Element* pElement = nullptr) = 0;
	virtual void Remove(Element* pElement) = 0;

	virtual Iterator* CreateIterator() = 0;
	virtual Element* GetItem(int Position) = 0;

	int GetCount() const { return m_TotalCnt; }
};

class List : public Aggregate
{
	struct LinkedElement
	{
		Element* m_pData;
		LinkedElement* m_pNext;

		LinkedElement(Element* pData = nullptr, LinkedElement* pNext = nullptr) :
			m_pData(pData), m_pNext(pNext) {}
	};
private:
	LinkedElement* m_pFirst;
public:
	List() : m_pFirst(nullptr) {}
	
	void AddNext(Element* pNewElement, Element* pElement = nullptr) override
	{
		if (m_pFirst == nullptr)
			m_pFirst = new LinkedElement(pNewElement);
		else if (pElement == nullptr || pElement == m_pFirst->m_pData)
		{
			LinkedElement* pTemp(m_pFirst->m_pNext);
			m_pFirst->m_pNext = new LinkedElement(pNewElement, pTemp);
		}
		else
		{
			LinkedElement *pPrev(nullptr), *pTemp(m_pFirst);
			while (pTemp != nullptr && pTemp->m_pData != pElement)
			{
				pPrev = pTemp;
				pTemp = pTemp->m_pNext;
			}
			if (pTemp != nullptr)
			{
				LinkedElement* pTemp2(pTemp->m_pNext);
				pTemp->m_pNext = new LinkedElement(pNewElement, pTemp2);
			}
			else
				pPrev->m_pNext = new LinkedElement(pNewElement, nullptr);
		}
		m_TotalCnt++;
	}
	void Remove(Element* pElement)
	{
		if (pElement == nullptr)
			return;
		LinkedElement *pPrev(nullptr), *pTemp(m_pFirst);
		while (pTemp != nullptr && pTemp->m_pData != pElement)
		{
			pPrev = pTemp;
			pTemp = pTemp->m_pNext;
		}
		if (pTemp != nullptr)
		{
			if (pTemp == m_pFirst)
			{
				delete pTemp;
				pTemp = nullptr;
				m_pFirst = nullptr;
			}
			else
			{
				pPrev->m_pNext = pTemp->m_pNext;
				delete pTemp;
				pTemp = nullptr;
			}
			m_TotalCnt--;
		}
	}

	Iterator* CreateIterator();
	Element* GetItem(int Position)
	{
		int Cnt;
		LinkedElement* pTemp(m_pFirst);
		for (Cnt = 0; pTemp != nullptr && Cnt != Position; Cnt++)
			pTemp = pTemp->m_pNext;
		if (pTemp != nullptr)
			return pTemp->m_pData;
		else
			return nullptr;
	}
};

class Iterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Element* GetItem() = 0;
};

class ListIterator : public Iterator
{
	Aggregate* m_pAggregate;
	int m_Position;
public:
	ListIterator(Aggregate* pAggregate) : m_pAggregate(pAggregate), m_Position(0) {}
	~ListIterator()
	{
		if (m_pAggregate != nullptr)
		{
			delete m_pAggregate;
			m_pAggregate = nullptr;
		}
	}

	void First() override { m_Position = 0; }
	void Next() override { m_Position++; }
	bool IsDone() override { return m_Position >= m_pAggregate->GetCount(); }
	Element* GetItem() override { return m_pAggregate->GetItem(m_Position); }
};

Iterator* List::CreateIterator() { return new ListIterator(this); }

class IteratorPtr
{
	Iterator* m_pIterator;
public:
	IteratorPtr(Iterator* pIterator) : m_pIterator(pIterator) {}
	~IteratorPtr() 
	{
		if (m_pIterator != nullptr)
		{
			delete m_pIterator;
			m_pIterator = nullptr;
		}
	}
	IteratorPtr(IteratorPtr &) = delete;
	IteratorPtr(IteratorPtr &&) = delete;
	IteratorPtr& operator=(IteratorPtr &) = delete;
	IteratorPtr& operator=(IteratorPtr &&) = delete;

	Iterator* operator->() { return m_pIterator; }
	Iterator& operator*() { return *m_pIterator; }
};

void main()
{
	Element l_ElementA("ElementA"), l_ElementB("ElementB"), l_ElementC("ElementC");
	List l_List;

	l_List.AddNext(&l_ElementA);
	l_List.AddNext(&l_ElementB, &l_ElementA);
	l_List.AddNext(&l_ElementC, &l_ElementA);

	IteratorPtr it(l_List.CreateIterator());
	for (it->First(); !it->IsDone(); it->Next())
		std::cout << it->GetItem()->m_Data << std::endl;
}