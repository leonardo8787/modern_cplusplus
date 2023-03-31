#include "list.hpp"
#include "no.hpp"

int main(int argc, char** argv) {
    // LinkedList<int> list;
    // LinkedList<double> list2;
    // LinkedList<char> list3;
    // LinkedList<float> list4;
    LinkedList<string> list5;
    int aux=1;
    do{
        cout<<"---Menu---"<<endl;
        cout<<"1-adicionar"<<endl;
        cout<<"2-remover"<<endl;
        cout<<"3-printar"<<endl;
        cout<<"4-limpar"<<endl;
        cout<<"0-sair"<<endl;
        int op; cin>>op;
        switch (op)
        {
            case 0:
                cout<<"Saindo..."<<endl;
                aux=0;
                break;
            case 1:
                cout<<"Foi colocado pré valores para que não fosse necessário fazer um menú muito grande!"<<endl;
                list5.add("12");
                list5.add("13");
                list5.add("14");
                list5.add("15");
                list5.add("16");
                list5.addIdx("1100", 0);
                // list2.add(3.14);
                // list3.add('a');
                // list4.add(38.777);
                // list5.add("leonardo bonitao");
                break;
            case 2:
                cout<<"Foi colocado pré valores para que não fosse necessário fazer um menú muito grande!"<<endl;
                // list5.remove("leonardo bonitao");
                list5.removeIdx(0);
                break;
            case 3:
                cout<<"Lista: ";
                list5.print();
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
