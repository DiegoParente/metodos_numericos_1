#include "./seidel.h"
#include <iostream>
using namespace std;

double **new_A(int order){
	double **A = (double**) calloc(order, sizeof(double*));
	for(int i=0; i<order; i++) A[i] = (double*) calloc(order, sizeof(double)); 
	return A;
}

double *new_b(int order){
	double *b = (double*) calloc(order, sizeof(double));
	return b;
}

int main(){
	int iv[3];
	iv[0] = 10;
	iv[1] = 50;
	iv[2] = 100;
	vector<x_k*> r1, r2, r3;
	int order = 3;
	for(int k=0; k<3; k++){
		double **A1, *b1;
		A1= new_A(order);
		b1 = new_b(order);
		A1[0][0]=9; 	A1[0][1]=3; 	A1[0][2]=1; 	b1[0]=13;
		A1[1][0]=2; 	A1[1][1]=5; 	A1[1][2]=-1; 	b1[1]=6;
		A1[2][0]=-6; 	A1[2][1]=0; 	A1[2][2]=8; 	b1[2]=2;
		seidel *s1 = new seidel(order,A1, b1);
		s1->solve(0.01, iv[k], &r1);
		x_k *result =  r1.back();
		cout<< "x1 =\n";
		for(int i=0; i<result->n; i++) cout << result->x[i] <<endl;
		cout<<"precision: 0.01| took " << result->iter << " iterations | norm = "<< result->norm <<endl;
		cout<<"itermax = "<<iv[k]<<endl;
		if(k==0){
			for(int i=0; i<r1.size(); i++) cout<<r1[i]->norm<<endl;
		}
		cout<<endl<<endl;
	}	


	for(int k=0; k<3; k++){
		double **A2, *b2;
		A2= new_A(order);
		b2= new_b(order);
		A2[0][0]=1; 	A2[0][1]=1; 	A2[0][2]=6; b2[0]=8;
		A2[1][0]=1; 	A2[1][1]=5; 	A2[1][2]=-1; b2[1]=5;
		A2[2][0]=4; 	A2[2][1]=2; 	A2[2][2]=-2; b2[2]=4;
		seidel *s2 = new seidel(order,A2, b2);
		s2->solve(0.01, iv[k], &r2);
		x_k *result2 = r2.back();
		cout<< "x2 =\n";
		for(int i=0; i<result2->n; i++) cout << result2->x[i] <<endl;
		cout<<"precision: 0.01| took " << result2->iter << " iterations | norm = "<< result2->norm <<endl;
		cout<<"itermax = "<<iv[k]<<endl;
		if(k==0){
			for(int i=0; i<r2.size(); i++) cout<<r2[i]->norm<<endl;
		}
		cout<<endl<<endl;
	}

	for(int k=0; k<3; k++){	
		double **A3, *b3;
		A3= new_A(order);
		b3= new_b(order);
		A3[0][0]=-3; 	A3[0][1]=4; 	A3[0][2]=5; 	b3[0]=6;
		A3[1][0]=-2; 	A3[1][1]=2; 	A3[1][2]=-3; 	b3[1]=-3;
		A3[2][0]=0; 	A3[2][1]=2; 	A3[2][2]=-1; 	b3[2]=1;
		seidel *s3 = new seidel(order,A3, b3);
		s3->solve(0.01, iv[k], &r3);
		x_k *result3 = r3.back();
		cout<< "x3 =\n";
		for(int i=0; i<result3->n; i++) cout << result3->x[i] <<endl;
		cout<<"precision: 0.01| took " << result3->iter << " iterations | norm = "<< result3->norm <<endl;
		cout<<"itermax = "<<iv[k]<<endl;
		if(k==0){
			for(int i=0; i<r3.size(); i++) cout<<r3[i]->norm<<endl;
		}
		cout<<endl<<endl;
	}	

	return 0;
}