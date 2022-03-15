// all.cpp

#include <chrono>
#include <iostream>
#include <memory>
// static constexpr long long numInt= 100000000;
static constexpr long long numInt= 100000000;

void PtrNormal()
{
  auto start = std::chrono::system_clock::now();
  for ( long long i = 0 ; i < numInt; ++i){
    int* tmp(new int(i));
    delete tmp;
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time PtrNormal: " << dur.count() << " seconds" << std::endl;

}


void shareWithNew()
{
  auto start = std::chrono::system_clock::now();
  for ( long long i = 0 ; i < numInt; ++i){
    std::shared_ptr<int> tmp(new int(i));
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time shareWithNew: " << dur.count() << " seconds" << std::endl;
}

void shareWithMake()
{
  auto start = std::chrono::system_clock::now();
  for ( long long i = 0 ; i < numInt; ++i){
    std::shared_ptr<int> tmp(std::make_shared<int>(i));
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time shareWithMake: " << dur.count() << " seconds" << std::endl;

}

void uniqueWithNew()
{
  auto start = std::chrono::system_clock::now();
  for ( long long i = 0 ; i < numInt; ++i){
    std::unique_ptr<int> tmp(new int(i));
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time uniqueWithNew: " << dur.count() << " seconds" << std::endl;

}

void uniqueWithMake()
{
  auto start = std::chrono::system_clock::now();
  for ( long long i = 0 ; i < numInt; ++i){
    std::unique_ptr<int> tmp(std::make_unique<int>(i));
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time uniqueWithMake: " << dur.count() << " seconds" << std::endl;

}

int main() {
  PtrNormal();
  shareWithNew();
  shareWithMake();
  uniqueWithNew();
  uniqueWithMake();
  return 0;
}