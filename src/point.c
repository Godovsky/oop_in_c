#include <stdlib.h>

#include <point.h>

struct P
{
	/* Public */
	int (*get_x) (POINT);
	int (*get_y) (POINT);
	void (*set_x) (POINT,int);
	void (*set_y) (POINT,int);

	/* Private */
	int x;
	int y;
};

static int get_x (POINT p)
{
	return ((struct P *)p)->x;
}

static int get_y (POINT p)
{
	return ((struct P *)p)->y;
}

static void set_x (POINT p, int x)
{
	((struct P *)p)->x = x;
}

static void set_y (POINT p, int y)
{
	((struct P *)p)->y = y;
}

POINT point_constructor (int x, int y)
{
	POINT p = malloc (sizeof(struct P));
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