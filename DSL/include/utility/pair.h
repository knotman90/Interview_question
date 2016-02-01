/*
 * pair.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef PAIR_H_
#define PAIR_H_

#include<algorithm/algorithm.h>
#include<common/operators.h>

namespace DSL {
template<typename T, typename D>
class pair {
private:


    T first;
    D second;

public:
    pair(const T &f , const D &s) : first(f), second(s){}
    void swap(pair p1){
        const T first_copy = first;
        const D second_copy = second;

        first = p1.first;
        second = p1.second;

        p1.first = first_copy;
        p1.second = second_copy;
    }

    pair& operator=( const pair& rhs ){
       first = rhs.first;
       second = rhs.second;
       return *this;
   }

};

};

template<typename T , typename D>
constexpr bool operator!=( const pair<T,D>& lhs, const pair<<T,D>& rhs ){
    return !(lhs == rhs)
}

//operators == and < are the minimum complete definition
//for deriving all the other operators
template<typename T , typename D>
 bool operator==( const pair<T,D>& lhs, const pair<T,D>& rhs ){
    return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

//< according to lexicographic ordering
template<typename T , typename D>
bool operator<( const pair<T,D>& lhs, const pair<T,D>& rhs ){
    return (lhs.first < rhs.first) || (lhs.second < rhs.second);
}

template<typename T, typename D>
inline make_pair(const T &f , const D &s){
    return pair(f , d);
}


}

#endif /* PAIR_H */
