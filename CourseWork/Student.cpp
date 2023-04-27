#include "Student.h"

Student::Student()
{
	{
		dateOfBirth;
		this->yearOfAdmission = 0;
		this->faculty = "";
		this->department = "";
		this->group = "";
		this->numberOfrecordBook = "";
		//this->recordBook =
	};
}

Student::Student(DateOfBirth dateOfBirth, unsigned short yearOfAdmission, string faculty, string department, string group, string numberOfrecordBook) :
	dateOfBirth(dateOfBirth), yearOfAdmission(yearOfAdmission), faculty(faculty), department(department), group(group), numberOfrecordBook(numberOfrecordBook){}
