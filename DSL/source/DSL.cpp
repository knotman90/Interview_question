//============================================================================
// Name        : DSL.cpp
// Author      : Davide Spataro
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ScopedPointer.h>
#include <SharedPointer.h>
template<class T>
class Test{
	public:
	T a;
	explicit Test(T aa = 0) : a(aa){};

	virtual ~Test(){
		std::cout<<"Destroyed\n";
	}
};

int func(DSL::ScopedPointer<Test<int>>& p){
	return p->a+10;
}


int main() {
	const DSL::ScopedPointer< Test<int> > p(new Test<int>(123));

	DSL::SharedPointer <Test<int>,int>ps(new Test<int>(222));
	std::cout<<p->a<<std::endl;



	return 0;
}
