#pragma once
#include <iostream>
#include "PatientsRepository.h"

class CommandExecutor
{
	CommandExecutor();
	~CommandExecutor();

	bool IsValid(std::string maybeCommand);
	void RunCommand(std::string command);

private:
	PatientsRepository* _repository = nullptr;
};

