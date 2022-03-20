// typeCategories.cpp 
#include <iostream>
#include <type_traits>

using std::cout;
int main()
{
  //out put 1 means that the function returns true
  cout << "is_void: " << std::is_void<void>::value << "\n";             // 1
  cout << "is_integral: " << std::is_integral<short>::value << "\n";        // 1
  cout << "is_floating_point: " << std::is_floating_point<double>::value << "\n"; // 1
  cout << "is_array: " << std::is_array<int [] >::value << "\n";         // 1
  cout << "is_pointer: " << std::is_pointer<int*>::value << "\n";          // 1
  cout << "is_reference: " << std::is_reference<int&>::value << "\n";        // 1

  struct A{
    int a;
    int f(int){ return 2011; }
  };
  cout << "is_member_object_pointer: " << std::is_member_object_pointer<int A::*>::value << "\n";          // 1
  cout << "is_member_function_pointer: " << std::is_member_function_pointer<int (A::*)(int)>::value << "\n"; // 1

  enum E{
    e= 1,
  };
  cout << "is_enum: " << std::is_enum<E>::value << "\n";                  // 1

  union U{
    int u;
  };
  cout << "is_union: " << std::is_union<U>::value << "\n";                 // 1

  cout << "is_class: " << std::is_class<std::string>::value << "\n";       // 1
  cout << "is_function: " << std::is_function<int * (double)>::value << "\n"; // 1
  cout << "is_lvalue_reference: " << std::is_lvalue_reference<int&>::value << "\n";   // 1
  cout << "is_rvalue_reference: " << std::is_rvalue_reference<int&&>::value << "\n";  // 1

  return 0;
}