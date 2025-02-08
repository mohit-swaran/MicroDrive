#include "motorDriver.h"

// Define three motors with unique pins
motor motor1(2, 3, 4, 5);
motor motor2(6, 7,8, 9);
motor motor3(10, 11, 12, 13);

void setup() {
    Serial.begin(115200);

    motor1.init(0);
    motor2.init(1);
    motor3.init(2);
    motor1.encoderTicksPerRevolution=1170;
    motor2.encoderTicksPerRevolution=1170;
    motor3.encoderTicksPerRevolution=1170;
    motor1.setPI(3.0, 35);
    motor2.setPI(3.0, 35);
    motor3.setPI(3.0, 35);

    Serial.println("Motors initialized.");
    delay(1000);
}

void loop() {
    motor1.setSpeed(-10);
    motor2.setSpeed(10);
    motor3.setSpeed(-10);
    
    motor1.updatePI();
    motor2.updatePI();
    motor3.updatePI();

    motor1.debug(DEBUG_SETPOINT | DEBUG_CONTROL | DEBUG_ERROR);
    delay(10);
}
