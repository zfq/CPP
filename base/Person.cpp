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
	Person::Person():BaseObject(),mName(""),mIdCardNumber(""),mMobile(""),mGender(Unknown)
	{
		std::cout << "call default ctr\n";
	}
	
	Person::Person(const Person &person):BaseObject()
	{
		initMemberVariables(person);
		std::cout << "call copy ctr\n";
	}
	
	void Person::initMemberVariables(const Person &person)
	{
		mName = person.mName;
		mIdCardNumber = person.mIdCardNumber;
		mMobile = person.mMobile;
		mGender = person.mGender;
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
		
		initMemberVariables(person);
		
		return *this;
	}
	
	const string & Person::getName()
	{
		return this->mName;
	}
	
	void Person::setName(const string &name)
	{
		this->mName = name;
	}
	
	void Person::setName(const char *name)
	{
		this->mName = name;
	}
	
	const string & Person::getIdCardNumber()
	{
		return mIdCardNumber;
	}

	void Person::setIdCardNumber(const string &idCardNumber)
	{
		mIdCardNumber = idCardNumber;
	}

	void Person::setIdCardNumber(const char *idCardNumber)
	{
		mIdCardNumber = idCardNumber;
	}

	const string & Person::getMobile()
	{
		return this->mMobile;
	}
	
	void Person::setMobile(const string &mobile)
	{
		this->mMobile = mobile;
	}
	
	void Person::setMobile(const char *mobile)
	{
		this->mMobile = mobile;
	}
	
	const Gender Person::getGender()
	{
		return mGender;
	}
	
	void Person::setGender(Gender gender)
	{
		this->mGender = gender;
	}
	
	void Person::description()
	{
		std::cout
		<< "<Person:" << this
		<< "{"
		<< "name:" << (this->mName)
		<< "idCardNumber:" << (this->mIdCardNumber)
		<< " mobile:" << (this->mMobile)
		<< " gender:" << this->mGender
		<< "}>\n";
	}
}
