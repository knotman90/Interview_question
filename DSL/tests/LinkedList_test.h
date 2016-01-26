#include <gtest/gtest.h>
#include <list/SingleLinkedList.h>


class SinleLinkedListTest : public ::testing::Test {

protected:
const int SIZE = 1000;

DSL::SingleLinkedList<int> LL;

void SetUp(){
    int a=3;
    int DIM = SIZE;
    int i =1;
    while(DIM--){
        a = DIM;
        LL.append(a);
    }
}

};

TEST_F(SinleLinkedListTest, takeFirst){
    ASSERT_EQ(LL.size(),SIZE);
    int i = SIZE;
    while(i){

        ASSERT_EQ(LL.size(),i);
        int v=LL.takeFirst();
        i--;


    }

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
