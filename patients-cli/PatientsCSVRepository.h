#pragma once
#include "PatientsRepository.h"
#include "csv.h"
#include <fstream>
#include <sstream>

constexpr auto PATIENTS_CSV_FILE = "patients.csv";
constexpr auto TEMP_PATIENTS_CSV_FILE_FOR_DELETION = "patients-with-deleted-record.csv";

class PatientsCSVRepository : public PatientsRepository
{
public:
	PatientsCSVRepository();

	std::vector<Patient> List() override;
	int Add(Patient patient) override;
	bool Delete(int id) override;

private:
	std::vector<Patient> ReadFromCSV(std::string csvPath);
	void InsertIntoCSV(std::string csvPath, Patient patient);
	bool DeleteFromCSV(std::string csvPath, int patientId);
};
