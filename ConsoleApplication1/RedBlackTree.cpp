#include "stdafx.h"
#include "RedBlackTree.h"
#include <iostream>
#include <Windows.h>

ElementRBTree::ElementRBTree(int value, ElementRBTree * father, ElementRBTree * l_son, ElementRBTree * r_son, bool black)
{
	this->value = value;
	this->setFather(father);
	this->setLSon(l_son);
	this->setRSon(r_son);
	this->setColor(black);	
}

void ElementRBTree::setFather(ElementRBTree * ptr)
{
	father = ptr;
}

void ElementRBTree::setLSon(ElementRBTree * ptr)
{
	l_son = ptr;
}

void ElementRBTree::setRSon(ElementRBTree * ptr)
{
	r_son = ptr;
}

void ElementRBTree::setColor(bool black)
{
	this->black = black;
}

void ElementRBTree::setRed()
{
	this->setColor(false);
}

void ElementRBTree::setBlack()
{
	this->setColor(true);
}

bool ElementRBTree::isBlack()
{
	return this->black;
}

bool ElementRBTree::isRed()
{
	return !this->black;
}


ElementRBTree * ElementRBTree::getRSon()
{
	return r_son;
}

ElementRBTree * ElementRBTree::getLSon()
{
	return l_son;
}

ElementRBTree * ElementRBTree::getFather()
{
	return father;
}

int ElementRBTree::getValue()
{
	return value;
}

void ElementRBTree::setValue(int x)
{
	this->value = x;
}

void RedBlackTree::rec_del(ElementRBTree * elem)
{
	if (elem != sentinel) {
		rec_del(elem->getLSon());
		rec_del(elem->getRSon());
		delete elem;
	}
}

RedBlackTree::RedBlackTree()
{
	sentinel = new ElementRBTree(NULL,sentinel,sentinel,sentinel,true);
	root = sentinel;
}

RedBlackTree::~RedBlackTree()
{
	rec_del(root);
}

void RedBlackTree::rotate_left(ElementRBTree* elem)
{
	rotate (elem,elem->getRSon(), false);
}

void RedBlackTree::rotate_right(ElementRBTree* elem)
{
	rotate(elem, elem->getLSon(), true);
}

void RedBlackTree::rotate(ElementRBTree* elem1, ElementRBTree* elem2, bool right)
{
	ElementRBTree* p;
	if (elem2 != sentinel)
	{
		p = elem1->getFather();
		if (right) {
			elem1->setLSon(elem2->getRSon());
			if (elem1->getLSon() != sentinel) elem1->getLSon()->setFather(elem1);
			elem2->setRSon(elem1);
		}
		else {
			elem1->setRSon(elem2->getLSon());
			if (elem1->getRSon() != sentinel) elem1->getRSon()->setFather(elem1);
			elem2->setLSon(elem1);
		}
		elem2->setFather(p);
		elem1->setFather(elem2);
		if (p != sentinel)
		{
			if (p->getLSon() == elem1) p->setLSon(elem2); else p->setRSon(elem2);
		}
		else root = elem2;
	}
}

void RedBlackTree::addFirst(int key)
{
	add(key,0);
}

void RedBlackTree::addLast(int key)
{
	add(key,0);
}

void RedBlackTree::delFirst()
{
	del(root->getValue());
}

void RedBlackTree::delLast()
{
}

ElementRBTree* RedBlackTree::getBrother(ElementRBTree * p)
{
	if ((p == sentinel) || (p->getFather() == sentinel))
		return sentinel;
	if (p == p->getFather()->getLSon())
		return p->getFather()->getRSon();
	else
		return p->getFather()->getLSon();
}

ElementRBTree * RedBlackTree::findMinKey(ElementRBTree * p)
{
	while (p->getLSon() != sentinel) {
		p = p->getLSon();
	}
	return p;
}

ElementRBTree * RedBlackTree::findSuccesor(ElementRBTree * p)
{
	ElementRBTree * temp;
	if (p->getRSon() != sentinel)
		return findMinKey(p->getRSon());
	temp = p->getFather();
	while (temp != sentinel && temp->getLSon() != p) {
		p = temp;
		temp = temp->getFather();
	}
	return temp;
}

void RedBlackTree::add(int key, int j = 0)
{
	ElementRBTree *B, *A = new ElementRBTree(key, root, sentinel, sentinel, true);
	if (A->getFather() == sentinel) root = A;
	else {
		while (true)
		{
			if (key < A->getFather()->getValue())
			{
				if (A->getFather()->getLSon()== sentinel)
				{
					A->getFather()->setLSon(A);
					break;
				}
				A->setFather(A->getFather()->getLSon());
			}
			else
			{
				if (A->getFather()->getRSon() == sentinel)
				{
					A->getFather()->setRSon(A);
					break;
				}
				A->setFather(A->getFather()->getRSon());
			}
		}
	}
	A->setRed();
	while ((A != root) && (A->getFather()->isRed()))
	{
		if (A->getFather() == A->getFather()->getFather()->getLSon())
		{
			B = A->getFather()->getFather()->getRSon();
			if (B->isRed())
			{
				A->getFather()->setBlack();
				B->setBlack();
				A->getFather()->getFather()->setRed();
				A = A->getFather()->getFather();
				continue;
			}
			if (A == A->getFather()->getRSon())
			{
				A = A->getFather();
				rotate_left(A);
			}
			A->getFather()->setBlack();
			A->getFather()->getFather()->setRed();
			rotate_right(A->getFather()->getFather());
			break;
		}
		else
		{ 
			B = A->getFather()->getFather()->getLSon();

			if (B->isRed())
			{
				A->getFather()->setBlack();
				B->setBlack();
				A->getFather()->getFather()->setRed();
				A = A->getFather()->getFather();
				continue;
			}

			if (A == A->getFather()->getLSon())
			{
				A = A->getFather();
				rotate_right(A);
			}
			A->getFather()->setBlack();
			A->getFather()->getFather()->setRed();
			rotate_left(A->getFather()->getFather());
			break;
		}
	}
	root->setBlack();
	incSize();
}

