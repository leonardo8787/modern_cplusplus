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

        // remove elemento da lista
        void remove(T val) {
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