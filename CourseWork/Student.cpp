#include "Student.h"

Student::Student()
{
	nameOfFile = "database.bin";
	inputValidation = new InputValidation();
}

Student::~Student()
{
	delete inputValidation;
}

Student::Student(DateOfBirth dateOfBirth, unsigned short yearOfAdmission, string faculty, string department, string group, string numberOfrecordBook) :
	yearOfAdmission(yearOfAdmission), faculty(faculty), department(department), group(group), numberOfrecordBook(numberOfrecordBook){}

//bool Student::findStudentByRecordBook(string recordBook, List<Student> students)
//{
//	/*for (auto& student : students) {
//		if (!strcmp(student.GetRecordBook(), recordBook)) return true;
//	return false;*/
//	for (auto p = std::begin(students);)
//}

bool Student::setYearOfAdmission(unsigned short yearOfAdmission)
{
	if (not(yearOfAdmission > 2000 and yearOfAdmission < 2023))
	{
		cout << "!!!Вы ввели неверный год поступления!!!" << endl << " (не в диапазоне от 2000 до 2023)" << endl;
		return false;
	}
	this->yearOfAdmission = yearOfAdmission;
	return true;
}

void Student::setFaculty(string faculty)
{
	this->faculty = faculty;
}

void Student::setDepartment(string department)
{
	this->department = department;
}

void Student::setGroup(string group)
{
	this->group = group;
}

void Student::setDefaultData()
{
	name = "Борис";
	lastName = "Бритва";
	patronymic = "Анатолич";
	dateOfBirth = "28.02.1980";
	sex = sex::attackHelicopter;
	yearOfAdmission = 2000;
	faculty = "ИКБ";
	department = "Информационная безопасность";
	group = "БББО-05-22";
	numberOfrecordBook = "1055067";
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++) {
			sessions[i][j].isEmpty = true;
		}
}

void Student::printData() {
	cout << endl << " _________Информация о студенте:_________" << endl;
	cout << "Фамилия: " << lastName << " Имя: " << name << " Отчество: " << patronymic << endl <<
		"Дата рождения: " << dateOfBirth << endl << "Год поступления: " << yearOfAdmission << endl <<
		"Факультет (институт): " << faculty << endl << "Группа: " << group << endl <<
		"Номер зачётной книжки: " << numberOfrecordBook << endl;
	cout << " Пол: ";
	if (sex == sex::man) { cout << "Человек " << endl; }
	if (sex == sex::woman) { cout << "Женщина " << endl; }
	if (sex == sex::attackHelicopter) { cout << "Боевой вертолёт " << endl; }
}

