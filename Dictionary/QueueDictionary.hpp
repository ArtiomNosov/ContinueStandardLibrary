//
//  QueueDictionary.hpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 15.11.2021.
//

#ifndef QueueDictionary_hpp
#define QueueDictionary_hpp

#include <stdio.h>
#include "Dictionary.hpp"
#include "AVLDictionary.hpp"
#include <iostream>
#include <vector>
#include "Pair.hpp"
#include "SequenceDictionary.hpp"


template<class K, class V>
class QueueDictionary{
private:
    Dictionary<K, V>* dict;
    std::vector<K>* vector = new std::vector<K>();
public:
    //QueueDictionary(){
    //    dict = new AVLDictionary<K, V>();
    //}
    
    QueueDictionary(std::string dictionary_type = "AVL", std::string sequence_type = "Dynamic Array"){
        if (dictionary_type == "AVL"){
            dict = new AVLDictionary<K, V>();
        }
        else if (dictionary_type == "Sequence"){
            if (sequence_type == "Dynamic Array"){
                dict = new SequenceDictionary<K, V>();
            }
            else if (sequence_type == "Linked List"){
                dict = new SequenceDictionary<K, V>("Linked List");
            }
            else throw std::invalid_argument("Invalid name of Sequence!");
        }
        else throw std::invalid_argument("Invalid name of Dictionary!");
    }
    
    void push(const K& input_key, const V& input_value){
        dict->add(input_key, input_value);
        vector->push_back(input_key);
    }
    
    void Delete(const K& input_key){
        if (dict->keyExist(input_key)){
            vector->erase(std::find(vector->begin(), vector->end(), input_key));
            dict->remove(input_key);
        }
        else throw std::out_of_range("Incorrect key!");
    }
    
    void pop(){
        if (vector->size() != 0){
            dict->remove(vector->at(0));
            vector->erase(vector->begin());
        }
    }
    
    bool keyExist(const K& input_key){
        if (dict->keyExist(input_key)){
            return 1;
        }
        return 0;
    }
    
    size_t getSize(){
        return vector->size();
    }
    
    V getLastValue(){
        if (vector->size() != 0){
            return dict->getValue(vector->at(0));
        }
        else throw std::out_of_range("Incorrect key!");
    }
    
    K getLastKey(){
        if (vector->size() != 0){
            return vector->at(0);
        }
        else throw std::out_of_range("Incorrect key!");
    }
    
    V getValue(const K& key){
        return dict->getValue(key);
    }
    
    void liftUp(const K& key){
        vector->erase(std::find(vector->begin(), vector->end(), key));
        vector->push_back(key);
    }

    
        
};

#endif /* QueueDictionary_hpp */
