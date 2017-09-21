//
//  DeliveryDriver.hpp
//  FoodDeliverSystem
//
//  Created by _ on 12/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef DeliveryDriver_hpp
#define DeliveryDriver_hpp

#include <stdio.h>
#include <vector>
#include "../base/Person.hpp"

namespace zfq {
	using std::vector;
	using std::string;
	
	/**
	 配送员
	 */
	class DeliveryDriver : public Person
	{
	private:
		
		/**
		 配送员唯一id号
		 */
		long deliveryDriverId;
		
		/**
		 配送员所关联的所有的餐馆id
		 */
		vector<string> restaurantIds;
		
	public:
		DeliveryDriver();
		DeliveryDriver(const long deliveryDriverId, const string &jsonArrayStr);
		DeliveryDriver(const DeliveryDriver &);
		~DeliveryDriver();
		
		DeliveryDriver & operator=(const DeliveryDriver &);
		
		const long getDeliveryDriverId();
		void setDeliveryDriverId(const long deliveryDriverId);
		
		const vector<string> getRestaurantIds();
		void setRestaurantIds(const string &);
		
		virtual void description();
	};

}

#endif /* DeliveryDriver_hpp */
