#ifndef _CFRACTION_H
#define _CFRACTION_H
class Fraction
{
private:
    int m_up, m_down;

public:
    Fraction(int = 0, int = 1);
    ~Fraction();
    void set_up(int);
    void set_down(int);
    void display() const;
    friend Fraction &operator++(Fraction &);
    friend Fraction operator++(Fraction &, int);
    friend Fraction &operator--(Fraction &);
    friend Fraction operator--(Fraction &, int);
    friend Fraction operator+(const Fraction &, const Fraction &);
    friend Fraction operator-(const Fraction &, const Fraction &);
    friend Fraction operator*(const Fraction &, const Fraction &);
    friend Fraction operator/(const Fraction &, const Fraction &);
    friend bool operator>(const Fraction &, const Fraction &);
    friend bool operator==(const Fraction &, const Fraction &);
    friend bool operator<(const Fraction &, const Fraction &);
    friend std::istream &operator>>(std::istream &, Fraction &);
    friend std::ostream &operator<<(std::ostream &, Fraction &);
};
#endif