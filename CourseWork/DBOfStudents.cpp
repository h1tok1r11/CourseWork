#include <iostream>
#include "Person.h"

#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>

#include "OneLinkedList.h"
#include "Subject.h"
#include "List.h"
//#include "ListOfSessions.h"

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    
    Subject Sub1("math", markType::bad);
    Subject Sub2("OIB", markType::excellent);
    Subject Sub3("Economic", markType::good);
    Subject Sub[5] = { Sub1, Sub2, Sub3 };
    List<Subject> list;

    /*for (int i = 0; i < 3; i++)
        list.push_back(Sub[i]);*/

    /*List<Subject> list;
    list.push_back();
    list.push_back(3);
    list.push_back(2);
    list.insert(15, 1);*/

    /*for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i].getMark() << " " << list[i].getSubjectName() << endl;
    }
    cout << endl << endl;*/

    /*list.removeAt(2);
    for (int i = 0; i < list.getSize(); i++)
    {
        cout << list[i] << endl;
    }*/



    //listOfSessions.push_front(list);
}