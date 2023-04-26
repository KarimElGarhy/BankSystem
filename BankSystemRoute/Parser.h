#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
class Parser
{
public:
	static vector<string> split(string line)
	{
		vector<string> splitted_line;
		int pos = 0;

		while (pos != -1)
		{
			pos = line.find("|");
			string mycut = line.substr(0, pos);
			splitted_line.push_back(mycut);
			line = line.substr(pos + 1);
		}

		return splitted_line;
	}

	static Client parseToClient(string line)
	{
		Client NewClient;
		vector<string> temp = split(line);
		NewClient.setId(stoi(temp[0]));
		NewClient.setName(temp[1]);
		NewClient.setPassword(temp[2]);
		NewClient.setBalance(stod(temp[3]));

		return NewClient;
	}

	static Employee parseToEmployee(string line)
	{
		Employee NewEmployee;
		vector<string> temp = split(line);
		NewEmployee.setId(stoi(temp[0]));
		NewEmployee.setName(temp[1]);
		NewEmployee.setPassword(temp[2]);
		NewEmployee.setSalary(stod(temp[3]));

		return NewEmployee;
	}

	static Admin parseToAdmin(string line)
	{
		Admin NewAdmin;
		vector<string> temp = split(line);
		NewAdmin.setId(stoi(temp[0]));
		NewAdmin.setName(temp[1]);
		NewAdmin.setPassword(temp[2]);
		NewAdmin.setSalary(stod(temp[3]));

		return NewAdmin;
	}
};

