/**
 * ````
 * Twitter Article: 
 */

#include <mutex>

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(const T& value): data(value), next = nullptr {}
};

template <typename T>
class LinkedList {
    private:
    Node<T>* head;

    public:
    LinkedList(): head(nullptr) {}
    
    void insert(const T& value);
    bool remove(const T& value);
    bool search(const T& value) const;
};

// Insert a node at the beginning
template <typename T>
void LinkedList<T>::insert(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

// Delete Operation
template <typename T>
bool LinkedList<T>::remove(const T& value) {
    if(!head) return false;

    if(head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node<T>* current = head;
    while(current->next && current->next->data != value) {
        current = current->next;
    }

    // Since we are stopping in the while loop above when we still have the next value, 
    // this condition will always be valid, and it successfully deletes the tail node as well.
    if(current->next) {
        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }

    return false;
}

// Search Operation
template <typename T>
bool LinkedList<T>::search(const T& value) const {
    Node<T>* current = head;
    while(current) {
        if(current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Thread safe Linked List
template <typename T>
class ThreadSafeLinkedList {
private:
    Node<T>* head;
    mutable std:mutex mutex;

public:
    ThreadSafeLinkedList(): head(nullptr) {}

    void insert(const T& value) {
        std::lock_guard<std::mutex> lock(mutex);
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    bool remove(const T& value) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if(head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node<T>* current = head;
        while(current->next && current->next != value) {
            current = current->next;
        }

        if(current->next) {
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            return true;
        }

        return false;
    }

    bool search(const T& value) {
        std::lock_guard<std::mutex> lock(mutex);
        Node<T>* current = head;
        while(current) {
            if(current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

// Advance Concurrency Optimization
#include <atomic>
#include <memory>

template <typename T>
class LockFreeLinkedList {
private:
    struct Node {
        T data;
        std::atomic<Node*> next;
        Node(const T& value): data(value), next(nullptr) {}
    }

    std::atomic<Node*> head;

public:
    void insert(const T& value) {
        Node* newNode = new Node(value); 
        Node* oldHead;

        do {
            oldHead = head.load(std::memory_order_relaxed);
            newNode->next.store(oldHead, std::memory_order_relaxed);
        } while(!head.compare_exchange_weak(oldHead, newNode, std::memory_order_release, std::memory_order_relaxed));
    }
};
