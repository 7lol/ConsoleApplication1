#include "StructModel.h"
#include "stdafx.h"

StructModel::StructModel()
	{
		size = 0;
	}

int StructModel::getSize()
{
	return size;
}

int StructModel::incSize()
{
	return ++size;
}

int StructModel::decSize()
{
	return  --size;
}

void StructModel::empty()
{
	size = 0;
}