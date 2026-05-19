#pragma once
#include "Developer.h"

class SeniorDeveloper : public Developer {
private:
    double stockBonus;

public:
    SeniorDeveloper(const std::string& name, int age, int id,
                    double baseSalary, const std::string& language,
                    int projectCount, double stockBonus);

    double calculateSalary() const override;
    void printInfo() const override;
};
