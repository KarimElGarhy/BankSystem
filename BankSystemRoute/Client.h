#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"
using namespace std;

class Client :
	public Person
{
private:
	static int counter ;
	double balance;
public:
	//Setter
	void setBalance(double balance) {
		if (Validation::checkBalance) {
			this->balance = balance;
		}
		else {
			cout << "Balance Must be > 1500";
		}
	}
	//Getter
	double getBalance() {
		return balance;
	}
	//Methods
	void deposit(double amount) {
		if (amount > 0) {
			this->balance += amount;
		}
		else {
			cout << "Invalid Amount \n";
		}
	}
	void withdraw(double amount) {
		if (amount <= this->balance && amount > 0) {
			this->balance -= amount;
		}
		else
		{
			cout << "Amount Exceeded Balance" << endl << "Your Balance now Is:  " << getBalance();;
		}
	}
	void transferTo(Client& recivedAccount, double amount) {
		withdraw(amount);
		recivedAccount.deposit(amount);
		cout << "\n ---------Transfer done! \n";
	}
	void checkBalance() {
		cout << "Your Balance is: " << getBalance();
	}
	void display() {
		cout << endl << "============================" << endl;
		cout << "Client info " << endl;
		cout << "============================" << endl;
		Person::display();
		cout << "Balance : " << getBalance() << endl;
	}
	//Constructor
	Client(int id, string name, string password, double balance) :Person(id, name, password) {
		setBalance(balance);
	}
	Client(string name, string password, double balance) :Person(name, password) {
		setBalance(balance);
	}
	Client() :Person() {
		setBalance(0);
	}
};
static vector<Client> allClients;

