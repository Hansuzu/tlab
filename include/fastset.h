#ifndef FAST_SET_H
#define FAST_SET_H

#include <vector.h>


template <typename T> class FastSet{
public:
    Vector<Vector<T> > vecs;
    T MAX_ELEMENT;
    
    void swap(Vector<T>& a, Vector<T>& b){
        a.swap(b);
    }
    
    
    void joinv(Vector<T>& a , Vector<T>& b){
        Vector<T> n;
        n.resize(a.size()<<1);
        int ai=0; int bi=0;
        a[a.size()]=MAX_ELEMENT;
        b[b.size()]=MAX_ELEMENT;
        for (int i=0; i<(int)n.size(); ++i){
            if (a[ai]<b[bi])  n[i]=a[ai++];
            else              n[i]=b[bi++];
        }
        swap(a, n);
    }

    void append(FastSet<T>& o){
        Vector<T> b;
        for (unsigned int ii=0;;++ii){
            if (ii>=o.vecs.size() && b.size()==0) break;
            if (ii>=vecs.size()) vecs.push_back(Vector<T>());
            Vector<T> a;swap(a, vecs[ii]);
            Vector<T> c;
            if (ii<o.vecs.size()) swap(c, o.vecs[ii]);
            
            if (a.size()==0) swap(a, c);
            if (a.size()==0) swap(a, b);
            if (b.size()==0) swap(b, c);
            if (a.size() && b.size() && c.size()){
                joinv(b, c);
                c.clear(); c.shrink_to_fit();
            }else if (a.size() && b.size()){
                joinv(b, a);
                a.clear(); a.shrink_to_fit();
            }
            swap(a, vecs[ii]);
            if (ii<o.vecs.size()) swap(c, o.vecs[ii]);
        }
    }
    
    void insert(T& v){
        FastSet<T> o;
        o.vecs.push_back(Vector<T>());
        o.vecs.back().emplace_back(v);
        append(o);
    }
    void insert_(T v){
        insert(v);
    }
    
    int findIndex(T& v){
        for (int i=0; i<(int)vecs.size(); ++i){
            if (vecs[i].empty()) continue;
            int a=0; int b=vecs[i].size()-1;
            while (a<b){
                int m=(a+b)>>1;
                if (vecs[i][m]<v) a=m+1;
                else b=m;
            }
            if (!(vecs[i][a]<v || v<vecs[i][a])) return (1<<i)|a;
        }
        return -1;
    }
    
    int nextIndex(int ix){
        if (ix<0) return -1;
        
        int i=31 - __builtin_clz(ix);
        int a=ix^(1<<i);
        ++a;
        while (i<(int)vecs.size()){
            if (a<(int)vecs[i].size()){
                return (1<<i)|a;
            }
            a=0;
            ++i;
        }
        return -1;
    }
    int firstIndex(){
        int i=0; int a=0;
        if (vecs[0].size()) return (1<<i)|a;
        return nextIndex((1<<i)|a);
    }
    
    int findIndex_(T v){
        return findIndex(v);
    }
    void insertToIndex(int ix, T& vs){
        int i=31 - __builtin_clz(ix);
        int a=ix^(1<<i);
        vecs[i][a]=vs;
    }
    T findByIndex(int ix){
        int i=31 - __builtin_clz(ix);
        int a=ix^(1<<i);
        return vecs[i][a];
    }
    
    void set_max_element(T max_element){
        MAX_ELEMENT=max_element;
    }
};

#endif