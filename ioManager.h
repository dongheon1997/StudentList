#pragma once

#include "StudentList.h"

class ioManager
{
private:
	void displayMenu() const;
	void insertStudent(StudentList &studentList) const;
	void deleteStudent(StudentList &studentList) const;
	void displayStudent(StudentList &studentList) const;

	int getInteger(string msg) const;
	string getString(string msg) const;

public:
	void run(StudentList &studentList) const;
};
