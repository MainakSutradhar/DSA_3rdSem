#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty(){
    return (top == NULL);
}

struct Node *createNode(int item){
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = item;
    ptr->next = NULL;
    return ptr;
}

void push(int item){
    struct Node *ptr = createNode(item);
    ptr->next = top;
    top = ptr;
}

void pop(){
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

int peek(){
    return top->data;
}

void display(){
    struct Node *temp = top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}



int main() {
    int choice, item;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push onto the stack: ";
                cin >> item;
                push(item);
                display();
                break;

            case 2:
                if (isEmpty()) {
                    cout << "Stack is empty. Cannot perform pop operation!" << endl;
                } else {
                    cout << "Popped element: " << peek() << endl;
                    pop();
                    display();
                }
                break;

            case 3:
                if (isEmpty()) {
                    cout << "Stack is empty. Nothing to peek!" << endl;
                } else {
                    cout << "Top element is: " << peek() << endl;
                }
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}