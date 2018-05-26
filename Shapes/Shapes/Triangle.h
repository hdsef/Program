#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
private:
	dots A, B, C;
	float dest(dots A, dots B);
public:
	Triangle(float Ax, float Ay, float Bx, float By, float Cx, float Cy);
	~Triangle();
	float perimetr();
	float square();
	void rotation();
	bool correct();
};

