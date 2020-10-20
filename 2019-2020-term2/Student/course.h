#ifndef _COURSE_H_
#define _COURSE_H_
#include <string>
using namespace std;
class Course
{
private:
    int term_;
    string course_name_;
    string teacher_;
    int score_;

public:
    Course(int term, string course_name, string teacher, int score);
    Course();
    Course(const Course &onecourse);
    Course &operator=(const Course &onecourse);
    ~Course();
    void course_print();
    friend std::istream &operator>>(std::istream &, Course &);
    friend std::ostream &operator<<(std::ostream &, Course &);
};

#endif