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
	
	User::User():Person(),mUserId(0),mNickName(""),mAvatarId(""),mMail(""),mPassword("")
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
		this->mUserId = user.mUserId;
		this->mNickName = user.mNickName;
		this->mAvatarId = user.mAvatarId;
		this->mMail = user.mMail;
		this->mPassword = user.mPassword;
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
		return mNickName;
	}
	
	void User::setNickName(const string &nickName)
	{
		this->mNickName = nickName;
	}
	
	const long User::getUserId()
	{
		return mUserId;
	}
	
	void User::setUserId(const long userId)
	{
		this->mUserId = userId;
	}
	
	string & User::getAvatarId()
	{
		return mAvatarId;
	}
	
	void User::setAvatarId(const string &avatarId)
	{
		this->mAvatarId = avatarId;
	}
	
	const string & User::getMail()
	{
		return mMail;
	}
	
	void User::setMail(const string &mail)
	{
		this->mMail = mail;
	}
	
	const string & User::getPassword()
	{
		return mPassword;
	}
	
	void User::setPassword(const string &password)
	{
		this->mPassword = password;
	}
	
	void User::description()
	{
		Person::description();
		
		std::cout
		<< "<User:" << this
		<< "{"
		<< "userId:" << mUserId
		<< " nickName:" << mNickName
		<< " avatarId:" << mAvatarId
		<< " mail:" << mMail
		<< " password:" << mPassword
		<< "}>\n";
	}
}
