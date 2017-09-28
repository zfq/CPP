//
//  BaseDao.cpp
//  FoodDeliverSystem
//
//  Created by _ on 17/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "BaseDao.hpp"
#include "ConnectionProvider.hpp"

namespace zfq {
    BaseDao::BaseDao():BaseObject()
    {

    }

    BaseDao::BaseDao(const BaseDao &baseDao):BaseObject()
    {

    }

    BaseDao::~BaseDao()
    {

    }

    void BaseDao::releaseStmt(sql::Statement *stmt)
    {
        if (stmt != NULL) {
            delete stmt;
            stmt = NULL;
        }
    }

    void BaseDao::releaseConn(sql::Connection *con)
    {
        if (con != NULL) {
            delete con;
            con = NULL;
        }
    }

    bool BaseDao::executeSql(const char* sqlArray[] , int sqlArraySize)
    {
        sql::Statement *stmt;
        try {
            stmt = zfq::ConnectionProvider::getSqlStatement();
            int result = 0;
            bool tmpResult = false;
            for (int i = 0; i < sqlArraySize; i++) {
                tmpResult = stmt->execute(sqlArray[i]);
                result += tmpResult;
            }
            return (result == sqlArraySize) ? true : false;
        } catch (sql::SQLException &e) {
            std::cout << "出错了:" << e.what() << "\n";
            return false;
        }
        
        // return false;
        
        // sql::mysql::MySQL_Driver *driver;
        // sql::Connection *con;
        // sql::Statement *stmt;
        // try {
        //     driver = sql::mysql::get_mysql_driver_instance();
        //     con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
        //     stmt = con->createStatement();

        //     int result = 0;
        //     bool tmpResult = false;
        //     for (int i = 0; i < sqlArraySize; i++) {
        //         tmpResult = stmt->execute(sqlArray[i]);
        //         result += tmpResult;
        //     }

        //     releaseStmt(stmt);
        //     releaseConn(con);

        //     return (result == sqlArraySize) ? true : false;
        // } catch (sql::SQLException &e){
        //     std::cout << "出错了:" << e.what() << "\n";
        //     return false;
        // }
        
        return true;
    }
}
