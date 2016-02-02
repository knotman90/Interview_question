#include <gtest/gtest.h>
#include <list/SingleLinkedList.h>
#include<algorithm/algorithm.h>



class SinleLinkedListTest : public ::testing::Test {

protected:
const int SIZE = 10000 ;

DSL::SingleLinkedList<int,uint> LL;

void SetUp(){
    int a;
    int DIM = SIZE;
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
    ASSERT_EQ(LL.size(),0);
    ASSERT_EQ(LL.isEmpty(),true);


}


TEST_F(SinleLinkedListTest, takeLast){
    ASSERT_EQ(LL.size(),SIZE);
    int i = SIZE;
    while(i){

        ASSERT_EQ(LL.size(),i);
        int v=LL.takeLast();
        i--;
    }

}

TEST_F(SinleLinkedListTest, contains){
    ASSERT_EQ(LL.size(),SIZE);
    int i = SIZE-1;
    while(i){
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
    int np=1;//one is prime count it here
    for(int i=3;i<N;i+=2){
        if(isPrime(i))
            np++;
    }
    return np;
}

//counts the number of primes from 0 to SIZE
TEST_F(SinleLinkedListTest, algorithm_count_if){
        const int NPRIMES=numPrimesUpTo(SIZE); //change according to SIZE
        int val = DSL::count_if(LL.begin() , LL.end() , isPrime<int> );
        printf("\t\tpi([0,%i]) = %i | FOUND = %i\n", SIZE , NPRIMES , val);

        EXPECT_EQ(val, NPRIMES) << "pi([0," <<SIZE<<"]) = "<<NPRIMES<<" | FOUND = "<<val;
    }

TEST_F(SinleLinkedListTest, algorithm_find__if){
    int i = SIZE-1;
    while(i){
        auto f = [&](int val) {return val==i;};
        int val = *( DSL::find_if(LL.begin() , LL.end() , f) );
        ASSERT_EQ(val, i);
        i--;
    }
}

TEST_F(SinleLinkedListTest, algorithm_all_of_any_of){
        int l=0, h=SIZE;
        auto f = [&](const int &val){
            return (val >= l && val <= h);
        };


        bool val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,true);

        bool any = DSL::any_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(any,true);

        //now set h and l out of range
        l =2;//one is out of range because is 0
        val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,false);

        any = DSL::any_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(any,true);

        h =SIZE-1;//one is out of range because is SIZE
        val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,false);

        any = DSL::any_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(any,true);

        l =2;
        h =SIZE-1;
        val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,false);

        any = DSL::any_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(any,true);


        l = -SIZE;
        h = -2*SIZE;

        val = DSL::all_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(val,false);

        any = DSL::any_of(LL.begin() , LL.end() , f);
        ASSERT_EQ(any,false);
}




TEST_F(SinleLinkedListTest, removeOne){
    int i = SIZE;
    while(false){
        ASSERT_EQ(LL.size(),i);
        int v=LL.removeOne(i);
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
