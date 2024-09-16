#include <gtest/gtest.h>
#include "TemperatureCheck.h"
#include "PulseRateCheck.h"
#include "Spo2Check.h"
#include "BloodPressureCheck.h"

// Test fixture for vital checks
class VitalCheckTest : public ::testing::Test {
 protected:
    float normalTemp = 98.6;
    float highTemp = 103;
    float lowTemp = 94;

    float normalPulse = 75;
    float highPulse = 110;
    float lowPulse = 55;

    float normalSpo2 = 95;
    float lowSpo2 = 85;

    float normalSystolic = 110;
    float highSystolic = 130;
    float lowSystolic = 85;

    float normalDiastolic = 70;
    float highDiastolic = 90;
    float lowDiastolic = 50;
};

// Test for TemperatureCheck
TEST_F(VitalCheckTest, TemperatureCheck_CriticalHigh) {
    TemperatureCheck tempCheck(highTemp);
    EXPECT_EQ(tempCheck.check(), "Temperature is too high!\n");
}

TEST_F(VitalCheckTest, TemperatureCheck_CriticalLow) {
    TemperatureCheck tempCheck(lowTemp);
    EXPECT_EQ(tempCheck.check(), "Temperature is too low!\n");
}

TEST_F(VitalCheckTest, TemperatureCheck_Normal) {
    TemperatureCheck tempCheck(normalTemp);
    EXPECT_EQ(tempCheck.check(), "");
}

// Test for PulseRateCheck
TEST_F(VitalCheckTest, PulseRateCheck_CriticalHigh) {
    PulseRateCheck pulseCheck(highPulse);
    EXPECT_EQ(pulseCheck.check(), "Pulse Rate is too high!\n");
}

TEST_F(VitalCheckTest, PulseRateCheck_CriticalLow) {
    PulseRateCheck pulseCheck(lowPulse);
    EXPECT_EQ(pulseCheck.check(), "Pulse Rate is too low!\n");
}

TEST_F(VitalCheckTest, PulseRateCheck_Normal) {
    PulseRateCheck pulseCheck(normalPulse);
    EXPECT_EQ(pulseCheck.check(), "");
}

// Test for Spo2Check
TEST_F(VitalCheckTest, Spo2Check_CriticalLow) {
    Spo2Check spo2Check(lowSpo2);
    EXPECT_EQ(spo2Check.check(), "Oxygen Saturation is too low!\n");
}

TEST_F(VitalCheckTest, Spo2Check_Normal) {
    Spo2Check spo2Check(normalSpo2);
    EXPECT_EQ(spo2Check.check(), "");
}

// Test for BloodPressureCheck
TEST_F(VitalCheckTest, BloodPressureCheck_CriticalHighSystolic) {
    BloodPressureCheck bpCheck(highSystolic, normalDiastolic);
    EXPECT_EQ(bpCheck.check(), "Systolic Blood Pressure is too high!\n");
}

TEST_F(VitalCheckTest, BloodPressureCheck_CriticalLowSystolic) {
    BloodPressureCheck bpCheck(lowSystolic, normalDiastolic);
    EXPECT_EQ(bpCheck.check(), "Systolic Blood Pressure is too low!\n");
}

TEST_F(VitalCheckTest, BloodPressureCheck_CriticalHighDiastolic) {
    BloodPressureCheck bpCheck(normalSystolic, highDiastolic);
    EXPECT_EQ(bpCheck.check(), "Diastolic Blood Pressure is too high!\n");
}

TEST_F(VitalCheckTest, BloodPressureCheck_CriticalLowDiastolic) {
    BloodPressureCheck bpCheck(normalSystolic, lowDiastolic);
    EXPECT_EQ(bpCheck.check(), "Diastolic Blood Pressure is too low!\n");
}

TEST_F(VitalCheckTest, BloodPressureCheck_Normal) {
    BloodPressureCheck bpCheck(normalSystolic, normalDiastolic);
    EXPECT_EQ(bpCheck.check(), "");
}
