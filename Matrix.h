#ifndef _MARTRIX_H_                 //�����ֻ࣬����n*n�ķ���
#define _MARTRIX_H_
class Martrix {
public:
	Martrix(unsigned size = 2);          //���캯��
	~Martrix();                     //��������
	void setMatrix(const double* values)const;          //Ϊ�������ó�ֵ
	void printMatrix()const;                            //��ʾ����
	unsigned getSize()const { return size; }                  //�õ������С
	double element(unsigned i, unsigned j)const { return elements[i * size + j]; }
	double& element(unsigned i, unsigned j) { return elements[i * size + j]; }
private:
	unsigned size;                       //�����С
	double* elements;                //��ž����������׵�ַ
};

#endif
