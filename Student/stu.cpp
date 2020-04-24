#include <iostream>
#include "date.h"
#include "course.h"
#include "stu.h"
using namespace std;
Student::Student(string name, string id, Date birthdate, Course courses)
{
    name_ = name;
    id_ = id;
    birth_ = birthdate;
    course_ = courses;
}
Student::Student() {}
Student::~Student() {}
void Student::print_stu()
{
    cout << name_ << " " << id_ << " ";
    birth_.date_print();
    cout << " ";
    course_.course_print();
    cout << endl;
}
std::istream &operator>>(std::istream &in, Student &person)
{
    in >> person.name_ >> person.id_ >> person.birth_ >> person.course_;
    return in;
}
std::ostream &operator<<(std::ostream &out, Student &person)
{
    out << person.name_ << " " << person.id_ << " " << person.birth_ << " " << person.course_;
    return out;
}
Student &Student::operator=(const Student &one)
{
    if (this == &one)
        return *this;
    name_ = one.name_;
    id_ = one.id_;
    birth_ = one.birth_;
    course_ = one.course_;
    return *this;
}
string Student::rtn_id()
{
    return id_;
}