#include "PulseRateCheck.h"

PulseRateCheck::PulseRateCheck(float pulse) : pulseRate_(pulse) {}

std::string PulseRateCheck::check() {
    if (pulseRate_ > 100) return "Pulse Rate is too high!\n";
    if (pulseRate_ < 60) return "Pulse Rate is too low!\n";
    return "";
}
