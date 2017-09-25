//
//  TestCase.hpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef TestCase_hpp
#define TestCase_hpp

#include <stdio.h>

namespace zfq {
	extern void testJson();
	extern void testSplit();

	//base
	extern void testPerson();

	//model
	extern void testDeliveryDriver();
	extern void testOrder();
	extern void testUser();
	extern void testRestaurant();
	extern void testDish();
	extern void testComment();
	extern void testRelpy();

	//dao
	extern void testCreateDatabase();
	extern void testDropDatabase();
	extern void testCreateTable();
}

#endif /* TestCase_hpp */
