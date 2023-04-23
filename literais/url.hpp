#ifndef URL_H
#define URL_H

#include <iostream>
#include <string>

using namespace std;

class URL {
    private:
        string esquema;
        string dominio;
        int porta;
        string caminho;
    public:
        std::string url_;
        URL() : esquema(""), dominio(""), porta(0), caminho("") {}
        URL(string esquema, string dominio, int porta, string caminho) : 
            esquema(esquema), dominio(dominio), porta(porta), caminho(caminho) {}
        URL(const URL& other);
        
        string get_esquema() { return esquema; }
        void set_esquema(string esquema) { this->esquema = esquema; }
        
        string get_dominio() { return dominio; }
        void set_dominio(string dominio) { this->dominio = dominio; }
        
        int get_porta() { return porta; }
        void set_porta(int porta) { this->porta = porta; }
        
        string get_caminho() { return caminho; }
        void set_caminho(string caminho) { this->caminho = caminho; }
};

// Sobrecarga do operador de sufixo
URL operator""_url(const char* str, long unsigned int size) {
    string url_str(str, size);
    // Separando os componentes da URL
    string esquema = "", dominio = "", caminho = "";
    int porta = 0;
    
    size_t pos = url_str.find("://");
    if (pos != string::npos) {
        esquema = url_str.substr(0, pos);
        url_str.erase(0, pos + 3);
    }
    
    pos = url_str.find("/");
    if (pos != string::npos) {
        dominio = url_str.substr(0, pos);
        caminho = url_str.substr(pos);
    } else {
        dominio = url_str;
    }
    
    pos = dominio.find(":");
    if (pos != string::npos) {
        porta = stoi(dominio.substr(pos + 1));
        dominio.erase(pos);
    }
    
    return URL(esquema, dominio, porta, caminho);
}

#endif