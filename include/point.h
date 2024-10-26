#ifndef POINT_H
#define POINT_H

typedef struct Point * POINT;

typedef int X_COORDINATE, Y_COORDINATE;

struct Point
{
	int	(*get_x) (POINT);
	int (*get_y) (POINT);
	void (*set_x) (POINT, X_COORDINATE);
	void (*set_y) (POINT, Y_COORDINATE);
};

POINT point_constructor (X_COORDINATE, Y_COORDINATE);
void point_deconstructor (POINT);

#endif
