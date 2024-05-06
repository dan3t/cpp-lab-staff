#ifndef LAB_CPP_STAFF_MANAGER_H
#define LAB_CPP_STAFF_MANAGER_H

#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee, public Project_Budget, public Heading {
public:
    ProjectManager(int id, std::string name,
                   int work_time, Positions position, Project project) : Employee(id, std::move(name), work_time,
                                                                                  position), project(project) {};

// TODO: Определить
    int calc_pro_additions(int bonus = 0) override;

// TODO: Определить
    int calc_budget_part() override;

// TODO: Определить
    void print_info() override;

// TODO: Определить
    void calc_salary() override;

// TODO: Определить
    int calc_heads() override;

protected:
    Project project;
};

class SeniorManager : public Employee, public Project_Budget, public Heading {
public:
    SeniorManager(int id, std::string name,
                  int work_time, Positions position, std::vector<const Project*> projects) : Employee(id, std::move(name), work_time, position) {};

// TODO: Определить
    int calc_pro_additions(int bonus = 0) override;

// TODO: Определить
    int calc_budget_part() override;

// TODO: Определить
    void print_info() override;

// TODO: Определить
    void calc_salary() override;

// TODO: Определить (мб удалить)
    void add_project(const Project *project);

// TODO: Определить
    int calc_heads() override;

protected:
    std::vector<const Project *> projects;
};

#endif //LAB_CPP_STAFF_MANAGER_H
