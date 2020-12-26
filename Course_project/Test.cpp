#include "Test.h"


Test::Test(int numberOfTest)
{

	ifstream fin;
	this->numberOfTest = numberOfTest;
	string path = to_string(numberOfTest) + ".txt";
	fin.open(path, ios_base::in);
	int	i = 1;
	string buff;
	while (!fin.eof())
	{
		getline(fin, buff);
		if (i % 6 == 0)
		{
			answ.push_back(buff);
		}
		else
		{
			question.push_back(buff);
		}
		i++;
	}
	fin.close();
}

bool Test::startTest(Student& stud)
{
	if (stud.access[numberOfTest - 1] != 1)
	{
		cout << "� ��� ���� ������� � �����!" << endl;
		system("pause");
		return 0;
	}
	for (int i = 0, j = 0; i < question.size(); i++, j++)
	{
		system("cls");
		int answer;
		cout << question[i] << endl;
		i++;
		cout << question[i] << endl;
		i++;
		cout << question[i] << endl;
		i++;
		cout << question[i] << endl;
		i++;
		cout << question[i] << endl;
		while (true)
		{
			cin >> answer;
			if (answer > 0 && answer < 5)
			{
				if (to_string(answer) == answ[j])
				{
					marks.push_back(1);
				}
				else
				{
					marks.push_back(0);
				}
				break;
			}
			else
			{
				cout << "�� ����� �������� ��������, ���������� ��� ���" << endl;
				cin.clear();
				cin.ignore(1048, '\n');
			}
		}
	}
	int mark = 0;
	int sum = 0;
	for (int i = 0; i < marks.size(); i++)
	{
		sum += marks[i];
		mark = round((float)sum / marks.size() * 10);
	}
	stud.access[numberOfTest - 1] = 0;
	stud.marks[numberOfTest - 1] = mark;
	system("cls");
	cout << "��� ���������: " << sum << " ���������� �� " << marks.size() << endl;
	cout << "���� ������: " << mark << endl;
	system("pause");
	return 1;
}

bool TestSystem::outStudentfin(Student stud)
{
	ifstream fin;
	fin.open(pathStudentData, ios_base::in);
	string buff, temp;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, buff);
			if (buff == stud.getlog())
			{
				temp += stud.getlog() + "\n" + stud.name + " " + stud.surname + " " + stud.group + " ";
				for (int i = 0; i < stud.access.size(); i++)
				{
					temp += to_string(stud.access[i]) + " ";
				}
				for (int i = 0; i < stud.marks.size(); i++)
				{
					temp += to_string(stud.marks[i]) + " ";
				}
				temp.at(temp.size() - 1) = '\n';
				getline(fin, buff);
			}
			else
			{
				if (buff != "")
				{
					temp += buff + "\n";
				}
			}
		}
		fin.close();
	}
	else
	{
		cerr << "������ ������ ������ � �������� � ����" << endl;
		system("pause");
		return 0;
	}
	ofstream fout;
	fout.open(pathStudentData, ios_base::out | ios_base::trunc);
	if (!fout.is_open())
	{
		cerr << "������ ������ ������ � �������� � ����" << endl;
		system("pause");
		return 0;
	}
	fout << temp;
	fout.close();
	return 1;
}

void TestSystem::showResults(Student stud)
{
	vector<string> marks;
	for (size_t i = 0; i < stud.marks.size(); i++)
	{
		if (stud.marks[i] == -1)
		{
			marks.push_back("���� �� �������!");
		}
		else
		{
			marks.push_back(to_string(stud.marks[i]));
		}
	}
	cout << "\t\t\t\t\t�������: " << stud.name << " " << stud.surname << " " << stud.group << endl << endl << endl << endl;
	cout << "������ �++:\n������: " << marks[0] << "\n������:" << boolalpha << stud.access[0] << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "���:\n������: " << marks[1] << "\n������:" << boolalpha << stud.access[1] << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "STL-����������:\n������: " << marks[2] << "\n������:" << boolalpha << stud.access[2] << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "������� ������ � ����?(0/1)" << endl;
	string c;
	while (true)
	{
		cin >> c;
		if (c == "0" || c == "1")
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(1048, '\n');
			cout << "������, ������� 0 ��� 1" << endl;
		}
	}
	if (c == "1")
	{
		ofstream fout;
		fout.open(pathReportStudent, ios_base::out | ios_base::trunc);
		if (!fout.is_open())
		{
			cerr << "������ ������ ������ � ��������" << endl;
			system("pause");
		}
		fout << "\t\t\t\t\t�������: " << stud.name << " " << stud.surname << " " << stud.group << endl;
		fout << "������ �++:\n������: " << marks[0] << "\n������:" << boolalpha << stud.access[0] << endl;
		fout << "----------------------------------------------------" << endl;
		fout << "���:\n������: " << marks[1] << "\n������:" << boolalpha << stud.access[1] << endl;
		fout << "----------------------------------------------------" << endl;
		fout << "STL-����������:\n������: " << marks[2] << "\n������:" << boolalpha << stud.access[2] << endl;
		fout << "----------------------------------------------------" << endl;
		fout.close();
		cout << "����� ������� �������� � ����!" << endl;
	}
}

