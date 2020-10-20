#include <iostream>
#include <cstring>
#include <string>
#include "course.h"
Course::Course(int term, string course_name, string teacher, int score)
{
    term_ = term;
    course_name_ = course_name;
    teacher_ = teacher;
    score_ = score;
}
Course::Course() {}
Course::Course(const Course &onecourse)
{
    term_ = onecourse.term_;
    course_name_ = onecourse.course_name_;
    teacher_ = onecourse.teacher_;
    score_ = onecourse.score_;
}
Course &Course::operator=(const Course &onecourse)
{
    if (this == &onecourse)
        return *this;
    term_ = onecourse.term_;
    course_name_ = onecourse.course_name_;
    teacher_ = onecourse.teacher_;
    score_ = onecourse.score_;
    return *this;
}
Course::~Course() {}
void Course::course_print()
{
    cout << term_ << " " << course_name_ << " " << teacher_ << " " << score_;
}
std::istream &operator>>(std::istream &in, Course &course)
{
    in >> course.term_ >> course.course_name_ >> course.teacher_ >> course.score_;
    return in;
}
std::ostream &operator<<(std::ostream &out, Course &course)
{
    out << course.term_ << " " << course.course_name_ << " " << course.teacher_ << " " << course.score_;
    return out;
}