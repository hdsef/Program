#include "Squar.h"


Squar::Squar(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy)
{
	A.x = Ax;
	A.y = Ay;
	B.x = Bx;
	B.y = By;
	C.x = Cx;
	C.y = Cy;
	D.x = Dx;
	D.y = Dy;
}


Squar::~Squar()
{
}

float Squar::angle(dots A, dots B, dots C) {
	return(((dest(A,C)*dest(A, C)- dest(A, B)*dest(A, B)- dest(B, C)*dest(B, C))/(-2*dest(A,B)*dest(B,C))));
}

float Squar::dest(dots A, dots B) {
	return(sqrt((B.x - A.x)*(B.x - A.x) + (B.y - B.x)*(B.y - B.x)));
}

float Squar::perimetr() {
	return (4 * dest(A, B));
}

float Squar::square() {
	return(dest(A, B)*dest(A, B));
}

bool Squar::correct() {
	if (dest(A, B) == dest(C, D) && dest(A, D) == dest(B, C) && angle(A, B, C) == angle(A, D, C))
		return 1;
	else
		return 0;
}

void Squar::rotation() {

}