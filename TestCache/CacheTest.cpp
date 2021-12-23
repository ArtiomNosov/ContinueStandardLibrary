//
//  CacheTest.cpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 17.12.2021.
//

#include "CacheTest.hpp"

void dcGet(){
    auto* cache = new LRUCache<std::string>(2);
    
    assert(cache->Get("1") == "1");
    assert(cache->Get("2") == "2");
    assert(cache->Get("1") == "1");
    assert(cache->Get("4") == "4");
    assert(cache->Get("1") == "1");
    assert(cache->Get("2") == "2");
    
    delete cache;
}

void dcInCache(){
    auto* cache = new LRUCache<std::string>(2);
    
    assert(cache->inCache("1") == 0);
    cache->Get("1");
    assert(cache->inCache("2") == 0);
    cache->Get("2");
    assert(cache->inCache("1") == 1);
    cache->Get("1");
    assert(cache->inCache("4") == 0);
    cache->Get("4");
    assert(cache->inCache("1") == 1);
    cache->Get("1");
    assert(cache->inCache("2") == 0);
    
    delete cache;
}



void dictionaryCacheTests(){
    std::cout << "DictionaryCache Tests:\n";
    dcGet();
    std::cout << "1)DictionaryCache get test compleated\n";
    dcInCache();
    std::cout << "2)DictionaryCache inCache test compleated\n";
}
