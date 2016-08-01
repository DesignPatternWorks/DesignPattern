#include <iostream>
#include <memory>

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

	void function()
	{
		std::cout << "Singleton Pattern" << std::endl;
	}
};
std::shared_ptr<Singleton> Singleton::instance(nullptr);

void main()
{
	Singleton::InstancePtr()->function();
}