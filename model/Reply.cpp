//
//  Reply.cpp
//  FoodDeliverSystem
//
//  Created by _ on 17/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "Reply.hpp"
#include <iostream>

namespace zfq {
	Reply::Reply():BaseObject(),mOrderId(0),mRestaurantId(0),mTargetAuthorId(0),mCommentDate(""),mContent("")
	{
		
	}
	
	Reply::Reply(const Reply &reply):BaseObject()
	{
		initMemberVariables(reply);
	}
	
	const long Reply::getOrderId()
	{
		return mOrderId;
	}
	
	void Reply::setOrderId(const long orderId)
	{
		mOrderId = orderId;
	}
	
	const long Reply::getTargetAuthorId()
	{
		return mTargetAuthorId;
	}
	
	void Reply::setTargetAuthorId(const long targetAuthorId)
	{
		mTargetAuthorId = targetAuthorId;
	}
	
	const long Reply::getRestaurantId()
	{
		return mRestaurantId;
	}
	
	void Reply::setRestaurantId(const long restaurantId)
	{
		mRestaurantId = restaurantId;
	}
	
	const string & Reply::getCommentDate()
	{
		return mCommentDate;
	}
	
	void Reply::setCommentDate(const string &commentDate)
	{
		mCommentDate = commentDate;
	}
	
	const string & Reply::getContent()
	{
		return mContent;
	}
	
	void Reply::setContent(const string &content)
	{
		mContent = content;
	}
	
	const Reply & Reply::operator=(const Reply &reply)
	{
		if (this == &reply) {
			return *this;
		}
		initMemberVariables(reply);
		return *this;
	}
	
	void Reply::initMemberVariables(const Reply &reply)
	{
		mOrderId = reply.mOrderId;
		mRestaurantId = reply.mRestaurantId;
		mTargetAuthorId = reply.mTargetAuthorId;
		mCommentDate = reply.mCommentDate;
		mContent = reply.mContent;
	}
	
	void Reply::description()
	{
		std::cout
		<< "<Reply:" << this
		<< "{"
		<< "orderId:" << mOrderId
		<< " restaurantId:" << mRestaurantId
		<< " targetAuthorId:" << mTargetAuthorId
		<< " commentDate:" << mCommentDate
		<< " content:" << mContent
		<< "}>\n";
	}
}
