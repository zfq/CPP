//
//  User.hpp
//  FoodDeliverSystem
//
//  Created by _ on 14/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef User_hpp
#define User_hpp
#include "../base/Person.hpp"
#include <string>
#include <stdio.h>

namespace zfq {
	using std::string;
	
	class User : public Person
	{
	private:
		/** 用户id 主键 */
		long mUserId;

		/** 用户昵称 */
		string mNickName;

		/** 用户头像id */
		string mAvatarId;

		/** 用户邮箱 */
		string mMail;

		/** 用户密码 */
		string mPassword;
		
		void initMemberVariables(const User &);
	public:
		User();
		User(const User &);
		~User();
		
		User & operator=(const User &);
		
		const string & getNickName();
		void setNickName(const string &nickName);
		
		const long getUserId();
		void setUserId(const long userId);
		
		string & getAvatarId();
		void setAvatarId(const string &);
		
		const string & getMail();
		void setMail(const string &);
		
		const string & getPassword();
		void setPassword(const string &);
		
		virtual void description();
	};
}

#endif /* User_hpp */
