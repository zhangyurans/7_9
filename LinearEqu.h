#ifndef _LINEAREQU_H_
#define _LINEAREQU_H_
#include"Matrix.h"
class LinearEqu :public Martrix {
public:
	LinearEqu(unsigned size = 2);                                           //���캯��
	~LinearEqu();                                                      //��������
	void setLinearEqu(const double* a, const double *b);               //���������ã�ǰһ��Ϊ��������ã���һ��Ϊ�����Ҷ�����������
	void printLinearEqu()const;                                        //��������ʾ
	void printSolution();                                         //���㲢���������Ľ�
private:
	double* solution;                                                  //���̵Ľ�����x
	double* sums;                                                      //���̵��Ҷ�����b
	bool solve();                                                      //���������
	
};
#endif                                                                 //���Է�������

