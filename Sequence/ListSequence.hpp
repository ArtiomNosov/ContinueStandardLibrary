#ifndef LinkSequence_hpp
#define LinkSequence_hpp

#include "LinkedList.hpp"
#include "Sequence.hpp"

template <typename T>
class ListSequence: public Sequence<T>{
private:
    LinkedList<T>* listSequence;
public:
    //Constructor
    ListSequence(){
        listSequence = new LinkedList<T>();
    };
    ListSequence(T* items, int count){
        listSequence = new LinkedList<T>(items, count);
    };
    ListSequence(LinkedList<T>& list){
        listSequence = LinkedList<T>(list);
    }
    ListSequence(LinkedList<T>* list){
        listSequence = list;
    };
    ListSequence(ListSequence<T>* list){
        listSequence = list->listSequence;
    }

    //Destructor
    ~ListSequence(){
        listSequence->Delete_LinkedList();
    }
    void Delete_LinkedListSequence(){
        listSequence->Delete_LinkedList();
    }
    //Decomposition
     T GetFirst() override{
        return listSequence->GetFirst();
    };//get el on first index
     T GetLast() override{
         return listSequence->GetLast();
     };//get el on last index
     T Get(int index) override{
         return listSequence->Get(index);
     };//get index of Node
     ListSequence<T>* GetSubsequence(int startIndex, int endIndex) override{
         LinkedList<T>* list;
         list = this->listSequence->GetSublist(startIndex, endIndex);
         auto* list_sequence = new ListSequence<T>(list);
         return list_sequence;
     };//get list of el
     int GetLength() override{
         return listSequence->GetLength();
     };// Length


    //Operations
     void Append(T item) override{
         listSequence->Append(item);
     }; //add el at end
     void Prepend(T item) override{
         listSequence->Prepend(item);
     }; //add el at head
     void Set(T item, int index) override{
         listSequence->Set(item, index);
     }; // add el at index (replace)
     void InsertAt(T item, int index) override{
         listSequence->InsertAt(item, index);
     }; //add el at index
     ListSequence<T>* Concat(Sequence<T>* list) override{
         auto *new_LinkedList = new ListSequence<T>(listSequence);
         for (int i = 0; i < list->GetLength(); i++){
             new_LinkedList->Append(list->Get(i));
         }
         return new_LinkedList;
     }; //concat two sequence
    //operators
     T operator[] (int index) override{
        return listSequence->Get(index);
     };
    
    ListSequence<T>* Copy(Sequence<T> *list) override{
        auto* new_ListSequence = new ListSequence();
        for (int i = 0; i < list->GetLength(); i++){
            new_ListSequence->Append(list->Get(i));
        }
        return new_ListSequence;
    };
    
    bool Exist(T item) override{
        return listSequence->Exist(item);
    }
    
    T GetItem(T item) override{
        return listSequence->GetItem(item);
    }
    
    void Delete(T item) override{
        listSequence->Delete(item);
    }
};
#endif /* LinkSequence_hpp */
