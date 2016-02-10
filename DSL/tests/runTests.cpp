#include <iostream>

//#include <ScopedPointer_test.h>

#include <LinkedList_test.h>
#include <pair_test.h>
#include<DoubleLinkedList_test.h>
//#include <list/DoubleLinkedList.h>
#include<vector/vector.h>

int main(int argc, char** argv){
DSL::SingleLinkedList<int> LL;
DSL::DoubleLinkedList<int> DL;
DSL::vector<int> V;
::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	return 0;
}
