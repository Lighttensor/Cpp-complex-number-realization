#include <complex/complex.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <string>

static const double _EPS = _2EPS / 2;

TEST_CASE("Complex::Complex(double, double)") {
    Complex z(0.1, 1.5);

    CHECK(z.re == 0.1);
    CHECK(z.im == 1.5);
}

TEST_CASE("Complex::Complex(double)") {
    Complex z(9.1);

    CHECK(z.re == 9.1);
    CHECK(z.im == 0);
}

TEST_CASE("Complex::operator==(const Complex&, const Complex&)") {
    Complex z1(0.4, 1.3);
    Complex z2(0.4, 1.3);

    CHECK(z1 == z2);
    CHECK(z2 == z1);

    Complex z3(3.3, 4.4);

    CHECK_FALSE(z1 == z3);
    CHECK_FALSE(z3 == z1);

    Complex z4(z1.re + _EPS, z1.im - _EPS);

    CHECK(z1 == z4);
    CHECK(z4 == z1);
}

TEST_CASE("Complex::operator==(const Complex&, const double)") {
    Complex z1(5.2, 0.0);

    CHECK(z1 == 5.2);

    CHECK_FALSE(z1 == 6.2);
    CHECK_FALSE(Complex(0.4, 3.2) == 1.7);

    CHECK(Complex(2.4 - _EPS, _EPS) == 2.4);
    CHECK(z1 == (5.2 + _EPS));
}

TEST_CASE("Complex::operator==(const double, const Complex&)") {
    Complex z1(6.7, 0);

    CHECK(6.7 == z1);

    CHECK_FALSE(1.2 == z1);
    CHECK_FALSE(6.7 == Complex(2.2, 6.7));

    CHECK(6.7 == Complex(6.7 - _EPS, _EPS));
    CHECK((6.7 + _EPS) == Complex(6.7, 0));
}

TEST_CASE("Complex::Complex()") {
    Complex z;

    CHECK(z == 0);
}

TEST_CASE("Complex::Complex(const Complex&)") {
    Complex z1(1.5, 2.5);
    Complex z2(z1);

    CHECK(z2 == z1);
}

TEST_CASE("Complex::operator=(const Complex&)") {
    Complex z1(1.2, 1.3);
    Complex z2 = z1;

    CHECK(z2 == z1);
}

TEST_CASE("Complex::operator=(const double)") {
    CHECK(Complex(3.3) == 3.3);
}

TEST_CASE("Complex::operator!=(const Complex&, const Complex&)") {
    Complex z1(7.8, 2.3);
    Complex z2(3.1, 4.8);

    CHECK(z1 != z2);
    CHECK(z2 != z1);

    Complex z3(7.3, 1.4);

    CHECK(z2 != z3);
    CHECK(z3 != z2);

    Complex z4(z1.re + _EPS, z1.im - _EPS);

    CHECK_FALSE(z1 != z4);
    CHECK_FALSE(z4 != z1);
}

TEST_CASE("Complex::operator!=(const Complex&, const double)") {
    CHECK(Complex(8.1) != 3.2);
    CHECK_FALSE(Complex(8.1) != 8.1);
    CHECK(Complex(8.1, 2.7) != 8.1);

    CHECK_FALSE(Complex(8.1 - _EPS, _EPS) != 8.1);
    CHECK_FALSE(Complex(8.1) != (8.1 + _EPS));
}

TEST_CASE("Complex::operator!=(const double, const Complex&)") {
    CHECK(0.2 != Complex(6.7, 0.0));
    CHECK_FALSE(6.7 != Complex(6.7, 0.0));
    CHECK(1.7 != Complex(1.7, 4.4));

    CHECK_FALSE(Complex(6.7 + _EPS, 0.0 - _EPS) != Complex(6.7 + _EPS, 0.0 - _EPS));
    CHECK_FALSE(5.5 != Complex(5.5 - _EPS, _EPS));
    CHECK_FALSE((6.7 + _EPS) != Complex(6.7, 0.0));
}

TEST_CASE("Complex::operator-()") {
    CHECK(Complex(-9.9, -7.2) == -Complex(9.9, 7.2));
}

TEST_CASE("operator+(const Complex&, const Complex&)") {
    CHECK(Complex(5.1, 3.3) + Complex(1.9, 3.4) == Complex(7, 6.7));
}

TEST_CASE("operator+(const Complex&, const double)") {
    CHECK(Complex(6.4, 8.6) + 3.7 == Complex(10.1, 8.6));
}

TEST_CASE("operator+(const double, const Complex&)") {
    CHECK(3.7 + Complex(6.4, 8.6) == Complex(10.1, 8.6));
}

TEST_CASE("Complex::operator+=(const Complex&)") {
    Complex z = Complex(2.5, 6.3);
    z += Complex(6.1, 2.5);

    CHECK(z == Complex(8.6, 8.8));
}

TEST_CASE("Complex::operator+=(const double)") {
    Complex z = Complex(2.5, 6.3);
    z += 5.6;

    CHECK(z == Complex(8.1, 6.3));
}

TEST_CASE("operator-(const Complex&, const Complex&)") {
    Complex(4.8, 3.1);
    Complex(1.9, 7.5);

    CHECK(Complex(4.8, 3.1) - Complex(1.9, 7.5) == Complex(2.9, -4.4));
}

