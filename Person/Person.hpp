//
//  Person.hpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 06.12.2021.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>


class Person{
private:
    std::string first_name_;
    std::string middle_name_;
    std::string last_name_;
    int birth_year_;
public:
    Person();
    
    Person(std::string first_name, std::string middle_name, std::string last_name, int birth_year){
        first_name_ = first_name;
        middle_name_ = middle_name;
        last_name_ = last_name;
        birth_year_ = birth_year;
    }
    
    Person(const Person &person){
        first_name_ = person.first_name_;
        middle_name_ = person.middle_name_;
        last_name_ = person.last_name_;
        birth_year_ = person.birth_year_;
    }
    
    
    
    std::string GetFirstName(){
        return first_name_;
    }
    
    std::string GetMiddleName(){
        return middle_name_;
    }
    
    std::string GetLastName(){
        return last_name_;
    }
    
    std::string GetFullName(){
        return first_name_ + " " + middle_name_ + "" + last_name_;
    }
        
    int GetBirthYear(){
        return birth_year_;
    }
    
    int GetAge(int year){
        return year - birth_year_;
    }
};


#endif /* Person_hpp */
