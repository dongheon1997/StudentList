#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	int id;
	string name;
	string department;
	string tel;
	string address;

public:
	Student(int id, string name, string department, string tel, string address);

	int getId() const { return id; }
	string getName() const { return name; }
	string getDepartment() const { return department; }
	string getTel() const { return tel; }
	string getAddress() const { return address; }
};
