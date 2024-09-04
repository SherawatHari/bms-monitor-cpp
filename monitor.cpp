#include "./monitor.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;
using std::string;

string checkTemperature(float temperature) {
    if (temperature > 102 || temperature < 95)
       return "Temperature is critical!\n";
    else
       return "";
}

string checkPulseRate(float pulseRate) {
    if (pulseRate < 60 || pulseRate > 100)
       return "Pulse Rate is out of range!\n";
    else
       return "";
}

string checkSpo2(float spo2) {
    if (spo2 < 90)
       return "Oxygen Saturation out of range!\n";
    else
       return "";
}

int vitalsOk(float temperature, float pulseRate, float spo2, int warningDuration) {
    string warningMessage;

    warningMessage += checkTemperature(temperature);
    warningMessage += checkPulseRate(pulseRate);
    warningMessage += checkSpo2(spo2);

    if (!warningMessage.empty()) {
        cout << warningMessage << "\n";
        for (int i = 0; i < warningDuration; i++) {
            cout << "\r* " << flush;
            sleep_for(seconds(1));
            cout << "\r *" << flush;
            sleep_for(seconds(1));
        }
        return 0;
    }
    return 1;
}
