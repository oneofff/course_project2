#include "Log.h"
string Student::getlog()
{
	return string(log);
}

void Student::setlog(string log)
{
	this->log = log;
}

string Student::getpass()
{
	return string(pass);
}

void Student::setpass(string pass)
{
	this->pass = pass;
}

string Teacher::getlog()
{
	return string(log);
}

void Teacher::setlog(string log)
{
	this->log = log;
}

string Teacher::getpass()
{
	return string(pass);
}

void Teacher::setpass(string pass)
{
	this->pass = pass;
}

namespace Crypt
{
	string Encrypt(string pass)
	{
		for (int i = 0; i < pass.size(); i++)
		{
			pass[i] = pass[i] + (i % pass.size());
		}
		return pass;
	}
	string Decrypt(string pass)
	{
		for (int i = 0; i < pass.size(); i++)
		{
			pass[i] = pass[i] - (i % pass.size());
		}
		return pass;
	}
};

//string Teacher::login()
//{
//	charbufff = ' ';
//	string log, pass;
//	vector<Teacher> vecOfTaecher;
//	getData(vecOfTaecher, pathTeacher);
//	while (true)
//	{
//		system("cls");
//		cout << "Введите логин:";
//		cin >> log;
//		cout << "Введите пароль:";
//		pass = "";
//		while (true)
//		{
//			buff = _getch();
//			if (buff == 8)
//			{
//				if (!(pass.empty()))
//				{
//					cout << (char)8 << " " << (char)8;
//					pass.erase(pass.length() - 1);
//				}
//			}
//			else if (buff == 13)
//			{
//				break;
//			}
//			else
//			{
//				cout << "*";
//				pass +=buff;
//			}
//
//		}
//		for (unsigned int i = 0; i < vecOfTaecher.size(); i++)
//		{
//			if (log == "")
//			{
//				cout << "asd";
//			}
//			if ((log == vecOfTaecher[i].log) && (pass == vecOfTaecher[i].pass))
//			{
//				system("cls");
//				return(log);
//
//				system("pause");
//			}
//		}
//
//		cout << endl << "Неверный логин или пароль, нажмите esc для выхода или любую другую клавишу чтобы попробовать снова" << endl;
//
//		if (_getch() == 27)
//		{
//			system("cls");
//			break;
//		}
//	}
//}


int getCountOfTest()
{
	ifstream fin;
	fin.open(pathCountTest, ios::in);
	if (fin.is_open())
	{
		int count;
		fin >> count;
		return count;
	}
	else
	{
		cerr << "Ошибка открытия файла  countTest.txt " << endl;
		return -1;
	}
}

Student::Student(string log, string pass, string name, string surname, string group, int countoftest,int *p1,int *p2)
{
	this->log = log;
	this->pass = pass;
	this->name = name;
	this->surname = surname;
	this->pass = pass;
	this->group = group;
	if (p1 == nullptr && p2 == nullptr)
	{
		for (int i = 0; i < countoftest; i++)
		{
			marks.push_back(-1);
			access.push_back(true);

		}
	}
	else
	{
		for (int i = 0; i < countoftest; i++)
		{
			marks.push_back(*(p1+i));
			access.push_back(*(p2+i));
		}
	}
}

template<class T>
void getData(vector<T>& data, string path)
{
	ifstream fin;
	fin.open(path, ios_base::in);
	if (fin.is_open())
	{
		string log, pass;
		T t;
		while (!fin.eof())
		{
			fin >> log
				>> pass;
			t.setlog(log);
			t.setpass(pass);
			data.push_back(t);
		}
	}
	fin.close();
}

bool outDataRegistration(Student s)
{
	ofstream fout;
	fout.open(pathStudent, ios_base::app);
	if (fout.is_open()) //Добавление 1 записи в конец файла
	{

		fout << s.getlog() << " " << s.getpass() << endl;
		fout.close();
	}
	else
	{
		cout << "Open pathStudent is fail" << endl;
		return(0);
	}
	fout.open(pathStudentData, ios_base::app);
	if (fout.is_open()) //Добавление 1 записи в конец файла
	{

		fout << s.log << endl << s.name << " " << s.surname << " " << s.group << " ";
		int count = getCountOfTest();
		for (int i = 0; i < count; i++)
		{
			fout << s.access[i] << " ";
		}
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
			{
				fout << s.marks[i];
			}
			else
			{
				fout << s.marks[i] << " ";
			}
		}
		fout << endl;
		fout.close();
	}
	else
	{
		cout << "Open pathStudent is fail" << endl;
		return(0);
	}
	return(1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n\n\n\n\n\n\n" << setw(81) <<right<<"Тестирование студентов по языку С++";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<setw(120)<<right<<"Разработал:" << endl <<right<<setw(120) << "Король С.Ю. 973603" << endl;
	cout << "\n\n\n\t\t\t\t\t      ";
	system("pause");
	//cout << setw(195) << "Нажмите Enter что бы продолжить";
	//cin.ignore(1048, '\n');
	LogMenu menu;
	
	while (true)
	{
		system("cls");
		int choice = menu.choiceMenu("Стартовое меню");
		if (choice == 1)
		{
			AutorizationModule<Teacher> autorization;
			string teacherlogin = autorization.Enter(pathTeacher);
			if (teacherlogin != "-1")
			{
				Teacher teach;
				TeacherMenu teachmenu;
				int c = 0;
				while (c != 3)
				{
					system("cls");
					c = teachmenu.choiceMenu("Teacher");
					TestSystem sys;
					vector<Student> stud;
					sys.getStudentsData(stud);
					switch (c)
					{
					case 1:
					{
						sys.workWithStudentAccess(stud);
						break;
					}
					case 2:
					{
						sys.workWithStudentData(stud);
						break;
					}
					case 3: break;
					}
				}
			}

		}
		else if (choice == 2)
		{
			AutorizationModule<Student> autorization;
			string studentlogin = autorization.Enter(pathStudent);
			if (studentlogin != "-1")
			{
				Student student(autorization.getStudentData(studentlogin));
				StudentMenu studmenu;
				int c = 0;
				while (c != 3)
				{
					system("cls");
					c = studmenu.choiceMenu(student.name+" "+student.surname+ " " + student.group);
					switch (c)
					{
					case 1:
					{
						TestMenu testmenu;
						int choice = testmenu.choiceMenu(student.name + " " + student.surname + " " + student.group);
						if (choice == 4)
						{
							break;
						}
						if (student.access[choice - 1] == 1)
						{
							Test test(choice);
							test.startTest(student);
							TestSystem sys;
							sys.outStudentfin(student);
						}
						else
						{
							cout << "У вас нету доступа к тесту!" << endl;
							system("pause");
						}
						break;
					}
					case 2:
					{
						system("cls");
						TestSystem sys;
						sys.showResults(student);
						system("pause");
						break;
					}
					case 3: break;
					}
				}
			}
		}
		else if (choice == 3)
		{
			AutorizationModule<Student> autorization;
			autorization.Registration();
		}
		else if (choice == 4)
		{
			exit(0);
		}
	}
}
