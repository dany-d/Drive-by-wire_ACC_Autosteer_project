function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rs"] = {file: "N:\\eecs461_project_workspace\\dany\\Project_Files\\Final_project_mbd_rtw\\path_data.c",
	size: 1643};
	 this.metricsArray.fcn["Lead_car_find_Outputs_wrapper"] = {file: "N:\\eecs461_project_workspace\\dany\\Project_Files\\Final_project_mbd_rtw\\Lead_car_find_wrapper.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["VD_equation_Outputs_wrapper"] = {file: "N:\\eecs461_project_workspace\\dany\\Project_Files\\Final_project_mbd_rtw\\VD_equation_wrapper.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["cos"] = {file: "C:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sin"] = {file: "C:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["vehicle_dynamics_Outputs_wrapper"] = {file: "N:\\eecs461_project_workspace\\dany\\Project_Files\\Final_project_mbd_rtw\\vehicle_dynamics_wrapper.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="Final_project_metrics.html">Global Memory: 1643(bytes) Maximum Stack: 8(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