void RedBlackTree::del(int i)
{
	ElementRBTree *A, *B, *C, *D;
	A = findPtr(i);

	if ((A->getLSon() == sentinel) || (A->getLSon() == sentinel)) B = A;
	else                                    
		B = findSuccesor(A);
	if (B->getLSon() != sentinel) {
		C = B->getLSon();
	}
	else {
		C = B->getRSon();
	}
	C->setFather(B->getFather());
	if (B->getFather() == sentinel) {
		root = C;
	}
	else if(B == B->getFather()->getLSon()) {
		B->getFather()->setLSon(C);
	}
	else {
		B->getFather()->setLSon(C);
	}
	if (B != A) A->setValue(B->getValue());
	if (B->isBlack())
		while ((C != root) && (C->isBlack()))
			if (C == C->getFather()->getLSon()){
				D = C->getFather()->getRSon();
				if (D->isRed())				{ 
					C->getFather()->setRed();
					D->setBlack();
					rotate_left(C->getFather());
					D= C->getFather()->getRSon();
				}
				if ((D->getLSon()->isBlack()) && (D->getRSon()->isBlack())){
					D->setRed();
					C = C->getFather();
					continue;
				}

				if (D->getRSon()->isBlack()){              
					D->getLSon()->setBlack();
					D->setRed();
					rotate_right(D);
					D = C->getFather()->getRSon();
				}
				D->setColor(C->getFather()->isBlack()); 
				C->getFather()->setBlack();
				D->getRSon()->setBlack();
				rotate_left(C->getFather());
				C = root;
			}
			else{
				D = C->getFather()->getLSon();
				if (D->isRed()){              
					D->setBlack();
					C->getFather()->setRed();
					rotate_right(C->getFather());
					D = C->getFather()->getLSon();
				}
				if ((D->getLSon()->isBlack()) && (D->getRSon()->isBlack())){
					D->setRed();
					C = C->getFather();
					continue;
				}
				if (D->getLSon()->isBlack()){
					D->getRSon()->setBlack();
					D->setRed();
					rotate_left(D);
					D = C->getFather()->getLSon();
				}
				D->setColor(C->getFather()->isBlack());
				C->getFather()->setBlack();
				D->getLSon()->setBlack();
				rotate_right(C->getFather());
				C = root;
			}
	C->setBlack();
	root;
	std::vector<std::string> vec = printOne("", "", root);
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\n";
	}
	Sleep(1500);
	//delete B;
	decSize();
}

int RedBlackTree::get(int i)
{
	return find(i);
}

int RedBlackTree::find(int i)
{
	return findPtr(i)->getValue();
}

ElementRBTree* RedBlackTree::findPtr(int i)
{
	ElementRBTree * p = root;
	while ((p != sentinel) && (p->getValue() != i))
		if (i < p->getValue()) p = p->getLSon();
		else           p = p->getRSon();
		if (p == sentinel) return sentinel;
		return p;
}

std::vector<std::string> RedBlackTree::retValues()
{
	return printOne("", "", root);
}

std::vector<std::string> RedBlackTree::printOne(std::string sp, std::string sn, ElementRBTree * p)
{
	std::vector<std::string> out2,x;
	std::string tmp,out;
	out="";
	if (p != sentinel)
	{
		tmp = sp;
		if (sn == cr) tmp[tmp.length() - 2] = ' ';
		x=(printOne(tmp + cp, cr, p->getRSon()));
		out2.insert(out2.end(), x.begin(), x.end());
		tmp = tmp.substr(0, sp.length() - 2);
		out = tmp + sn + std::to_string(p->getValue());
		p->isBlack() ? out += "B" : out += "R";
		out2.push_back(out);
		tmp = sp;
		if (sn == cl) tmp[tmp.length() - 2] = ' ';
		x=printOne(tmp + cp, cl, p->getLSon());
		out2.insert(out2.end(), x.begin(), x.end());
	}
	return out2;
}

RedBlackTree::RedBlackTree(std::vector<int> vec)
{
	sentinel = new ElementRBTree(NULL, sentinel, sentinel, sentinel, true);
	root = sentinel;
	rec_del(root);
	cr = "  ";
	cl = cp = cr;
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	for (unsigned int i = 0; i < vec.size(); i++) {
		this->add(vec[i]);
	}
}