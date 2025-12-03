#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
#include "FuzzyVariable.h"
#include "MamdaniRule.h"

class MamdaniSystem
{
private:
    std::vector<FuzzyVariable *> inputVariables;
    FuzzyVariable *outputVariable;
    std::vector<MamdaniRule> rules;

public:
    MamdaniSystem(
        const std::vector<FuzzyVariable *> &inputs,
        FuzzyVariable *output,
        const std::vector<MamdaniRule> &ruleSet)
        : inputVariables(inputs),
          outputVariable(output),
          rules(ruleSet)
    {
        if (inputs.empty())
            throw std::runtime_error("MamdaniSystem requires at least one input variable.");

        if (!output)
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
                auto it = std::find_if(
                    inputVariables.begin(), inputVariables.end(),
                    [&](auto *var)
                    { return var->variableName == ant.variable; });

                if (it == inputVariables.end())
                    throw std::runtime_error("Unknown variable: " + ant.variable);

                double inputValue = crispInputs.at((*it)->variableName);
                double mu = (*it)->getMembershipValue(ant.membershipName, inputValue);

                ruleStrength = std::min(ruleStrength, mu);
            }

            // ★ AUTO-CENTROID EXTRACTED FROM OUTPUT MEMBERSHIP FUNCTION
            const auto *mf = outputVariable->getFunction(rule.consequent.membershipName);
            double centroid = mf->getCentroid();

            numerator += ruleStrength * centroid;
            denominator += ruleStrength;
        }

        return denominator == 0.0 ? 0.0 : numerator / denominator;
    }
};
