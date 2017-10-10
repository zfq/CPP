//
//  OrderDao.hpp
//  FoodDeliverSystem
//
//  Created by _ on 17/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef OrderDao_hpp
#define OrderDao_hpp

#include <stdio.h>
#include "BaseDao.hpp"
#include "../model/Order.hpp"

namespace zfq {
	class OrderDao : public BaseDao
	{
	public:
		OrderDao();
		OrderDao(const OrderDao &);

		bool createTable();
		bool insert(const Order &order);
		bool remove(long orderId);
		bool update(const Order &order);
		std::list<Order> getAll();
		/* 从startOrderId起查询number个 */
		std::list<Order> getOrders(long startOrderId, int number, bool ascending);
		const Order getById(long orderId);
	};
}
#endif /* OrderDao_hpp */
