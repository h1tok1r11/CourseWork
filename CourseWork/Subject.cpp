#include "Subject.h"

Subject::Subject(char subjectName[40], markType mark)
{
	setSubject(&subjectName[40], mark);
}
void Subject::setSubject(char subjectName[40], markType mark)
{
	strcpy_s(this->subjectName, sizeof(this->subjectName), subjectName);
	this -> mark = mark;
}
;