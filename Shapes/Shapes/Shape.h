#pragma once
#include <math.h>
struct dots
{
	float x;
	float y;
};

class Shape
{
public:
	Shape();
	~Shape();
	virtual float perimetr();
	virtual float square();
	virtual void rotation();
	virtual bool correct();
};

