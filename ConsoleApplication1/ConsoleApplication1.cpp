// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>	
#include <fstream>
#include "List.h"
#include "Tab.h"
#include "Heap.h"
#include "AbstractStruct.h"
#include "ConsoleApplication1.h"
#include <windows.h>
#include <string>

using namespace std;

void writeHeapToStream(vector<int> vec, ostream& stream = cout) {
	for (int k = 0;k < vec.size();k++) {
		if (vec[k] == -2)
		{
			stream << "\n";
			continue;
		}
		stream << vec[k] << "\t";
	}
	stream << "\n";
}

void writeToStream(vector<int> vec, ostream& stream = cout) {
	if (vec[0] == -2)
		writeHeapToStream(vec);
	else
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
	Heap heap = Heap();
	List list = List();
	Tab table = Tab();
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
		cout << "4. Podaj nazwe pliku" << endl;
		cout << "0. Wyjscie" << endl;
		keys = _getch();
		switch (keys)
		{
		case ('1') : {
			table = Tab(readFromFile(filename));
			data = &table;
			menu2 = true;
			break;
		}
		case ('2') : {
			list = List(readFromFile(filename));
			data = &list;
			menu2 = true;
			break;
		}
		case ('3') : {
			heap = Heap(readFromFile(filename));
			data = &heap;
			menu2 = true;
			break;
		}
		case ('4') : {
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