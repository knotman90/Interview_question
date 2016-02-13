/*
 * pair.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

 #ifndef SORTING_H_
 #define SORTING_H_

namespace DSL {

//basic cimplementation calls >operator
template <typename T>
constexpr bool greater(const T &lhd, const T &rhs){
    return lhd > rhs;
}

//uses < operator
template <typename RandomIterator >
void sort(RandomIterator s , RandomIterator e);

template <typename RandomIterator , typename BinaryComparator>
void sort(RandomIterator s , RandomIterator e , BinaryComparator comparator);


}


 #endif /* SORTING */
