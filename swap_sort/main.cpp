#include "SwapSort.hpp"

int main() {
    vector<SwapSort> vec;

    vec.push_back(SwapSort(3));
    vec.push_back(SwapSort(1));
    vec.push_back(SwapSort(2));

    sort(vec.begin(), vec.end());

    for (const SwapSort& t : vec)
        cout<<t.getData()<<" ";
    cout<<endl;

    return 0;
}
