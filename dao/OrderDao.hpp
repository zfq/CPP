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
#include "../model/Order.hpp"

namespace zfq {
	class OrderDao
	{
	public:
		OrderDao();
		OrderDao(const OrderDao &);
		bool createTable();
		bool insert(const Order &order);
		bool deleteObj(int id);
		bool update(const Order &order);
		std::vector<Order> getAll();
		const Order & getById(long id);
	};
}
#endif /* OrderDao_hpp */
