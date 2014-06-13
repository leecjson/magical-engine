#include "PlatformMacros.h"
#include "Object.h"
#include "Utils.h"

Object::Object()
: _reference_count(0)
{

}

Object::~Object()
{

}

std::string&& Object::toString() const
{
	std::string info;

	return std::move(info);
}