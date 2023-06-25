#ifndef PESSOA_H
#define PESSOA_H

#include<bits/stdc++.h>
using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;
    public:
        Pessoa() : nome(""), idade(0) {}
        Pessoa(const string& n, int a) : nome(n), idade(a) {}
        Pessoa(const Pessoa& other) : nome(other.nome), idade(other.idade) {}
        void swapFunc(Pessoa& other) {
            swap(nome, other.nome);
            swap(idade, other.idade);
        }
        string getNome() { return nome; }
        int getIdade() { return idade; }
};

#endif