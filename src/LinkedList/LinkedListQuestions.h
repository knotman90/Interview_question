#include <gtest/gtest.h>
#include<algorithm/algorithm.h>
#include <list/SingleLinkedList.h>

#include<map>

//append all the number between [start,start+size)
void initializeList(int size, int start, DSL::SingleLinkedList<int> &L1){
	for(int i=0;i<size;i++){

		L1.append(start+i);
	}
}
//----------------------------------------------------------------------------
/*
Given two list of the same type produce a third list
that is the union of the other two. Duplicate elements should appear
only once in the final list.
*/

/**
Complexity: Time O(log(|L1|) + log(|l2|) + |L1|+|L2|) = O(n)
			Space O(|L1|+|L2|)
*/
template<class T>
void listUnioneSmarter(DSL::SingleLinkedList<T> &L1, DSL::SingleLinkedList<T> &L2, DSL::SingleLinkedList<T> &L3){
	std::map<T , int> counters;
	auto f = [&](const T& val) {
		if(counters.find(val) != counters.end())
			counters[val]++;
		else
			counters[val] = 1;
	};
	DSL::for_each(L1.begin(), L1.end() , f);
	DSL::for_each(L2.begin(), L2.end() , f);
	DSL::for_each(counters.begin(), counters.end() , [&](auto it){
		L3.append(it.first);
	}	);
	//DSL::print(L3.begin(),L3.end());
}

/**
Complexity: Time O(|L1|^2 + |L2|^2)
			Space O(1)
*/
template<class T>
void listUnioneNaive(DSL::SingleLinkedList<T> &L1, DSL::SingleLinkedList<T> &L2, DSL::SingleLinkedList<T> &L3){
	auto f = [&](const T& val) {
		if(!DSL::contains(L3.begin(), L3.end(), val)){
			L3.append(val);
		}
	};
	DSL::for_each(L1.begin(), L1.end() , f);
	DSL::for_each(L2.begin(), L2.end() , f);
}

template<typename UnionFunction>
void testUnion(const int SIZE, UnionFunction uf ){
	//unione of two equal lists = one list
		DSL::SingleLinkedList<int> L1;
		initializeList(SIZE,0,L1);
		DSL::SingleLinkedList<int> L2;
		initializeList(SIZE,0,L2);
		DSL::SingleLinkedList<int> L3;

		ASSERT_EQ(false,L3==L1);
		ASSERT_EQ(false,L3==L2);
		uf(L1,L2,L3);
		ASSERT_EQ(true,L3==L1);
		ASSERT_EQ(true,L3==L2);
		ASSERT_EQ(SIZE,L3.size());

		L1.clear();
		L3.clear();
		initializeList(SIZE,SIZE,L1);
		//now l1 and L2 have empty intersection
		uf(L1,L2,L3);
	//DSL::print(L1.begin(), L1.end());
	//DSL::print(L3.begin(), L3.end());
		ASSERT_EQ(true,L3 !=L1 );
		ASSERT_EQ(true,L3 !=L2 );
		ASSERT_EQ(L1.size() + L2.size(),L3.size());

		//intersection not empty
		L1.clear();
		L3.clear();
		initializeList(SIZE,SIZE/2,L1);
		uf(L1,L2,L3);
		ASSERT_EQ(L1.size() + L2.size()-SIZE/2,L3.size());


}
TEST(LinkedList,LinkedList_UNION_naive){
	testUnion(1000, listUnioneNaive<int>);
}
TEST(LinkedList,LinkedList_UNION_smarter){
	testUnion(1000, listUnioneSmarter<int>);
}


//----------------------------------------------------------------------------
/*
Given two list of the same type produce a third list
which elements make up the INTERSECTION between of the other two.
Duplicate elements should appear only once in the final list.
*/


/**
Complexity: Time O(|L1|^2 + |L2|^2)
			Space O(1)
*/
template<class T>
void listIntersectionNaive(DSL::SingleLinkedList<T> &L1, DSL::SingleLinkedList<T> &L2, DSL::SingleLinkedList<T> &L3){
	auto f = [&](const T& val) {
		if(DSL::contains(L2.begin(), L2.end(), val) && !DSL::contains(L3.begin(), L3.end(), val)){
			L3.append(val);
		}
	};
	DSL::for_each(L1.begin(), L1.end() , f);

}


template<typename UnionFunction>
void testIntersection(const int SIZE, UnionFunction uf ){
	//unione of two equal lists = one list
		DSL::SingleLinkedList<int> L1;
		initializeList(SIZE,0,L1);
		DSL::SingleLinkedList<int> L2;
		initializeList(SIZE,0,L2);
		DSL::SingleLinkedList<int> L3;

		ASSERT_EQ(false,L3==L1);
		ASSERT_EQ(false,L3==L2);
		uf(L1,L2,L3);
		ASSERT_EQ(true,L3==L1);
		ASSERT_EQ(true,L3==L2);
		ASSERT_EQ(SIZE,L3.size());

		L1.clear();
		L3.clear();
		initializeList(SIZE,SIZE,L1);
		//now l1 and L2 have empty intersection
		uf(L1,L2,L3);
//	DSL::print(L1.begin(), L1.end());
//DSL::print(L2.begin(), L2.end());
//	DSL::print(L3.begin(), L3.end());
		ASSERT_EQ(true,L3 !=L1 );
		ASSERT_EQ(true,L3 !=L2 );
		ASSERT_EQ(L3.isEmpty(),true);

		//intersection not empty
		L1.clear();
		L3.clear();
		initializeList(SIZE,SIZE/2,L1);
		uf(L1,L2,L3);
		ASSERT_EQ(SIZE/2,L3.size());


}



TEST(LinkedList,LinkedList_INTERSECTION_naive){
	testIntersection(10, listIntersectionNaive<int>);
}
TEST(LinkedList,LinkedList_INTERSECTION_smarter){
//	testIntersection(10000, listIntersectionSmarter<int>);
}
