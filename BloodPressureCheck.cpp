#include "BloodPressureCheck.h"

std::string BloodPressureCheck::checkSystolic() const {
    if (systolic_ > 120) return "Systolic Blood Pressure is too high!\n";
    if (systolic_ < 90) return "Systolic Blood Pressure is too low!\n";
    return "";  // Normal range
}

std::string BloodPressureCheck::checkDiastolic() const {
    if (diastolic_ > 80) return "Diastolic Blood Pressure is too high!\n";
    if (diastolic_ < 60) return "Diastolic Blood Pressure is too low!\n";
    return "";  // Normal range
}

BloodPressureCheck::BloodPressureCheck(float systolic, float diastolic)
    : systolic_(systolic), diastolic_(diastolic) {}

std::string BloodPressureCheck::check() {
    std::string result;
    result += checkSystolic();  // Delegate systolic check
    result += checkDiastolic();  // Delegate diastolic check
    return result;
}
