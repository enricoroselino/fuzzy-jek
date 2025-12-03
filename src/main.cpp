#include <iostream>
#include <unordered_map>
#include <limits>

#include "TriangularMembershipFunction.h"
#include "FuzzyVariable.h"
#include "MamdaniSystem.h"
#include "SugenoSystem.h"
#include "FuzzyRules.h"

double getValidatedInput(const std::string &label, int minValue, double maxValue)
{
    double value;

    while (true)
    {
        std::cout << "Enter " << label << " (" << minValue << "–" << maxValue << "): ";
        std::cin >> value;

        // Handle non-numeric input
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a numeric value.\n";
            continue;
        }

        // Range validation
        if (value < minValue || value > maxValue)
        {
            std::cout << "Value must be between " << minValue << " and " << maxValue << ".\n";
            continue;
        }

        return value;
    }
}

int main()
{

    // --------------------- DEFINE FUZZY VARIABLES ---------------------
    FuzzyVariable discipline("Discipline");
    discipline.addMembershipFunction({"Low", 1, 3, 5});
    discipline.addMembershipFunction({"Medium", 3, 5, 7});
    discipline.addMembershipFunction({"High", 5, 7, 9});

    FuzzyVariable productivity("Productivity");
    productivity.addMembershipFunction({"Low", 1, 3, 5});
    productivity.addMembershipFunction({"Medium", 3, 5, 7});
    productivity.addMembershipFunction({"High", 5, 7, 9});

    FuzzyVariable performance("Performance");
    performance.addMembershipFunction({"Low", 10, 30, 50});
    performance.addMembershipFunction({"Medium", 30, 50, 70});
    performance.addMembershipFunction({"High", 50, 70, 90});

    // build fuzzy systems
    MamdaniSystem mamdaniSystem({&discipline, &productivity}, &performance, MAMDANI_RULE_SET);
    SugenoSystem sugenoSystem({&discipline, &productivity}, SUGENO_RULE_SET);

    // get user inputs
    double disciplineInput = getValidatedInput("Discipline", 1, 10);
    double productivityInput = getValidatedInput("Productivity", 1, 10);

    // process the inputs
    std::unordered_map<std::string, double> crispInputs{
        {"Discipline", disciplineInput},
        {"Productivity", productivityInput}};

    double mamdaniResult = mamdaniSystem.evaluate(crispInputs);
    double sugenoResult = sugenoSystem.evaluate(crispInputs);

    // --------------------- OUTPUT RESULTS ---------------------
    std::cout << "\n=== PERFORMANCE RESULTS ===\n";
    std::cout << "Mamdani Output : " << mamdaniResult << "\n";
    std::cout << "Sugeno Output  : " << sugenoResult << "\n";

    return 0;
}
