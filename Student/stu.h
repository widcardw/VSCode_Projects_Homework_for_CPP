#ifndef _STU_H_
#define _STU_H_
#include "date.h"
#include "course.h"
class Student
{
private:
    string name_;
    string id_;
    Date birth_;
    Course course_;

public:
    Student(string name, string id, Date dirth, Course course);
    Student();
    ~Student();
    void print_stu();
    friend std::istream &operator>>(std::istream &, Student &);
    friend std::ostream &operator<<(std::ostream &, Student &);
};

#endif