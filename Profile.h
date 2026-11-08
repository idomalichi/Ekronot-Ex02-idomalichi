#pragma once
#include <string>
#include "User.h"
#include "UserList.h"
#include "Page.h"

class Profile
{
private:
    User _owner;
    Page _page;
    UserList _friends;

public:
    void init(const User owner);
    User getOwner() const;
    void setStatus(const std::string& status);
    void addPostToProfilePage(const std::string& post);
    std::string getPage() const;
    void clearPage();
    void addFriend(const User user);
    std::string getFriends() const;
    std::string getFriendsWithSameNameLength() const;
    void clear();
};