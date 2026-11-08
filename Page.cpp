#include "Page.h"

void Page::init()
{
	_posts = "";
	_status = "";
}

std::string Page::getStatus() const
{
	return _status;
}

std::string Page::getPosts() const
{
	return _posts;
}

void Page::setStatus(const std::string& status)
{
	_status = status;
}

void Page::addLineToPosts(const std::string& new_line)
{
	_posts += new_line + "\n";
}

void Page::clearPage()
{
	_posts = "";
}