#include "list.hpp"
#include "no.hpp"

int main(int argc, char** argv) {
    LinkedList list;
    int aux=1;
    do{
        cout<<"---Menu---"<<endl;
        cout<<"1-adicionar"<<endl;
        cout<<"2-remover"<<endl;
        cout<<"3-printar"<<endl;
        cout<<"4-limpar"<<endl;
        cout<<"0-sair"<<endl;
        int op; cin>>op;
        int num;
        switch (op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
                aux=0;
                break;
            case 1:
                cout<<"Digite um número: ";
                cin>>num;
                list.add(num);
                break;
            case 2:
                cout<<"Digite um número: ";
                cin>>num;
                list.remove(num);
                break;
            case 3:
                cout<<"Lista: ";
                list.print();
                break;
            case 4:
                system("cls");
                break;
            default:
                break;
        }
    }while(aux!=0);
    return 0;
}
