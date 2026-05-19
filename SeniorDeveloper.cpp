#include "SeniorDeveloper.h"
#include <iostream>

SeniorDeveloper::SeniorDeveloper(const std::string& name, int age, int id,
                                 double baseSalary, const std::string& language,
                                 int projectCount, double stockBonus)
    : Developer(name, age, id, baseSalary, language, projectCount),
      stockBonus(stockBonus) {}

double SeniorDeveloper::calculateSalary() const {
    return Developer::calculateSalary() + stockBonus;
}

void SeniorDeveloper::printInfo() const {
    std::cout << "[Senior Dev] " << name
              << " | Age: " << age
              << " | ID: " << employeeId
              << " | Projects: " << projectCount
              << " | Stock bonus: " << stockBonus
              << " | Total salary: " << calculateSalary() << " EUR\n";
}
