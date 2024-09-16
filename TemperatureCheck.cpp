#include "TemperatureCheck.h"

TemperatureCheck::TemperatureCheck(float temp) : temperature_(temp) {}

std::string TemperatureCheck::check() {
    if (temperature_ > 102) return "Temperature is too high!\n";
    if (temperature_ < 95) return "Temperature is too low!\n";
    return "";
}
