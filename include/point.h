#ifndef POINT_H
#define POINT_H

typedef struct Point * POINT;

struct Point
{
	int	(*get_x) (POINT);
	int (*get_y) (POINT);
	void (*set_x) (POINT, int);
	void (*set_y) (POINT, int);
};

POINT point_constructor (int, int);
void point_deconstructor (POINT);

#endif
