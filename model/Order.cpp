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
	
	Order::Order():BaseObject(),orderId(0),restaurantId(0),userId(0),deliveryDriverId(0),orderStatus(OrderStatusNotYetAccepted)
	{
		for (int i = 0; i < NumberOfOrderStatus; i++) {
			statusModifiedDate[i] = "";
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
		orderId = order.orderId;
		restaurantId = order.restaurantId;
		userId = order.userId;
		deliveryDriverId = order.deliveryDriverId;
		orderStatus = order.orderStatus;
		
		for (int i = 0; i < NumberOfOrderStatus; i++) {
			statusModifiedDate[i] = order.statusModifiedDate[i];
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
		return orderId;
	}
	
	void Order::setOrderId(const long orderId)
	{
		this->orderId = orderId;
	}
	
	long Order::getUserId()
	{
		return userId;
	}
	
	void Order::setUserId(const long userId)
	{
		this->userId = userId;
	}
	
	long Order::getDeliveryDriverId()
	{
		return deliveryDriverId;
	}
	
	void Order::setDeliveryDriverId(const long deliveryDriverId)
	{
		this->deliveryDriverId = deliveryDriverId;
	}
	
	OrderStatus Order::getOrderStatus()
	{
		return orderStatus;
	}
	
	void Order::setOrderStatus(OrderStatus orderStatus)
	{
		this->orderStatus = orderStatus;
	}
	
	string * Order::getStatusModifiedDate()
	{
		return statusModifiedDate;
	}
	
	void Order::description()
	{
		string dateStr("[");
		for (int i = 0; i < NumberOfOrderStatus; i++) {
			dateStr += (statusModifiedDate[i] + ",");
		}
		dateStr += "]";
		
		std::cout
		<< "<Order:" << this
		<< "{"
		<< "orderId:" << orderId
		<< " restaurantId:" << restaurantId
		<< " userId:" << userId
		<< " deliveryDriverId:" << deliveryDriverId
		<< " orderStatus:" << orderStatus
		<< " statusModifiedDate:" << dateStr
		<< "}>\n";
	}
	
}
