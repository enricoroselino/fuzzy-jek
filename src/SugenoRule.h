#pragma once
#include <string>
#include <vector>

struct SugenoAntecedent
{
    std::string variable;
    std::string membershipName;
};

struct SugenoConsequent
{
    double outputValue;
};

class SugenoRule
{
public:
    std::vector<SugenoAntecedent> antecedents;
    SugenoConsequent consequent;

    SugenoRule(const std::vector<SugenoAntecedent> &ants,
               const SugenoConsequent &cons)
        : antecedents(ants), consequent(cons) {}
};