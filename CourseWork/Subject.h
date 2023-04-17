#pragma once
#include <iostream>

using namespace std;

class Subject
{
private:
	enum class markType : char { fail, pass, bad, satisfactory, good, excellent } mark;
	char subjectName[40];
public:
	Subject(string subjectName, markType mark);
	void setSubject(string subjectName, markType mark);
	string getSubjectName() {
		return subjectName;
	};
	markType getMark() {
		return mark;
	}
};

