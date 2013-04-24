#ifndef SEIDEL_H
#define SEIDEL_H
#include <vector>
#include <cmath>
#include <cstdlib>
#include "report.h"

class seidel{

public:
	double **A, *b;
	int order;
	seidel(int order);
	seidel(int order, double **A, double *b);
	void solve(double precision, int itermax, std::vector<x_k*> *report);
private:
	double norm(double *x, double *v);	
};

#endif