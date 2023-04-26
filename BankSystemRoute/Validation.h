#pragma once
#include <string>
#include <iostream>
using namespace std;

class Validation
{
public:
	static bool CheckName(string name) {
		for (int i = 0; i < name.length(); i++) {
			if (!isalpha(name[i])) {
				return false;
			}
		}
		if (name.length() <= 20 && name.length() >= 5) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool checkPassword(string password) {
		if (password.length() <= 20 && password.length() >= 8) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool checkBalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		else return true;
	}
	static bool checkSalary(double salary) {
		if (salary < 5000) {
			return false;
		}
		else return true;
	}
};

