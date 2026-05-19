#include "Department.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdexcept>

Department::Department(const std::string& name) : departmentName(name) {}

void Department::addEmployee(std::shared_ptr<Employee> emp) {
    employees.push_back(emp);
}

void Department::sortBySalary() {
    std::sort(employees.begin(), employees.end(),
        [](const std::shared_ptr<Employee>& a, const std::shared_ptr<Employee>& b) {
            return a->calculateSalary() > b->calculateSalary();
        });
}

std::shared_ptr<Employee> Department::findByName(const std::string& name) const {
    auto it = std::find_if(employees.begin(), employees.end(),
        [&name](const std::shared_ptr<Employee>& emp) {
            return emp->getName() == name;
        });

    if (it == employees.end()) {
        throw std::runtime_error("Employee not found: " + name);
    }
    return *it;
}

double Department::totalSalaryBudget() const {
    return std::accumulate(employees.begin(), employees.end(), 0.0,
        [](double sum, const std::shared_ptr<Employee>& emp) {
            return sum + emp->calculateSalary();
        });
}

void Department::printAll() const {
    std::cout << "\n=== Department: " << departmentName << " ===\n";
    for (const auto& emp : employees) {
        emp->printInfo();
    }
    std::cout << "Total salary budget: " << totalSalaryBudget() << " EUR\n";
}

const std::string& Department::getName() const { return departmentName; }
