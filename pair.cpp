#include <utility>
#include <iostream>

int main() {

	auto p = std::make_pair("Quan", 23);
	// std::pair<const char*, int>
	std::cout << p.first << ":" << p.second << '\n';
	std::cout << std::get<0>(p) << ":" << std::get<1>(p) << '\n';

	p.first = "Trang";
	std::cout << p.first << ":" << p.second << '\n';

	return 0;
}
