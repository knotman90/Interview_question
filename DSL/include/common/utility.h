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


//Lambda has type: D -> T -> D
template<typename T , typename D ,
		typename Iterator = sequential_forward_iterator<T> ,
		typename Lambda>
D fold(const Iterator s,const Iterator e, const D a, Lambda l){
	D acc = a ;
	Iterator n = s;
	while(s != e)
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
