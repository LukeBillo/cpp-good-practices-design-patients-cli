#include "PatientsCSVRepository.h"

PatientsCSVRepository::PatientsCSVRepository() : PatientsRepository()
{
}

std::vector<Patient> PatientsCSVRepository::List()
{
	return ReadFromCSV(PATIENTS_CSV_FILE);
}

int PatientsCSVRepository::Add(Patient patient)
{
	auto patients = List();
	Patient lastPatient = patients.back();

	int newPatientId = lastPatient.Id + 1;
	patient.Id = newPatientId;

	InsertIntoCSV(PATIENTS_CSV_FILE, patient);
	return patient.Id;
}

void PatientsCSVRepository::Delete(int id)
{
}

std::vector<Patient> PatientsCSVRepository::ReadFromCSV(std::string csvPath)
{
	io::CSVReader<4> patientsCSV(csvPath);
	patientsCSV.read_header(io::ignore_extra_column, "Id", "FirstName", "SecondName", "MedicalInformation");

	int id;
	std::string firstName;
	std::string secondName;
	std::string medicalInformation;

	auto patients = std::make_unique<std::vector<Patient>>();

	while (patientsCSV.read_row(id, firstName, secondName, medicalInformation)) 
	{
		auto patient = new Patient(id, firstName, secondName, medicalInformation);
		patients->push_back(*patient);
	}

	return *patients;
}

void PatientsCSVRepository::InsertIntoCSV(std::string csvPath, Patient patient)
{
	std::ofstream patientsCSV;
	patientsCSV.open(csvPath, std::ios_base::app);
	patientsCSV << "\n" << patient.Id << "," << patient.FirstName << "," << patient.SecondName << "," << patient.MedicalInformation;
}

