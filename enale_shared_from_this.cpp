#include <memory>
#include <iostream>


class Test : public std::enable_shared_from_this<Test>
{
public:
	~Test() { std::cout << "~Test()\n";}
	std::shared_ptr<Test> getPtr() {
		return shared_from_this();
	}

	static std::shared_ptr<Test> create() {
		return std::shared_ptr<Test>(new Test());
	}
private:
	Test() = default;
};


int main()
{
	auto pTest = Test::create();
	auto pTest2 = pTest->getPtr();
	std::cout << pTest.use_count() << '\n';
	std::cout << pTest2.use_count() << '\n';
}