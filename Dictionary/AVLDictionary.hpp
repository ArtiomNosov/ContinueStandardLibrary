//
//  AVLDictionary.hpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 09.11.2021.
//

#ifndef AVLDictionary_hpp
#define AVLDictionary_hpp

#include <stdio.h>
#include "Pair.hpp"
#include "BinaryTree.hpp"
#include "Dictionary.hpp"

template<typename K, typename V>
class AVLDictionary: public Dictionary<K, V>{
private:
    unsigned int size = 0;
    BinaryTree<Pair<K, V>>* tree = new BinaryTree<Pair<K, V>>();
public:
    AVLDictionary() = default;
    AVLDictionary(const K& input_key, const V& input_value){
        size = 1;
        tree->Add(Pair<K, V>(input_key, input_value));
    }
    
    void add(const K& input_key, const V& input_value){
        if (not this->keyExist(input_key)){
            size += 1;
            tree->add(Pair<K, V>(input_key, input_value));
            return;
        }
        throw std::invalid_argument("Key already exist");
    }
    
    V getValue(const K& input_key){
        if (this->tree->exist(Pair<K, V>(input_key))){
            return this->tree->getData(Pair<K, V>(input_key)).getSecond();
        }
        else throw std::invalid_argument("Missing key");
    }
    
    Pair<K, V> getPair(const K& input_key){
        if (tree->exist(Pair<K, V>(input_key))){
            return tree->getData(Pair<K, V>(input_key));
    
        }
        else throw std::invalid_argument("Missing key");
    }
    
    int getSize(){
        return this->size;
    }
    
    bool keyExist(const K& input_key){
            return tree->exist(Pair<K, V>(input_key));
    }
    
    void remove(const K& input_key){
        if (this->tree->exist(input_key)){
            tree->remove(Pair<K, V>(input_key));
            size -= 1;
        }
    }
    
    
    ~AVLDictionary(){
        delete this->tree;
        size = NULL;
    }
};


#endif /* AVLDictionary_hpp */
