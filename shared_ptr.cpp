#include <memory>
#include <iostream>

class Test
{
public:
	Test() {std::cout << "Test()\n";}
	~Test() {std::cout << "~Test()\n";}
};


int main()
{
	std::shared_ptr s = std::make_shared<Test>();
	// use_count() == 1;
	std::cout << s.use_count() << '\n';

	std::shared_ptr s2(s); // use_count == 2;	
	std::cout << s2.use_count() << '\n';


	s = std::make_shared<Test>(); // assign new pointer
	std::cout << s.use_count() << '\n'; // 1
	std::cout << s2.use_count() << '\n'; // 1

	s2 = std::make_shared<Test>();
	// the old pointer will be delete
	std::cout << s2.use_count() << '\n';


	auto ps2 = s2.get();
	delete ps2;

	std::cout << (s2 ? "true" : "false") << '\n';
	while (true) {
		
	}

	return 0;
}
