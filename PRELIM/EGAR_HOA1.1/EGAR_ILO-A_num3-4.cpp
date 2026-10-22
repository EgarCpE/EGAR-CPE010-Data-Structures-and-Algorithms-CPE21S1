#include <iostream>

bool showLogicalOperations(bool a, bool b);

int main() {

    showLogicalOperations(true, false);
    
    return 0;
}


bool showLogicalOperations(bool a, bool b) {
  
    std::cout << "Type 1 if true and 0 if false" << std::endl;
    std::cin >> a;
    std::cin >> b;
    
    
    std::cout << "A AND B: " << (a && b) << std::endl;
    std::cout << "A OR B:  " << (a || b) << std::endl;
    std::cout << "NOT A:   " << (!a) << std::endl;
    std::cout << "NOT B:   " << (!b) << std::endl;
    std::cout << "A XOR B: " << (a ^ b) << std::endl;
    std::cout << "A NAND B: " << !(a && b) << std::endl;
    std::cout << "A NOR B: " << !(a || b) << std::endl;
    std::cout << "A XNOR B: " << !(a ^ b) << std::endl;
    

    return true;
}