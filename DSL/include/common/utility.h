/*
 * Utility.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef UTILITY_H_
#define UTILITY_H_
#include<common/iterator.h>

namespace DSL{


//Return value
//Iterator to the first element satisfying the condition or last if no such element is found.
template<typename Iterator, typename Lambda>
Iterator find_if(Iterator s, Iterator e, Lambda predicate){
	while(s != e){
		if(predicate(*s))
			return s;
	}
	return e;
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


class NonCopiable{
public:
	NonCopiable(){};
private:
	NonCopiable(NonCopiable& c) = delete;
	NonCopiable& operator=(NonCopiable& c) = delete;
};

}



#endif /* UTILITY_H_ */
