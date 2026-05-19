#include "Person.h"
#include <stdexcept>

Person::Person(const std::string& name, int age) {
    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }
    if (age < 0 || age > 120) {
        throw std::invalid_argument("Invalid age.");
    }
    this->name = name;
    this->age = age;
}

std::string Person::getName() const { return name; }
int Person::getAge() const { return age; }
