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
	 void ( *deallocator ) ( T* ptr);
public:
	explicit SharedPointer(T* ptr):deallocator(SharedPointer::defaultDeallocator),count(0),pointer(ptr){
		Valid(count);
	};

	explicit SharedPointer(SharedPointer& sp):deallocator(SharedPointer::defaultDeallocator),pointer(sp.pointer){
		count=sp.count+1;
	}

	template<typename Y>
	explicit SharedPointer(SharedPointer& sp,Y _deallocator):deallocator(_deallocator),pointer(sp.pointer){
			count=sp.count+1;
	}


	inline static void defaultDeallocator(T* ptr){
		delete ptr;
	}

    SharedPointer & operator=(SharedPointer const & r){
    	if(r.pointer != this->pointer){
    		//reset
    	}
    }
    SharedPointer & operator=(SharedPointer const && r); // never throws

	virtual ~SharedPointer(){
		if(count==0){
			if(pointer)
				deallocator(pointer);
		}else{
			count--;
		}

	}

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
