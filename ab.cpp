#include <iostream>
using namespace std;

class HList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    // Constructor: Initializes the dummy head node
    HList() {
        head = new Node(0);  // Dummy head node with value 0
    }

    // Checks if the list is empty
    bool emptyList() {
        return head->next == nullptr;
    }

    // Inserts a new node with value ‘newV’ after node with value ‘oldV’
    void insert_after(int oldV, int newV) {
        Node* current = head->next;  // Start from the first actual node
        while (current != nullptr) {
            if (current->data == oldV) {
                Node* newNode = new Node(newV);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Node with value " << oldV << " not found." << endl;
    }

    // Inserts a new node at the start of the list
    void insert_begin(int value) {
        Node* newNode = new Node(value);
        newNode->next = head->next;
        head->next = newNode;
    }

    // Inserts a new node at the end of the list
    void insert_end(int value) {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(value);
    }

    // Deletes a node with value 'val' from the list
    void delete_Node(int val) {
        Node* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            cout << "Node with value " << val << " not found." << endl;
        }
    }

    // Deletes a node from the beginning of the list
    void delete_begin() {
        if (emptyList()) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }

    // Deletes a node from the end of the list
    void delete_end() {
        if (emptyList()) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    // Displays the values stored in the list
    void traverse() {
        if (emptyList()) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head->next;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor: Cleans up all nodes to prevent memory leaks
    ~HList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    HList list;
    list.insert_begin(10);
    list.insert_end(20);
    list.insert_end(30);
    list.insert_after(20, 25);
    list.traverse();  // Output: 10 20 25 30
    list.delete_Node(25);
    list.traverse();  // Output: 10 20 30
    list.delete_begin();
    list.traverse();  // Output: 20 30
    list.delete_end();
    list.traverse();  // Output: 20
    return 0;
}
