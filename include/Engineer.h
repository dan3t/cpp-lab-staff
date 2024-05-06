#ifndef LAB_CPP_STAFF_ENGINEER_H
#define LAB_CPP_STAFF_ENGINEER_H

#include "Personal.h"

class Engineer : public Personal, public Project_Budget {
public:
    Engineer(int id, std::string name, int work_time, Positions positions, int salary, Project project) :
            Personal(id, std::move(name), work_time, position, salary), project(project) {};

    int calc_bonus_salary(int bonus) override;

    void print_info() override;

    int calc_base_salary(int salary, int work_time_salary) override;

protected:
    Project project;
};

class Programmer : public Engineer {
public:
    Programmer(int id, std::string name, int work_time, Positions position, int salary, Project project) :
            Engineer(id, std::move(name), work_time, position, salary, project) {};

    int calc_pro_additions(int bonus) override;
};

class Tester : public Engineer {
    Tester(int id, std::string name, int work_time, Positions position, int salary, Project project) :
            Engineer(id, std::move(name), work_time, position, salary, project) {};

    int calc_pro_additions(int bonus) override;
};

class TeamLeader : public Programmer, public Heading {
    TeamLeader(int id, std::string name, int work_time, Positions position, int salary, Project project) :
            Programmer(id, std::move(name), work_time, position, salary, project) {};

    void calc_salary() override;

    int calc_heads() override;
};

#endif //LAB_CPP_STAFF_ENGINEER_H
