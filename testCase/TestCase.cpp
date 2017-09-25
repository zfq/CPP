//
//  TestCase.cpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "TestCase.hpp"
#include "../thirdParty/rapidjson/document.h"
#include "../model/DeliveryDriver.hpp"
#include "../model/Restaurant.hpp"
#include "../utils/StringUtil.hpp"
#include "../model/Comment.hpp"
#include "../model/Reply.hpp"
#include "../base/Person.hpp"
#include "../model/Order.hpp"
#include "../model/User.hpp"
#include "../model/Dish.hpp"
#include "../thirdParty/mySqlConn/include/mysql_driver.h"
#include "../thirdParty/mySqlConn/include/cppconn/statement.h"
#include "../thirdParty/mySqlConn/include/mysql_connection.h"
#include <iostream>
#include <string>

namespace zfq {
	
	void testJson()
	{
		const char *str = "[\"2011\", \"2012\", \"2013\"]";
		rapidjson::Document d;
		d.Parse(str);
		if (d.HasParseError()) {
			return;
		}
		
		rapidjson::Value &v = d;
		if (v.IsArray()) {
			for(rapidjson::SizeType i = 0; i < v.Size(); i++) {
				rapidjson::Value & tmpV = v[i];
				std::cout << tmpV.GetString() << "\n";
			}
		}
	}
	
	void testSplit()
	{
		string originStr = "2011,2012,2013";
		string sepa = ",";
		std::vector<std::string> result;
		
		zfq::split(originStr, sepa, result);
		
		for (std::vector<int>::size_type i = 0; i < result.size(); i++) {
			std::cout << result.at(i) << "-";
		}
	}
	
	Person testReturn()
	{
		return Person("张三", "13141187980", Female);
	}
	
	void testPerson()
	{
		Person p;
		p.description();
		
		//	p = Person("张三", "13141187980", Female);
		//	p.description();
		
		p = testReturn();
		p.description();
	}
	
	void testDeliveryDriver()
	{
		DeliveryDriver deli(111, "123,456,678,543");
		deli.description();
	}
	
	void testOrder()
	{
		Order o;
		o.description();
	}
	
	void testUser()
	{
		User u;
		
		u.setName("赵富强");
		u.setMobile("13141187980");
		u.setGender(Male);
		u.setUserId(12345);
		u.setNickName("无助的tom");
		u.setMail("1586687169@mail.com");
		u.setAvatarId("2011-sdfsd");
		u.setPassword("qwer1234");
		
		User abc;
		abc = u;
		abc.description();
	}
	
	void testRestaurant()
	{
		Restaurant r;
		r.setRestaurantId(111);
		Person p("张三", "1586686129", Female);
		r.setAgent(p);
		r.setRestaurantType(RestaurantTypeHotPot);
		r.setAddress("河南省 周口市");
		r.description();
	}
	
	void testDish()
	{
		Dish d;
		d.setRestaurantId(2011234);
		d.setDishName("大盘鸡");
		d.setDishType(DishTypeSiCuanCuisine);
		d.setDishDesciption("我们都-死+87*..."); //鸡肉+土豆+面条的菜...
		d.setDishImgIds("o2o-2324444,o2o-456667,o2o-wewewe");
		d.description();
	}
	
	void testComment()
	{
		Comment c;
		c.setOrderId(4444);
		c.setRestaurantId(1234);
		c.setAuthorId(2222);
		c.setCommentDate("2011-11-12 8:45");
		c.setContent("水电费水电费");
		c.setImgIds("o2o-2333,o2o-4455,o2o-4545");
		c.setScore(4.5);
		c.description();
	}
	
	void testRelpy()
	{
		Reply r;
		r.setOrderId(22222);
		r.setRestaurantId(1234);
		r.setTargetAuthorId(2222);
		r.setCommentDate("2011-11-12 8:45");
		r.setContent("水电费水电费");

		r.description();
	}

	void deleteStmt(sql::Statement *stmt)
	{
		if (stmt != NULL) {
			delete stmt;
			stmt = NULL;
		}
	}

	void deleteConn(sql::Connection *con)
	{
		if (con != NULL) {
			delete con;
			con = NULL;
		}
	}

