#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <point.h>

typedef struct Rectangle * RECTANGLE;

typedef int WIDTH, HEIGHT;

struct Rectangle
{
	void (*set_w) (RECTANGLE, WIDTH);
	void (*set_h) (RECTANGLE, HEIGHT);
	int	(*get_w) (RECTANGLE);
	int (*get_h) (RECTANGLE);
	
	void (*set_x) (RECTANGLE, X_COORDINATE);
	void (*set_y) (RECTANGLE, Y_COORDINATE);
	int (*get_x) (RECTANGLE);
	int (*get_y) (RECTANGLE);

	int (*get_area) (RECTANGLE);
};

RECTANGLE rectangle_constructor (WIDTH, HEIGHT, X_COORDINATE, Y_COORDINATE);
void rectangle_deconstructor (RECTANGLE);

#endif
