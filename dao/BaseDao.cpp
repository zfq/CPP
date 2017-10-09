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

    bool BaseDao::executeSql(const std::string &sql)
    {
        sql::Statement *stmt;
        try {
            stmt = zfq::ConnectionProvider::getSqlStatement();
            int result = stmt->execute(sql);
            return result;
        } catch (sql::SQLException &e) {
            std::cout << "出错了:" << e.what() << "\n";
            return false;
        }
        return false;
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
        return false;
    }

}
