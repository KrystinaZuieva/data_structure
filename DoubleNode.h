#ifndef DATA_STRUCTURE_DOUBLENODE_H
#define DATA_STRUCTURE_DOUBLENODE_H
#include <memory>

namespace double_node {
    struct DoubleNode {
        int data;
        std::shared_ptr<DoubleNode> next;
        std::weak_ptr<DoubleNode> previous;
        explicit DoubleNode(int value) : data{value} {}
    };
}

#endif
