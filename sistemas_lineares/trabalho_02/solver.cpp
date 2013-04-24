#include "./solver.h"

solver::solver(unsigned int rows, unsigned int columns){
	this->rows = rows;
	this->columns = columns;
	A = (double**) calloc(rows, sizeof(double*));
	for(int i=0; i<rows; i++) A[i] = (double*) calloc(columns, sizeof(double));
	B = (double*) calloc(rows, sizeof(double));
}
solver::solver(unsigned int rows,unsigned int columns, double **A, double *B){
	this->rows = rows;
	this->columns = columns;
	this->A = A;
	this->B = B;
}
report_data *solver::solve(string method, double e, unsigned int itermax){
	if(method == "jacobi") return this->gauss_jacobi(e, itermax);
	if(method == "seidel") return this->gauss_seidel(e, itermax);
	return NULL;
}

void solver::set_value(unsigned int row,unsigned int column, double value){
	A[row][column] = value;
}

double solver::get_value(unsigned int row, unsigned int column){
	return A[row][column];
}

report_data *solver::gauss_jacobi(double e, unsigned int itermax){
	double *X = (double *) calloc(this->rows, sizeof(double));
	double *V = (double *) calloc(this->rows, sizeof(double));

	for(int i=0; i<this->rows; i++){
		double r =  1/this->A[i][i];
		for(int j=0; j<this->columns; j++){
			if(i!= j) 
				this->A[i][j]*=r;
		}
		this->B[i]*=r;
		X[i] = this->B[i];
	}
	unsigned int counter = 0;
	while(true){
		counter++;
		for(int i=0; i<this->rows; i++){
			double sum=0;
			for(int j=0; j<this->columns; j++){
				if(i!=j)
					sum+=(this->A[i][j]*X[j]);
			}
			V[i] = this->B[i] - sum;
		}
		double norm = this->norm(X, V);
		if(norm<=e || counter >= itermax)
			break;
	}
	report_data *results = (report_data*) malloc(sizeof(report_data));
	results->X = X;
	results->n = this->columns;
	results->iter = counter;
	return results;
}

report_data *solver::gauss_seidel(double e, unsigned int itermax){
	double *X = (double *) calloc(this->rows, sizeof(double));
	double *V = (double *) calloc(this->rows, sizeof(double));

	for(int i=0; i<this->rows; i++){
		double r =  1/this->A[i][i];
		for(int j=0; j<this->columns; j++){
			if(i!= j) 
				this->A[i][j]*=r;
		}
		this->B[i]*=r;
		X[i] = this->B[i];
	}
	unsigned int counter = 0;
	while(true){
		counter++;
		for(int i=0; i<this->rows; i++){
			double sum=0;
			for(int j=0; j<this->columns; j++){
				if(i!=j)
					sum+=(this->A[i][j]*X[j]);
			}
			V[i] = X[i];
			X[i] = this->B[i] - sum;
		}
		double norm = this->norm(V, X);
		if(norm<=e || counter >= itermax)
			break;
	}
	report_data *results = (report_data*) malloc(sizeof(report_data));
	results->X = X;
	results->n = this->columns;
	results->iter = counter;
	return results;
}

double solver::norm(double *X, double *V){
	double nn = 0, nd =0;
	for(int i=0; i<this->columns; i++){
		double t =  fabs(V[i] - X[i]);
		if(t>nn) nn = t;
		if(fabs(V[i]) > nd) nd = fabs(V[i]);
		X[i] = V[i];
	}
	return nn/nd;
}

double solver::get_b_value(unsigned int index){
	return this->B[index];
}
	
void solver::set_b_value(unsigned int index, double value){
	this->B[index] = value;
}

unsigned int solver::get_rows(){
	return this->rows;
}
unsigned int solver::get_columns(){
	return this->columns;
}