#pragma once
#include <iostream>
#include "EmployeeManager.h"
#include "Employee.h"
#include "Admin.h"
#include"FileHelper.h"
using namespace std;
class AdminManager
{
public:
	static void printAdminMenu()
	{
		system("cls");
		cout << "\t\t\t\t\t\tAdmin Functions\n";
		cout << "1-Add New Client\n";
		cout << "2-List Of All Clients\n";
		cout << "3-Search For A Client\n";
		cout << "4-Edit Client\n";
		cout << "5-Add New Employee\n";
		cout << "6-List Of All Employee\n";
		cout << "7-Search For An Employee\n";
		cout << "8-Edit Employee\n";
		cout << "9-Display\n";
		cout << "10-Logout\n";
		cout << endl;
	}


	static void returnToMenu(Admin* a) {

		printAdminMenu();
		AdminOptions(a);
	}

	/*Client Operation*/

	static void newClient(Admin* a)
	{
		string name, password;
		double balance;
		cout << "enter name:\n";
		cin >> name;
		cout << "enter password:\n";
		cin >> password;
		cout << "enter balance:\n";
		cin >> balance;


		Client* c = new Client();

		if (Validation::CheckName(name) && Validation::checkPassword(password) && Validation::checkBalance(balance))
		{
			int id = FileHelper::getLast("lasID.txt");

			c->setId(id + 1); c->setName(name); c->setPassword(password); c->setBalance(balance);
			a->addClient(*c);
			FileHelper::saveClient(*c);

			cout << "Client Has been Save, you will redirect to Admin Menu";

			Sleep(1500);
			returnToMenu(a);

		}
		else
		{
			cout << "New Client Did not suitable please confirm that Name is Alpha only & password from 5-20 char. and  balance > 1500\n";

			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				newClient(a);
			}
			else if (x == 2)
			{
				returnToMenu(a);
			}
			else
			{
				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				returnToMenu(a);
			}
		}
	}

	static void listAllClients(Admin* a)
	{
		for (int i = 0; i < allClients.size(); i++)
		{
			a->listClient(allClients[i]);
			cout << "=================\n";
		}
		cout << "\n";
		cout << "\n1 - Admin Menu \n";
		cout << "2 - Exit\n";
		int x;
		cout << "\nEnter Your Choice  : ";
		cin >> x;
		system("cls");
		if (x == 1)
		{
			printAdminMenu();
			AdminOptions(a);
		}
		if (x == 2)
		{
			exit(0);
		}

	}

	static void searchForClient(Admin* a)
	{
		int id;
		cout << "enter id:\n";
		cin >> id;
		Client* c = a->searchClient(id);
		if (c)
		{
			c->display();
			cout << "\n";
			cout << "\n1 - Admin Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(a);
			}
			if (x == 2)
			{
				exit(0);
			}
		}
		else
		{
			cout << "not found\n";

		}
	}

	static void editClientInfo(Admin* admin)
	{
		int x;
		int id;
		string name, password;
		double balance;
		cout << "Enter Id : ";
		cin >> id;

		Client* client = admin->searchClient(id);

		if (client != nullptr)
		{
			cout << "\nWhat You Want To Edit : \n";
			cout << "1-All data\n";
			cout << "2-Name\n";
			cout << "3-Password\n";
			cout << "4-Balance\n";

			cout << "\nEnter Your Choice : ";
			cin >> x;

			switch (x)
			{
			case 1:
			{
				cout << "\nEnter New Name : ";
				cin >> name;
				cout << "\nEnter New Password : ";
				cin >> password;
				cout << "\nEnter New balance : ";
				cin >> balance;
				admin->editClient(id, name, password, balance);
				FileHelper::clearFile("Client.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Client has been changed";
				returnToMenu(admin);
				break;
			}
			case 2:
			{
				cout << "\nEnter New Name : ";
				cin >> name;
				password = client->getPassword();
				balance = client->getBalance();
				admin->editClient(id, name, password, balance);
				FileHelper::clearFile("Client.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Client has been changed";
				returnToMenu(admin);
				break;
			}
			case 3:
			{
				cout << "\nEnter New Password : ";
				cin >> password;
				name = client->getName();
				balance = client->getBalance();
				admin->editClient(id, name, password, balance);
				FileHelper::clearFile("Client.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Client has been changed";
				returnToMenu(admin);
				break;
			}
			case 4:
			{
				cout << "\nEnter New Balance : ";
				cin >> balance;
				name = client->getName();
				password = client->getPassword();
				admin->editClient(id, name, password, balance);
				FileHelper::clearFile("Client.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Client has been changed";
				returnToMenu(admin);
				break;
			}
			default:
			{

				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				editClientInfo(admin);
				returnToMenu(admin);
				break;
			}
			}
		}
		else
		{
			cout << "\n************************\n";
			cout << "Client not found\n\n";
			cout << "************************\n\n";
			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				editClientInfo(admin);
			}
			else if (x == 2)
			{
				printAdminMenu();
				AdminOptions(admin);
			}
			else
			{
				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				printAdminMenu();
				AdminOptions(admin);
			}
		}
	}
	/*End Client Operation*/

	static Admin* login(int id, string password)
	{
		Admin* a = searchForAdmin(id);
		if (a)
		{
			if (a->getPassword() == password)
			{
				return a;
			}
			else
			{
				cout << "Password incorrect" << endl;
				return nullptr;
			}
		}
		else
		{
			cout << "id incorrect" << endl;
			return nullptr;
		}
	}

	static Admin* searchForAdmin(int id)
	{
		Admin* a;
		for (int i = 0; i < allAdmins.size(); i++)
		{
			if (allAdmins[i].getId() == id)
			{
				a = &allAdmins[i];
				return a;
			}
		}
		return nullptr;
	}

	static void newEmployee(Admin* a)
	{

		string name, password;
		double salary;
		cout << "enter name:\n";
		cin >> name;
		cout << "enter password:\n";
		cin >> password;
		cout << "enter Salary:\n";
		cin >> salary;


		Employee* e = new Employee();

		if (Validation::CheckName(name) && Validation::checkPassword(password) && Validation::checkSalary(salary))
		{
			int id = FileHelper::getLast("lasID.txt");

			e->setId(id + 1); e->setName(name); e->setPassword(password); e->setSalary(salary);

			a->addEmployee(*e);

			FileHelper::saveEmployee(*e);

			cout << "Employee Has been Save, you will redirect to Admin Menu";

			Sleep(1500);

			returnToMenu(a);

		}
		else
		{
			cout << "New Employee Did not suitable please confirm that Name is Alpha only & password from 5-20 char. and  Salary > 5000\n";

			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				newEmployee(a);
			}
			else if (x == 2)
			{
				returnToMenu(a);
			}
			else
			{
				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				returnToMenu(a);
			}
		}
	}

	static void listAllEmployees(Admin* a)
	{
		for (int i = 0; i < allEmployees.size(); i++)
		{
			a->listEmployee(allEmployees[i]);
			cout << "=================\n";
		}
		cout << "\n";
		cout << "\n1 - Admin Menu \n";
		cout << "2 - Exit\n";
		int x;
		cout << "\nEnter Your Choice  : ";
		cin >> x;
		system("cls");
		if (x == 1)
		{
			printAdminMenu();
			AdminOptions(a);
		}
		if (x == 2)
		{
			exit(0);
		}
	}

	static void searchForEmployee(Admin* a)
	{
		int id;
		cout << "enter id:\n";
		cin >> id;
		Employee* e = a->searchEmployee(id);
		if (e)
		{
			e->display();
			cout << "\n";
			cout << "\n1 - Admin Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(a);
			}
			if (x == 2)
			{
				exit(0);
			}
		}
		else
		{
			cout << "not found\n";
		}
	}

	static void editEmployeeInfo(Admin* a)
	{
		int x;
		int id;
		string name, password;
		double salary;
		cout << "Enter Id : ";
		cin >> id;

		Employee* e = a->searchEmployee(id);

		if (e != nullptr)
		{
			cout << "\nWhat You Want To Edit : \n";
			cout << "1-All data\n";
			cout << "2-Name\n";
			cout << "3-Password\n";
			cout << "4-Salary\n";

			cout << "\nEnter Your Choise : ";
			cin >> x;

			switch (x)
			{
			case 1:
			{
				cout << "\nEnter New Name : ";
				cin >> name;
				cout << "\nEnter New Password : ";
				cin >> password;
				cout << "\nEnter New salary : ";
				cin >> salary;

				a->editEmployee(id, name, password, salary);
				FileHelper::clearFile("Employee.txt");
				FileHelper::saveAllEmployeesFromVector();
				cout << "Employee has been changed";
				returnToMenu(a);
				break;
			}
			case 2:
			{
				cout << "\nEnter New Name : ";
				cin >> name;
				password = e->getPassword();
				salary = e->getSalary();
				a->editEmployee(id, name, password, salary);
				FileHelper::clearFile("Admin.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Employee has been changed";
				returnToMenu(a);
				break;
			}
			case 3:
			{
				cout << "\nEnter New Password : ";
				cin >> password;
				name = e->getName();
				salary = e->getSalary();
				a->editClient(id, name, password, salary);
				FileHelper::clearFile("Admin.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Employee has been changed";
				returnToMenu(a);
				break;
			}
			case 4:
			{
				cout << "\nEnter New Salary : ";
				cin >> salary;
				name = e->getName();
				password = e->getPassword();
				a->editEmployee(id, name, password, salary);
				FileHelper::clearFile("Admin.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "\nEmployee has been changed\n";
				returnToMenu(a);
				break;
			}
			default:
			{

				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				editEmployeeInfo(a);
				returnToMenu(a);
				break;
			}
			}
		}
		else
		{
			cout << "\n************************\n";
			cout << "Employee not found\n\n";
			cout << "************************\n\n";
			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				editEmployeeInfo(a);
			}
			else if (x == 2)
			{
				printAdminMenu();
				AdminOptions(a);
			}
			else
			{
				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				printAdminMenu();
				AdminOptions(a);
			}
		}
	}

	static bool AdminOptions(Admin* admin)
	{
		int x = 0;

		cout << "Enter your choise : ";

		cin >> x;

		switch (x)
		{
		case 1:
		{
			system("cls");
			newClient(admin);
			break;
		}
		case 2:
		{
			system("cls");
			listAllClients(admin);
			break;
		}
		case 3:
		{
			system("cls");
			searchForClient(admin);
			break;
		}
		case 4:
		{
			system("cls");
			editClientInfo(admin);
			break;
		}
		case 5:
		{
			system("cls");
			newEmployee(admin);
			break;
		}
		case 6:
		{
			system("cls");
			listAllEmployees(admin);
			break;
		}
		case 7:
		{
			system("cls");
			searchForEmployee(admin);
			break;
		}
		case 8:
		{
			system("cls");
			editEmployeeInfo(admin);
			break;
		}
		case 9:
		{
			system("cls");
			admin->display();
			cout << "\n";
			cout << "\n1 - Admin Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(admin);
			}
			if (x == 2)
			{
				exit(0);
			}
			break;
		}

		case 10:
		{
			return true;
		}
		default:
		{
			cout << "\n*************************************\n";
			cout << "Your Choise Not Found In List\n";
			cout << "*************************************\n\n";
			AdminOptions(admin);
		}
		}
		return false;
	}
};

