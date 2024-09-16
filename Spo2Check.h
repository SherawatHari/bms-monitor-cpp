#ifndef SPO2CHECK_H_
#define SPO2CHECK_H_

#include <string>
#include "VitalCheck.h"

class Spo2Check : public VitalCheck {
 public:
    explicit Spo2Check(float spo2);
    std::string check() override;

 private:
    float spo2_;
};

#endif  // SPO2CHECK_H_
