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
		/** 订单创建/提交成功 */
		OrderStatusCreateSucceed,
		/** 订单已被用户取消 */
		OrderStatusUserCancelled,
		/** 订单已被商家取消 */
		OrderStatusRestaurantCancelled,
		/** 订单已支付 */
		OrderStatusPaid,
		/** 商家已接单 */
		OrderStatusRestaurantAccepted,
		/** 骑手已接单 */
		OrderStatusDriverAccepted,
		/** 开始配送 */
		OrderStatusInDistribution,
		/** 已完成 */
		OrderStatusComplete,
		/** 配送失败 */
		OrderStatusFailed
	};
	
	class Order : public BaseObject
	{
	public:
		/** 订单状态的个数，目前只有9种状态 */
		static const int NumberOfOrderStatus = 9;
		
	private:
		
		/** 订单id 主键*/
		long mOrderId;
		
		/** 商家id */
		long mRestaurantId;
		
		/** 用户id */
		long mUserId;
		
		/** 配送员id */
		long mDeliveryDriverId;
		
		/** 订单状态 */
		OrderStatus mOrderStatus;
		
		/** 每个订单状态对应的修改时间戳 */
		string *mStatusModifiedDate;
		
		void initMemberVariables(const Order &);
		
	public:
		Order();
		Order(const Order &);
		~Order();
		
		Order & operator=(const Order &);
		
		long getOrderId() const;
		void setOrderId(const long orderId);

		long getRestaurantId() const;
		void setRestaurantId(const long restaurantId);

		long getUserId() const;
		void setUserId(const long userId);

		long getDeliveryDriverId() const;
		void setDeliveryDriverId(const long deliveryDriverId);
		
		OrderStatus getOrderStatus() const;
		void setOrderStatus(const OrderStatus orderStatus);
		
		string * getStatusModifiedDate() const;
		
		virtual void description();
	};
}

#endif /* Order_hpp */
