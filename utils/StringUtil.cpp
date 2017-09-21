//
//  StringUtil.cpp
//  FoodDeliverSystem
//
//  Created by _ on 13/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "StringUtil.hpp"

namespace zfq {
	
	/**
	 分割字符串
	 
	 @param originStr 原始字符串
	 @param separator 分隔符
	 @param result 分割后所得的数组
	 */
	void split(const std::string &originStr, const std::string &separator, std::vector<std::string> &result)
	{
		result.clear();
		using size_type = std::string::size_type;
		size_type beginPos = 0;
		size_type index = originStr.find_first_of(separator, beginPos);
		while (index != std::string::npos) {
			result.push_back(originStr.substr(beginPos, index - beginPos));
			beginPos = index + 1;
			index = originStr.find_first_of(separator, beginPos);
		}
		
		//保存最后一个
		if (index - beginPos > 0) {
			result.push_back(originStr.substr(beginPos, index - beginPos));
		}
	}
	
	/**
	 将字符串数组转换成字符串
	 
	 @param array 字符串数组
	 @return 返回"[x,x,x]"形式的字符串
	 */
	std::string stringFromArray(const std::vector<std::string> &array)
	{
		std::string desc("[");
		std::vector<int>::size_type size = array.size();
		
		if (size == 1) {
			desc += (array.at(0));
		} else {
			for (std::vector<int>::size_type i = 0; i < size; i++) {
				if (i == size - 1) {
					desc += array.at(i);
				} else {
					desc += (array.at(i) + ",");
				}
			}
		}
		desc += "]";

		return desc;
	}
	
}
