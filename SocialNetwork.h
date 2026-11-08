#pragma once
#include <string>
#include "ProfileList.h"

class SocialNetwork
{
private:
	std::string _networkName;
	ProfileList _profiles;
	int _minAge;

public:
	void init(const std::string networkName, int minAge);
	void clear();
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(const Profile profileToAdd);
	std::string getWindowsDevices() const;
};