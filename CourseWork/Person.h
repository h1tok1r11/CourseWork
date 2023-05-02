#pragma once
#include "DateOfBirth.h"
#include <iostream>
#include <string>

using namespace std;

enum sex : char { man, woman, attackHelicopter };

class Person
{
private:
	/*char name[20];
	char lastName[30];
	char patronymic[20];*/
	string name;
	string lastName;
	string patronymic;
	DateOfBirth dateOfBirth;
	sex sex;
	//enum sex : char { man, woman, attackHelicopter } sex;
public:
	Person();
	Person(string name, string lastName, string patronymic, DateOfBirth dateOfBirth, enum sex sex);
	void setPerson(string name, string lastName, string patronymic, DateOfBirth dateOfBirth, enum sex sex);
	string getName() { return name; };
	string getLastName() { return lastName; };
	string getPatronymic() { return patronymic; };
	DateOfBirth getDateOfBirth(){ return dateOfBirth; };
	enum sex getSex() { return sex; };
};

