//
//  BaseDao.hpp
//  FoodDeliverSystem
//
//  Created by _ on 17/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef BaseDao_hpp
#define BaseDao_hpp

#include <stdio.h>
#include <vector>
#include "../base/BaseObject.hpp"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>

namespace zfq {
	class BaseDao : public BaseObject
	{
	public:
		BaseDao();
		BaseDao(const BaseDao &);
		~BaseDao();

		void releaseStmt(sql::Statement *stmt);
		void releaseConn(sql::Connection *con);

		bool executeSql(const std::string &sql);
		bool executeSql(const char* sqlArray[] , int sqlArraySize);
	};
}
#endif /* BaseDao_hpp */
