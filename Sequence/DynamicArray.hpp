#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <string>
#include <sstream>

const std::string SIZE_LESS_00 = "Size is less than 0";
const std::string INDEX_OUT_OF_RANGE0 = "Index out of range";

template <typename T>
class DynamicArray {
private:
    T* data = nullptr;
    int size;
public:
    //Contructor
    DynamicArray(){
        size = 0;
    };
    DynamicArray(int size){
        if(size < 0){
            throw std::length_error(SIZE_LESS_00);
        };
        data = new T[size];
        this->size = size;
    };
    DynamicArray(T* items, int count){
        if(count < 0){
            throw std::length_error(SIZE_LESS_00);
        };
        data = new T[count];
        size = count;
        for(int i = 0; i < count; i++)
            data[i] = items[i];
    };
    DynamicArray(DynamicArray <T> &dynamicArray){
        data = new T[size];
        size = dynamicArray.size;
        for(int i = 0; i<size; i++){
            data[i] = dynamicArray.data[i];
        };
    };
    DynamicArray(DynamicArray<T>* dynArr){
        size = dynArr->size;
        data = dynArr->data;
    }


    //Destructor
    ~DynamicArray(){
        delete[] data;
        size = 0;
    };
    void Delete_DynamicArray(){
        delete[] data;
        size = 0;
    }
    //Function for cast int to string
    std::string toString(int val)
    {
        std::ostringstream oss;
        oss << val;
        return oss.str();
    }
    //Decomposition
    T Get(int index){
        if(index < 0 || index >= size){
            std::string msg = INDEX_OUT_OF_RANGE0 + ". Get -> " + toString(index) + " but len -> " + toString(size);
            throw std::out_of_range(msg);
        };
        return data[index];
    };

    int GetSize(){
        return size;
    }


    //Operations
    void Set(int index, T value){
        if (index < 0 || index >= size) {
            std::string msg = INDEX_OUT_OF_RANGE0 + ". Get -> " + toString(index) + " but len -> " + toString(size);
            throw std::out_of_range(msg);
        }
        data[index] = value;
    };
    void Resize(int newSize){
        if (newSize < 0){
            throw std::out_of_range(INDEX_OUT_OF_RANGE0);
        };// wrong len

        if (newSize == 0){
            delete[] data;
            data = nullptr;
            size = 0;
            return;
        }// len = 0 => delete

        if (newSize == size){
            return;
        }// newSize is the same as len

        if (newSize < size){
            T* new_data = new T[newSize];
            for (int i = 0; i < newSize; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            size = newSize;
            data = new_data;
            return;
        }// shortening array

        if (newSize > 0 && size == 0){
            T* new_data = new T[newSize];
            delete[] data;
            size = newSize;
            data = new_data;
        }//

        if (newSize > size){
            T* new_data = new T[newSize];
            for (int i = 0; i < size; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            size = newSize;
            data = new_data;
            return;
        }// increase length of array
    };
    
    bool Exist(T item){
        bool res = 0;
        for (int i = 0; i < size; i++) {
            if (data[i] == item){
                res = 1;
            }
        }
        return res;
    }
    
    T GetItem(T item){
        if (this->Exist(item)){
            for (int i = 0; i < size; i++) {
                if (data[i] == item){
                    return data[i];;
                }
            }
        }
        throw std::out_of_range(INDEX_OUT_OF_RANGE0);
    }
    
    void Delete(T item){
        if (this->Exist(item)){
            size -= 1;
            for (int i = 0; i < size; i++) {
                if (data[i] == item){
                    for (int j = i; j < size; j++){
                        data[j] = data[j  + 1];
                    }
                    return;
                }
            }
        }
    }
    


    //Operators
    T operator[] (int index){
        if (index < 0 || index >= this->size){
            throw std::out_of_range(INDEX_OUT_OF_RANGE0);
        }
        return this->Get(index);
    };

};
#endif /* DynamicArray_hpp */
