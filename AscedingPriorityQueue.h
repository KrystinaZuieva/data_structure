#ifndef DATA_STRUCTURE_ASCEDINGPRIORITYQUEUE_H
#define DATA_STRUCTURE_ASCEDINGPRIORITYQUEUE_H
#include <iostream>
#include "GeneralNode.h"

using namespace std;
using namespace general_node;

template <typename T>
class AscendingPriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        shared_ptr<Node> next;

        Node(const T& item, int priority) : data(item), priority(priority), next(nullptr) {}
    };

    shared_ptr<Node> head;

public:
    AscendingPriorityQueue() = default;

    [[nodiscard]] bool isEmpty() const {
        return !head;
    }

    void enqueue(const T& item, int priority) {
        shared_ptr<Node> newNode = make_shared<Node>(item, priority);
        if (!head || priority < head->priority) {
            newNode->next = move(head);
            head = move(newNode);
        } else {
            Node* current = head.get();
            while (current->next && current->next->priority <= priority) {
                current = current->next.get();
            }
            newNode->next = move(current->next);
            current->next = move(newNode);
        }
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        T item = move(head->data);
        head = move(head->next);
        return item;
    }

    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return head->data;
    }

    friend ostream& operator<<(ostream& os, const AscendingPriorityQueue<T>& queue) {
        auto current = queue.head.get();
        while (current) {
            os << current->data << " (Priority: " << current->priority << ") ";
            current = current->next.get();
        }
        return os;
    }
};


#endif
