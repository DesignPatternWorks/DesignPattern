#include <iostream>
#include <memory>

/* 프로그램 상에서 어떤 클래스의 객체가 하나만 존재해야 할 때 사용하는 패턴 */

class Singleton
{
	static std::shared_ptr<Singleton> instance;
private:
	Singleton() = default;
	Singleton(Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton & operator=(Singleton &) = delete;
	Singleton & operator=(Singleton &&) = delete;
public:
	~Singleton() = default;
	static Singleton& Instance() { return *(InstancePtr()); }
	static Singleton* InstancePtr()
	{
		if (instance == nullptr)
			instance.reset(new Singleton);
		return instance.get();
	}

	void Function()
	{
		std::cout << "Singleton::Function()" << std::endl;
	}
};
std::shared_ptr<Singleton> Singleton::instance(nullptr);

void main()
{
	Singleton::InstancePtr()->Function();
}