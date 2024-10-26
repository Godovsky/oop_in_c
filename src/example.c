#include <stdio.h>

#include <point.h>
#include <rectangle.h>

int main (int argc, char * argv[])
{
	POINT Point = point_constructor (1, 2);
	RECTANGLE Rectangle = rectangle_constructor (3, 4, 5, 6);
	RECTANGLE Rectangle2 = rectangle_constructor (10, 10, 10, 10);
	
	if (NULL == Point || NULL == Rectangle) return 1;

	printf ("Point: x = %d, y = %d\n",
			Point->get_x(Point),
			Point->get_y(Point));
	
	Point->set_x(Point, 100);
	Point->set_y(Point, 200);
	printf ("Point: x = %d, y = %d\n\n",
			Point->get_x(Point),
			Point->get_y(Point));

	printf ("Rectangle: w = %d, h = %d, x = %d, y = %d\n",
			Rectangle->get_w(Rectangle),
			Rectangle->get_h(Rectangle),
			Rectangle->get_x(Rectangle),
			Rectangle->get_y(Rectangle));
	
	Rectangle->set_w(Rectangle, 9);
	Rectangle->set_h(Rectangle, 8);		
	Rectangle->set_x(Rectangle, 10);
	Rectangle->set_y(Rectangle, 20);
	printf ("Rectangle: w = %d, h = %d, x = %d, y = %d, area = %d\n\n",
			Rectangle->get_w(Rectangle),
			Rectangle->get_h(Rectangle),
			Rectangle->get_x(Rectangle),
			Rectangle->get_y(Rectangle),
			Rectangle->get_area(Rectangle));

	printf ("Rectangle2: w = %d, h = %d, x = %d, y = %d\n",
			Rectangle2->get_w(Rectangle2),
			Rectangle2->get_h(Rectangle2),
			Rectangle2->get_x(Rectangle2),
			Rectangle2->get_y(Rectangle2));

	Rectangle2->set_w(Rectangle2, 20);
	Rectangle2->set_h(Rectangle2, 20);		
	Rectangle2->set_x(Rectangle2, 20);
	Rectangle2->set_y(Rectangle2, 20);
	printf ("Rectangle2: w = %d, h = %d, x = %d, y = %d, area = %d\n",
			Rectangle2->get_w(Rectangle2),
			Rectangle2->get_h(Rectangle2),
			Rectangle2->get_x(Rectangle2),
			Rectangle2->get_y(Rectangle2),
			Rectangle2->get_area(Rectangle2));

	point_deconstructor (Point);
	rectangle_deconstructor (Rectangle);
	rectangle_deconstructor (Rectangle2);

	printf ("\nPress [Enter] to quit...");
	while (getchar () != '\n');
	
	return 0;
}
