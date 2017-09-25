//
//  Restaurant.hpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef Restaurant_hpp
#define Restaurant_hpp

#include <stdio.h>
#include "../base/BaseObject.hpp"
#include "../base/Person.hpp"

namespace zfq {

	enum RestaurantType {
		
		/** 川菜 */
		RestaurantTypeSiCuanCuisine = 1 << 0,
		
		/** 东北菜 */
		RestaurantTypeNorthEastCuisine = 1 << 1,
		
		/** 火锅 */
		RestaurantTypeHotPot = 1 << 2,
		
		/** 烧烤 */
		RestaurantTypeBarbecue = 1 << 3,
		
		/** 快餐 */
		RestaurantTypeFastFood = 1 << 4,
		
		/** 主食 */
		RestaurantTypeStapleFood = 1 << 5,
		
		/** 其他 */
		RestaurantTypeOther = 1 << 6
	};
	
	class Restaurant : public BaseObject
	{
	private:
		/** 餐馆id 主键*/
		long restaurantId;
		
		/** 餐馆类型 */
		RestaurantType restaurantType;
		
		/** 餐馆法人 */
		Person agent;
		
		/** 餐馆地址 */
		string address;
		
		void initMemberVariables(const Restaurant &);
	public:
		Restaurant();
		Restaurant(const Restaurant &);
		~Restaurant();
		
		const long getRestaurantId();
		void setRestaurantId(long restaurantId);
		
		const RestaurantType getRestaurantType();
		void setRestaurantType(RestaurantType restaurantType);
		
		const Person & getAgent();
		void setAgent(const Person & agent);
		
		const string & getAddress();
		void setAddress(const string & address);
		
		Restaurant & operator=(const Restaurant &);

		virtual void description();
	};
}
#endif /* Restaurant_hpp */
