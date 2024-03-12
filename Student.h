#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <string>
#include <vector>

struct Student : public User {
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string gender;
    std::string dateOfBirth;
    std::string socialID;
    std::vector<std::string> courses;

    Student(const std::string& username, const std::string& password, const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& gender, const std::string& dateOfBirth, const std::string& socialID)
        : User(username, password), studentID(studentID), firstName(firstName), lastName(lastName), gender(gender), dateOfBirth(dateOfBirth), socialID(socialID) {}

    void viewCourses() const {
        // Implement course viewing logic here
    }

    void viewScoreboard() const {
        // Implement scoreboard viewing logic here
    }

    void viewProfile() const override {
        // Implement profile viewing logic here
    }
};

#endif // STUDENT_H