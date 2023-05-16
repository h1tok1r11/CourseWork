
#include "InputValidation.h"
#pragma once

enum sex : char { man, woman, attackHelicopter };
enum markType : int { fail, pass, bad, satisfactory, good, excellent };


class Sessions 
{
public:
	char nameOfSubject[50];
	enum markType markType;
	bool isEmpty;
};

class StudentNode
{
public:
	char lastName[30];
	char name[20];
	char patronymic[30];
	char dateOfBirthString[15];
	int yearOfAdmission;
	char faculty[30];
	char department[30];
	char group[15];
	char numberOfrecordBook[10];
	enum sex sex;
	Sessions sessions[9][10];
};

class Student
{
private:
	string nameOfFile;
	StudentNode studentData;
	InputValidation* editData;
public:
	Student();
	~Student();
	void setLastName();
	void setName();
	void setPatronymic();
	void setDateOfBirth();
	void setYearOfAdmission();
	void setFaculty();
	void setDepartment();
	void setGroup();
	void setNumberOfRecordBook();
	void setSex(string header);
	void setMark(string header, int numberOfSession, int numberOfSubject);
	string returnMarkString(enum markType mark);
	void setSessions(string header, int numberOfStudent);
	void setSubjects(string header, int numberOfSesssion, int numberOfStudent);
	void setDefaultData1();
	void setDefaultData2();
	void setDefaultData3();
	void printData();
	void editStudent(int numberOfSesssion);
	void setStudentData(int numberOfSesssion);
	void setStudentNodeFromFile(int num);
	void addStudentToFile();
	void writeToFileStudentData(int	num);
	void deleteFromFileStudentData(int num);
	int countNumberOfRecords();
	void getShortInfoFromFile();
	void clearStudentNode();
	string setLeftBorderOfIntervalOfDateOfBirth();
	string setRightBorderOfIntervalOfDateOfBirth();
	float returnGPA(int numberOfSession);
	void bubbleSortMarksInDescendingOrder();
};