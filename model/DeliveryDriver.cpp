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
	DeliveryDriver::DeliveryDriver():Person(),deliveryDriverId(0)
	{
		
	}
	
	DeliveryDriver::DeliveryDriver(const long deliveryDriverId, const string &jsonArrayStr)
	{
		this->deliveryDriverId = deliveryDriverId;
		zfq::split(jsonArrayStr, ",", this->restaurantIds);
	}
	
	DeliveryDriver::DeliveryDriver(const DeliveryDriver &deliveryDriver):Person(deliveryDriver)
	{
		deliveryDriverId = deliveryDriver.deliveryDriverId;
		restaurantIds = deliveryDriver.restaurantIds;
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
		deliveryDriverId = deliveryDriver.deliveryDriverId;
		restaurantIds = deliveryDriver.restaurantIds;
		return *this;
	}
	
	const long DeliveryDriver::getDeliveryDriverId()
	{
		return deliveryDriverId;
	}
	
	void DeliveryDriver::setDeliveryDriverId(const long deliveryDriverId)
	{
		this->deliveryDriverId = deliveryDriverId;
	}
	
	const vector<string> DeliveryDriver::getRestaurantIds()
	{
		return restaurantIds;
	}
	
	void DeliveryDriver::setRestaurantIds(const string &restaurantIds)
	{
		split(restaurantIds, ",", this->restaurantIds);
	}
	
	void DeliveryDriver::description()
	{
		std::cout
		<< "<DeliveryDriver:" << this
		<< "{"
		<< "deliveryDriverId:" << (this->deliveryDriverId)
		<< " restaurantIds:" << stringFromArray(restaurantIds)
		<< "}>\n";
	}
}
