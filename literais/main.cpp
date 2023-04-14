#include "url.hpp"

int main(){
    URL palavra;
    
    palavra.setEsquema("https");
    palavra.setDominio("www.google.com");
    palavra.setPorta(80);
    palavra.setCaminho("/search?q=url");

    cout<<"Minha URL: "<<palavra.getEsquema()<<"://"<<palavra.getDominio();
    
    if (palavra.getPorta() != 0) 
        cout<<":"<<palavra.getPorta();
    
    cout<<palavra.getCaminho()<<endl;

    return 0;
}