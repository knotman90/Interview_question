#include <gtest/gtest.h>
#include <list/SingleLinkedList.h>
#include <algorithm/algorithm.h>




using ::testing::TestWithParam;
using ::testing::Values;

class SinleLinkedListTest : public ::testing::TestWithParam<int> {

protected:
 int SIZE = 10000 ;

DSL::SingleLinkedList<int,uint> LL;

void SetUp(){
    SIZE=GetParam();
    int i=1;
    while(i <= SIZE){ //numbers [0 , SIZE)
        LL.append(i);
        i++;
    }
}

};

// Here, we instantiate our tests with a list of two PrimeTable object
// factory functions:
INSTANTIATE_TEST_CASE_P(
    size_list,
    SinleLinkedListTest,
    Values(0 , 1 , 2 , 3 , 5 , 10 , 100 ,1000 , 10000 )
//Values( 0 , 1 , 2, 3, 6 )
    );

TEST_P(SinleLinkedListTest, takeFirst){
    ASSERT_EQ(LL.size(),SIZE);
    int rem =0;
    int i = 1;

    while(i <= SIZE){
        //std::cout<<"hi\n";
        ASSERT_EQ(LL.size(),SIZE-rem);

        int v=LL.takeFirst();
        rem++;
        ASSERT_EQ(LL.size(),SIZE-rem);
        ASSERT_EQ(v,i);
        i++;

    }
    ASSERT_EQ(LL.size(),0);
    ASSERT_EQ(LL.isEmpty(),true);


}


TEST_P(SinleLinkedListTest, takeLast){
    ASSERT_EQ(LL.size(),SIZE);
    int i = SIZE;
    while(i){

        ASSERT_EQ(LL.size(),i);
        int v=LL.takeLast();
        i--;
    }

}

TEST_P(SinleLinkedListTest, contains){
    ASSERT_EQ(LL.size(),SIZE);
    int i = SIZE-1;
    while(i > 0){
        ASSERT_EQ(true, LL.contains(i));
        i--;
    }
}

template <typename T>
bool isOdd(T num){
    bool lastBit = 0x1 & num;
    return lastBit;
}

template <typename T>
bool isPrime(T num){
    if(!isOdd(num)) //=isEven
        return false;
    int limit = std::sqrt(num)+1;
    for(int i=3;i<limit;i+=2)
        if(num%i == 0)
            return false;

    return true;
}

int numPrimesUpTo(const int N){
    if(N <=0)
        return 0;
    int np=1;//one is prime count it here
    for(int i=3;i<=N;i+=2){
        if(isPrime(i))
            np++;
    }
    return np;
}

//counts the number of primes from 0 to SIZE
TEST_P(SinleLinkedListTest, algorithm_count_if){

        const int NPRIMES=numPrimesUpTo(SIZE); //change according to SIZE
        int val = DSL::count_if(LL.begin() , LL.end() , isPrime<int> );
        printf("\t\tpi([0,%i]) = %i | FOUND = %i\n", SIZE , NPRIMES , val);

        EXPECT_EQ(val, NPRIMES) << "pi([0," <<SIZE<<"]) = "<<NPRIMES<<" | FOUND = "<<val;
    }

TEST_P(SinleLinkedListTest, algorithm_find__if){
    int i = SIZE-1;
    auto f = [&](int val) {return val==i;};
    if(SIZE == 0) {
        auto it =  DSL::find_if(LL.begin() , LL.end() , f);
        ASSERT_EQ(LL.end() , it );
        return;
    }
    while(i){

        int val = *( DSL::find_if(LL.begin() , LL.end() , f) );
        ASSERT_EQ(val, i);
        i--;
    }
}

TEST_P(SinleLinkedListTest, algorithm_any_of){
    int l=0, h=SIZE;
    auto f = [&](const int &val){
        return (val >= l && val <= h);
    };

    if(SIZE==0)
        ASSERT_EQ(DSL::any_of(LL.begin() , LL.end() , f), false);
    else{
        bool any = DSL::any_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(any,true);

    }
}


TEST_P(SinleLinkedListTest, algorithm_all_of_any_of){
    int l=0, h=SIZE;
    auto f = [&](const int &val){
        return (val >= l && val <= h);
    };

    if(SIZE==0){

        ASSERT_EQ( DSL::all_of(LL.begin() , LL.end() , f),true);
        ASSERT_EQ(DSL::any_of(LL.begin() , LL.end() , f), false);
    }else{


        bool val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,true);

            //now set h and l out of range
        l =2;//one is out of range because is 0
        val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,false);



        h =SIZE-1;//one is out of range because is SIZE
        val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,false);



        l =2;
        h =SIZE-1;
        val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,false);

        l = -SIZE;
        h = -2*SIZE;

        val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,false);

    }
}




TEST_P(SinleLinkedListTest, removeOne){

    int i = 0;
    int n_rem =0;
    int original_size=LL.size();
    while(i <= SIZE){
        bool cont = LL.contains(i);
        if(cont)
            ++n_rem;
        bool rem = LL.removeOne(i);
        ASSERT_EQ(rem,cont) << SIZE;
        ASSERT_EQ(LL.size(),original_size-n_rem);
        i++;
    }
    ASSERT_EQ(LL.size(),0);
    ASSERT_EQ(LL.size(),original_size-n_rem);
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
