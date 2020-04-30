//CTeacherAdministrator
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class CTeacher
{
protected:
    string name_;
    string sex_;
    string address_;
    string tele_;
    string title_;

public:
    CTeacher(string name, string sex, string address, string tele, string title);
    void display_t();
};
CTeacher::CTeacher(string name, string sex, string address, string tele, string title)
    : name_(name), sex_(sex), address_(address), tele_(tele), title_(title) {}
void CTeacher::display_t()
{
    cout << "name: " << name_ << endl;
    cout << "sex: " << sex_ << endl;
    cout << "address: " << address_ << endl;
    cout << "telephone: " << tele_ << endl;
    cout << "title: " << title_ << endl;
}

class CAdministrator
{
protected:
    string name_;
    string sex_;
    string address_;
    string tele_;
    string post_;

public:
    CAdministrator(string name, string sex, string address, string tele, string post);
    void display_a();
};
CAdministrator::CAdministrator(string name, string sex, string address, string tele, string post)
    : name_(name), sex_(sex), address_(address), tele_(tele), post_(post) {}
void CAdministrator::display_a()
{
    cout << "name: " << name_ << endl;
    cout << "sex: " << sex_ << endl;
    cout << "address: " << address_ << endl;
    cout << "telephone: " << tele_ << endl;
    cout << "post: " << post_ << endl;
}

class CTeacher_Administrator : public CTeacher, public CAdministrator
{
protected:
    double wages_;

public:
    CTeacher_Administrator(string name, string sex, string address, string tele, string title, string post, double wages);
    void show();
};
CTeacher_Administrator::CTeacher_Administrator(string name, string sex, string address, string tele, string title, string post, double wages)
    : CTeacher(name, sex, address, tele, title), CAdministrator(name, sex, address, tele, post), wages_(wages) {}
void CTeacher_Administrator::show()
{
    CTeacher::display_t();
    cout << "post: " << CAdministrator::post_ << endl;
    cout << "wages: " << wages_ << endl;
}

int main()
{
    CTeacher_Administrator a("Mike", "m", "WenYuan RD 1st", "13800000000", "senior", "teacher", 7000.0);
    a.show();
    return 0;
}