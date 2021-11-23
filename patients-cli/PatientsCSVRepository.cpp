#include "PatientsCSVRepository.h"

PatientsCSVRepository::PatientsCSVRepository() : PatientsRepository()
{
	
}

std::vector<Patient> PatientsCSVRepository::List()
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
