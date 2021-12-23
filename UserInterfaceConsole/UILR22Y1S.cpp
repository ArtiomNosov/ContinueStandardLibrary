//
//  Interface.cpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 16.11.2021.
//

#include "UILR22Y1S.hpp"


int inputTaskType(){
    std::cout << "+––––––––––––––––––––––––––+\n"
                 "|           Menu           |\n"
                 "|    1 - manual work       |\n"
                 "|    2 - tests             |\n"
                 "|    0 - exit              |\n"
                 "+––––––––––––––––––––––––––+\n"
                 "Input number: ";
    
    int dict_type;
    std::cin >> dict_type;
    if (dict_type == 1 or dict_type == 2 or dict_type == 0){
        return dict_type;
    }
    std::cout << "Incorrect number!";
    return inputTaskType();
}

std::string inputString(){
    std::cout << "Input data: ";
    std::string string;
    std::cin >> string;
    return string;
}

bool continueWork(){
    std::cout << "Continue work with cache?: \n"
                 "1 - Yes                    \n"
                 "2 - No                     \n"
                 "Input number: ";
    
    int choice;
    std::cin >> choice;
    if (choice == 1){
        return 1;
    }
    if (choice == 2) {
        return 0;
    }
    std::cout << "Incorrect number!";
    return continueWork();
}

std::string inputDictionaryType(){
    std::cout << "Input Dictionary type: \n"
                 "1 - AVL Tree           \n"
                 "2 - Sequence           \n"
                 "Input number: ";
    
    int dict_type;
    std::cin >> dict_type;
    if (dict_type == 1){
        return "AVL";
    }
    if (dict_type == 2) {
        return "Sequence";
    }
    std::cout << "Incorrect number!";
    return inputDictionaryType();
}

std::string inputSequenceType(){
    std::cout << "Input Sequence type:   \n"
                 "1 - Dynamic Array      \n"
                 "2 - Linked List        \n"
                 "Input number: ";
    
    int dict_type;
    std::cin >> dict_type;
    if (dict_type == 1){
        return "Dynamic Array";
    }
    if (dict_type == 2) {
        return "Linked List";
    }
    std::cout << "Incorrect number!";
    return inputSequenceType();
}

int inputMaxCacheSize(){
    std::cout << "Input max size of Cache: ";
    int max_size;
    std::cin >> max_size;
    if (max_size < 0){
        std::cout << "Incorrect size!";
        return inputMaxCacheSize();
    }
    return max_size;
}



bool runInterface(){
    int type = inputTaskType();
    
    if (type == 0) {
        return 0;
    }
    
    if (type == 1) {
        int max_size = inputMaxCacheSize();
        std::string dict_type = inputDictionaryType();
        std::string seq_type = "";
        if (dict_type == "Sequence"){
            seq_type = inputSequenceType();
        }
        auto* cache = new LRUCache<std::string>(max_size, dict_type, seq_type);
        
        bool workWithCache = continueWork();
        while (workWithCache){
            if (workWithCache){
                std::string str = inputString();
                if (cache->inCache(str)){
                    std::cout << "Cache: Value from cache.\n";
                }
                else std::cout << "Cache: Value not from cache.\n";
                cache->Get(str);
                workWithCache = continueWork();
            }
        }
        return 1;
    }
    
    if (type == 2){
        std::cout << "Tests:\n";
        avlTests();
        avlDictionaryTests();
        sequenceDictionaryTests();
        queueDictionaryTests();
        dictionaryCacheTests();
        return 1;
    }
    return 1;
}
