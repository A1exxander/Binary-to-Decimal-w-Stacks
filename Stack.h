#pragma once
#include <array>
#include <iostream>



class ArrayStack { // Reason why we use a stack is since we need to flip the input from little endian to big endian - Stacks are useful for reversing data and when getting the binary representation of a number with code, we get the last ( smallest number ) first 
private:
    int top{};
    std::array<int, 8> myArray; // Size 8 since we will only be representing 1 byte.
public:

    ArrayStack();

    void push(const int value); 

    void pop();

    bool isEmpty();

    void purge(); 

    void peek();
};

namespace conversion {
    	int getInput();
   	int inputValidation(const int range);
	void binaryConversion(int num, ArrayStack& S);
	void printBinaryConversion(ArrayStack& S);
};
