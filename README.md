# ab-dsa-lab-4
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* last;  // Points to the last node

    CircularLinkedList() : last(nullptr) {}

    // Function to insert a node at the end of the list
    void insert_end(char value) {
        Node* newNode = new Node(value);
        if (last == nullptr) {
            // List is empty, point new node to itself
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;  // New node points to the head (first node)
            last->next = newNode;        // Last node points to the new node
            last = newNode;              // New node becomes the last node
        }
    }

    // Function to traverse and print the list
    void traverse() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = last->next;  // Start from the first node
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);  // Stop when we reach the starting node
        cout << endl;
    }

    // Function to merge two circular linked lists
    void merge(CircularLinkedList& other) {
        if (last == nullptr || other.last == nullptr) {
            cout << "One of the lists is empty, cannot merge." << endl;
            return;
        }

        Node* temp = last->next;  // Store the reference to the first node of list1

        last->next = other.last->next;  // Connect list1's last node to list2's first node
        other.last->next = temp;        // Connect list2's last node to list1's first node
        last = other.last;              // Update the last node to list2's last node
    }
};

int main() {
    CircularLinkedList list1;
    CircularLinkedList list2;

    // Insert characters to list1 ("POWER")
    list1.insert_end('P');
    list1.insert_end('O');
    list1.insert_end('W');
    list1.insert_end('E');
    list1.insert_end('R');

    // Insert characters to list2 ("POINT")
    list2.insert_end('P');
    list2.insert_end('O');
    list2.insert_end('I');
    list2.insert_end('N');
    list2.insert_end('T');

    // Merge list1 and list2
    list1.merge(list2);

    // Traverse and print the merged list
    list1.traverse();  // Output should be: P O W E R P O I N T
    return 0;
}

