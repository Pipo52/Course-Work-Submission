#pragma once
#include "Employee.h"
#include <string>

class Developer : public Employee {
protected:
    std::string programmingLanguage;
    int projectCount;

public:
    Developer(const std::string& name, int age, int id,
              double baseSalary, const std::string& language, int projectCount);

    double calculateSalary() const override;
    void printInfo() const override;
};
