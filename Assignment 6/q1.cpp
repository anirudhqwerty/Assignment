#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* headC = NULL;
Node* headD = NULL;

void insertCircular(int value, int posType, int key = 0) {
    Node* newNode = new Node();
    newNode->data = value;
    if (headC == NULL) {
        newNode->next = newNode;
        headC = newNode;
        cout << "Inserted " << value << " as the first node.\n";
        return;
    }
    if (posType == 1) {
        Node* temp = headC;
        while (temp->next != headC)
            temp = temp->next;
        newNode->next = headC;
        temp->next = newNode;
        headC = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    } else if (posType == 2) {
        Node* temp = headC;
        while (temp->next != headC)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = headC;
        cout << "Inserted " << value << " at the end.\n";
    } else if (posType == 3) {
        Node* temp = headC;
        while (temp->data != key && temp->next != headC)
            temp = temp->next;
        if (temp->data != key) {
            cout << "Node " << key << " not found.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << ".\n";
    } else if (posType == 4) {
        Node* temp = headC;
        Node* prev = NULL;
        do {
            if (temp->data == key)
                break;
            prev = temp;
            temp = temp->next;
        } while (temp != headC);
        if (temp->data != key) {
            cout << "Node " << key << " not found.\n";
            delete newNode;
            return;
        }
        if (temp == headC) {
            Node* last = headC;
            while (last->next != headC)
                last = last->next;
            newNode->next = headC;
            headC = newNode;
            last->next = headC;
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
        cout << "Inserted " << value << " before " << key << ".\n";
    }
}

void deleteCircular(int key) {
    if (headC == NULL) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = headC;
    Node* prev = NULL;
    do {
        if (temp->data == key)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != headC);
    if (temp->data != key) {
        cout << "Node " << key << " not found.\n";
        return;
    }
    if (temp == headC && temp->next == headC) {
        delete headC;
        headC = NULL;
    } else if (temp == headC) {
        Node* last = headC;
        while (last->next != headC)
            last = last->next;
        headC = headC->next;
        last->next = headC;
        delete temp;
    } else {
        prev->next = temp->next;
        delete temp;
    }
    cout << "Deleted node " << key << ".\n";
}

void searchCircular(int key) {
    if (headC == NULL) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = headC;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != headC);
    cout << "Node " << key << " not found.\n";
}

void displayCircular() {
    if (headC == NULL) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = headC;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != headC);
    cout << "(head)\n";
}

void insertDoubly(int value, int posType, int key = 0) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    if (headD == NULL) {
        headD = newNode;
        cout << "Inserted " << value << " as the first node.\n";
        return;
    }
    if (posType == 1) {
        newNode->next = headD;
        headD->prev = newNode;
        headD = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    } else if (posType == 2) {
        Node* temp = headD;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << value << " at the end.\n";
    } else if (posType == 3) {
        Node* temp = headD;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << ".\n";
    } else if (posType == 4) {
        Node* temp = headD;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            delete newNode;
            return;
        }
        newNode->prev = temp->prev;
        newNode->next = temp;
        if (temp->prev != NULL)
            temp->prev->next = newNode;
        else
            headD = newNode;
        temp->prev = newNode;
        cout << "Inserted " << value << " before " << key << ".\n";
    }
}

void deleteDoubly(int key) {
    if (headD == NULL) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = headD;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node " << key << " not found.\n";
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        headD = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
    cout << "Deleted node " << key << ".\n";
}

void searchDoubly(int key) {
    if (headD == NULL) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = headD;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << key << " not found.\n";
}

void displayDoubly() {
    if (headD == NULL) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = headD;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int listType, choice, value, key, posType;
    do {
        cout << "Main Menu";
        cout << "1. Circular Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> listType;

        if (listType == 1) {
            do {
                cout << "CLL";
                cout << "1. Insert Node\n";
                cout << "2. Delete Node\n";
                cout << "3. Search Node\n";
                cout << "4. Display List\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        cout << "1.Beginning 2.End 3.After 4.Before : ";
                        cin >> posType;
                        if (posType == 3 || posType == 4) {
                            cout << "Enter reference node value: ";
                            cin >> key;
                            insertCircular(value, posType, key);
                        } else {
                            insertCircular(value, posType);
                        }
                        break;
                    case 2:
                        cout << "Enter node value to delete: ";
                        cin >> key;
                        deleteCircular(key);
                        break;
                    case 3:
                        cout << "Enter value to search: ";
                        cin >> key;
                        searchCircular(key);
                        break;
                    case 4:
                        displayCircular();
                        break;
                }
            } while (choice != 5);
        }

        else if (listType == 2) {
            do {
                cout << "DLL";
                cout << "1. Insert Node\n";
                cout << "2. Delete Node\n";
                cout << "3. Search Node\n";
                cout << "4. Display List\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        cout << "1.Beginning 2.End 3.After 4.Before : ";
                        cin >> posType;
                        if (posType == 3 || posType == 4) {
                            cout << "Enter reference node value: ";
                            cin >> key;
                            insertDoubly(value, posType, key);
                        } else {
                            insertDoubly(value, posType);
                        }
                        break;
                    case 2:
                        cout << "Enter node value to delete: ";
                        cin >> key;
                        deleteDoubly(key);
                        break;
                    case 3:
                        cout << "Enter value to search: ";
                        cin >> key;
                        searchDoubly(key);
                        break;
                    case 4:
                        displayDoubly();
                        break;
                }
            } while (choice != 5);
        }

    } while (listType != 3);

    cout << "Exiting...\n";
    return 0;
}
