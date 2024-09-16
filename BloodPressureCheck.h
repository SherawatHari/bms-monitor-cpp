#ifndef BLOODPRESSURECHECK_H_
#define BLOODPRESSURECHECK_H_

#include <string>
#include "VitalCheck.h"

class BloodPressureCheck : public VitalCheck{
 private:
    float systolic_;
    float diastolic_;

    // Helper function to handle systolic pressure check
    std::string checkSystolic() const;
    // Helper function to handle diastolic pressure check
    std::string checkDiastolic() const;

 public:
    explicit BloodPressureCheck(float systolic, float diastolic);

    // Function to check blood pressure and return warning message
    std::string check() override;
};

#endif  // BLOODPRESSURECHECK_H_
