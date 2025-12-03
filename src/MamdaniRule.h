#pragma once
#include <string>
#include <vector>

struct MamdaniAntecedent
{
    std::string variable;
    std::string membershipName;
};

struct MamdaniConsequent
{
    std::string membershipName;
};

class MamdaniRule
{
public:
    std::vector<MamdaniAntecedent> antecedents;
    MamdaniConsequent consequent;

    MamdaniRule(const std::vector<MamdaniAntecedent> &ants,
                const MamdaniConsequent &cons)
        : antecedents(ants), consequent(cons) {}
};