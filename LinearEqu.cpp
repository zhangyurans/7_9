#include<iostream>
#include<cmath>
#include"LinearEqu.h"
using namespace std;
namespace {
	inline void swap(double& v1, double& v2) {               //交换两个实数
		double temp = v1;
		v1 = v2;
		v2 = temp;
	}
}
LinearEqu::LinearEqu(unsigned size/*=2*/):Martrix(size) {
	solution = new double[size];
	sums = new double[size];
}
LinearEqu::~LinearEqu() {
	delete[]solution;
	delete[]sums;
}
void LinearEqu::setLinearEqu(const double* a, const double* b) {
	setMatrix(a);
	for (size_t i = 0; i < getSize(); i++) {
		sums[i] = b[i];
	}
	printMatrix();
}
void LinearEqu::printLinearEqu()const {
	cout << "The Line equation is:" << endl;
	for (size_t i = 0; i < getSize(); i++) {
		for (size_t j = 0; j < getSize(); j++) {
			cout << element(i, j) << "  ";
		}
		cout << "     " << sums[i] << endl;
	}
}
bool LinearEqu::solve() {                                                                     //全选主元高斯消去法计算方程组
	const unsigned n = getSize();
	unsigned* const js = new unsigned [getSize()];                                                             //存储主元素所在列号的数组
	double* const A = new double[n * n];
	double* const b = new double[n];
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			A[n * i + j] = element(i, j);
		}
		b[i] = sums[i];
	}
	for (size_t k = 0; k < n - 1; k++) {                                              //寻找主元素
		double max = 0;                                                                          //主元素
		int is;                                                                               //主元素所在行号
		for (size_t i = k; i < n; i++) {
			for (size_t j = k; j < n; j++) {
				double t = fabs(A[n * i + j]);
				if (fabs(max) < t) {
					max = t;
					is = i;
					js[k] = j;
				}
			}
		}
		if (max == 0) {                                                                       //如果主元素为0,则无解
			delete[]js;
			delete[]A;
			delete[]b;
			return false;
		}
		else {                                                                                //交换行列，把主元素交换到k行k列
			if (js[k] != k) {                                                                 //交换列
				for (size_t i = 0; i < n; i++)
					swap(A[i * n + js[k]], A[i * n + k]);
			}
			if (is != k) {                                                                    //交换行
				for (size_t j = k; j < n; j++) {
					swap(A[is * n + j], A[k * n + j]);
				}
				swap(b[is], b[k]);
			}
		}
		double major = A[k * n + k];
		for (size_t j = k + 1; j < n; j++) {                                         //归一化
			A[k*n+j] /= major;
		}
		b[k] /= major;
		for (size_t i = k+1; i < n; i++) {                                           //消去计算
			for (size_t j = k + 1; j < n; j++) {
				A[n * i + j] -= A[i * n + k] * A[k * n + j];				
			}
			b[i] -= A[i * n + k] * b[k];
		}
	}
	double d = A[(n - 1) * n + (n - 1)];
	if (fabs(d) < 1e-15) {
		delete[]js;
		delete[]A;
		delete[]b;
		return false;
	}
	solution[n - 1] = b[n - 1] / d;                                               //回代过程
	for (int i = static_cast<int>(n) - 2; i >= 0; i--) {
		double t = 0;
		for (size_t j = i + 1; j < n ; j++) {
			t += A[n * i + j] * solution[j];
		}
		solution[i] = b[i] - t;
	}
	js[n - 1] = n - 1;                                                               //对之前的交换行的操作反向，将解向量数据顺序排列正确
	for (int k = static_cast<int>(n) - 1; k >= 0; k--) {
		if (js[k] != k) {
			swap(solution[js[k]], solution[k]);
		}
	}
	delete[]js;
	delete[]A;
	delete[]b;
	return true;
}

void LinearEqu::printSolution() {
	if (!solve()) {
		cout << "Fail！" << endl;
	}
	else {
		cout << "The result is：" << endl;
		for (size_t i = 0; i < getSize(); i++) {
			cout << "x[" << i << "]=" << solution[i] << endl;
		}
	}
}