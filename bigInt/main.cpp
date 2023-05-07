/*
Big int 

representação interna com array
construtor que recebe array
construtor de cópia 
operador de atribuição por cópia
operadores +, -, *, /
operador literal (sufixo _)
*/

#include "bigInt.hpp"
#include "bigInt.cpp"

int main(){
    string numero1, numero2; cin>>numero1>>numero2;
    cout<<numero1<<" "<<numero2;
    cout<<endl<<"========= Resultado ========="<<endl;
    cout<<"soma: "<<somarStrings(numero1, numero2)<<endl;
    cout<<"subtracao: "<<subtrairStrings(numero1, numero2)<<endl;
    cout<<"multiplicacao: "<<multiplicarStrings(numero1, numero2)<<endl;
    cout<<"divisao: "<<dividirStrings(numero1, numero2)<<endl;
    return 0;
}