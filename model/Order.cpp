//
//  Order.cpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "Order.hpp"
#include <iostream>

namespace zfq {
	
	Order::Order():BaseObject(),mOrderId(0),mRestaurantId(0),mUserId(0),mDeliveryDriverId(0),mOrderStatus(OrderStatusCreateSucceed)
	{
		for (int i = 0; i < NumberOfOrderStatus; i++) {
			mStatusModifiedDate[i] = "";
		}
	}
	
	Order::Order(const Order &order)
	{
		initMemberVariables(order);
	}
	
	Order::~Order()
	{
		
	}
	
	void Order::initMemberVariables(const Order &order)
	{
		mOrderId = order.mOrderId;
		mRestaurantId = order.mRestaurantId;
		mUserId = order.mUserId;
		mDeliveryDriverId = order.mDeliveryDriverId;
		mOrderStatus = order.mOrderStatus;
		
		for (int i = 0; i < NumberOfOrderStatus; i++) {
			mStatusModifiedDate[i] = order.mStatusModifiedDate[i];
		}
	}
	
	Order & Order::operator=(const Order &order)
	{
		if (this == &order) {
			return *this;
		}
		
		initMemberVariables(order);
		return *this;
	}
	
	long Order::getOrderId()
	{
		return mOrderId;
	}
	
	void Order::setOrderId(const long orderId)
	{
		this->mOrderId = orderId;
	}
	
	long Order::getUserId()
	{
		return mUserId;
	}
	
	void Order::setUserId(const long userId)
	{
		this->mUserId = userId;
	}
	
	long Order::getDeliveryDriverId()
	{
		return mDeliveryDriverId;
	}
	
	void Order::setDeliveryDriverId(const long deliveryDriverId)
	{
		this->mDeliveryDriverId = deliveryDriverId;
	}
	
	OrderStatus Order::getOrderStatus()
	{
		return mOrderStatus;
	}
	
	void Order::setOrderStatus(OrderStatus orderStatus)
	{
		this->mOrderStatus = orderStatus;
	}
	
	string * Order::getStatusModifiedDate()
	{
		return mStatusModifiedDate;
	}
	
	void Order::description()
	{
		string dateStr("[");
		for (int i = 0; i < NumberOfOrderStatus; i++) {
			dateStr += (mStatusModifiedDate[i] + ",");
		}
		dateStr += "]";
		
		std::cout
		<< "<Order:" << this
		<< "{"
		<< "orderId:" << mOrderId
		<< " restaurantId:" << mRestaurantId
		<< " userId:" << mUserId
		<< " deliveryDriverId:" << mDeliveryDriverId
		<< " orderStatus:" << mOrderStatus
		<< " statusModifiedDate:" << dateStr
		<< "}>\n";
	}
	
}
