#include "Person.h"

Person::Person(char name[20], char secondName[30], char patronymic[20], DateOfBirth dateOfBirth, enum class sex sex)
{
	setPerson(&name[20], &secondName[30], &patronymic[20], dateOfBirth, sex);
}

void Person::setPerson(char name[20], char lastName[30], char patronymic[20], DateOfBirth dateOfBirth, enum class sex sex)
{
	strcpy_s(this->name, sizeof(this->name), name);
	strcpy_s(this->lastName, sizeof(this->lastName), lastName);
	strcpy_s(this->patronymic, sizeof(this->patronymic), patronymic);
	this->dateOfBirth = dateOfBirth;
	this->sex = sex;
}

char* Person::getFullName()
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
