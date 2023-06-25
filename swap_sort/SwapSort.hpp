#ifndef SWAPSORT_H
#define SWAPSORT_H

#include<bits/stdc++.h>
using namespace std;

class SwapSort {
    private:
        int data;
    public:
        SwapSort(int d) : data(d) {}
        int getData() const { return data; }
        void swapFunc(SwapSort& other) {
            cout<<"Chamada swap: "<<data<<" e "<<other.data<<endl;
            swap(data, other.data);
        }
};

#endif