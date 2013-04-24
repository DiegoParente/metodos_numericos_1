#ifndef SOLVER_H
#define SOLVER_H
#include <string>
#include <exception>
#include <cfloat>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

typedef struct{
	double *X;
	unsigned int n;
	unsigned int iter;
}report_data;


class solver{

public:
	solver(unsigned int rows, unsigned int columns);
	solver(unsigned int rows,unsigned int columns, double **A, double *B);
	report_data *solve(string method, double e, unsigned int itermax);//Retorna o vetor com os valores de x
	void set_value(unsigned int row,unsigned int column, double value);
	double get_value(unsigned int row, unsigned int column);
	double get_b_value(unsigned int index);
	void set_b_value(unsigned int index, double value);
	unsigned int get_rows();
	unsigned int get_columns();

private:
	double **A, *B;
	unsigned int rows, columns;
	report_data *gauss_jacobi(double e, unsigned int itermax);
	report_data *gauss_seidel(double e, unsigned int itermax);
	double norm(double *X, double *V);
};

#endif