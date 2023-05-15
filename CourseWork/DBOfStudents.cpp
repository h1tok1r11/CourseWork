#include <iostream>
#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "List.h"
#include "Menu.h"
#include "Student.h"
#include "CryptoTools.h"

using namespace std;

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    
    Student student;

    Decrypt();
    //student.getShortInfoFromFile();
    student.bubbleSortMarksInDescendingOrder();
    Crypt();
}