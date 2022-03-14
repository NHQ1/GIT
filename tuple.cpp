#include <iostream>
#include <tuple>
#include <utility>
#include <initializer_list>


template<typename T>
void print(const T& t)
{
	std::cout << '{';
	for (auto i : t) 
	{
		std::cout << i << ',';
	}
	std::cout << "}\n";
}

int main()
{
	std::tuple v = std::make_tuple(10, "Quan", 10.5F);
	// tutple<int, const char*, float>


	int count;
	const char *name;
	float average;

	std::tie(count, name, average) = v;
	std::cout << count << '\n';
	std::cout << name << '\n';
	std::cout << average << '\n';


	std::tuple v2 = std::make_tuple<std::initializer_list<int>, int, const char*>({1, 2, 3, 4}, 15, "Trang");
	// std::tuple<std::initializer_list<int>, int, const char*>


	std::initializer_list<int> l;
	const char* name_;
	std::tie(l, std::ignore, name_) = v2;

	print(l);
	std::cout << name_ << '\n';

	return 0;
}