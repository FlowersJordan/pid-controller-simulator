# PID Controller Simulator

A command-line PID (Proportional-Integral-Derivative) controller simulator written in C++.

## What is a PID Controller?

A PID controller is an algorithm used in embedded systems to reach and maintain a target value smoothly. Think of a thermostat — when the room is cold it blasts heat, but as it approaches the target temperature it slows down to avoid overshooting. PID is the algorithm that makes that happen.

It is used in:
- Thermostats and HVAC systems
- Drone flight stabilization
- Motor speed controllers
- Cruise control in vehicles
- Industrial automation

## How It Works

The algorithm calculates correction using three terms:
- **P (Proportional)** — reacts to the current error
- **I (Integral)** — accounts for how long the error has persisted
- **D (Derivative)** — reacts to how fast the error is changing

Combined they produce smooth convergence to the target value.

## How To Compile and Run

```bash
g++ pid.cpp -o pid
./pid
```

## Sample Output
Step 1  | Current: 67.80 | Target: 72.00 | Output: 7.80
Step 2  | Current: 71.13 | Target: 72.00 | Output: 3.33
Step 3  | Current: 73.11 | Target: 72.00 | Output: 1.98
...
Step 20 | Current: 72.01 | Target: 72.00 | Output: -0.02


The simulator overshoots slightly before correcting and converging — this is normal PID behavior called dampening.

## Gains Used

| Gain | Value | Role |
|------|-------|------|
| Kp | 0.5 | Proportional response strength |
| Ki | 0.1 | Integral accumulation rate |
| Kd | 0.05 | Derivative dampening strength |

## Built With
- C++
- Concepts: OOP, references, file I/O, simulation loops