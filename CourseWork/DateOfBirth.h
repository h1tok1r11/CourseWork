#pragma once

class DateOfBirth
{
private:
	unsigned short day;
	unsigned short month;
	unsigned short year;
public:
	DateOfBirth(unsigned short day, unsigned short month, unsigned short year);
	void setDateOfBirth(unsigned short day, unsigned short month, unsigned short year);
	unsigned short getDateOfBirth();
};

