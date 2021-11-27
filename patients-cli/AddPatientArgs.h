#pragma once
#include <iostream>

struct AddPatientArgs
{
	std::string FirstName;
	std::string SecondName;
	std::string MedicalInformation;

	AddPatientArgs(std::string firstName, std::string secondName, std::string medicalInformation)
	{
		FirstName = firstName;
		SecondName = secondName;
		MedicalInformation = medicalInformation;
	}
};