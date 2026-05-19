#pragma once
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age);
    virtual ~Person() = default;

    std::string getName() const;
    int getAge() const;

    virtual void printInfo() const = 0;
};
