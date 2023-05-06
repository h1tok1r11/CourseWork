#include "Student.h"
#include "Menu.h"
#include <fstream>

Student::Student()
{
	nameOfFile = "database.bin";
	editData = new InputValidation();
}

Student::~Student()
{
	delete editData;
}

//Student::Student(DateOfBirth dateOfBirth, unsigned short yearOfAdmission, string faculty, string department, string group, string numberOfrecordBook) :
//	yearOfAdmission(yearOfAdmission), faculty(faculty), department(department), group(group), numberOfrecordBook(numberOfrecordBook){}

//bool Student::findStudentByRecordBook(string recordBook, List<Student> students)
//{
//	/*for (auto& student : students) {
//		if (!strcmp(student.GetRecordBook(), recordBook)) return true;
//	return false;*/
//	for (auto p = std::begin(students);)
//}

//bool Student::setYearOfAdmission(unsigned short yearOfAdmission)
//{
//	if (not(yearOfAdmission > 2000 and yearOfAdmission < 2023))
//	{
//		cout << "!!!Вы ввели неверный год поступления!!!" << endl << " (не в диапазоне от 2000 до 2023)" << endl;
//		return false;
//	}
//	this->yearOfAdmission = yearOfAdmission;
//	return true;
//}
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
	strcpy_s(name, "Борис");
	strcpy_s(lastName, "Бритва");
	strcpy_s(patronymic, "Анатолич");
	strcpy_s(dateOfBirth, "28.02.1980");
	sex = sex::attackHelicopter;
	yearOfAdmission = 2000;
	strcpy_s(faculty, "ИКБ");
	strcpy_s(department, "Информационная безопасность");
	strcpy_s(group, "БББО-05-22");
	strcpy_s(numberOfrecordBook, "1055А67");
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++) {
			sessions[i][j].isEmpty = true;
		}
}

void Student::printData() {
	cout << endl << " _________Информация о студенте:_________" << endl;
	cout << "Фамилия: " << lastName << " Имя: " << name << " Отчество: " << patronymic << endl <<
		"Дата рождения: " << dateOfBirth << endl << "Год поступления: " << yearOfAdmission << endl <<
		"Факультет (институт): " << faculty << endl << "Кафедра: " << department << endl <<
		"Группа: " << group << endl << "Номер зачётной книжки: " << numberOfrecordBook << endl;
	cout << " Пол: ";
	if (sex == sex::man) { cout << "Человек " << endl; }
	if (sex == sex::woman) { cout << "Женщина " << endl; }
	if (sex == sex::attackHelicopter) { cout << "Боевой вертолёт " << endl; }
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
			editData->clear(lastName); editData->setLabel("Введите фамилию: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str(); //почему нельзя убрать c_str
			strncpy_s(lastName, str.c_str(), str.size());
			break;
		case 2:
			editData->clear(name); editData->setLabel("Введите имя: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(name, str.c_str(), str.size());
			break;
		case 3:
			editData->clear(patronymic); editData->setLabel("Введите отчество: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(patronymic, str.c_str(), str.size());
			break;
		case 4:
			editData->clear(dateOfBirth); editData->setLabel("Введите дату рождения: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(dateOfBirth, str.c_str(), str.size());
			break;
		case 5:
			editData->clear(to_string(yearOfAdmission)); editData->setLabel("Введите год поступления: ");
			yearOfAdmission = editData->getData(editType::onlyDigits, 2000, 2023);
			break;
		case 6:
			editData->clear(faculty); editData->setLabel("Введите факультет (институт): ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(faculty, str.c_str(), str.size());
			break;
		case 7:
			editData->clear(department); editData->setLabel("Введите кафедру: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(department, str.c_str(), str.size());
		case 8:
			editData->clear(group); editData->setLabel("Введите группу: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(group, str.c_str(), str.size());
			break;
		case 9:
			editData->clear(numberOfrecordBook); editData->setLabel("Введите номер зачётной книжки: ");
			str = editData->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(numberOfrecordBook, str.c_str(), str.size());
			break;
		case 10:
			while (sexItem != 0) {
				sexItem = MenuOfEditingSex->run();
				if (sexItem == 1) { sex = sex::man; sexItem = 0; }
				if (sexItem == 2) { sex = sex::woman; sexItem = 0; }
				if (sexItem == 3) { sex = sex::attackHelicopter; sexItem = 0; }
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

void Student::addStudentToFile() {
	FILE* binaryFile;
	fopen_s(&binaryFile, nameOfFile.c_str(), "a+");
	fwrite(lastName, sizeof(lastName), 1,binaryFile);
	fwrite(name, sizeof(name), 1, binaryFile);
	fwrite(patronymic, sizeof(patronymic), 1, binaryFile);
	fwrite(dateOfBirth, sizeof(dateOfBirth), 1, binaryFile);
	fwrite((char*)yearOfAdmission, sizeof(yearOfAdmission), 1, binaryFile);
	fwrite(faculty, sizeof(faculty), 1, binaryFile);
	fwrite(department, sizeof(department), 1, binaryFile);
	fwrite(group, sizeof(group), 1, binaryFile);
	fwrite(numberOfrecordBook, sizeof(numberOfrecordBook), 1, binaryFile);
	fwrite((char*)sex, sizeof(sex), 1, binaryFile);
	//fwrite((char*)sessions, sizeof(sessions), 1, binaryFile);
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
	return size;// / sizeof(st);
}

void Student::getShortInfoFromFile() {
	system("cls");
	cout << "список данных о студентах: " << endl;
	int size = countNumberOfRecords();
	FILE* binaryFile;
	fopen_s(&binaryFile, nameOfFile.c_str(), "r");
	for (int i = 0; i < size; i++) {
		fread_s(&st, sizeof(st), sizeof(st), 1, binaryfile);
		cout << i << ". " << st.surname << " " << st.name << " " << st.middlename << " " << st.group << endl;
	}
	fclose(binaryfile);
	_getch();
	edit->clear();
	edit->setlabel("ââåäèòå íîìåð èç ñïèñêà ÷òîáû ïîëó÷èòü ïîäðîáíóþ èíôîðìàöèþ î ñòóäåíòå. ");
	int num = edit->getdata(edittype::onlydigit, 0, size);
	setstudentdata(num);
	editstudent();
	write2filestudentdata(num);
}
//
//void setstudentdata(int num) {
//	file* binaryfile;
//	fopen_s(&binaryfile, filename.c_str(), "r");
//	fseek(binaryfile, num * sizeof(st), seek_set);
//	fread_s(&st, sizeof(st), sizeof(st), 1, binaryfile);
//	fclose(binaryfile);
//}
//void write2filestudentdata(int num) {
//	int size = countrecords();
//
//	file* binaryfile;
//	file* tmpfile;
//	fopen_s(&binaryfile, filename.c_str(), "r");
//	fopen_s(&tmpfile, "tmp.txt", "w+");
//	studentnode tmp_st;
//	for (int i = 0; i < size; i++) {
//		fread_s(&tmp_st, sizeof(tmp_st), sizeof(tmp_st), 1, binaryfile);
//		if (i == num)
//			fwrite(&st, sizeof(st), 1, tmpfile);
//		else
//			fwrite(&tmp_st, sizeof(tmp_st), 1, tmpfile);
//	}
//	fclose(binaryfile);
//	fclose(tmpfile);
//	remove(filename.c_str());
//	rename("tmp.txt", filename.c_str());
//
//}
//
//};
