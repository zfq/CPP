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
#include "../thirdParty/mySqlConn/include/mysql_driver.h"
#include "../thirdParty/mySqlConn/include/cppconn/statement.h"
#include "../thirdParty/mySqlConn/include/mysql_connection.h"

namespace zfq {
	class BaseDao : public BaseObject
	{
	public:
		BaseDao();
		BaseDao(const BaseDao &);
		~BaseDao();

		void releaseStmt(sql::Statement *stmt);
		void releaseConn(sql::Connection *con);

		bool executeSql(const char* sqlArray[] , int sqlArraySize);
	};
}
#endif /* BaseDao_hpp */
