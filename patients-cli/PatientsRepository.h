#pragma once
#include "Patient.h"
#include <vector>

class PatientsRepository
{
	PatientsRepository() {}

	virtual std::vector<Patient> ReadAll() = 0;
	virtual int Add(Patient patient) = 0;
	virtual void Delete(int id) = 0;
};

