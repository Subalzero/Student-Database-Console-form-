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
void clear();

class Student
{
public:
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

LinkedList<Student*> l;
int Student::total = 30;

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
			clear();
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
	string name, id;
	int score;
	cout << "Name: ";
	cin >> name;
	cout << "ID: ";
	cin >> id;
	cout << "Score: ";
	cin >> score;
	Student *s = new Student(id, name, score);
	l.addBack(s);
}

void deleteStud()
{
	showStud();
	int index;
	cout << "Indicate index to be deleted: ";
	cin >> index;
	Student *s = l.removeAt(index);
	delete s;
}

void showStud()
{
	for (int i = 0; i < l.size_of(); i++)
	{
		Student *s = l.itemAt(i);
		cout << "Name: " << s->name << endl;
		cout << "ID: " << s->id << endl;
		cout << "Score: " << s->score << endl;
	}
}

void clear()
{
	while (!l.isEmpty())
	{
		Student *s = l.removeFront();
		delete s;
	}
}

