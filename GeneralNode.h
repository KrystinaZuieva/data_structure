#ifndef DATA_STRUCTURE_GENERALNODE_H
#define DATA_STRUCTURE_GENERALNODE_H

#include <memory>

namespace general_node {
    template<typename T>
    struct Node {
        T data;
        std::shared_ptr<Node<T>> next;

        explicit Node(const T &value) : data{value}, next{nullptr} {};
    };
}

#endif
