#include "DateOfBirth.h"
#include "RecordBook.h"

#pragma once
class Student
{
private:
	string name;
	string secondName;
	string patronymic;
	DateOfBirth dateOfBirth;
	unsigned short yearOfAdmission;
	string faculty;
	string department;
	string group;
	string numberOfrecordBook;
	char sex;

public:
	Student(string name, string secondName, string patronymic);
};

