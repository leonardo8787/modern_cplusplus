#ifndef LIST_H
#define LIST_H

// recebe nó de uma classe em outro arquivo
#include "no.hpp"

class LinkedList {
    public:
        // inicia cabeça da lista com nulo
        Node* head;
        LinkedList() {
            head = nullptr;
        }

        // adiciona número na lista
        template <typename T> void add(T val) {
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        // remove elemento da lista
        template <typename T> void remove(T val) {
            if (head == nullptr) 
                return;
                
            if (head->value == val) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node* current = head;
            while (current->next != nullptr) {
                if (current->next->value == val) {
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }
                current = current->next;
            }
        }

        // mostra elementos da lista encadeada 
        void print() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->value << " ";
                current = current->next;
            }
            cout << endl;
        }
};

#endif