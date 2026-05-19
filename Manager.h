#pragma once
#include "Employee.h"

class Manager : public Employee {
private:
    int teamSize;
    double bonusPerMember;

public:
    Manager(const std::string& name, int age, int id,
            double baseSalary, int teamSize, double bonusPerMember);

    double calculateSalary() const override;
    void printInfo() const override;
};
