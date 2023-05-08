#include<bits/stdc++.h>
using namespace std;

string somaStringAlternativo(string str1, string str2){
    int tamanhoTotal = max(str1.length(), str2.length());
    long long int tam1 = str1.size();
    long long int tam2 = str1.size();
    long long int soma=0;
    long long int vaiUm=0;
    string resultado="";
    str1 = string(tam1 - str1.length(), '0') + str1;
    str2 = string(tam2 - str2.length(), '0') + str2;
    for(long long int i=tamanhoTotal-1; i>=0; i--){
        soma=(str1[i]-'0')+(str2[i]-'0')+vaiUm;
        resultado=to_string(soma % 10)+resultado;
        vaiUm=soma/10;
    }
    if(vaiUm != 0)
        resultado=to_string(vaiUm)+resultado;
    return resultado;
}

string subtrairStrings(string str1, string str2) {
    if (str1 == str2)
        return "0";
    bool negativo = false;
    if (str1.length() < str2.length() || (str1.length() == str2.length() && str1 < str2)) {
        swap(str1, str2);
        negativo = true;
    }
    long long int tamanho = max(str1.length(), str2.length());
    str2 = string(tamanho - str2.length(), '0') + str2;
    string resultado = "";
    long long int borrow = 0;
    for (long long int i = tamanho - 1; i >= 0; i--) {
        long long int subtracao = (str1[i] - '0') - (str2[i] - '0') - borrow;
        if (subtracao < 0) {
            subtracao += 10;
            borrow = 1;
        } else
            borrow = 0;
        resultado = to_string(subtracao) + resultado;
    }
    while (resultado[0] == '0' && resultado.length() > 1)
        resultado.erase(0, 1);
    if (negativo) 
        resultado = "-" + resultado;
    return resultado;
}

string multiplicarStrings(string str1, string str2) {
    if (str1 == "0" || str2 == "0") 
        return "0";
    if (str1.length() < str2.length()) 
        swap(str1, str2);
    string resultado = "0";
    for (long long int i = str2.length() - 1; i >= 0; i--) {
        long long int multiplicador = str2[i] - '0';
        long long int carry = 0;
        string parcial = "";
        for (long long int j = str1.length() - 1; j >= 0; j--) {
            long long int produto = multiplicador * (str1[j] - '0') + carry;
            carry=produto/10;
            produto%=10;
            parcial=to_string(produto)+parcial;
        }
        if (carry > 0) 
            parcial=to_string(carry)+parcial;
        parcial+=string(str2.length()-i-1,'0');
        resultado=somarStrings(resultado, parcial);
    }
    while (resultado[0] == '0' && resultado.length() > 1) 
        resultado.erase(0, 1);
    return resultado;
}