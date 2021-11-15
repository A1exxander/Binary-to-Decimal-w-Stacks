#include "Stack.h"

int main()
{   
    
    ArrayStack S;

    int number{0};

    while (number != 2) {
        number = conversion::getInput();
        conversion::binaryConversion(number, S);
        conversion::printBinaryConversion(S);

        std::cout << "\nRepeat? 1 to continue, 2 to exit : ";
        std::cin >> number;
        
    }
    
    std::cout << "\nExiting\n";

}


