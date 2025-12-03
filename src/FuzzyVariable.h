#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "TriangularMembershipFunction.h"

class FuzzyVariable
{
public:
    std::string variableName;
    std::vector<TriangularMembershipFunction> functions;

    FuzzyVariable(const std::string &name)
        : variableName(name) {}

    void addMembershipFunction(const TriangularMembershipFunction &mf)
    {
        functions.push_back(mf);
    }

    double getMembershipValue(const std::string &functionName, double x) const
    {
        for (const auto &mf : functions)
            if (mf.name == functionName)
                return mf.compute(x);

        throw std::runtime_error("Membership function not found: " + functionName);
    }

    // ★ NEW: allow MamdaniSystem to read the centroid
    const TriangularMembershipFunction *getFunction(const std::string &name) const
    {
        for (const auto &mf : functions)
            if (mf.name == name)
                return &mf;

        throw std::runtime_error("Membership function not found: " + name);
    }
};
