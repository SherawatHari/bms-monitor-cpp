#ifndef TEMPERATURECHECK_H_  // Include guard
#define TEMPERATURECHECK_H_

#include <string>
#include "VitalCheck.h"

class TemperatureCheck : public VitalCheck {
 public:
    explicit TemperatureCheck(float temp);  // explicit constructor for single argument
    std::string check() override;

 private:
    float temperature_;
};

#endif  // TEMPERATURECHECK_H_
