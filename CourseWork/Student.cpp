#include "Student.h"
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

void Student::setLastName() {
	editData->clear(studentData.lastName); editData->setLabel("Введите фамилию: ");
	tmpstr = editData->getData(editType::onlyAlpha, 30).c_str(); //почему нельзя убрать c_str
	strncpy_s(studentData.lastName, tmpstr.c_str(), tmpstr.size());
}

void Student::setName() {
	editData->clear(studentData.name); editData->setLabel("Введите имя: ");
	tmpstr = editData->getData(editType::onlyAlpha, 30).c_str();
	strncpy_s(studentData.name, tmpstr.c_str(), tmpstr.size());
}

void Student::setPatronymic() {
	editData->clear(studentData.patronymic); editData->setLabel("Введите отчество: ");
	tmpstr = editData->getData(editType::onlyAlpha, 30).c_str();
	strncpy_s(studentData.patronymic, tmpstr.c_str(), tmpstr.size());
}

void Student::setDateOfBirth() {
	editData->clear(studentData.dateOfBirthString); editData->setLabel("Введите дату рождения: ");
	tmpstr = editData->getData(editType::onlyAlpha, 30).c_str();
	strncpy_s(studentData.dateOfBirthString, tmpstr.c_str(), tmpstr.size());
}

void Student::setYearOfAdmission(){
	editData->clear(to_string(studentData.yearOfAdmission)); editData->setLabel("Введите год поступления: ");
	studentData.yearOfAdmission = editData->getData(editType::onlyDigits, 2000, 2023);
}

void Student::setFaculty() {
	editData->clear(studentData.faculty); editData->setLabel("Введите факультет (институт): ");
	tmpstr = editData->getData(editType::onlyAlpha, 30).c_str();
	strncpy_s(studentData.faculty, tmpstr.c_str(), tmpstr.size());
}

void Student::setDepartment() {
	editData->clear(studentData.department); editData->setLabel("Введите кафедру: ");
	tmpstr = editData->getData(editType::onlyAlpha, 30).c_str();
	strncpy_s(studentData.department, tmpstr.c_str(), tmpstr.size());
}

void Student::setGroup() {
	editData->clear(studentData.group); editData->setLabel("Введите группу: ");
	tmpstr = editData->getData(editType::onlyAlpha, 30).c_str();
	strncpy_s(studentData.group, tmpstr.c_str(), tmpstr.size());
}

void Student::setNumberOfRecordBook() {
	editData->clear(studentData.numberOfrecordBook); editData->setLabel("Введите номер зачётной книжки: ");
	tmpstr = editData->getData(editType::onlyAlpha, 30).c_str();
	strncpy_s(studentData.numberOfrecordBook, tmpstr.c_str(), tmpstr.size());
}

