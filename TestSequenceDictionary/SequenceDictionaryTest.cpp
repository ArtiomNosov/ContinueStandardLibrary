//
//  SequenceDictionaryTest.cpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 16.12.2021.
//

#include "SequenceDictionaryTest.hpp"

void sequenceDictionaryAdd(){
    auto* dict = new SequenceDictionary<int, int>();
    
    dict->add(1, 1);
    dict->add(2, 1);
    dict->add(3, 1);
    dict->add(4, 1);
    dict->add(5, 1);
    dict->add(6, 1);
    
    assert(dict->keyExist(1) == true);
    assert(dict->keyExist(2) == true);
    assert(dict->keyExist(3) == true);
    assert(dict->keyExist(4) == true);
    assert(dict->keyExist(5) == true);
    assert(dict->keyExist(6) == true);
    assert(dict->keyExist(220) == false);
    assert(dict->keyExist(224) == false);
    
    delete dict;
}

void sequenceDictionaryGet(){
    auto* dict = new SequenceDictionary<int, int>();
    
    dict->add(1, 1);
    dict->add(2, 2);
    dict->add(3, 3);
    dict->add(4, 4);
    dict->add(5, 5);
    dict->add(6, 6);
    
    assert(dict->getValue(1) == 1);
    assert(dict->getValue(2) == 2);
    assert(dict->getValue(3) == 3);
    assert(dict->getValue(4) == 4);
    assert(dict->getValue(5) == 5);
    assert(dict->getValue(6) == 6);
    
    
    delete dict;
}

void sequenceDictionaryGetPair(){
    auto* dict = new SequenceDictionary<int, int>();
    
    dict->add(1, 1);
    dict->add(2, 2);
    dict->add(3, 3);
    dict->add(4, 4);
    dict->add(5, 5);
    dict->add(6, 6);
    
    Pair<int, int> pair1 = Pair<int, int>(1, 1);
    Pair<int, int> pair2 = Pair<int, int>(2, 2);
    Pair<int, int> pair3 = Pair<int, int>(3, 3);
    Pair<int, int> pair4 = Pair<int, int>(4, 4);
    Pair<int, int> pair5 = Pair<int, int>(5, 5);
    Pair<int, int> pair6 = Pair<int, int>(6, 6);
    
    assert(dict->getPair(1) == pair1);
    assert(dict->getPair(2) == pair2);
    assert(dict->getPair(3) == pair3);
    assert(dict->getPair(4) == pair4);
    assert(dict->getPair(5) == pair5);
    assert(dict->getPair(6) == pair6);
    
    delete dict;
}


void sequenceDictionaryGetSize(){
    auto* dict = new SequenceDictionary<int, int>();
    
    dict->add(1, 1);
    assert(dict->getSize() == 1);
    
    dict->add(2, 2);
    assert(dict->getSize() == 2);
    
    dict->add(3, 3);
    assert(dict->getSize() == 3);
    
    dict->add(4, 4);
    assert(dict->getSize() == 4);
    
    dict->add(5, 5);
    assert(dict->getSize() == 5);
    
    dict->add(6, 6);
    assert(dict->getSize() == 6);
    
    
    delete dict;
}

void sequenceDictionaryRemove(){
    auto* dict = new SequenceDictionary<int, int>();
    
    dict->add(1, 1);
    dict->add(2, 1);
    dict->add(3, 1);
    dict->add(4, 1);
    dict->add(5, 1);
    dict->add(6, 1);
    
    dict->remove(1);
    assert(dict->keyExist(1) == false);
    
    dict->remove(2);
    assert(dict->keyExist(2) == false);
    
    dict->remove(3);
    assert(dict->keyExist(3) == false);
    
    dict->remove(4);
    assert(dict->keyExist(4) == false);
    
    dict->remove(5);
    assert(dict->keyExist(5) == false);
    
    dict->remove(6);
    assert(dict->keyExist(6) == false);

    
    delete dict;
}


void sequenceDictionaryTests(){
    std::cout << "SequenceDictionary Tests:\n";
    sequenceDictionaryAdd();
    std::cout << "1)SequenceDictionary add test compleated\n";
    sequenceDictionaryGet();
    std::cout << "2)SequenceDictionary get test compleated\n";
    sequenceDictionaryGetPair();
    std::cout << "3)SequenceDictionary getPair test compleated\n";
    sequenceDictionaryGetSize();
    std::cout << "4)SequenceDictionary getSize test compleated\n";
    sequenceDictionaryRemove();
    std::cout << "5)SequenceDictionary remove test compleated\n";
}
