#include <iostream>

//#include <ScopedPointer_test.h>

#include <LinkedList_test.h>
#include <pair_test.h>


int main(int argc, char** argv){
DSL::SingleLinkedList<int> LL;
::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	return 0;
}
