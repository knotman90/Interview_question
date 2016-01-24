/*
 * ScopedPointer.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef SCOPEDPOINTER_H_
#define SCOPEDPOINTER_H_

#include <common/utility.h>

namespace DSL{

template<class T>
class ScopedPointer : NonCopiable{
private:
	T * pointer;
public:
	 ScopedPointer( T  *p): pointer(p){};
	virtual ~ScopedPointer(){
		if(pointer)
			delete pointer;
	};
	T * operator->() const {return pointer;};
	T & operator*() const {return *pointer;};



private:

};

}

#endif /* SCOPEDPOINTER_H_ */
