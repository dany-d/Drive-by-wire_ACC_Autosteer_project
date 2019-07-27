%
% This file initializes all paramters for ACCLogic_Test.mdl
%

clear               % Clear Workspace
clc                 % Clear Command Window

testcase = 2;

% Parameters
TIMESTEP = 0.01;
H = 10;
u_offset = 0;       % Not Required

% Manual Mode Switching
ManEnt1 = 10;       % Enable Manual
ManEnt2 = 15;       % Disable Manual
ManEnt3 = 20;       % Enable Manual
ManEnt4 = 25;       % Disable Manual

% Location of This Car
MyCarVel_us = 3;
MyCarMan_us = 6;

% Locations of Cars 1 - 5
Car1_start_s = 30;
Car1_us = 0;
Car2_start_s = 47;
Car2_us = 1;
Car3_start_s = 25;
Car3_us = 0.25;
Car4_start_s = 35;
Car4_us = 0.5;
Car5_start_s = 75;
Car5_us = 0;
Car6_start_s = 30;
Car6_us = 0.2;

