//
// Created by denis on 17.04.2024.
//

#define STAFF_DATA_SIZE 3
#define PROJECT_DATA_SIZE 3

#include "Factory.h"
#include "Manager.h"

std::vector<const Employee *> StaffFactory::hireStaff(const std::string &staff_path, const std::string &project_path) {

    // Hash Table "string -> enum"

    std::unordered_map<std::string, Positions> map = {
            {"programmer", programmer},
            {"team_leader", team_leader},
            {"project_manager", project_manager},
            {"senior_manager", senior_manager},
            {"cleaner", cleaner},
            {"driver", driver},
            {"tester", driver}
    };

    // Data

    std::vector<const Employee *> staff;
    std::vector<const Project *> projects;

    std::string line;

    // Project parsing

    std::ifstream in_project(project_path);

    if (in_project.is_open()) {
        while (std::getline(in_project, line)) {
            std::istringstream iss(line);
            std::string buffer;
            std::vector<std::string> data(PROJECT_DATA_SIZE);
            while (iss >> buffer) {
                data.push_back(buffer);
            }
            const int id = std::stoi(data[0]);
            const int budget = std::stoi(data[1]);
            const int number_of_employees = std::stoi(data[2]);

            // Add project to vector

            const Project *project = new Project(id, budget, number_of_employees);
            projects.push_back(project);
        }
    }

    in_project.close();

    // Staff parsing

    std::ifstream in_staff(staff_path);
    if (in_staff.is_open()) {
        while (std::getline(in_staff, line)) {
            std::istringstream iss(line);
            std::string buffer;
            std::vector<std::string> data(STAFF_DATA_SIZE);
            while (iss >> buffer) {
                data.push_back(buffer);
            }
            const int id = std::stoi(data[0]);
            const std::string name = data[1] + data[2] + data[3];
            Positions position = map[data[4]];
            // TODO: checkpoint, убрать переменные за скоуп, коммит
            switch (position) {
                case project_manager:
                    int project_id = std::stoi(data[5]);
                    const Project* project = findProject(projects, project_id);
                    const ProjectManager* project_manager = new ProjectManager(id, name, 0, position, *project);
                    staff.push_back(project_manager);
                    break;
                case senior_manager:
                    const SeniorManager* senior_manager = new SeniorManager(id, name, 0, position, projects);
                    staff.push_back(senior_manager);
                    break;
                default:
                    break;
            }
        }
    }
    in_staff.close();

    return staff;
}

const Project *StaffFactory::findProject(std::vector<const Project *> projects, int id) {
    for (auto project : projects) {
        if (project->get_id() == id) {
            return project;
        }
    }
    return nullptr;
}
