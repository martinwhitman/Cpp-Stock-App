//User class, includes name, age, requests, adds a request amount every time something is returned
//Created by Carl Phillips

#include <string>
#include <iostream>
#include "pch.h"
#include "User.h"

using namespace std;

User::User()
{

}

User::User(std::string name)
{
	setName(name);
}

void User::setName(std::string n) 
{ 
	name = n; 
}

string User::getName() 
{ 
	return name; 
}

void User::setAge(int a) 
{ 
	age = a; 
}

int User::getAge() 
{ 
	return age; 
}

void User::setRequests(int r) 
{ 
	requests = requests + r; 
}

int User::getRequests() 
{ 
	return requests; 
}
