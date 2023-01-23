#ifndef _DLLNode_H_ 
#define _DLLNode_H_

template<class T> 
class DLLNode{

    public: 
    T data; 
    DLLNode<T> *next; //pointer to the next node 
    DLLNode<T> *previous; //pointer to the previous node

    //Constructor function 
    DLLNode(); 
    DLLNode(T value); 
}; 

template<class T> 
DLLNode<T>::DLLNode() : data{}, next{nullptr}{}

template<class T> 
DLLNode<T>::DLLNode(T value){
    data = value; 
    next = nullptr; //pointing to nothing
}


#endif //_DLLNode_H_