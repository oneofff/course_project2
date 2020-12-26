#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "Menu.h"
#include "Test.h"
#include <fstream>
#include "conio.h"
using namespace std;
#define pathTeacher "Teacher.txt"
#define pathStudent "Student.txt"
#define pathStudentData "Studentdata.txt"
#define pathCountTest "counttest.txt"
#define pathReportStudent "StudentReport.txt"
#define pathReportTeacher "TeacherReport.txt"
namespace Crypt
{
	string Encrypt(string pass);
	string Decrypt(string pass);
}
class User
{
public:
	virtual void result() = 0;
	virtual void startTest() = 0;
	virtual string getlog() = 0;
	virtual void setlog(string) = 0;
	virtual string getpass() = 0;
	virtual void setpass(string) = 0;
private:

};
class Student : public User
{
public:
	Student(string log = " ", string pass = " ", string name = " ", string surname = " ", string group = " ",int countOfTest=3,int*p=nullptr,int* p2= nullptr);
	void result() {};
	void startTest() {};
	string getlog();
	void setlog(string);
	string getpass();
	void setpass(string);
	friend bool outDataRegistration(Student s);
	friend int main();
	friend class Test;
	friend class TestSystem;
private:
	string log, pass, name, surname, group;
	vector<int> marks;
	vector<bool> access;
};
class Teacher : public User
{
public:
	void result() {};
	void startTest()
	{

	};
	string getlog();
	void setlog(string log);
	string getpass();
	void setpass(string);


private:
	string log, pass;
};


int getCountOfTest();
template<class T>
void getData(vector<T>& data, string path);
bool outDataRegistration(Student);
template<class T>
class AutorizationModule
{
public:
	AutorizationModule()
	{
		ifstream fin;
		fin.open("counttest.txt", ios::in);
		if (fin.is_open())
		{
			fin >> countOfTests;

		}
		else
		{
			cerr << "Ошибка открытия файла  countTest.txt " << endl;
			countOfTests = -1;
		}
		fin.close();
	};
	string Enter(string path);
	T getStudentData(string log);
	bool Registration();
private:
	int countOfTests;
};

template<class T>
string AutorizationModule<T>::Enter(string path)
{
	string log, pass;
	char buff = ' ';
	vector<T> vecOfT;
	getData(vecOfT, path);
	for (int i = 0; i < vecOfT.size(); i++)
	{
		string a = vecOfT[i].getpass();
		vecOfT[i].setpass(Crypt::Decrypt(a));
	}

	while (true)
	{
		system("cls");
		cout << "Введите логин:";
		cin >> log;
		cout << "Введите пароль:";
		pass = "";
		while (true)
		{
			buff = _getch();
			if (buff == 8)
			{
				if (!(pass.empty()))
				{
					cout << (char)8 << " " << (char)8;
					pass.erase(pass.length() - 1);
				}
			}
			else if (buff == 13)
			{
				break;
			}
			else
			{
				cout << "*";
				pass +=buff;
			}

		}
		bool enter = 0;
		for (unsigned int i = 0; i < vecOfT.size(); i++)
		{		
			if (log == "")
			{
				cout << "Логин не может быть пустым" << endl;
			}
			if ((log == vecOfT[i].getlog()) && (pass == vecOfT[i].getpass()))
			{

				return log;
			}
		}

		cout << endl << "Неверный логин или пароль, нажмите esc для выхода или любую другую клавишу чтобы попробовать снова" << endl;

		if (_getch() == 27)
		{
			return log = "-1";
			system("cls");
			break;
		}
	}
}

template<class T>
T AutorizationModule<T>::getStudentData(string log)
{
	string temp;
	ifstream fin;
	fin.open("Studentdata.txt", ios_base::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> temp;
			if (temp == log)
			{
				string name, surname, group, pass;
				int* access, * marks;
				access = new int[sizeof(int) * countOfTests];
				marks = new int[sizeof(int) * countOfTests];
				fin >> name >> surname >> group;
				for (int i = 0; i < countOfTests; i++)
				{
					fin >> access[i];
				}
				for (int i = 0; i < countOfTests; i++)
				{
					fin >> marks[i];
				}
				T stud(log, pass, name, surname, group, countOfTests, marks, access);
				delete[] access;
				delete[] marks;
				return stud;
			}
		}
	}
	else
	{
		cerr << "Ошибка открытия файла  studentdata.txt " << endl;
	}
	fin.close();
}

template<class T>
inline bool AutorizationModule<T>::Registration()
{

		string log, pass;
		char buff = ' ';
		bool isuser = false;
		vector<Student> vectorOfStudent;
		getData(vectorOfStudent, pathStudent);
		system("cls");
		while (true)
		{
			cout << "Введите логин:";
			cin >> log;
			if (log.size() < 4)
			{
				cout << "Логин должен состоять как минимум из 4 символов" << endl;
			}
			else
			{
				break;
			}
		}

		for (unsigned int i = 0; i < vectorOfStudent.size(); i++)
		{
			if (vectorOfStudent[i].getlog() == log)
			{
				cout << "Пользователь с таким именем уже существует" << endl;
				system("pause");
				return 0;
				isuser = true;
			}
		}

		while (true)
		{
			cout << "Введите пароль:";
			cin >> pass;
			if (pass.size() < 4)
			{
				cout << "Пароль должен состоять как минимум из 4 символов" << endl;
			}
			else
			{
				break;
			}
		}
		if (!isuser)
		{
			string name, surname, group;
			cout << "Введите имя " << endl;
			cin >> name;
			cout << "Введите фамилию" << endl;
			cin >> surname;
			cout << "Введите номер группы" << endl;
			cin >> group;
			if (countOfTests == -1)
			{
				cerr << "Ошибка, файл содержащий информацию от тестах не найден" << endl;
				system("pause");
				return 0;
			}
			Crypt::Encrypt(pass);
			Student s(log, pass, name, surname, group, countOfTests);
			if (outDataRegistration(s))
			{
				cout << "Регистрация успешно завершена" << endl;
				system("pause");
				return 1;
			}
		}
		system("pause");
		system("cls");
}
