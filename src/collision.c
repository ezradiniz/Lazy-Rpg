#include "collision.h"

int hasCollision(int x1, int y1, int w1, int h1,
				int x2, int y2, int w2, int h2)
{	

	return !(x2> (x1 + w1) ||
			(x2 + w2) < x1 ||
			y2 > (y1 + h1) ||
			(y2 + h2) < y1);
}
