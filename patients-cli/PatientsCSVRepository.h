#pragma once
#include "PatientsRepository.h"

class PatientsCSVRepository : public PatientsRepository
{
public:
	PatientsCSVRepository();

	std::vector<Patient> List() override;
	int Add(Patient patient) override;
	void Delete(int id) override;
};
