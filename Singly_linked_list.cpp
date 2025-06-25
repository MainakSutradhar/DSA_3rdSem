#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int key){
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = key;
    ptr->next = NULL;
    return ptr;
}

struct Node *addBeg(int key){
        struct Node *ptr = createNode(key);
        ptr->next = head;
        head = ptr;
        return ptr;
}

struct Node *addEnd(int key){
    struct Node *ptr = createNode(key);
    if(head == NULL){
        head = ptr;
        return ptr;
    }
    struct Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = ptr;
    return ptr;
}

void delBeg(){
    if(head == NULL){
        cout<<endl<<"Empty list"<<endl;
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void delEnd(){
    if(head == NULL){
        cout<<endl<<"Empty list"<<endl;
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    struct Node *curr = temp->next;
    temp->next = NULL;
    free(curr);
}

int count(){
    if(head == NULL)return 0;
    struct Node *temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

int search(int item){
    if(head == NULL){
        cout<<endl<<"Empty list "<<endl;
        return 0;
    }
    struct Node *temp = head;
    while(temp != NULL){
        if(temp->data == item)return 1;
        temp = temp->next;
    }
    return 0;
}

int smallest(){
    if(head == NULL){
        cout<<endl<<"Empty list "<<endl;
        return -999;
    }
    struct Node *temp = head;
    int min = 999;
    while(temp != NULL){
        if(temp->data < min){
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

int largest(){
    if(head == NULL){
        cout<<endl<<"Empty list "<<endl;
        return 999;
    }
    struct Node *temp = head;
    int max = -999;
    while(temp != NULL){
        if(temp->data < max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void reverse() {
    if (head == NULL) {
        cout << endl << "Empty list " << endl;
        return;
    }
    struct Node *curr, *temp = NULL;
    while (head != NULL) {
        curr = head;
        head = head->next;
        curr->next = temp;
        temp = curr;
    }
    head = temp;
}

void addSorted(int item){
    struct Node *ptr = createNode(item);
    if(head == NULL){
        head = ptr;
    }
    struct Node *temp = head;
    while(temp->data<item || temp!=NULL){
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = temp->next->next;
}



void display(){
    if(head == NULL){
        cout<<endl<<"Empty list"<<endl;
        return;
    }
    
    struct Node *temp = head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main() {
    int choice, item;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add element at the beginning\n";
        cout << "2. Add element at the end\n";
        cout << "3. Delete element from the beginning\n";
        cout << "4. Delete element from the end\n";
        cout << "5. Display the list\n";
        cout << "6. Count elements in the list\n";
        cout << "7. Search for an element\n";
        cout << "8. Find the smallest element\n";
        cout << "9. Find the largest element\n";
        cout << "10. Reverse the list\n";
        cout << "11. Add element in sorted order\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add at the beginning: ";
                cin >> item;
                addBeg(item);
                display(); // Display after addition at the beginning
                break;

            case 2:
                cout << "Enter value to add at the end: ";
                cin >> item;
                addEnd(item);
                display(); // Display after addition at the end
                break;

            case 3:
                delBeg();
                display(); // Display after deletion from the beginning
                break;

            case 4:
                delEnd();
                display(); // Display after deletion from the end
                break;

            case 5:
                display(); // Display list when asked directly
                break;

            case 6:
                cout << "Number of elements in the list: " << count() << endl;
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> item;
                if (search(item)) {
                    cout << "Element found in the list.\n";
                } else {
                    cout << "Element not found.\n";
                }
                break;

            case 8:
                cout << "Smallest element: " << smallest() << endl;
                break;

            case 9:
                cout << "Largest element: " << largest() << endl;
                break;

            case 10:
                reverse();
                display(); // Display after reversing the list
                break;

            case 11:
                cout << "Enter value to add in sorted order: ";
                cin >> item;
                addSorted(item);
                display(); // Display after adding in sorted order
                break;

            case 12:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}