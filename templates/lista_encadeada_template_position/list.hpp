#ifndef LIST_H
#define LIST_H

// recebe nó de uma classe em outro arquivo
#include "no.hpp"

template <typename T>
class LinkedList {
    public:
        // inicia cabeça da lista com nulo
        Node<T>* head;
        LinkedList() {
            head = nullptr;
        }
        
        // adiciona número na lista
        void add(T val) {
            Node<T>* newNode = new Node<T>(val);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        // adiciona número na lista idx
        void addIdx(T val, int idx) {
            Node<T>* newNode = new Node<T>(val);
            int count = 0;
            if (head == nullptr) {
                head = newNode;
                return;
            }

            Node<T>* current = head;
            if(idx == 0){
                newNode->next = current;
                head = newNode;
                return;
            }

            while (current->next != nullptr) {
                count++; if(count == idx) break;
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        // remove elemento da lista
        void remove(T val) {
            int count = 0;
            if (head == nullptr) 
                return;
                
            if (head->value == val) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node<T>* current = head;
            while (current->next != nullptr) {
                if (current->next->value == val) {
                    Node<T>* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }
                current = current->next;
            }
        }

        // remove elemento da lista com index
        void removeIdx(int idx) {
            cout<<"index: "<<idx<<endl;
            int count = 0;
            if (head == nullptr) 
                return;

            if (idx == 0) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node<T>* current = head;
            while (current != nullptr) {
                cout<<count<<endl;
                if(count == idx-1){
                    cout<<"Remove: "<<current->next->value<<endl;
                    Node<T>* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }else{
                    count++;
                    current = current->next;
                }
            }
        }

        // mostra elementos da lista encadeada 
        void print() {
            Node<T>* current = head;
            while (current != nullptr) {
                cout << current->value << " ";
                current = current->next;
            }
            cout << endl;
        }
};

#endif