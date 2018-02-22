#ifndef VECTOR_H
#define VECTOR_H


template<typename T> class Vector{
public:
private:
    unsigned int current_size;
    unsigned int data_size;
    T* data;
    
    void stretch(){ //Make larger.
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
    
    void smaller(unsigned int new_size){ //Make smaller, given the new size
        if (data_size<=new_size) return; //If new size is not smaller, do nothing
        
        T* new_data=new T[new_size+1];
        for (unsigned int i=0; i<new_size; ++i){
            new_data[i]=data[i];
        }
        delete[] data;
        data=new_data;
        data_size=new_size;
    }
public:
    void swap(Vector<T>& o){
        T* d=data; data=o.data; o.data=d;
        unsigned int t=current_size; current_size=o.current_size; o.current_size=t;
        t=data_size; data_size=o.data_size; o.data_size=t;
    }
    
    void shrink_to_fit(){ // Make as small as possible without losing data
        if (current_size==0) smaller(0); 
        else{
            unsigned int new_size=(1<<(31-__builtin_clz(current_size)));
            smaller(new_size);
        }
    }
    
    void clear(){current_size=0;}
    
    bool empty(){return current_size==0;}
    
    T& back(){return data[current_size-1];}
    
    void pop_back(){--current_size;}
    
    void resize(unsigned int new_size){
        current_size=new_size;
        while (data_size<current_size) stretch();
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
    
    Vector(){
        data=NULL;
        current_size=0;
        data_size=0;
    }
    
    T& operator[](int i){return data[i];}
    
    ~Vector(){
        if (data_size) delete[] data;
    }
};

#endif