#include "ioManager.h"

void ioManager::displayMenu() const
{
	cout << "================================================" << endl;
	cout << "  1) 학생 추가" << endl;
	cout << "  2) 학생 삭제" << endl;
	cout << "  3) 학생 출력" << endl;
	cout << "  4) 종료" << endl;
	cout << "================================================" << endl;
}

void ioManager::insertStudent(StudentList &studentList) const
{
	int id = getInteger("  추가할 학생의 학번: ");

	int index = studentList.findIndex(id);

	if (index == NOT_EXIST)
	{
		string name = getString("                성명: ");
		string department = getString("                학과: ");
		string tel = getString("                전화번호: ");
		string address = getString("                주소: ");

		index = studentList.findIndex(id, TO_INSERT);

		studentList.insertStudent(new Student(id, name, department, tel, address), index);

		cout << "  [추가 완료]" << endl;
	}
	else
	{
		cout << "  [추가 실패] 학번이 기존 학생의 것과 중복됩니다." << endl;
	}
}

void ioManager::deleteStudent(StudentList &studentList) const
{
	int id = getInteger("  삭제할 학생의 학번: ");

	int index = studentList.findIndex(id);

	if (index == NOT_EXIST)
	{
		cout << "  [삭제 실패] 해당 학생을 찾을 수 없습니다." << endl;
	}
	else
	{
		studentList.deleteStudent(index);

		cout << "  [삭제 완료]" << endl;
	}
}

void ioManager::displayStudent(StudentList &studentList) const
{
	int count = studentList.getCount();

	if (count == 0)
	{
		cout << "  [출력 실패] 등록된 학생이 없습니다." << endl;
	}
	else
	{
		for (int i = 0; i < count; i += 1)
		{
			const Student &student = studentList.getStudent(i);

			cout << "  학번: " << student.getId() << ", 성명: " << student.getName() << ", 학과: " << student.getDepartment() << ", 전화번호: " << student.getTel() << ", 주소: " << student.getAddress() << endl;
		}

		cout << "  [출력 완료]" << endl;
	}
}

int ioManager::getInteger(string msg) const
{
	int integer;
	cout << msg;
	cin >> integer;
	cin.ignore();
	return integer;
}

string ioManager::getString(string msg) const
{
	string str;
	cout << msg;
	getline(cin, str);
	return str;
}

void ioManager::run(StudentList &studentList) const
{
	displayMenu();

	enum { INSERT = 1, DELETE = 2, DISPLAY = 3, QUIT = 4 };

	while (1)
	{
		int select = getInteger("\n명령: ");

		switch (select)
		{
		case INSERT:
			insertStudent(studentList);
			break;
		case DELETE:
			deleteStudent(studentList);
			break;
		case DISPLAY:
			displayStudent(studentList);
			break;
		case QUIT:
			return;
		}
	}
}
