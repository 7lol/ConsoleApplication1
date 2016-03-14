#include "stdafx.h"
#include "Heap.h"
#include <iostream>

int Heap::get(int i)
{
	if (i < getSize())
		return table[i];
	else
		return -1;
}

int Heap::find(int key)
{
	for (int i = 0;i < getSize();i++)
	{
		if (table[i] == key)
			return i;
	}
	return -1;
}

int Heap::leftSon(int i) {
	if (getSize() - 1 >= ((i * 2) + 1))
		return ((i * 2) + 1);
	else
		return -1;
}

int Heap::rightSon(int i) {
	if (getSize() >= ((i + 1) * 2))
		return ((i + 1) * 2);
	else
		return -1;
}

int Heap::father(int i) {
	if (((i - 1) / 2) >= 0)
		return ((i - 1) / 2);
	else
		return -1;
}

void Heap::swap(int* m,int* n) {
	int temp = *m;
	*m = *n;
	*n = temp;
}

void Heap::add(int key, int j=0)
{
	if (find(key) != -1) return;
	int *newTab = new int[incSize()];
	for (int k = 0;k < getSize()-1;k++) {
		newTab[k] = table[k];
	}
	newTab[getSize() - 1] = key;
	if (table != NULL)
		delete[] table;
	table = newTab;
	if (getSize() > 1)
	{
		int i = getSize()-1;
		while (table[father(i)] > table[i])
		{
			for (int j = 0;j < getSize();j++) {
			}
			swap(&table[father(i)], &table[i]);
			i = father(i);
			if (father(i) == -1) break;
		}
	}
}

void Heap::del(int key)
{
	int i = find(key);
	if (i == -1) return;
	int *newTab = new int[decSize()];
	for (int j = 0;j < i;j++) {
		newTab[j] = table[j];
	}
	newTab[i] = table[getSize()];
	for (int j = i+1;j < getSize();j++)
	{
		newTab[j] = table[j];
	}
	while (true)
	{
		if (leftSon(i) == -1 || rightSon(i) == -1)
			break;
		if (leftSon(i) > getSize() - 1 )
			break;
		if (rightSon(i) > getSize() - 1)
		{
			if (table[i] < table[leftSon(i)])
				break;
			swap(&table[i], &table[leftSon(i)]);
		}
		else if (table[leftSon(i)] < table[rightSon(i)])
		{
			if (table[i] < table[leftSon(i)])
				break;
			swap(&table[i], &table[leftSon(i)]);
			i = leftSon(i);
		}
		else
		{
			if (table[i] < table[rightSon(i)])
				break;
			swap(&table[i], &table[rightSon(i)]);
			i = rightSon(i);
		}
	}
}

void Heap::addFirst(int key)
{
	add(key);
}

void Heap::addLast(int key)
{
	add(key);
}

void Heap::delFirst()
{
	del(0);
}

void Heap::delLast()
{
	int *newTab = new int[decSize()];
	for (int i = 0;i > getSize() - 1;) {
		newTab[i] = table[i];
	}
}

std::vector<int> Heap::retValues()
{
	std::vector<int> vec;
	for (unsigned int i = 0;i < getSize();i++) {
		if (log2(i + 1) == (int)log2(i + 1))
			vec.push_back(-2);
		vec.push_back(table[i]);
	}
	return vec;
}

Heap::Heap(std::vector<int> vec)
{
	table = NULL;
	for (unsigned int i = 0;i < vec.size();i++) {
		add(vec[i]);
	}
}

Heap::Heap()
{
	table = NULL;
}

Heap::~Heap()
{
	/*
	empty();
	delete[] table;
	*/
}
