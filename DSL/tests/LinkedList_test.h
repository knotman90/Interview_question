#include <gtest/gtest.h>
#include<list/SingleLinkedList.h>

template <typename T>
class SinleLinkedListTest : public ::testing::Test {
protected:

    typename DSL::SingleLinkedList<T> LL;
};

typedef ::testing::Types<char, int, unsigned int> types;
TYPED_TEST_CASE(SingleLinkedListTest, types);

//TYPED_TEST(SingleLinkedListTest, INITIALIZATION) {
//    typename TestFixture::LL p;
//ASSERT_EQ(p->_head,nullptr);
//    ASSERT_EQ(p->_count,(TypeParam)0);

//}
