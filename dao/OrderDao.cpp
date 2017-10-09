//
//  OrderDao.cpp
//  FoodDeliverSystem
//
//  Created by _ on 17/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "OrderDao.hpp"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/datatype.h>
#include <cppconn/prepared_statement.h>
#include "../utils/StringUtil.hpp"
#include "ConnectionProvider.hpp"
#include <sstream>

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
				"orderStatus INT UNSIGNED,"
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

	void setPreStatementValue(sql::PreparedStatement *prep_stmt, int paramIndex, const string &value)
    {
        if (value.compare("") == 0) {
            prep_stmt->setNull(paramIndex, sql::DataType::SQLNULL);
        } else {
            prep_stmt->setString(paramIndex, value);
        }
    }

    void setPreStatementBigIntValue(sql::PreparedStatement *prep_stmt, int paramIndex, const string &value)
    {
        if (value.compare("0") == 0) {
			prep_stmt->setNull(paramIndex, sql::DataType::SQLNULL);
		} else {
			prep_stmt->setBigInt(paramIndex, value);
		}
    }

	bool OrderDao::insert(const Order &order)
	{
		const char *sql1 = "USE foodDeleverSystem";
		const char * sql[] = {sql1};
		BaseDao::executeSql(sql, 1);

		try {
			sql::Connection *conn = ConnectionProvider::getSqlConnection();
			sql::PreparedStatement *prep_stmt = conn->prepareStatement(
				"INSERT INTO food_delivery_system_order "
				"(restaurantId, userId, deliveryDriverId, orderStatus,"
				"createSucceedDate, userCancelledDate, restaurantCancelledDate, paidDate, restaurantAcceptedDate, driverAcceptedDate, inDistributionDate, completeDate, failedDate)"
				"VALUES (?, ?, ?, ?,  ?,?,?,?,?,?,?,?,?);"
				);

			std::string resIdStr = stringFromInt(order.getRestaurantId());
			std::string userIdStr = stringFromInt(order.getUserId());
			std::string driverIdStr = stringFromInt(order.getDeliveryDriverId());
			
			setPreStatementBigIntValue(prep_stmt, 1, resIdStr);
			setPreStatementBigIntValue(prep_stmt, 2, userIdStr);
			setPreStatementBigIntValue(prep_stmt, 3, driverIdStr);
			prep_stmt->setInt(4, order.getOrderStatus());

			//设置每个状态对应的日期
			std::string *modifiedDate = order.getStatusModifiedDate();
			for (int i = 0 ;i < Order::NumberOfOrderStatus; i++) {
				setPreStatementValue(prep_stmt, 5+i, modifiedDate[i]);
			}

			prep_stmt->execute();
		} catch (sql::SQLException &e) {
			std::cout << "orderDao出错了:" << e.what() << "\n" <<e.getSQLState() << "\n";
            return false;
		}
		
		return true;
	}
	
	bool OrderDao::remove(long orderId)
	{
		ConnectionProvider::getSqlConnection();
		std::string sql = "USE foodDeleverSystem;DELETE FROM food_delivery_system_order WHERE orderId =" + std::to_string(orderId);
		bool result = BaseDao::executeSql(sql);
		return result;
	}
	
	bool OrderDao::update(const Order &order)
	{
		sql::Connection *conn = ConnectionProvider::getSqlConnection();
		BaseDao::executeSql("USE foodDeleverSystem");

		sql::PreparedStatement *prep_stmt = conn->prepareStatement(
			"UPDATE food_delivery_system_order SET restaurantId=?, userId=?, deliveryDriverId=?, orderStatus=?,"
			"createSucceedDate=?, userCancelledDate=?, restaurantCancelledDate=?, paidDate=?, restaurantAcceptedDate=?, driverAcceptedDate=?, inDistributionDate=?, completeDate=?, failedDate=? "
			"WHERE orderId=?"
			);
		std::string resIdStr = stringFromInt(order.getRestaurantId());
		std::string userIdStr = stringFromInt(order.getUserId());
		std::string driverIdStr = stringFromInt(order.getDeliveryDriverId());
		
		setPreStatementBigIntValue(prep_stmt, 1, resIdStr);
		setPreStatementBigIntValue(prep_stmt, 2, userIdStr);
		setPreStatementBigIntValue(prep_stmt, 3, driverIdStr);
		prep_stmt->setInt(4, order.getOrderStatus());

		//设置每个状态对应的日期
		std::string *modifiedDate = order.getStatusModifiedDate();
		for (int i = 0 ;i < Order::NumberOfOrderStatus; i++) {
			setPreStatementValue(prep_stmt, 5+i, modifiedDate[i]);
		}
		prep_stmt->setBigInt(5+Order::NumberOfOrderStatus, stringFromInt(order.getOrderId()));
		prep_stmt->execute();

		return true;
	}
	
	std::list<Order> OrderDao::getAll()
	{
		std::list<Order> v;
		return v;
	}
	
	const Order OrderDao::getById(long orderId)
	{
		sql::Connection *conn = ConnectionProvider::getSqlConnection();
		sql::Statement *stmt = conn->createStatement();;
		sql::ResultSet  *res;
		
		BaseDao::executeSql("USE foodDeleverSystem");

		sql::SQLString sql("SELECT * FROM food_delivery_system_order WHERE orderId = " + std::to_string(orderId));
		res = stmt->executeQuery(sql);

		Order order;
		while (res->next()) {
			order.setOrderId(orderId);
			order.setRestaurantId(res->getUInt64("restaurantId"));
			order.setUserId(res->getUInt64("userId"));
			order.setDeliveryDriverId(res->getUInt64("deliveryDriverId"));
			order.setOrderStatus(static_cast<OrderStatus>(res->getUInt("orderStatus")));

			//设置日期
			std::string *modifiedDate = order.getStatusModifiedDate();
			for (int i = 0; i < Order::NumberOfOrderStatus; i++) {
				modifiedDate[i] = res->getString(i + 6);
			}
		}
		order.description();
		return order;
	}
}
