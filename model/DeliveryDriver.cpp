//
//  DeliveryDriver.cpp
//  FoodDeliverSystem
//
//  Created by _ on 12/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "DeliveryDriver.hpp"
#include "../utils/StringUtil.hpp"
#include <iostream>

namespace zfq {
	DeliveryDriver::DeliveryDriver():Person(),mDeliveryDriverId(0)
	{
		
	}
	
	DeliveryDriver::DeliveryDriver(const long deliveryDriverId, const string &jsonArrayStr)
	{
		this->mDeliveryDriverId = deliveryDriverId;
		zfq::split(jsonArrayStr, ",", this->mRestaurantIds);
	}
	
	DeliveryDriver::DeliveryDriver(const DeliveryDriver &deliveryDriver):Person(deliveryDriver)
	{
		mDeliveryDriverId = deliveryDriver.mDeliveryDriverId;
		mRestaurantIds = deliveryDriver.mRestaurantIds;
	}
	
	DeliveryDriver::~DeliveryDriver()
	{
		
	}
	
	DeliveryDriver & DeliveryDriver::operator=(const DeliveryDriver &deliveryDriver)
	{
		if (this == &deliveryDriver) {
			return *this;
		}
		
		Person::operator=(deliveryDriver);
		mDeliveryDriverId = deliveryDriver.mDeliveryDriverId;
		mRestaurantIds = deliveryDriver.mRestaurantIds;
		return *this;
	}
	
	const long DeliveryDriver::getDeliveryDriverId()
	{
		return mDeliveryDriverId;
	}
	
	void DeliveryDriver::setDeliveryDriverId(const long deliveryDriverId)
	{
		this->mDeliveryDriverId = deliveryDriverId;
	}
	
	const vector<string> DeliveryDriver::getRestaurantIds()
	{
		return mRestaurantIds;
	}
	
	void DeliveryDriver::setRestaurantIds(const string &restaurantIds)
	{
		split(restaurantIds, ",", this->mRestaurantIds);
	}
	
	void DeliveryDriver::description()
	{
		std::cout
		<< "<DeliveryDriver:" << this
		<< "{"
		<< "deliveryDriverId:" << (mDeliveryDriverId)
		<< " restaurantIds:" << stringFromArray(mRestaurantIds)
		<< "}>\n";
	}
}
