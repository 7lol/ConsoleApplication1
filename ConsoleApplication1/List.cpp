#include "stdafx.h"
#include "List.h"
#include <iostream>

		Element * Element::getNext()
		{
			return next;
		}

		Element * Element::getPrev()
		{
			return prev;
		}

		Element::Element(int value, Element * next, Element * prev)
		{
			this->value = value;
			setNext(next);
			setPrev(prev);
		}

		Element::Element(int value)
		{
			this->value = value;
			setNext(this);
			setPrev(this);
		}

		void Element::setNext(Element * ptr)
		{
			next = ptr;
		}

		void Element::setPrev(Element * ptr)
		{
			prev = ptr;
		}

		int Element::getValue()
		{
			return value;
		}

		Element * List::getPt(int i)
		{
			Element* element;
			if (i > getSize() / 2) {
				element = first->getPrev();
				for (int j = getSize();j <= i;j--) {
					element = element->getPrev();
				}
			}
			else {
				element = first;
				for (int j = 0;j < i;j++) {
					element = element->getNext();
				}
			}
			return element;
		}

		List::List(std::vector<int> vec)
		{
			for (int i = 0; i < vec.size();i++) {
				addLast(vec[i]);
			}
		}

		List::List()
		{
			first = NULL;
		}

		List::~List()
		{
			empty();
			Element* element = first;
			Element* next;
			for (int i = 0;i < getSize();i++) {
				next = element->getNext();
				delete element;
				decSize();
				element = next;
			}
			first = NULL;
		}

		void List::addFirst(int key)
		{
			this->add(key, 0);
		}

		void List::addLast(int key)
		{
			int i = getSize();
			if (getSize()>0)
				this->add(key, getSize());
			else
				this->add(key, 0);
		}

		void List::delFirst()
		{
			del(0);
		}

		void List::delLast()
		{
			del(getSize() - 1);
		}

		void List::add(int key, int i)
		{
			if (getSize() > 0) {
				Element* prev = getPt(i - 1);
				Element* next = prev->getNext();
				Element* element = new Element(key, next, prev);
				if (i == 0) {
					first = element;
				}
				next->setPrev(element);
				prev->setNext(element);
			}
			else
			{
				Element* element = new Element(key);
				first = element;
			}
		incSize();
		}

		void List::del(int i)
		{
			if (getSize() > 0) {
				Element* element = getPt(i);
				if (first == element)
					first = element->getNext();
				if (!(element == element->getNext())) {
					Element* next = element->getNext();
					Element* prev = element->getPrev();
					next->setPrev(prev);
					prev->setNext(next);
					delete element;
				}
				else

					delete element;
				decSize();
			}
		}

		std::vector<std::string> List::retValues()
		{
			std::vector<std::string> vec;
			Element* element=first;
			for (int i = 0;i < getSize();i++) {
				vec.push_back(std::to_string(element->getValue()));
				element = element->getNext();
			}
			return vec;
		}

		int List::get(int i)
		{
			return getPt(i)->getValue();
		}

		int List::find(int key)
		{
			Element* element = first;
			for (int i = 0; i < getSize(); i++) {
				if (key == element->getValue())
					return i;
				element = element->getNext();
			}
			return -1;
		}
