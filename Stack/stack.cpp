#include <iostream>
#include <string>

template <typename T>
class Stack final{
private:
    static const size_t SIZE = 100;
    T st_[SIZE];
    int top;
public:
    Stack();

    T pop();

    void push(T elem);

    bool isEmpty();

    bool isFull();

    T topElem() const;
};

template <class T> Stack<T>::Stack() {
    top = -1;
};

template <class T> bool Stack<T>::isFull() {
    return (top == (SIZE - 1));
}

template <class T> bool Stack<T>::isEmpty() {
    return top == -1;
}

template <class T> void Stack<T>::push(T elem) {
    if (isFull()) {
        std::cout << "Can not push new elem. Stack is full!";
    } else {
        std::cout << "Pushed elem: " << elem << std::endl;
        top++;
        st_[top] = elem;
    }
}

template <class T> T Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Can not pop an elem. Stack is empty!";
        throw std::runtime_error("Can not pop an elem. Stack is empty");
    } else {
        top--;
        return st_[top + 1];
    }
}

template <class T> T Stack<T>::topElem() const{
    return st_[top];
}

int main() {
    using namespace std;
    std::cout << "Custom Stack" << std::endl;

    // Creating object of Stack class in main() method
    // Declaring objects of type Integer and String
    Stack<int> integer_stack;
    Stack<string> string_stack;
 
    // Adding elements to integer stack object
    // Custom integer entries
    integer_stack.push(2);
    integer_stack.push(54);
    integer_stack.push(255);
 
    // Adding elements to string stack
    // Custom string entries
    string_stack.push("Best");
    string_stack.push("Stackich");
    string_stack.push("Ever");
 
    // Now, removing element from integer stack
    cout << integer_stack.pop() << " is removed from stack"
         << endl;
 
    // Removing top element from string stack
    cout << string_stack.pop() << " is removed from stack "
         << endl;
 
    // Print and display the top element in integer stack
    cout << "Top element is " << integer_stack.topElem() << endl;
 
    // Print and display the top element in string stack
    cout << "Top element is " << string_stack.topElem() << endl;
}