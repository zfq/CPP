//
//  OrderDao.cpp
//  FoodDeliverSystem
//
//  Created by _ on 17/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "OrderDao.hpp"
#include "../thirdParty/mySqlConn/include/mysql_driver.h"
#include "../thirdParty/mySqlConn/include/cppconn/statement.h"
#include "../thirdParty/mySqlConn/include/mysql_connection.h"

namespace zfq {
	
	OrderDao::OrderDao()
	{

	}

	OrderDao::OrderDao(const OrderDao &orderDao)
	{

	}

	bool OrderDao::createTable()
	{
		
	}

	bool OrderDao::insert(const Order &order)
	{
		return true;
	}
	
	bool OrderDao::deleteObj(int id)
	{
		return true;
	}
	
	bool OrderDao::update(const Order &order)
	{
		return true;
	}
	
	std::vector<Order> OrderDao::getAll()
	{
		std::vector<Order> v;
		return v;
	}
	
	const Order & OrderDao::getById(long id)
	{
		return Order();
	}
}
