#pragma once
#include <iostream>

using namespace std;

enum class markType : char { fail, pass, bad, satisfactory, good, excellent };

class Subject
{
private:
	markType mark;
	string subjectName;
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

