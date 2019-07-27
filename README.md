# Drive-by-wire_ACC_Autosteer_project
*Steer-by-Wire, Adaptive Cruise Control (ACC) and Auto-steering controller design using NXP microcontroller 
- Simulated connected vehicle ecosystem over CAN bus, implementing ACC and auto-steering by shared vehicle position and velocity  
- Implemented ACC using Stateflow modelling to dynamically switch between position and velocity control.  Bicycle vehicle dynamics model used to estimate the trajectory; designed and tuned PD controller for Automatic Steering control to follow trajectory*

**Introduction**

The project objective is to develop and simulate a virtual car model for a connected vehicle ecosystem with adaptive cruise control (ACC) and automatic steering control. The major subsystems comprising the project are as follows:
- Vehicle Dynamics
- Adaptive Cruise Control
- Automatic Steering Control

The vehicle dynamics subsystem comprises of modeling the vehicle based on the bicycle model. This model enables us to estimate the trajectory of the vehicle motion when applying inputs such as steering direction through the haptic wheel and driving force inputs through the potentiometer manually or through the dip switches during cruise control.

The adapative cruise control (ACC) subsystem adds functionality in the form of velocity control or position control. When ACC is enabled through a dip switch, velocity control mode must be activated. The cruising speed for this mode is set through a set of dip switches. The switching from velocity mode to position mode and vice-versa is based on the distance of our vehicle from the leading car. This switching logic was implemented using stateflow. In case the ACC is disabled, the vehicle is controlled manually by the user.

Once the vehicle model and ACC system are implemented, automatic steering control is implemented using closed loop feedback control. The controllers must ensure that the vehicle follows the center-line trajectory by automatically steering the car through the actuation of haptic wheel. It also ensures that vehicle motion is stable with respect to overshoot and steady state error for all driving force inputs.

To simulate a connected vehicle ecosystem, the position and velocity of our vehicle in the global ecosystem is shared over the CAN bus to interact with other vehicles.

**Pick Lead Logic**

The ACC system governs the switching from velocity control to distance control mode and vice-versa. Since this switching was governed by the distance between our vehicle and closest vehicle ahead, we had to implement a Pick Lead Logic. This was done using Sfunction on Simulink. The S-function computes the distance of our vehicle with reference to all other vehicles. This was followed by iteratively checking (using if statement and for loop) all the computed distances to find the vehicle closest to our vehicle. During this process, all vehicles behind our base vehicle were discounted by checking that the computed distance was positive. Once the minimum distance and associated vehicle was found, its position and velocity were sent as outputs.

**Automatic Steering Controllers**

Developing an automatic steering vehicle required two closed loop feedback systems. Both these feedback loops were based on a PD controller. The outer control loop maintains the distance from the road centerline while the inner control loop maintains the haptic wheel angular position. The feedback for the outer control loop (actual vehicle position from centerline) was provided by the vehicle dynamics subsystem. The feedback for the inner control loop (haptic wheel position) was obtained from the encoder.

To determine the initial gain values for the controllers, we examined the transfer function for each of the two closed loop systems. On the basis of the given natural frequency and zeta, we analytically computed initial gain values for the controllers. The system was then simulated on MATLAB and it was observed that the step response had a large overshoot. This was reduced by adjusting the gain values until an improved step response was recorded. We implemented these tuned gains in the lab. However, we observed that the steering was sluggish in nature. To improve the speed of the response we increased the Kp for outer control loop. We then observed that the system response would overshoot and was oscillatory in nature. We minimized the oscillations by increasing the Kd value for the inner control loop. The issue was finally resolved by scaling down the effect of auto steering torque by 20.
