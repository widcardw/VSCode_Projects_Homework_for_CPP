/* 试建立一个学生类，除具有姓名、学号、出生年月等信息，
   还要有学生的修课记录，要求按照学期记录，根据学期选课情
   况动态申请空间。修课记录包括：学生的课程名、教师、成绩等信息。
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;

class Date
{
private:
    int year_;
    int month_;
    int day_;

public:
    Date(int year, int month, int day)
    {
        year_ = year;
        month_ = month;
        day_ = day;
    }
    Date() {}
    Date(const Date &oneday)
    {
        year_ = oneday.year_;
        month_ = oneday.month_;
        day_ = oneday.day_;
    }
    Date &operator=(const Date &oneday)
    {
        if (this == &oneday)
            return *this;
        year_ = oneday.year_;
        month_ = oneday.month_;
        day_ = oneday.day_;
        return *this;
    }
    void date_print()
    {
        cout << year_ << "-" << month_ << "-" << day_;
    }
    ~Date(){};
};

class Course
{
private:
    int term_;
    string course_name_;
    string teacher_;
    int score_;

public:
    Course(int term, string course_name, string teacher, int score)
    {
        term_ = term;
        course_name_ = course_name;
        teacher_ = teacher;
        score_ = score;
    }
    Course() {}
    Course(const Course &onecourse)
    {
        term_ = onecourse.term_;
        course_name_ = onecourse.course_name_;
        teacher_ = onecourse.teacher_;
        score_ = onecourse.score_;
    }
    Course &operator=(const Course &onecourse)
    {
        if (this == &onecourse)
            return *this;
        term_ = onecourse.term_;
        course_name_ = onecourse.course_name_;
        teacher_ = onecourse.teacher_;
        score_ = onecourse.score_;
        return *this;
    }
    ~Course() {}
    void course_print()
    {
        cout << term_ << " " << course_name_ << " " << teacher_ << " " << score_;
    }
};

class Student
{
private:
    string name_;
    string id_;
    Date birthdate_;
    Course courses_;

public:
    Student(string name, string id, Date birthdate, Course courses)
    {
        name_ = name;
        id_ = id;
        birthdate_ = birthdate;
        courses_ = courses;
    }
    Student() {}
    ~Student() {}
    void print()
    {
        cout << name_ << " " << id_ << " ";
        birthdate_.date_print();
        cout << " ";
        courses_.course_print();
        cout << endl;
    }
};

void read(ifstream &fin, Student *stu)
{
    string name, id;
    fin >> name >> id;
    int year, month, day;
    fin >> year >> month >> day;
    Date birthdate(year, month, day);
    int term, score;
    string course_name, teacher;
    fin >> term >> course_name >> teacher >> score;
    Course courses(term, course_name, teacher, score);
    *stu = Student(name, id, birthdate, courses);
}
int main()
{
    ifstream fin("stu.txt");
    if (!fin)
    {
        cout << "Cannot open the file!" << endl;
        exit(1);
    }
    int num;
    fin >> num;
    Student *stu;
    stu = new Student[num];
    for (int i = 0; i < num; ++i)
    {
        read(fin, stu + i);
        stu[i].print();
    }
    return 0;
}