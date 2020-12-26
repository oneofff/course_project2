#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "conio.h"
#include "Menu.h"
#include "Log.h"
using namespace std;

class Student;

class Test
{
public:
	Test(int numberOfTest);
	bool startTest(Student&);
	friend class Student;
private:
	int numberOfTest;
	vector<string> question;
	vector<string> answ;
	vector<int> marks;
};

class TestSystem
{
public:
	TestSystem()
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
	}
	bool outStudentfin(Student);
	void showResults(Student);
	bool getStudentsData(vector<Student>& stud);
	void workWithStudentAccess(vector<Student>& stud);
	void PrintStudetData(vector<Student>& stud);
	void workWithStudentData(vector<Student> stud);
	void search(vector<Student> stud, vector<Student>& result, string group);
	void search(vector<Student> stud, vector<Student>& result, string name, string surname);
private:
	int countOfTests;
};
