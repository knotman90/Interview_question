/*
 * assert.h
 *
 *  Created on: 24  gen 2016
 *      Author: Davide Spataro
 */
#ifndef ASSERT_H_
#define ASSERT_H_


#ifndef NDEBUG
#include <cassert>
#define DSL_ASSERT( condition) \
do { \
        if(!(condition)) \
        { \
                std::cerr << "Assertion failed at " << __FILE__ << ":" << __LINE__; \
                std::cerr << " inside " << __FUNCTION__ << std::endl; \
                std::cerr << "Condition: " << (condition); \
                abort(); \
        } \
} while(0);
#else
  #define DSL_ASSERT(condition)
#endif

#endif /* ASSERT_H_ */
