//
//  ConnectionProvider.hpp
//  FoodDeliverSystem
//
//  Created by _ on 27/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef ConnectionProvider_hpp
#define ConnectionProvider_hpp

#include <stdio.h>
#include "../thirdParty/mySqlConn/include/mysql_driver.h"
#include "../thirdParty/mySqlConn/include/cppconn/statement.h"
#include "../thirdParty/mySqlConn/include/mysql_connection.h"

namespace zfq {
    class ConnectionProvider
    {
    private:
        ConnectionProvider(){}
    public:
        static ConnectionProvider* getSharedInstance()
        {
            static ConnectionProvider *sharedInstance;
            if (sharedInstance == NULL) {
                sharedInstance = new ConnectionProvider();
            }
            return sharedInstance;
        }

        static sql::Connection * getSqlConnection()
        {
            ConnectionProvider *sharedInstance = ConnectionProvider::getSharedInstance();
            static sql::Connection *connection;
            if (connection == NULL) {
                sql::mysql::MySQL_Driver *driver;
                driver = sql::mysql::get_mysql_driver_instance();
                connection = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
            }
            return connection;
        }

        static sql::Statement * getSqlStatement()
        {
            sql::Connection *conn = ConnectionProvider::getSqlConnection();
            static sql::Statement *stmt;
            if (stmt == NULL) {
                stmt = conn->createStatement();
            }
            return stmt;
        }
        
        static void release()
        {
            sql::Statement *stmt = ConnectionProvider::getSqlStatement();
            if (stmt) {
                delete stmt;
                stmt = NULL;
            }

            sql::Connection *conn = ConnectionProvider::getSqlConnection();
            if (conn){
                delete conn;
                conn = NULL;
            }

            ConnectionProvider *sharedInstance = ConnectionProvider::getSharedInstance();
            if (sharedInstance) {
                delete sharedInstance;
                sharedInstance = NULL;
            }
        }
        
    };
}
#endif /* ConnectionProvider_hpp */
