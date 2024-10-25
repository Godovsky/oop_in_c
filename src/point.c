#include <stdlib.h>

#include <point.h>

typedef struct
{
	/* Public */
	int (*get_x) (POINT);
	int (*get_y) (POINT);
	void (*set_x) (POINT,int);
	void (*set_y) (POINT,int);

	/* Private */
	int x;
	int y;
} _POINT, * p_POINT;

static int get_x (POINT p)
{
	return ((p_POINT)p)->x;
}

static int get_y (POINT p)
{
	return ((p_POINT)p)->y;
}

static void set_x (POINT p, int x)
{
	((p_POINT)p)->x = x;
}

static void set_y (POINT p, int y)
{
	((p_POINT)p)->y = y;
}

POINT point_constructor (int x, int y)
{
	POINT p = malloc (sizeof(_POINT));
	if (p)
	{
		p->get_x = get_x;
		p->get_y = get_y;
		p->set_x = set_x;
		p->set_y = set_y;
		p->set_x(p, x);
		p->set_y(p, y);
	}

	return p;
}

void point_deconstructor (POINT p)
{
	if (p) free (p);
}