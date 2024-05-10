#include <unordered_map>

#include "Employee.h"

int Project::get_num_of_employees() const {
    return this->number_of_employees;
}

int Project::get_budget() const {
    return this->budget;
}

int Project::get_id() const {
    return this->id;
}

std::string Employee::get_position_print() const {
    std::unordered_map<Positions, std::string> map = {
            {programmer,      "programmer"},
            {team_leader,     "team_leader"},
            {project_manager, "project_manager"},
            {senior_manager,  "senior_manager"},
            {cleaner,         "cleaner"},
            {driver,          "driver"},
            {tester,          "tester"}
    };
    return map[this->position];
}

void Employee::set_work_time(int time) {
    this->work_time = time;
}

Positions Employee::get_position() const {
    return this->position;
}
