#ifndef	Tab12309
#define Tab12309
#include "StructModel.h"

class Tab
	: public StructModel{
public:
	Tab(std::vector<int> vec);
	Tab();
	~Tab();
	void addFirst(int key) override;
	void addLast(int key) override;
	void delFirst() override;
	void delLast() override;
	void add(int key, int i) override;
	void del(int i) override;
	int get(int i) override;
	int find(int i) override;
	std::vector<std::string> retValues() override;
private:
	int *table;
};

#endif
