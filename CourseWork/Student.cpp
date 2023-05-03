#include "Student.h"

Student::Student()
{
	{
		this->yearOfAdmission = 0;
		this->faculty = "";
		this->department = "";
		this->group = "";
		this->numberOfrecordBook = "";
		//this->recordBook =
	};
}

Student::Student(DateOfBirth dateOfBirth, unsigned short yearOfAdmission, string faculty, string department, string group, string numberOfrecordBook) :
	yearOfAdmission(yearOfAdmission), faculty(faculty), department(department), group(group), numberOfrecordBook(numberOfrecordBook){}

bool Student::findStudentByRecordBook(string recordBook, List<Student> students)
{
	for (auto& student : students) {
		if (!strcmp(student.GetRecordBook(), recordBook)) return true;
	return false;
}

bool Student::setYearOfAdmission(unsigned short yearOfAdmission)
{
	if (not(yearOfAdmission > 2000 and yearOfAdmission < 2023))
	{
		cout << "!!!Вы ввели неверный год поступления!!!" << endl << " (не в диапазоне от 2000 до 2023)" << endl;
		return false;
	}
	this->yearOfAdmission = yearOfAdmission;
	return true;
}

void Student::setFaculty(string faculty)
{
	this->faculty = faculty;
}

void Student::setDepartment(string department)
{
	this->department = department;
}

void Student::setGroup(string group)
{
	this->group = group;
}
