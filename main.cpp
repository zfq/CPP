//
//  main.cpp
//  FoodDeliverSystem
//
//  Created by _ on 12/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include <iostream>
//#include "TestCase.hpp"
#include "base/Person.hpp"

int main(int argc, const char * argv[]) {
	
//	zfq::testRelpy();
	std::cout << "Hello world!" << "\n";
	zfq::Person p("张三", "13141187980", zfq::Male);
	p.description();
	return 0;
}



