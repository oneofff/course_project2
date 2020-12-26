#include "Menu.h"

int LogMenu::choiceMenu(string s)
{
	system("cls");
	cout << "\t\t\t\t\t\t" << s << endl << endl << endl<< endl;
	int choice = 1;
	while (choice != 4)
	{
		cout << "1.Войти как преподаватель" << endl;
		cout << "2.Войти как студент" << endl;
		cout << "3.Регистрация нового студента" << endl;
		cout << "4.Выход из программы" << endl;
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
				cout << "Вы ввели неверное значение, попробуйте еще раз" << endl;
				cin.clear();
				cin.ignore(1048, '\n');//убрать индетефикатор ошибки и отчисть буфер
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
		cout << "1.Работа с аккаунтами студентов" << endl;
		cout << "2.Работа с данными о прохождении тестов" << endl;
		cout << "3.Назад" << endl;
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
				cout << "Вы ввели неверное значение, попробуйте еще раз" << endl;
				cin.clear();
				cin.ignore(1048, '\n');//убрать индетефикатор ошибки и отчисть буфер
			}
		}

	}
}

int StudentMenu::choiceMenu(string s)
{
	system("cls");
	cout << "\t\t\t\t\tСтудент: " << s << endl << endl << endl << endl;
	int choice = 1;
	while (choice != 3)
	{
		cout << "1.Пройти тест" << endl;
		cout << "2.Результаты" << endl;
		cout << "3.Назад" << endl;
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
				cout << "Вы ввели неверное значение, попробуйте еще раз" << endl;
				cin.clear();
				cin.ignore(1048, '\n');//убрать индетефикатор ошибки и отчисть буфер
			}
		}

	}
}

int TestMenu::choiceMenu(string s)
{
	system("cls");
	cout << "\t\t\t\t\tСтудент: " << s << endl << endl << endl << endl;
	int choice = 1;
	while (choice != 3)
	{
		cout << "1.Основы С++" << endl;
		cout << "2.ООП" << endl;
		cout << "3.STL-библиотека" << endl;
		cout << "4.Назад"<< endl;
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
				cout << "Вы ввели неверное значение, попробуйте еще раз" << endl;
				cin.clear();
				cin.ignore(1048, '\n');//убрать индетефикатор ошибки и отчисть буфер
			}
		}

	}
}