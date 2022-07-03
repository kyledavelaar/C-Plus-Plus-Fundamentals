#include <iostream>
#include <functional> // for reference-wrapper
#include <string>
#include <vector>

/*
    REFERENCE WRAPPERS are needed if want to put a reference inside a vector
*/

// forward delcare so can use in Doctor
class Patient;

class Doctor {
    private:
        std::string m_name{};
        // need reference_wrapper if want to hold references inside a vector
        std::vector<std::reference_wrapper<const Patient>> m_patients{};
    public:
        Doctor(const std::string& name) : m_name{name} {}
        void addPatient(Patient& patient);
        friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);
        const std::string& getName() const { return m_name; }
};

class Patient {
    private:
        std::string m_name{};
        std::vector<std::reference_wrapper<const Doctor>> m_doctors{};
        void addDoctor(const Doctor& doctor) {
            m_doctors.push_back(doctor);
        }
    public:
        Patient(const std::string& name) : m_name{name} {};
        friend std::ostream& operator<<(std::ostream& out, const Patient& patient);
        const std::string& getName() const { return m_name; }
        // so doctors can call private addDoctor method
        friend void Doctor::addPatient(Patient& patient);
};

// why no const here but a const in patient.addDoctor?
void Doctor::addPatient(Patient& patient) {
    m_patients.push_back(patient);
    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor) {
    if (doctor.m_patients.empty()) {
        out << doctor.m_name << " has no patients";
    } else {
        out << doctor.m_name << " is seeing patients:" << '\n';
        for (const auto& patient : doctor.m_patients) {
            out << patient.get().getName() << '\n';
        }
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
    if (patient.m_doctors.empty()) {
        out << patient.getName() << " has no doctors";
    } else {
        out << patient.getName() << " has doctors:" << '\n';
        for (const auto& doctor : patient.m_doctors) {
            out << doctor.get().getName() << '\n';
        }
    }
    return out;
}

int main() {
    Doctor loser{"Loser"};
    Doctor doctorMary{"Mary"};
    Patient patientJames{"James"};
    Patient patientYarro{"Yarro"};
    Patient creep{"Creep"};
    doctorMary.addPatient(patientJames);
    doctorMary.addPatient(patientYarro);
    std::cout << doctorMary << '\n';
    std::cout << patientJames << '\n';
    std::cout << patientYarro << '\n';
    std::cout << loser << '\n';
    std::cout << creep << '\n';


    return 0;
}





