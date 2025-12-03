#pragma once
#include <string>
#include <unordered_map>
#include "TriangularMembershipFunction.h"

class FuzzyVariable
{
public:
    std::string variableName;
    std::unordered_map<std::string, TriangularMembershipFunction> membershipFunctions;

    explicit FuzzyVariable(const std::string &name) : variableName(name) {}

    void addMembershipFunction(const TriangularMembershipFunction &mf)
    {
        membershipFunctions.emplace(mf.name, mf);
    }

    double getMembershipValue(const std::string &membershipName, double crispValue) const
    {
        return membershipFunctions.at(membershipName).compute(crispValue);
    }
};