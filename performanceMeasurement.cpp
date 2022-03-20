// performanceMeasurement.cpp 
#include <iostream>
#include <vector>
#include <chrono>
#include <type_traits>

using namespace std;

int main(){
  std::vector<int> myBigVec(10000000, 2011);
  std::vector<int> myEmptyVec1;

  auto begin= std::chrono::high_resolution_clock::now();
  myEmptyVec1 = myBigVec;
  auto end= std::chrono::high_resolution_clock::now() - begin;

  auto timeInSeconds = std::chrono::duration<double>(end).count();
  std::cout << timeInSeconds << std::endl; // 0.0150688800 <- may vary from execution to execution


  std::cout << std::boolalpha << std::is_same<std::chrono::high_resolution_clock, std::chrono::steady_clock>::value << '\n';
  std::cout << std::boolalpha << std::is_same<std::chrono::high_resolution_clock, std::chrono::system_clock>::value << '\n';

  return 0;
}