#ifndef	AbstractStruct12309
#define AbstractStruct12309
#include "stdafx.h"

class AbstractStruct
{
public:
	virtual void addFirst(int key) = 0;
	virtual void addLast(int key) = 0;
	virtual void delFirst() = 0;
	virtual void delLast() = 0;
	virtual void add(int key, int i) = 0;
	virtual void del(int i) = 0;
	virtual int get(int i) = 0;
	virtual int find(int i) = 0;
	virtual std::vector<std::string> retValues() = 0;
};
#endif