#ifndef FAST_SET_H
#define FAST_SET_H

#include <bits/stdc++.h>


template <typename T> class FastSet{
public:
    std::vector<std::vector<T> > vecs;
    
    void joinv(std::vector<T>& a , std::vector<T>& b){
        std::vector<T> n;
        n.resize(a.size()<<1);
        std::merge(a.begin(), a.end(), b.begin(), b.end(), n.begin());
        std::swap(a, n);
    }

    void append(FastSet<T>& o){
        std::vector<T> b;
        for (unsigned int ii=0;;++ii){
            if (ii>=o.vecs.size() && b.size()==0) break;
            if (ii>=vecs.size()) vecs.push_back(std::vector<T>());
            std::vector<T> a;std::swap(a, vecs[ii]);
            std::vector<T> c;
            if (ii<o.vecs.size()) std::swap(c, o.vecs[ii]);
            
            if (a.size()==0) std::swap(a, c);
            if (a.size()==0) std::swap(a, b);
            if (b.size()==0) std::swap(b, c);
            if (a.size() && b.size() && c.size()){
            joinv(b, c);
            c.clear(); c.shrink_to_fit();
            }else if (a.size() && b.size()){
            joinv(b, a);
            a.clear(); a.shrink_to_fit();
            }
            std::swap(a, vecs[ii]);
            if (ii<o.vecs.size()) std::swap(c, o.vecs[ii]);
        }
    }
    
    void insert(T& v){
        FastSet<T> o;
        o.vecs.push_back(std::vector<T>());
        o.vecs.back().push_back(v);
        append(o);
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
            if (!(vecs[i][a]<v || v<vecs[i][a])) return (1<<i)+a;
        }
        return -1;
    }
    
    T findByIndex(int ix){
        int i=31 - __builtin_clz(ix);
        int a=ix^(1<<i);
        return vecs[i][a];
    }
};

#endif