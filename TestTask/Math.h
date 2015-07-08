
#include <math.h>
#include <afx.h>

namespace walter
{
	double length(CPoint vec);

	double scalar_multiplication(CPoint first, CPoint second);

	CPoint const_multiplication(CPoint vec, double value);

	void normalize(CPoint & vec);
}