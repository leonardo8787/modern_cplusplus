#include "copyAndSwat.hpp"

int main() {
    Pessoa pessoa1("Leonardo", 21);
    Pessoa pessoa2(pessoa1);

    cout<<"Pessoa 2: Nome - "<<pessoa2.getNome()<<", Idade - "<<pessoa2.getIdade()<<endl;

    Pessoa pessoa3("Bob", 30);
    pessoa3.swapFunc(pessoa2);

    cout<<"Pessoa 2 (depois swap): Nome - "<<pessoa2.getNome()<<", Idade - "<<pessoa2.getIdade()<<endl;
    cout<<"Pessoa 3 (depois swap): Nome - "<<pessoa3.getNome()<<", Idade - "<<pessoa3.getIdade()<<endl;

    return 0;
}
