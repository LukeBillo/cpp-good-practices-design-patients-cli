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
	std::string args = "";
	std::string inputCommand = "";

	std::cout << "Welcome to the patient records CLI" << std::endl;
	PrintHelp();

	while (command != Command::Quit)
	{
		std::getline(std::cin, inputCommand);

		auto commandAndArgs = Parse(inputCommand);
		command = std::get<0>(commandAndArgs);
		args = std::get<1>(commandAndArgs);

		switch (command)
		{
		case Command::List:
		{
			auto patients = repository->List();

			std::cout << "|" << std::setw(4) << "Id";
			std::cout << "|" << std::setw(30) << "Name";
			std::cout << "|" << std::setw(80) << "Medical Information" << "|" << std::endl;

			for (Patient patient : patients)
			{
				std::cout << "|" << std::setw(4) << patient.Id;
				std::cout << "|" << std::setw(30) << patient.FullName();
				std::cout << "|" << std::setw(80) << patient.MedicalInformation << "|" << std::endl;
			}
			break;
		}
		case Command::Add:
		{
			auto addArgs = GetAddCommandArgs(args);
			int id = repository->Add(Patient(addArgs));
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
