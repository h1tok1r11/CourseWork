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

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    
    /*Subject Sub1("math", markType::bad);
    Subject Sub2("OIB", markType::excellent);
    Subject Sub3("Economic", markType::good);
    Subject Sub[5] = { Sub1, Sub2, Sub3 };
    OneLinkedList<Subject> A;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++) {
            A.pushBack(Sub[j]);
        }*/

    List<int> list;
    list.push_back(10);
    list.push_back(3);
}