bool TestSystem::getStudentsData(vector<Student>& stud)
{
	string temp;
	ifstream fin;
	fin.open("Studentdata.txt", ios_base::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string log, name, surname, group, pass;
			fin >> log
				>> name
				>> surname
				>> group;
			if (log != "")
			{
				int* access, * marks;
				access = new int[sizeof(int) * countOfTests];
				marks = new int[sizeof(int) * countOfTests];
				for (int i = 0; i < countOfTests; i++)
				{
					fin >> access[i];
				}
				for (int i = 0; i < countOfTests; i++)
				{
					fin >> marks[i];
				}
				Student s(log, pass, name, surname, group, countOfTests, marks, access);
				stud.push_back(s);
				delete[] access;
				delete[] marks;
			}
		}
	}
	else
	{
		cerr << "������ �������� �����  studentdata.txt " << endl;
		return 0;
	}
	fin.close();
	return 1;
}

void TestSystem::workWithStudentAccess(vector<Student>& stud)
{
	bool fl = 0, k = 0, t = 0, l = 0;
	while (!fl)
	{
		k = 0, t = 0, l = 0;
		system("cls");
		PrintStudetData(stud);
		cout << "1.�������� ������ ������������" << endl;
		cout << "2.�����" << endl;
		int c;
		while (!k)
		{
			cin >> c;
			if (c == 1)
			{
				while (!t)
				{
					cout << "�������� ��������" << endl;
					int num;
					cin >> num;
					if (num > 0 && num <= stud.size())
					{
						while (!l)
						{
							cout << "�������� ����� �����" << endl;
							cin >> c;
							if (c > 0 && c <= countOfTests)
							{
								stud[num - 1].access[c - 1] = !stud[num - 1].access[c - 1];
								outStudentfin(stud[num - 1]);
								cout << "������ ������� �������!" << endl;
								system("pause");
								k = 1;
								t = 1;
								l = 1;
							}
							else
							{
								cin.clear();
								cin.ignore(1048, '\n');
								cout << "������, ������� ���������� ��������" << endl;
							}
						}
					}
					else
					{
						cin.clear();
						cin.ignore(1048, '\n');
						cout << "������, ������� ���������� ��������" << endl;
					}
				}
			}
			else if (c == 2)
			{
				fl = 1;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(1048, '\n');
				cout << "������, ������� 1 ��� 2" << endl;
			}
		}
	}
}

void TestSystem::PrintStudetData(vector<Student>& stud)
{
	cout << right << setw(7) << "�����|" << right << setw(28) << "�������|" << right << setw(30) << "1.������ �++|" << right << setw(30) << "2.���|" << right << setw(30) << "3.STL-����������|" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < stud.size(); i++)
	{
		vector<string> mark;
		for (int j = 0; j < stud[i].marks.size(); j++)
		{
			if (stud[i].marks[j] == -1)
			{
				mark.push_back("���� �� �������!");
			}
			else
			{
				mark.push_back(to_string(stud[i].marks[j]));
			}
		}

		string name = stud[i].name + " " + stud[i].surname + " " + stud[i].group + "|";
		string num = to_string(i + 1) + ".|";
		string access[3];
		for (int j = 0; j < stud[i].access.size(); j++)
		{
			if (stud[i].access[j])
			{
				access[j] = "true";
			}
			else
			{
				access[j] = "false";
			}

		}
		string access0 = "������: " + access[0] + "|";
		string access1 = "������: " + access[1] + "|";
		string access2 = "������: " + access[2] + "|";
		string mark0 = "������: " + mark[0] + "|";
		string mark1 = "������: " + mark[1] + "|";
		string mark2 = "������: " + mark[2] + "|";
		cout << right << setw(7) << num << right << setw(28) << name <<
			right << setw(30) << access0 << right << setw(30) << access1 << right << setw(30) << access2 << endl <<
			setw(7) << "|" << setw(28) << "|" << setw(30) << right << mark0 << right << setw(30) << mark1 << right << setw(30) << mark2 << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
		/*cout << i + 1 << ".C������: " << stud[i].name << " " << stud[i].surname << " " << stud[i].group << endl << endl;
		cout << "1.������ �++:\n������: " << mark[0] << "\n������:" << boolalpha << stud[i].access[0] << endl << endl;
		cout << "2.���:\n������: " << mark[1] << "\n������:" << boolalpha << stud[i].access[1] << endl << endl;
		cout << "3.STL-����������:\n������: " << mark[2] << "\n������:" << boolalpha << stud[i].access[2] << endl << endl;
		cout << "----------------------------------------------------" << endl << endl;*/
	}
}

