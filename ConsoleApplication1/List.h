#ifndef	List12309
#define List12309
#include "StructModel.h"
#include <iostream>

class Element {
protected:
	Element* next;
	Element* prev;
	int value;
public:
	Element(int value);
	Element(int value, Element* next, Element* prev);
	void setNext(Element* ptr);
	void setPrev(Element* ptr);
	Element* getNext();
	Element* getPrev();
	int getValue();
};

class List 
	: public StructModel{
protected:
	Element *first;
	Element *getPt(int i);
public:
	List(std::vector<int> vec);
	List();
	~List();
	void addFirst(int key) override;
	void addLast(int key) override;
	void delFirst() override;
	void delLast() override;
	void add(int key, int i) override;
	void del(int i) override;
	std::vector<int> retValues() override;
	int get(int i) override;
	int find(int i) override;
};

#endif