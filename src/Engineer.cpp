//
// Created by denis on 17.04.2024.
//
#include "Engineer.h"

// TODO: change
int Engineer::calc_bonus_salary(int bonus) {
    return Personal::calc_bonus_salary(bonus);
}

void Engineer::print_info() {
    Personal::print_info();
}

int Engineer::calc_base_salary(int salary, int work_time_salary) {
    return Personal::calc_base_salary(salary, work_time_salary);
}

int Programmer::calc_pro_additions(int bonus) {
    return 0;
}

int Tester::calc_pro_additions(int bonus) {
    return 0;
}

void TeamLeader::calc_salary() {

}

int TeamLeader::calc_heads() {
    return 0;
}
