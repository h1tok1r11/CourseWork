#include "DateOfBirth.h"
#include "RecordBook.h"
#include "Person.h"
#pragma once

class Student : public Person
{
private:
	unsigned short yearOfAdmission;
	string faculty;
	string department;
	string group;
	string numberOfrecordBook;
	//RecordBook recordBook;
public:
	Student();
	Student(DateOfBirth dateOfBirth, unsigned short yearOfAdmission, string faculty, string department, string group, string numberOfrecordBook);
	//static bool findStudentByRecordBook(string recordBook, List<Student> students);
	bool setYearOfAdmission(unsigned short yearOfAdmission);
	unsigned short getYearOfAdmiddion() { return yearOfAdmission; }
	void setFaculty(string faculty);
	string getFaculty() { return faculty; }
	void setDepartment(string department);
	string getDepartment() { return department; }
	void setGroup(string group);
	string getgroup() { return group; }
};