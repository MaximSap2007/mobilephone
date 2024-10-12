#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdio>

struct Numbers
{
	std::string Abonent;
	std::string HomePhoneNumber;
	std::string WorkPhoneNumber;
	std::string PhoneNumber;
	std::string AboutUser;
};
class PhoneNumbersBook
{
private:
	int count;
public:
	//Input new users:
	Numbers number;
	PhoneNumbersBook()
	{
		std::cout << "Input the number of users:\t"; std::cin >> count;
		std::cin.ignore();
		Numbers numbers;
		for (int i = 0; i < count; i++)
		{
			std::cout << std::endl;
			std::cout << "Enter name, last name: ";
			std::cin>> number.Abonent;
			std::cout << std::endl;
			std::cout << "Enter Home phone: ";
			std::cin >> number.HomePhoneNumber;
			std::cout << std::endl;
			std::cout << "Enter Work Phone: ";
			std::cin >> number.WorkPhoneNumber;
			std::cout << std::endl;
			std::cout << "Enter Mobile Phone: ";
			std::cin >> number.PhoneNumber;
			std::cout << std::endl;
			std::cout << "Enter Information: ";
			std::cin >> number.AboutUser;
			std::cout << std::endl;
			File();
			std::cout << "- - - - - - - - - - - - -\n";
		}
		
	}
	~PhoneNumbersBook()
	{	
	}
	//Save them into file.Input and Output: 
	void File()
	{
		int numb;
		std::string l;
		
		std::cout << "Input here 1 to save it into your file or 2 to output it from it:"; std::cin >> numb;
		if (numb == 1)
		{
			std::ofstream file("PhoneBook.txt", std::ios::app);
			file << std::endl <<number.Abonent << std::endl << number.HomePhoneNumber << std::endl <<
				number.WorkPhoneNumber << std::endl << number.PhoneNumber << std::endl << number.AboutUser;
			file.close();
			
		};
		if (numb == 2)
		{
			std::ifstream file("PhoneBook.txt");
			while (getline(file, l))
			{
				std::cout << std::endl<<l << std::endl;
			};
			file.close();
		};
		if (1 > numb > 2)
		{
			std::cout << "Error!";
			return File();
		};
	}
	//Delete users:
	void DelAndChange()
	{
		int numb;
		std::string lT;
		std::string l;
		std::string text;
		std::ifstream file("PhoneBook.txt");
		file.close();
		std::cout << "\nDo you want to delete your file?If yes - press -- 'Yes'.If no, press -- 'No':"; std::cin >> text;
		if(text == "Yes")
		{
			if (remove("PhoneBook.txt") == 0)
			{
				std::cout << "\nYour file has been deleated!";
				std::cout << "\nDo you want to create a new file? If yes, press -- 'Yes'.If no, press -- 'No'!:"; std::cin >> text;
				if(text == "Yes")
				{
					std::ofstream newFile("NEWFILE.txt"); 
					Numbers numbers;
					for (int i = 0; i < count; i++)
					{
						std::cout << std::endl;
						std::cout << "Enter name, last name: ";
						std::cin >> number.Abonent;
						std::cout << std::endl;
						std::cout << "Enter Home phone: ";
						std::cin >> number.HomePhoneNumber;
						std::cout << std::endl;
						std::cout << "Enter Work Phone: ";
						std::cin >> number.WorkPhoneNumber;
						std::cout << std::endl;
						std::cout << "Enter Mobile Phone: ";
						std::cin >> number.PhoneNumber;
						std::cout << std::endl;
						std::cout << "Enter Information: ";
						std::cin >> number.AboutUser;
						std::cout << std::endl;
						CopyFile();
						std::cout << "- - - - - - - - - - - - -\n";
					}
					newFile.close();
				}
				if (text == "No")return ;

			}
			else
			{
				std::perror("Error deleting file");
			}
		}
		if (text == "No")return;

		
	}
	void CopyFile()
	{
		int numb;
		std::string l;

		std::cout << "Input here 1 to save it into your file or 2 to output it from it:"; std::cin >> numb;
		if (numb == 1)
		{
			std::ofstream file("NEWFILE.txt", std::ios::app);
			file << std::endl << number.Abonent << std::endl << number.HomePhoneNumber << std::endl <<
				number.WorkPhoneNumber << std::endl << number.PhoneNumber << std::endl << number.AboutUser;
			file.close();

		};
		if (numb == 2)
		{
			std::ifstream file("NEWFILE.txt");
			while (getline(file, l))
			{
				std::cout << std::endl << l << std::endl;
			};
			file.close();
		};
		if (1 > numb > 2)
		{
			std::cout << "Error!";
			return File();
		};
	}
	
};
