#pragma once
#include <string>
#include <vector>
#include "Employee.h"
class Admin :
	public Employee
{
public:
	//Constructor
	Admin()
	{

	}

	Admin(int id, string name, string password, double salary)
		:Employee(id, name, password, salary) {

	}
	Admin(string name, string password, double salary) :Employee(name, password, salary) {

	}
	void addEmployee(Employee& c)
	{
		allEmployees.push_back(c);
	}

	Employee* searchEmployee(int id)
	{
		for (int i = 0; i < allEmployees.size(); i++)
		{
			if (allEmployees[i].getId() == id)
			{
				Employee* c = &allEmployees[i];
				return c;
			}
		}
		return nullptr;
	}

	void listEmployee(Employee c)
	{
		cout << c.getId() << endl;
		cout << c.getName() << endl;
		cout << c.getPassword() << endl;
		cout << c.getSalary() << endl;
	}

	void editEmployee(int id, string name, string password, double salary)
	{
		Employee* c = searchEmployee(id);
		c->setName(name);
		c->setPassword(password);
		c->setSalary(salary);
	}

};

static vector<Admin> allAdmins;