/*
 * Utility.h
 *
 *  Created on: 18 gen 2016
 *      Author: knotman
 */

#ifndef UTILITY_H_
#define UTILITY_H_

namespace DSL{

class NonCopiable{
public:
	NonCopiable(){};
private:
	NonCopiable(NonCopiable& c) = delete;
	NonCopiable& operator=(NonCopiable& c) = delete;
};

}



#endif /* UTILITY_H_ */
