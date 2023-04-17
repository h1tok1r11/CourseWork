#pragma once
#include "DateOfBirth.h"

class Person
{
private:
	char name[20];
	char secondName[30];
	char patronymic[20];
	DateOfBirth dateOfBirth;
	enum class sex : char { man, woman, attackHelicopter } sex;
public:
	Person(char name[20], char secondName[30], char patronymic[20], DateOfBirth dateOfBirth, enum class sex sex);
};

