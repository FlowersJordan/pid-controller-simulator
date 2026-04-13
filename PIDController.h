#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class PIDController {
    public:
        float target;
        float kp;
        float ki;
        float kd;
        float previousError;
        float integral;


        PIDController(float t, float p, float i, float d);
        
        float calculate(float& current);
    };

#endif 