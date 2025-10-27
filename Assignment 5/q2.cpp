#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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
}

int deleteOccurrences(int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == key) {
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
            count++;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return count;
}

void displayList() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int n, value, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(value);
    }
    cout << "Enter key to count and delete: ";
    cin >> key;
    int count = deleteOccurrences(key);
    cout << "Occurrences of " << key << ": " << count << "\n";
    cout << "List after deletion: ";
    displayList();
    return 0;
}
