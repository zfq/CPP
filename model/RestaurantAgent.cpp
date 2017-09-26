//
//  RestaurantAgent.cpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "RestaurantAgent.hpp"
#include <iostream>

namespace zfq {
    
    RestaurantAgent::RestaurantAgent():Person(),mRestaurantAgentId(0)
    {
        
    }
    
    RestaurantAgent::RestaurantAgent(const RestaurantAgent &agent):Person(agent)
    {
        initMemberVariables(agent);
    }
    
    RestaurantAgent::~RestaurantAgent()
    {
        std::cout << "release RestaurantAgent:" << this << "\n";
    }
    
    void RestaurantAgent::initMemberVariables(const RestaurantAgent &agent)
    {
        this->mRestaurantAgentId = agent.mRestaurantAgentId;
    }

    RestaurantAgent & RestaurantAgent::operator=(const RestaurantAgent &agent)
    {
        if (this == &agent) {
            return *this;
        }
        
        Person::operator=(agent);
        initMemberVariables(agent);
        
        return *this;
    }
    
    const long RestaurantAgent::getRestaurantAgentId()
    {
        return mRestaurantAgentId;
    }
    
    void RestaurantAgent::setRestaurantAgentId(const long restaurantAgentId)
    {
        this->mRestaurantAgentId = restaurantAgentId;
    }
    
    void RestaurantAgent::description()
    {
        Person::description();
        
        std::cout
        << "<RestaurantAgent:" << this
        << "{"
        << "restaurantId:" << mRestaurantAgentId
        << "}>\n";
    }
}
