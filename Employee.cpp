#include "Employee.h"
#include <iostream>
#include <stdexcept>

Employee::Employee(const std::string& name, int age, int id, double baseSalary)
    : Person(name, age), employeeId(id) {
    if (baseSalary < 0) {
        throw std::invalid_argument("Salary cannot be negative.");
    }
    this->baseSalary = baseSalary;
}

int Employee::getId() const { return employeeId; }
double Employee::getBaseSalary() const { return baseSalary; }

double Employee::calculateSalary() const {
    return baseSalary;
}

void Employee::printInfo() const {
    std::cout << "[Employee] " << name
              << " | Age: " << age
              << " | ID: " << employeeId
              << " | Salary: " << calculateSalary() << " EUR\n";
}
