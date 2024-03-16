#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "LinkedList.h"
#include"Student.h"

struct CourseInfo {
    std::string courseID;
    std::string courseName;
    std::string className;
    std::string teacherName;
    std::string credits;
    int maxStudent;
    std::string session;

    CourseInfo() : courseID(""), courseName(""), className(""), teacherName(""), credits(""), maxStudent(0), session("") {}

    CourseInfo(const std::string& courseID, const std::string& courseName, const std::string& className, const std::string& teacherName, const std::string& credits, int maxStudent, const std::string& session)
        : courseID(courseID), courseName(courseName), className(className), teacherName(teacherName), credits(credits), maxStudent(maxStudent), session(session) {}
};

struct Course : public CourseInfo {
    CourseInfo courseInfo;
    LinkedList<Student> students;

    Course(const std::string& courseID, const std::string& courseName, const std::string& className, const std::string& teacherName, const std::string& credits, int maxStudent, const std::string& session)
        : courseInfo(courseID, courseName, className, teacherName, credits, maxStudent, session) {}

    void addStudent(const Student& student) {
        students.add(student); //pseudo code
    }

    void removeStudent(const Student& student) {
        students.remove(student); // pseudo code
    }

    void updateCourseInfo();



};

#endif // COURSE_H
