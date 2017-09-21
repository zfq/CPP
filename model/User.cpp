//
//  User.cpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "User.hpp"
#include <iostream>

namespace zfq {
	
	User::User():Person(),userId(0),nickName(""),avatarId(""),mail(""),password("")
	{
		
	}
	
	User::User(const User &user):Person(user)
	{
		initMemberVariables(user);
	}
	
	User::~User()
	{
		
	}
	
	void User::initMemberVariables(const User &user)
	{
		this->userId = user.userId;
		this->nickName = user.nickName;
		this->avatarId = user.avatarId;
		this->mail = user.mail;
		this->password = user.password;
	}

	User & User::operator=(const User &user)
	{
		if (this == &user) {
			return *this;
		}
		
		Person::operator=(user);
		initMemberVariables(user);
		
		return *this;
	}
	
	const string & User::getNickName()
	{
		return nickName;
	}
	
	void User::setNickName(const string &nickName)
	{
		this->nickName = nickName;
	}
	
	const long User::getUserId()
	{
		return userId;
	}
	
	void User::setUserId(const long userId)
	{
		this->userId = userId;
	}
	
	string & User::getAvatarId()
	{
		return avatarId;
	}
	
	void User::setAvatarId(const string &avatarId)
	{
		this->avatarId = avatarId;
	}
	
	const string & User::getMail()
	{
		return mail;
	}
	
	void User::setMail(const string &mail)
	{
		this->mail = mail;
	}
	
	const string & User::getPassword()
	{
		return password;
	}
	
	void User::setPassword(const string &password)
	{
		this->password = password;
	}
	
	void User::description()
	{
		Person::description();
		
		std::cout
		<< "<Order:" << this
		<< "{"
		<< "userId:" << userId
		<< " nickName:" << nickName
		<< " avatarId:" << avatarId
		<< " mail:" << mail
		<< " password:" << password
		<< "}>\n";
	}
}
