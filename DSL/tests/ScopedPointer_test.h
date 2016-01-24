#include <gtest/gtest.h>
#include <memory/ScopedPointer.h>


class ScopedPointerTest : public ::testing::Test {
protected:
	DSL::ScopedPointer<int> p;
	ScopedPointerTest() : p(new int) {}
	void setUp(){
		*p=rand()%100+1;
	}
};

void nullscopedPointer(){

	{
		DSL::ScopedPointer<int> p (nullptr);
	}
}

TEST(SCOPED_POINTER,NULL_POINTER_TEST){
	ASSERT_NO_FATAL_FAILURE(nullscopedPointer());
}

TEST_F(ScopedPointerTest,DEREFERENCING){
	ASSERT_NE(0,*p);
	*p=0;
	ASSERT_EQ(0,*p);
}
