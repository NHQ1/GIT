#include <functional>
#include <map>
#include <iostream>

int main()
{

	std::map<char, std::function<double(double, double)>> arithmetics;
	arithmetics.insert({'+', [](double a, double b) {return a + b;}});
	arithmetics.insert({'-', [](double a, double b) {return a - b;}});
	arithmetics.insert({'*', [](double a, double b) {return a * b;}});
	arithmetics.insert({'/', [](double a, double b) {return a / b;}});



	std::cout << arithmetics.at('+')(10.0, 20.5) << '\n';
	std::cout << arithmetics.at('-')(10.0, 20.5) << '\n';
	std::cout << arithmetics.at('*')(10.0, 20.5) << '\n';
	std::cout << arithmetics.at('/')(10.0, 20.5) << '\n';


	auto multiple10 = std::bind(arithmetics.at('*'), std::placeholders::_1, 10);

	std::cout << multiple10(7.8) << '\n';

	auto divideReserve = std::bind(arithmetics.at('/'), std::placeholders::_2, std::placeholders::_1);
	std::cout << divideReserve(10, 2) << '\n'; // 0.2
	std::cout << divideReserve(100, 500) << '\n'; // 5
	return 0;
}