//
//  Comment.hpp
//  FoodDeliverSystem
//
//  Created by _ on 15/09/2017.
//  Copyright © 2017 zhaofuqiang. All rights reserved.
//

#ifndef Comment_hpp
#define Comment_hpp

#include <stdio.h>
#include "../base/BaseObject.hpp"
#include <vector>

namespace zfq {
	class Comment : public BaseObject
	{
	private:
		/** 订单id */
		long mOrderId;
		
		/** 评论发起者id */
		long mAuthorId;
		
		/** 餐馆id */
		long mRestaurantId;
		
		/** 评论时间 */
		string mCommentDate;
		
		/** 评论内容 */
		string mContent;
		
		/** 图片id */
		std::vector<string> mImgIds;
		
		/** 评分 */
		float mScore;
		
		void initMemberVariables(const Comment &);
	public:
		Comment();
		Comment(const Comment &);
		
		const long getOrderId();
		void setOrderId(const long orderId);
		
		const long getAuthorId();
		void setAuthorId(const long authorId);
		
		const long getRestaurantId();
		void setRestaurantId(const long restaurantId);
		
		const string & getCommentDate();
		void setCommentDate(const string &commentDate);
		
		const string & getContent();
		void setContent(const string &content);
		
		const std::vector<string> & getImgIds();
		void setImgIds(const std::vector<string> &);
		void setImgIds(const string &);
		
		const float getScore();
		void setScore(const float score);
		
		const Comment &operator=(const Comment &);
		
		virtual void description();
	};
}
#endif /* Comment_hpp */
