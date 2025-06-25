#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Pointers for the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to create a new node
struct Node* createNode(int item) {
    struct Node* ptr = new Node; // Use new instead of malloc
    ptr->data = item;
    ptr->next = NULL;
    return ptr;
}

// Function to enqueue an element into the queue
void enqueue(int item) {
    struct Node* ptr = createNode(item);
    if (front == NULL) {
        front = rear = ptr; // If queue is empty, front and rear are the same
    } else {
        rear->next = ptr; // Link the new node to the current rear
        rear = ptr;       // Update the rear pointer
    }
    cout << item << " enqueued into the queue." << endl;
}

// Function to dequeue an element from the queue
void dequeue() {
    struct Node* temp = front;
    cout << front->data << " dequeued from the queue." << endl;
    front = front->next; // Move front to the next node
    if (front == NULL) { // If the queue becomes empty
        rear = NULL;
    }
    delete temp; // Use delete instead of free
}

// Function to get the front element of the queue
int peek() {
    return front->data;
}

// Function to display the queue
void display() {
    struct Node* temp = front;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Menu-driven main function
int main() {
    int choice, item;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> item;
                enqueue(item);
                display();
                break;

            case 2:
                if (front == NULL) {
                    cout << "Queue is empty. Cannot dequeue!" << endl;
                } else {
                    dequeue();
                    display();
                }
                break;

            case 3:
                if (front == NULL) {
                    cout << "Queue is empty. Nothing to peek!" << endl;
                } else {
                    cout << "Front element is: " << peek() << endl;
                }
                break;

            case 4:
                if (front == NULL) {
                    cout << "Queue is empty. Nothing to display!" << endl;
                } else {
                    display();
                }
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
