#ifndef CLASS_H
#define CLASS_H

#include <string>
#include "LinkedList.h"
#include "Student.h"

struct Class {
    std::string classID;
    LinkedList<Student> students;

    Class(const std::string& classID)
        : classID(classID) {}

    void addStudent(const Student& student){
        students.add(student); //pseudo code
    }

    void removeStudent(const Student& student);
};

#endif // CLASS_H