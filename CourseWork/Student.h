#include "DateOfBirth.h"
#include "RecordBook.h"
#include "Person.h"
#pragma once

class Student : public Person
{
private:
	DateOfBirth dateOfBirth;
	unsigned short yearOfAdmission;
	string faculty;
	string department;
	string group;
	string numberOfrecordBook;
	//RecordBook::

public:
	//Student(string name, string secondName, string patronymic);
};

