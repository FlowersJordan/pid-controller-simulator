#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "PIDController.h"


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
