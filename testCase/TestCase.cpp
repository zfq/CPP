//
//  TestCase.cpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "TestCase.hpp"
// #include "../thirdParty/rapidjson/document.h"
#include "../model/DeliveryDriver.hpp"
#include "../model/Restaurant.hpp"
#include "../utils/StringUtil.hpp"
#include "../model/Comment.hpp"
#include "../model/Reply.hpp"
#include "../base/Person.hpp"
#include "../model/Order.hpp"
#include "../model/User.hpp"
#include "../model/Dish.hpp"
#include <iostream>
#include <string>

namespace zfq {
	
	void testJson()
	{
		// const char *str = "[\"2011\", \"2012\", \"2013\"]";
		// rapidjson::Document d;
		// d.Parse(str);
		// if (d.HasParseError()) {
		// 	return;
		// }
		
		// rapidjson::Value &v = d;
		// if (v.IsArray()) {
		// 	for(rapidjson::SizeType i = 0; i < v.Size(); i++) {
		// 		rapidjson::Value & tmpV = v[i];
		// 		std::cout << tmpV.GetString() << "\n";
		// 	}
		// }
	}
	
	void testSplit()
	{
		string originStr = "2011,2012,2013";
		string sepa = ",";
		std::vector<std::string> result;
		
		zfq::split(originStr, sepa, result);
		
		for (std::vector<int>::size_type i = 0; i < result.size(); i++) {
			std::cout << result.at(i) << "-";
		}
	}
	
	Person testReturn()
	{
		return Person("张三", "13141187980", Female);
	}
	
	void testPerson()
	{
		Person p;
		p.description();
		
		//	p = Person("张三", "13141187980", Female);
		//	p.description();
		
		p = testReturn();
		p.description();
	}
	
	void testDeliveryDriver()
	{
		DeliveryDriver deli(111, "123,456,678,543");
		deli.description();
	}
	
	void testOrder()
	{
		Order o;
		o.description();
	}
	
	void testUser()
	{
		User u;
		
		u.setName("赵富强");
		u.setMobile("13141187980");
		u.setGender(Male);
		u.setUserId(12345);
		u.setNickName("无助的tom");
		u.setMail("1586687169@mail.com");
		u.setAvatarId("2011-sdfsd");
		u.setPassword("qwer1234");
		
		User abc;
		abc = u;
		abc.description();
	}
	
	void testRestaurant()
	{
		Restaurant r;
		r.setRestaurantId(111);
		Person p("张三", "1586686129", Female);
		r.setAgent(p);
		r.setRestaurantType(RestaurantTypeHotPot);
		r.setAddress("河南省 周口市");
		r.description();
	}
	
	void testDish()
	{
		Dish d;
		d.setRestaurantId(2011234);
		d.setDishName("大盘鸡");
		d.setDishType(DishTypeSiCuanCuisine);
		d.setDishDesciption("我们都-死+87*..."); //鸡肉+土豆+面条的菜...
		d.setDishImgIds("o2o-2324444,o2o-456667,o2o-wewewe");
		d.description();
	}
	
	void testComment()
	{
		Comment c;
		c.setOrderId(4444);
		c.setRestaurantId(1234);
		c.setAuthorId(2222);
		c.setCommentDate("2011-11-12 8:45");
		c.setContent("水电费水电费");
		c.setImgIds("o2o-2333,o2o-4455,o2o-4545");
		c.setScore(4.5);
		c.description();
	}
	
	void testRelpy()
	{
		Reply r;
		r.setOrderId(22222);
		r.setRestaurantId(1234);
		r.setTargetAuthorId(2222);
		r.setCommentDate("2011-11-12 8:45");
		r.setContent("水电费水电费");

		r.description();
	}
}
