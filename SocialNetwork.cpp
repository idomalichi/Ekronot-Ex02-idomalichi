#include "SocialNetwork.h"

void SocialNetwork::init(const std::string networkName, int minAge)
{
	_networkName = networkName;
	_minAge = minAge;
	_profiles.init();
}

void SocialNetwork::clear()
{
	_profiles.clear();
}

std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

int SocialNetwork::getMinAge() const
{
	return _minAge;
}

bool SocialNetwork::addProfile(const Profile profileToAdd)
{
	if (profileToAdd.getOwner().getAge() < _minAge)
	{
		return false;
	}
	return _profiles.add(profileToAdd);
}

std::string SocialNetwork::getWindowsDevices() const
{
	std::string result = "";
	ProfileNode* currProfile = _profiles.get_first();
	while (currProfile != nullptr)
	{
		DevicesList devicesList = currProfile->get_data().getOwner().getDevices();
		DeviceNode* currDevice = devicesList.get_first();
		while (currDevice != nullptr)
		{
			Device device = currDevice->get_data();
			if (device.getOS().find("Windows") != std::string::npos)
			{
				if (result != "")
				{
					result += ", ";
				}
				result += "[" + std::to_string(device.getID()) + ", " + device.getOS() + "]";
			}
			currDevice = currDevice->get_next();
		}
		currProfile = currProfile->get_next();
	}
	return result;
}