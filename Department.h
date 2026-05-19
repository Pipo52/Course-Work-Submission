#pragma once
#include "Employee.h"
#include <vector>
#include <memory>
#include <string>

class Department {
private:
    std::string departmentName;
    std::vector<std::shared_ptr<Employee>> employees;

public:
    explicit Department(const std::string& name);

    void addEmployee(std::shared_ptr<Employee> emp);
    void sortBySalary();
    std::shared_ptr<Employee> findByName(const std::string& name) const;
    double totalSalaryBudget() const;
    void printAll() const;
    const std::string& getName() const;
};
