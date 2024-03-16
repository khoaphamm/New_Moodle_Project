#include "LinkedList.h"
#include "Semester.h"

struct SchoolYear {
    std::string year;
    LinkedList<Semester> semesters;

    SchoolYear(const std::string& year)
        : year(year) {}

    void createYear();

    void addSemester(const Semester& semester) {
        semesters.add(semester);
    }

    void viewSemesters() const;


};
