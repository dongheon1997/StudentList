#pragma once

#include "Student.h"

enum { NOT_EXIST = -1, TO_INSERT = 1 };

class StudentList
{
private:
	Student **studentList;
	int count;
	int size;

	void resize();

public:
	StudentList();
	~StudentList();

	const Student &getStudent(int index) const { return *studentList[index]; }
	int getCount() const { return count; }

	void insertStudent(Student *student, int index);
	void deleteStudent(int index);
	int findIndex(int id, bool toInsert = false) const;
};
