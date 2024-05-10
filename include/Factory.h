#ifndef LAB_CPP_STAFF_FACTORY_H
#define LAB_CPP_STAFF_FACTORY_H

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

// Amount of columns in data set
#define MANAGERS_ROW_SIZE 6
#define ENGINEERS_ROW_SIZE 7
#define PERSONAL_ROW_SIZE 6
#define PROJECT_ROW_SIZE 3

#include "Employee.h"

class StaffFactory {
public:
    static std::vector<Employee *> hireStaff(const std::string &personal,
                                                   const std::string &managers,
                                                   const std::string &engineers,
                                                   const std::string &projects);

    static const Project *findProject(const std::vector<const Project *> &projects, int id);
};

#endif //LAB_CPP_STAFF_FACTORY_H
