//
//  Reply.hpp
//  FoodDeliverSystem
//
//  Created by _ on 17/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef Reply_hpp
#define Reply_hpp
#include "../base/BaseObject.hpp"
#include <stdio.h>

namespace zfq {
	class Reply : public BaseObject
	{
	private:
		/** 订单id */
		long mOrderId;
		
		/** 发起餐馆id */
		long mRestaurantId;
		
		/** 目标用户id */
		long mTargetAuthorId;
		
		/** 评论时间 */
		string mCommentDate;
		
		/** 评论内容 */
		string mContent;
		
		void initMemberVariables(const Reply &);
	public:
		Reply();
		Reply(const Reply &);
		
		const long getOrderId();
		void setOrderId(const long orderId);
		
		const long getTargetAuthorId();
		void setTargetAuthorId(const long targetAuthorId);
		
		const long getRestaurantId();
		void setRestaurantId(const long restaurantId);
		
		const string & getCommentDate();
		void setCommentDate(const string &commentDate);
		
		const string & getContent();
		void setContent(const string &content);
		
		const Reply &operator=(const Reply &);
		
		virtual void description();
	};
}

#endif /* Reply_hpp */
