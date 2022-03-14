#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>


class Movable
{
public:
	Movable() {std::cout << "Movable()\n";}
	Movable(const Movable& m) {std::cout << "Copy constructor\n";}
	Movable& operator=(const Movable& m) {std::cout << "Copy assignment\n"; return *this;}
	Movable(Movable&& m) {std::cout << "Move constructor\n";}
	Movable& operator=(Movable&& m) {std::cout << "Move assignment\n"; return *this;}
};


int main() {
	Movable m; // default constructor;
	Movable m2(m); // copy constructor
	Movable m3(std::move(m)); // move constructor
	m2 = m3; // copy assignment
	m3 = std::move(m2); // move assignment;
	return 0;
}
