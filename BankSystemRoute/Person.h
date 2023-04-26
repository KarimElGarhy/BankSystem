#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Validation.h"
using namespace std;

class Person
{
private:
	string name, password;
protected:
	int id;
	//static int nextId;
public:
	//Setter
	void setId(int id) {

		
		this->id = id;
	}
	void setName(string name) {
		if (Validation::CheckName(name)) {
			this->name = name;
		}
		else {
			cout << "The Name Must Be Only Characters and Between 5-20. \n";
		}
	}
	void setPassword(string password) {
		if (Validation::checkPassword(password)) {
			this->password = password;
		}
		else {
			cout << "The Password Must Be Between 5-20. \n";
		}
	}
	//Getter
	int getId() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getPassword() {
		return this->password;
	}
	//Constructor
	Person(int id, string name, string password) {
		setName(name);
		setPassword(password);
	}
	Person( string name, string password) {
		/*setId();*/
		setName(name);
		setPassword(password);
	}
	Person() {
		//setId();;
	}
	//Methods
	void display() {
		cout << "ID		: " << getId() << endl;
		cout << "Name		: " << getName() << endl;
		cout << "Password	: " << getPassword() << endl;
	}


};

