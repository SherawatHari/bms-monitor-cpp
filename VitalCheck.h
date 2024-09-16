#ifndef VITALCHECK_H_  // Include guard
#define VITALCHECK_H_

#include <string>

class VitalCheck {
 public:
    virtual ~VitalCheck() = default;
    virtual std::string check() = 0;  // Pure virtual function for checking vitals
};

#endif  // VITALCHECK_H_
