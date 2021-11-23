#include "PatientsCSVRepository.h"

PatientsCSVRepository::PatientsCSVRepository() : PatientsRepository()
{
	
}

std::vector<Patient> PatientsCSVRepository::ReadAll()
{
	return std::vector<Patient>();
}

int PatientsCSVRepository::Add(Patient patient)
{
	return 0;
}

void PatientsCSVRepository::Delete(int id)
{
}
