#include "Stack.h"

ArrayStack::ArrayStack() : top{ -1 } {// Member initilizer list instead of assigning the values in the constructor body
}

void ArrayStack::push(int value) {
		if (top < 8) {
			++top;
			myArray[top] = value;
		}
		else {
			std::cout << "\nStack is full! Must pop or create new stack.";
		}
}

void ArrayStack::pop(){

		if (!isEmpty()) {
			std::cout << myArray[top];
			myArray[top] = NULL;
			--top;
		}
		else {
			std::cout << "\nStack is empty!";
		}
}

bool ArrayStack::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

void ArrayStack::purge(){
		if (!isEmpty()) {
			for (auto i = top; i > 0; --i) {
				myArray[i] = NULL;
			}
		}
		top = -1;
}

void ArrayStack::peek() {
		std::cout << myArray[top];
}

namespace conversion { // Namespace outside of our class body incase we make multiple Stack instances 

	void binaryConversion(int num, ArrayStack& S) { 
	
		while (num > 0) {
			S.push(num % 2);
			num = num / 2;
		}
	}

	void printBinaryConversion(ArrayStack& S) {
		std::cout << "\n0b";
		while (!S.isEmpty()) {
			S.pop();
		}
		std::cout << "\n";
	}

	// getInput and inputValidation seem better to be used in a namespace and not inside the class, why? My thoughts are as it is not directly related to the stack and can be reused for all instances of the stack, alt would be calling this member method of instance and setting member variable
	int getInput(){ 
		constexpr int maxNum{ 255 }; // Avoid magic numbers
		int num{};
		std::cout << "Enter a number : ";
		std::cin >> num;
		if (num > maxNum) {
			num = inputValidation(maxNum);
		}
		return num;
	}

	int inputValidation(int range) {
		int num{ 256 }; // used to gate loop
		while (num > range)
		{
			std::cout << "\nEnter a number from 0 - " << range << " : ";
			std::cin >> num;
		}
		return num;
	}

}

