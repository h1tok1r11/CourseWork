﻿#include "Student.h"
#include "Menu.h"
#include <fstream>
#include <string>

Student::Student()
{
	nameOfFile = "database.bin";
	editData = new InputValidation();
}

Student::~Student()
{
	delete editData;
}

string tmpstr;
//Student::Student(DateOfBirth dateOfBirth, unsigned short yearOfAdmission, string faculty, string department, string group, string numberOfrecordBook) :
//	yearOfAdmission(yearOfAdmission), faculty(faculty), department(department), group(group), numberOfrecordBook(numberOfrecordBook){}

//bool Student::findStudentByRecordBook(string recordBook, List<Student> students)
//{
//	/*for (auto& student : students) {
//		if (!strcmp(student.GetRecordBook(), recordBook)) return true;
//	return false;*/
//	for (auto p = std::begin(students);)
//}

bool Student::setYearOfAdmission(unsigned short yearOfAdmission)
{
	editData->clear(to_string(studentData.yearOfAdmission)); editData->setLabel("Введите год поступления: ");
	studentData.yearOfAdmission = editData->getData(editType::onlyDigits, 2000, 2023);
	/*if (not(yearOfAdmission > 2000 and yearOfAdmission < 2023))
	{
		cout << "!!!Вы ввели неверный год поступления!!!" << endl << " (не в диапазоне от 2000 до 2023)" << endl;
		return false;
	}
	studentData.yearOfAdmission = yearOfAdmission;
	return true;*/
}
//
//void Student::setFaculty(string faculty)
//{
//	this->faculty = faculty;
//}
//
//void Student::setDepartment(string department)
//{
//	this->department = department;
//}
//
//void Student::setGroup(string group)
//{
//	this->group = group;
//}

void Student::setDefaultData()
{
	strcpy_s(studentData.lastName, "Бритва");
	strcpy_s(studentData.name, "Борис");
	strcpy_s(studentData.patronymic, "Анатолич");
	strcpy_s(studentData.dateOfBirthString, "28.02.1980");
	studentData.yearOfAdmission = 2000;
	strcpy_s(studentData.faculty, "ИКБ");
	strcpy_s(studentData.department, "Информационная безопасность");
	strcpy_s(studentData.group, "БББО-05-22");
	strcpy_s(studentData.numberOfrecordBook, "1055А67");
	studentData.sex = sex::attackHelicopter;
	/*for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++) {
			studentData.sessions[i][j].isEmpty = true;
		}*/
}

void Student::printData() {
	cout << endl << " _________Информация о студенте:_________" << endl;
	cout << "Фамилия: " << studentData.lastName << endl << "Имя: " << studentData.name << endl <<
		"Отчество: " << studentData.patronymic << endl << "Дата рождения: " << studentData.dateOfBirthString << endl << "Год поступления: " << studentData.yearOfAdmission << endl <<
		"Факультет (институт): " << studentData.faculty << endl << "Кафедра: " << studentData.department << endl <<
		"Группа: " << studentData.group << endl << "Номер зачётной книжки: " << studentData.numberOfrecordBook << endl;
	cout << "Пол: ";
	if (studentData.sex == sex::man) { cout << "Человек " << endl; }
	if (studentData.sex == sex::woman) { cout << "Женщина " << endl; }
	if (studentData.sex == sex::attackHelicopter) { cout << "Боевой вертолёт " << endl; }
}

