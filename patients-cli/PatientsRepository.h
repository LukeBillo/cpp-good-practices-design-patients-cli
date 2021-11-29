#pragma once
#include "Patient.h"
#include <vector>

class PatientsRepository
{
public:
	virtual std::vector<Patient> List() = 0;
	virtual int Add(Patient patient) = 0;
	virtual bool Delete(int id) = 0;
};

