//
//  Dictionary.hpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 15.11.2021.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include "Pair.hpp"

template <class K, class V>
class Dictionary {
public:
    Dictionary(){};
    Dictionary(const K& key, const V& value){};
    
    virtual void add(const K& input_key, const V& input_value) = 0;
    virtual Pair<K, V> getPair(const K& input_key) = 0;
    virtual int getSize() = 0;
    virtual bool keyExist(const K& input_key) = 0;
    virtual void remove(const K& input_key) = 0;
    virtual V getValue(const K& input_key) = 0;
    
    ~Dictionary(){};
};
#endif /* Dictionary_hpp */
