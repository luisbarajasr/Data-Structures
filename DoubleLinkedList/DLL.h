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
    bool deleteAt(int position); 
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
        cout<< temporalPtr->data<< " "; 
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
        newDLLNode-> next= head; 
        head->previous = newDLLNode; 
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
      newDLLNode->previous = tail; 
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

template<class T> 
bool DLL<T>::deleteAt(int position){

    bool state = false; 

    if(position < 0 || position >= numElements){   
        throw out_of_range("Index out of range"); 
    }
    else if( position == 0){

        DLLNode<T> *temporal = head; 

        //if DLL contains just one node
        if(head != nullptr && head->next == nullptr){
            head = nullptr; 
            tail = nullptr; 
        }
        else{
            head = temporal->next; 
            head->previous = nullptr; 
        }
        delete temporal; 
        numElements--; 
        state = true; 
        return state; 
    }
    else { //is position > 0

        DLLNode<T> *temporal = head; 
        DLLNode<T> *temporal2 = nullptr; 

        int index = 0;

        while( index != position){ //keep looking por the index 

            temporal2 = temporal; 
            temporal = temporal->next; 
            index++; 
        }

        if( temporal->next == nullptr){
            temporal2->next = nullptr; 
            tail = temporal2; 
        }
        else{
            temporal2->next = temporal->next; 
            temporal->next->previous = temporal2; 
        }

        delete temporal; 
        numElements--; 
        state = true; 
        return state; 
    }
}

template<class T> 
T DLL<T>::getData(int position){
    
    if(position < 0 || position >= numElements){
        throw out_of_range("Index out of range"); 
    }
    else{

        if(position == 0){
            return head->data; 
        }
        
        DLLNode<T> *temporal = head; 
        int index = 0; 

        while(index != position){

            if(index == position){
                return temporal->data; 
            }
            index++; 
            temporal = temporal->next; 
        }

        return -1; 
    }
}

template<class T> 
void DLL<T>:: updateData(T value, T newValue){

    DLLNode<T> *temporal = head; 

    while(temporal != nullptr){

        if(temporal->data == value){
            temporal->data = newValue; 
            break; 
        }
        temporal = temporal->next; 
    }

    if(temporal == nullptr){
        throw out_of_range("No value found.");
    }
}



#endif //DLL_H_