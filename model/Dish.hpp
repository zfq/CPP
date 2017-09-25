//
//  Dish.hpp
//  FoodDeliverSystem
//
//  Created by _ on 15/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef Dish_hpp
#define Dish_hpp

#include <stdio.h>
#include "../base/BaseObject.hpp"
#include <vector>

namespace zfq {
	
	enum DishType {
		
		/** 川菜 */
		DishTypeSiCuanCuisine = 1 << 0,
		
		/** 东北菜 */
		DishTypeNorthEastCuisine = 1 << 1,
		
		/** 火锅 */
		DishTypeHotPot = 1 << 2,
		
		/** 烧烤 */
		DishTypeBarbecue = 1 << 3,
		
		/** 快餐 */
		DishTypeFastFood = 1 << 4,
		
		/** 主食 */
		DishTypeStapleFood = 1 << 5,
		
		/** 凉菜 */
		DishTypeColdDish = 1 << 6,
		
		/** 热菜 */
		DishTypeHotDishes = 1 << 7,
		
		/** 饮品 */
		DishTypeDrink = 1 << 8,
		
		/** 其他 */
		DishTypeOther = 1 << 9
	};
	
	class Dish : public BaseObject
	{
	private:
		/** 所属的餐馆id */
		long mRestaurantId;
		
		/** 菜名 */
		string mDishName;
		
		/** 菜的类型 */
		DishType mDishType;
		
		/** 菜的描述 */
		string mDishDesciption;
		
		/** 菜的图片 */
		std::vector<string> mDishImgIds;
		
		void initMemberVariables(const Dish &);
	public:
		Dish();
		Dish(const Dish &);
		~Dish();
		
		const long getRestaurantId();
		void setRestaurantId(const long restaurantId);
		
		const string & getDishName();
		void setDishName(const string &);
		
		DishType getDishType();
		void setDishType(const DishType dishType);
		
		const string & getDishDesciption();
		void setDishDesciption(const string &);

		const std::vector<string> & getDishImgIds();
		void setDishImgIds(const string &);
		
		Dish & operator=(const Dish &);
		
		virtual void description();
	};
}

#endif /* Dish_hpp */
