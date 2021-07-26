#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class Stack {
    Node* head;
    Node* tail;
public:
    Stack() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~Stack() {
        Node* temp = this->head;
        Node* temp_next = nullptr;
        while(temp != nullptr) {
            temp_next = temp_next;
            delete temp;
            temp = temp_next;
        }
    }

    int len() {
        int length = 0;
        Node* temp = this->head; 
        while(temp != nullptr) {
            length++;
            temp = this->head->next;
        }

        return length;
    }

    void push(int new_Value) {
        // Case when the inserted node is null
        Node* newNode = new Node(new_Value);
        if (newNode == nullptr) {
            return;
        } // Case when the inserted node is inserted to an empty list
        if (this->head == nullptr) {
            this->head = newNode;
        }
        else { // Otherwise, just insert it in the stack.
            newNode->next = this->head;
            this->head = newNode;
        }
    }


    void print() {
        Node* temp = this->head;
        while(temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int pop() {
        if (this->head == nullptr) {
            return -1;
        }
        int value = 0;
        Node* temp = this->head;
        this->head = temp->next;
        value = temp->value;
        free(temp);
        return value;
    }


};

int main() {
    int n = 0;
    cout << "Enter number of nodes you want to use: ";
    cin >> n;

    Stack* myStack = new Stack();

    for(int i = 0 ; i < n ; ++i) {
        int temp = 0;
        cin >> temp;
        

        myStack->push(temp);
    }

    myStack->print();
    int val = myStack->pop();
    cout << val << endl;
    val = myStack->pop();
    cout << val << endl;
    val = myStack->pop();
    cout << val << endl;
    val = myStack->pop();
    cout << val << endl;
    val = myStack->pop();
    cout << val << endl;

    myStack->push(123);
    myStack->push(234);
    myStack->push(420);

    myStack->print();

    val = myStack->pop();
    cout << val << endl;
    val = myStack->pop();
    cout << val << endl;
    val = myStack->pop();
    cout << val << endl;


    delete myStack;
}