#include<iostream>
using namespace std;

struct Node{
    int key;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *createNode(int data){
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->key = data;
    ptr->lchild = NULL;
    ptr->rchild = NULL;
    return ptr;
}

struct Node* insert(struct Node* r, int key) {
    if (r == NULL) return createNode(key); // Create a new node if tree is empty

    struct Node* temp = r;
    struct Node* parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (key < temp->key) {
            temp = temp->lchild;
        } else if (key > temp->key) {
            temp = temp->rchild;
        } else {
            return r; // Key already exists
        }
    }

    if (key < parent->key) {
        parent->lchild = createNode(key); // Attach new node to the left
    } else {
        parent->rchild = createNode(key); // Attach new node to the right
    }

    return r;
}


int search(struct Node* r, int key) {
    if (r == NULL) {
        return 0; // Tree is empty or key not found
    }

    if (r->key == key) {
        return 1; // Key found
    } else if (key < r->key) {
        return search(r->lchild, key); // Search in the left subtree
    } else {
        return search(r->rchild, key); // Search in the right subtree
    }
}



int totalNode(struct Node *r){
    if(r==NULL)return 0;
    return (totalNode(r->rchild) + totalNode(r->lchild) + 1);
}

int largest(struct Node* r) {
    if (r == NULL) {
        cout << "Empty tree" << endl;
        return -999;
    }
    while (r->rchild != NULL) {
        r = r->rchild; // Go to the rightmost node
    }
    return r->key;
}


int smallest(struct Node* r) {
    if (r == NULL) {
        cout << "Empty tree" << endl;
        return 999;
    }
    while (r->lchild != NULL) {
        r = r->lchild; // Go to the leftmost node
    }
    return r->key;
}


int height(struct Node *r){
    if(r==NULL)return 0;
    int h1 = height(r->lchild);
    int h2 = height(r->rchild);
    int m = max(h1,h2)+1;
    return m;
}

Node* findMin(Node* r) {
    while (r->lchild != NULL) {
        r = r->lchild; // Go to the leftmost node
    }
    return r;
}

struct Node* delNode(struct Node* r, int key) {
    if (r == NULL) {
        return r; // Tree is empty or key not found
    }

    if (key < r->key) {
        r->lchild = delNode(r->lchild, key); // Search in the left subtree
    } else if (key > r->key) {
        r->rchild = delNode(r->rchild, key); // Search in the right subtree
    } else {
        // Node to be deleted found
        if (r->lchild == NULL) {
            Node* temp = r->rchild;
            free(r);
            return temp;
        } else if (r->rchild == NULL) {
            Node* temp = r->lchild;
            free(r);
            return temp;
        }

        // Node with two children
        Node* temp = findMin(r->rchild); // Find the inorder successor
        r->key = temp->key; // Replace r's key with successor's key
        r->rchild = delNode(r->rchild, temp->key); // Delete the successor
    }

    return r;
}


void inorder(struct Node* r) {
    if (r == NULL) return;
    inorder(r->lchild);
    cout << r->key << " ";
    inorder(r->rchild);
}

void preorder(struct Node* r) {
    if (r == NULL) return;
    cout << r->key << " ";
    preorder(r->lchild);
    preorder(r->rchild);
}

void postorder(struct Node* r) {
    if (r == NULL) return;
    postorder(r->lchild);
    postorder(r->rchild);
    cout << r->key << " ";
}


int main() {
    struct Node* root = NULL;
    int choice, key;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Search for a key\n";
        cout << "3. Delete a node\n";
        cout << "4. Find the largest element\n";
        cout << "5. Find the smallest element\n";
        cout << "6. Calculate total number of nodes\n";
        cout << "7. Calculate height of the tree\n";
        cout << "8. Display Inorder Traversal\n";
        cout << "9. Display Preorder Traversal\n";
        cout << "10. Display Postorder Traversal\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                root = insert(root, key);
                cout << "Key inserted.\n";
                break;

            case 2:
                cout << "Enter the key to search: ";
                cin >> key;
                if (search(root, key)) {
                    cout << "Key found in the tree.\n";
                } else {
                    cout << "Key not found in the tree.\n";
                }
                break;

            case 3:
                cout << "Enter the key to delete: ";
                cin >> key;
                root = delNode(root, key);
                cout << "Key deleted (if present).\n";
                break;

            case 4:
                cout << "Largest element: " << largest(root) << endl;
                break;

            case 5:
                cout << "Smallest element: " << smallest(root) << endl;
                break;

            case 6:
                cout << "Total number of nodes: " << totalNode(root) << endl;
                break;

            case 7:
                cout << "Height of the tree: " << height(root) << endl;
                break;

            case 8:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 9:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 10:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 11:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
