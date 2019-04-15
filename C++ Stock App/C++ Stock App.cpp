// Proof of API concept for Stock Quote app
//Uses cpr (C++ Requests library) installed via VCPKG to execute API requests from iexcloud.io financial data api
//requires x86 debug config in VS not x64

#include "pch.h"
#include <iostream>
#include <cpr/cpr.h>
using namespace std;

int main()
{
	cout << "Hello API!\n";

	cout << "Current quote for Merck (NYSE MRK): ";
	auto r = cpr::Get(cpr::Url{ "https://cloud.iexapis.com/beta/stock/MRK/quote/latestPrice?token=pk_05b60effc229410da18fd2dd0aa3bbae" });
	cout << r.text;
}