#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;

    public:
        SelfList(Method method) : head(nullptr), method(method) {};

        void insert(T data) {
            if(this->head == nullptr){
                Node<T>* temp = new Node<T>(data);
                this->head = temp;
            }
            else{
                Node<T>* temp = new Node<T>(data);
                temp->next = this->head;
                this->head = temp;
            }
        }
             
        bool remove(T data) {
            if(this->head == nullptr) return false;
            Node<T>* actual = this->head;
            Node<T>* node_remove = nullptr;
            // Para qué sacaste esta condición del bucle? Podrías tener todo junto
            if(actual->data == data){
                this->head = actual->next;
                delete actual;
                return true;
            }
            while(actual){
                //cout << "Estoy en: " << actual->data << '\n';
                if(actual->next->data == data){
                    //cout << "found " << data << " next to " << actual->data << " \n";
                    node_remove = actual->next;
                    actual->next = actual->next->next;
                    delete node_remove;
                    //delete actual->next;      // bug line
                    return true;
                }
                actual = actual->next;
            }
            return false;
        }  

        bool find(T data) {
            // Podrías haber sacado los métodos como funciones
            // Podrías ahorrar muchas líneas con un find tipo la lista de traits con puntero doble
            if(this->method == Move){
                //cout << "Start method 'Move' finding \n";
                if(this->head == nullptr) return false;
                Node<T>* actual = this->head;
                Node<T>* node_cp = nullptr;
                if(actual->data == data){
                    // Aquí no estás moviendo al frente, si encuentras el elemento retornas true
                    return true;
                }
                while(actual){
                    if(actual->next->data == data){
                        node_cp = actual->next;
                        actual->next = actual->next->next;
                        node_cp->next = this->head;
                        this->head = node_cp;
                        return true;
                    }
                    actual = actual->next;
                }
                return false;
            }
            else if(this->method == Count){
                //cout << "Start method 'Count' finding \n";
                if(this->head == nullptr) return false;
                Node<T>* actual = this->head;
                Node<T>* prev_node_found = nullptr;  //pointer to the prev_node when find data
                while(actual != nullptr){
                    if(actual->data == data){   //if you find the data
                        actual->count++;
                        if(actual != this->head){       // if it is not already the head do the following
                            //Start searching the new place for the node
                            Node<T>* itera_node = this->head;
                            Node<T>* prev_at_new_place = nullptr;
                            while(actual->count < itera_node->count){   //if true -> continue forward
                                prev_at_new_place = itera_node;
                                itera_node = itera_node->next;
                            }
                            if(actual != itera_node){   //if the place is different than current place (new place)
                                prev_node_found->next = actual->next;
                                actual->next = itera_node;
                            }
                            if(itera_node == this->head){   // if actual is as first element
                                this->head = actual;
                            }
                            else{
                                prev_at_new_place->next = actual;
                            }
                        }
                        return true;
                    }
                    prev_node_found = actual;
                    actual = actual->next;
                }
                return false;
            }
            else if(this->method == Transpose){
                //cout << "Start method 'Transpose' finding \n";
                if(this->head == nullptr) return false;
                Node<T>* actual = this->head;
                Node<T>* prev_node_found = nullptr;  //pointer to the prev_node which actually find data
                if(actual->data == data) return true;   // if data is on head return true
                Node<T>* temp_node = nullptr;
                while(actual != nullptr){
                    if(actual->next == nullptr) break;      // if is the last element break
                    //cout << "Check: " << actual->next->data << " vs " << data << '\n';
                    if(actual->next->data == data){   // found it
                        cout << "found! \n";
                        if(actual != this->head){
                            prev_node_found->next = actual->next;   //ok
                            temp_node = actual->next;     //backup pointer-node data
                            actual->next = actual->next->next;  //ok
                            temp_node->next = actual;
                            return true;
                        }
                        else{
                            temp_node = actual->next;
                            actual->next = actual->next->next;
                            temp_node->next = actual;
                            this->head = temp_node;
                            return true;
                        }
                    }
                    prev_node_found = actual;
                    actual = actual->next;
                }
                cout << "Result: not found \n";
                return false;
            }
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

        ~SelfList() {
            if(size()){
                cout << "Calling Destructor - Destructor execution \n";
                this->head->killSelf();
                this->head = nullptr;
            }
        }
};

#endif