#include <gtest/gtest.h>
#include <list/SingleLinkedList.h>


//append all the number between [start,start+size)
void initializeList(int size, int start, DSL::SingleLinkedList<int> &L1){
	for(int i=0;i<size;i++){

		L1.append(start+i);
	}
}

/*
Given two list of the same type produce a third list
that is the union of the other two. Duplicate elements should appear
only once in the final list.
*/

void listUnion(DSL::SingleLinkedList<int> &L1, DSL::SingleLinkedList<int> &L2, DSL::SingleLinkedList<int> &L3){

}
TEST(LinkedList,LinkedList_UNION){
	const int SIZE=100;
	DSL::SingleLinkedList<int> L1;
	initializeList(100,0,L1);
	DSL::SingleLinkedList<int> L2;
	initializeList(100,1,L2);
	DSL::SingleLinkedList<int> L3;

	ASSERT_EQ(true,L1==L2);
}


TEST(LinkedList,LinkedList_INTERSECTION){
	ASSERT_EQ(1,1);
}
