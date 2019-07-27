/* path_data1.h */ 
#ifndef _PATH_DATA1_H_
#define _PATH_DATA1_H_

#define MAX_RS	31
/*#define MAX_RS  4*/
#define PATH_LENGTH	2.214926187885e+003

/*#define PATH_LENGTH 5.456637061435918e+002*/

enum rs_type { STRAIGHT=1, CONST_CURVE };

struct road_seg_type{
	enum rs_type type;
	double p;
	union {
		 struct {
			double length;
			double start[2];
			double stop[2];
			signed char junk;
		} straight;
		 struct {
			double r;
			double center[2];
			double ts;
			double te;
			signed char dir;
		} const_curve;
	} data;
};

#endif
