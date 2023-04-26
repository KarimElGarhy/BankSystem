#pragma once
#include <iostream>
#include "Employee.h"
#include "Admin.h"
#include "ClientManager.h"
#include"FileHelper.h"
#include <windows.h>

using namespace std;
class EmployeeManager
{
public:
	static void returnToMenu(Employee* e) {

		printEmployeeMenu();
		employeeOptions(e);
	}
	static void printEmployeeMenu()
	{
		system("cls");
		cout << "\t\t\t\t\t\tEmployee Functions\n";
		cout << "1-Add New Client\n";
		cout << "2-List Of All Clients\n";
		cout << "3-Search For A Client\n";
		cout << "4-Edit Client\n";
		cout << "5-Display\n";

		cout << "6-Logout\n";
		cout << endl;
	}

	static void newClient(Employee* e)
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
			
			c->setId(id+1); c->setName(name); c->setPassword(password); c->setBalance(balance);
			e->addClient(*c);
			FileHelper::saveClient(*c);

			cout << "Client Has been Save, you will redirect to Employee Menu";

			Sleep(1500);
			returnToMenu(e);

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
				newClient(e);
			}
			else if (x == 2)
			{
				returnToMenu(e);
			}
			else
			{
				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				returnToMenu(e);
			}
		}
	}

	static void listAllClients(Employee* e)
	{
		for (int i = 0; i < allClients.size(); i++)
		{
			e->listClient(allClients[i]);
			cout << "=================\n";
		}
		cout << "\n";
		cout << "\n1 - Employee Menu \n";
		cout << "2 - Exit\n";
		int x;
		cout << "\nEnter Your Choice  : ";
		cin >> x;
		system("cls");
		if (x == 1)
		{
			printEmployeeMenu();
			employeeOptions(e);
		}
		if (x == 2)
		{
			exit(0);
		}
	}

	static void searchForClient(Employee* e)
	{
		int id;
		cout << "enter id:\n";
		cin >> id;
		Client* c = e->searchClient(id);
		if (c)
		{
			c->display();
			cout << "\n";
			cout << "\n1 - Employee Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(e);
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

	static void editClientInfo(Employee* employee)
	{
		int x;
		int id;
		string name, password;
		double balance;
		cout << "Enter Id : ";
		cin >> id;

		Client* client = employee->searchClient(id);

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

				employee->editClient(id, name, password, balance);

				FileHelper::clearFile("Client.txt");

				FileHelper::saveAllClientsFromVector();

				cout << "Client has been changed";
				returnToMenu(employee);
				break;
			}
			case 2:
			{
				cout << "\nEnter New Name : ";
				cin >> name;
				password = client->getPassword();
				balance = client->getBalance();
				employee->editClient(id, name, password, balance);
				FileHelper::clearFile("Client.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Client has been changed";
				returnToMenu(employee);
				break;
			}
			case 3:
			{
				cout << "\nEnter New Password : ";
				cin >> password;
				name = client->getName();
				balance = client->getBalance();
				employee->editClient(id, name, password, balance);
				FileHelper::clearFile("Client.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Client has been changed";
				returnToMenu(employee);
				break;
			}
			case 4:
			{
				cout << "\nEnter New Balance : ";
				cin >> balance;
				name = client->getName();
				password = client->getPassword();
				employee->editClient(id, name, password, balance);
				FileHelper::clearFile("Client.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "Client has been changed";
				returnToMenu(employee);
				break;
			}
			default:
			{

				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				editClientInfo(employee);
				returnToMenu(employee);
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
				editClientInfo(employee);
			}
			else if (x == 2)
			{
				printEmployeeMenu();
				employeeOptions(employee);
			}
			else
			{
				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				printEmployeeMenu();
				employeeOptions(employee);
			}
		}
	}

	static Employee* login(int id, string password)
	{
		Admin* a = new Admin();
		Employee* e = a->searchEmployee(id);
		if (e)
		{
			if (e->getPassword() == password)
			{
				return e;
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

	static bool employeeOptions(Employee* employee)
	{
		int x = 0;

		cout << "Enter your choise : ";

		cin >> x;

		switch (x)
		{
		case 1:
		{
			system("cls");
			newClient(employee);
			break;
		}
		case 2:
		{
			system("cls");
			listAllClients(employee);
			break;
		}
		case 3:
		{
			system("cls");
			searchForClient(employee);
			break;
		}
		case 4:
		{
			system("cls");
			editClientInfo(employee);
			break;
		}
		case 5:
		{
			system("cls");
			employee->display();
			cout << "\n";
			cout << "\n1 - Employee Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(employee);
			}
			if (x == 2)
			{
				exit(0);
			}

			break;
		}

		case 6:
		{
			return true;
		}
		default:
		{
			cout << "\nYour Choice Not Found In List\n";
			employeeOptions(employee);
		}
		}
		return false;
	}
};