	void executeSql(const char* sqlArray[] , int sqlArraySize)
	{
		sql::mysql::MySQL_Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		try {
			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
			stmt = con->createStatement();

			for (int i = 0; i < sqlArraySize; i++) {
				stmt->execute(sqlArray[i]);
			}

			deleteStmt(stmt);
			deleteConn(con);
		} catch (sql::SQLException &e){
			std::cout << "出错了:" << e.what() << "\n";

			deleteStmt(stmt);
			deleteConn(con);
		}
	}

	void testDropDatabase()
	{
		const char *sqlArray[] = {"DROP DATABASE foodDeleverSystem"};
		executeSql(sqlArray,1);
	}

	void testCreateDatabase()
	{
		const char *sqlArray[] = {"CREATE DATABASE IF NOT EXISTS foodDeleverSystem CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;"};
		executeSql(sqlArray,1);
	}
	
	void testCreateTable()
	{
		const char *sql1 = "USE foodDeleverSystem";

		//菜单
		const char *createDishSql = 
				"CREATE TABLE IF NOT EXISTS food_delivery_system_dish (" 
				"restaurantId BIGINT UNSIGNED,"
				"dishName VARCHAR(400),"
				"dishType SMALLINT UNSIGNED,"
				"dishDesciption VARCHAR(1000),"
				"dishImgIds VARCHAR(2000)"
				") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";

		//用户
		const char *createUserSql = 
				"CREATE TABLE IF NOT EXISTS food_delivery_system_user (" 
				"userId BIGINT UNSIGNED AUTO_INCREMENT,"
				"nickName VARCHAR(400),"
				"avatarId VARCHAR(100),"
				"mail VARCHAR(80),"
				"password VARCHAR(20),"
				"PRIMARY KEY (userId)"
				") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";

		//餐馆
		const char *createRestaurantSql = 
				"CREATE TABLE IF NOT EXISTS food_delivery_system_restaurant (" 
				"restaurantId BIGINT UNSIGNED AUTO_INCREMENT,"
				"restaurantType SMALLINT UNSIGNED,"
				"agentId BIGINT UNSIGNED,"
				"address VARCHAR(400),"
				"PRIMARY KEY (restaurantId)"
				") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";

		//订单
		const char *createOrderSql = 
				"CREATE TABLE IF NOT EXISTS food_delivery_system_order (" 
				"orderId BIGINT UNSIGNED AUTO_INCREMENT,"
				"restaurantId BIGINT UNSIGNED,"
				"userId BIGINT UNSIGNED,"
				"deliveryDriverId BIGINT UNSIGNED,"
				"orderStatus TINYINT UNSIGNED,"
				"PRIMARY KEY (orderId)"
				") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";

		//评论
		const char *createCommentSql = 
				"CREATE TABLE IF NOT EXISTS food_delivery_system_comment (" 
				"orderId BIGINT UNSIGNED,"
				"authorId BIGINT UNSIGNED,"
				"restaurantId BIGINT UNSIGNED,"
				"commentDate VARCHAR(100),"
				"content VARCHAR(400),"
				"imgIds VARCHAR(2000)"
				") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";

		//回复
		const char *createReplySql = 
				"CREATE TABLE IF NOT EXISTS food_delivery_system_reply (" 
				"orderId BIGINT UNSIGNED,"
				"restaurantId BIGINT UNSIGNED,"
				"targetAuthorId BIGINT UNSIGNED,"
				"commentDate VARCHAR(100),"
				"content VARCHAR(400)"
				") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";

		//配送员
		const char *createDeliveryDriverSql = 
				"CREATE TABLE IF NOT EXISTS food_delivery_system_delivery_driver (" 
				"deliveryDriverId BIGINT UNSIGNED AUTO_INCREMENT,"
				"restaurantId BIGINT UNSIGNED,"
				"PRIMARY KEY (deliveryDriverId)"
				") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";
		const char * sqlArray[] = {sql1, createDishSql, createUserSql, createRestaurantSql, createOrderSql, createCommentSql, createReplySql, createDeliveryDriverSql};
		executeSql(sqlArray,8);
	}
}
