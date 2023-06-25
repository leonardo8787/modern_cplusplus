#ifndef MYCLASSE_H
#define MYCLASSE_H

#include <bits/stdc++.h>
using namespace std;

class MyClass {
public:
    MyClass() : data(nullptr), size(0) {}
    MyClass(const MyClass& other) : data(new int[other.size]), size(other.size) {
        copy(other.data, other.data + size, data);
    }
    ~MyClass() { delete[] data; }
    MyClass& operator=(MyClass other) {
        swap(data, other.data);
        swap(size, other.size);
        return *this;
    }
private:
    int* data;
    size_t size;
};

#endif