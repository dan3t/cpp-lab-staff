#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <utility>
#include <vector>

enum Positions {
    programmer,
    team_leader,
    project_manager,
    senior_manager,
    cleaner,
    driver,
    tester,
};

class Project {
public:
    Project(int id, int budget, int number_of_employees) : id(id), budget(budget),
                                                           number_of_employees(number_of_employees) {}

    int get_num_of_employees() const;

    int get_budget() const;

    int get_id() const;

private:
    int id;
    int budget;
    int number_of_employees;
};

class Employee {
public:
    Employee(int id, std::string name,
             int work_time, Positions position) :
            id(id), name(std::move(name)),
            work_time(work_time), position(position) {}

    virtual void calc_salary() = 0;

    virtual void print_info() = 0;

private:
    int id;
protected:
    Positions position;
    int payment;
    int work_time;
    std::string name;
    std::vector<std::string> enum_print = {"programmer",
                                           "team_leader",
                                           "project_manager",
                                           "senior_manager",
                                           "cleaner",
                                           "driver",
                                           "tester"};
};

#endif  // INCLUDE_EMPLOYEE_H_
