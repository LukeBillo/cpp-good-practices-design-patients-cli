#pragma once
#include "PatientsRepository.h"

class InMemoryPatientsRepository : public PatientsRepository
{
public:
	InMemoryPatientsRepository();

	std::vector<Patient> List() override;
	int Add(Patient patient) override;
	bool Delete(int id) override;
private:
	std::vector<Patient>* _patients;
};

