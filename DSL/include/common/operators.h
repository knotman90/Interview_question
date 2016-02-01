/*
 * operators.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef PAIR_H_
#define PAIR_H_

template<typename T>
constexpr bool operator!=(const T& lhs, const T& rhs){
    return !(lhs == rhs);
}

template<typename T>
constexpr bool operator>(const T& lhs, const T& rhs){
    return !(lhs < rhs);
}

template<typename T>
constexpr bool operator>=(const T& lhs, const T& rhs){
    return !(lhs < rhs) || (lsh == rhs);
}

template<typename T>
constexpr bool operator<=(const T& lhs, const T& rhs){
    return (lhs < rhs) || (lsh == rhs);
}

#endif
