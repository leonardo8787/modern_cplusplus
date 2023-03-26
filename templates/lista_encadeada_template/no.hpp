#ifndef NO_H
#define NO_H

#include <iostream>
using namespace std;

//nó é criado, bem parecido com uma struct.
class Node {
    public:
        int value;
        Node* next;
        template <typename T> Node(T val) {
            value = val;
            next = nullptr;
        }
};

#endif