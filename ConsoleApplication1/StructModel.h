#ifndef	Model12309
#define Model12309
#include <vector>
#include <cstdint>
#include "AbstractStruct.h"

class StructModel :public AbstractStruct
{
public:
	StructModel();
	int getSize();
	int incSize();
	int decSize();
	void empty();
private:
	int size;
};

#endif