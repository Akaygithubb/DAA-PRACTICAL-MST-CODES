#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << val << " at the beginning.\n";
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted " << val << " at the end.\n";
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        cout << "Deleted " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        cout << "Deleted " << temp->data << " from the end.\n";
        delete temp;
    }

    // Display the list
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.insertAtEnd(25);

    dll.display();

    dll.deleteFromBeginning();
    dll.deleteFromEnd();

    dll.display();

    return 0;
}
//2nd code---------------->






#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr) {}
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    CircularLinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted " << val << " at the beginning.\n";
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << val << " at the end.\n";
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->next == head) { // Only one node
            cout << "Deleted " << head->data << " from the beginning.\n";
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* toDelete = head;
            head = head->next;
            temp->next = head;
            cout << "Deleted " << toDelete->data << " from the beginning.\n";
            delete toDelete;
        }
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->next == head) { // Only one node
            cout << "Deleted " << head->data << " from the end.\n";
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = head;
            cout << "Deleted " << toDelete->data << " from the end.\n";
            delete toDelete;
        }
    }

    // Display the list
    void display() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtBeginning(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.insertAtEnd(25);

    cll.display();

    cll.deleteFromBeginning();
    cll.deleteFromEnd();

    cll.display();

    return 0;
}
