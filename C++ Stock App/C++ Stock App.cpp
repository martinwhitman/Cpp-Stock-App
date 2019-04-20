// Proof of API concept for Stock Quote app
//Uses cpr (C++ Requests library) installed via VCPKG to execute API requests from iexcloud.io financial data api
//requires x86 debug config in VS not x64

#include "pch.h"
#include <iostream>
#include <string>
#include "User.h"
#include <cpr/cpr.h>
using namespace std;

int getStockPrice();
void test();

int request;
const int MOSTREQUESTS = 100;


int main()
{
	int choice = 0;
	string name;
	int age;
	int request;

	cout << "What is your name? " << endl;
	cin >> name;

	User user1;
	user1.setName(name);

	cout << "How old are you? " << endl;
	cin >> age;
	user1.setAge(age);

	while (choice != 9)
	{
		cout << "What would you like to do?" << endl;
		cout << "1. Get Stock Price" << endl;
		cout << "2. Something else" << endl;
		cout << "3. test " << endl;
		cout << "9. Exit Program" << endl;


		cin >> choice;

		if (choice == 1)
		{
			request = getStockPrice();
			user1.setRequests(request);
		}
		else if (choice == 2)
		{
			request = getStockPrice();
			user1.setRequests(request);
		}
		else if (choice == 3)
		{
			request = getStockPrice();
			user1.setRequests(request);
		}
		else if (choice == 4)
		{
			request = getStockPrice();
			user1.setRequests(request);
		}
		else if (choice == 9)
		{
			break;
		}
	}

	cout << user1.getRequests();

	return 0;
}

int getStockPrice()
{
	string str;
	string userNum = "";
	string stock1 = "https://cloud.iexapis.com/beta/stock/";
	string stock2 = "/quote/latestPrice?token=pk_05b60effc229410da18fd2dd0aa3bbae";

	cout << "Please input stock name:  ";

	cin >> userNum;


	str = stock1 + userNum + stock2;


	auto r = cpr::Get(cpr::Url{ str });
	cout << endl << r.text;

	return 1;
}

void test()
{
	
}