#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>

#include "./VitalCheck.h"
#include "./TemperatureCheck.h"
#include "./PulseRateCheck.h"
#include "./Spo2Check.h"
#include "./BloodPressureCheck.h"

using std::cout;
using std::string;
using std::vector;
using std::unique_ptr;

void displayWarning(const std::string& message, int warningDuration) {
    if (!message.empty()) {
        cout << message << "\n";  // Print warning message
        for (int i = 0; i < warningDuration; ++i) {
            cout << "\r* " << std::flush;  // Print * for visual warning
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "\r *" << std::flush;  // Print * for visual warning
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

int vitalsOk(const vector<unique_ptr<VitalCheck>>& checks, int warningDuration) {
    string warningMessage;

    for (const auto& check : checks) {
        warningMessage += check->check();  // Accumulate messages from each check
    }

    displayWarning(warningMessage, warningDuration);  // Delegate message handling

    return warningMessage.empty() ? 1 : 0;  // Return 1 if all vitals are OK, else 0
}

int main() {
    vector<unique_ptr<VitalCheck>> checks;
    checks.emplace_back(new TemperatureCheck(103));  // Example values
    checks.emplace_back(new PulseRateCheck(110));
    checks.emplace_back(new Spo2Check(85));
    checks.emplace_back(new BloodPressureCheck(130, 85));

    vitalsOk(checks, 5);  // Check vitals with warning duration of 5 seconds

    return 0;
}
