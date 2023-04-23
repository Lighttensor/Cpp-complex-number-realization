#include <stdexcept>
#include <iosfwd>
#include <string>
#include <limits>
#pragma once

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H


const double _2EPS = 4 * std::numeric_limits<double>::epsilon();

struct Complex {
    double Re = 0;
    double Im = 0;

    char left = '{';
    char right = '}';
    char comma = ',';

    Complex(double Re, double Im);
    Complex(double Im);
    Complex(const Complex& complex);

    bool isnull() const;
    double ABS() const;

    std::string makeStr() const;

    std::istream& read(std::istream& in);
    std::ostream& write(std::ostream& out) const;

    Complex& operator+=(const Complex& b);
    Complex& operator+=(const double& b);

    Complex& operator-=(const Complex& b);
    Complex& operator-=(const double& b);

    Complex operator-() const;
    Complex operator+() const;

    Complex& operator=(const Complex& b);
    Complex& operator=(const double& b);

    Complex& operator*=(const Complex& b);
    Complex& operator*=(const double& b);

    Complex& operator/=(const Complex& b);
    Complex& operator/=(const double& b);
};

bool operator!=(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const double& rhs);
bool operator!=(const double& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator==(const Complex& lhs, const double& rhs);
bool operator==(const double& lhs, const Complex& rhs);

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator+(const double& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);
Complex operator-(const double& lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double& rhs);
Complex operator*(const double& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);


std::ostream& operator<<(std::ostream& out, const Complex& rhs);

std::istream& operator>>(std::istream& in, Complex& rhs);

bool equal(const double& lhs, const double& rhs);

#endif






