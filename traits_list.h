#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;

        bool find(T data, Node<T> **&pointer) {
            pointer = &(this->head);
            //Node<T>* actual = this->head;
            // Aquí podrías cambiar un poco las condiciones para tener el return false fuera y evitar warnings
            while(*pointer) {
                if ((*pointer)->data == data) {
                    return true;
                }
                if(!cmp((*pointer)->data, data)){
                    return false;
                }
                pointer = &((*pointer)->next);
            }
        }
              
    public:
        TraitsList() : head(nullptr) {};
             
        bool insert(T data) {
            Node<T> **temp = nullptr;
            if(!find(data, temp)){
                Node<T> *nuevo_nodo = new Node<T>(data);
                nuevo_nodo->next = *temp;
                *temp = nuevo_nodo;
            }
        }
             
        bool remove(T data) {
            Node<T> **temp = nullptr;
            if(find(data, temp)){
                Node<T> *del_node = *temp;
                *temp = (*temp)->next;
                delete del_node;
                return true;
            }
            return false;
        }  

        bool find(T data) {
            Node<T> **temp = nullptr;
            return find(data, temp);
        }

        T operator [] (int index) {
            if(index < 0 || index >= size()){
                throw out_of_range("Error bro! index out of range!" );
            }
            Node<T>* temp_node = this->head;
            int i=0;
            while(true){
                if(i == index){
                    return temp_node->data;
                }
                i++;
                temp_node = temp_node->next;
            }
        }
             
        int size() {
            int nodes = 0;
            Node<T>* actual = this->head;
            while(actual){
                nodes++;
                actual = actual->next;
            }
            return nodes;
        }

        void print() {
            if(size() == 0) return;
            Node<T>* actual = this->head;
            while(actual){
                cout << actual->data << " ";
                actual = actual->next;
            }
            cout << "\n";
        }

        ~TraitsList() {
            if(size()){
                //cout << "Calling Destructor for Trait_List - Destructor execution \n";
                this->head->killSelf();
                this->head = nullptr;
            }
        }         
};

#endif