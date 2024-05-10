#include "Personal.h"

void Personal::print_info() const {
    std::cout << "FULL NAME: " << this->name << std::endl;
    std::cout << "Position: " << this->get_position_print() << std::endl;
    std::cout << "Salary (per hour): " << this->salary << std::endl;
    std::cout << "Work time (in hours): " << this->work_time << std::endl;
    std::cout << "Current payment: " << this->payment << std::endl;
}

int Personal::calc_base_salary(int salary_value, int work_time_value) {
    return salary_value * work_time_value;
}

int Personal::calc_bonus_salary(int bonus) {
    return 0;
}

// 30% of the time worked was at night

int Driver::calc_bonus_salary(int bonus) {
    return bonus * work_time * 0.3;
}

void Driver::calc_salary() {
    this->payment = calc_base_salary(this->salary, this->work_time) + calc_bonus_salary();
}

void Cleaner::calc_salary() {
    this->payment = calc_base_salary(this->salary, this->work_time);
}
