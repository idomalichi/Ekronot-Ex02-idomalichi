#pragma once
#include <string>

class Page
{
private:
	std::string _status;
	std::string _posts;
public:
	void init();
	std::string getStatus() const;
	std::string getPosts() const;
	void setStatus(const std::string& status);
	void addLineToPosts(const std::string& new_line);
	void clearPage();
};