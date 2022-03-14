#include <iostream>
#include <utility>
#include <iostream>
#include <vector>
class Forward
{
public:
	explicit Forward(int a) {std::cout << "Forward()\n";}
	Forward(const Forward& m) {std::cout << "Copy constructor\n";}
	Forward& operator=(const Forward& m) {std::cout << "Copy assignment\n"; return *this;}
	Forward(Forward&& m) {std::cout << "Move constructor\n";}
	Forward& operator=(Forward&& m) {std::cout << "Move assignment\n"; return *this;}
private:
	int a;
};

template<typename T, typename... Args>
T createT(Args&&... args) {
	return T(std::forward<Args>(args)... );
}


int main() {

	std::vector<Forward> v;
	v.reserve(5);

	v.emplace_back(5);
	v.push_back(createT<Forward>(5));
	return 0;
}
