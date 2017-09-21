//
//  BaseObject.cpp
//  FoodDeliverSystem
//
//  Created by _ on 12/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "BaseObject.hpp"
#include <iostream>

namespace zfq {
	BaseObject::BaseObject()
	{
		
	}
	
	BaseObject::~BaseObject()
	{
		
	}
	
	void BaseObject::description()
	{
		std::cout <<"<BaseObject:" << this << ">\n";
	}
}
