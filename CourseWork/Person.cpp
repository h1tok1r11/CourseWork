#include "Person.h"

Person::Person(char name[20], char secondName[30], char patronymic[20], DateOfBirth dateOfBirth, enum class sex sex)
{
	strcpy_s(this->name, sizeof(name), name);
	strcpy_s(this->secondName, sizeof(secondName), secondName);
	strcpy_s(this->patronymic, sizeof(patronymic), patronymic);
	this->dateOfBirth = dateOfBirth;
	this->sex = sex;
}
