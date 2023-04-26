#pragma once
#include <fstream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
#include "Parser.h"
class FileHelper
{
public:
	static void saveLast(string fileName, int id) {
		ofstream file;
		file.open(fileName);
		file << id;
		file.close();
	}
	static int getLast(string fileName) {
		ifstream file;
		file.open(fileName);
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveClient(Client c)
	{
		int id = getLast("lasID.txt");
		fstream file("Client.txt", ios::binary | ios::app);
		file << id + 1
			<< '|' << c.getName()
			<< '|' << c.getPassword()
			<< '|' << c.getBalance() << endl;
		file.close();
		saveLast("lasID.txt", id + 1);
	}

	static void saveClientFromVector(Client c)
	{
		fstream file("Client.txt", ios::binary | ios::app);
		file << c.getId()
			<< '|' << c.getName()
			<< '|' << c.getPassword()
			<< '|' << c.getBalance() << endl;
		file.close();
	}
	static void saveEmployeeFromVector(Employee e)
	{
		fstream file("Employee.txt", ios::binary | ios::app);
		file << e.getId()
			<< '|' << e.getName()
			<< '|' << e.getPassword()
			<< '|' << e.getSalary() << endl;
		file.close();
	}
	static void saveAdminFromVector(Admin a)
	{
		fstream file("Admin.txt", ios::binary | ios::app);
		file << a.getId()
			<< '|' << a.getName()
			<< '|' << a.getPassword()
			<< '|' << a.getSalary() << endl;
		file.close();
	}

	static void saveEmployee(Employee e)
	{
		int id = getLast("lasID.txt");
		fstream file("Employee.txt", ios::binary | ios::app);
		file << id + 1
			<< '|' << e.getName()
			<< '|' << e.getPassword()
			<< '|' << e.getSalary() << endl;
		file.close();
		saveLast("lasID.txt", id + 1);
	}

	static void saveAdmin(Admin a)
	{
		int id = getLast("lasID.txt");
		fstream file("Admin.txt", ios::binary | ios::app);
		file << id + 1
			<< '|' << a.getName()
			<< '|' << a.getPassword()
			<< '|' << a.getSalary() << endl;
		file.close();
		saveLast("lasID.txt", id + 1);
	}

	static void getClients()
	{
		fstream file("Client.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			Client c = Parser::parseToClient(line);
			allClients.push_back(c);
		}
		file.close();
	}
	static void getEmployees()
	{
		fstream file("Employee.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			Employee e = Parser::parseToEmployee(line);
			allEmployees.push_back(e);
		}
		file.close();
	}

	static void getAdmins()
	{
		fstream file("Admin.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			Admin a = Parser::parseToAdmin(line);
			allAdmins.push_back(a);
		}
		file.close();
	}
	static void saveAllAdmins() {
		for (int i = 0; i < allAdmins.size(); i++) {
			saveAdmin(allAdmins[i]);
		}
	}

	static void saveAllClients() {
		for (int i = 0; i < allClients.size(); i++) {
			saveClient(allClients[i]);
		}
	}
	static void saveAllEmployees() {
		for (int i = 0; i < allEmployees.size(); i++) {
			saveEmployee(allEmployees[i]);
		}
	}
	static void saveAllClientsFromVector() {
		for (int i = 0; i < allClients.size(); i++) {
			saveClientFromVector(allClients[i]);
		}
	}
	static void saveAllEmployeesFromVector() {
		for (int i = 0; i < allEmployees.size(); i++) {
			saveEmployeeFromVector(allEmployees[i]);
		}
	}
	static void saveAllAdminsFromVector() {
		for (int i = 0; i < allAdmins.size(); i++) {
			saveAdminFromVector(allAdmins[i]);
		}
	}

	static void clearFile(string fileName)
	{
		fstream file(fileName, ios::out | ios::trunc);
		file.close();
	}
};

