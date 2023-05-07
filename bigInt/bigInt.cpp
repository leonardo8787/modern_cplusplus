#include "bigInt.hpp"

string somarStrings(string str1, string str2) {
    string num1 = str1;
    string num2 = str2;
    int tamanho = max(num1.length(), num2.length());
    num1 = string(tamanho - num1.length(), '0') + num1;
    num2 = string(tamanho - num2.length(), '0') + num2;
    string resultado = "";
    int carry = 0;
    for (int i = tamanho - 1; i >= 0; i--) {
        int soma = (num1[i] - '0') + (num2[i] - '0') + carry;
        resultado = to_string(soma % 10) + resultado;
        carry = soma / 10;
    }
    if (carry != 0)
        resultado = to_string(carry) + resultado;
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
    int tamanho = max(str1.length(), str2.length());
    str2 = string(tamanho - str2.length(), '0') + str2;
    string resultado = "";
    int borrow = 0;
    for (int i = tamanho - 1; i >= 0; i--) {
        int subtracao = (str1[i] - '0') - (str2[i] - '0') - borrow;
        if (subtracao < 0) {
            subtracao += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        resultado = to_string(subtracao) + resultado;
    }
    while (resultado[0] == '0' && resultado.length() > 1) {
        resultado.erase(0, 1);
    }
    if (negativo) {
        resultado = "-" + resultado;
    }
    return resultado;
}

string multiplicarStrings(string str1, string str2) {
    if (str1 == "0" || str2 == "0") 
        return "0";
    if (str1.length() < str2.length()) 
        swap(str1, str2);
    string resultado = "0";
    for (int i = str2.length() - 1; i >= 0; i--) {
        int multiplicador = str2[i] - '0';
        int carry = 0;
        string parcial = "";
        for (int j = str1.length() - 1; j >= 0; j--) {
            int produto = multiplicador * (str1[j] - '0') + carry;
            carry = produto / 10;
            produto %= 10;
            parcial = std::to_string(produto) + parcial;
        }
        if (carry > 0) 
            parcial = std::to_string(carry) + parcial;
        parcial += std::string(str2.length() - i - 1, '0');
        resultado = somarStrings(resultado, parcial);
    }
    while (resultado[0] == '0' && resultado.length() > 1) 
        resultado.erase(0, 1);
    return resultado;
}

string dividirStrings(string dividendo, string divisor) {
    if (divisor == "0" || dividendo < divisor)
        return "0";
    string quociente = "";
    string resto = "";
    int i = 0;
    while (i < dividendo.length()) {
        resto += dividendo[i];
        int contador_quociente = 0;
        while (divisor <= resto) {
            resto = subtrairStrings(resto, divisor);
            contador_quociente++;
        }
        if (quociente != "" || contador_quociente > 0) {
            quociente += to_string(contador_quociente);
        }
        i++;
    }
    if (quociente == "")
        return "0";
    while (quociente[0] == '0' && quociente.length() > 1)
        quociente.erase(0, 1);
    return quociente;
}