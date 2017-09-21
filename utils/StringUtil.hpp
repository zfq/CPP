//
//  StringUtil.hpp
//  FoodDeliverSystem
//
//  Created by _ on 13/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef StringUtil_hpp
#define StringUtil_hpp

#include <stdio.h>
#include <string>
#include <vector>

namespace zfq {
	
	extern void split(const std::string &originStr, const std::string &separator, std::vector<std::string> &result);
	
	extern std::string stringFromArray(const std::vector<std::string> &array);
}
#endif /* StringUtil_hpp */
