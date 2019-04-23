// Proof of API concept for Stock Quote app
//Uses cpr (C++ Requests library) installed via VCPKG to execute API requests from iexcloud.io financial data api
//requires x86 debug config in VS not x64

#include "pch.h"
#include <iostream>
#include <cpr/cpr.h>
#include <rapidjson/rapidjson.h>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;
int main()
{
	cout << "Hello API!\n";

	cout << "Current quote for Merck (NYSE MRK): ";
	auto r = cpr::Get(cpr::Url{ "https://cloud.iexapis.com/beta/stock/MRK/quote?token=pk_05b60effc229410da18fd2dd0aa3bbae" });
	cout << r.text;
	json x = json::parse(r.text);
	for (json::iterator it = x.begin(); it != x.end(); ++it) {
		std::cout << it.key() << " : " << it.value() << "\n";
	}
	cout << x["latestPrice"];

	
}