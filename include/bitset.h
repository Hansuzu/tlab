#ifndef BITSET_H
#define BITSET_H

//Simple bitset

class Bitset{
    
private:
    unsigned int cpopcount;
    unsigned int size;
    unsigned int data_size;
    
    unsigned int min(unsigned int a, unsigned int b){return a<b?a:b;}
    unsigned int max(unsigned int a, unsigned int b){return a<b?b:a;}
    
    unsigned long long* data;
    
public:
    unsigned int popcount(){return cpopcount;}
    
    bool getBit(unsigned int i){
        unsigned int data_i=i/64;
        unsigned int bit_i=(i&(63));
        return data[data_i]&(1ull<<(bit_i));
    }
    
    
    void setBitOn(unsigned int i){
        unsigned int data_i=i/64;
        unsigned int bit_i=(i&(63));
        if (!(data[data_i]&(1ull<<(bit_i)))) ++cpopcount;
        data[data_i]|=(1ull<<(bit_i));
    }
    void setBitOff(unsigned int i){
        unsigned int data_i=i/64;
        unsigned int bit_i=(i&(63));
        if (data[data_i]&(1ull<<(bit_i))) --cpopcount;
        data[data_i]&=~(1ull<<(bit_i));
    }
    
    
    void operator&=(const Bitset& o){
        unsigned int dl=min(data_size, o.data_size);
        for (unsigned int i=0; i<dl; ++i){
            int c_popcount=__builtin_popcountll(data[i]);
            data[i]&=o.data[i];
            cpopcount+=(__builtin_popcountll(data[i]))-c_popcount;
        }
    }
    
    void operator|=(const Bitset& o){
        unsigned int dl=min(data_size, o.data_size);
        for (unsigned int i=0; i<dl; ++i){
            int c_popcount=__builtin_popcountll(data[i]);
            data[i]|=o.data[i];
            cpopcount+=(__builtin_popcountll(data[i]))-c_popcount;
        }
    }
    
    Bitset operator&(const Bitset& o){
        Bitset r(max(size, o.size));
        r|=*this;
        r&=o;
        return r;
    }
    
    Bitset operator|(const Bitset& o){
        Bitset r(max(size, o.size));
        r|=*this;
        r|=o;
        return r;
    }
    
    void operator=(const Bitset& o){
        delete[] data;
        data=new unsigned long long[o.data_size];
        cpopcount=o.cpopcount;
        size=o.size;
        data_size=o.data_size;
        
        for (unsigned int i=0; i<data_size; ++i){
            data[i]=o.data[i];
        }
    }
    
    
    Bitset(unsigned int size_){
        size=size_;
        data_size=(size+63)/64;
        if (data_size==0) data_size=1;
        data=new unsigned long long[data_size];
        for (unsigned int i=0; i<data_size; ++i) data[i]=0;
        cpopcount=0;
    }
    
    Bitset(const Bitset& o){
        data_size=o.data_size;
        size=o.size;
        cpopcount=o.cpopcount;
        data=new unsigned long long[data_size];
        for (unsigned int i=0; i<data_size; ++i) data[i]=o.data[i];
    }
    
    Bitset(){
        data_size=1;
        size=0;
        data=new unsigned long long[data_size];
        for (unsigned int i=0; i<data_size; ++i) data[i]=0;
        cpopcount=0;
    }
    ~Bitset(){
        delete[] data;
    }
};

#endif