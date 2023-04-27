#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "InputValidation.h"
#include "List.h"

template <typename T>
class Menu
{
private:
	string upTitle;
	List<T> items; 
	string downTitle;
public:

	Menu(string upTitle) {
		this->upTitle = move(upTitle);
		//upTitle =  _upTitle;
	}

	Menu() : Menu("Just trash") {
		downTitle = "Another trash";
	}

	void addMenuItem(string _item) {
		items.push_back(_item);
	}
	void draw() {
		system("cls");
		cout << upTitle << endl;
		//int count = items.getCount();
		//for (int i = 0; i < count; i++) {
		//	cout << i << ". " << items.getItem(i) << endl;
		//}
		items.printItems();
		cout << downTitle << endl;
	}
	int run() {
		draw();
		InputValidation* cl = new InputValidation;
		cl->setLabel("Input name");
		int min = 0, max = items.getSize();
		int selectItem = cl->getData(editType::onlyDigits, min, max);
		delete cl;
		return selectItem;

	}

};
