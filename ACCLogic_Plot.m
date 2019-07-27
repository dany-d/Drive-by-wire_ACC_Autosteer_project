%
% This file plots the data acquired from ACCState_TestCase.mdl
%

PLOT_MODE_BOUNDARY = 150;

figure(1)
h = area([t t t],PLOT_MODE_BOUNDARY.*[Position_Enable Velocity_Enable Manual_Enable]);
set(h(1),'FaceColor',[1 .9 .9]);
set(h(2),'FaceColor',[.9 1 .9]);
set(h(3),'FaceColor',[.9 .9 1]);
hold on
p = plot(t,MyCar_Pos,t,Car1_Pos,t,Car2_Pos,t,Car3_Pos,t,Car4_Pos,t,Car5_Pos,t,Car6_Pos);
set(p,'LineWidth',2);
xlabel('Time (Sec)');
ylabel('Position of Each Car (S Coordinate)');
title(['ACC Logic Test Output ' num2str(testcase)]);
legend('Position Mode','Velocity Mode','Manual Mode','This Car','Car1','Car2','Car3','Car4','Car5','Car6','Location','NorthWest');
hold off



