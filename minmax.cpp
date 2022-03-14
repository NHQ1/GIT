#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <string>

bool comp2(const std::string& str1, const std::string& str2)
{
	return str1.size() < str2.size();
}
class Comparable
{
private:
	int age;
public:
	Comparable(int age_) : age(age_) {}
	int getAge() const { return age;}
	friend std::ostream& operator<<(std::ostream& os, const Comparable& c)
	{
		os << "Comparable, age: " << c.getAge() << '\n';
		return os;
	}

	friend bool operator<(const Comparable& c1, const Comparable& c2)
	{
		return c1.getAge() < c2.getAge();
	}

	friend bool operator>(const Comparable& c1, const Comparable& c2)
	{
		return c1.getAge() >= c2.getAge();
	}
};

bool comp(const Comparable& c1, const Comparable& c2)
{
	return c1.getAge() < c2.getAge();
}

int main() {
	auto min = std::min(Comparable{10}, Comparable{15}, comp);
	std::cout << min << '\n';

	auto minmax = std::minmax({Comparable{10}, Comparable{14}, Comparable{5}, Comparable{4}});
	// => return a pair<min, max>
	std::cout << minmax.first << '\n';
	std::cout << minmax.second << '\n';




	auto minStr = std::min({"Quan", "Trang", "Soc", "Kien"}, comp2);
	std::cout << minStr << '\n';
	return 0;
}
