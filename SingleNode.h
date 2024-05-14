#ifndef DATA_STRUCTURE_SINGLENODE_H
#define DATA_STRUCTURE_SINGLENODE_H
#include <memory>

namespace single_node {
    struct SingleNode {
        int data;
        std::unique_ptr<SingleNode> next;
        explicit SingleNode(int value) : data{value}, next{nullptr} {};
    };
}


#endif
