#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
#include "PIDController.h"


 int main() {

        PIDController pid(72.0f, 0.5f, 0.1f, 0.05f);
        float current = 60.0f;

        ofstream outFile("pid_output.csv");
        outFile << "Step,Current,Target,Output\n";
        for (int i = 0; i < 20; i++) {
            float output = pid.calculate(current);
            current += output;
            cout << fixed << setprecision(2)
            <<"Step " << i +1 << " | Current: " << current << " | Target: " << pid.target << " | Output: " << output << "\n";
            outFile << i + 1 << "," << current << "," << pid.target << "," << output << "\n";
        }
        outFile.close();
        cout << "PID simulation completed. Output saved to pid_output.csv\n";


        }
