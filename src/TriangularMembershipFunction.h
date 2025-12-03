#pragma once
#include <string>

class TriangularMembershipFunction
{
public:
    std::string name;
    double left;
    double center;
    double right;

    TriangularMembershipFunction(const std::string &name, double left, double center, double right)
        : name(name), left(left), center(center), right(right) {}

    double compute(double x) const
    {
        if (x <= left || x >= right)
            return 0.0;
        if (x == center)
            return 1.0;
        if (x > left && x < center)
            return (x - left) / (center - left);
        return (right - x) / (right - center);
    }
};