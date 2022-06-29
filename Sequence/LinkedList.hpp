#ifndef link_list_hpp
#define link_list_hpp

#include <stdexcept>
#include <string>
#include <sstream>

const std::string INDEX_OUT_OF_RANGE = "Index out of range";
const std::string SIZE_LESS_0 = "Size is less than 0";



template <typename T> class LinkedList {
private:

    template <typename T> class Node {
    public:
        T value;
        Node<T>* next;

        Node() {
            value;
            next = nullptr;
        };
        Node(T value, Node<T>* next) {
            this->value = value;
            this->next = next;
        };
    };

    Node<T>* head = nullptr;
    int size;
public:
    //Constructor

    LinkedList(){
        size = 0;
        head = nullptr;
    }
    LinkedList(int size){
        this->size = size;
        head = nullptr;
    }
    LinkedList(T* items, int count){
        if (count < 0){
            throw std::length_error(SIZE_LESS_0);
        };
        for(int i = 0; i < count; i++){
            Append(items[i]);
        };
    };
    LinkedList(const LinkedList<T>& list){
        for (int i = 0; i < list.GetLength(); i++){
            this->Append(list.Get(i));
        }
    };
    LinkedList(LinkedList<T>* list){
        head = list->head;
        size = list->size;
    }
    //Destructor
    ~LinkedList(){
        Delete_LinkedList();
    };
    void Delete_LinkedList(){
        Node<T>* buf = new Node<T>();
        head = nullptr;
        while (head != nullptr){
            buf = head;
            delete buf;
            head = head->next;
        }
        size = 0;
    }

    //Decomposition
    T GetFirst() const{
        if (head == nullptr){
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
        return head->value;
    };
    T GetLast() const{
        if (head == nullptr){
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
        return Get(size-1);
    };
    T Get(int index) const{
        if (index < 0 || index >= size){
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
        Node<T>* buff = head;
        for(int i = 0; i < index; i++){
            buff = buff->next;
        }
        return buff->value;
    };
    LinkedList<T>* GetSublist(int start, int end){
        if (start >= size || end >= size || start < 0 || end < 0){
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }

        LinkedList<T>* new_list = new LinkedList<T>();
        for(int i = start; i < end; i++){
            new_list->Append(this->Get(i));
        }
        new_list->size = end - start;
        return new_list;
    };
    int GetLength() const{
        return size;
    };


    //Operations
    void Append(T value){
        Node<T>* newElem = new Node<T>;
        newElem->value = value;
        newElem->next = nullptr;
        if(head == nullptr) {
            head = newElem;
            size = 1;
            return;
        } else{
            Node<T>* buf;
            buf = head;
            //after while buf point on last el in list
            while(buf->next != nullptr){
                buf = buf->next;
            }
            size++;
            buf->next = newElem;
        }
    };
    void Prepend(T value){
        this->head = new Node<T>(value, this->head);
        size++;
    };
    void InsertAt(T value, int index){
        if(index < 0 || index > this->size){
            throw std::out_of_range("InsertAt : Index out of range");
        }
        Node<T>* buff = head;
        for(int i = 0; i < index-1; i++){
            buff = buff->next;
        }
        Node<T>* new_node = new Node<T>(value, buff->next);
        buff->next = new_node;
        size++;
    };
    void Set(T value, int index){
        if (index < 0 || index > size - 1)
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        Node<T>* buff = head;
        for (int i = 0; i < index; i++)
            buff = buff->next;
        buff->value = value;
    }
    LinkedList<T>* Concat(LinkedList<T>* list){
        LinkedList<T>* newList = new LinkedList<T>();
        newList->head = this->head;
        Node<T>* buff = this->head;
        for(int i = 0; i < this->GetLength() - 1; i++){
            buff = buff->next;
        };
        newList->size = list->size + this->size;
        buff->next = list->head;
        return newList;
    };


    //Operators
    Node<T>* operator[] (int index){
        if (index < 0 || index > this->size-1) {
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
        Node<T>* buff = head;
        for (int i = 0; i < index; i++) {
            buff = buff->next;
        }
        return buff;
    };
    
    LinkedList<T>* Copy(LinkedList<T> *list_seq){
        LinkedList<T>* newLL = new LinkedList<T>(list_seq);
        return newLL;
    };
    
    bool Exist(T item){
        bool res = 0;
        Node<T>* buff = head;
        for(int i = 0; i < size; i++){
            if (buff->value == item){
                res = 1;
            }
            buff = buff->next;
        }
        return res;
    }
    
    T GetItem(T item){
        if (this->Exist(item)){
            Node<T>* buff = head;
            for(int i = 0; i < size; i++){
                if (buff->value == item){
                    return buff->value;
                }
                buff = buff->next;
            }
        }
        throw std::out_of_range(INDEX_OUT_OF_RANGE);
    }
    
    void DeleteOnIndex(int delta, Node<T>* node){
        if (delta == 1){
            if (node->next->next != nullptr){
                node->next = node->next->next;
            }
            else{
                node->next = nullptr;
            }
            return;
        }
        DeleteOnIndex(delta - 1, node->next);
    }
    
    void DeleteOnIndex(int index){
        if (index >= size){
            return throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
        
        if (index == 0){
            head = head->next;
            return;
        }
        
        DeleteOnIndex(index, this->head);
    }
    
    void Delete(T item){
        if (this->Exist(item)){
            Node<T>* buff = head;
            for(int i = 0; i < size; i++){
                if (buff->value == item){
                    DeleteOnIndex(i);
                    this->size -= 1;
                    return;
                }
                buff = buff->next;
            }
        }
    }

};
#endif /* link_list_hpp */
