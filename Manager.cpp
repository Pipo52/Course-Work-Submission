#include "Manager.h"
#include <iostream>
#include <stdexcept>

Manager::Manager(const std::string& name, int age, int id,
                 double baseSalary, int teamSize, double bonusPerMember)
    : Employee(name, age, id, baseSalary) {
    if (teamSize < 0) {
        throw std::invalid_argument("Team size cannot be negative.");
    }
    this->teamSize = teamSize;
    this->bonusPerMember = bonusPerMember;
}

double Manager::calculateSalary() const {
    return baseSalary + (teamSize * bonusPerMember);
}

void Manager::printInfo() const {
    std::cout << "[Manager]  " << name
              << " | Age: " << age
              << " | ID: " << employeeId
              << " | Team: " << teamSize
              << " | Salary: " << calculateSalary() << " EUR\n";
}
