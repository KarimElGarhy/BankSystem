#pragma once
#include <iostream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include"FileHelper.h"
using namespace std;

class ClientManager
{
public:
	static void returnToMenu(Client* c) {

		printClientMenu();
		clientOptions(c);
	}
	static void printClientMenu()
	{
		system("cls");
		cout << "\t\t\t\t\t\tClient Functions\n";
		cout << "1-Deposit\n";
		cout << "2-Withdraw\n";
		cout << "3-transferTo\n";
		cout << "4-checkBalance\n";
		cout << "5-Display\n";
		cout << "6-Logout\n";
		cout << endl;
	}
	static void updatePassword(Person* p)
	{
		string password;
		cout << "enter new password" << endl;
		cin >> password;
		p->setPassword(password);

	}
	static Client* login(int id, string password)
	{
		Employee* e = new Employee();
		Client* c = e->searchClient(id);
		if (c)
		{
			if (c->getPassword() == password)
			{
				return c;
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
	static bool clientOptions(Client* _Client)
	{
		int x = 0;

		cout << "Enter your choise : ";

		cin >> x;

		switch (x)
		{
		case 1:
		{
			system("cls");
			double amount = 0;
			cout << "Enter Amount To Deposit : ";
			cin >> amount;
			_Client->deposit(amount);

			FileHelper::clearFile("Client.txt");
			FileHelper::saveAllClientsFromVector();

			cout << "\n";
			cout << "\n1 - Client Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(_Client);
			}
			if (x == 2)
			{
				exit(0);
			}
			break;
		}
		case 2:
		{
			system("cls");
			double amount = 0;
			cout << "Enter Amount To Withdraw : ";
			cin >> amount;
			_Client->withdraw(amount);

			FileHelper::clearFile("Client.txt");
			FileHelper::saveAllClientsFromVector();


			cout << "\n";
			cout << "\n1 - Client Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(_Client);
			}
			if (x == 2)
			{
				exit(0);
			}
			break;
		}
		case 3:
		{
			system("cls");
			double amount = 0;
			Client* otherClient;
			Employee* e = new Employee();
			int id = 0;
			cout << "Enter Client Id you want TransferTo : ";
			cin >> id;
			otherClient = e->searchClient(id);
			cout << "Enter Amount To transferTo : ";
			cin >> amount;
			if (otherClient != nullptr)
			{
				_Client->transferTo(*otherClient, amount);
				FileHelper::clearFile("Client.txt");
				FileHelper::saveAllClientsFromVector();
				cout << "\n";
				cout << "\n1 - Client Menu \n";
				cout << "2 - Exit\n";
				int x;
				cout << "\nEnter Your Choice  : ";
				cin >> x;
				system("cls");
				if (x == 1)
				{
					returnToMenu(_Client);
				}
				if (x == 2)
				{
					exit(0);
				}
			}
			else
			{
				cout << "\n******************************************\n";
				cout << "The Other Client Not Found In System\n";
				cout << "******************************************\n\n";
			}
			break;
		}
		case 4:
		{
			system("cls");
			_Client->checkBalance();
			cout << "\n";
			cout << "\n1 - Client Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(_Client);
			}
			if (x == 2)
			{
				exit(0);
			}
			
			break;
		}
		case 5:
		{
			system("cls");
			_Client->display();
			cout << "\n";
			cout << "\n1 - Client Menu \n";
			cout << "2 - Exit\n";
			int x;
			cout << "\nEnter Your Choice  : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				returnToMenu(_Client);
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
			cout << "\n*************************************\n";
			cout << "Your Choise Not Found In List\n";
			cout << "*************************************\n\n";
			clientOptions(_Client);
		}
		}
		return false;
	}
};

