#include "url.hpp"

int main() {
    // Criando um objeto URL a partir de uma string literal usando o operador de sufixo
    // URL url = "https://cefetplusplus.github.io/"_url;
    URL url = "https://www.cefetmg.br:443/"_url;
    // URL url = "https://cefetplusplus.github.io/"_url;
    
    // Imprimindo os componentes da URL
    cout << "Esquema: " << url.get_esquema() << endl;
    cout << "Domínio: " << url.get_dominio() << endl;
    cout << "Porta: " << url.get_porta() << endl;
    cout << "Caminho: " << url.get_caminho() << endl;
    
    return 0;
}
