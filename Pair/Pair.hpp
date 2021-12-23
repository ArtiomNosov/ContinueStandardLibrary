//
//  Pair.hpp
//  Lab2_3s
//
//  Created by  Николай Фонов on 09.12.2021.
//

#ifndef Pair_hpp
#define Pair_hpp

#include <iostream>

template<typename T1, typename T2>
class Pair {
private:
    T1 element1;
    T2 element2;
public:
    Pair();

    Pair(const T1& elem1, const T2& elem2);
    
    Pair(const T1& elem);

    Pair(std::pair<T1, T2> p);

    Pair(const Pair<T1, T2> &p);

    void setFirst(T1 value);

    void setSecond(T2 value);

    T1 getFirst() const;

    T2 getSecond() const;

    Pair<T1, T2> &operator=(const Pair<T1, T2> &p);

    bool operator==(const Pair<T1, T2> &p) const;

    bool operator<(const Pair<T1, T2> &p) const;

    bool operator<=(const Pair<T1, T2> &p) const;

    bool operator>(const Pair<T1, T2> &p) const;

    bool operator>=(const Pair<T1, T2> &p) const;

    template<typename T11, typename T22>
    friend std::ostream &operator<<(std::ostream &out, const Pair<T11, T22> &p);
    
    ~Pair();
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& elem1, const T2& elem2) {
    this->element1 = elem1;
    this->element2 = elem2;
}

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& elem) {
    this->element1 = elem;
}




template<typename T1, typename T2>
Pair<T1, T2>::Pair(const Pair<T1, T2> &p) {
    this->element2 = p.element2;
    this->element1 = p.element1;
}

template<typename T1, typename T2>
void Pair<T1, T2>::setFirst(T1 value) {
    this->element1 = value;
}

template<typename T1, typename T2>
void Pair<T1, T2>::setSecond(T2 value) {
    this->element2 = value;
}

template<typename T1, typename T2>
T1 Pair<T1, T2>::getFirst() const {
    return this->element1;
}

template<typename T1, typename T2>
T2 Pair<T1, T2>::getSecond() const {
    return this->element2;
}

template<typename T1, typename T2>
Pair<T1, T2> &Pair<T1, T2>::operator=(const Pair<T1, T2> &p) {
    if (this == &p) {
        return *this;
    }
    this->element1 = p.element1;
    this->element2 = p.element2;
    return *this;
}

template<typename T11, typename T22>
std::ostream &operator<<(std::ostream &out, const Pair<T11, T22> *p) {
    out << "<" << p->getFirst() << ", " << p->getSecond() << ">";
    return out;
}

template<typename T11, typename T22>
std::ostream &operator<<(std::ostream &out, const Pair<T11, T22> &p) {
    out << "<" << p.getFirst() << ", " << p.getSecond() << ">";
    return out;
}

template<typename T1, typename T2>
bool Pair<T1, T2>::operator==(const Pair<T1, T2> &p) const {
    return this->element1 == p.element1;
}

template<typename T1, typename T2>
Pair<T1, T2>::Pair(std::pair<T1, T2> p) {
    this->element1 = p.first;
    this->element2 = p.second;
}

template<typename T1, typename T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p) const {
    if (this->element1 < p.element1) {
        return true;
    } else {
        return false;
    }
}

template<typename T1, typename T2>
bool Pair<T1, T2>::operator>(const Pair<T1, T2> &p) const {
    if (this->element1 > p.element1) {
        return true;
    } else {
        return false;
    }
}

template<typename T1, typename T2>
bool Pair<T1, T2>::operator<=(const Pair<T1, T2> &p) const {
    if (this->element1 <= p.element1) {
        return true;
    } else {
        return false;
    }
}

template<typename T1, typename T2>
bool Pair<T1, T2>::operator>=(const Pair<T1, T2> &p) const {
    if (this->element1 >= p.element1) {
        return true;
    } else {
        return false;
    }
}

template<typename T1, typename T2>
Pair<T1, T2>::Pair() = default;

template<typename T1, typename T2>
Pair<T1, T2>::~Pair(){}

#endif /* Pair_hpp */
