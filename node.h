#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    int count;
      
    Node(T data) : data(data) {
        next = nullptr;
        count = 0;
    }
      
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    //cout << "Kill " << this->data << '\n';
    if (next) {
        next->killSelf();
    }
    //cout << "deleting " << this->data << '\n';
    delete this;
}

#endif