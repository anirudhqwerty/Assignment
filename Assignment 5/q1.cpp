#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

void insertBeforeAfter(int value, int key, bool insertAfter) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        cout << "List is empty!\n";
        delete newNode;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with value " << key << " not found!\n";
        delete newNode;
        return;
    }
    if (insertAfter) {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << ".\n";
    } else {
        newNode->next = temp;
        if (prev == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        cout << "Inserted " << value << " before " << key << ".\n";
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted node with value " << temp->data << " from beginning.\n";
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    if (head->next == NULL) {
        cout << "Deleted node with value " << head->data << " from end.\n";
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    cout << "Deleted node with value " << temp->data << " from end.\n";
    prev->next = NULL;
    delete temp;
}

void deleteSpecific(int key) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with value " << key << " not found!\n";
        return;
    }
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    cout << "Deleted node with value " << key << ".\n";
    delete temp;
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node with value " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node with value " << key << " not found in the list.\n";
}

void displayList() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, key;
    bool insertAfter;
    do {
        cout << "Menu";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a specific node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete a specific node\n";
        cout << "7. Search for a node\n";
        cout << "8. Display all nodes\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter reference node value: ";
            cin >> key;
            cout << "Insert (1) After or (0) Before the node? ";
            cin >> insertAfter;
            insertBeforeAfter(value, key, insertAfter);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            cout << "Enter node value to delete: ";
            cin >> key;
            deleteSpecific(key);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> key;
            searchNode(key);
            break;
        case 8:
            displayList();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);
    return 0;
}
