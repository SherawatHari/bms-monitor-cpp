#ifndef PULSERATECHECK_H_
#define PULSERATECHECK_H_

#include <string>
#include "VitalCheck.h"

class PulseRateCheck : public VitalCheck {
 public:
    explicit PulseRateCheck(float pulse);
    std::string check() override;

 private:
    float pulseRate_;
};

#endif  // PULSERATECHECK_H_
