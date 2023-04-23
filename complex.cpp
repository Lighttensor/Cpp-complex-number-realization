#include "complex.h"
#include <cmath>
#include <string>
#include <ostream>
#include <istream>

Complex::Complex(double Re, double Im){
    Re = Re;
    Im = Im;
}

Complex::Complex(double Re){
    Re = Re;
    Im = 0;
}

Complex::Complex(const Complex& complex){
    Re = complex.Re;
    Im = complex.Im;
}

Complex::Complex(){
    Re = 0;
    Im = 0;
}

bool Complex::isnull() const{
    if(equal(Re, 0) and equal(Im, 0))
        return true;
    return false;
}

double Complex::ABS() const{
    return sqrt(Re * Re + Im * Im);
}

std::string Complex::makeStr() const{
    char buff[100];
    char sym = (Im >= 0) ? '+' : '-';
    sprintf(buff, "%f %c %fi", Re, sym, std::abs(Im));
    return std::string(buff);
}

Complex& Complex::operator=(const Complex& b){
    Re = b.Re;
    Im = b.Im;
    return *this;
}

Complex& Complex::operator=(const double& b){
    Re = b;
    Im = 0;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.Re + rhs.Re, lhs.Im + rhs.Im);
}

Complex operator+(const Complex& lhs, const double& rhs){
    return Complex(lhs.Re + rhs, lhs.Im);
}

Complex operator+(const double& lhs, const Complex& rhs){
    return Complex(lhs + rhs.Re, rhs.Im);
}

Complex Complex::operator+() const{
    return *this;
};

Complex& Complex::operator+=(const Complex& b){
    Re += b.Re;
    Im += b.Im;
    return *this;
}

Complex& Complex::operator+=(const double& b){
    Re += b;
    return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.Re - rhs.Re, lhs.Im - rhs.Im);
}

Complex operator-(const Complex& lhs, const double& rhs){
    return Complex(lhs.Re - rhs, lhs.Im);
}

Complex operator-(const double& lhs, const Complex& rhs){
    return Complex(lhs - rhs.Re, -rhs.Im);
}

Complex Complex::operator-() const{
    return Complex(-Re, -Im);
}

Complex& Complex::operator-=(const Complex& b){
    Re -= b.Re;
    Im -= b.Im;
    return *this;
}

Complex&  Complex::operator-=(const double& b){
    Re -= b;
    return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.Re * rhs.Re - lhs.Im * rhs.Im, lhs.Im * rhs.Re + lhs.Re * rhs.Im);
}

Complex operator*(const Complex& lhs, const double& rhs){
    return Complex(lhs.Re * rhs, lhs.Im * rhs);
}

Complex operator*(const double& lhs, const Complex& rhs){
    return Complex(lhs * rhs.Re, lhs * rhs.Im);
}

Complex&  Complex::operator*=(const Complex& b){
    double ReT = Re * b.Re - Im * b.Im;
    double ImT = Im * b.Re + Re * b.Im;
    Re = ReT;
    Im = ImT;
    return *this;
}

Complex& Complex::operator*=(const double& b){
    Re *= b;
    Im *= b;
    return *this;
}

bool operator==(const Complex& lhs, const Complex& rhs){
    return (equal(lhs.Im, rhs.Im) and equal(lhs.Re, rhs.Re)) ? true : false;
}

bool operator==(const Complex& lhs, const double& rhs){
    return (equal(lhs.Im, 0) and equal(lhs.Re, rhs)) ? true : false;
}

bool operator==(const double& lhs, const Complex& rhs){
    return (equal(lhs, rhs.Re) and equal(rhs.Im, 0)) ? true : false;
}

bool operator!=(const Complex& lhs, const Complex& rhs){
    return !(equal(lhs.Im, rhs.Im) and equal(lhs.Re, rhs.Re)) ? true : false;
}

bool operator!=(const Complex& lhs, const double& rhs){
    return !(equal(lhs.Im, 0) and equal(lhs.Re, rhs)) ? true : false;
}

bool operator!=(const double& lhs, const Complex& rhs){
    return !(equal(lhs, rhs.Re) and equal(rhs.Im, 0)) ? true : false;
}

Complex operator/(const Complex& lhs, const Complex& rhs){
    if(rhs.isnull())
        throw std::runtime_error("Деление на 0\n");
    if(lhs.isnull())
        return lhs;

    double ReT = (lhs.Re * rhs.Re + lhs.Im * rhs.Im) / (rhs.Re * rhs.Re + rhs.Im * rhs.Im);
    double ImT = (lhs.Im * rhs.Re - lhs.Re * rhs.Im) / (rhs.Re * rhs.Re + rhs.Im * rhs.Im);
    return Complex(ReT, ImT);
}

Complex operator/(const Complex& lhs, const double& rhs){
    if(equal(rhs, 0))
        throw std::runtime_error("Деление на 0\n");
    if(lhs.isnull())
        return lhs;

    return Complex(lhs.Re / rhs, lhs.Im / rhs);
}

Complex operator/(const double& lhs, const Complex& rhs){

    if(rhs.isnull())
        throw std::runtime_error("Деление на 0\n");
    if(equal(lhs, 0))
        return lhs;

    return Complex((lhs * rhs.Re)/(rhs.Re*rhs.Re + rhs.Im*rhs.Im), (-lhs * rhs.Im)/(rhs.Re*rhs.Re + rhs.Im*rhs.Im));
}

Complex& Complex::operator/=(const Complex& b){
    if(b.isnull())
        throw std::runtime_error("Деление на 0\n");
    if(this->isnull())
        return *this;
    double ReT = (Re * b.Re + Im * b.Im) / (b.Re*b.Re + b.Im*b.Im);
    double ImT = (Im * b.Re - Re * b.Im) / (b.Re*b.Re + b.Im*b.Im);

    Re = ReT;
    Im = ImT;
    return *this;
}

Complex& Complex::operator/=(const double& b){
    if(equal(b, 0))
        throw std::runtime_error("Деление на 0\n");
    if(this->isnull())
        return *this;

    Re /= b;
    Im /= b;
    return *this;
}

std::ostream& Complex::write(std::ostream &os) const{
    return os << left << Re << comma << Im << right;
}

std::istream& Complex::read(std::istream& is){
    char left = 0;
    char right = 0;
    char sep = 0;

    double tRe = 0.0;
    double tIm = 0.0;

    Re = 0;
    Im = 0;

    is >> left >> tRe >> sep >> tIm >> right;
    if (is.good()) {
        if (left == left and sep == comma and right == right){
            Re = tRe;
            Im = tIm;
        }
        else
            is.setstate(std::ios_base::failbit);
    }
    else
        is.setstate(std::ios_base::failbit);

    return is;
}

std::ostream& operator<<(std::ostream& out, const Complex& rhs){
    return rhs.write(out);
}

std::istream& operator>>(std::istream& in, Complex& rhs) {
    return rhs.read(in);
}

 bool equal(const double& rhs, const double& lhs) {
    return std::abs(rhs - lhs) <= _2EPS;
}

