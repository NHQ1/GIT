#include <memory>
#include <utility>
#include <iostream>

class Test
{
private:
	int a_;
public:
	Test(int a = 10) : a_(a) {std::cout << "Test(" << a << ")\n";}
	~Test() { std::cout << "~Test(" << a_ << ")\n";}
};
int main()
{
	std::unique_ptr<int> ui = std::make_unique<int>(10);
	// std::unique_ptr<int> ui2 = std::move(ui);

	int *i = ui.release();
	std::unique_ptr<int> ui2 = std::move(ui);
	std::cout << ui.get() << '\n';
	std::cout << ui2.get() << '\n';
	std::cout << i << '\n';
	std::cout << *i << '\n';
	std::cout << (ui2.get() != nullptr ? "true" : "false") << '\n';
	// std::cout << *ui2 << '\n';
	delete i;



	std::unique_ptr<Test> uTest = std::make_unique<Test>(10);
	std::cout << uTest.get() << '\n';
	uTest.reset();
	std::cout << uTest.get() << '\n';
	std::cout << "Test\n";



	std::unique_ptr<Test> t = std::make_unique<Test>(100);
	{
		auto t2 = std::make_unique<Test>(101);
		t.swap(t2);
	}
	std::cout << "Swap done\n";



	std::unique_ptr<Test[]> ut(new Test[10]);

	auto j = ut.get();
	unsigned m = 10;
	while (--m > 0) {
		std::cout << ++j << '\n';
	}

	return 0;
}