void Student::setSex(string header) {
	int sexItem = -1;
	Menu<string>* MenuOfEditingSex = new Menu<string>(header);
	MenuOfEditingSex->addMenuItem("Выход"); // 0
	MenuOfEditingSex->addMenuItem("Мужской"); // 1 
	MenuOfEditingSex->addMenuItem("Женский"); // 2
	MenuOfEditingSex->addMenuItem("Боевовертолётный"); // 3
	while (sexItem != 0) {
		sexItem = MenuOfEditingSex->run();
		if (sexItem == 1) { studentData.sex = sex::man; sexItem = 0; }
		if (sexItem == 2) { studentData.sex = sex::woman; sexItem = 0; }
		if (sexItem == 3) { studentData.sex = sex::attackHelicopter; sexItem = 0; }
	}
	delete MenuOfEditingSex;
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

void Student::setDefaultData1()
{
	strcpy_s(studentData.lastName, "Бритва");
	strcpy_s(studentData.name, "Борис");
	strcpy_s(studentData.patronymic, "Анатолич");
	strcpy_s(studentData.dateOfBirthString, "28.02.1980");
	studentData.yearOfAdmission = 2008;
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

void Student::setDefaultData2()
{
	strcpy_s(studentData.lastName, "Скальпель");
	strcpy_s(studentData.name, "Антон");
	strcpy_s(studentData.patronymic, "Генадич");
	strcpy_s(studentData.dateOfBirthString, "27.03.1984");
	studentData.yearOfAdmission = 2018;
	strcpy_s(studentData.faculty, "ИКБ");
	strcpy_s(studentData.department, "Информационная безопасность");
	strcpy_s(studentData.group, "БББО-05-22");
	strcpy_s(studentData.numberOfrecordBook, "1034А77");
	studentData.sex = sex::man;
	/*for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++) {
			studentData.sessions[i][j].isEmpty = true;
		}*/
}
void Student::setDefaultData3()
{
	strcpy_s(studentData.lastName, "Резьба");
	strcpy_s(studentData.name, "Жанна");
	strcpy_s(studentData.patronymic, "Санна");
	strcpy_s(studentData.dateOfBirthString, "23.05.1999");
	studentData.yearOfAdmission = 2028;
	strcpy_s(studentData.faculty, "ИКБ");
	strcpy_s(studentData.department, "Информационная безопасность");
	strcpy_s(studentData.group, "БББО-05-22");
	strcpy_s(studentData.numberOfrecordBook, "1983А56");
	studentData.sex = sex::woman;
	/*for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++) {
			studentData.sessions[i][j].isEmpty = true;
		}*/
}

void Student::printData() {
	cout << endl << "_________Информация о студенте:_________" << endl;
	cout << "Фамилия: " << studentData.lastName << endl << "Имя: " << studentData.name << endl <<
		"Отчество: " << studentData.patronymic << endl << "Дата рождения: " << studentData.dateOfBirthString << endl << "Год поступления: " << studentData.yearOfAdmission << endl <<
		"Факультет (институт): " << studentData.faculty << endl << "Кафедра: " << studentData.department << endl <<
		"Группа: " << studentData.group << endl << "Номер зачётной книжки: " << studentData.numberOfrecordBook << endl;
	cout << "Пол: ";
	if (studentData.sex == sex::man) { cout << "Человек " << endl; }
	if (studentData.sex == sex::woman) { cout << "Женщина " << endl; }
	if (studentData.sex == sex::attackHelicopter) { cout << "Боевой вертолёт " << endl; }
	cout << "________________________________________" << endl << endl;
}

void Student::editStudent() {
	//Student::setDefaultData1();
	Menu<string>* menuOfStudents = new Menu<string>("___Меню редактирования студента___");

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
	while (selectedItem != 0) {
		printData();
		cout << "Нажмите любую клавишу" << endl;
		_getch();
		selectedItem = menuOfStudents->run();
		switch (selectedItem)
		{
		case 1:
			setLastName();
			break;
		case 2:
			setName();
			break;
		case 3:
			setPatronymic();
			break;
		case 4:
			setDateOfBirth();
			break;
		case 5:
			setYearOfAdmission();
			break;
		case 6:
			setFaculty();
			break;
		case 7:
			setDepartment();
			break;
		case 8:
			setGroup();
			break;
		case 9:
			setNumberOfRecordBook();
			break;
		case 10:
			setSex("Меню редактирования пола студента");
			break;
		// TODO case 11:
		deafault:
			break;
		}
	}
	delete menuOfStudents;

}

void Student::setStudentData() {
	clearStudentNode();
	setLastName();
	setName();
	setPatronymic();
	setDateOfBirth();
	setYearOfAdmission();
	setFaculty();
	setDepartment();
	setGroup();
	setNumberOfRecordBook();
	setSex("Меню бинаризации");
}

void Student::setStudentNodeFromFile(int num) {
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
	for (int i = 0; i < size; i++) {
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
		//cout << i + 1 << ')'; printData();
		cout << i << ") " << studentData.lastName << " " << studentData.name << " " << studentData.patronymic << " " << studentData.dateOfBirthString << endl;
	}
	fclose(binaryFile);
	cout << "Нажмите любую клавишу" << endl;
	_getch();
	editData->clear();
	editData->setLabel("Введите номер из списка чтобы получить подробную информацию о студенте. ");
	int num = editData->getData(editType::onlyDigits, 0, size);
	setStudentNodeFromFile(num);
	editStudent();
	writeToFileStudentData(num);
}

void Student::getShortInfoFromFile(int min, int max) {
	//editData->setLabel("Укажите интервал года рождения студентов для дальнейшей сортировки этих студентов. ");
	//int size = countNumberOfRecords();
	//int min = editData->getData(editType::onlyDigits, 2000, 2023);
	//int max = editData->getData(editType::onlyDigits, 2000, 2023);
	//system("cls");
	//cout << "Список данных о студентах: " << endl;
	//FILE* binaryFile;
	//fopen_s(&binaryFile, nameOfFile.c_str(), "r");
	//for (int i = 0; i < size; i++) {
	//	fread_s(&studentData, sizeof(studentData), sizeof(studentData), 1, binaryFile);
	//	//cout << i + 1 << ')'; printData();
	//	cout << i << ") " << studentData.lastName << " " << studentData.name << " " << studentData.patronymic << " " << studentData.dateOfBirthString << endl;
	//}
	//fclose(binaryFile);
	//cout << "Нажмите любую клавишу" << endl;
	//_getch();
	//editData->clear();
	//editData->setLabel("Введите номер из списка чтобы получить подробную информацию о студенте. ");
	//int num = editData->getData(editType::onlyDigits, 0, size);
	//setStudentNodeFromFile(num);
	//editStudent();
	//writeToFileStudentData(num);
}

void Student::clearStudentNode() {
	strcpy_s(studentData.lastName, "");
	strcpy_s(studentData.name, "");
	strcpy_s(studentData.patronymic, "");
	strcpy_s(studentData.dateOfBirthString, "");
	studentData.yearOfAdmission = 0;
	strcpy_s(studentData.faculty, "");
	strcpy_s(studentData.department, "");
	strcpy_s(studentData.group, "");
	strcpy_s(studentData.numberOfrecordBook, "");
}

void Student::bubbleSortMarksInDescendingOrder()
{
	List<StudentNode> ListOfStudents;
	int countOfItems = countNumberOfRecords();	
	for (int i = 0; i < countOfItems; i++)
	{
		setStudentNodeFromFile(i);
		ListOfStudents.push_back(studentData);
	}

	for (int i = 0; i < countOfItems; i++) {
		for (int j = 0; j < countOfItems - 1; j++) {
			if (ListOfStudents[j].yearOfAdmission < ListOfStudents[j + 1].yearOfAdmission) {
				StudentNode tmp = ListOfStudents[j];
				ListOfStudents[j] = ListOfStudents[j + 1];
				ListOfStudents[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < countOfItems; i++)
	{
		studentData = ListOfStudents[i];
		deleteFromFileStudentData(0);
		addStudentToFile();
	}
}
