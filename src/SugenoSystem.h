#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "FuzzyVariable.h"
#include "SugenoRule.h"

class SugenoSystem
{
private:
    std::vector<FuzzyVariable *> inputVariables;
    std::vector<SugenoRule> rules;

public:
    SugenoSystem(
        const std::vector<FuzzyVariable *> &inputs,
        const std::vector<SugenoRule> &ruleSet)
        : inputVariables(inputs), rules(ruleSet)
    {
        if (inputs.empty())
            throw std::runtime_error("SugenoSystem requires at least one input variable.");

        if (ruleSet.empty())
            throw std::runtime_error("SugenoSystem requires at least one rule.");
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

            numerator += ruleStrength * rule.consequent.outputValue;
            denominator += ruleStrength;
        }

        return denominator == 0.0 ? 0.0 : numerator / denominator;
    }

    void printRulePredicates(const std::unordered_map<std::string, double> &inputs) const
    {
        std::cout << "\n=== Rule Predicates (Sugeno) ===\n";

        int index = 1;

        for (const auto &rule : rules)
        {
            double ruleStrength = 1.0;

            std::cout << "Rule " << index << ": ";

            for (size_t i = 0; i < rule.antecedents.size(); ++i)
            {
                const auto &ant = rule.antecedents[i];
                std::cout << ant.variable << "=" << ant.membershipName;

                if (i < rule.antecedents.size() - 1)
                    std::cout << " AND ";
            }

            for (const auto &ant : rule.antecedents)
            {
                auto it = std::find_if(inputVariables.begin(), inputVariables.end(),
                                       [&](auto *var)
                                       { return var->variableName == ant.variable; });

                double x = inputs.at((*it)->variableName);
                double mu = (*it)->getMembershipValue(ant.membershipName, x);

                ruleStrength = std::min(ruleStrength, mu);
            }

            std::cout << "  → α = " << ruleStrength << "\n";
            index++;
        }
    }
};
