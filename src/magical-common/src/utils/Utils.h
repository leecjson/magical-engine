#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <memory>

static inline std::string&& magicalToString(int num)
{
	char buf[64];
	sprintf(buf, "%d", num);
	return std::move(std::string(buf));
}

static inline std::string&& magicalToString(void* ptr)
{
	char buf[64];
	sprintf(buf, "%p", ptr);
	return std::move(std::string(buf));
}

static inline std::string&& magicalToString(float num, const char* format = "%f")
{
	char buf[64];
	sprintf(buf, format, num);
	return std::move(std::string(buf));
}

#endif //__UTILS_H__