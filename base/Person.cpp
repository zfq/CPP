//
//  Person.cpp
//  FoodDeliverSystem
//
//  Created by _ on 12/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "Person.hpp"
#include <iostream>

namespace zfq {
	Person::Person():BaseObject(),name(""),mobile(""),gender(Unknown)
	{
		std::cout << "call default ctr\n";
	}
	
	Person::Person(const Person &person):BaseObject()
	{
		name = person.name;
		mobile = person.mobile;
		gender = person.gender;
		std::cout << "call copy ctr\n";
	}
	
	Person::Person(const char *name, const char *mobile, Gender gender):BaseObject()
	{
		this->name = string(name);
		this->mobile = string(mobile);
		this->gender = gender;
	}
	
	Person::Person(const string &name, const string &mobile, Gender gender):BaseObject()
	{
		this->name = name;
		this->mobile = mobile;
		this->gender = gender;
	}
	
	Person::~Person()
	{
		std::cout << "release Person:" << this << "\n";
	}
	
	Person & Person::operator=(const Person &person)
	{
		if (this == &person) {
			return *this;
		}
		
		name = person.name;
		mobile = person.mobile;
		gender = person.gender;
		
		return *this;
	}
	
	const string & Person::getName()
	{
		return this->name;
	}
	
	void Person::setName(const string &name)
	{
		this->name = name;
	}
	
	void Person::setName(const char *name)
	{
		this->name = name;
	}
	
	const string & Person::getMobile()
	{
		return this->mobile;
	}
	
	void Person::setMobile(const string &mobile)
	{
		this->mobile = mobile;
	}
	
	void Person::setMobile(const char *mobile)
	{
		this->mobile = mobile;
	}
	
	const Gender Person::getGender()
	{
		return gender;
	}
	
	void Person::setGender(Gender gender)
	{
		this->gender = gender;
	}
	
	void Person::description()
	{
		std::cout
		<< "<Person:" << this
		<< "{"
		<< "name:" << (this->name)
		<< " mobile:" << (this->mobile)
		<< " gender:" << this->gender
		<< "}>\n";
	}
}
