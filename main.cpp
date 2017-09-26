//
//  main.cpp
//  FoodDeliverSystem
//
//  Created by _ on 12/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include <iostream>
#include "testCase/TestCase.hpp"
// #include "thirdParty/mySqlConn/include/mysql_driver.h"
// #include "thirdParty/mySqlConn/include/mysql_connection.h"

int main(int argc, const char * argv[]) {
	
	// zfq::testCreateDatabase();
	// zfq::testCreateTable();

    zfq::testUser();
    std::cout << "=======\n";
    zfq::testRestaurantAgent();
    // sql::mysql::MySQL_Driver *driver;
    // sql::Connection *con;

    // driver = sql::mysql::get_mysql_driver_instance();
    // con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");

    // delete con;

	return 0;
}



