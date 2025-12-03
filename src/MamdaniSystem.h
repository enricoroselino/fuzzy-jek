#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "FuzzyVariable.h"
#include "MamdaniRule.h"

class MamdaniSystem
{
private:
    std::vector<FuzzyVariable *> inputVariables;
    FuzzyVariable *outputVariable;
    std::vector<MamdaniRule> rules;

    std::unordered_map<std::string, double> centroidValues = {
        {"Low", 30.0},
        {"Medium", 50.0},
        {"High", 70.0}};

public:
    MamdaniSystem(
        const std::vector<FuzzyVariable *> &inputs,
        FuzzyVariable *output,
        const std::vector<MamdaniRule> &ruleSet)
        : inputVariables(inputs), outputVariable(output), rules(ruleSet)
    {
        if (inputs.empty())
            throw std::runtime_error("MamdaniSystem requires at least one input variable.");

        if (output == nullptr)
            throw std::runtime_error("MamdaniSystem requires an output variable.");

        if (ruleSet.empty())
            throw std::runtime_error("MamdaniSystem requires at least one rule.");
    }

    double evaluate(const std::unordered_map<std::string, double> &crispInputs) const
    {
        double numerator = 0.0;
        double denominator = 0.0;

        for (const auto &rule : rules)
        {
            double ruleStrength = 1.0;

            for (const auto &ant : rule.antecedents)
            {
                auto it = std::find_if(inputVariables.begin(), inputVariables.end(),
                                       [&](auto *var)
                                       { return var->variableName == ant.variable; });

                if (it == inputVariables.end())
                    throw std::runtime_error("Unknown variable in rule antecedent: " + ant.variable);

                double mu = (*it)->getMembershipValue(ant.membershipName, crispInputs.at((*it)->variableName));
                ruleStrength = std::min(ruleStrength, mu);
            }

            numerator += ruleStrength * centroidValues.at(rule.consequent.membershipName);
            denominator += ruleStrength;
        }

        return denominator == 0.0 ? 0.0 : numerator / denominator;
    }
};
