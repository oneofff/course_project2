#pragma once
#include <iostream>
#include <string>
using namespace std;
class Menu
{
public:
	virtual int choiceMenu(string) = 0;

private:

};
class LogMenu :Menu
{
public:
	int choiceMenu(string) override;
};
class TeacherMenu :Menu
{
public:
	int choiceMenu(string) override;
};
class StudentMenu :Menu
{
public:
	int choiceMenu(string) override;
};
class TestMenu :Menu
{
public:
	int choiceMenu(string) override;
};