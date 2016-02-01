/*
 * algorithm.h
 *
 *  Created on: 18 gen 2016
 *      Author: Davide Spataro

 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

namespace DSL {

//this has to be specialized for each class that is SWAPPABLE
    template< class T >
    void swap( T& a, T& b ){
        T a_copy = a;
        a = b;
        b = a_copy;
    }

    template< class T2, size_t N >
    void swap( T2 (&a)[N], T2 (&b)[N]);
    //swap ranges


// -- Non-modifying sequence operations --

    template< typename T ,  typename  Iterator >
    bool contains( const Iterator s, const  Iterator e, const  T &value )   {
        auto predicate_equal = [&] (T curr){ return value == curr;  };
        bool ret =  e == find_if(s , e , predicate_equal);
        return !ret;
    }

    //Return value
    //Iterator to the first element satisfying the condition or last if no such element is found.
    template<typename Iterator, typename Lambda>
    inline Iterator find_if_not(  Iterator s, Iterator e, Lambda predicate){
    	auto not_predicate = [&](auto v){return !predicate(v); };
        return find_if(s , e , not_predicate);

    }


    //Return value
    //Iterator to the first element satisfying the condition or last if no such element is found.
    template<typename Iterator, typename Lambda>
    Iterator find_if(  Iterator s, Iterator e, Lambda predicate){
    	while(s != e){
    		if(predicate(*s))
    			return s;

            s++;
    	}
    	return e;
    }


template<typename Iterator, typename Lambda>
bool all_of(Iterator s , Iterator e , Lambda predicate){
    while(s != e)
        if(!predicate(*s))
            return false;

    return true;
}

template<typename Iterator, typename Lambda>
bool any_of(Iterator s , Iterator e , Lambda predicate){
    while(s != e)
        if(predicate(*s))
            return true;

    return false;
}

template<typename Iterator, typename Lambda>
bool none_of(Iterator s , Iterator e , Lambda predicate){
    return !any_of(s,e,predicate);
}


template<typename Iterator, typename T, typename D = int>
D count(Iterator s , Iterator e , const T &t)  {
        auto count_equal = [&](const D acc, const T val) { if (val == t) return acc+1; return acc; };
        return count_if(s , e , 0 , count_equal);

}


template<typename Iterator, typename T, typename Lambda, typename D = int>
D count(Iterator s , Iterator e , Lambda unary_predicate)  {
        D count = fold(s , e , 0 , unary_predicate );
        return count;

}


    //Lambda has type: D -> T -> D
    template<typename Payload , typename D ,
    		typename Iterator,
    		typename Lambda>
    D fold(const Iterator s,const Iterator e, const D a, Lambda l){
    	D acc = a ;
    	Iterator n = s;
    	while(n != e)
    		 acc = l(acc,s++);

    	return acc;
    }



}/* namespace DSL */


#endif /* ALGORITHM_H_ */
