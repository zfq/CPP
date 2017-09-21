//
//  BaseObject.hpp
//  FoodDeliverSystem
//
//  Created by _ on 12/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef BaseObject_hpp
#define BaseObject_hpp

#include <stdio.h>
#include <string>

namespace zfq {
	using std::string;
	
	class BaseObject
	{
	public:
		BaseObject();
		~BaseObject();
		
		virtual void description();
	};
}

#endif /* BaseObject_hpp */