void Student::editStudent() {
	Student::setDefaultData();
	Menu<string>* menuOfStudents = new Menu<string>("Меню редактирования студента");

	menuOfStudents->addMenuItem("Выход"); // 0
	menuOfStudents->addMenuItem("Изменить фамилию"); // 1 
	menuOfStudents->addMenuItem("Изменить имя"); // 2
	menuOfStudents->addMenuItem("Изменить отчество"); // 3
	menuOfStudents->addMenuItem("Изменить дату рождения"); // 4
	menuOfStudents->addMenuItem("Изменить год постулпения"); // 5
	menuOfStudents->addMenuItem("Изменить факультет (институт)"); // 6
	menuOfStudents->addMenuItem("Изменить кафедру"); //7
	menuOfStudents->addMenuItem("Изменить группу"); // 8
	menuOfStudents->addMenuItem("Изменить номер зачётной книжки"); // 9
	menuOfStudents->addMenuItem("Изменить пол"); // 10
	menuOfStudents->addMenuItem("Просмотреть/изменить успеваемость"); // 11
	int selectedItem = -1;
	Menu<string>* MenuOfEditingSex = new Menu<string>("Меню редактирования пола студента");
	MenuOfEditingSex->addMenuItem("Выход"); // 0
	MenuOfEditingSex->addMenuItem("Мужской"); // 1 
	MenuOfEditingSex->addMenuItem("Женский"); // 2
	MenuOfEditingSex->addMenuItem("Боевовертолётный"); // 3
	int sexItem = -1;
	string str;
	while (selectedItem != 0) {
		printData();
		_getch();
		selectedItem = menuOfStudents->run();
		switch (selectedItem)
		{
		case 1:
			editData->clear(studentData.lastName); editData->setLabel("Введите фамилию: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str(); //почему нельзя убрать c_str
			strncpy_s(studentData.lastName, str.c_str(), str.size());
			break;
		case 2:
			editData->clear(studentData.name); editData->setLabel("Введите имя: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(studentData.name, str.c_str(), str.size());
			break;
		case 3:
			editData->clear(studentData.patronymic); editData->setLabel("Введите отчество: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(studentData.patronymic, str.c_str(), str.size());
			break;
		case 4:
			editData->clear(studentData.dateOfBirthString); editData->setLabel("Введите дату рождения: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(studentData.dateOfBirthString, str.c_str(), str.size());
			break;
		case 5:
			editData->clear(to_string(studentData.yearOfAdmission)); editData->setLabel("Введите год поступления: ");
			studentData.yearOfAdmission = editData->getData(editType::onlyDigits, 2000, 2023);
			break;
		case 6:
			editData->clear(studentData.faculty); editData->setLabel("Введите факультет (институт): ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(studentData.faculty, str.c_str(), str.size());
			break;
		case 7:
			editData->clear(studentData.department); editData->setLabel("Введите кафедру: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(studentData.department, str.c_str(), str.size());
		case 8:
			editData->clear(studentData.group); editData->setLabel("Введите группу: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(studentData.group, str.c_str(), str.size());
			break;
		case 9:
			editData->clear(studentData.numberOfrecordBook); editData->setLabel("Введите номер зачётной книжки: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(studentData.numberOfrecordBook, str.c_str(), str.size());
			break;
		case 10:
			while (sexItem != 0) {
				sexItem = MenuOfEditingSex->run();
				if (sexItem == 1) { studentData.sex = sex::man; sexItem = 0; }
				if (sexItem == 2) { studentData.sex = sex::woman; sexItem = 0; }
				if (sexItem == 3) { studentData.sex = sex::attackHelicopter; sexItem = 0; }
			}

			break;
		// TODO case 11:
		deafault:
			break;
		}
	}
	delete MenuOfEditingSex;
	delete menuOfStudents;

}

void Student::setStudentData() {
	
	//editData->clear(studentData.lastName); editData->setLabel("Введите фамилию: ");
	//str = editData->getData(editType::onlyAlpha, 30).c_str(); //почему нельзя убрать c_str
	//strncpy_s(studentData.lastName, str.c_str(), str.size());
	//editData->clear(studentData.name); editData->setLabel("Введите имя: ");
	//str = editData->getData(editType::onlyAlpha, 30).c_str();
	//strncpy_s(studentData.name, str.c_str(), str.size());
	//editData->clear(studentData.patronymic); editData->setLabel("Введите отчество: ");
	//str = editData->getData(editType::onlyAlpha, 30).c_str();
	//strncpy_s(studentData.patronymic, str.c_str(), str.size());
	//editData->clear(studentData.dateOfBirthString); editData->setLabel("Введите дату рождения: ");
	//str = editData->getData(editType::onlyAlpha, 30).c_str();
	//strncpy_s(studentData.dateOfBirthString, str.c_str(), str.size());
	//editData->clear(to_string(studentData.yearOfAdmission)); editData->setLabel("Введите год поступления: ");
	//studentData.yearOfAdmission = editData->getData(editType::onlyDigits, 2000, 2023);
	//editData->clear(studentData.faculty); editData->setLabel("Введите факультет (институт): ");
	//str = editData->getData(editType::onlyAlpha, 30).c_str();
	//strncpy_s(studentData.faculty, str.c_str(), str.size());
	//editData->clear(studentData.department); editData->setLabel("Введите кафедру: ");
	//str = editData->getData(editType::onlyAlpha, 30).c_str();
	//strncpy_s(studentData.department, str.c_str(), str.size());
	//editData->clear(studentData.group); editData->setLabel("Введите группу: ");
	//str = editData->getData(editType::onlyAlpha, 30).c_str();
	//strncpy_s(studentData.group, str.c_str(), str.size());
	//editData->clear(studentData.numberOfrecordBook); editData->setLabel("Введите номер зачётной книжки: ");
	//str = editData->getData(editType::onlyAlpha, 30).c_str();
	//strncpy_s(studentData.numberOfrecordBook, str.c_str(), str.size());
	//}
}

void Student::setStudentData(int num) {
	FILE* binaryFile;
	fopen_s(&binaryFile, nameOfFile.c_str(), "r");
	fseek(binaryFile, num * sizeof(studentData), SEEK_SET);
	fread_s(&studentData, sizeof(studentData), sizeof(studentData), 1, binaryFile);
	fclose(binaryFile);
}

void Student::addStudentToFile() {
	FILE* binaryFile;
	fopen_s(&binaryFile, nameOfFile.c_str(), "a+");
	fwrite(&studentData, sizeof(studentData), 1, binaryFile);
	fclose(binaryFile);
	/*ofstream fout(nameOfFile, ios::binary);
	fout.write(lastName, sizeof(lastName));
	fout.write(name, sizeof(name));
	fout.write(patronymic, sizeof(patronymic));
	fout.write(dateOfBirth, sizeof(dateOfBirth));
	fout.write((char*)yearOfAdmission, sizeof(yearOfAdmission));
	fout.write(faculty, sizeof(faculty));
	fout.write(department, sizeof(department));
	fout.write(group, sizeof(group));
	fout.write(numberOfrecordBook, sizeof(numberOfrecordBook));
	fout.write((char*)sex, sizeof(sex));
	fout.write(lastName, sizeof(lastName));
	fout.write((char*)sessions, sizeof(sessions));
	fout.close();*/
}

void Student::writeToFileStudentData(int num) {
	int size = countNumberOfRecords();
	FILE* binaryFile;
	FILE* tmpFile;
	fopen_s(&binaryFile, nameOfFile.c_str(), "r");
	fopen_s(&tmpFile, "tmp.txt", "w+");
	StudentNode tmpStudentData;
	for (int i = 0; i < size; i++) {
		fread_s(&tmpStudentData, sizeof(tmpStudentData), sizeof(tmpStudentData), 1, binaryFile);
		if (i + 1 == num)
			fwrite(&studentData, sizeof(studentData), 1, tmpFile);
		else
			fwrite(&tmpStudentData, sizeof(tmpStudentData), 1, tmpFile);
	}
	fclose(binaryFile);
	fclose(tmpFile);
	remove(nameOfFile.c_str());
	rename("tmp.txt", nameOfFile.c_str());

}

void Student::deleteFromFileStudentData(int num){
	int size = countNumberOfRecords();
	FILE* binaryFile;
	FILE* tmpFile;
	fopen_s(&binaryFile, nameOfFile.c_str(), "r");
	fopen_s(&tmpFile, "tmp.txt", "w+");
	StudentNode tmpStudentData;
	for (int i = 1; i < size; i++) {
		fread_s(&tmpStudentData, sizeof(tmpStudentData), sizeof(tmpStudentData), 1, binaryFile);
		if (i != num)
			fwrite(&tmpStudentData, sizeof(tmpStudentData), 1, tmpFile);
	}
	fclose(binaryFile);
	fclose(tmpFile);
	remove(nameOfFile.c_str());
	rename("tmp.txt", nameOfFile.c_str());
}

int Student::countNumberOfRecords() {
	/*ifstream fin(nameOfFile, ios::binary);
	fin.seekg(0, ios::end);
	int size = fin.tellg();
	fin.close();
	return size / sizeof(size);*/
	FILE* binaryFile;
	fopen_s(&binaryFile, nameOfFile.c_str(), "r");
	fseek(binaryFile, 0l, SEEK_END);
	int size = ftell(binaryFile);
	fclose(binaryFile);
	return size / sizeof(studentData);
}

void Student::getShortInfoFromFile() {	
	system("cls");
	cout << "Список данных о студентах: " << endl;
	int size = countNumberOfRecords();
	FILE* binaryFile;
	fopen_s(&binaryFile, nameOfFile.c_str(), "r");
	for (int i = 0; i < size; i++) {
		fread_s(&studentData, sizeof(studentData), sizeof(studentData), 1, binaryFile);
		cout << i + 1; printData();
		//cout << i << ". " << studentData.lastName << " " << studentData.name << " " << studentData.patronymic << " " << studentData.dateOfBirthString << endl;
	}
	fclose(binaryFile);
	_getch();
	editData->clear();
	editData->setLabel("Введите номер из списка чтобы получить подробную информацию о студенте. ");
	int num = editData->getData(editType::onlyDigits, 0, size);
	setStudentData(num);
	editStudent();
	writeToFileStudentData(num);
}