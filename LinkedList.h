#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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

public:
    LinkedList() : head(nullptr) {}

    void add(const T& data);

    void remove(const T& data);

    Node<T>* find(const T& data) const;
    
    size_t size() const;
};

#endif // LINKEDLIST_H