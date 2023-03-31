#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    string input;
    bool inteiro=false;
    for(int i=0; i<argc; ++i){
        input+=argv[i];
        input.append(" ");
    }
    cout<<"\nsaida: "<<input<<endl;
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    for(int i=0; i<input.size(); ++i){
        cout<<input[i]<<endl;
    }
    for(int i=input.size(); i>=0; --i){
        if(input[i] == '-'){
            if(input[i+1] == 'i'){
                cout<<"inteiro"<<endl;
                inteiro=true;
            }
            if(input[i+1] == 'n' and inteiro == true){
                int randomico = input[i+1];
                while(randomico--) {
                    int numero=rand();
                    cout<<numero<<" ";
                }
            }else{
                int randomico = input[i+1];
                while(randomico--) {
                    int numero=rand();
                    cout<<numero<<" ";
                }
            }
        }
    }
    return 0;
}


