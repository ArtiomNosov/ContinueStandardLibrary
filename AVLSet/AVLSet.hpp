//
//  AVLSet.hpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 10.12.2021.
//

#ifndef AVLSet_hpp
#define AVLSet_hpp

#include <stdio.h>
#include "BinaryTree.hpp"

template<typename T>
class AVLSet{
private:
    BinaryTree<T>* tree = new BinaryTree<T>();
    int size = 0;
public:
    
    AVLSet() = default;
    
    void Add(const T& data){
        if (not this->tree->exist(data)){
            this->tree->add(data);
            size += 1;
        }
    }
    
    void Remove(const T& data){
        if (this->tree->Exist(data)){
            tree->Delete(data);
            size -= 1;
        }
    }
    
    int GetCount(){
        return this->size;
    }
    
    T Get(int index){
        return this->tree->getOnIndex(index);
    }
    
    bool IsEmpty(){
        return this->GetCount() == 0;
    }
    
    bool HasElement(const T& element){
        return tree->Exist(element);
    }
    
    AVLSet<T>* Union(AVLSet<T>* set){
        auto* res = tree->UnionTree(set->tree);
        res->size = res->tree->GetCountNodes();
        return res;
    }
    
    AVLSet<T>* Intersec(AVLSet<T>* set){
        AVLSet<T>* res = new AVLSet<T>();
        res->tree = this->tree->IntersecTree(set->tree);
        res->size = res->tree->GetCountNodes();
        return res;
    }
    
    AVLSet<T>* Except(AVLSet<T>* set){
        AVLSet<T>* res = new AVLSet<T>();
        res->tree = this->tree->Except(set->tree);
        res->size = res->tree->GetCountNodes();
        return res;
    }
    
    
    ~AVLSet(){
        delete tree;
        size = NULL;
    }
};



#endif /* AVLSet_hpp */
