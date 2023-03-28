#ifndef NO_H
#define NO_H

#include <iostream>
using namespace std;

//nó é criado, bem parecido com uma struct.
template <typename T>
class Node {
    public:
        T value;
        Node<T>* next;
        Node(T val) {
            value = val;
            next = nullptr;
        }
};

#endif