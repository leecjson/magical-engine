#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <memory>

template< class _Type >
inline std::string&& magicalToString(const char* format, _Type param)
{
	char buffer[128];
	sprintf(buffer, format, param);
	return std::move(std::string(buffer));
}

//static inline std::string&& magicalToString(int num, const char* format = "%d")
//{
//	char buf[64];
//	sprintf(buf, format, num);
//	return std::move(std::string(buf));
//}
//
//static inline std::string&& magicalToString(void* ptr, const char* format = "%p")
//{
//	char buf[64];
//	sprintf(buf, format, ptr);
//	return std::move(std::string(buf));
//}
//
//static inline std::string&& magicalToString(float num, const char* format = "%f")
//{
//	char buf[64];
//	sprintf(buf, format, num);
//	return std::move(std::string(buf));
//}
//
//static inline std::string&& magicalToString(double num, const char* format = "%d")
//{
//	char buf[128];
//	sprintf(buf, format, num);
//	return std::move(std::string(buf));
//}
//
//static inline int magicalToInt(const std::string& str)
//{
//	return atoi(str.c_str());
//}
//
//static inline int magicalToInt(const std::string&& str)
//{
//	return atoi(str.c_str());
//}
//
//static inline float magicalToFloat(const std::string& str)
//{
//	return atof(str.c_str());
//}
//
//static inline float magicalToFloat(const std::string&& str)
//{
//	return atof(str.c_str());
//}

#endif //__UTILS_H__