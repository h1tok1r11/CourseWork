#include "DateOfBirth.h"
#include "RecordBook.h"

#pragma once

enum class sex : char {man, woman, attackHelicopter};

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
	sex sex;
	//RecordBook::

public:
	Student(string name, string secondName, string patronymic);
};

