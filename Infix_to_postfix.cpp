#include <iostream>
#define MAX 10
using namespace std;

char arr[MAX];
int top = -1;

// Check if the stack is full
int isFull() {
    return (top == MAX - 1);
}

// Check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Push an element onto the stack
void push(char item) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    arr[++top] = item;
}

// Pop an element from the stack
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return;
    }
    top--;
}

// Peek the top element of the stack
char peek() {
    if (!isEmpty())
        return arr[top];
    return '\0';
}

// Check if a character is an operand
int isOperand(char x) {
    return ((x >= 'A' && x <= 'z') || (x >= '0' && x <= '9'));
}

// Check if a character is an operator
int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

// Get the precedence of an operator
int prec(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

// Convert infix to postfix
string infix_to_postfix(string s) {
    string postfix = "";
    for (int i = 0; i < s.length(); i++) {
        if (isOperand(s[i])) {
            postfix += s[i];
        } else if (s[i] == '(') {
            push(s[i]);
        } else if (s[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix += peek();
                pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop();
            }
        } else if (isOperator(s[i])) {
            while (!isEmpty() && prec(s[i]) <= prec(peek())) {
                postfix += peek();
                pop();
            }
            push(s[i]);
        }
    }
    // Pop remaining operators from the stack
    while (!isEmpty()) {
        postfix += peek();
        pop();
    }
    return postfix;
}

// Main function
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << exp << endl;
    string result = infix_to_postfix(exp);
    cout << "Postfix Expression: " << result << endl;
    return 0;
}
