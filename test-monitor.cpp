#include "./monitor.h"

#include "gtest/gtest.h"

// Forward declarations of the functions from your code
std::string checkTemperature(float temperature);
std::string checkPulseRate(float pulseRate);
std::string checkSpo2(float spo2);
int vitalsOk(float temperature, float pulseRate, float spo2, int warningDuration);

// Test checkTemperature function
TEST(VitalSignsTest, CheckTemperature) {
    EXPECT_EQ(checkTemperature(103), "Temperature is critical!\n");      // Temp too high
    EXPECT_EQ(checkTemperature(94), "Temperature is critical!\n");       // Temp too low
    EXPECT_EQ(checkTemperature(98.6), "");                               // Normal temp
}

// Test checkPulseRate function
TEST(VitalSignsTest, CheckPulseRate) {
    EXPECT_EQ(checkPulseRate(101), "Pulse Rate is out of range!\n");     // Pulse too high
    EXPECT_EQ(checkPulseRate(59), "Pulse Rate is out of range!\n");      // Pulse too low
    EXPECT_EQ(checkPulseRate(75), "");                                   // Normal pulse
}

// Test checkSpo2 function
TEST(VitalSignsTest, CheckSpo2) {
    EXPECT_EQ(checkSpo2(89), "Oxygen Saturation out of range!\n");       // Spo2 too low
    EXPECT_EQ(checkSpo2(90), "");                                        // Spo2 boundary
    EXPECT_EQ(checkSpo2(95), "");                                        // Normal Spo2
}

// Test vitalsOk function for all normal vital signs
TEST(VitalSignsTest, VitalsOkNormal) {
    EXPECT_EQ(vitalsOk(98.6, 75, 95, 0), 1);                             // All vitals ok
}

// Test vitalsOk function when temperature is critical
TEST(VitalSignsTest, VitalsOkTemperatureCritical) {
    EXPECT_EQ(vitalsOk(103, 75, 95, 0), 0);                              // Temp critical
}

// Test vitalsOk function when pulse rate is critical
TEST(VitalSignsTest, VitalsOkPulseRateCritical) {
    EXPECT_EQ(vitalsOk(98.6, 101, 95, 0), 0);                            // Pulse critical
}

// Test vitalsOk function when oxygen saturation is critical
TEST(VitalSignsTest, VitalsOkSpo2Critical) {
    EXPECT_EQ(vitalsOk(98.6, 75, 89, 0), 0);                             // Spo2 critical
}

// Test vitalsOk function when multiple vitals are critical
TEST(VitalSignsTest, VitalsOkMultipleCritical) {
    EXPECT_EQ(vitalsOk(103, 101, 89, 0), 0);                             // Multiple critical
}
