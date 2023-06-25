#include "gradiente.h"

int main(){
    auto f = [](vector<double> x) {
        return (x[0] * x[0]) + 2 * x[1];
    };
    vector<double> x = {2.0, 3.0};
    auto g = gradiente(f, x, 1e-9);
    cout<<"["<<g[0]<<" , "<<g[1]<<"]"<<endl;
    return 0;
}