#include "Manager.h"

void ProjectManager::calc_salary() {
    this->payment = calc_heads() + calc_budget_part();
}

// За каждого получает 5000 у.е.

int ProjectManager::calc_heads() {
    return 5000 * this->projects.front()->get_num_of_employees();
}

void ProjectManager::print_info() const {
    std::cout << "FULL NAME: " << this->name << std::endl;
    std::cout << "Position: " << this->get_position_print() << std::endl;
    std::cout << "Work time (in hours): " << this->work_time << std::endl;
    std::cout << "Manages project/projects: ";
    for (auto project : this->projects) {
        std::cout << project->get_id() << " ";
    }
    std::cout << std::endl;
    std::cout << "Current payment: " << this->payment << std::endl;
}

// Получает половину от бюджета проекта

int ProjectManager::calc_budget_part() {
    return this->projects.front()->get_budget() * 0.5;
}

int ProjectManager::calc_pro_additions(int bonus) {
    return 0;
}

// Получает 15% с каждого проекта + за руководство

void SeniorManager::calc_salary() {
    int projects_part = 0;
    for (auto project : this->projects) {
        projects_part += 0.15 * project->get_budget();
    }
    this->payment = projects_part + ProjectManager::calc_heads();
}