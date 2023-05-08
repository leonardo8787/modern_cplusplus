/*
Big int 

representação interna com array
construtor que recebe array
construtor de cópia 
operador de atribuição por cópia
operadores +, -, *, /
operador literal (sufixo _)
*/

#include "bigIntWithClass.hpp"

int main(){
    // BigIng num1("123456789012345678901234567890");
    // BigIng num2("987654321098765432109876543210");

    BigIng num1("1");
    BigIng num2("2");

    cout<<endl<<"========= Resultado ========="<<endl;
    
    BigIng sum = num1 + num2;
    cout<<"soma: "<<sum.toString()<<endl;
    BigIng diff = num1 - num2;
    cout<<"subtracao: "<<diff.toString()<<endl;
    // BigIng prod = num1 * num2;
    // cout<<"multiplicacao: "<<prod.toString()<<endl; 
    // BigIng quotient = num1 / num2;
    // cout<<"divisao (inteira): "<<quotient.toString()<<endl;
    
    return 0;
}