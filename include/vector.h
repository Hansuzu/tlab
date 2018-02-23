#ifndef VECTOR_H
#define VECTOR_H

//Convert string to Vector
#include <string>

template<typename T> class Vector{
public:
private:
    unsigned int current_size;
    unsigned int data_size;
    T* data;
    
    void stretch(){ //Make larger. (push_back calls this if this is two small)
        if (data_size==0){ //If size 0 make size 1
            data=new T[1+1];
            data_size=1;
        }else{ //Make size 2*size
            T* new_data=new T[2*data_size+1];
            for (unsigned int i=0; i<data_size; ++i){
                new_data[i]=data[i];
            }
            delete[] data;
            data=new_data;
            data_size*=2;
        }
    }
    
    unsigned int min(unsigned int a, unsigned int b){return a<b?a:b;}
    
    void resize_container_to(unsigned int new_size){ //Make new size of Vector new_size
        if (new_size==data_size) return;
        T* new_data=NULL;
        if (new_size) new_data=new T[new_size+1];
        
        unsigned int size_min=min(new_size, data_size);
        for (unsigned int i=0; i<size_min; ++i){
            new_data[i]=data[i];
        }
        if (data_size) delete[] data;
        data=new_data;
        data_size=new_size;
    }
    
public:
    void swap(Vector<T>& o){
        T* d=data; data=o.data; o.data=d;
        unsigned int t=current_size; current_size=o.current_size; o.current_size=t;
        t=data_size; data_size=o.data_size; o.data_size=t;
    }
    
    void shrink_to_fit(){ // Make the datasize to fit the current_size
                          //Can also make it larger
        if (current_size==0) resize_container_to(0); 
        else if (current_size==1) resize_container_to(1);
        else{
            unsigned int new_size=(1<<(32-__builtin_clz(current_size-1)));
            resize_container_to(new_size);
        }
    }
    unsigned int container_size(){
        return data_size;
    }
    
    void clear(){current_size=0;}
    
    bool empty(){return current_size==0;}
    
    T& back(){return data[current_size-1];}
    
    void pop_back(){--current_size;}
    
    void resize(unsigned int new_size){
        current_size=new_size;
        shrink_to_fit();
    }
    
    void emplace_back(T& t){
        if (current_size==data_size)  stretch();
        data[current_size++]=t;
    }
    void push_back(T t){
        emplace_back(t);
    }
    
    unsigned int size(){
        return current_size;
    }
    
    
    Vector& operator=(const Vector& o){
        if (data_size) delete[] data;
        data_size=o.data_size;
        current_size=o.current_size;
        data=new T[data_size];
        for (int i=0; i<(int)current_size; ++i) data[i]=o.data[i];
        return *this;
    }
    
    Vector(const Vector& o){
        data_size=o.data_size;
        current_size=o.current_size;
        data=new T[data_size];
        for (int i=0; i<(int)current_size; ++i) data[i]=o.data[i];
    }
    
    Vector(){
        data=NULL;
        current_size=0;
        data_size=0;
    }
    
    Vector(std::string(c)){
        data=NULL;
        current_size=c.size();
        data_size=0;
        shrink_to_fit();
        for (unsigned int i=0; i<current_size; ++i) data[i]=c[i];
    }
    
    T& operator[](int i){return data[i];}
    
    ~Vector(){
        if (data_size) delete[] data;
    }
};

#endif