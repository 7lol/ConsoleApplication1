#ifndef	Red12309
#define Red12309
#include "StructModel.h"

class ElementRBTree {
protected:
	ElementRBTree* l_son;
	ElementRBTree* r_son;
	ElementRBTree* father;
	int value;
	bool black;
public:
	ElementRBTree(int value, ElementRBTree* father, ElementRBTree* l_son, ElementRBTree* r_son, bool black);
	void setFather(ElementRBTree* ptr);
	void setLSon(ElementRBTree* ptr);
	void setRSon(ElementRBTree* ptr);
	void setRed();
	void setBlack();
	bool isRed();
	bool isBlack();
	void setColor(bool black);
	ElementRBTree* getRSon();
	ElementRBTree* getLSon();
	ElementRBTree* getFather();
	int getValue();
	void setValue(int x);
};

class RedBlackTree
	: public StructModel {
public:
	RedBlackTree();
	RedBlackTree(std::vector<int> vec);
	~RedBlackTree();
	virtual void addFirst(int key) override;
	virtual void addLast(int key) override;
	virtual void delFirst() override;
	virtual void delLast() override;
	ElementRBTree* findPtr(int i);
	ElementRBTree* getBrother(ElementRBTree * p);
	ElementRBTree* findSuccesor(ElementRBTree * p);
	ElementRBTree* findMinKey(ElementRBTree * p);
	virtual void add(int key, int i) override;
	virtual void del(int i) override;
	virtual int get(int i) override;
	virtual int find(int i) override;
	virtual std::vector<std::string> retValues() override;
	std::vector<std::string> printOne(std::string sp, std::string sn, ElementRBTree * p);
private:
	//usuwanie rekurencyjne elementow
	void rec_del(ElementRBTree * elem);
	//rotacja 2 elementow
	void RedBlackTree::rotate(ElementRBTree* elem1, ElementRBTree* elem2, bool right);
	//rotacja drzewa w lewo wzgledem elem
	void rotate_left(ElementRBTree * elem);
	//rotacja drzewa w prawo wzgledem elem
	void rotate_right(ElementRBTree * elem);
	ElementRBTree* sentinel;
	ElementRBTree* root;
	std::string cr,cl,cp;
};

#endif
