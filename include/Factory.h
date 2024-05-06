#ifndef LAB_CPP_STAFF_FACTORY_H
#define LAB_CPP_STAFF_FACTORY_H

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

#include "Employee.h"

class StaffFactory {
public:
    static std::vector<const Employee *> hireStaff(const std::string &staff_path, const std::string &project_path);

    static const Project *findProject(std::vector<const Project *> projects, int id);
};

#endif //LAB_CPP_STAFF_FACTORY_H
