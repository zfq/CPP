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
	Restaurant::Restaurant():BaseObject(),mRestaurantId(0),mRestaurantType(RestaurantTypeStapleFood),mAgentId(0),mAddress("")
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
		mRestaurantId = restaurant.mRestaurantId;
		mRestaurantType = restaurant.mRestaurantType;
		mAgentId = restaurant.mAgentId;
		mAddress = restaurant.mAddress;
	}
	
	const long Restaurant::getRestaurantId()
	{
		return mRestaurantId;
	}
	
	void Restaurant::setRestaurantId(long restaurantId)
	{
		this->mRestaurantId = restaurantId;
	}
	
	const RestaurantType Restaurant::getRestaurantType()
	{
		return mRestaurantType;
	}
	
	void Restaurant::setRestaurantType(RestaurantType restaurantType)
	{
		this->mRestaurantType = restaurantType;
	}
	
	const long Restaurant::getAgentId()
	{
		return mAgentId;
	}
	
	void Restaurant::setAgentId(long agentId)
	{
		this->mAgentId = agentId;
	}
	
	const string & Restaurant::getAddress()
	{
		return this->mAddress;
	}
	
	void Restaurant::setAddress(const string & address)
	{
		this->mAddress = address;
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
		<< "restaurantId:" << mRestaurantId
		<< " restaurantType:" << mRestaurantType
		<< " agent:" << mAgentId
		<< " address:" << mAddress
		<< "}>\n";
	}
}
