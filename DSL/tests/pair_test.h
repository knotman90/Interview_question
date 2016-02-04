/*
 * pair.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

 #ifndef PAIR_TEST_H_
 #define PAIR_TEST_H_

#include <utility/pair.h>
#include <string.h>

 TEST(PAIR, equality){
    DSL::pair<std::string,double> p1("hello",0.123);
    DSL::pair<std::string,double> p2("hello",0.123);
    bool eq = p1==p2;
    ASSERT_EQ(true,eq);
    p1.first = "firsthaschanged";

    eq = p1==p2;
    ASSERT_EQ(false,eq);

    p1.first="hello";

    p1.second = 0.124;
    eq = p1==p2;
    ASSERT_EQ(false,eq);

    //bith first and second different
    p1.first = "firsthaschangedagain";

    eq = p1==p2;
    ASSERT_EQ(false,eq);

 }

 TEST(PAIR, OPERATOR_EQUAL){
    DSL::pair<std::string,double> p1("first1",1.1);
    DSL::pair<std::string,double> p2("first2",2.1);
    DSL::pair<std::string,double> p3("",0);
    p3=p1;
    bool eq = (p3==p1);
    ASSERT_EQ(true,eq);

    p2=p3;
    eq = (p3==p1) && (p1 == p2) && (p2 == p3);

    ASSERT_EQ(true,eq);

 }


 TEST(PAIR, swap){
    DSL::pair<std::string,double> p1("first1",1.1);
    DSL::pair<std::string,double> p2("first2",2.1);

    DSL::pair<std::string,double> p3(p1);
    DSL::pair<std::string,double> p4(p2);
    ASSERT_EQ(true,(p1==p3));
    ASSERT_EQ(true,(p2==p4));

    DSL::swap(p1,p2);
    ASSERT_EQ(false,(p1==p3));
    ASSERT_EQ(false,(p2==p4));
    
    ASSERT_EQ(true,(p1==p4));
    ASSERT_EQ(true,(p2==p3));

 }





 #endif /* PAIR_TEST_H_ */
