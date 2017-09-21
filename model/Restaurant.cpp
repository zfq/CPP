//
//  Restaurant.cpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "Restaurant.hpp"
#include <iostream>

namespace zfq {
	Restaurant::Restaurant():BaseObject(),restaurantId(0),restaurantType(RestaurantTypeStapleFood),agent(),address("")
	{
		
	}
	
	Restaurant::Restaurant(const Restaurant &restaurant):BaseObject()
	{
		initMemberVariables(restaurant);
	}
	
	Restaurant::~Restaurant()
	{
		
	}
	
	void Restaurant::initMemberVariables(const Restaurant &restaurant)
	{
		restaurantId = restaurant.restaurantId;
		restaurantType = restaurant.restaurantType;
		agent = restaurant.agent;
		address = restaurant.address;
	}
	
	const long Restaurant::getRestaurantId()
	{
		return restaurantId;
	}
	
	void Restaurant::setRestaurantId(long restaurantId)
	{
		this->restaurantId = restaurantId;
	}
	
	const RestaurantType Restaurant::getRestaurantType()
	{
		return restaurantType;
	}
	
	void Restaurant::setRestaurantType(RestaurantType restaurantType)
	{
		this->restaurantType = restaurantType;
	}
	
	const Person & Restaurant::getAgent()
	{
		return agent;
	}
	
	void Restaurant::setAgent(const Person & agent)
	{
		this->agent = agent;
	}
	
	const string & Restaurant::getAddress()
	{
		return this->address;
	}
	
	void Restaurant::setAddress(const string & address)
	{
		this->address = address;
	}
	
	Restaurant & Restaurant::operator=(const Restaurant &restaurant)
	{
		if (this == &restaurant) {
			return *this;
		}
		
		initMemberVariables(restaurant);
		return *this;
	}
	
	void Restaurant::description()
	{
		std::cout
		<< "<Restaurant:" << this
		<< "{"
		<< "restaurantId:" << restaurantId
		<< " restaurantType:" << restaurantType;
		
		std::cout << " agent:";
		agent.description();
		std::cout << " address:" << address
		<< "}>\n";
	}
}
