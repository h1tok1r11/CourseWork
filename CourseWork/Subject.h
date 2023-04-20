#pragma once
#include <iostream>

using namespace std;

enum class markType : char { fail, pass, bad, satisfactory, good, excellent };

class Subject
{
private:
	//enum class markType : char { fail, pass, bad, satisfactory, good, excellent } mark;
	markType mark;
	string subjectName;
public:
	Subject() {
		mark = markType::fail;
		subjectName = "";
	}
	Subject(string subjectName, markType mark);
	void setSubject(string subjectName, markType mark);
	string getSubjectName() {
		return subjectName;
	};
	markType getMark() {
		return mark;
	}
};

