#include "StudentList.h"

StudentList::StudentList()
{
	size = 8;
	studentList = new Student *[size];
	count = 0;
}

StudentList::~StudentList()
{
	for (int i = 0; i < count; i += 1)
	{
		delete studentList[i];
	}
	delete[] studentList;
}

void StudentList::resize()
{
	size *= 2;
	Student **temp = new Student *[size];
	for (int i = 0; i < count; i += 1)
	{
		temp[i] = studentList[i];
	}
	delete[] studentList;
	studentList = temp;
}

void StudentList::insertStudent(Student *student, int index)
{
	if (count == size)
	{
		resize();
	}
	for (int i = count; i > index; i -= 1)
	{
		studentList[i] = studentList[i - 1];
	}
	studentList[index] = student;
	count += 1;
}

void StudentList::deleteStudent(int index)
{
	delete studentList[index];
	count -= 1;
	for (int i = index; i < count; i += 1)
	{
		studentList[i] = studentList[i + 1];
	}
}

int StudentList::findIndex(int id, bool toInsert/*false*/) const
{
	int left = 0, right = count - 1, mid;

	while (true)
	{
		if (right < left)
		{
			if (toInsert) return left;
			else return NOT_EXIST;
		}

		mid = (left + right) / 2;

		if (studentList[mid]->getId() == id)
		{
			return mid;
		}
		else if (studentList[mid]->getId() > id)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
}
