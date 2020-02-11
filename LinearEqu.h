#ifndef _LINEAREQU_H_
#define _LINEAREQU_H_
#include"Matrix.h"
class LinearEqu :public Martrix {
public:
	LinearEqu(unsigned size = 2);                                           //构造函数
	~LinearEqu();                                                      //析构函数
	void setLinearEqu(const double* a, const double *b);               //方程组设置，前一个为方阵的设置，后一个为方程右端向量的设置
	void printLinearEqu()const;                                        //方程组显示
	void printSolution();                                         //计算并输出方程组的解
private:
	double* solution;                                                  //方程的解向量x
	double* sums;                                                      //方程的右端向量b
	bool solve();                                                      //方程组求解
	
};
#endif                                                                 //线性方程组类

