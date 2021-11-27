#pragma once
#include "PatientsRepository.h"
#include "csv.h"
#include <fstream>

constexpr auto PATIENTS_CSV_FILE = "patients.csv";;

class PatientsCSVRepository : public PatientsRepository
{
public:
	PatientsCSVRepository();

	std::vector<Patient> List() override;
	int Add(Patient patient) override;
	void Delete(int id) override;

private:
	std::vector<Patient> ReadFromCSV(std::string csvPath);
	void InsertIntoCSV(std::string csvPath, Patient patient);
};
