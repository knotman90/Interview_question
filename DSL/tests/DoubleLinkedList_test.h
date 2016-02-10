#include <gtest/gtest.h>
#include <list/DoubleLinkedList.h>
#include<algorithm/algorithm.h>




using ::testing::TestWithParam;
using ::testing::Values;

class DoubleLinkedListTest : public ::testing::TestWithParam<int> {

protected:
 int SIZE = 10000 ;

DSL::DoubleLinkedList<int,uint> LL;

void SetUp(){
    SIZE=GetParam();
    int a;
    int DIM = SIZE;
    while(DIM--){
        a = DIM;
        LL.append(a);
    }
}

};

// Here, we instantiate our tests with a list of two PrimeTable object
// factory functions:
INSTANTIATE_TEST_CASE_P(
    size_list,
    DoubleLinkedListTest,
    //Values(0 , 1 , 2 , 3 , 5 , 10 , 100 ,1000 , 10000 )
Values( 10 , 11 , 12, 13,10, 50 )
    );

TEST_P(DoubleLinkedListTest, takeFirst){
    ASSERT_EQ(LL.size(),SIZE);
    int i = SIZE;
    while(i){

        ASSERT_EQ(LL.size(),i);
        int v=LL.takeFirst();
        i--;
    }
    ASSERT_EQ(LL.size(),0);
    ASSERT_EQ(LL.isEmpty(),true);


}


TEST_P(DoubleLinkedListTest, takeLast){
    ASSERT_EQ(LL.size(),SIZE);
    int i = SIZE;
    while(i){

        ASSERT_EQ(LL.size(),i);
        int v=LL.takeLast();
        i--;
    }
    DSL::print(LL.begin(),LL.end());
}










/*
typedef ::testing::Types<char, int, unsigned int> types;
TYPED_TEST_CASE(SingleLinkedListTest, types);

TYPED_TEST(SingleLinkedListTest, INITIALIZATION) {
        typename TestFixture::LL p;
        ASSERT_EQ(p->_head,nullptr);
        ASSERT_EQ(p->_count,(TypeParam)0);

}
*/
