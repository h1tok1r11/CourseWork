//#include "DateOfBirth.h"
//#include "RecordBook.h"
//#include "Person.h"
#include "InputValidation.h"
#pragma once

enum sex : char { man, woman, attackHelicopter };
enum markType : int { fail, pass, bad, satisfactory, good, excellent };


struct Sessions {
	string nameOfSubject;
	enum markType markType;
	bool isEmpty;
};

struct StudentNode  
{
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
	//Sessions sessions[9][10];
};

class Student// : public Person
{
private:
	string nameOfFile;
	StudentNode studentData;
	InputValidation* editData;
public:
	Student();
	~Student();
	//Student(DateOfBirth dateOfBirth, unsigned short yearOfAdmission, string faculty, string department, string group, string numberOfrecordBook);
	//static bool findStudentByRecordBook(string recordBook, List<Student> students);
	bool setYearOfAdmission(unsigned short yearOfAdmission);
	/*unsigned short getYearOfAdmiddion() { return yearOfAdmission; }
	void setFaculty(string faculty);
	string getFaculty() { return faculty; }
	void setDepartment(string department);
	string getDepartment() { return department; }
	void setGroup(string group);
	string getgroup() { return group; }*/
	void setDefaultData();
	void printData();
	void editStudent();
	void setStudentData();
	void setStudentData(int num);
	void addStudentToFile();
	void writeToFileStudentData(int	num);
	void deleteFromFileStudentData(int num);
	int countNumberOfRecords();
	void getShortInfoFromFile();
};