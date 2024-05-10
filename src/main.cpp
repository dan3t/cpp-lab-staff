#include <random>

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

using namespace std;

int main() {

    string personal_path = R"(..\..\data\personal.txt)";
    string manager_path = R"(..\..\data\managers.txt)";
    string engineers_path = R"(..\..\data\engineers.txt)";
    string projects_path = R"(..\..\data\projects.txt)";

    vector<Employee *> staff = StaffFactory::hireStaff(personal_path, manager_path,
                                                             engineers_path, projects_path);

    // Set work time for each employee and calculating salary

    for (auto employee : staff) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(100, 200);
        int work_time = dis(gen);
        employee->set_work_time(work_time);
    }

    for (auto employee : staff) {

        // Set bonus for personal

        switch (employee->get_position()) {
            case driver: {
                int bonus = 1;
                dynamic_cast<Personal*>(employee)->set_bonus(bonus);
                break;
            }
            case programmer: {
                int bonus = 2;
                dynamic_cast<Personal*>(employee)->set_bonus(bonus);
                employee->calc_salary();
            }
            case tester: {
                int bonus = 8;
                dynamic_cast<Personal*>(employee)->set_bonus(bonus);
                employee->calc_salary();
            }
            case team_leader: {
                int bonus = 3;
                dynamic_cast<Personal*>(employee)->set_bonus(bonus);
            }
        }
        employee->calc_salary();
    }

    // Print info

    for (auto employee : staff) {
        employee->print_info();
        cout << "------------------------------------" << endl;
    }

    return 0;
}