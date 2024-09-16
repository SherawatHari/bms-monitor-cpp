#include "Spo2Check.h"

Spo2Check::Spo2Check(float spo2) : spo2_(spo2) {}

std::string Spo2Check::check() {
    if (spo2_ < 90) return "Oxygen Saturation is too low!\n";
    return "";
}
