//
// Created by nightingale on 3/27/21.
//

#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

#include <ostream>

using std::ostream;

template<typename T>
struct Node
{
    T data;
    Node* ptrNext;
};

template<typename T>
Node<T>* insertNode(Node<T>* ptrBegin, T data)
{
    Node<T>* ptr = new Node<T>;
    ptr->data = data;
    ptr->ptrNext = ptrBegin;
    return ptr;
}

template<typename T>
struct List
{
    Node<T>* begin;
    int size;
};

template<typename T>
void list_init(List<T>& L)
{
    L.begin = nullptr;
    L.size = 0;
}

template<typename T>
void list_insert(List<T>& L, const T& value){
    L.size++;
    L.begin = insertNode(L.begin, value);
}

template<typename T>
void list_print(const List<T>& L, ostream& os)
{
    Node<T>* ptr = L.begin;

    while (ptr) {
        os << ptr->data << '\n';
        ptr = ptr->ptrNext;
    }
}

template<typename T>
void list_destroy(List<T>& L)
{
    Node<T>* ptr = L.begin;
    Node<T>* ptrPrev;

    while (ptr) {
        ptrPrev = ptr;
        ptr = ptr->ptrNext;
        delete ptrPrev;
    }
    L.size = 0;
    L.begin = nullptr;
}



#endif //LIST_NODE_HPP
