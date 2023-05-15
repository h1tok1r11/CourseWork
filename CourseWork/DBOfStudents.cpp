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
#include "Menu.h"
#include "Student.h"

#include <wincrypt.h>
#include "CryptoTools.h"

using namespace std;

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    
    Student student;

    /*student.setDefaultData1();
    student.addStudentToFile();
    student.setDefaultData2();
    student.addStudentToFile();
    student.setDefaultData3();
    student.addStudentToFile();*/
    //student.addStudentToFile();
    //student.setStudentData();
    //student.addStudentToFile();

    Decrypt();
    student.getShortInfoFromFile();
    student.bubbleSortMarksInDescendingOrder();
    Crypt();
}