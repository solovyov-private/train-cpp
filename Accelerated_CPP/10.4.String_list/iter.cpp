#include <algorithm>
#include <iostream>

template <typename T>
class StringList
{
    private:
        class Node;

        int sz;
        Node* pHead;
        Node* pTail;

        class Node
        {
            public:
                T value;
                Node* pPrev;
                Node* pNext;

                Node(T value = T(), Node* pPrev = nullptr, Node* pNext = nullptr) 
                {
                    this->value = value;
                    this->pPrev = pPrev;
                    this->pNext = pNext;
                }
        };

    public:
        StringList() { sz = 0; pHead = nullptr; pTail = nullptr; };
        ~StringList() { clear(); };

        void clear() { while(sz) pop_front(); };
        void pop_front();
        void push_back(T l);
        int size() { return sz; }

        T& operator[](const int index);

        class Iterator;
        class ReverseIterator; 

        Iterator begin() { return Iterator(pHead); }
        Iterator end() { return Iterator(pTail); }
        ReverseIterator rbegin() { return ReverseIterator(pTail); }
        ReverseIterator rend() { return ReverseIterator(pHead); }

        class Iterator 
        {
            private:
                Node* pIter;
            public:
                Iterator(Node* tmp) : pIter(tmp) { }
                Iterator(const Iterator& tmp) : pIter(tmp.pIter) {}
                Iterator& operator++ () { pIter = pIter->pNext; return *this; }
                Iterator& operator-- () { pIter = pIter->pPrev; return *this; }
                bool operator!= (Iterator rVal) { return pIter != rVal.pIter->pNext; }
                T& operator* () { return pIter->value; }
        };

        class ReverseIterator 
        {
            private:
                Node* pIter;
            public:
                ReverseIterator(Node* tmp) : pIter(tmp) { }
                ReverseIterator(const ReverseIterator& tmp) : pIter(tmp.pIter) {}
                ReverseIterator& operator++ () { pIter = pIter->pPrev; return *this; }
                ReverseIterator& operator-- () { pIter = pIter->pNext; return *this; }
                bool operator!= (ReverseIterator rVal) { return pIter != rVal.pIter->pPrev; }
                T& operator* () { return pIter->value; }
        };
};

template<typename T>
void StringList<T>::pop_front()
{
    Node* tmp = pHead;
    pHead = pHead->pNext;
    delete tmp;
    sz--;
}

template<typename T>
void StringList<T>::push_back(T l)
{
    if (pHead == nullptr && pTail == nullptr) {
        pHead = new Node(l);
        pTail = pHead;
    } else {
        Node* tmp = this->pHead;
        while (tmp->pNext != nullptr) {
            tmp = tmp->pNext;
        }

        tmp->pNext = new Node(l, tmp);
        pTail = tmp->pNext;
   }

    sz++;
}

template<typename T>
T& StringList<T>::operator[](const int index)
{
    bool moveBackward = 0;
    int cnt = 0;

    Node* tmp = this->pHead;

    if (index / sz > 0.5) {
        // Backward direction
        //
        moveBackward = 1;
        tmp = this->pTail;
    }

    while (tmp != nullptr) {
        if (cnt == index) {
            return tmp->value;
        }

        if (! moveBackward) {
            tmp = tmp->pNext;
            cnt++;
        } else {
            tmp = tmp->pPrev;
            cnt--;

        }
    }
    return tmp->value;
}

int main()
{
    StringList<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);
    lst.push_back(55);

    std::cout << "Initial: " << std::endl;
    for (size_t i = 0; i < lst.size(); ++i) {
        std::cout << lst[i] << std::endl;
    }

    std::cout << "Iterator: " << std::endl;
    for (StringList<int>::Iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "Reverse: " << std::endl;
    for (StringList<int>::ReverseIterator it = lst.rbegin(); it != lst.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}
