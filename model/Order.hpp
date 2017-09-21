//
//  Order.hpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef Order_hpp
#define Order_hpp

#include <stdio.h>
#include "../base/BaseObject.hpp"


namespace zfq {
	
	enum OrderStatus {
		/** 未接单 */
		OrderStatusNotYetAccepted,
		/** 已拒单 */
		OrderStatusRejected,
		/** 已接单 */
		OrderStatusAccepted,
		/** 配送中 */
		OrderStatusInDistribution,
		/** 已完成 */
		OrderStatusComplete
	};
	
	class Order : public BaseObject
	{
	public:
		/** 订单状态的个数，目前只有5种状态 */
		static const int NumberOfOrderStatus = 5;
		
	private:
		
		/** 订单id */
		long orderId;
		
		/** 商家id */
		long restaurantId;
		
		/** 用户id */
		long userId;
		
		/** 配送员id */
		long deliveryDriverId;
		
		/** 订单状态 */
		OrderStatus orderStatus;
		
		/** 每个订单状态对应的修改时间 */
		string statusModifiedDate[NumberOfOrderStatus];
		
		void initMemberVariables(const Order &);
		
	public:
		Order();
		Order(const Order &);
		~Order();
		
		Order & operator=(const Order &);
		
		long getOrderId();
		void setOrderId(const long orderId);
		long getUserId();
		void setUserId(const long userId);
		long getDeliveryDriverId();
		void setDeliveryDriverId(const long deliveryDriverId);
		OrderStatus getOrderStatus();
		void setOrderStatus(const OrderStatus orderStatus);
		
		string * getStatusModifiedDate();
		
		virtual void description();
	};
}

#endif /* Order_hpp */
