#pragma once
#include "DateOfBirth.h"
#include <string.h>

class Person
{
private:
	char name[20];
	char lastName[30];
	char patronymic[20];
	DateOfBirth dateOfBirth;
	enum class sex : char { man, woman, attackHelicopter } sex;
public:
	Person(char name[20], char lastName[30], char patronymic[20], DateOfBirth dateOfBirth, enum class sex sex);
	void setPerson(char name[20], char lastName[30], char patronymic[20], DateOfBirth dateOfBirth, enum class sex sex);
	char* getFullName();
	DateOfBirth getDateOfBirth();
	//enum class sex getSex();
};

