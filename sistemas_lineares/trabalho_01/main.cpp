#include <iostream>
#include "./linear_system.h"
#include <cstring>
#include <string>

using namespace std;


int main(){
	int i=0;
	while(i<4){
 		double **A, *B;
		A = (double **)calloc(3, sizeof(double*));
		B = (double*) calloc(3, sizeof(double));
		for(int i=0; i<3; i++) A[i] = (double *) calloc(3, sizeof(double));
		A[0][0]= 3 ;A[0][1]= 2 ;A[0][2]= 4 ; B[0]=1;
		A[1][0]= 1 ;A[1][1]= 1 ;A[1][2]= 2 ; B[1]=2;
		A[2][0]= 4 ;A[2][1]= 3 ;A[2][2]= -2 ; B[2]=3;
		linear_system *ls = new linear_system(3, 3, A, B);
		string method = i==0?"LU":(i==1?"gauss":(i==2?"gauss-jordan":"gauss with partial pivoting"));
		B = ls->solve(method);
		cout << method<< ": " <<endl << B[0] << " " << B[1] << " " << B[2] <<endl;
		i++;
	}
}


