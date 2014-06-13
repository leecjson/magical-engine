#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

class Object
{
public:
	Object();
	virtual ~Object();
	virtual std::string&& toString() const;

private:
	int _reference_count;
};



#endif //__OBJECT_H__