TEST_CASE("operator-(const Complex&, const double)") {
    Complex z = Complex(2.7, 8.2) - 2.3;

    CHECK(Complex(2.7, 8.2) - 2.3 == Complex(0.4, 8.2));
}

TEST_CASE("operator-(const double, const Complex&)") {
    Complex z = 1.7 - Complex(5.1, 4.3);

    CHECK(1.7 - Complex(5.1, 4.3) == Complex(-3.4, -4.3));
}

TEST_CASE("Complex::operator-=(const Complex&)") {
    Complex z = Complex(2.5, 4.2);
    z -= Complex(3.2, 4.5);

    CHECK(z == Complex(-0.7, -0.3));
}

TEST_CASE("Complex::operator-=(const double)") {
    Complex z = Complex(4.6, 1.7);
    z -= 8.1;

    CHECK(z == Complex(-3.5, 1.7));
}

TEST_CASE("operator*(const Complex&, const Complex&)") {
    Complex(7, 4);
    Complex(3, 4);

    CHECK(Complex(7, 4) * Complex(3, 4) == Complex(5, 40));
    CHECK(Complex(4, 6) * Complex(0) == Complex(0));
}

TEST_CASE("operator*(const Complex&, const double)") {
    CHECK(Complex(3.6, 1.4) * 3 == Complex(10.8, 4.2));
}

TEST_CASE("operator*(const double, const Complex&)") {
    CHECK(3 * Complex(3.6, 1.4) == Complex(10.8, 4.2));
}

TEST_CASE("Complex::operator*=(const Complex&)") {
    Complex z(7, 4);
    z *= Complex(3, 4);

    CHECK(z == Complex(5, 40));
}

TEST_CASE("Complex::operator*=(const double)") {
    Complex z = Complex(5.3, 5.6);
    z *= 3;

    CHECK(z == Complex(15.9, 16.8));
}

TEST_CASE("operator/(const Complex&, const Complex&)") {
    CHECK(Complex(6, 2) / Complex(4, 2) == Complex(1.4, -0.2));
}

TEST_CASE("operator/(const Complex&, const double)") {
    CHECK(Complex(3.3, 2.2) / 1.1 == Complex(3, 2));
}

TEST_CASE("operator/(const double, const Complex&)") {
    CHECK(3 / Complex(6, 3) == Complex(0.4, -0.2));
}

TEST_CASE("Complex::operator/=(const Complex&)") {
    Complex z = Complex(2, 3);
    z /= Complex(3, 4);

    CHECK(z == Complex(0.72, 0.04));
}

TEST_CASE("Complex::operator/=(const double)") {
    Complex z = Complex(3.3, 2.2);
    z /= 1.1;

    CHECK(z == Complex(3, 2));
}

TEST_CASE("SUCCESS - operator>>(std::istream&, Complex&)") {
    std::string input[] = {
            "{3.3,6.2}",
            "{-7.3,3.0}",
            "{0.0,-0.2}"
    };
    double expected[][2] = {
            {3.3,  6.2},
            {-7.3,  3.0},
            {0.0, -0.2}
    };

    int count = 3;
    for (int i = 0; i < count; ++i) {

        CAPTURE(i);
        CAPTURE(input[i]);

        std::stringstream stream(input[i]);

        Complex z;
        stream >> z;
        CHECK(stream.good());
        CHECK(z.re == doctest::Approx(expected[i][0]));
        CHECK(z.im == doctest::Approx(expected[i][1]));
    }
}

TEST_CASE("operaotr<<(std::ostream&, const Complex&)") {
    std::stringstream stream;
    Complex z(3.6, 5.1);

    stream << z;

    std::string str;

    stream >> str;

    CHECK(str == "{3.6,5.1}");
}

TEST_CASE("operaotr>>(std::istream&, Complex&)") {
    std::string input[] = {
            "[3:4]",
            "[4,5]",
            "[.;5]",
            "[5.2,4.6]",
            "(2.4)",
            "(2,5)",
            "{4.3}",
            "(3;45)",
            "(3:5)",
            "3.2,4.5",
            "3:5",
            "6;32",
            ".3;.3",
            "4.7,3.8",
            "{2;55}",
            "{3,.3.}",
            "{.1;2}",
            "{,2.3}",
            "{;3:2}",
            "{3:5}",
            "[1.4]",
            "[5;4]",
    };

    for (int i=0; i < 27; ++i){

        CAPTURE(input[i]);

        std::stringstream stream;
        stream << input[i];
        Complex z;
        stream >> z;

        CHECK(stream.fail());
        CHECK(z.re == 0.0);
        CHECK(z.im == 0.0);

        stream.clear();
    }
}

TEST_CASE("isZero method test") {
    CHECK(Complex().isZero());
    CHECK(Complex(0, 0).isZero());
    CHECK((Complex(5, 1) - Complex(5, 1)).isZero());
    CHECK((Complex(5, 0) -5).isZero());

    CHECK_FALSE(Complex(5, 0).isZero());
    CHECK_FALSE((Complex() + 5).isZero());
    CHECK((Complex() + 0).isZero());

}
