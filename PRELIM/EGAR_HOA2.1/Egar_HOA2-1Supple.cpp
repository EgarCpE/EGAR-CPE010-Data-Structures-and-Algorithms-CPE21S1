#include <iostream>
#include <string>

// class for fruits and vegies
// problem 1
class fruits {
private: 
    std::string fruitname; // declare string fruitname
    double fruitprice;     // declare fruit price
    int fruitquantity;     // declare fruit quantity

public: // blueprint
    // constructor
    fruits(std::string newFruitName = "unknown", double newFruitPrice = 0.0, int newFruitQuantity = 0) {
        // methods for getting the fruit infos
        fruitname = std::move(newFruitName);
        fruitprice = std::move(newFruitPrice);
        fruitquantity = std::move(newFruitQuantity);
    
        std::cout << "The constructor is called." << std::endl;
    }

    // method to calculate total fruit price
    double CalcTotalfruitPrice() const { return fruitprice * fruitquantity; }

    // deconstructor
    ~fruits() {
        std::cout << "The Deconstuctor is called." << std::endl;  
    }

    // copy constructor
    fruits(const fruits &copyfruit) {
        std::cout << "Copy constructor called" << std::endl;
        fruitname = copyfruit.fruitname;
        fruitprice = copyfruit.fruitprice;
        fruitquantity = copyfruit.fruitquantity;
    }

    // copy assignment operator
    fruits& operator=(const fruits &copyfruit) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &copyfruit) {
            fruitname = copyfruit.fruitname;
            fruitprice = copyfruit.fruitprice;
            fruitquantity = copyfruit.fruitquantity;
        }
        return *this;
    }

    // This getters are used to access the private members of the class
    std::string getName() const { return fruitname; }
    double getPrice() const { return fruitprice; }
    int getQuantity() const { return fruitquantity; }
};

class vegies {
private: 
    std::string vegiename; // declare string vegiename
    double vegieprice;     // declare vegie price
    int vegiequantity;     // declare vegie quantity
    
public: // blueprint for vegies
    // constructor
    vegies(std::string newVegieName = "unknown", double newVegiePrice = 0.0, int newVegieQuantity = 0) {
        // methods for getting the vegie infos
        vegiename = std::move(newVegieName);
        vegieprice = std::move(newVegiePrice);
        vegiequantity = std::move(newVegieQuantity);
    
        std::cout << "The constructor is called." << std::endl;
    }

    // method to calculate total vegie price
    double CalcTotalvegiePrice() const { return vegieprice * vegiequantity; }

    // deconstructor
    ~vegies() {
        std::cout << "The Deconstuctor is called." << std::endl;
    }

    // copy constructor
    vegies(const vegies &copyvegie) {
        std::cout << "Copy constructor called" << std::endl;
        vegiename = copyvegie.vegiename;
        vegieprice = copyvegie.vegieprice;
        vegiequantity = copyvegie.vegiequantity;
    }

    // copy assignment operator
    vegies& operator=(const vegies &copyvegie) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &copyvegie) {
            vegiename = copyvegie.vegiename;
            vegieprice = copyvegie.vegieprice;
            vegiequantity = copyvegie.vegiequantity;
        }
        return *this;
    }

    // This getters are used to access the private members of the class
    std::string getName() const { return vegiename; }
    double getPrice() const { return vegieprice; }
    int getQuantity() const { return vegiequantity; }
};

enum itemtype { is_fruit, is_vegie };

struct groceryitem {
    itemtype type;
    fruits* fruitptr = nullptr;
    vegies* vegieptr = nullptr;
};

double TotalSum(groceryitem list[], int listsize) {
    double totalsum = 0.0;
    for (int i = 0; i < listsize; ++i) {
        if (list[i].type == is_fruit && list[i].fruitptr != nullptr) {
            totalsum += list[i].fruitptr->CalcTotalfruitPrice();
        } 
        else if (list[i].type == is_vegie && list[i].vegieptr != nullptr) {
            totalsum += list[i].vegieptr->CalcTotalvegiePrice();
        }
    }
    return totalsum;
}

// Function to print details of all items
void DisplayGroceryList(groceryitem list[], int listsize) {
    std::cout << "\n GROCERY LIST \n";
    for (int i = 0; i < listsize; ++i) {
        if (list[i].type == is_fruit && list[i].fruitptr != nullptr) {
            std::cout << "[Fruit] " << list[i].fruitptr->getName()
                      << " | PHP " << list[i].fruitptr->getPrice()
                      << " | Quantity: x" << list[i].fruitptr->getQuantity()
                      << " | Subtotal: PHP " << list[i].fruitptr->CalcTotalfruitPrice() << std::endl;
        } 
        else if (list[i].type == is_vegie && list[i].vegieptr != nullptr) {
            std::cout << "[Vegie] " << list[i].vegieptr->getName()
                      << " | PHP " << list[i].vegieptr->getPrice()
                      << " | Quantity: x" << list[i].vegieptr->getQuantity()
                      << " | Subtotal: PHP " << list[i].vegieptr->CalcTotalvegiePrice() << std::endl;
        }
    }
}

int main() {
    const int listsize = 4;

    std::cout << "Grocery List\n" << std::endl;

    // Dynamically creating instances of fruits and vegies in an array
    groceryitem GroceryList[listsize];
    GroceryList[0] = { is_fruit, new fruits("Apple", 10.0, 7), nullptr };
    GroceryList[1] = { is_fruit, new fruits("Banana", 10.0, 8), nullptr };
    GroceryList[2] = { is_vegie, nullptr, new vegies("Broccoli", 60.0, 12) };
    GroceryList[3] = { is_vegie, nullptr, new vegies("Lettuce", 50.0, 10) };

    // Displaying all details about saved instances
    DisplayGroceryList(GroceryList, listsize);

    std::cout << "\nTotal Sum: PHP " << TotalSum(GroceryList, listsize) << std::endl;
    std::cout << "Initial Total Sum: PHP " << TotalSum(GroceryList, listsize) << std::endl;

    std::cout << "\n Deleting Lettuce" << std::endl;
    for (int i = 0; i < listsize; ++i) {
        if (GroceryList[i].type == is_vegie && GroceryList[i].vegieptr != nullptr) {
            if (GroceryList[i].vegieptr->getName() == "Lettuce") {
                delete GroceryList[i].vegieptr;        // De-allocate memory
                GroceryList[i].vegieptr = nullptr;    // Clear the pointer
                std::cout << "\n-> Lettuce has been deleted and memory freed.\n" << std::endl;
            }
        }
    }

    // Display updated details and updated sum
    DisplayGroceryList(GroceryList, listsize);
    std::cout << "Updated Total Sum: PHP " << TotalSum(GroceryList, listsize) << std::endl;

    // Cleaning up remaining dynamic memory before program termination
    std::cout << "\nCleaning Up Remaining Memory dont turn off system" << std::endl;
    for (int i = 0; i < listsize; ++i) {
        if (GroceryList[i].type == is_fruit && GroceryList[i].fruitptr != nullptr) {
            delete GroceryList[i].fruitptr;
            GroceryList[i].fruitptr = nullptr;
        } 
        else if (GroceryList[i].type == is_vegie && GroceryList[i].vegieptr != nullptr) {
            delete GroceryList[i].vegieptr;
            GroceryList[i].vegieptr = nullptr;
        }
    }

    return 0;
}
