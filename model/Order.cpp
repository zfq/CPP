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
	
	Order::Order():BaseObject(),mOrderId(0),mRestaurantId(0),mUserId(0),mDeliveryDriverId(0),mOrderStatus(OrderStatusCreateSucceed),mStatusModifiedDate(NULL)
	{
		mStatusModifiedDate = new string[NumberOfOrderStatus];
		for (int i = 0; i < NumberOfOrderStatus; i++) {
			mStatusModifiedDate[i] = "";
		}
	}
	
	Order::Order(const Order &order):BaseObject(),mStatusModifiedDate(NULL)
	{
		initMemberVariables(order);
	}
	
	Order::~Order()
	{
		if (mStatusModifiedDate != NULL) {
			delete[] mStatusModifiedDate;
			mStatusModifiedDate = NULL;
		}
	}
	
	void Order::initMemberVariables(const Order &order)
	{
		mOrderId = order.mOrderId;
		mRestaurantId = order.mRestaurantId;
		mUserId = order.mUserId;
		mDeliveryDriverId = order.mDeliveryDriverId;
		mOrderStatus = order.mOrderStatus;
		
		if (mStatusModifiedDate == NULL) {
			mStatusModifiedDate = new string[NumberOfOrderStatus];
		}
		
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
	
	long Order::getOrderId() const
	{
		return mOrderId;
	}
	
	void Order::setOrderId(const long orderId)
	{
		this->mOrderId = orderId;
	}
	
	long Order::getRestaurantId() const
	{
		return mRestaurantId;
	}

	void Order::setRestaurantId(const long restaurantId)
	{
		mRestaurantId = restaurantId;
	}

	long Order::getUserId() const
	{
		return mUserId;
	}
	
	void Order::setUserId(const long userId)
	{
		this->mUserId = userId;
	}
	
	long Order::getDeliveryDriverId() const
	{
		return mDeliveryDriverId;
	}
	
	void Order::setDeliveryDriverId(const long deliveryDriverId)
	{
		this->mDeliveryDriverId = deliveryDriverId;
	}
	
	OrderStatus Order::getOrderStatus() const
	{
		return mOrderStatus;
	}
	
	void Order::setOrderStatus(OrderStatus orderStatus)
	{
		this->mOrderStatus = orderStatus;
	}
	
	string * Order::getStatusModifiedDate() const
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
