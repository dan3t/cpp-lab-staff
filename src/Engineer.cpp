//
// Created by denis on 17.04.2024.
//
#include "Engineer.h"

// TODO: change
int Engineer::calc_bonus_salary(int bonus) {
    return Personal::calc_bonus_salary(bonus);
}

void Engineer::print_info() const {
    std::cout << "FULL NAME: " << this->name << std::endl;
    std::cout << "Position: " << this->get_position_print() << std::endl;
    std::cout << "Salary (per hour): " << this->salary << std::endl;
    std::cout << "Work time (in hours): " << this->work_time << std::endl;
    std::cout << "Current project: " << this->project.get_id() << std::endl;
    std::cout << "Current payment: " << this->payment << std::endl;
}

int Engineer::calc_base_salary(int salary, int work_time_salary) {
    return salary * work_time_salary;
}

int Engineer::calc_budget_part() {
    return this->project.get_budget() * 0.5 / this->project.get_num_of_employees();
}

void Engineer::calc_salary() {
    this->payment = calc_base_salary(salary, work_time) + calc_pro_additions(bonus) + calc_budget_part();
}

int Programmer::calc_pro_additions(int bonus) {
    return bonus + this->work_time;
}

int Tester::calc_pro_additions(int bonus) {
    return bonus * salary;
}

void TeamLeader::calc_salary() {
    this->payment = Engineer::calc_base_salary(salary, work_time) + Engineer::calc_budget_part() + calc_heads();
}

// 20% от доли которую получают инженеры

int TeamLeader::calc_heads() {
    return Engineer::calc_budget_part() * this->project.get_num_of_employees() * 0.3;
}
