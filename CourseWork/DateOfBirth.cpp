#include "DateOfBirth.h"

DateOfBirth::DateOfBirth()
{
	setDateOfBirth(day, month, year);
}

DateOfBirth::DateOfBirth(unsigned short day, unsigned short month, unsigned short year) :
	day(day), month(month), year(year) {};

void DateOfBirth::setDateOfBirth(unsigned short day, unsigned short month, unsigned short year) {
	this->day = day;
	this->month = month;
	this -> year = year;
};

unsigned short DateOfBirth::getDateOfBirth()
{
	return day, month, year;
}
