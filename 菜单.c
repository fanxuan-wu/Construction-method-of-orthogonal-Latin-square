#define  _CRT_SECURE_NO_WARNINGS 1
#include"����������.h"

int main()
{
	int n;
	int A[4][4] = { 0,1,2,3, 1,0,3,2, 2,3,0,1, 3,2,1,0 };
	int B[4][4] = { 0,1,2,3, 2,3,0,1, 3,2,1,0, 1,0,3,2 };
	int A1[N][N] = { 0 };
	int A2[N][N] = { 0 };
	int A3[N][N] = { 0 };
	int A4[N][N] = { 0 };//���켸���վ������ڴ洢���ݣ�
	int C1[N][N] = { 0 }, C2[N][N] = { 0 };
	printf("��������Ҫ��������������Ľ���n:\n");
	scanf("%d", &n);
	if (n <= 2 || n == 6) {//�������������ж�
		printf("�����ڽ���Ϊ%d������������\n", n);
		return 0;
	}
	else if (n == 4) {
		OLs4(A, B);//���4��������������
		return 0;
	}
	else if (n % 2 == 1) {
		OLsOdd(A1, A2, &n);//���첢�������������������
		return 0;
	}

	int p = 0, m;
	m = Pnd(&n, &p);//�����ж����ֽ�n��
	if (m == 1) {//���첢���4*2^p��������������
		init(A, B, A1, A2);//��A1��A2���г�ʼ��������4�׾���A��B��ֵ��ֵ��A1��A2
		p = p - 2;//�õ�n=4*2^p
		OLs4doub(A1, A2, A3, A4, p);//4*2^p�ı����������������Ĺ���,�������
	}
	else if (m == 2) {
		if (p == 2) {
			m = 4, n = n / 4;
			OLsOdd(A1, A2, &n); //���첢�������������������
			init(A, B, A3, A4);//��A3��A4���г�ʼ��������4�׾���A��B��ֵ��ֵ��A3��A4
			OLs4Odd(A3, A1, C1, n, m);
			OLs4Odd(A4, A2, C2, n, m);
			reorder_matrix(C1, n * m);//��C1��������
			reorder_matrix(C2, n * m);
			copy(C1, C2, n * m / 2);//���C1��C2
		}
		else {
			n = n / (int)pow(2, p);
			p = p - 2;//�õ�n=4*2^p
			OLsOdd(A1, A2, &n); //���첢�������������������
			init(A, B, A3, A4);//��A3��A4���г�ʼ��������4�׾���A��B��ֵ��ֵ��A3��A4
			OLs4doub(A3, A4, C1, C2, p);//4*2^p�ı����������������Ĺ���,�������
			OLs4Odd(A3, A1, C1, n, 4 * (int)pow(2, p));
			OLs4Odd(A4, A2, C2, n, 4 * (int)pow(2, p));
			reorder_matrix(C1, n * 4 * (int)pow(2, p));//��C1��������
			reorder_matrix(C2, n * 4 * (int)pow(2, p));
			copy(C1, C2, n * 4 * (int)pow(2, p) / 2);//���C1��C2
		}
	}
	return 0;
}