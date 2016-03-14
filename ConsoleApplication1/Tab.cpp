#include "Tab.h"
#include "stdafx.h"

Tab::Tab(std::vector<int> vec)
{
	table = NULL;
	for (unsigned int i = 0; i < vec.size();i++) {
		addLast(vec[i]);
	}
}

Tab::Tab()
{
	table = NULL;
}

Tab::~Tab()
{
	/*
	empty();
	delete[] table;
	*/
}

void Tab::add(int key, int i)
{
	int *newTab = new int[incSize()];
	for (int j = 0;j < i;j++) {
		*(newTab + j) = *(table + j);
	}
	*(newTab + i) = key;
	for (int j = i;j < getSize()-1;j++) {
		*(newTab + j + 1) = *(table + j);
	}
	if (table!=NULL)
		delete[] table;
	table = newTab;
}

void Tab::addFirst(int key)
{
	add(key, 0);
}

void Tab::addLast(int key)
{
	add(key, getSize());
}

void Tab::delFirst()
{
	del(0);
}

void Tab::delLast()
{
	del(getSize() - 1);
}


void Tab::del(int i)
{
	int *newTab = new int[decSize()];
	for (int j = 0;j < i;j++) {
		*(newTab + j) = *(table + j);
	}
	for (int j = i;j < getSize();j++) {
		*(newTab + j) = *(table + j + 1);
	}
	delete[] table;
	table = newTab;
}

int Tab::get(int i)
{
	if (i >= 0 && i < getSize())
		return *(table + i);
	else
		throw _Out_bound_;
}

int Tab::find(int key)
{
	for (int i = 0;i < getSize();i++) {
		if (table[i]==key)
			return i;
	}
	return -1;
}

std::vector<int> Tab::retValues()
{
	std::vector<int> vec;
	for (int i = 0;i < getSize();i++) {
		vec.push_back(table[i]);
	}
	return vec;
}
