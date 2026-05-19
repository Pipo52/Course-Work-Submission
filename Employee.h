#pragma once
#include "Person.h"

class Employee : public Person {
protected:
    int employeeId;
    double baseSalary;

public:
    Employee(const std::string& name, int age, int id, double baseSalary);

    int getId() const;
    double getBaseSalary() const;

    virtual double calculateSalary() const;
    void printInfo() const override;
};
