#include <iostream>

bool GreaterorLess(int a, int b);

int main(){
  int a, b;

  std::cout << "Number A: ";
  std::cin >> a;

  std::cout << "Number B: ";
  std::cin >> b;

  if (GreaterorLess(a, b))
    std::cout << "A is Greater than B";
  else if (a == b)
    std::cout << "A is Equal to B";
  else
    std::cout << "A is Less than B";

  return 0;
}

bool GreaterorLess(int a, int b){
  return a > b;
}

