#ifndef STAFF_H
#define STAFF_H

#include "User.h"
#include <string>
#include <vector>

struct Staff : public User {
    std::string staffID;
    std::string firstName;
    std::string lastName;

    Staff(const std::string& username, const std::string& password, const std::string& staffID, const std::string& firstName, const std::string& lastName)
        : User(username, password), staffID(staffID), firstName(firstName), lastName(lastName) {}

    void createClass();

    void addStudent();

    void createCourse();

    void viewClasses();

    void viewStudentsInClass();

    void viewCourses();

    void viewStudentsInCourse();

    void exportStudentsInCourse();

    void importScoreboard();
    
    void viewScoreboard();

    void updateStudentResult();

    void publishScoreboard();
};

#endif // STAFF_H