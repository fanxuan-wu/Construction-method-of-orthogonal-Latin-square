#define  _CRT_SECURE_NO_WARNINGS 1
#include"����������.h"

int OLs4(int* A1[4][4], int* A2[4][4]) {//���4��������������
	int i, j;
	printf("4�׻�Ϊ������������A1���£�\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j == 0) printf(" | ");
			printf("%d ", A1[i][j]);
			if (j == 3) printf("| \n");
		}
	}
	printf("4�׻�Ϊ������������A2���£�\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j == 0) printf(" | ");
			printf("%d ", A2[i][j]);
			if (j == 3) printf("| \n");
		}
	}
}
int OLsOdd(int* A1[][N], int* A2[][N], int* n){
	printf("%d�׻�Ϊ������������A1���£�\n",*n);
	int i = 0, j = 0;
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			A1[i][j] = (1 * i + j) % *n;
		}
	}
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			if (j == 0) printf(" | ");
			printf("%2d ", A1[i][j]);
			if (j == *n - 1) printf("| \n");
		}
	}
	printf("\n");
	printf("%d�׻�Ϊ������������A2���£�\n",*n);
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			A2[i][j] = (2 * i + j) % *n;
		}
	}
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			if (j == 0) printf(" | ");
			printf("%2d ", A2[i][j]);
			if (j == *n - 1) printf("| \n");
		}
	}
}
int Pnd(int* n, int* p) {//�����ж����ֽ�n��
	{
		int i, a;
		a = *n;
		for (i = 0;; i++) {
			if (a == 1) {//��n����ֻ������������2ʱ����1
				printf("%d = 2^%d\n", *n, *p);
				return 1;
			}
			else if (a % 2 == 0) {//�ж����ڼ�������2
				a = a / 2;
				*p = *p + 1;
			}
			else if (*p != 1) {//��n��ֻ����һ������2���Լ�һ������ʱ����2
				printf("%d = 2^%d * %d\n", *n, *p, a);
				return 2;
			}
			else if (*p == 1) {//��n����1������2���Լ�һ������ʱ����0
				printf("����%d�д���һ������2\n", *n);
				printf("��Ȼ�����ϴ���%d�׵�����������\n", *n);
				printf("���ܱ�Ǹ,������ͨ���˳������%d������������\n", *n);
				return 0;
			}
		}
	}
}

int init(int* A[][4], int* B[][4], int* A1[][N], int* A2[][N]) {//��A1��A2���г�ʼ��
	int i, j;
	for (i = 0; i < 4; i++) {//��A��ֵ��A1
		for (j = 0; j < 4; j++)
			A1[i][j] = A[i][j];
	}
	for (i = 0; i < 4; i++) {//��B��ֵ��A2
		for (j = 0; j < 4; j++)
			A2[i][j] = B[i][j];
	}
}
int copy_array(int source1[][N], int source2[][N], int destination1[][N], int destination2[][N], int m) {
	int i, j;
	{//����2m������������destination1
		for (i = 0; i < m; i++) {
			for (j = 0; j < m; j++) destination1[i][j] = source1[i][j];
			for (j = m; j < 2 * m; j++) destination1[i][j] = source1[i][j - m] + m;
		}
		for (i = m; i < 2 * m; i++) {
			for (j = 0; j < m; j++) destination1[i][j] = source1[i - m][j] + m;
			for (j = m; j < 2 * m; j++) destination1[i][j] = source1[i - m][j - m];
		}
	}
	{//��������������destination2
		for (i = 0; i < m / 2; i++) {
			for (j = 0; j < m; j++) destination2[i][j] = source2[i][j];
			for (j = m; j < 2 * m; j++) destination2[i][j] = source2[i][j - m] + m;
		}
		for (i = m; i < 3 * m / 2; i++) {
			for (j = 0; j < m; j++) destination2[i][j] = source2[i - m / 2][j];
			for (j = m; j < 2 * m; j++) destination2[i][j] = destination2[i][j - m] + m;
		}
		for (i = m / 2; i < m; i++) {
			for (j = 0; j < m; j++) destination2[i][j] = destination2[i - m / 2][j] + m;
			for (j = m; j < 2 * m; j++) destination2[i][j] = destination2[i][j - m] - m;
		}
		for (i = 3 * m / 2; i < 2 * m; i++) {
			for (j = 0; j < m; j++) destination2[i][j] = destination2[i - m / 2][j] + m;
			for (j = m; j < 2 * m; j++) destination2[i][j] = destination2[i][j - m] - m;
		}
	}
}
int OLs4doub(int* A1[N][N], int* A2[N][N], int* A3[N][N], int* A4[N][N], int p) {//4�ı����������������Ĺ���
	int a, i, j, m;
	for (i = 0; i < p; i++) {//һ����Ҫ����p��
		m = 4 * (int)pow(2, i);;//��4�׿�ʼ����8�ף�ֱ����Ҫ��Ľ���
		copy_array(A1, A2, A3, A4, m);//������m������������A1��A2�����A3��A4
		for (a = 0; a < 2 * m; a++) {//���°��¹��ɵ�A3��A4��ֵ��A1��A2�������������
			for (j = 0; j < 2 * m; j++)
				A1[a][j] = A3[a][j];
		}
		for (a = 0; a < 2 * m; a++) {
			for (j = 0; j < 2 * m; j++)
				A2[a][j] = A4[a][j];
		}
	}
	copy(A1, A2, m);//���A1��A2
}
int copy(int* A1[][N], int* A2[][N], int m){
	int i, j;
	printf("\n");
	for (i = 0; i < 2 * m; i++) {//���A1
		for (j = 0; j < 2 * m; j++) {
			if (j == 0) printf(" | ");
			printf("%2d ", A1[i][j]);
			if (j == 2 * m - 1) printf("| \n");
		}
	}
	printf("\n");
	for (i = 0; i < 2 * m; i++) {//���A2
		for (j = 0; j < 2 * m; j++) {
			if (j == 0) printf(" | ");
			printf("%2d ", A2[i][j]);
			if (j == 2 * m - 1) printf("| \n");
		}
	}
}
int OLs4Odd(int C[][N], int D[][N],int C1[][N], int m, int n) {
	int a,i, j, k, o;
	int p = 0, q = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			for (k = 0; k < n; k++) {
				for (o = 0; o < m; o++) {
					a = C[i][k] * 10 + D[j][o];
					for (p; p < n * m;) {
						for (q; q < n * m;) {
							C1[p][q] = a;
							q++;
							break;
						}
						if (q == n * m) {
							q = 0; p++; break;
						}
						else break;
					}
				}
			}
		}
	}
}



void reorder_matrix(int* C[][N], int n) {
	int mapping[N] = { 0 };
	int count = 0;
	for (int i = 0; i < n; i++) {//���ȱ�������A�ĵ�һ�У������ֹ���Ԫ�ر��浽mapping�����У�ͬʱ��¼���ֹ��Ĳ�ͬԪ�صĸ���count
		int j;
		for (j = 0; j < count; j++) {
			if (mapping[j] == C[0][i]) {
				break;
			}
		}
		if (j == count) {
			mapping[count] = C[0][i];
			count++;
		}
	}
	for (int i = 0; i < n; i++) {//�ٴα�������A��������A�е�Ԫ���滻�ɶ�Ӧ����ֵ
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < count; k++) {
				if (C[i][j] == mapping[k]) {
					C[i][j] = k;
					break;
				}
			}
		}
	}
}

