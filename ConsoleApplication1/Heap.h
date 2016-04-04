#ifndef	Heap12309
#define Heap12309
#include "StructModel.h"

class Heap
	: public StructModel {
public:
	Heap(std::vector<int> vec);
	Heap();
	~Heap();
	virtual void addFirst(int key) override;
	virtual void addLast(int key) override;
	virtual void delFirst() override;
	virtual void delLast() override;
	virtual void add(int key, int i) override;
	virtual void del(int i) override;
	virtual int get(int i) override;
	virtual int find(int i) override;
	virtual std::vector<std::string> retValues() override;
private:
	std::vector<std::string> printOne(std::string sp, std::string sn, int v);
	int leftSon(int i);
	int rightSon(int i);
	int father(int i);
	void swap(int* m, int* n);
	int *table;
	std::string cr, cl, cp;
};

#endif
