//
//  Person.hpp
//  FoodDeliverSystem
//
//  Created by _ on 12/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>
#include "BaseObject.hpp"

namespace zfq {
	using std::string;
	
	enum Gender {
		Unknown = 0,
		Male = 1,
		Female = 2
	};
	
	class Person : public BaseObject
	{
	private:
		string name;
		string mobile;
		Gender gender;
	public:
		Person();
		Person(const Person &);
		Person(const char *name, const char *mobile, Gender gender);
		Person(const string &name, const string &mobile, Gender gender);
		~Person();
		
		Person & operator=(const Person &);
		
		const string & getName();
		void setName(const string &name);
		void setName(const char *name);
		
		const string & getMobile();
		void setMobile(const string &mobile);
		void setMobile(const char *mobile);
		
		const Gender getGender();
		void setGender(Gender gender);
		
		virtual void description();
	};

}

#endif /* Person_hpp */
