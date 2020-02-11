#ifndef _MARTRIX_H_                 //矩阵类，只处理n*n的方阵
#define _MARTRIX_H_
class Martrix {
public:
	Martrix(unsigned size = 2);          //构造函数
	~Martrix();                     //析构函数
	void setMatrix(const double* values)const;          //为方阵设置初值
	void printMatrix()const;                            //显示方阵
	unsigned getSize()const { return size; }                  //得到方阵大小
	double element(unsigned i, unsigned j)const { return elements[i * size + j]; }
	double& element(unsigned i, unsigned j) { return elements[i * size + j]; }
private:
	unsigned size;                       //方阵大小
	double* elements;                //存放矩阵的数组的首地址
};

#endif
