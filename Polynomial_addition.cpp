#include <iostream>
using namespace std;

struct Node {
    int exponent;
    int coefficient;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int exponent, int coefficient) {
    struct Node* ptr = new Node;
    ptr->exponent = exponent;
    ptr->coefficient = coefficient;
    ptr->next = NULL;
    return ptr;
}

// Function to insert a term into the polynomial linked list
void insert(struct Node** ptr, int exponent, int coefficient) {
    struct Node* curr = createNode(exponent, coefficient);
    if (*ptr == NULL) {
        *ptr = curr;
        return;
    }
    struct Node* temp = *ptr;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = curr;
}

// Function to add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent == p2->exponent) {
            insert(&result, p1->exponent, p1->coefficient + p2->coefficient);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exponent > p2->exponent) {
            insert(&result, p1->exponent, p1->coefficient);
            p1 = p1->next;
        } else {
            insert(&result, p2->exponent, p2->coefficient);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insert(&result, p1->exponent, p1->coefficient);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert(&result, p2->exponent, p2->coefficient);
        p2 = p2->next;
    }
    return result;
}

// Function to display the polynomial
void display(struct Node* ptr) {
    if (ptr == NULL) {
        cout << "Empty expression" << endl;
        return;
    }
    struct Node* curr = ptr;
    while (curr != NULL) {
        cout << curr->coefficient << "x^" << curr->exponent;
        if (curr->next != NULL) {
            cout << " + ";
        }
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice, exponent, coefficient;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert term into Polynomial 1\n";
        cout << "2. Insert term into Polynomial 2\n";
        cout << "3. Add Polynomials\n";
        cout << "4. Display Polynomial 1\n";
        cout << "5. Display Polynomial 2\n";
        cout << "6. Display Resultant Polynomial\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter exponent: ";
                cin >> exponent;
                cout << "Enter coefficient: ";
                cin >> coefficient;
                insert(&poly1, exponent, coefficient);
                break;

            case 2:
                cout << "Enter exponent: ";
                cin >> exponent;
                cout << "Enter coefficient: ";
                cin >> coefficient;
                insert(&poly2, exponent, coefficient);
                break;

            case 3:
                result = addPoly(poly1, poly2);
                cout << "Polynomials added successfully." << endl;
                break;

            case 4:
                cout << "Polynomial 1: ";
                display(poly1);
                break;

            case 5:
                cout << "Polynomial 2: ";
                display(poly2);
                break;

            case 6:
                cout << "Resultant Polynomial: ";
                display(result);
                break;

            case 7:
                cout << "Exiting program..." << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}