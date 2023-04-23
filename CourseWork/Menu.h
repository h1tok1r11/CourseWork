#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "InputValidation.h"
#include "List.h"

template <typename T>
class ClassMenu
{
private:
	string upTitle;
	List<T> items; 
	string downTitle;
public:

	ClassMenu(string upTitle) {
		this->upTitle = move(upTitle);
		//upTitle =  _upTitle;
	}

	ClassMenu() : ClassMenu("dfsdf sdfd") {
		downTitle = "dfsdf df ";
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
		items.printItems4Menu();
		cout << downTitle << endl;
	}
	int run() {
		draw();
		InputValidation* cl = new InputValidation();
		cl->setLabel("sdf df");
		int min = 0, max = items.getCount();
		int selectItem = cl->getData(editType::onlyDigit, min, max);
		delete cl;
		return selectItem;

	}

};
