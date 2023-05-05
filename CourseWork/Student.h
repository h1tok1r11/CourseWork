#include "DateOfBirth.h"
#include "RecordBook.h"
#include "Person.h"
#include "InputValidation.h"
#pragma once

struct Sessions {
	string nameOfSubject;
	enum markType;
	bool isEmpty;
};

class Student : public Person
{
private:
	string nameOfFile;
	unsigned short yearOfAdmission;
	char faculty[30];
	char department[30];
	char group[15];
	char numberOfrecordBook[10];
	//RecordBook recordBook;
	Sessions sessions[9][10];
	InputValidation* inputValidation;
public:
	Student();
	~Student();
	//Student(DateOfBirth dateOfBirth, unsigned short yearOfAdmission, string faculty, string department, string group, string numberOfrecordBook);
	//static bool findStudentByRecordBook(string recordBook, List<Student> students);
	/*bool setYearOfAdmission(unsigned short yearOfAdmission);
	unsigned short getYearOfAdmiddion() { return yearOfAdmission; }
	void setFaculty(string faculty);
	string getFaculty() { return faculty; }
	void setDepartment(string department);
	string getDepartment() { return department; }
	void setGroup(string group);
	string getgroup() { return group; }*/
	void setDefaultData();
	void printData();
	void editStudent();
};