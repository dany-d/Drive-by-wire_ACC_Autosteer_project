% MBD_S32K14_USER_COPY_REQUIRED_FILES Includes user specific files.
% MBD_S32K14_USER_COPY_REQUIRED_FILES includes user specific files needed for build.
% There may be instances where variables are used from code that is not part 
% of the model but are instead hand coded. In these instances, user specific 
% files will need to be included in the build directory created by toolbox.  
% The user can specify which files to include in the build directory by 
% modifying this file. 
% 
% This is a template that demonstrates how to include user specific files.
% 
% Copyright (c) 2006 Freescale Semiconductor, Inc.
% Copyright (c) 2017 NXP.
% All rights reserved.
function mbd_s32k14_user_copy_required_files(dest_dir)
    disp('### EECS461: user_copy_required_files')
    mysource_dir = pwd;
        % get all the c file names
    file_list = dir(fullfile(pwd, '*.c'));
    % copy them into the directory
    for i=1:length(file_list)
        mbd_s32k_copy(strcat(mysource_dir,filesep,file_list(i,1).name),...
            strcat(dest_dir,filesep, file_list(i,1).name),'f');
    end
%     mbd_s32k_copy(strcat(mysource_dir,filesep,'src.c'),strcat(dest_dir,filesep,'src.c'),'f');
%     mbd_s32k_copy(strcat(mysource_dir,filesep,'src.h'),strcat(dest_dir,filesep,'src.h'),'f');
end
