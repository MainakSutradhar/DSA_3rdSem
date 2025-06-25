#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

struct Node *createNode(int item){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = item;
    ptr->next = NULL;
    return ptr;
}

void addBeg(int item){
    struct Node *ptr = createNode(item);
    if(last == NULL){
        ptr->next = ptr;
        last = ptr;
        return;
    }
    ptr->next = last->next;
    last->next = ptr;
}

void addEnd(int item){
    struct Node *ptr = createNode(item);
    if(last == NULL){
        ptr->next = ptr;
        last = ptr;
        return;
    }
    ptr->next = last->next;
    last->next = ptr;
    last = ptr;
}

void delBeg(){
    if(last == NULL){
        cout<<endl<<"Empty list "<<endl;
        return;
    }
    if(last->next == NULL){
        free(last);
        last = NULL;
        return;
    }
    struct Node *temp = last->next;
    last->next = last->next->next;
    free(temp);
}

void delEnd(){
    if(last == NULL){
        cout<<endl<<"Empty list "<<endl;
        return;
    }
    if(last->next == NULL){
        free(last);
        last = NULL;
        return;
    }
    struct Node *temp = last->next;
    while(temp->next != last){
        temp = temp->next;
    }
    temp->next = last->next;
    free(last);
    last = temp;
    return;
}

void display(){
    if(last == NULL){
        cout<<endl<<"Empty list "<<endl;
        return;
    }
    struct Node *temp = last->next;
    cout<<endl;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != last->next);
    cout<<endl;
}



int main() {
    int choice, item;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add at Beginning\n";
        cout << "2. Add at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to add at the beginning: ";
                cin >> item;
                addBeg(item);
                display();
                break;

            case 2:
                cout << "Enter the element to add at the end: ";
                cin >> item;
                addEnd(item);
                display();
                break;

            case 3:
                delBeg();
                display();
                break;

            case 4:
                delEnd();
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting program..." << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}