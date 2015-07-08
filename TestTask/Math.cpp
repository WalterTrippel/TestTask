#include "Math.h"
#include "stdafx.h"

namespace walter
{

	double length(CPoint vec)
	{
		return sqrt((double)(vec.x * vec.x + vec.y * vec.y));
	}

	double scalar_multiplication(CPoint first, CPoint second)
	{
		double res = first.x * second.x + first.y * second.y;
		return res;
	}

	CPoint const_multiplication(CPoint vec, double value)
	{
		return CPoint(vec.x * value, vec.y * value);
	}

	void normalize(CPoint & vec)
	{
#define shiftOnScroll 3
		double lngth = length(vec);
		vec = CPoint(shiftOnScroll * (vec.x / lngth), shiftOnScroll * (vec.y / lngth));
	}
}