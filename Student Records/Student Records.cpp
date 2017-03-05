// Student Records.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void addStud();
void deleteStud();
void showStud();

class Student
{
	string id, name;
	int score;
	static int total;
	double grade;

	Student(string id, string name, int score)
	{
		this->id = id;
		this->name = name;
		this->score = score;
	}
};

LinkedList<Student*> l;   //TODO: modify this code (will cause memory leak if initialized).

int main()
{
	cout << "Welcome!" << endl;
	cout << "This program stores student information." << endl;
	cout << "Please choose the following:" << endl;
	while (true)
	{
		cout << "Press 1 to add student.\n";
		cout << "Press 2 to delete student\n";
		cout << "Press 3 to show student data.\n";
		cout << "Press 0 to exit.\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			addStud();
			break;
		case 2:
			deleteStud();
			break;
		case 3:
			showStud();
			break;
		default:
			cout << "Error! Please try again." << endl;
			break;
		}
	}
}

void addStud()
{

}

void deleteStud()
{

}

void showStud()
{

}

