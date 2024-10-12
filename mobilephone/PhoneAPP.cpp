#include<iostream>
#include<fstream>
#include<string>
#include"AboutUsers.h"

using namespace std;

int main()
{
	PhoneNumbersBook p;
	int i;
	cout << "Press 1 to save information into file or 2 to delete old file and create a new file to save your changes:"; cin >> i;
	switch (i)
	{
	case 1:
		p.File();
		break;
	case 2:
		p.DelAndChange();
		break;
	default:
	break;
	}
	
}