
#include <iostream>
#include <array>

class ArrayStack {
private: 
    int top{};
    std::array<int, 8> myArray;
public:

    ArrayStack() {
        top = -1;
    }

    void push(int value) {
        if (top < 8) {
            ++top;
            myArray[top] = value;
        }
        else {
            std::cout << "\nStack is full! Must pop or create new stack.";
        }
    }

    void pop() {
        if (!isEmpty()) {
            std::cout << myArray[top];
        }
        else {
            std::cout << "\nStack is empty!";
        }
        myArray[top] = NULL;
        --top;
    }

    bool isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    void purge() {
        if (!isEmpty()) {
            for (auto i = top; i > 0; --i) {
                myArray[i] = NULL;
            }
        }
        top = -1;
    }

    void peek() {
        std::cout << myArray[top];
        }
};

void binaryConversion(int num, ArrayStack& s);
void printBinaryConversion(ArrayStack& S);

int main()
{
    ArrayStack S;

    binaryConversion(128, S);
    printBinaryConversion(S);

}

void binaryConversion(int num, ArrayStack& S) { // Storing via little endian, when popped, itll be in big endian. Remember little endian is small number comes first, while big is largest number comes first. Smallest number enters first so big numbers at end so when popped big numbers first
    
    while (num > 0 )
    {
        S.push(num % 2);
        num /= 2;
    }

}

void printBinaryConversion(ArrayStack& S) {

    while (!S.isEmpty())
    {
        S.pop();
    }

}

