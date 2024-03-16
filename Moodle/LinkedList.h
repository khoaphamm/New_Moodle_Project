#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& data, Node* next = nullptr)
        : data(data), next(next) {}
};


template <typename T>
class LinkedList {
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}

    void add(const T& data){
         Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void addSorted(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr || *data <= *head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr && *current->next->data < *data) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        count++;
   }

    void remove(const T& data){
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current != nullptr && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) return; // data not found
        if (prev == nullptr) { // data is in the first node
            head = current->next;
            if (head == nullptr) tail = nullptr; // list is now empty
        } else {
            prev->next = current->next;
            if (current->next == nullptr) tail = prev; // data is in the last node
        }
        delete current;
        count--;
    }

    Node<T>* find(const T& data) const{
        Node<T>* current = head;
        while (current != nullptr && current->data != data) {
            current = current->next;
        }
        return current; // returns nullptr if data not found
    }
    
    int size() const{
        return count;
    }

    T& get(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    T removeFirst() {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node<T>* oldHead = head;
        T data = oldHead->data; // Copy the data
        head = head->next;
        if (head == nullptr) {
            tail = nullptr; // The list is now empty
        }
        delete oldHead; // Delete the old head node
        count--;
        return data; // Return the data of the removed node
    }

    bool isEmpty(){
        return count == 0;
    }

    // ~LinkedList(){
    //     Node<LinkedList<T>*>* current = head;
    //     while (current != nullptr) {
    //         Node<LinkedList<T>*>* next = current->next;
    //         delete current->data;  // delete the LinkedList that current points to
    //         delete current;  // delete the node itself
    //         current = next;
    //     }
    //     head = tail = nullptr;
    //     count = 0;
    // }
};



#endif // LINKEDLIST_H
