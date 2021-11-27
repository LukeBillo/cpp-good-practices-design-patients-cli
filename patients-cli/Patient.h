#pragma once
#include <iostream>
#include "AddPatientArgs.h"

constexpr signed int NO_ID = -1;

struct Patient
{
	int Id;
	std::string FirstName;
	std::string SecondName;
	std::string MedicalInformation;

	std::string FullName() 
	{
		return this->FirstName + " " + this->SecondName;
	}

	Patient(int id, std::string firstName, std::string secondName, std::string medicalInformation)
	{
		Id = id;
		FirstName = firstName;
		SecondName = secondName;
		MedicalInformation = medicalInformation;
	}

	Patient(AddPatientArgs addPatientArgs) 
	{
		Id = NO_ID;
		FirstName = addPatientArgs.FirstName;
		SecondName = addPatientArgs.SecondName;
		MedicalInformation = addPatientArgs.MedicalInformation;
	}
};