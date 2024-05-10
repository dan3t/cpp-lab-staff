#ifndef LAB_CPP_STAFF_MANAGER_H
#define LAB_CPP_STAFF_MANAGER_H

#include <utility>
#include <iostream>

#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Project_Budget, public Heading {
public:
    ProjectManager(int id, std::string name,
                   int work_time, Positions position, const std::vector<const Project*>& projects) : Employee(id, std::move(name), work_time,
                                                                                  position), projects(projects) {}
    int calc_budget_part() override;

    int calc_pro_additions(int bonus) override;

    void print_info() const override;

    void calc_salary() override;

    int calc_heads() override;

protected:
    std::vector<const Project *> projects;
};

class SeniorManager : public ProjectManager {
public:
    SeniorManager(int id, std::string name,
                  int work_time, Positions position, const std::vector<const Project*>& projects) : ProjectManager(id, std::move(name), work_time, position, projects) {};

    void calc_salary() override;
};

#endif //LAB_CPP_STAFF_MANAGER_H
