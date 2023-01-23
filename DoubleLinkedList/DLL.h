#ifndef _DLL_H_
#define _DLL_H_

#include "DLLNode.h"
#include <iostream> 
using namespace std; 

template<class T> 
class DLL{
    private: 
    DLLNode<T> *head; //pointer to point the FISRT node in the list
    DLLNode<T> *tail; //pointer to point the LAST node in the list 
    int numElements; 

    public: 
    DLL(); 
    ~DLL(); 
    int getNumElements(); 
    void printList(); 
    void addFirst(T value); 
    void addLast(T value); 
    bool deleteData(T value); 
    bool deleteAt(T value); 
    T getData(int position); 
    void updateData(T value, T newValue); 

}; 

template<class T> 
DLL<T>::DLL(){
    head = nullptr; 
    tail = nullptr; 
    numElements = 0; 
}

template<class T> 
DLL<T>:: ~DLL(){
    DLLNode<T> *previuos, *moving; 
    previuos = head; 

    while( previuos != nullptr ){
        moving = previuos->next; 
        delete previuos; 
        previuos = moving; 
    }

    head = nullptr; 
    tail = nullptr; 
    numElements = 0; 
}

template<class T> 
int DLL<T>::getNumElements(){
    return numElements; 
}

template<class T> 
void DLL<T>::printList(){
    DLLNode<T> *temporalPtr = head; 

    while( temporalPtr != nullptr ){
        cout<< temporalPtr->value<< " "; 
        temporalPtr = temporalPtr->next; 
    }
    cout<<endl; 
}

template<class T> 
void DLL<T>::addFirst(T value){
    DLLNode<T> *newDLLNode = new DLLNode<T>(value); 

    if(numElements == 0){
        head = tail = newDLLNode; 
    }
    else{
        newDLLNode-> = head; 
        head->prev = newDLLNode; 
        head = newDLLNode; 
    }
    numElements++; 
}

template<class T> 
void DLL<T>::addLast(T value){

    //DLL<T> *newDLLNode = new DLLNode<T>(value); 

    if( numElements == 0){
        addFirst(value); 
    }
    else{
      DLLNode<T> *newDLLNode = new DLLNode<T>(value); 
      tail->next = newDLLNode; 
      newDLLNode->prev = tail; 
      tail = newDLLNode;   
    }
    numElements++; 
}

template<class T> 
bool DLL<T>::deleteData(T value){

    bool state = false; 

    if(numElements == 0){
        return state; 
    }
    else{
        DLLNode<T> *temporal = head; 
        DLLNode<T> *prev = nullptr; 

        while( temporal != nullptr && temporal->data != value){
            prev = temporal; 
            temporal = temporal->next; 
        }

        if(temporal == nullptr){
            return state; 
        }

        //If the element to delete is the head
        if(temporal == head){
            head = head->next; 

            if(head != nullptr){
                head->previous = nullptr; 
            }
        }
        else if(temporal->next == nullptr){
            prev->next = nullptr; 
            tail = prev; 
        }
        else{
            prev->next = temporal->next; 
            temporal->next->previous = temporal->previous; 
        }

        delete temporal; 
        numElements--;
        state = true; 
        return state; 
    }
}



#endif //DLL_H_