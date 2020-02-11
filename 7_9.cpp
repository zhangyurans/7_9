#include<iostream>
#include"LinearEqu.h"
#include"Matrix.h"
using namespace std;

int main() {
	double a[] = {
		0.2368,0.2471,0.2568,1.2671,
		0.1968,0.2071,1.2168,0.2271,
		0.1581,1.1675,0.1768,0.1871,
		1.1161,0.1254,0.1397,0.1490
	};
	double e[] = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1
	};

	double b[] = { 1.8471,1.7471,1.6471,1.5471 };
	LinearEqu equ(4);
	equ.setLinearEqu(a, b);
	//equ.setMatrix(a);
	//equ.printMatrix();
	equ.printLinearEqu();
	equ.printSolution();
	return 0;
}