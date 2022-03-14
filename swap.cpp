#include <utility>
#include <iostream>
#include <string>


int main() {


	std::string a = "Quan";
	std::string b = "Trang";

	std::cout << static_cast<void*>(a.data()) << a << '\n';
	std::cout << static_cast<void*>(b.data()) << b << '\n';

	std::swap(a, b);

	std::cout << static_cast<void*>(a.data()) << a << '\n';
	std::cout << static_cast<void*>(b.data()) << b << '\n';

	return 0;
}
