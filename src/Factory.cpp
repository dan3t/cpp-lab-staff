#include "Factory.h"
#include "Manager.h"
#include "Engineer.h"

std::vector<Employee *> StaffFactory::hireStaff(const std::string &personal_path, const std::string &managers_path,
                                                      const std::string &engineers_path, const std::string &projects_path) {
    // Hash Table "string -> enum"

    std::unordered_map<std::string, Positions> map = {
            {"programmer",      programmer},
            {"team_leader",     team_leader},
            {"project_manager", project_manager},
            {"senior_manager",  senior_manager},
            {"cleaner",         cleaner},
            {"driver",          driver},
            {"tester",          tester}
    };
    // Data

    std::vector<Employee *> staff;
    std::vector<const Project *> projects;

    std::string line;
    std::string buffer;

    // Project parsing

    std::fstream in_project(projects_path);

    if (in_project.is_open()) {
        while (std::getline(in_project, line)) {

            std::istringstream iss(line);
            std::vector<std::string> row;

            while (iss >> buffer) {
                row.push_back(buffer);
            }

            const int id = std::stoi(row[0]);
            const int budget = std::stoi(row[1]);
            const int number_of_employees = std::stoi(row[2]);

            // Add project to vector

            const Project *project = new Project(id, budget, number_of_employees);
            projects.push_back(project);
        }
    }

    in_project.close();
    line.clear();
    buffer.clear();

    // Manager parsing

    std::fstream f_managers(managers_path);

    if (f_managers.is_open()) {
        while (std::getline(f_managers, line)) {

            std::istringstream iss(line);
            std::vector<std::string> row;

            while (iss >> buffer) {
                row.push_back(buffer);
            }

            const int id = std::stoi(row[0]);
            const std::string name = row[1] + ' ' + row[2] + ' ' + row[3];
            const Positions position = map[row[4]];
            Employee* employee;
            switch (position) {
                case project_manager: {
                    const int project_id = std::stoi(row[5]);
                    const Project *project = findProject(projects, project_id);
                    employee = new ProjectManager(id, name, 0, position, {project});
                    break;
                }
                case senior_manager: {
                    employee = new SeniorManager(id, name, 0, position, projects);
                    break;
                }
            }

            staff.push_back(employee);
        }
    }

    f_managers.close();
    line.clear();
    buffer.clear();

    // Engineers Path

    std::fstream f_engineers(engineers_path);

    if (f_engineers.is_open()) {
        while (std::getline(f_engineers, line)) {

            std::istringstream iss(line);
            std::vector<std::string> row;

            while (iss >> buffer) {
                row.push_back(buffer);
            }

            const int id = std::stoi(row[0]);
            const std::string name = row[1] + ' ' + row[2] + ' ' + row[3];
            const Positions position = map[row[4]];
            const int project_id = std::stoi(row[5]);
            const int salary = std::stoi(row[6]);

            const Project* project = findProject(projects, project_id);
            Employee* employee;

            switch (position) {
                case programmer:
                    employee = new Programmer(id, name, 0, position, salary, *project);
                    break;
                case tester:
                    employee = new Tester(id, name, 0, position, salary, *project);
                    break;
                case team_leader:
                    employee = new TeamLeader(id, name, 0, position, salary, *project);
                    break;
            }

            staff.push_back(employee);
        }
    }

    f_engineers.close();
    line.clear();
    buffer.clear();

    // Personal Path

    std::fstream f_personal(personal_path);

    if (f_personal.is_open()) {
        while (std::getline(f_personal, line)) {

            std::istringstream iss(line);
            std::vector<std::string> row;

            while (iss >> buffer) {
                row.push_back(buffer);
            }

            const int id = std::stoi(row[0]);
            const std::string name = row[1] + ' ' + row[2] + ' ' + row[3];
            const Positions position = map[row[4]];
            const int salary = std::stoi(row[5]);

            Employee* employee;

            switch (position) {
                case driver:
                    employee = new Driver(id, name, 0, position, salary);
                    break;
                case cleaner:
                    employee = new Cleaner(id, name, 0, position, salary);
                    break;
            }

            staff.push_back(employee);
        }
    }

    f_personal.close();


    return staff;
}

const Project *StaffFactory::findProject(const std::vector<const Project *> &projects, int id) {
    for (auto project : projects) {
        if (project->get_id() == id) {
            return project;
        }
    }
    return nullptr;
}
