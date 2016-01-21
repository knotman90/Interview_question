#include <gtest/gtest.h>
#include <memory/ScopedPointer.h>

double squareroot(const double a){
 return 2;
}

TEST(SQROOT,one){
	EXPECT_EQ (2, squareroot(1.0));
	EXPECT_EQ(1,squareroot(2.0));
}

int main(int argc, char** argv){
::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

return 0;
}
