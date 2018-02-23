//Pair<T1, T2>
//Simple

#ifndef PAIR_H
#define PAIR_H

template<typename T1, typename T2>
class Pair{
public:
    T1 first;
    T2 second;
    
    Pair(){}
    Pair(T1 a, T2 b){first=a; second=b;}
};


#endif