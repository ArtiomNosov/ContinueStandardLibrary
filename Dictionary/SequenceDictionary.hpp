//
//  SequenceDictionary.hpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 11.11.2021.
//

#ifndef SequenceDictionary_hpp
#define SequenceDictionary_hpp

#include <stdio.h>
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Pair.hpp"
#include <iostream>
#include "Dictionary.hpp"

template<typename K, typename V>
class SequenceDictionary: public Dictionary<K, V>{
private:
    unsigned int size = 0;
    std::string sequence;
    Sequence<Pair<K, V>>* seq;
public:
    SequenceDictionary(){
        size = 0;
        sequence = "Dynamic Array";
        seq = new ArraySequence<Pair<K, V>>();
    }
    
    SequenceDictionary(std::string sequence_type){
        size = 0;
        sequence = sequence_type;
        if (sequence_type == "Dynamic Array"){
            seq = new ArraySequence<Pair<K, V>>();
        }
        else if (sequence_type == "Linked List"){
            seq = new ListSequence<Pair<K, V>>();
        }
        else throw std::invalid_argument("Invalid name of sequence!");
    }
    
    SequenceDictionary(const K& input_key, const V& input_value, std::string sequence_type = "Dynamic Array"){
        size = 1;
        sequence = sequence_type;
        if (sequence_type == "Dynamic Array"){
            seq = new ArraySequence<Pair<K, V>>();
        }
        else if (sequence_type == "Linked List"){
            seq = new LinkedList<Pair<K, V>>();
        }
        seq->Append(Pair<K, V>(input_key, input_value));
    }
    
    void add(const K& input_key, const V& input_value){
        if (not this->keyExist(input_key)){
            size += 1;
            seq->Append(Pair<K, V>(input_key, input_value));
            return;
        }
        throw std::invalid_argument("Key already exist");

        
    }
    
    V getValue(const K& input_key){
        if (this->seq->Exist(Pair<K, V>(input_key))){
            return this->seq->GetItem(Pair<K, V>(input_key)).getSecond();
        }
        else throw std::invalid_argument("Missing key");
    }
    
    Pair<K, V> getPair(const K& input_key){
        if (this->seq->Exist(Pair<K, V>(input_key))){
            return this->seq->GetItem(Pair<K, V>(input_key));
        }
        else throw std::invalid_argument("Missing key");
    }
    
    int getSize(){
        return this->size;
    }
    
    bool keyExist(const K& input_key){
        return seq->Exist(Pair<K, V>(input_key));
    }
    
    //bool ContainsValue(const Value& input_value){
    //    return seq->Exist(Pair<Key, Value>(input_value));
    //}
    
    void remove(const K& input_key){
        if (seq->Exist(input_key)){
            seq->Delete(Pair<K, V>(input_key));
            size -= 1;
        }
    }
    
    ~SequenceDictionary(){
        delete this->seq;
        size = NULL;
        sequence = "";
    }
    
};
#endif /* SequenceDictionary_hpp */
