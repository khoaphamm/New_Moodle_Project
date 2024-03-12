#ifndef SEMESTER_H
#define SEMESTER_H

#include <string>
#include <vector>

struct Semester {
    std::string semester;
    std::vector<std::string> courses;

    Semester(const std::string& semester)
        : semester(semester) {}

    void createSemester();
    void addCourse(const std::string& course);
    void viewCourses() const;
};

#endif // SEMESTER_H