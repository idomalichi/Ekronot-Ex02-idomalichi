#include "User.h"
#include "DeviceList.h"

void User::init(unsigned int id, const std::string& username, unsigned int age)
{
	_id = id;
	_username = username;
	_age = age;
	_devices.init();
}

unsigned int User::getID() const
{
	return _id;
}

std::string User::getUserName() const
{
	return _username;
}

unsigned int User::getAge() const
{
	return _age;
}

DevicesList& User::getDevices()
{
	return _devices;
}
//func adds a new device to the devices list
void User::addDevice(const Device newDevice)
{
	_devices.add(newDevice);
}
//func checks if all the devices are active
bool User::checkIfDevicesAreOn() const
{
    DeviceNode* curr = _devices.get_first();

    while (curr != nullptr)
    {
        if (!curr->get_data().isActive())
        {
            return false;
        }
        curr = curr->get_next();
    }

    return true;
}

void User::clear()
{
    _devices.clear();
}