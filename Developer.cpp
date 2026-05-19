#include "Developer.h"
#include <iostream>

Developer::Developer(const std::string& name, int age, int id,
                     double baseSalary, const std::string& language, int projectCount)
    : Employee(name, age, id, baseSalary),
      programmingLanguage(language),
      projectCount(projectCount) {}

double Developer::calculateSalary() const {
    return baseSalary + (projectCount * 200.0);
}

void Developer::printInfo() const {
    std::cout << "[Developer] " << name
              << " | Age: " << age
              << " | ID: " << employeeId
              << " | Lang: " << programmingLanguage
              << " | Projects: " << projectCount
              << " | Salary: " << calculateSalary() << " EUR\n";
}
