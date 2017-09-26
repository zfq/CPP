//
//  RestaurantAgent.hpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef RestaurantAgent_hpp
#define RestaurantAgent_hpp
#include "../base/Person.hpp"
#include <string>
#include <stdio.h>

namespace zfq {
    using std::string;
    
    class RestaurantAgent : public Person
    {
    private:
        /** 餐馆法人id */
        long mRestaurantAgentId;

        void initMemberVariables(const RestaurantAgent &);
    public:
        RestaurantAgent();
        RestaurantAgent(const RestaurantAgent &);
        ~RestaurantAgent();
        
        RestaurantAgent & operator=(const RestaurantAgent &);
        
        const long getRestaurantAgentId();
        void setRestaurantAgentId(const long restaurantAgentId);
        
        virtual void description();
    };
}

#endif /* RestaurantAgent_hpp */
