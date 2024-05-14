#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
#include <iostream>

using namespace std;

template <typename T, int maxSize>
class Stack {
private:
    T data[maxSize];
    int top;

public:
    Stack() : top(-1) {}

    [[nodiscard]] bool isEmpty() const {
        return top == -1;
    }

    [[nodiscard]] bool isFull() const {
        return top == maxSize - 1;
    }

    void push(const T& item) {
        if (isFull()) {
            throw out_of_range("Stack is full");
        }
        data[++top] = item;
    }

    T pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return data[top--];
    }

    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return data[top];
    }

    friend ostream& operator<<(ostream& os, const Stack<T, maxSize>& stack) {
        for (int i = stack.top; i >= 0; --i) {
            os << stack.data[i] << " ";
        }
        return os;
    }
};


#endif
