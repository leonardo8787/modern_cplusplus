#ifndef RACIONAL_H
#define RACIONAL_H

#include<bits/stdc++.h>
using namespace std;

class Racional {
    private:
        int denominador;
        int numerador;         
    public:
        Racional() : numerador(0), denominador(1) {}
        Racional(int numera, int denomina) : numerador(numera), denominador(denomina) {}
        Racional(const Racional& other) : numerador(other.numerador), denominador(other.denominador) {}
        Racional(Racional&& other) : numerador(other.numerador), denominador(other.denominador) {
            other.numerador = 0;
            other.denominador = 1;
        }
        ~Racional() {}
        Racional& operator=(const Racional& other) {
            if (this != &other) {
                numerador = other.numerador;
                denominador = other.denominador;
            }
            return *this;
        }
        // Racional& operador=(Racional&& other) {
        //     if(this != &other){
        //         numerador = other.numerador;
        //         denominador = other.denominador;
        //         other.numerador = 0;
        //         other.denominador = 1;
        //     }
        //     return *this;
        // };
        int getNumerador() const {
            return numerador;
        }
        int getDenominador() const {
            return denominador;
        }
        void setNumerador(int num) {
            numerador = num;
        }
        void setDonominador(int den) {
            denominador = den;
        }
        double valor() const {
            return static_cast<double>(numerador) / (denominador);
        }
        //Operadores relacionais 
        bool operator<(const Racional& other) const {
            return (numerador * other.denominador) < (other.numerador * denominador);
        }
        bool operator<=(const Racional& other) const {
            return (numerador * other.denominador) <= (other.numerador * denominador);
        }
        bool operator>(const Racional& other) const {
            return (numerador * other.denominador) > (other.numerador * denominador);
        }
        bool operator>=(const Racional& other) const {
            return (numerador * other.denominador) >= (other.numerador * denominador);
        } 
        bool operator==(const Racional& other) const {
            return (numerador * other.denominador) == (other.numerador * denominador);
        }
        //operadores aritméticos
        Racional operator+(const Racional& other) const {
            int novoNumerador = (numerador * other.denominador) + (other.numerador * denominador);
            int novoDenominador = denominador * other.denominador;
            return Racional(novoNumerador, novoDenominador);
        }
        Racional operator-(const Racional& other) const {
            int novoNumerador = (numerador * other.denominador) - (other.numerador * denominador);
            int novoDenominador = denominador * other.denominador;
            return Racional(novoNumerador, novoDenominador);
        }
        Racional operator*(const Racional& other) const {
            int novoNumerador = numerador * other.denominador;
            int novoDenominador = denominador * other.denominador;
            return Racional(novoNumerador, novoDenominador);
        }
        Racional operator/(const Racional& other) const {
            int novoNumerador = numerador * other.denominador;
            int novoDenominador = denominador * other.denominador;
            return Racional(novoNumerador, novoDenominador);
        }
        Racional& operator+=(const Racional& other) {
            numerador = (numerador * other.denominador) + (other.numerador * denominador);
            denominador = denominador * other.denominador;
            return *this;
        }
        Racional& operator-=(const Racional& other) {
            numerador = (numerador * other.denominador) - (other.numerador * denominador);
            denominador = denominador * other.denominador;
            return *this;
        }
        Racional& operator*=(const Racional& other) {
            numerador *= other.denominador;
            return *this;
        }
        Racional& operator/=(const Racional& other) {
            numerador /= other.denominador;
            return *this;
        };
};

#endif
