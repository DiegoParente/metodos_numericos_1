#include "seidel.h"

seidel::seidel(int order){
	this->order =  order;
	this->A = (double **) calloc(order, sizeof(double*));
	for(int i=0; i<order; i++) this->A[i] = (double*) calloc(order, sizeof(double));
	this->b = (double*) calloc(order, sizeof(double));		
}
seidel::seidel(int order, double **A, double *b){
	this->order = order;
	this->A = A;
	this->b = b;
}

void seidel::solve(double precision, int itermax, std::vector<x_k*> *report){
	double *x = (double*) calloc(this->order, sizeof(double));
	double *v = (double*) calloc(this->order, sizeof(double));

	for(int i=0; i<this->order; i++){
		double r = 1/this->A[i][i];//Esse passo admite que a matriz n possui nenhum elemento nulo na diagonal
		for(int j=0; j<this->order; j++){
			if(i!=j) this->A[i][j] *= r; 
		}
		this->b[i]*=r;
		x[i] = this->b[i];
	}

	int k = 0;
	while(true){
		k++;
		for(int i=0; i<this->order; i++){
			double sum=0;
			for(int j=0; j<this->order; j++){
				if(i!=j) sum+= (this->A[i][j]*x[j]);
			}
			v[i] = x[i];
			x[i] = this->b[i] - sum;
		}
		double norm = this->norm(v, x);
		x_k *rel = (x_k *) malloc(sizeof(x_k));
		rel->n = this->order;
		rel->iter = k;
		rel->x = (double*) calloc(this->order, sizeof(double));
		for(int i=0; i<this->order; i++) rel->x[i] = x[i];
		rel->norm = norm;
		report->push_back(rel);
		if(norm <= precision || k >= itermax) break;
	}
}

double seidel::norm(double *x, double *v){
	double nn=0, nd=0;
	for(int i=0; i<this->order; i++){
		double t = fabs(v[i] - x[i]);
		if(t>nn) nn =t;
		if(fabs(v[i]) > nd) nd=fabs(v[i]);
		x[i] = v[i];
	}
	return nn/nd;
}	