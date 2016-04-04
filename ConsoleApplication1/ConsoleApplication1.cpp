// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>	
#include <fstream>
#include "List.h"
#include "Tab.h"
#include "Heap.h"
#include "RedBlackTree.h"
#include "AbstractStruct.h"
#include "ConsoleApplication1.h"
#include <windows.h>
#include <string>

using namespace std;

void writeToStream(std::vector<std::string> vec, ostream& stream = cout) {
	for (unsigned int i = 0;i < vec.size();i++)
		stream << vec[i] << endl;
}

vector<int> readFromStream(istream& stream = cin) {
	vector<int> vec;
	int temp;
	while (!(stream >> temp).eof())
	{
		if (!stream.fail())
			vec.push_back(temp);
	}
	return vec;
}

vector<int> readFromFile(string name) {
	ifstream file;
	file.open(name, std::ios::in);
	if (file.good()) {
		return readFromStream(file);
	}
	file.close();
	return vector<int>();
}

int menus()
{
	int i, key;
	char keys;
	bool exit = false;
	bool menu2 = false;
	Heap* heap;
	List* list;
	Tab* table;
	RedBlackTree* tree;
	vector<int> vec;
	AbstractStruct *data;
	string filename = "123.txt";
	do {
		while(menu2) {
			system("cls");
			cout << "1. Usuñ" << endl;
			cout << "2. Dodaj" << endl;
			cout << "3. ZnajdŸ" << endl;
			cout << "4. Wyœwietl" << endl;
			cout << "0. Powrot" << endl;
			keys = _getch();
			switch (keys)
			{
			case ('1') : {
				system("cls");
				cout << "podaj element/klucz lub index do usuniecia " << endl;
				cin >> i;
				data->del(i);
				break;
			}
			case ('2') : {
				system("cls");
				cout << "podaj klucz i numer elementu(opcjonalne dla listy i talbicy) " << endl;
				cin >> key >> i;
				data->add(key, i);
				break;
			}
			case ('3') : {
				system("cls");
				cout << "podaj klucz do znalezienia" << endl;
				cin >> key;
				cout<<"\n"<<data->find(key);
				Sleep(1500);
				break;
			}
			case ('4') : {
					system("cls");
					writeToStream(data->retValues(),cout);
					_getch();
					break;
			}
			case ('0') : {
				menu2 = false;
				break;
			}
			}
		}
		system("cls");
		cout << "1. Tablica" << endl;
		cout << "2. Lista" << endl;
		cout << "3. Kopiec" << endl;
		cout << "4. Drzewo RB" << endl;
		cout << "5. Podaj nazwe pliku" << endl;
		cout << "0. Wyjscie" << endl;
		keys = _getch();
		switch (keys)
		{
		case ('1') : {
			table = new Tab(readFromFile(filename));
			data = table;
			menu2 = true;
			break;
		}
		case ('2') : {
			list = new List(readFromFile(filename));
			data = list;
			menu2 = true;
			break;
		}
		case ('3') : {
			heap = new Heap(readFromFile(filename));
			data = heap;
			menu2 = true;
			break;
		}
		case ('4'): {
			tree = new RedBlackTree(readFromFile(filename));
			data = tree;
			menu2 = true;
			break;
		}
		case ('5') : {
			do {
				system("cls");
				cout << "Podaj prawidlowa nazwe pliku do wczytania \n";
				cin >> filename;
				ifstream f(filename.c_str());
				if (f.good()) {
					f.close();
					break;
				}
			} while (true);
			break;
		}
		case ('0') : {
			exit = true;
			break;
		}
		}
	} while (!exit);
	return 0;
}

int main()
{
	menus();
}