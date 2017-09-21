//
//  Dish.cpp
//  FoodDeliverSystem
//
//  Created by _ on 15/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "Dish.hpp"
#include <iostream>
#include "../utils/StringUtil.hpp"

namespace zfq {
	
	using std::vector;
	
	Dish::Dish():BaseObject()
	{
		
	}
	
	Dish::Dish(const Dish &dish):BaseObject()
	{
		initMemberVariables(dish);
	}
	
	Dish::~Dish()
	{
		
	}
	
	void Dish::initMemberVariables(const Dish &dish)
	{
		this->restaurantId = dish.restaurantId;
		this->dishName = dish.dishName;
		this->dishType = dish.dishType;
		this->dishImgIds = dish.dishImgIds;
		this->dishDesciption = dish.dishDesciption;
	}
	
	const long Dish::getRestaurantId()
	{
		return restaurantId;
	}
	
	void Dish::setRestaurantId(const long restaurantId)
	{
		this->restaurantId = restaurantId;
	}
	
	const string & Dish::getDishName()
	{
		return dishName;
	}
	
	void Dish::setDishName(const string &dishName)
	{
		this->dishName = dishName;
	}
	
	DishType Dish::getDishType()
	{
		return dishType;
	}
	
	void Dish::setDishType(const DishType dishType)
	{
		this->dishType = dishType;
	}
	
	const string & Dish::getDishDesciption()
	{
		return dishDesciption;
	}
	
	void Dish::setDishDesciption(const string &tmpDishDescription)
	{
		this->dishDesciption = tmpDishDescription;
	}
	
	const std::vector<string> & Dish::getDishImgIds()
	{
		return dishImgIds;
	}
	
	void Dish::setDishImgIds(const string &dishImgIds)
	{
		split(dishImgIds, ",", this->dishImgIds);
	}
	
	Dish & Dish::operator=(const Dish &dish)
	{
		if (this == &dish) {
			return *this;
		}
		initMemberVariables(dish);
		return *this;
	}
	
	void Dish::description()
	{
		std::cout
		<< "<Dish:" << this
		<< "{"
		<< "restaurantId:" << restaurantId
		<< " dishName:" << dishName
		<< " dishDesciption:" << dishDesciption
		<< " dishImgIds:" << stringFromArray(dishImgIds)
		<< "}>\n";
	}
}
