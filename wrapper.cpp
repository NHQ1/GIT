#include <functional>
#include <iostream>
#include <cstddef>

template<typename T>
void doubleMe(T t) {
	t *= 2;
}


void test(const int &a) {
	// a = 100;
}

int main()
{

	int a = 10;
	auto x = std::ref(a);

	doubleMe(std::ref(a));

	std::cout << a << '\n'; // 20

	test(std::ref(a));

	std::cout << a << '\n'; 
	auto f3 = 100;
	auto f2 = std::bind(test, std::cref(f3));
	f2();

	auto j = std::ref(a);
	// std::reference_wrapper<int>

	auto j2 = j.get();
	// int

	return 0;
}