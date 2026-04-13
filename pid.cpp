#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class PIDController {
    public:
        float target;
        float kp;
        float ki;
        float kd;
        float previousError;
        float integral;


        PIDController(float t, float p, float i, float d) {
            target = t;
            kp = p;
            ki = i;
            kd = d;
            previousError = 0.0f;
            integral = 0.0f;
        }


        float calculate(float& current) {
            float error = target - current;
            integral += error;
            float derivative = error - previousError;
            previousError = error;
            return (kp * error) + (ki * integral) + (kd * derivative);

        }
    };


 int main() {

        PIDController pid(72.0f, 0.5f, 0.1f, 0.05f);
        float current = 60.0f;


        for (int i = 0; i < 20; i++) {
            float output = pid.calculate(current);
            current += output;
            cout << fixed << setprecision(2)
            <<"Step " << i +1 << " | Current: " << current << " | Target: " << pid.target << " | Output: " << output << "\n";
        }


        }
