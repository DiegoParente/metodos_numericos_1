#ifndef LINEAR_SYSTEM_H
#define LINEAR_SYSTEM_H
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

//linear_system class models a linear system Ax = B
class linear_system{

public:
	linear_system(unsigned int rows, unsigned int columns);
	linear_system(unsigned int rows, unsigned int columns, double **A, double *B);
	double *solve(string method);
	unsigned int get_rows_number();
	unsigned int get_columns_number();
	double **get_A();
private:
	unsigned int rows, columns;
	double **A;
	double *B;
	double *gauss();//ok| Fazer reaproveitamento de código para gauss e partial_gauss, estilo: gauss_base recebendo ponteiro pra função;
	double *partial_gauss();//ok
	double *gauss_jordan();//ok
	double *lu();//ok
};	

#endif
