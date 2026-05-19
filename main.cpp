#include <iostream>
#include <memory>
#include "Department.h"
#include "Manager.h"
#include "Developer.h"
#include "SeniorDeveloper.h"
#include "Utils.h"

int main() {
    try {
        Department dept("Engineering");

        dept.addEmployee(std::make_shared<Employee>("Alice Johnson", 35, 1, 2000.0));
        dept.addEmployee(std::make_shared<Manager>("Bob Smith", 42, 2, 3000.0, 5, 150.0));
        dept.addEmployee(std::make_shared<Developer>("Carol White", 28, 3, 2500.0, "C++", 4));
        dept.addEmployee(std::make_shared<SeniorDeveloper>("Dave Brown", 34, 4, 3000.0, "Rust", 6, 800.0));

        dept.printAll();

        dept.sortBySalary();
        std::cout << "\n[Sorted by salary]\n";
        dept.printAll();

        std::cout << "\n[Search result]\n";
        auto found = dept.findByName("Carol White");
        found->printInfo();

        std::vector<std::shared_ptr<Employee>> topList = {
            std::make_shared<SeniorDeveloper>("Eve Senior", 40, 5, 4000.0, "Go", 8, 1000.0)
        };
        printAll("Top Performers", topList);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "\n[Exception tests]\n";
    try {
        auto e = std::make_shared<Employee>("", 25, 99, 1000.0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught: " << e.what() << "\n";
    }

    try {
        auto e = std::make_shared<Employee>("Test", 25, 99, -500.0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught: " << e.what() << "\n";
    }

    return 0;
}
