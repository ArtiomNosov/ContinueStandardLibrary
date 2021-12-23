//
//  Cache.hpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 15.11.2021.
//

#ifndef Cache_hpp
#define Cache_hpp

#include <stdio.h>
#include <iostream>
// #include "QueueDictionary/QueueDictionary.hpp"
// #include "AVLDictionary/AVLDictionary.hpp"
// #include "AVLSet/AVLSet.hpp"
// #include "SequenceDictionary/SequenceDictionary.hpp"






template<class V>
class LRUCache
{
private:
    //associates each value with its own id
    Dictionary<V, int>* id_dict;
    QueueDictionary<int, V>* main_dict;
    int MaxSize;
    
    void add2MainDict(const V& value){
        if (main_dict->getSize() < MaxSize){
            AVLSet<V>* set = new AVLSet<V>();
            set->Add(value);
            id_dict = CalcIndexesForDictionary(set, id_dict, main_dict);
            int key = id_dict->getValue(value);
            //id_dict->Add(value, key);
            main_dict->push(key, value);
            return;
        }
        V begin_value = main_dict->getLastValue();
        
        id_dict->remove(begin_value);
        main_dict->pop();
        
        AVLSet<V>* set = new AVLSet<V>();
        set->Add(value);
        id_dict = CalcIndexesForDictionary(set, id_dict, main_dict);
        int key = id_dict->getValue(value);
        main_dict->push(key, value);
    };
    
    void update2MainDict(int& key){
        V value = main_dict->getValue(key);
        main_dict->liftUp(key);
    }
    
    
    Dictionary<V, int>* CalcIndexesForDictionary(AVLSet<V>* set, Dictionary<V, int>* dict, QueueDictionary<int, V>* qdict){
        int index = 0;
        int position = 0;
        while (index < set->GetCount()){
            if (qdict->keyExist(position)){
                position++;
            }
            else{
                dict->add(set->Get(index), position);
                position++;
                index++;
            }
        }
        return dict;
    }
    
    
public:
    LRUCache(int maxSize, std::string dictionary_type = "AVL", std::string sequence_type = "Dynamic Array")
        {
        /*
         maxSize: Max size of cache
         dictionary_type: type of dictionary (AVL or Sequence)
         sequense_type: type of sequence (Linked List of Dynamic Array)
         */
        
        if (maxSize < 1) {
            throw new std::out_of_range("maxSize < 1");
        }
        
        main_dict = new QueueDictionary<int, V>(dictionary_type, sequence_type);
        MaxSize = maxSize;
        
        if (dictionary_type == "AVL"){
            id_dict = new AVLDictionary<V, int>();
        }
        else if (dictionary_type == "Sequence"){
            if (sequence_type == "Dynamic Array"){
                id_dict = new SequenceDictionary<V, int>("Dynamic Array");
            }
            else if (sequence_type == "Linked List"){
                id_dict = new SequenceDictionary<V, int>("Linked List");
            }
            else throw std::invalid_argument("Invalid name of Sequence!");
        }
        else throw std::invalid_argument("Invalid name of Dictionary!");
                
    }
    
    V Get(const V& value){
        
        if (id_dict->keyExist(value)){
            int key = id_dict->getValue(value);
            update2MainDict(key);
            return main_dict->getValue(key);
        }
        
        //Request!
        add2MainDict(value);
        return main_dict->getValue(id_dict->getValue(value));
    }
    
    QueueDictionary<int, V>* GetCache(){
        return main_dict;
    }
    
    bool inCache(const V& value){
        if (id_dict->keyExist(value)){
            return 1;
        }
        else return 0;
    }
};

#endif /* Cache_hpp */
