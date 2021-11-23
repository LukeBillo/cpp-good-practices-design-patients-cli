#pragma once
#include <iostream>

struct Patient
{
	std::string FirstName;
	std::string SecondName;
	std::string MedicalInformation;

	Patient(std::string firstName, std::string secondName, std::string medicalInformation) 
	{
		FirstName = firstName;
		SecondName = secondName;
		MedicalInformation = medicalInformation;
	}
};