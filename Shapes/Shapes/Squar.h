#pragma once
#include "Shape.h"
class Squar :
	public Shape
{
private:
	dots A, B, C, D;
	float dest(dots A, dots B);
	float angle(dots A, dots B, dots C);
public:
	Squar(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy);
	~Squar();
	float perimetr();
	float square();
	void rotation();
	bool correct();
};

