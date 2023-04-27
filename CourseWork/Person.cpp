#include "Person.h"

Person::Person()
{
	this->name = "";
	this->lastName = "";
	this->patronymic = "";
	dateOfBirth;
	sex = man;
}

Person::Person(string name, string lastName, string patronymic, DateOfBirth dateOfBirth, enum sex sex)
{
	setPerson(name, lastName, patronymic, dateOfBirth, sex);
}

void Person::setPerson(string name, string lastName, string patronymic, DateOfBirth dateOfBirth, enum sex sex)
{
	/*strcpy_s(this->name, sizeof(this->name), name);
	strcpy_s(this->lastName, sizeof(this->lastName), lastName);
	strcpy_s(this->patronymic, sizeof(this->patronymic), patronymic);*/
	this->name = name;
	this->lastName = lastName;
	this->patronymic = patronymic;
	this->dateOfBirth = dateOfBirth;
	this->sex = sex;
}

string Person::getFullName()
{
	return name, lastName, patronymic;
}

DateOfBirth Person::getDateOfBirth()
{
	return dateOfBirth;
}

//enum class sex Person::getSex()
//{
//	return sex();
//}
