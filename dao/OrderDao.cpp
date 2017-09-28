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
	
	OrderDao::OrderDao():BaseDao()
	{

	}

	OrderDao::OrderDao(const OrderDao &orderDao):BaseDao()
	{

	}

	bool OrderDao::createTable()
	{
		const char *sql1 = "USE foodDeleverSystem";
		const char *createOrderSql = 
				"CREATE TABLE IF NOT EXISTS food_delivery_system_order (" 
				"orderId BIGINT UNSIGNED AUTO_INCREMENT,"
				"restaurantId BIGINT UNSIGNED,"
				"userId BIGINT UNSIGNED,"
				"deliveryDriverId BIGINT UNSIGNED,"
				"orderStatus TINYINT UNSIGNED,"
				"createSucceedDate DATETIME,"
				"userCancelledDate DATETIME,"
				"restaurantCancelledDate DATETIME,"
				"paidDate DATETIME,"
				"restaurantAcceptedDate DATETIME,"
				"driverAcceptedDate DATETIME,"
				"inDistributionDate DATETIME,"
				"completeDate DATETIME,"
				"failedDate DATETIME,"
				"PRIMARY KEY (orderId)"
				") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";
		const char * sql[] = {sql1, createOrderSql};
		return BaseDao::executeSql(sql, 2);
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
