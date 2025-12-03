#pragma once
#include <vector>
#include "MamdaniRule.h"
#include "SugenoRule.h"

// Constant Mamdani rules
const std::vector<MamdaniRule> MAMDANI_RULE_SET = {
    // Discipline Low
    MamdaniRule({{"Discipline", "Low"}, {"Productivity", "Low"}}, {"Low"}),
    MamdaniRule({{"Discipline", "Low"}, {"Productivity", "Medium"}}, {"Low"}),
    MamdaniRule({{"Discipline", "Low"}, {"Productivity", "High"}}, {"Medium"}),

    // Discipline Medium
    MamdaniRule({{"Discipline", "Medium"}, {"Productivity", "Low"}}, {"Low"}),
    MamdaniRule({{"Discipline", "Medium"}, {"Productivity", "Medium"}}, {"Medium"}),
    MamdaniRule({{"Discipline", "Medium"}, {"Productivity", "High"}}, {"High"}),

    // Discipline High
    MamdaniRule({{"Discipline", "High"}, {"Productivity", "Low"}}, {"Medium"}),
    MamdaniRule({{"Discipline", "High"}, {"Productivity", "Medium"}}, {"High"}),
    MamdaniRule({{"Discipline", "High"}, {"Productivity", "High"}}, {"High"})};

// Constant Sugeno rules
const std::vector<SugenoRule> SUGENO_RULE_SET = {
    // Discipline Low
    SugenoRule({{"Discipline", "Low"}, {"Productivity", "Low"}}, {30.0}),
    SugenoRule({{"Discipline", "Low"}, {"Productivity", "Medium"}}, {30.0}),
    SugenoRule({{"Discipline", "Low"}, {"Productivity", "High"}}, {50.0}),

    // Discipline Medium
    SugenoRule({{"Discipline", "Medium"}, {"Productivity", "Low"}}, {30.0}),
    SugenoRule({{"Discipline", "Medium"}, {"Productivity", "Medium"}}, {50.0}),
    SugenoRule({{"Discipline", "Medium"}, {"Productivity", "High"}}, {70.0}),

    // Discipline High
    SugenoRule({{"Discipline", "High"}, {"Productivity", "Low"}}, {50.0}),
    SugenoRule({{"Discipline", "High"}, {"Productivity", "Medium"}}, {70.0}),
    SugenoRule({{"Discipline", "High"}, {"Productivity", "High"}}, {70.0})};