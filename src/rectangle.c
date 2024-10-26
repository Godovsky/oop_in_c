#include <stdlib.h>

#include <point.h>
#include <rectangle.h>

struct R
{
	/* Public */
	void (*set_w) (RECTANGLE, WIDTH);
	void (*set_h) (RECTANGLE, HEIGHT);
	int (*get_w) (RECTANGLE);
	int (*get_h) (RECTANGLE);

	void (*set_x) (RECTANGLE, X_COORDINATE);
	void (*set_y) (RECTANGLE, Y_COORDINATE);
	int (*get_x) (RECTANGLE);
	int (*get_y) (RECTANGLE);

	int (*get_area) (RECTANGLE);

	/* Private */
	POINT Point;

	int w;
	int h;
};

static int get_w (RECTANGLE r)
{
	return ((struct R *)r)->w;
}

static int get_h (RECTANGLE r)
{
	return ((struct R *)r)->h;
}

static void set_w (RECTANGLE r, WIDTH w)
{
	((struct R *)r)->w = w;
}

static void set_h (RECTANGLE r, HEIGHT h)
{
	((struct R *)r)->h = h;
}

static int get_x (RECTANGLE r)
{
	return ((struct R *)r)->Point->get_x(((struct R *)r)->Point);
}

static int get_y (RECTANGLE r)
{
	return ((struct R *)r)->Point->get_y(((struct R *)r)->Point);
}

static void set_x (RECTANGLE r, X_COORDINATE x)
{
	((struct R *)r)->Point->set_x(((struct R *)r)->Point, x);
}

static void set_y (RECTANGLE r, Y_COORDINATE y)
{
	((struct R *)r)->Point->set_y(((struct R *)r)->Point, y);
}

static int get_area (RECTANGLE r)
{
	return ((struct R *)r)->w * ((struct R *)r)->h;
}

RECTANGLE rectangle_constructor (WIDTH w, HEIGHT h, X_COORDINATE x, Y_COORDINATE y)
{
	RECTANGLE r = malloc (sizeof(struct R));
	if (r)
	{
		((struct R *)r)->Point = point_constructor (x, y);
		if (((struct R *)r)->Point)
		{
			r->set_w = set_w;
			r->set_h = set_h;
			r->get_w = get_w;
			r->get_h = get_h;

			r->set_w(r, w);
			r->set_h(r, h);

			r->get_area = get_area;

			r->set_x = set_x;
			r->set_y = set_y;
			r->get_x = get_x;
			r->get_y = get_y;

			r->set_x(r, x);
			r->set_y(r, y);
		}
		else free (r);
	}
	return r;
}

void rectangle_deconstructor (RECTANGLE r)
{
	if (r)
	{
		if (((struct R *)r)->Point) free (((struct R *)r)->Point);
		free (r);
	}
}