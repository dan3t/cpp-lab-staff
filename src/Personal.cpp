//
// Created by denis on 17.04.2024.
//
#include "Personal.h"

void Personal::print_info() {
    std::cout << "FULL NAME: " << this->name << std::endl;
    std::cout << "Position: " << this->position << std::endl;
    std::cout << "Salary (per hour): " << this->salary << std::endl;
    std::cout << "Work time (in hours): " << this->work_time << std::endl;
    std::cout << "Current payment: " << this->payment << std::endl;
}

int Personal::calc_base_salary(int salary_value, int work_time_value) {
    return salary_value * work_time_value;
}

int Driver::calc_bonus_salary(int bonus) {
    return bonus * work_time;
}

void Driver::calc_salary() {
    this->payment = calc_base_salary(this->salary, this->work_time) + calc_bonus_salary();
}

void Cleaner::calc_salary() {
    this->payment = calc_base_salary(this->salary, this->work_time);
}