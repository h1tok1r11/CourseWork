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
	enum class sex : char { man, woman, attackHelicopter } sex;
	//RecordBook::

public:
	Student(string name, string secondName, string patronymic);
};

