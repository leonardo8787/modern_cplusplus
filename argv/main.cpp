#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    int precisao=0;
    default_random_engine generator(time(nullptr));
    pair<double, double> range = {0, 1000};
    string input;
    int n=1;
    bool inteiro=false;
    for(int i=0; i<argc; ++i){
        input+=argv[i];
        input.append(" ");
    }
    for(int i=0; i<argc; ++i){
        if((argv[i]) == "-p"){
            cout<<"precisão: "<<argv[++i]<<endl;
            precisao=stoi(argv[++i]);
        }
    }
    input.erase(std::remove_if(input.begin(), input.end(), [](unsigned char c){ return std::isspace(c); }), input.end());
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-i") {
            inteiro = true;
        }else if (string(argv[i]) == "-n") {
            n=stoi(argv[++i]);
        }else if (string(argv[i]) == "-r") {
            range.first = stod(argv[++i]);
            range.second = stod(argv[++i]);
        } else if (string(argv[i]) == "-s") {
            generator.seed(stoi(argv[++i]));
        }
    }
    cout<<"precisao: "<<precisao<<endl;
    uniform_real_distribution<double> real_distribution(range.first, range.second);
    uniform_int_distribution<int> int_distribution((int)range.first, (int)range.second);
    if(inteiro == true)
        cout<<"Range de numeros inteiros:"<<endl;
    else
        cout<<"Range de numeros reais:"<<endl;
    for(int i=0; i<n; i++){
        double value;
        if(inteiro)
            value = int_distribution(generator);
        else 
            value = real_distribution(generator);
        cout << fixed;
        cout<<"["<<setprecision(precisao)<<value<<"] ";
    }
    return 0;
}