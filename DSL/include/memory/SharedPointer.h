/*
 * SharedPointer.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */
#ifndef SHAREDPOINTER_H_
#define SHAREDPOINTER_H_

#include "Utility.h"

namespace DSL {

typedef unsigned int uint;

template <typename T,typename D = uint>
class SharedPointer : DSL::NonCopiable{
public:
	SharedPointer(T* ptr):pointer(ptr){
		Valid(count);
	};

private:
	D count=0;
	T* pointer;

	//check for count D parameter to be numeric (one of the following)
	void Valid(int a){};
	void Valid(uint a){};
	void Valid(short a){};


};

}//namespace

#endif /* SHAREDPOINTER_H_ */
