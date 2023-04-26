#pragma once
#include <iostream>
#include "Person.h"
#include "Client.h"
#include "Validation.h"

class Employee :
	public Person
{
protected:
	double salary;
public:
	//Constructor
	Employee(int id, string name, string password, double balance) :Person(id, name, password) {
		setSalary(balance);
	}
	Employee(string name, string password, double balance) :Person(name, password) {
		setSalary(balance);
	}

	Employee() :Person() {

	}
	//Setter
	void setSalary(double salary) {
		if (Validation::checkSalary(salary)) {
			this->salary = salary;
		}
		else {
			cout << "Salary Must be greater than 5000 \n";
		}
	}
	//Getter
	double getSalary() {
		return this->salary;
	}
	//Methods
	void display() {
		cout << endl << "============================" << endl;
		cout << "Employee info " << endl;
		cout << "============================" << endl;
		Person::display();
		cout << "salary : " << getSalary();
	}
	void addClient(Client& c) {
		allClients.push_back(c);
	}

	Client* searchClient(int id) {
		for (int i = 0; i < allClients.size(); i++) {
			if (allClients[i].getId() == id) {
				Client* c = &allClients[i];
				return c;
			}
		}
		return nullptr;
	}
	void listClient(Client c) {
		cout << c.getId() << endl;
		cout << c.getName() << endl;
		cout << c.getPassword() << endl;
		cout << c.getBalance() << endl;
	}
	void editClient(int id, string name, string password, double balance) {
		Client* c = searchClient(id);
		c->setName(name);
		c->setPassword(password);
		c->setBalance(balance);
	}
};

static vector<Employee> allEmployees;
