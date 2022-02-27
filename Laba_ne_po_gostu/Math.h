#pragma once
#ifndef _MATH_H_
#define _MATH_H_


class Math
{
public:
	Math();
	~Math();
	void Find();
	double NewtonsMethod(double x, double eps);
	double SecantMethod(double x0, double x1, double eps);
	double DichotomyMethod(double x0, double x1, double eps);
	double IterationMethod(double x, double eps);
	void FindPoints();

private:
	double Xmin;
	double Xmax;
	double h;
};

#endif // !MATH_H

