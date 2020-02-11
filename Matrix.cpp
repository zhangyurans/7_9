#include<iostream>
#include"Matrix.h"
using namespace std;
Martrix::Martrix(unsigned size/*=2*/) :size(size) {
	elements = new double[size * size];
}
Martrix::~Martrix() {
	delete[]elements;
}
void Martrix::setMatrix(const double* values)const {
	for (size_t i = 0; i < size * size; i++) {
		elements[i] = values[i];
	}
}

void Martrix::printMatrix()const {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			cout << element(i, j) << " ";
		}
		cout << endl;
	}
}