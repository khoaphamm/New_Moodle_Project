#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::add(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template <typename T>
void LinkedList<T>::remove(const T& data) {
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

template <typename T>
Node<T>* LinkedList<T>::find(const T& data) const {
    Node<T>* current = head;
    while (current != nullptr && current->data != data) {
        current = current->next;
    }
    return current; // returns nullptr if data not found
}

