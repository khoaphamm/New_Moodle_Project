#ifndef STUDENT_H
#define STUDENT_H

#include <string>


struct Student{
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string gender;
    std::string dateOfBirth;
    std::string socialID;

    Student(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& gender, const std::string& dateOfBirth, const std::string& socialID)
        :studentID(studentID), firstName(firstName), lastName(lastName), gender(gender), dateOfBirth(dateOfBirth), socialID(socialID) {}


    void viewCourses();

    void viewScoreboard();

    bool operator==(const Student& other) const {
        return studentID == other.studentID;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }

    bool operator>(const Student& other) const {
        return studentID > other.studentID;
    }

    bool operator<(const Student& other) const {
        return studentID < other.studentID;
    }
};

#endif // STUDENT_H
