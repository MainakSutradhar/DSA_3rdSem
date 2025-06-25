#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    int priority;
};
 
struct Node *front = NULL;
 
struct Node *createNode(int item,int p){
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = item;
    ptr->priority = p;
    ptr->next = NULL;
    return ptr;
}

void enqueue(int item,int priority){
    struct Node *ptr = createNode(item,priority);
    if(front == NULL || front->priority >= priority){
        ptr->next = front;
        front = ptr;
        return;
    }
    struct Node *temp = front;
    while(temp->priority < priority && temp->next!=NULL){
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    
}

void dequeue(){
    if(front == NULL){
        cout<<endl<<"Empty queue"<<endl;
        return;
    }
    struct Node *temp = front;
    front = temp->next;
    free(temp);
    return;
}

void display(){
    if(front == NULL){
        cout<<"Empty queue "<<endl;
        return;
    }
    struct Node *temp = front;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}




int main() {
    int choice, item, priority;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> item;
                cout << "Enter its priority: ";
                cin >> priority;
                enqueue(item, priority);
                cout << "Queue after enqueue: ";
                display();
                break;

            case 2:
                if (front == NULL) {
                    cout << "Queue is empty. Cannot dequeue.\n";
                } else {
                    dequeue();
                    cout << "Queue after dequeue: ";
                    display();
                }
                break;

            case 3:
                cout << "Queue: ";
                display();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}




