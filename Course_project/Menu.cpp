#include "Menu.h"

int LogMenu::choiceMenu(string s)
{
	system("cls");
	cout << "\t\t\t\t\t\t" << s << endl << endl << endl<< endl;
	int choice = 1;
	while (choice != 4)
	{
		cout << "1.����� ��� �������������" << endl;
		cout << "2.����� ��� �������" << endl;
		cout << "3.����������� ������ ��������" << endl;
		cout << "4.����� �� ���������" << endl;
		bool fail = true;
		while (fail)
		{
			cin >> choice;
			if (choice > 0 && choice <= 4)
			{
				return choice;
			}
			else
			{
				cout << "�� ����� �������� ��������, ���������� ��� ���" << endl;
				cin.clear();
				cin.ignore(1048, '\n');//������ ������������� ������ � ������� �����
			}
		}

	}
}

int TeacherMenu::choiceMenu(string s)
{
	system("cls");
	cout << "\t\t\t\t\t" << s << endl << endl << endl << endl;
	int choice = 1;
	while (choice != 3)
	{
		cout << "1.������ � ���������� ���������" << endl;
		cout << "2.������ � ������� � ����������� ������" << endl;
		cout << "3.�����" << endl;
		bool fail = true;
		while (fail)
		{
			cin >> choice;
			if (choice > 0 && choice <= 3)
			{
				return choice;
			}
			else
			{
				cout << "�� ����� �������� ��������, ���������� ��� ���" << endl;
				cin.clear();
				cin.ignore(1048, '\n');//������ ������������� ������ � ������� �����
			}
		}

	}
}

int StudentMenu::choiceMenu(string s)
{
	system("cls");
	cout << "\t\t\t\t\t�������: " << s << endl << endl << endl << endl;
	int choice = 1;
	while (choice != 3)
	{
		cout << "1.������ ����" << endl;
		cout << "2.����������" << endl;
		cout << "3.�����" << endl;
		bool fail = true;
		while (fail)
		{
			cin >> choice;
			if (choice > 0 && choice <= 3)
			{
				return choice;
			}
			else
			{
				cout << "�� ����� �������� ��������, ���������� ��� ���" << endl;
				cin.clear();
				cin.ignore(1048, '\n');//������ ������������� ������ � ������� �����
			}
		}

	}
}

int TestMenu::choiceMenu(string s)
{
	system("cls");
	cout << "\t\t\t\t\t�������: " << s << endl << endl << endl << endl;
	int choice = 1;
	while (choice != 3)
	{
		cout << "1.������ �++" << endl;
		cout << "2.���" << endl;
		cout << "3.STL-����������" << endl;
		cout << "4.�����"<< endl;
		bool fail = true;
		while (fail)
		{
			cin >> choice;
			if (choice > 0 && choice <= 4)
			{
				return choice;
			}
			else
			{
				cout << "�� ����� �������� ��������, ���������� ��� ���" << endl;
				cin.clear();
				cin.ignore(1048, '\n');//������ ������������� ������ � ������� �����
			}
		}

	}
}