void editStudent() {
	setDefaultData();
	ClassMenu* studMenu = new ClassMenu("Ìåíþ ðåäàêòèðîâàíèÿ ñòóäåíòà");

	studMenu->addMenuItem("Âûõîä"); // 0
	studMenu->addMenuItem("Èçìåíèòü ôàìèëèþ"); // 1 
	studMenu->addMenuItem("Èçìåíèòü èìÿ"); // 2
	studMenu->addMenuItem("Èçìåíèòü îò÷åñòâî"); // 3
	studMenu->addMenuItem("Èçìåíèòü èíñòèòóò"); // 4
	studMenu->addMenuItem("Èçìåíèòü êàôåäðó"); // 5
	studMenu->addMenuItem("Èçìåíèòü ãðóïïó"); // 6
	studMenu->addMenuItem("Èçìåíèòü ïîë"); // 7
	studMenu->addMenuItem("Èçìåíèòü ãîä  íà÷àëà îáó÷åíèÿ"); // 8
	studMenu->addMenuItem("Èçìåíèòü íîìåð çà÷åòíîé êíèæêè"); // 9
	studMenu->addMenuItem("Ïðîñìîòðåòü/èçìåíèòü óñïåâàåìîñòü"); // 10
	int selectedItem = -1;
	ClassMenu* sexMenu = new ClassMenu("Ìåíþ ðåäàêòèðîâàíèÿ ïîëà ñòóäåíòà");
	sexMenu->addMenuItem("Âûõîä"); // 0
	sexMenu->addMenuItem("Ìóæñêîé"); // 1 
	sexMenu->addMenuItem("Æåíñêèé"); // 2
	sexMenu->addMenuItem("Íåîïðåäåëåí"); // 3
	int sexItem = -1;
	string str;
	while (selectedItem != 0) {
		printInfo();
		_getch();
		selectedItem = studMenu->run();
		switch (selectedItem)
		{
		case 1:
			edit->clear(st.surName); edit->setLabel("Ââåäèòå ôàìèëèþ: ");
			str = edit->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(st.surName, str.c_str(), str.size());
			break;
		case 2:
			edit->clear(st.name); edit->setLabel("Ââåäèòå èìÿ: ");
			str = edit->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(st.name, str.c_str(), str.size());
			break;
		case 3:
			edit->clear(st.middleName); edit->setLabel("Ââåäèòå îò÷åñòâî: ");
			str = edit->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(st.middleName, str.c_str(), str.size());
			break;
		case 4:
			edit->clear(st.institute); edit->setLabel("Ââåäèòå èíñòèòóò: ");
			str = edit->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(st.institute, str.c_str(), str.size());
			break;
		case 5:
			edit->clear(st.department); edit->setLabel("Ââåäèòå êàôåäðó: ");
			str = edit->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(st.department, str.c_str(), str.size());
			break;
		case 6:
			edit->clear(st.group); edit->setLabel("Ââåäèòå ãðóïïó: ");
			str = edit->getData(editType::onlyAlpha, 30).c_str();
			strncpy_s(st.group, str.c_str(), str.size());
			break;
		case 7:

			while (sexItem != 0) {
				sexItem = sexMenu->run();
				if (sexItem == 1) { st.sex = sex::Men; sexItem = 0; }
				if (sexItem == 2) { st.sex = sex::Women; sexItem = 0; }
				if (sexItem == 3) { st.sex = sex::Any; sexItem = 0; }
			}

			break;
		case 8:
			edit->clear(to_string(st.startYear));
			edit->setLabel("Ââåäèòå ãîä íà÷àëà îáó÷åíèÿ: ");
			st.startYear = edit->getData(editType::onlyDigit, 1940, 2012);
			break;
		deafault:
			break;
		}
	}
	delete sexMenu;
	delete studMenu;

}

void addSt2File() {
	FILE* binaryFile;
	fopen_s(&binaryFile, filename.c_str(), "a+");
	fwrite(&st, sizeof(st), 1, binaryFile);
	fclose(binaryFile);
}

int countRecords() {
	FILE* binaryFile;
	fopen_s(&binaryFile, filename.c_str(), "r");
	fseek(binaryFile, 0L, SEEK_END);
	int size = ftell(binaryFile);
	fclose(binaryFile);
	return size / sizeof(st);
}

void getShortInfoFromFile() {
	system("cls");
	cout << "Ñïèñîê äàííûõ î ñòóäåíòàõ: " << endl;
	int size = countRecords();
	FILE* binaryFile;
	fopen_s(&binaryFile, filename.c_str(), "r");
	for (int i = 0; i < size; i++) {
		fread_s(&st, sizeof(st), sizeof(st), 1, binaryFile);
		cout << i << ". " << st.surName << " " << st.name << " " << st.middleName << " " << st.group << endl;
	}
	fclose(binaryFile);
	_getch();
	edit->clear();
	edit->setLabel("Ââåäèòå íîìåð èç ñïèñêà ÷òîáû ïîëó÷èòü ïîäðîáíóþ èíôîðìàöèþ î ñòóäåíòå. ");
	int num = edit->getData(editType::onlyDigit, 0, size);
	setStudentData(num);
	editStudent();
	write2FileStudentData(num);
}

void setStudentData(int num) {
	FILE* binaryFile;
	fopen_s(&binaryFile, filename.c_str(), "r");
	fseek(binaryFile, num * sizeof(st), SEEK_SET);
	fread_s(&st, sizeof(st), sizeof(st), 1, binaryFile);
	fclose(binaryFile);
}
void write2FileStudentData(int num) {
	int size = countRecords();

	FILE* binaryFile;
	FILE* tmpFile;
	fopen_s(&binaryFile, filename.c_str(), "r");
	fopen_s(&tmpFile, "tmp.txt", "w+");
	StudentNode tmp_st;
	for (int i = 0; i < size; i++) {
		fread_s(&tmp_st, sizeof(tmp_st), sizeof(tmp_st), 1, binaryFile);
		if (i == num)
			fwrite(&st, sizeof(st), 1, tmpFile);
		else
			fwrite(&tmp_st, sizeof(tmp_st), 1, tmpFile);
	}
	fclose(binaryFile);
	fclose(tmpFile);
	remove(filename.c_str());
	rename("tmp.txt", filename.c_str());

}

};
