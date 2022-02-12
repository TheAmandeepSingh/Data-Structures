/**
 *                                  L I N K E D   L I S T
 * Basic implementation of linked list. Added a template struct for Nodes, doubly linked list.
 * Added functions:
 * 1) addNode() - appends node at the end
 * 2) getRoot() - returns root node
 * 3) getLast() - returns last node
 * 4) deleteLast() - delete last node
 * 5) reverse() - reverse the linked list
 * 6) peekFront() - show first node data
 * 7) peekBack() - show last node data
 * 8) getSize() - returns the size of the linked list
 * 9) print() - prints the linked list
 **/

#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
struct Node {
    Node* next, *prev;
    T data;

    Node(): next{nullptr}, prev{nullptr}, data{} {}
    Node(const T& data): data{data}, next{nullptr}, prev{nullptr}{}
};

template<class T>
class LinkedList{
    Node<T>* root;
    Node<T>* last;
    int _size{};

public:
    void addNode(const T& data){
        if(_size == 0){
            root = new Node<T>(data);
            last = root;
            ++_size;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        ++_size;
    }

    Node<T>* getRoot(){
        if(_size == 0) return nullptr;
        if(root) return root;
        return nullptr;
    }

    Node<T>* getLastNode(){
        if(_size == 0) return nullptr;
        if(last) return last;
        return nullptr;
    }

    int getSize(){
        return _size;
    }

    int peekFront(){
        if(_size != 0 && root) return root->data;
        return  -1;
    }

    int peekBack(){
        if(_size != 0 && last) return last->data;
        return -1;
    }

    Node<T>* reverse(){
        if(_size == 0 || !root) return nullptr;

        Node<T>* prev(nullptr), *next(nullptr);
        Node<T>* curr(root);
        last = root; // setting last node to first

        while(curr){
            next = curr->next; //setting next node
            curr->next = prev; //reverse the nodes, setting next node's next to prev noce
            curr->prev = next; // setting prev node to next node
            prev = curr; // previous node will be current node for next loop
            curr = next;
        }

        root = prev;
        return root;
    }

    void deleteLast(){
        if(_size == 0 || !last) return;

        Node<T>* lastNode = last;
        if(last->prev){
            last->prev->next = nullptr;
        }
        last = last->prev;
        delete lastNode;
        --_size;

        if(_size == 0){
            root = nullptr;
            last = nullptr;
        }
    }

    void print(){
        if(_size == 0 || !root) {
            cout<<"Empty list"<<endl;
            return;
        }

        Node<T>* node = root;
        while(node){
            if(node->next == nullptr) {
                cout << node->data << " --> NULL"<<endl;
            } else {
                cout<<node->data<< " --> ";
            }
            node = node->next;
        }
    }
};

int main(){

    LinkedList<int>* list = new LinkedList<int>();
    if(list->getSize() == 0){
        cout<< "LinkedList is ready (:"<<endl;
    } else {
        cout<< "!! There is some issue !!"<<endl;
    }

    list->addNode(1);
    list->addNode(2);
    list->addNode(3);
    list->addNode(4);

   // assert(2 == list->getSize());

    list->print();
    list->deleteLast();
    list->print();
    cout<<"Size: "<<list->getSize()<<endl;
    cout<<"First Node: "<<list->peekFront()<<endl;
    cout<<"Last Node: "<<list->peekBack()<<endl;
    list->reverse();
    list->print();

    delete list;
    return 0;
}