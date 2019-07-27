% 
% 
u = 16; % Vehicle speed in m/s
L = 1.6; % Wheelbase in m
Ksa = 100; % Self-aligning torque constant, Nmm-s/m-rad
R = 1/5; % Haptic-to vehicle steering angle gain
Tmax = 5; % Simulation time
tau = 0.0001; % Approximate derivative time constant

% Haptic wheel identified parameters see Bo Sys ID
% b = 1.2; %Nmm-s/rad 0.0012 Nms/rad
% J = 0.683; %Nmm-s^2
% k = 0.0097; %Nmm/s
% % 
% %Cascade PD Implementation:
% 
% wn = 10;
% zeta = .7;
% Kp = 0.625;0
00% Kd = 0.0875;
% 
% sim('LinearVehicle_PD');
% 
% 
% figure(1)
% 
% 
% plot(tout,yout)
% xlabel('time, seconds')
% % % 
% %Alternative PD Implementation:
% Kp = 0.625;
% Kd_Alt = 0.14;
% 
% sim('LinearVehicle_AltPD');
% hold on 
% grid on 
% 
% plot(tout,yout)
% xlabel('time, seconds')
% legend('Cascade PD', 'Alternative PD')
% 
% hold off
% 
% % Haptic box cascade PD controller
% wn = 30.0;
% zeta = .7;
% Kpm = 1473.5;
% Kdm = 137.43;
% 
% sim('HapticBox_PD');
% 
% 
% figure(2)
% 
% 
% 
% plot(tout,yout)
% xlabel('time, seconds')
% title(['Step response, Haptic Box'])
% 
% % Haptic box alternative PD controller
% wn = 30;
% zeta = 0.7;
% Kpm = 1473.5;
% Kdm_Alt = 0.0933;
% sim('HapticBox_AltPD');
% hold on
% grid on
% 
% 
% 
% plot(tout,yout)
% xlabel('time, seconds')
% legend('Cascade PD', 'Alternative PD')
% 
% 
% hold off
% % Linear Vehicle plus Haptic Box
% 
% % Kp = 0.625;
% % Kd = 0.0875;
% % Kpm = 1473.5;
% % Kdm = 137.43;
% 
% Kp = 2.925;
% Kd = 0.2775;
% Kpm = 1573.5;
% Kdm = 190;
% 
% 
% sim('LinearVehiclePlusHaptic');
% 
% 
% figure(3)
% 
% 
% plot(tout,yout)
% xlabel('time, seconds')
% title(['Road Angle Input Step Response'])
% 
% 



