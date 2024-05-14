#ifndef DATA_STRUCTURE_SINGLYLINKEDLIST_H
#define DATA_STRUCTURE_SINGLYLINKEDLIST_H

#include <iostream>
#include "SingleNode.h"

using namespace std;
using namespace single_node;

template<typename T>

class SinglyLinkedList {
private:
    unique_ptr<SingleNode<T>> head;
    int size;
public:
    SinglyLinkedList() : head{nullptr}, size{0} {};

    explicit SinglyLinkedList(int value) : head{make_unique<SinglyLinkedList<T>>(value)}, size{1} {};

    void checkIndex(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
    };

    void insertAtBeginning(int value) {
        unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(value);
        newNode->next = move(head);
        head = move(newNode);
        size++;
    };

    void insertAtEnd(int value) {
        unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(value);
        SingleNode<T> *current = head.get();
        if (!current) {
            head = move(newNode);
            size++;
            return;
        }
        while (current->next) {
            current = current->next.get();
        }
        current->next = move(newNode);
        size++;
    };

    void insertAtIndex(int index, int value) {
        checkIndex(index);

        if (index == 0) {
            insertAtBeginning(value);
            return;
        } else if (index == size) {
            insertAtEnd(value);
            return;
        } else {
            unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(value);
            SingleNode<T> *current = head.get();
            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }
            newNode->next = move(current->next);
            current->next = move(newNode);
            size++;
        }
    };

    int operator[](int index) const {
        checkIndex(index);
        SingleNode<T> *current = head.get();
        for (int i = 0; i < index; i++) {
            current = current->next.get();
        }
        return current->data;
    };

    void removeFromBeginning() {
        if (!head) {
            throw out_of_range("List is empty!");
        }
        head = move(head->next);
        --size;
    };

    void removeFromEnd() {
        if (!head) {
            throw out_of_range("List is empty!");
        }
        if (size == 1) {
            head.reset();
            --size;
            return;
        }
        SingleNode<T> *current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
        --size;
    };

    void removeAtIndex(int index) {
        checkIndex(index);
        if (index == 0) {
            removeFromBeginning();
            return;
        } else if (index == size - 1) {
            removeFromEnd();
            return;
        }

        SingleNode<T> *current = head.get();
        for (int i = 0; i < index - 1; i++) {
            current = current->next.get();
        }
        current->next = move(current->next->next);
        --size;
    };

    [[nodiscard]] bool search(int value) const {
        SingleNode<T> *current = head.get();
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next.get();
        }
        return false;
    };

    [[nodiscard]] int getSize() const {
        return size;
    };

    friend ostream &operator<<(ostream &os, SinglyLinkedList<T> &obj) {
        SingleNode<T> *current = obj.head.get();
        os << "List data: " << endl;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << endl;
        return os;
    };
};


#endif
