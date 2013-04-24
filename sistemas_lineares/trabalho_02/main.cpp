#include "solver.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>
using namespace std;
int main(){
	double e;
	unsigned int itermax;
	cout<<"entre a precisao"<<endl;
	cin >> 	e;
	cout<<"defina o maximo de iteracoes" <<endl;
	cin >> itermax;
	FILE *report;
	report = fopen("report.txt", "w");
	solver *s = new solver(8,8);
	s->set_value(0, 0, 17.0);  	s->set_value(0, 1, -5.0);  	s->set_value(0, 2, 0.0);  			s->set_value(0, 3, 0.0);  				s->set_value(0, 4, 0.0);  		s->set_value(0, 5, 0.0);			s->set_value(0, 6, 0.0);  				s->set_value(0, 7, -2.0);			s->set_b_value(0, 1000.0);  
	s->set_value(1, 0, 1.0);  	s->set_value(1, 1, -4.0);  	s->set_value(1, 2, 2.0);  			s->set_value(1, 3, 0.0);  				s->set_value(1, 4, 0.0);  		s->set_value(1, 5, 0.0);			s->set_value(1, 6, 1.0);  				s->set_value(1, 7, 0.0);			s->set_b_value(1, 0.0);  
	s->set_value(2, 0, 0.0);  	s->set_value(2, 1, 6.0);  	s->set_value(2, 2, -9.0);  			s->set_value(2, 3, 2.0);  				s->set_value(2, 4, 0.0);  		s->set_value(2, 5, 1.0);			s->set_value(2, 6, 0.0);  				s->set_value(2, 7, 0.0);			s->set_b_value(2, 0.0);  
	s->set_value(3, 0, 0.0);  	s->set_value(3, 1, 0.0);  	s->set_value(3, 2, 1.0);  			s->set_value(3, 3, -4.0);  				s->set_value(3, 4, 3.0);  		s->set_value(3, 5, 0.0);			s->set_value(3, 6, 0.0);  				s->set_value(3, 7, 0.0);			s->set_b_value(3, 0.0);  
	s->set_value(4, 0, 0.0);  	s->set_value(4, 1, 0.0);  	s->set_value(4, 2, 0.0);  			s->set_value(4, 3, 8.0);  				s->set_value(4, 4, -9.0);  		s->set_value(4, 5, 1.0);			s->set_value(4, 6, 0.0);  				s->set_value(4, 7, 0.0);			s->set_b_value(4, 0.0);  
	s->set_value(5, 0, 0.0);  	s->set_value(5, 1, 0.0);  	s->set_value(5, 2, 4.0);  			s->set_value(5, 3, 0.0);  				s->set_value(5, 4, 3.0);  		s->set_value(5, 5, -10.0);			s->set_value(5, 6, 3.0);  				s->set_value(5, 7, 0.0);			s->set_b_value(5, 0.0);  
	s->set_value(6, 0, 0.0);  	s->set_value(6, 1, 12.0);  	s->set_value(6, 2, 0.0);  			s->set_value(6, 3, 0.0);  				s->set_value(6, 4, 0.0);  		s->set_value(6, 5, 3.0);			s->set_value(6, 6, -23.0);  			s->set_value(6, 7, 8.0);			s->set_b_value(6, 0.0);  
	s->set_value(7, 0, 6.0);  	s->set_value(7, 1, 0.0);  	s->set_value(7, 2, 0.0);  			s->set_value(7, 3, 0.0);  				s->set_value(7, 4, 0.0);  		s->set_value(7, 5, 0.0);			s->set_value(7, 6, 10.0);  				s->set_value(7, 7, -31.0);			s->set_b_value(7, 0.0);  

	report_data *solution;
	fprintf(report, "Relatorio de desempenho do metodo gauss-jacobi serial na execucao para o sistema linear dado, tendo como parametros: e = %lf e itermax = %d\n\nsolucao encontrada:\n", e, itermax);
	solution = s->solve("jacobi", e, itermax);
	for(int i=0; i<solution->n; i++) 
		fprintf(report, "X[%d] = %lf\n", i, solution->X[i]);
	fprintf(report, "A sua execucao tomou %d iteracoes\n", solution->iter);
	//cout << endl << endl;

	s = new solver(8,8);
	s->set_value(0, 0, 17.0);  	s->set_value(0, 1, -5.0);  	s->set_value(0, 2, 0.0);  			s->set_value(0, 3, 0.0);  				s->set_value(0, 4, 0.0);  		s->set_value(0, 5, 0.0);			s->set_value(0, 6, 0.0);  				s->set_value(0, 7, -2.0);			s->set_b_value(0, 1000.0);  
	s->set_value(1, 0, 1.0);  	s->set_value(1, 1, -4.0);  	s->set_value(1, 2, 2.0);  			s->set_value(1, 3, 0.0);  				s->set_value(1, 4, 0.0);  		s->set_value(1, 5, 0.0);			s->set_value(1, 6, 1.0);  				s->set_value(1, 7, 0.0);			s->set_b_value(1, 0.0);  
	s->set_value(2, 0, 0.0);  	s->set_value(2, 1, 6.0);  	s->set_value(2, 2, -9.0);  			s->set_value(2, 3, 2.0);  				s->set_value(2, 4, 0.0);  		s->set_value(2, 5, 1.0);			s->set_value(2, 6, 0.0);  				s->set_value(2, 7, 0.0);			s->set_b_value(2, 0.0);  
	s->set_value(3, 0, 0.0);  	s->set_value(3, 1, 0.0);  	s->set_value(3, 2, 1.0);  			s->set_value(3, 3, -4.0);  				s->set_value(3, 4, 3.0);  		s->set_value(3, 5, 0.0);			s->set_value(3, 6, 0.0);  				s->set_value(3, 7, 0.0);			s->set_b_value(3, 0.0);  
	s->set_value(4, 0, 0.0);  	s->set_value(4, 1, 0.0);  	s->set_value(4, 2, 0.0);  			s->set_value(4, 3, 8.0);  				s->set_value(4, 4, -9.0);  		s->set_value(4, 5, 1.0);			s->set_value(4, 6, 0.0);  				s->set_value(4, 7, 0.0);			s->set_b_value(4, 0.0);  
	s->set_value(5, 0, 0.0);  	s->set_value(5, 1, 0.0);  	s->set_value(5, 2, 4.0);  			s->set_value(5, 3, 0.0);  				s->set_value(5, 4, 3.0);  		s->set_value(5, 5, -10.0);			s->set_value(5, 6, 3.0);  				s->set_value(5, 7, 0.0);			s->set_b_value(5, 0.0);  
	s->set_value(6, 0, 0.0);  	s->set_value(6, 1, 12.0);  	s->set_value(6, 2, 0.0);  			s->set_value(6, 3, 0.0);  				s->set_value(6, 4, 0.0);  		s->set_value(6, 5, 3.0);			s->set_value(6, 6, -23.0);  			s->set_value(6, 7, 8.0);			s->set_b_value(6, 0.0);  
	s->set_value(7, 0, 6.0);  	s->set_value(7, 1, 0.0);  	s->set_value(7, 2, 0.0);  			s->set_value(7, 3, 0.0);  				s->set_value(7, 4, 0.0);  		s->set_value(7, 5, 0.0);			s->set_value(7, 6, 10.0);  				s->set_value(7, 7, -31.0);			s->set_b_value(7, 0.0);  
	fprintf(report, "\n\n\nRelatorio de desempenho do metodo gauss-seidel serial na execucao para o sistema linear dado, tendo como parametros: e = %lf e itermax = %d\n\nsolucao encontrada:\n", e, itermax);
	solution = s->solve("seidel", e, itermax);
	for(int i=0; i<s->get_rows(); i++) 
		fprintf(report, "X[%d] = %lf\n", i, solution->X[i]);
	fprintf(report, "A sua execucao tomou %d iteracoes\n", solution->iter);

	return 0;
}

