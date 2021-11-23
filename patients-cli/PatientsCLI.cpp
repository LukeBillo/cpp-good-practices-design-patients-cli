#include <iostream>
#include <iomanip>
#include "CommandParser.h"
#include "PatientsCSVRepository.h"

void PrintHelp()
{
	std::cout << std::endl;
	std::cout << "Usage: <command> <args>" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "list" << std::endl;
	std::cout << "add <first_name> <second_name> \"<medical_info>\"" << std::endl;
	std::cout << "delete <id>" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;
}

int main()
{
	PatientsRepository* repository = new PatientsCSVRepository();

	Command command = Command::Invalid;
	std::string inputCommand = "";

	std::cout << "Welcome to the patient records CLI" << std::endl;
	PrintHelp();

	while (command != Command::Quit)
	{
		std::cin >> inputCommand;
		command = Parse(inputCommand);

		switch (command)
		{
		case Command::List:
		{
			auto patients = repository->List();

			std::cout << "|" << std::setw(30) << "Name";
			std::cout << "|" << std::setw(30) << "Medical Information" << "|" << std::endl;

			for (Patient patient : patients)
			{
				std::cout << std::setw(30) << patient.FullName() << "|";
				std::cout << std::setw(30) << patient.MedicalInformation << "|" << std::endl;
			}
			break;
		}
		case Command::Add:
		{
			break;
		}
		case Command::Delete:
		{
			break;
		}
		case Command::Invalid:
		{
			std::cout << "Unrecognised command." << std::endl;
			PrintHelp();
			break;
		}
		}
	}
}
