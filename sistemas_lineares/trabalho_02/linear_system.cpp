#include "./linear_system.h"

linear_system::linear_system(unsigned int rows, unsigned int columns){
	B = (double *) calloc(columns, sizeof(double));
	A = (double **) calloc(rows, sizeof(double *));
	for(int i=0; i<rows; i++) A[i] = (double *) calloc(columns, sizeof(double));
	this->rows =  rows;
	this->columns =  columns;	
}

linear_system::linear_system(unsigned int rows, unsigned int columns, double **A, double *B){
	this->A = A;
	this->B = B;
	this->rows = rows;
	this->columns = columns;
}

unsigned int linear_system::get_rows_number(){
	return rows;
}

unsigned int linear_system::get_columns_number(){
	return columns;
}

double *linear_system::solve(string method){
	if(method == "gauss") return this->gauss();
	if(method == "gauss with partial pivoting") return this->partial_gauss();
	if(method == "gauss-jordan") return this->gauss_jordan();
	if(method == "LU") return this->lu();
	return NULL;
}	

double *linear_system::gauss(){
	for(int i=0; i<rows-1; i++){//garante que, se os sistema é um SPD, não haverão valores 0 na sua diagonal, após o término do laço.
		for(int p=i+1; this->A[i][i] == 0 && p<this->rows; p++){
			double *aux =  this->A[i];
			this->A[i] = this->A[p];
			this->A[p] = aux;
			double b_aux = this->B[i];
			this->B[i] = this->B[p];
			this->B[p] = b_aux;		
		}
	}

	for(int i=0; i<rows-1; i++){//Faz o triangulamento superior da matriz de coeficientes do sistema, atualizando os valores de B

		for(int j=i+1; j<this->rows; j++){
			double aux = A[j][i]/A[i][i];
			if(aux == 0) continue;
			A[j][i] = 0;
			for(int k=i+1; k<this->columns; k++) this->A[j][k] -= (aux*A[i][k]);
			B[j] -= (aux*B[i]);		
		}
	}
	//Faz os cálculos dos valores das variáveis, retorna eles em X
	double *X = (double*) calloc(this->columns, sizeof(double));
	for(int i=0; i<this->columns; i++) X[i] = B[i];
	for(int i=this->rows-2; i>=0; i--){
		for(int j = i+1; j<this->columns; j++) X[i] -= (A[i][j]*X[j]);
		X[i]/=A[i][i]; 
	}
	return X;
}

double *linear_system::partial_gauss(){

	for(int i=0; i<rows-1; i++){
		for(int p=i+1; p<this->rows; p++){//Ao início de cada iteração, faz-se o pivoteamento que caracteriza pivoteamento parcial
			if(fabs(this->A[i][i]) < fabs(this->A[p][i])){
				double *aux =  A[i];
				A[i] = A[p];
				A[p] = aux;
				double aux2 = B[i];
				B[i] = B[p];
				B[p] = aux2;			
			}		
		}
		for(int j=i+1; j<this->rows; j++){//Faz o triangulamento superior da matriz de coeficientes do sistema, atualizando os valores de B
			double aux = A[j][i]/A[i][i];
			if(aux == 0) continue;
			A[j][i] = 0;
			for(int k=i+1; k<this->columns; k++) this->A[j][k] -= (aux*A[i][k]);
			B[j] -= (aux*B[i]);		
		}
	}
	//Faz os cálculos dos valores das variáveis, retorna eles em O
	double *X = (double*) calloc(this->columns, sizeof(double));
	for(int i=0; i<this->columns; i++) X[i] = B[i];
	for(int i=this->rows-2; i>=0; i--){
		for(int j = i+1; j<this->columns; j++) X[i] -= (A[i][j]*X[j]);
		X[i]/=A[i][i]; 
	}
	return X;
}

double *linear_system::gauss_jordan(){

	for(int i=0; i<rows-1; i++){
		for(int p=i+1; p<this->rows; p++){//Ao início de cada iteração, faz-se o pivoteamento que caracteriza pivoteamento parcial
			if(fabs(this->A[i][i]) < fabs(this->A[p][i])){
				double *aux =  A[i];
				A[i] = A[p];
				A[p] = aux;
				double aux2 = B[i];
				B[i] = B[p];
				B[p] = aux2;			
			}		
		}
		for(int j=i+1; j<this->columns; j++) A[i][j]/=A[i][i]; 
		B[i]/=A[i][i];	
		A[i][i] = 1;
		
		for(int j=i-1; j>=0;j--){
			for(int k = i+1; k<this->columns; k++) A[j][k]-=(A[j][i]*A[i][k]);
			B[j] -= B[i]*A[j][i]; 		
		} 

		for(int j=i+1; j<this->rows;j++){
			for(int k = i+1; k<this->columns; k++) A[j][k]-=(A[j][i]*A[i][k]);
			B[j] -= B[i]*A[j][i]; 		
		} 
		for(int j=i-1;j>=0; j--) A[j][i]=0;
		for(int j=i+1;j<this->rows;j++) A[j][i] = 0;	
	}
	return B;	
}

double **linear_system::get_A(){
	return this->A;
}

double *linear_system::lu(){

	int *Ps= (int*)calloc(this->rows,sizeof(int));
	for(int i=0;i<this->rows;i++) Ps[i] = i;

	for(int i=0; i<rows-1; i++){
		for(int p=i+1; p<this->rows; p++){//Ao início de cada iteração, faz-se o pivoteamento que caracteriza pivoteamento parcial
			if(fabs(this->A[i][i]) < fabs(this->A[p][i])){
				double *aux =  A[i];
				A[i] = A[p];
				A[p] = aux;
				double aux2 = B[i];
				B[i] = B[p];
				B[p] = aux2;
				int aux3 =Ps[i];
				Ps[i] = Ps[p];
				Ps[p] = aux3;			
			}		
		}
		for(int j=i+1; j<this->rows; j++){
			double m =  A[j][i]/A[i][i];
			A[j][i] = m;
			for(int k=i+1; k<this->columns; k++) A[j][k] -= (m*A[i][k]);	
		}			
	}
	
	double *bl = (double*)calloc(this->rows, sizeof(double));
	for(int i = 0; i<this->rows; i++) bl[i] = B[Ps[i]];
	double *Y = (double*)calloc(this->rows, sizeof(double));	
	for(int i=0; i<this->rows; i++){
		double sum=0;
		for(int j=0; j<i; j++) sum+=(A[i][j]*Y[j]);		
		Y[i] = B[i] - sum;
	}

	for(int i=this->rows-2; i>=0; i--){
		for(int j = i+1; j<this->columns; j++) Y[i] -= (A[i][j]*Y[j]);
		Y[i]/=A[i][i]; 
	}
	return Y;
}
