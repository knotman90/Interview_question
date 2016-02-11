
#include <gtest/gtest.h>
#include <vector/vector.h>
#include <algorithm/algorithm.h>



using ::testing::TestWithParam;
using ::testing::Values;

class vectorTest : public ::testing::TestWithParam<int> {

protected:
int SIZE = 10000;

DSL::vector<int,uint> V;

void SetUp(){
        SIZE=GetParam();
        int a;
        int DIM = SIZE;
        while(DIM--) {
                a = DIM;

        }
}

};
// Here, we instantiate our tests with a list of two PrimeTable object
// factory functions:
INSTANTIATE_TEST_CASE_P(
        size_vector,
        vectorTest,
        //Values(0 , 1 , 2 , 3 , 5 , 10 , 100 ,1000 , 10000 )
        Values( 10, 11, 12, 13,10, 50 )
        );

TEST_P(vectorTest, size){
    ASSERT_EQ(V.capacity(),1);
    ASSERT_EQ(V.size(),0);
    int oldsize= V.capacity();
    V.push_back(1);
    V.push_back(1);
    ASSERT_EQ(V.capacity(),2*oldsize);



}
