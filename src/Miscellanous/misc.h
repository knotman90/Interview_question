#include <gtest/gtest.h>
#include <algorithm/algorithm.h>
//-----------------------------------------------------------------------------
/*
QUESTION:
Given a time (Hours:Minutes) compute the angle between the two clock hands
The angle is clockwise
*/

double clockAngle(int H, int M){
	double alpha_12_H  = (360 * H)/12;
	double alpha_12_M  = (360 * M)/60;
	return DSL::max(alpha_12_H,alpha_12_M) - DSL::min(alpha_12_H,alpha_12_M);
	return 0.0;
}
TEST(misc,angleBetweenHoursMinutes){
	int H;
	int M;

	//zero angle
	H=0;
	M=0;
	ASSERT_DOUBLE_EQ(clockAngle(H,M),0.0d);

	//90 angle
	H=0;
	M=15;
	ASSERT_DOUBLE_EQ(clockAngle(H,M),90.0d);

	//90 angle
	H=7;
	M=50;
	ASSERT_DOUBLE_EQ(clockAngle(H,M),90.0d);

	//180 angle
	H=4;
	M=50;
	ASSERT_DOUBLE_EQ(clockAngle(H,M),180.0d);
    H=0;
	for(int i=0;i<60;i++){
		M=i;
		ASSERT_DOUBLE_EQ(clockAngle(H,M),(360/60)*i);
	}

}

//-----------------------------------------------------------------------------

/*
QUESTION:
Given a time (Hours:Minutes:Seconds) compute the angle between the two clock hands
considering that hands are moving continously!
*/

TEST(LinkedList,angleClock_moving_continously){
	ASSERT_EQ(1,0);
}



//-----------------------------------------------------------------------------
