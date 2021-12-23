//
//  QueueDictionaryTest.cpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 16.12.2021.
//

#include "QueueDictionaryTest.hpp"

void qdPushBack(){
    auto* qd = new QueueDictionary<int, int>("AVL", "");
    
    qd->push(1, 1);
    qd->push(2, 2);
    qd->push(3, 3);
    qd->push(4, 4);
    qd->push(5, 5);
    qd->push(6, 6);
    
    assert(qd->keyExist(1) == 1);
    assert(qd->keyExist(2) == 1);
    assert(qd->keyExist(3) == 1);
    assert(qd->keyExist(4) == 1);
    assert(qd->keyExist(5) == 1);
    assert(qd->keyExist(6) == 1);
    
    delete qd;
}

void qdDelete(){
    auto* qd = new QueueDictionary<int, int>("AVL", "");
    
    qd->push(1, 1);
    qd->push(2, 2);
    qd->push(3, 3);
    qd->push(4, 4);
    qd->push(5, 5);
    qd->push(6, 6);
    
    qd->Delete(1);
    assert(qd->keyExist(1) == 0);
    
    qd->Delete(2);
    assert(qd->keyExist(2) == 0);
    
    qd->Delete(3);
    assert(qd->keyExist(3) == 0);
    
    qd->Delete(4);
    assert(qd->keyExist(4) == 0);
    
    qd->Delete(5);
    assert(qd->keyExist(5) == 0);
    
    qd->Delete(6);
    assert(qd->keyExist(6) == 0);
    
    delete qd;
}

void qdDeleteBegin(){
    auto* qd = new QueueDictionary<int, int>("AVL", "");
    
    qd->push(1, 1);
    qd->push(2, 2);
    qd->push(3, 3);
    qd->push(4, 4);
    qd->push(5, 5);
    qd->push(6, 6);
    
    qd->pop();
    assert(qd->keyExist(1) == 0);
    qd->pop();
    assert(qd->keyExist(2) == 0);
    qd->pop();
    assert(qd->keyExist(3) == 0);
    qd->pop();
    assert(qd->keyExist(4) == 0);
    qd->pop();
    assert(qd->keyExist(5) == 0);
    qd->pop();
    assert(qd->keyExist(6) == 0);
    
    delete qd;
}

void qdGetSize(){
    auto* qd = new QueueDictionary<int, int>("AVL", "");
    
    assert(qd->getSize() == 0);
    
    qd->push(1, 1);
    assert(qd->getSize() == 1);
    qd->push(2, 2);
    assert(qd->getSize() == 2);
    qd->push(3, 3);
    assert(qd->getSize() == 3);
    qd->push(4, 4);
    assert(qd->getSize() == 4);
    qd->push(5, 5);
    assert(qd->getSize() == 5);
    qd->push(6, 6);
    assert(qd->getSize() == 6);
    
    delete qd;
}

void qdGetBeginKey(){
    auto* qd = new QueueDictionary<int, int>("AVL", "");
        
    qd->push(1, 1);
    assert(qd->getLastKey() == 1);
    qd->push(2, 2);
    assert(qd->getLastKey() == 1);
    qd->push(3, 3);
    assert(qd->getLastKey() == 1);
    qd->push(4, 4);
    assert(qd->getLastKey() == 1);
    qd->push(5, 5);
    assert(qd->getLastKey() == 1);
    qd->push(6, 6);
    assert(qd->getLastKey() == 1);
    
    delete qd;
}

void qdGetBeginValue(){
    auto* qd = new QueueDictionary<int, int>("AVL", "");
        
    qd->push(1, 1);
    assert(qd->getLastValue() == 1);
    qd->push(2, 2);
    assert(qd->getLastValue() == 1);
    qd->push(3, 3);
    assert(qd->getLastValue() == 1);
    qd->push(4, 4);
    assert(qd->getLastValue() == 1);
    qd->push(5, 5);
    assert(qd->getLastValue() == 1);
    qd->push(6, 6);
    assert(qd->getLastValue() == 1);
    
    delete qd;
}


void queueDictionaryTests(){
    std::cout << "QueueDictionary Tests:\n";
    qdPushBack();
    std::cout << "1)QueueDictionary add test compleated\n";
    qdDelete();
    std::cout << "2)QueueDictionary delete test compleated\n";
    qdDeleteBegin();
    std::cout << "3)QueueDictionary deleteBegin test compleated\n";
    qdGetSize();
    std::cout << "4)QueueDictionary getSize test compleated\n";
    qdGetBeginKey();
    std::cout << "5)QueueDictionary getBeginKey test compleated\n";
    qdGetBeginValue();
    std::cout << "6)QueueDictionary getBeginValue test compleated\n";
}
