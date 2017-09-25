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
	
	Dish::Dish():BaseObject(),mRestaurantId(0),mDishName(""),mDishType(DishTypeOther),mDishDesciption("")
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
		this->mRestaurantId = dish.mRestaurantId;
		this->mDishName = dish.mDishName;
		this->mDishType = dish.mDishType;
		this->mDishImgIds = dish.mDishImgIds;
		this->mDishDesciption = dish.mDishDesciption;
	}
	
	const long Dish::getRestaurantId()
	{
		return mRestaurantId;
	}
	
	void Dish::setRestaurantId(const long restaurantId)
	{
		this->mRestaurantId = restaurantId;
	}
	
	const string & Dish::getDishName()
	{
		return mDishName;
	}
	
	void Dish::setDishName(const string &dishName)
	{
		this->mDishName = dishName;
	}
	
	DishType Dish::getDishType()
	{
		return mDishType;
	}
	
	void Dish::setDishType(const DishType dishType)
	{
		this->mDishType = dishType;
	}
	
	const string & Dish::getDishDesciption()
	{
		return mDishDesciption;
	}
	
	void Dish::setDishDesciption(const string &tmpDishDescription)
	{
		this->mDishDesciption = tmpDishDescription;
	}
	
	const std::vector<string> & Dish::getDishImgIds()
	{
		return mDishImgIds;
	}
	
	void Dish::setDishImgIds(const string &dishImgIds)
	{
		split(dishImgIds, ",", this->mDishImgIds);
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
		<< "restaurantId:" << mRestaurantId
		<< " dishName:" << mDishName
		<< " dishDesciption:" << mDishDesciption
		<< " dishImgIds:" << stringFromArray(mDishImgIds)
		<< "}>\n";
	}
}
