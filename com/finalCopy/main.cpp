#include "./SensorReceiver.h"
#include <iostream>

int main(){
    cout << "[MAIN TESTING PROGRAM]" << endl;
    SensorReceiver sensor = SensorReceiver();
    cout << sensor.getSwitch() << endl;
    return 0;
}