void TestSystem::workWithStudentData(vector<Student> stud)
{
	int  k = 0, t = 0, l = 0, c = 0;
	while (true)
	{
		k = 0, t = 0, l = 0;
		system("cls");
		PrintStudetData(stud);
		cout << "1.�����" << endl;
		cout << "2.����������" << endl;
		cout << "3.�����" << endl;
		while (!k)
		{
			cin >> c;
			if (c == 1)
			{
				while (!t)
				{
					cout << "1.����� �� ������" << endl;
					cout << "2.����� �� �����,�������" << endl;
					cout << "3.�����" << endl;
					int num;
					cin >> num;
					if (num > 0 && num <= 3)
					{
						while (!l)
						{
							if (num == 1)
							{
								cout << "������� ����� ������" << endl;
								string group;
								cin >> group;
								vector<Student> temp;
								search(stud, temp, group);
								if (temp.size() != 0)
								{
									system("cls");
									cout << "�������� ������: " << group << endl << endl;
									PrintStudetData(temp);
									system("pause");
									k = 1, l = 1, t = 1;
								}
								else
								{
									system("cls");
									cout << "�������� ������: " << group << " �� �������!" << endl;
									system("pause");
								}
							}
							else if (num == 2)
							{
								cout << "������� ���" << endl;
								string name, surname;
								cin >> name;
								cout << "������� �������" << endl;
								cin >> surname;
								vector<Student> temp;
								search(stud, temp, name, surname);
								if (temp.size() != 0)
								{
									system("cls");
									PrintStudetData(temp);
									system("pause");
								}
								else
								{
									system("cls");
									cout << "�������: " << name << " " << surname << " �� ������!" << endl;
									system("pause");
								}
								k = 1, l = 1, t = 1;
							}
							else if (num == 3)
							{
								k = 1, l = 1, t = 1;
							}
							else
							{
								cin.clear();
								cin.ignore(1048, '\n');
								cout << "������, ������� ���������� ��������" << endl;
							}
						}
					}
					else
					{
						cin.clear();
						cin.ignore(1048, '\n');
						cout << "������, ������� ���������� ��������" << endl;
					}
				}
			}
			else if (c == 2)
			{
				while (!t)
				{
					cout << "1.���������� �� ������" << endl;
					cout << "2.���������� �� �������" << endl;
					cout << "3.�����" << endl;
					int num;
					cin >> num;
					if (num > 0 && num <= 3)
					{
						while (!l)
						{
							if (num == 1)
							{

								for (int i = 0; i < stud.size(); i++)
								{
									for (int j = 0; j < i; j++)
									{

										if (stud[j].group > stud[j + 1].group)
										{
											Student temp = stud[j];
											stud[j] = stud[j + 1];
											stud[j + 1] = temp;
										}
									}
								}
								k = 1, l = 1, t = 1;
							}

							else if (num == 2)
							{
								for (int i = 0; i < stud.size(); i++)
								{
									for (int j = 0; j < i; j++)
									{

										if (stud[j].surname > stud[j + 1].surname)
										{
											Student temp = stud[j];
											stud[j] = stud[j + 1];
											stud[j + 1] = temp;
										}
									}
								}
								k = 1, l = 1, t = 1;
							}
							else if (num == 3)
							{
								k = 1, l = 1, t = 1;
							}
							else
							{
								cin.clear();
								cin.ignore(1048, '\n');
								cout << "������, ������� ���������� ��������" << endl;
							}
						}

					}
				}
			}
			else if (c == 3)
			{
				return;
			}
			else
			{
				cin.clear();
				cin.ignore(1048, '\n');
				cout << "������, ������� 1 ��� 2" << endl;

			}
		}
	}

}

void TestSystem::search(vector<Student> stud, vector<Student>& result, string group)
{
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].group == group)
		{
			result.push_back(stud[i]);
		}
	}

}

void TestSystem::search(vector<Student> stud, vector<Student>& result, string name, string surname)
{
	vector<Student> searchItems;
	for (int i = 0; i < stud.size(); i++)
	{
		if (stud[i].name == name && stud[i].surname == surname)
		{
			result.push_back(stud[i]);
		}
	}

}