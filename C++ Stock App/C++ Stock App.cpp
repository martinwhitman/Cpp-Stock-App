// Proof of API concept for Stock Quote app
//Uses cpr (C++ Requests library) installed via VCPKG to execute API requests from iexcloud.io financial data api
//requires x86 debug config in VS not x64

#include "pch.h"
#include <iostream>
#include <string>
#include "User.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <cpr/cpr.h>
#include <rapidjson/rapidjson.h>
#include <nlohmann/json.hpp>
#include "../../../../../../Program Files (x86)/Windows Kits/10/Include/10.0.17763.0/ucrt/string.h"
using namespace std;

using json = nlohmann::json;

using namespace rapidjson;
int getStockPrice();
int getStockInfo();

int request;
const int MOSTREQUESTS = 100;


int getCrypto();

int getStockStats();

int getCompanyDetails();

int main()
{
	/*code for reference
	 *cout << "Current quote for Merck (NYSE MRK): ";
	auto r = cpr::Get(cpr::Url{ "https://cloud.iexapis.com/beta/stock/MRK/quote?token=pk_05b60effc229410da18fd2dd0aa3bbae" });
	cout << r.text;
	json x = json::parse(r.text);
	for (json::iterator it = x.begin(); it != x.end(); ++it) {
		std::cout << it.key() << " : " << it.value() << "\n";
	}
	cout << x["latestPrice"];
*/

	int choice = 0;
	string name;
	int age;
	int request;

	cout << "Stock Application - This app will give you options to get information for specific stocks." << endl << endl;
	cout << "What is your name? " << endl;
	cin >> name;									//Gets the users name and stores it in a new user object

	User user1;
	user1.setName(name);

	cout << "How old are you? " << endl;			//Gets the users age, if the user is not older than 18, they cannot use the application
	cin >> age;
	user1.setAge(age);

	if (user1.getAge() >= 18) {
		while (choice != 9 && user1.getRequests() < MOSTREQUESTS)		//if the user hits 100 requests the application will end
		{
			cout << "What would you like to do?" << endl;				//menu for the application
			cout << "1. Get Stock Price" << endl;
			cout << "2. Get Details for a Stock" << endl;
			cout << "3. Get Stats for a Stock"<<endl;
			cout << "4. Get Details for a Stock Company" << endl;
			cout << "5. Get Crypto prices" << endl;
			cout << "9. Exit Program" << endl;

			cin >> choice;												//gets the users choice

			if (choice == 1)											//depending on user input will get different information
			{
				request = getStockPrice();								//depending on the request the request amount will go up
				user1.setRequests(request);
			}
			else if (choice == 2)
			{
				request = getStockInfo();
				user1.setRequests(request);
			}
			else if(choice==3)
			{
				request = getStockStats();
				user1.setRequests(request);
			}
			else if(choice==4)
			{
				request = getCompanyDetails();
				user1.setRequests(request);
			}
			else if (choice==5)
			{
				request = getCrypto();
				user1.setRequests(request);
			}
			else if (choice == 9)
			{
				break;
			}
		}
	}
	else if (user1.getAge() < 18)
	{
		cout << "Sorry, you are too young to use this application. Please come back when you are of age." << endl;
	}


	cout << endl << "Ending Requests: " << user1.getRequests() << endl;				//Tells the user how many requests were made

	return 0;
}

int getCrypto()
{
	string link;	
	string token = "pk_05b60effc229410da18fd2dd0aa3bbae";
	string crypto;
	int choice;
	cout << "\nChoose 1 for Bitcoin, 2 for Ethereum, 3 for XRP, 4 for Litecoin, or 5 for EOS: ";
	cin >> choice;
	switch (choice)
	{
	case 1:crypto = "BTCUSDT";
		break;
	case 2:crypto = "ETHUSDT";
		break;
	case 3:crypto = "XRPUSDT";
		break;
	case 4:crypto = "LTCUSDT";
		break;
	case 5:crypto = "EOSUSDT";
		break;
	default:
		break;
	}
	link = "https://cloud.iexapis.com/beta/crypto/" + crypto + "/quote?token=" + token;
	auto r = cpr::Get(cpr::Url{ link });				//calls to a website and returns a json string
	json x = json::parse(r.text);

	cout << endl <<"The price for that crypto is "<< x["latestPrice"]<< endl << endl;
	return 1;
}

