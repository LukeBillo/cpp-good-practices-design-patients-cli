#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include "PatientsRepository.h"
#include "Command.h"
#include "AddPatientArgs.h"
#include "TrimUtility.h"

std::map<std::string, Command> CommandMapping = {
	{ "list", Command::List },
	{ "add", Command::Add },
	{ "delete", Command::Delete },
	{ "quit", Command::Quit }
};

std::tuple<Command, std::string> Parse(std::string command)
{
	std::istringstream commandInputStream(command);
	std::string commandWithoutArgs;
	std::string commandArgs;

	commandInputStream >> commandWithoutArgs;
	std::getline(commandInputStream, commandArgs);

	std::transform(commandWithoutArgs.begin(), commandWithoutArgs.end(), commandWithoutArgs.begin(), [](unsigned char c) { return std::tolower(c); });
	auto iterator = CommandMapping.find(commandWithoutArgs);

	return iterator == CommandMapping.end() ?
		std::make_tuple(Command::Invalid, "") :
		std::make_tuple(iterator->second, commandArgs);
}

AddPatientArgs GetAddCommandArgs(std::string args)
{
	std::istringstream argumentsStream(args);

	std::string firstName;
	std::string secondName;
	std::string medicalInformation;

	argumentsStream >> firstName >> secondName;
	std::getline(argumentsStream, medicalInformation);

	medicalInformation = TrimWhitespaceAndApostrophes(medicalInformation);

	return AddPatientArgs(firstName, secondName, medicalInformation);
}