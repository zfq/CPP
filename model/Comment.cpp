//
//  Comment.cpp
//  FoodDeliverSystem
//
//  Created by _ on 15/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#include "Comment.hpp"
#include <iostream>
#include "../utils/StringUtil.hpp"

namespace zfq {
	Comment::Comment():BaseObject(),mOrderId(0),mRestaurantId(0),mAuthorId(0),mCommentDate(""),mContent("")
	{
		
	}
	
	Comment::Comment(const Comment &comment):BaseObject()
	{
		initMemberVariables(comment);
	}
	
	void Comment::initMemberVariables(const Comment &comment)
	{
		mOrderId = comment.mOrderId;
		mRestaurantId = comment.mRestaurantId;
		mAuthorId = comment.mAuthorId;
		mCommentDate = comment.mCommentDate;
		mContent = comment.mContent;
		mImgIds = comment.mImgIds;
	}
	
	const long Comment::getOrderId()
	{
		return mOrderId;
	}
	
	void Comment::setOrderId(const long orderId)
	{
		mOrderId = orderId;
	}
	
	const long Comment::getAuthorId()
	{
		return mAuthorId;
	}
	
	void Comment::setAuthorId(const long authorId)
	{
		mAuthorId = authorId;
	}
	
	const long Comment::getRestaurantId()
	{
		return mRestaurantId;
	}
	
	void Comment::setRestaurantId(const long restaurantId)
	{
		mRestaurantId = restaurantId;
	}
	
	const string & Comment::getCommentDate()
	{
		return mCommentDate;
	}
	
	void Comment::setCommentDate(const string &commentDate)
	{
		mCommentDate = commentDate;
	}
	
	const string & Comment::getContent()
	{
		return mContent;
	}
	
	void Comment::setContent(const string &content)
	{
		mContent = content;
	}
	
	const std::vector<string> & Comment::getImgIds()
	{
		return mImgIds;
	}
	
	void Comment::setImgIds(const std::vector<string> &imgIds)
	{
		mImgIds = imgIds;
	}
	
	void Comment::setImgIds(const string &imgIds)
	{
		split(imgIds, ",", mImgIds);
	}
	
	const float Comment::getScore()
	{
		return mScore;
	}
	
	void Comment::setScore(const float score)
	{
		mScore = score;
	}
	
	const Comment & Comment::operator=(const Comment &comment)
	{
		if (this == &comment) {
			return *this;
		}
		initMemberVariables(comment);
		return *this;
	}
	
	void Comment::description()
	{
		std::cout
		<< "<Comment:" << this
		<< "{"
		<< "orderId:" << mOrderId
		<< " authorId:" << mAuthorId
		<< " restaurantId:" << mRestaurantId
		<< " commentDate:" << mCommentDate
		<< " content:" << mContent
		<< " mImgIds:" << stringFromArray(mImgIds)
		<< " score:" << mScore
		<< "}>\n";
	}
}
