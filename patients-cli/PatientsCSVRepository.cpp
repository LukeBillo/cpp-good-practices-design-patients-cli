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

bool PatientsCSVRepository::Delete(int id)
{
	return DeleteFromCSV(PATIENTS_CSV_FILE, id);
}

std::vector<Patient> PatientsCSVRepository::ReadFromCSV(std::string csvPath)
{
	io::CSVReader<4> patientsCSV(csvPath);
	patientsCSV.read_header(io::ignore_extra_column, "Id", "FirstName", "SecondName", "MedicalInformation");

	int id = NO_ID;
	std::string firstName = "";
	std::string secondName = "";
	std::string medicalInformation = "";

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

bool PatientsCSVRepository::DeleteFromCSV(std::string csvPath, int patientIdToDelete)
{
	io::CSVReader<4> patientsCSV(csvPath);
	patientsCSV.read_header(io::ignore_extra_column, "Id", "FirstName", "SecondName", "MedicalInformation");

	int id = NO_ID;
	std::string firstName = "";
	std::string secondName = "";
	std::string medicalInformation = "";

	std::ofstream tempPatientsCSV;
	tempPatientsCSV.open(TEMP_PATIENTS_CSV_FILE_FOR_DELETION);
	tempPatientsCSV << "Id,FirstName,SecondName,MedicalInformation";
	tempPatientsCSV.close();

	while (patientsCSV.read_row(id, firstName, secondName, medicalInformation))
	{
		auto patient = Patient(id, firstName, secondName, medicalInformation);
		
		if (patient.Id != patientIdToDelete) {
			InsertIntoCSV(TEMP_PATIENTS_CSV_FILE_FOR_DELETION, patient);
		}
	}

	int removeErrorCode = remove(csvPath.c_str());
	if (removeErrorCode != 0) 
	{
		return false;
	}

	int renameErrorCode = rename(TEMP_PATIENTS_CSV_FILE_FOR_DELETION, csvPath.c_str());
	return renameErrorCode == 0;
}
