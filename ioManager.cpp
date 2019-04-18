#include "ioManager.h"

void ioManager::displayMenu() const
{
	cout << "================================================" << endl;
	cout << "  1) �л� �߰�" << endl;
	cout << "  2) �л� ����" << endl;
	cout << "  3) �л� ���" << endl;
	cout << "  4) ����" << endl;
	cout << "================================================" << endl;
}

void ioManager::insertStudent(StudentList &studentList) const
{
	int id = getInteger("  �߰��� �л��� �й�: ");

	int index = studentList.findIndex(id);

	if (index == NOT_EXIST)
	{
		string name = getString("                ����: ");
		string department = getString("                �а�: ");
		string tel = getString("                ��ȭ��ȣ: ");
		string address = getString("                �ּ�: ");

		index = studentList.findIndex(id, TO_INSERT);

		studentList.insertStudent(new Student(id, name, department, tel, address), index);

		cout << "  [�߰� �Ϸ�]" << endl;
	}
	else
	{
		cout << "  [�߰� ����] �й��� ���� �л��� �Ͱ� �ߺ��˴ϴ�." << endl;
	}
}

void ioManager::deleteStudent(StudentList &studentList) const
{
	int id = getInteger("  ������ �л��� �й�: ");

	int index = studentList.findIndex(id);

	if (index == NOT_EXIST)
	{
		cout << "  [���� ����] �ش� �л��� ã�� �� �����ϴ�." << endl;
	}
	else
	{
		studentList.deleteStudent(index);

		cout << "  [���� �Ϸ�]" << endl;
	}
}

void ioManager::displayStudent(StudentList &studentList) const
{
	int count = studentList.getCount();

	if (count == 0)
	{
		cout << "  [��� ����] ��ϵ� �л��� �����ϴ�." << endl;
	}
	else
	{
		for (int i = 0; i < count; i += 1)
		{
			const Student &student = studentList.getStudent(i);

			cout << "  �й�: " << student.getId() << ", ����: " << student.getName() << ", �а�: " << student.getDepartment() << ", ��ȭ��ȣ: " << student.getTel() << ", �ּ�: " << student.getAddress() << endl;
		}

		cout << "  [��� �Ϸ�]" << endl;
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
		int select = getInteger("\n���: ");

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
