#include "PIDController.h"

PIDController::PIDController(float t, float p, float i, float d) {
    target = t;
    kp = p;
    ki = i;
    kd = d;
    previousError = 0.0f;
    integral = 0.0f;
}

float PIDController::calculate(float& current) {
    float error = target - current;
    integral += error;
    float derivative = error - previousError;
    previousError = error;
    return (kp * error) + (ki * integral) + (kd * derivative);
}