#include "Triangle.h"


Triangle::Triangle(float Ax,float Ay,float Bx,float By,float Cx,float Cy)
{
	A.x = Ax;
	A.y = Ay;
	B.x = Bx;
	B.y = By;
	C.x = Cx;
	C.y = Cy;
}


Triangle::~Triangle()
{
}

float Triangle::dest(dots A, dots B) {
	return(sqrt((B.x - A.x)*(B.x - A.x) + (B.y - B.x)*(B.y - B.x)));
}

float Triangle::perimetr() {
	return (dest(A,B)+dest(B,C)+dest(C,A));
}

float Triangle::square() {
	float p = perimetr()/2;
	return (sqrt(p*(p - dest(A, B))*(p - dest(B, C))*(p - dest(C, A))));
}

bool Triangle::correct() {
	if (dest(A, B) + dest(B, C) > dest(C, A) && dest(B, C) + dest(C, A) > dest(A, B) && dest(C, A) + dest(A, B) > dest(B, C))
		return 1;
	else
		return 0;
}

void Triangle::rotation() {
}
