#ifndef url_h_
#define url_h_

#include<bits/stdc++.h>
using namespace std;

class URL {
    private:
        string _dominio;
        string _esquema;
        int _porta;
        string _caminho;

    public:
        URL() : _esquema(""), _dominio(""), _porta(0), _caminho("") {}

        URL(const string& esquema, const string& dominio, int porta, const string& caminho)
            : _esquema(esquema), _dominio(dominio), _porta(porta), _caminho(caminho) {}

        URL(const URL& outraURL)
            : _esquema(outraURL._esquema), _dominio(outraURL._dominio), _porta(outraURL._porta), _caminho(outraURL._caminho) {}
        
        string getEsquema()
            return _esquema;

        void setEsquema(string esquema)
            _esquema = esquema;

        string getDominio()
            return _dominio;

        void setDominio(string dominio)
            _dominio = dominio;

        int getPorta()
            return _porta;

        void setPorta(int porta)
            _porta = porta;

        string getCaminho()
            return _caminho;

        void setCaminho(string caminho)
            _caminho = caminho;
};

#endif 