#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include <iostream>
#include "GeneralNode.h"

using namespace std;
using namespace general_node;

template<typename T>

class Queue {
private:
    shared_ptr<Node<T>> front;
    Node<T> *rear;

public:
    Queue() : rear(nullptr) {}

    [[nodiscard]] bool isEmpty() const {
        return !front;
    }

    void enqueue(const T &item) {
        shared_ptr<Node<T>> newNode = make_shared<Node<T>>(item);
        if (!front) {
            front = move(newNode);
            rear = front.get();
        } else {
            rear->next = move(newNode);
            rear = rear->next.get();
        }
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        T item = move(front->data);
        front = move(front->next);
        if (!front) {
            rear = nullptr;
        }
        return item;
    }

    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return front->data;
    }

    friend ostream& operator<<(ostream& os, const Queue<T>& queue) {
        auto current = queue.front.get();
        while (current) {
            os << current->data << " ";
            current = current->next.get();
        }
        return os;
    }
};

#endif