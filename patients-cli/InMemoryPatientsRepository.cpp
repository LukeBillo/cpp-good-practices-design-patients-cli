#include "InMemoryPatientsRepository.h"

InMemoryPatientsRepository::InMemoryPatientsRepository()
{
    _patients = new std::vector<Patient>();
}

std::vector<Patient> InMemoryPatientsRepository::List()
{
    return *_patients;
}

int InMemoryPatientsRepository::Add(Patient patient)
{
    int newPatientId = 0;

    if (_patients->empty()) {
        newPatientId = 1;
    }
    else {
        Patient lastPatient = _patients->back();
        newPatientId = lastPatient.Id + 1;
        patient.Id = newPatientId;
    }

    _patients->push_back(patient);
    return newPatientId;
}

bool InMemoryPatientsRepository::Delete(int id)
{
    auto iterator = std::find_if(_patients->begin(), _patients->end(), [id](Patient patient) {
        return patient.Id == id;
    });

    _patients->erase(iterator);
    return true;
}
