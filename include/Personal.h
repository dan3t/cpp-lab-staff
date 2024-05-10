#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>
#include <utility>
#include "Employee.h"
#include"Interfaces.h"

class Personal : public Employee, public Work_Base_Time {
public:
    Personal(int id, std::string name,
             int work_time, Positions position, int salary) :
            Employee(id, std::move(name), work_time, position),
            salary(salary) {};

    void print_info() const override;

    int calc_base_salary(int salary, int work_time) override;

    int calc_bonus_salary(int bonus) override;
protected:
    int salary;
};

class Driver : public Personal {
public:
    using Personal::Personal;

    void calc_salary() override;

    int calc_bonus_salary(int bonus = 4) override;
};

class Cleaner : public Personal {
public:
    using Personal::Personal;

    void calc_salary() override;
};

#endif  // INCLUDE_PERSONAL_H_
