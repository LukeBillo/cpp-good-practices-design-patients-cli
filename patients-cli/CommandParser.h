#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include "PatientsRepository.h"
#include "Command.h"

std::map<std::string, Command> CommandMapping = {
	{ "list", Command::List },
	{ "add", Command::Add },
	{ "delete", Command::Delete },
	{ "quit", Command::Quit }
};

Command Parse(std::string command)
{
	std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c) { return std::tolower(c); });
	auto iterator = CommandMapping.find(command);

	return iterator == CommandMapping.end() ?
		Command::Invalid :
		iterator->second;
}

bool IsValid(std::string command)
{
	Command parsedCommand = Parse(command);
	return parsedCommand != Command::Invalid;
}