int getCompanyDetails()
{
	string link;
	string token = "pk_05b60effc229410da18fd2dd0aa3bbae";
	string stock;
	cout << "Please input stock ticker symbol for the company you are interested in: ";
	cin >> stock;
	link = "https://cloud.iexapis.com/beta/stock/" + stock + "/company?token=" + token;
	auto r = cpr::Get(cpr::Url{ link });				//calls to a website and returns a json string
	json x = json::parse(r.text);
	cout << "\nCompany Name: " << x["companyName"];
	cout << "\nEmployees: " << x["employees"];
	cout << "\nCEO: " << x["CEO"];
	cout << "\nExchange: " << x["exchange"];
	cout << "\nIndustry: " << x["industry"];
	cout << "\nWebsite: " << x["website"];
	cout << "\nDescription: " << x["description"];
	cout << "\nIssue Type: " << x["issueType"];
	cout << "\nSector: " << x["sector"];
	cout << "\n";
	return 1;
}


int getStockStats()
{
	string link;	
	string token = "pk_05b60effc229410da18fd2dd0aa3bbae";
	string stock;
	cout << "Please input stock ticker symbol: ";
	cin >> stock;
	link = "https://cloud.iexapis.com/beta/stock/" + stock + "/stats?token=" + token;
	auto r = cpr::Get(cpr::Url{ link });				//calls to a website and returns a json string
	json x = json::parse(r.text);
	cout << "\nCompany Name: " << x["companyName"];
	cout << "\n52 Week High: " << x["week52high"];
	cout << "\n52 Week Low: " << x["week52low"];
	cout << "\n52 Week Change: " << x["week52change"];
	cout << "\nShares Outstanding: " << x["sharesOutstanding"];
	cout << "\n200 Day Moving Average: " << x["day200MovingAvg"];
	cout << "\n50 Day Moving Average: " << x["day50MovingAvg"];
	cout << "\nEmployees: " << x["employees"];
	cout << "\nEarnings Per Share (Trailing 12 Months): " << x["ttmEPS"];
	cout << "\nDividend Rate (Trailing 12 Months): " << x["ttmDividendRate"];
	cout << "\nDividend Yield: " << x["dividendYield"];
	cout << "\nNext Dividend Date: " << x["nextDividendDate"];
	cout << "\nNext Earnings Date: " << x["nextEarningsDate"];
	cout << "\nPrice to Earnings Ratio: " << x["peRatio"];
	cout << "\n";
	return 5;
}



int getStockPrice()										//just gets the stock price -- uses the rapidjson method
{
	string link;										//Declares the strings needed to make the call
	string userNum = "";
	string stock1 = "https://cloud.iexapis.com/beta/stock/";
	string stock2 = "/quote/latestPrice?token=pk_05b60effc229410da18fd2dd0aa3bbae";

	cout << "Please input stock ticker symbol:  ";
	cin >> userNum;										//gets user input for the stock

	link = stock1 + userNum + stock2;

	auto r = cpr::Get(cpr::Url{ link });				//calls to a website and returns a json string
	cout << endl << r.text << endl << endl;

	return 1;											//returns 1 for 1 request
}

int getStockInfo()										//gets more stock info -- uses rapidjson method
{
	string startUrl = "https://cloud.iexapis.com/beta/stock/";			//declares urls
	string uInput;
	string endUrl = "/quote/?token=pk_05b60effc229410da18fd2dd0aa3bbae";
	string link;

	cout << endl << "Input Stock Ticker Symbol" << endl;								//gets user input for stock info
	cin >> uInput;

	link = startUrl + uInput + endUrl;									//creates the link and makes the call
	auto r = cpr::Get(cpr::Url{ link });
	std::string s = r.text;

	int n = s.length();
	char json[1000];
	strcpy_s(json, s.c_str());											//parses the json string to char array

	Document d;															//creates a document and parses the array to the document
	d.Parse(json);
	Value& compName = d["companyName"];									//creates a value for the corresponding info
	Value& calcPrice = d["calculationPrice"];
	Value& lat = d["latestPrice"];
	Value& ytd = d["ytdChange"];
	Value& marketCap = d["marketCap"];
	Value& change = d["change"];
	Value& changePercent = d["changePercent"];

	cout << endl << "Company Name: " << compName.GetString() << endl;	//lists the information for the stock chosen
	cout << "Calc Price: " << calcPrice.GetString() << endl;
	cout << "Latest Price: " << lat.GetDouble() << endl;
	cout << "Year to Date Change: " << ytd.GetDouble() << endl;
	cout << "Market Cap: " << marketCap.GetDouble() << endl;
	cout << "Change: " << change.GetDouble() << endl;
	cout << "Percent Change: " << changePercent.GetDouble() << endl;



	/*  This code included for testing, will return the full json string to see if there is
		an unexpected value returned, like null
	// 3. Stringify the DOM
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);
	// Output the full json
	std::cout << buffer.GetString() << std::endl;
	*/

	return 12;															//returns the request number
}