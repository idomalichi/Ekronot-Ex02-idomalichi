#include "Profile.h"

void Profile::init(const User owner)
{
	_owner = owner;
	_page.init();
	_friends.init();
}

User Profile::getOwner() const
{
	return _owner;
}

void Profile::setStatus(const std::string& status)
{
	_page.setStatus(status);
}

void Profile::clear()
{
	_friends.clear();
}

void Profile::clearPage()
{
	_page.clearPage();
}

void Profile::addPostToProfilePage(const std::string& post)
{
	_page.addLineToPosts(post);
}

std::string Profile::getPage() const
{
	std::string page = "Status: " + _page.getStatus() + "\n*******************\n*******************\n" + _page.getPosts();
	return page;
}

void Profile::addFriend(const User user)
{
	_friends.add(user);
}

std::string Profile::getFriends() const
{
	std::string friends = "";
	UserNode* curr = _friends.get_first();
	while (curr != nullptr)
	{
		if (friends != "")
		{
			friends += ",";
		}
		friends = friends + (curr->get_data().getUserName());
		curr = curr->get_next();
	}
	return friends;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	std::string sameL = "";
	UserNode* curr = _friends.get_first();
	while (curr != nullptr)
	{
		if (curr->get_data().getUserName().length() == _owner.getUserName().length())
		{
			if (sameL != "")
			{
				sameL += ",";
			}
			sameL = sameL + (curr->get_data().getUserName());
		}

		curr = curr->get_next();
	}
	return sameL;
}